<?php
session_start();
//~ $statusCode=false;
//~ if (!(isset($_SESSION['panel_user']))){
	//~ session_destroy();
	//~ header("Location: /login.php");
//~ }else{
		//~ $statusCode=true;
//~ }

	 //передаем данные для выпонения команд!!!-----
		//~ if($statusCode)
		//~ {
include '../../config.php';
include '../utils/utils.php';


$error = "";

if(!isset($_POST['nameapp']) || trim($_POST['nameapp']) == "")
	$error .= "Error: Name application can not be empty<br />";

if(!isset($_POST['url']) || trim($_POST['url']) == "")
	$error .= "Error: URL admin panel can not be empty<br />";

if(!isset($_POST['keytraff']) || trim($_POST['keytraff']) == "")
	$error .= "Error: Traffic Encryption Key can not be empty<br />";

if(!isset($_POST['tag']) || trim($_POST['tag']) == "")
	$error .= "Error: TAG can not be empty<br />";

if(!isset($_POST['selecticon']) || trim($_POST['selecticon']) == "")
	$error .= "Error: Icon name can not be empty<br />";

if(!isset($_POST['Accessibility']) || trim($_POST['Accessibility']) == "")
	$error .= "Error: Name Accessibility Service can not be empty<br />";

if($error != "")
	die("<p style='color: red'>{$error}</p><p><a href='javascript:history.back()'>Back</a>");
	
$appname = trim($_POST['nameapp']);
$admin_url = trim($_POST['url']);
$keytraff = trim($_POST['keytraff']);
$tag = trim($_POST['tag']);
$icon_name = $_POST['selecticon'];
$accessib_name = trim($_POST['Accessibility']);
$cryptapk = (isset($_POST['cryptapk']))? true : false;

$twitor = trim($_POST['Twitter']);

if(isset($_POST['checkPlayProtect']))
	$playProtectSeconds = (int) $_POST['secondsPlayProtect'];
else
	$playProtectSeconds = "";

if(isset($_POST['checkstarturl']))
	$starturl = trim($_POST['urlsite']);
else
	$starturl = '';

$admin_mode =  (int) $_POST['admindev'];
$accesib_mode =  (int) $_POST['RequestAccessibility'];

$config = array(
"appname" =>  $appname,
"admin_url" =>  $admin_url,
"keytraff" =>  $keytraff,
"tag" =>  $tag,
"admin_mode" =>  $admin_mode,
"accesib_mode" =>  $accesib_mode,
"accessib_name" =>  $accessib_name,
"playProtectSeconds" =>  $playProtectSeconds,
"starturl" =>  $starturl,
"icon_name" =>  $icon_name,
"twitor" =>  $twitor,
"cryptapk" =>  $cryptapk,
"status" =>  "Waiting"
);


$js = json_encode($config);

$task = "../../../tasks/" . time() . "_task.json";
file_put_contents($task, $js);
chmod($task, 0666);


#save panel url & key traff 
file_put_contents("../../../last.cfg", json_encode(array("url"=>$admin_url, "key"=>$keytraff)));




print("<br>
<br><body bgcolor=#444>
<center><h2 style='color: white'>Task has been added. APK will be build in 5 minutes</h2>
<img src='../../images/loading.gif'></img>
<meta http-equiv='Refresh' content='1; url=../../?cont=apks' />");
//~ header("Location: ../../?cont=apks");

//~ $utils = new functions();
//~ $utils->build($appname, $admin_url, $keytraff, $tag, $admin_mode, $accesib_mode,
//~ $accessib_name, $playProtectSeconds, $starturl, $icon_name, $twitor, $cryptapk);


//~ $user = $_SESSION['panel_user'];

//~ $nameapp = isset($_REQUEST['nameapp']) ? $_REQUEST['nameapp'] : "";
//~ $url = isset($_REQUEST['url']) ? $_REQUEST['url'] : "";
//~ $keytraff = isset($_REQUEST['keytraff']) ? $_REQUEST['keytraff'] : "";
//~ $tag = isset($_REQUEST['tag']) ? $_REQUEST['tag'] : "";
//~ $admindev = isset($_REQUEST['admindev']) ? $_REQUEST['admindev'] : "";
//~ $RequestAccessibility = isset($_REQUEST['RequestAccessibility']) ? $_REQUEST['RequestAccessibility'] : "";
//~ $Accessibility = isset($_REQUEST['Accessibility']) ? $_REQUEST['Accessibility'] : "";
//~ $secondsPlayProtect = isset($_REQUEST['secondsPlayProtect']) ? $_REQUEST['secondsPlayProtect'] : "";
//~ $urlsite = isset($_REQUEST['urlsite']) ? $_REQUEST['urlsite'] : "";
//~ $icon = isset($_REQUEST['icon']) ? $_REQUEST['icon'] : "";
//~ $twitter = isset($_REQUEST['twitter']) ? $_REQUEST['twitter'] : "";
//~ $crypt = isset($_REQUEST['crypt']) ? $_REQUEST['crypt'] : "";


//~ $boolcrypt = false;

//~ if($crypt=="true"){
		//~ $boolcrypt = true;
//~ }

//~ $utils->build($nameapp,$url,$keytraff,$tag,$admindev,$RequestAccessibility,$Accessibility,$secondsPlayProtect,$urlsite,$icon,$twitter,$boolcrypt);


	//header("Location: /index.php?cont=build");
	//$utils->clear();
//~ }
?>
