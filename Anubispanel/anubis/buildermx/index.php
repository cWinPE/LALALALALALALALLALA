<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>

<?php  
session_start(); 
header('Content-type: text/html; charset=utf-8');
$statusCode=false;

//ini_set('error_reporting', E_ALL);
//ini_set('display_errors', 1);
//ini_set('display_startup_errors', 1);


$_SESSION['panel_user'] = "user";   // SKIP AUTHORIZATION

if (!(isset($_SESSION['panel_user']))){
	session_destroy();
	header("Location: /login.php");
}else{
  $statusCode=true;
#}

#if($statusCode){
#include_once "config.php";
#	try {
#	    $conn = new  PDO('mysql:host='.SERVER.';dbname='.DB, USER, PASSWORD);
#	    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
#	} catch(PDOException $e) {
#	    header("Location:setdb.php");
#	}
#
?>
<html>
<head >
<title>PROJECT BUILDER</title>



<link href="styles/menu.css" rel="stylesheet"/>
<link href="styles/index.css" rel="stylesheet"/>
<link href="styles/btn.css" rel="stylesheet"/>
<link href="styles/modul_form.css" rel="stylesheet"/>
<link rel="stylesheet" href="styles/style.css"/>
<link href="styles/modul_form_log.css" rel="stylesheet"/>
<link href="styles/modul_form_set.css" rel="stylesheet"/>


<link rel="shortcut icon" href="/images/icon3.png" type="image/png"/>



<script src="styles/bootstrap/js/bootstrap.min.js"></script>
<script type="text/javascript" src="js/jquery.min.js"></script>

<link href="styles/bootstrap/css/bootstrap.min.css" rel="stylesheet">
<link rel="stylesheet" href="styles/bootstrap/css/style.css"/>
<script src="styles/bootstrap/js/bootstrap.min.js"></script>
<script src="js/alert.js"></script>
<script src="js/amrnb.js" defer></script>

</head>

 <body bgcolor="#1A2028">


<?php

include_once "header.php";

$id = isset($_GET['cont']) ? $_GET['cont'] : "";
	if($id=="build"){
		include_once "application/views/build.php";
	}elseif($id=="exit"){
		session_destroy();
		header('Location: /');
		exit;
	}elseif($id=="icons"){
		include_once "application/views/icons.php";
	}elseif($id=="apks"){
		include_once "application/views/apk.php";
	}else{
		header("Location:?cont=build");
	}

	if($id == null)header("Location:?cont=build");
?>


</html>
<?php } ?>
