<?php

if(file_exists("install.php")) die("<p style='margin-top: 100px; text-align: center; color: red'>rename or delete install.php</p>");

if(!is_writable("../data/")) die("data/ is not writable");

require("../config.php");
require("../pdo.php");

$db = new Db();
$db->connect();
if(!$db->is_connected)
	die('db error');

$starttime = microtime(true);

include("admin.class.php");
$a = new admin($db);
echo $a->draw($_REQUEST);

$endtime = microtime(true);
printf("<!-- Page loaded in %f seconds -->", $endtime - $starttime);
die;
