<meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>

<?php  
session_start(); 
if(isset($_SESSION["panel_user"])) {
  //  header("Location: ./homepage.php");
  echo "" ;
    
    }else{
        session_destroy();
        header("Location: bots_login/index.php");
    }
header('Content-type: text/html; charset=utf-8');
$statusCode=false;
if (!(isset($_SESSION['panel_user'])))
{
	session_destroy();
	header("Location: bots_login/");
}else{

	if ($_SESSION['panel_status']!="Action"){
		session_destroy();
		header("Location: bots_login/index.php");
	}else{
		$statusCode=true;
	}
}
if($statusCode){
include_once "config.php";
	try {
	    $conn = new  PDO('mysql:host='.SERVER.';dbname='.DB, USER, PASSWORD);
	    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	} catch(PDOException $e) {
	    header("Location:setdb.php");
	}

?>
<html>
<head >
<link rel="shortcut icon" href="favicon.ico">
<title>LOCKER_1.1</title>


<link href="styles/menus.css" rel="stylesheet"/>
<link href="styles/index.css" rel="stylesheet"/>
<link href="styles/btn.css" rel="stylesheet"/>
<link href="styles/modul_form.css" rel="stylesheet"/>
<link rel="stylesheet" href="styles/style.css"/>
<link href="styles/modul_form_log.css" rel="stylesheet"/>
<link href="styles/modul_form_set.css" rel="stylesheet"/>

<link rel="stylesheet" href="styles/fa_fa/css/font-awesome.min.css">


<link rel="shortcut icon" href="/images/icon3.png" type="image/png"/>



<script src="styles/bootstrap/js/bootstrap.min.js"></script>
<script type="text/javascript" src="js/jquery.min.js"></script>

<link href="styles/bootstrap/css/bootstrap.min.css" rel="stylesheet">
<link rel="stylesheet" href="styles/bootstrap/css/style.css"/>
<script src="styles/bootstrap/js/bootstrap.min.js"></script>
<script src="js/alert.js"></script>
<script src="js/amrnb.js" defer></script>
<!--
<script src="styles/bootstrap/js/bootstrap.js"></script>
<link href="http://cdnjs.cloudflare.com/ajax/libs/twitter-bootstrap/2.3.0/css/bootstrap.css"    rel="stylesheet">
-->
</head>
  <style>
  .nav > li > a:hover, .nav > li > a:focus {
  text-decoration: none;
  background-color: #2f0000;
} ul {
  background: black;
}
    .table_dark tr:hover td {
     background: #260101;
} .btn-outline-secondary {
    color: #e4e3e3f7;
    background-color: #28a745;
    background-image: none;
    border-color: #000000;
} .btn-outline-success {
    color: #efecec;
    background-color: #28a745;
    background-image: none;
    border-color: black;
} .btn-outline-danger {
    color: #e4e3e3;
    background-color: #28a745;
    background-image: none;
    border-color: black;
} .btn-outline-success:hover {
  color: #fff;
  background-color: transparent;
  border-color: #28a745;
} .btn-outline-danger:hover {
  color: #fff;
  background-color: transparent;
  border-color: #28a745;
} .btn-outline-secondary:hover {
  color: #fff;
  background-color: transparent;
  border-color: #28a745;
} .navs {
	background: #000;
    width: 13%;
    position: fixed;
    height: 100%;
	border-right: 1px solid #04ac01;
	
} .content {
    color: #fff;
    float: right;
    width: 86.5%;
    height: 100%;
    border: 1px solid #04ac01;
    background-color: #000000;
	border-top: 0px;
	border-bottom: 0px;
} .textlog {
    font-family: ""Roboto", "Helvetica", "Arial", sans-serif";
    font-size: 13;
    width: 98%;
	padding: 7px;
    height: 94%;
    background: black;
    border: 1px solid #f00;
    resize: both;
    color: #00ec07;
    opacity: 0.7;
	outline: none;
}
  .navbar { position: static;min-height: 50px;margin-bottom: 20px;border: 1px solid transparent; }
  .header { margin-right: 1.5%;border-bottom: 1px solid rgb(3 175 0);margin-left: 14%;border-left: 1px solid rgb(3 175 0);border-right: 1px solid rgb(3 175 0);border-radius: 6px; }
 body {
                background:url('images/fon.jpg')no-repeat center fixed;
                -webkit-background-size:cover;
                -moz-background-size:cover;
                -o-background-size:cover;
                background-size:cover;
            }
			.akbank { 
			color: #1ae029;
			font-size: 16px;
			font-variant: all-petite-caps;
		}
.go-up, .go-down {
 display: none;
 position: fixed; /*позиционирование*/
 z-index: 9999; /*поверх все элементов на странице*/
 right: 15%; /*положение на странице, если слева - left*/
 background: #4F4F4F;
 border: 1px solid #ccc;
 border-radius: 5px;
 cursor: pointer;
 color: #fff;
 text-align: center;
 font: normal normal 42px/42px sans-serif;
 text-shadow: 0 1px 2px #000;
 opacity: .5;
 padding: 3px;
 margin-bottom: 5px;
 width: 42px;
 height: 42px;
} .go-up { bottom: 60px; }
.go-down { bottom: 10px; }
.go-down:hover,
.go-up:hover {
 opacity: 1;
 box-shadow: 0 5px 0.5em -1px #666;
}
  </style>

 <body>
<div class="go-up" title="Вверх" id='ToTop'>⇧</div>
<div class="go-down" title="Вниз" id='OnBottom'>⇩</div>
 <script type="text/javascript">
$(function(){
 if ($(window).scrollTop()>="250") $("#ToTop").fadeIn("slow")
 $(window).scroll(function(){
  if ($(window).scrollTop()<="250") $("#ToTop").fadeOut("slow")
   else $("#ToTop").fadeIn("slow")
 });

 if ($(window).scrollTop()<=$(document).height()-"999") $("#OnBottom").fadeIn("slow")
 $(window).scroll(function(){
  if ($(window).scrollTop()>=$(document).height()-"999") $("#OnBottom").fadeOut("slow")
   else $("#OnBottom").fadeIn("slow")
 });

 $("#ToTop").click(function(){$("html,body").animate({scrollTop:0},"slow")})
 $("#OnBottom").click(function(){$("html,body").animate({scrollTop:$(document).height()},"slow")})
});
</script>
 <?php

                include_once 'application/utils/classUsersRights.php';
                include_once 'application/utils/utils.php';
                include_once 'application/database/webSocket.php';

                $functions = new functions;
                $getBots = $functions->getBots();
                $getCards = $functions->getCards();
                $getInjections = $functions->getInjections();
				$getCommand = $functions->getCommand();
                ?>
 <aside id='sidebar-left' class='sidebar-left'>

            <div class=''>
                <div class='nano-content'>
				  <nav class='navs' role='navigation'>
				  <center><img width = '120' src='images/icons/lock.png' style='padding: 11px 0 19px 0;'/></center>
                    <nav id='menu' class='navs' role='navigation' style="overflow: auto;height: 81%;">
                        <ul class='nav nav-mains'>
                            <li>
                                <a href='?cont=bots&page=1'>
                                    <i class='fa fa-lock akbank' aria-hidden='true'></i>
                                    <span class='pull-right label label-danger'><?php echo $getBots; ?></span>
                                    <span class='akbank'>Device</span>
                                </a>
                            </li>
                            <?php
							if (($_SESSION['panel_right'] == "admin") || ($_SESSION['panel_right'] == "user")) {
                                echo "
                            <li>
                                <a href='?cont=commands'>
                                    <i class='fa fa-exclamation-circle akbank' aria-hidden='true'></i>
									<span class='pull-right label label-danger'>$getCommand</span>
                                    <span class='akbank'><font style='position: relative;top: -1px;'>List</font></span>
                                </a>
                            </li>";
                            }
							if ($_SESSION['panel_right'] == "admin") {
                                echo "  <li>
                                <a href='?cont=settings'>
                                    <i class='fa fa-cog akbank' aria-hidden='true'></i>
                                    <span class='akbank'><font style='position: relative;top: -1px;'>Settings</font></span>
                                </a>
                            </li>";
                            } ?>
                            <li>
                                <a href='?cont=exit'>
                                    <i class='fa fa-sign-out akbank' aria-hidden='true'></i>
                                    <span class='akbank'><font style='position: relative;top: -1px;'>LogOut</font></span>
                                </a>
                            </li>
                        </ul>
                    </nav>
				</nav>
                </div>

            </div>

        </aside>

<?php

include_once "application/utils/classUsersRights.php";
include_once "application/utils/utils.php";
include_once 'application/database/webSocket.php';

$id = isset($_GET['cont']) ? $_GET['cont'] : "";
	if($id=="bots"){
		include_once "application/views/botstable.php";
	}elseif($id=="statistic"){
		include_once "application/views/statistic.php";
	}elseif($id=="commands"){
		include_once "application/views/commands.php";
	}elseif($id=="settings"){
		include_once "application/views/settingsPanel.php";
	}elseif($id=="exit"){
		session_destroy();
			echo "<script>window.location.replace('bots_login/index.php');</script>";
		//header('Location: bots_login/index.php');
		exit;
	}else{
	//	header("Location:?cont=bots&page=1");
		echo "<script>window.location.replace('?cont=bots&page=1');</script>";
	}

	if($id == null)	echo "<script>window.location.replace('?cont=bots&page=1');</script>";//header("Location:?cont=bots&page=1");
?>


</html>
<?php } ?>
