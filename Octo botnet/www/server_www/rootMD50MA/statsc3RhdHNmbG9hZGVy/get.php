<?php
require("../config.php");
require("../helpers.php");

$f = $_GET['f'];
if(!startsWith($f, "rc/")) die;

while(strstr($f, ".."))
	$f = str_replace("..", "", $f);

$path = "../" . PANEL_FOLDER . "/" . $f;

if(!file_exists($path)) die;

if(endsWith($path, ".css"))
	header("Content-type: text/css");
else if(endsWith($path, ".js"))
	header("Content-type: text/javascript");
else if(endsWith($path, ".png"))
	header("Content-type: image/png");

die(file_get_contents($path));
