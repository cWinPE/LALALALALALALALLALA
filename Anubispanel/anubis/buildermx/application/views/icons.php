<?php


if(isset($_FILES['filename']['name']))
{
	if(!is_writable("app_icons/"))
		echo "<h2 style='color: red'>App_icons is not writable</h2>";

	$name = $_FILES['filename']['name'];
	
	if(substr($name, -4) == ".png")
	{
		$dir = "app_icons/" . str_replace(".png", "", $name) . "/mipmap-hdpi/";
		
		if(!file_exists($dir))
		{
			
			system("mkdir -p $dir && chmod 777 $dir", $ch);
			//~ var_dump($ch);
		}
		
		$getFile = $dir . "ic_launcher.png";
		echo $getFile;
		move_uploaded_file($_FILES['filename']['tmp_name'], $getFile);//UPLOAD ICON
		//~ header("Refresh:0");
	}

}

?>
<br />
<br />
<br />
<center>
<h3 style="color: white">Icons</h3>
<div style="width:30%; border: 1px solid black; border-color: #43717a;	background: #1D1F24; border-radius: 4px;">
<form action="" method="post" enctype="multipart/form-data">
	<br />
<p style="color: white">Choose PNG file:</p>
<input type="file" name="filename" accept=".png"/>
</br>
<input type="submit" value="Upload" style=" border: 1px solid #000" class="btn btn-default btn">
</form>
</center>

<div class="content" style="padding-top:15px;">
<table class="table table-hover table_dark" id="bootstrap-table">
<thead class="header_table_bots">
	<th><a style='color: #EDB749;'>File Name</a></th>
	<th><a style='color: #EDB749;' title="Icons">Icons</a></th>
<!--
	<th><a title="Delete"><img src="images/icons/table/icloud.png" width='25px'/></a></th>
-->
</thead>

<?php
chdir("app_icons");
$files = scandir(".", 1);
$path = getcwd();
foreach($files as $nameF)
{
	if($nameF == "." || $nameF == "..") continue;
	
	if(!is_dir($path ."/". $nameF)) continue;
	
		echo "<tr class='table_bots' style='color: #A4A4A4'>
		<td><a title='$nameF' style='font-size: 15pt'>$nameF</a></td>
		<td><a title='Icon'><img width=64 src='app_icons/$nameF/mipmap-hdpi/ic_launcher.png'></img></a></td>
	<!-- <td><a href='application/set/deleteFile.php?t=png&f=$nameF'>Delete</a></td> -->
		</tr>";
}

?>
</table>






<?php

die;

$user =$_SESSION['panel_user'];
$svoy=getcwd();
$godir="application/datalogs/files/$user";

$dir = "$svoy/$godir";
$files2 = scandir($dir, 1);


$getFile = "$godir/".$_FILES['filename']['name'];

if(substr($_FILES['filename']['name'], strlen($_FILES['filename']['name'])-4,4)==".png"){
	move_uploaded_file($_FILES['filename']['tmp_name'], $getFile);//UPLOAD ICON
	header("Refresh:0");
}

if(!file_exists("$godir")){
	system("sudo mkdir $godir && sudo chmod 777 $godir && touch $godir/fhkjadgjghkshkliy-.txt");
}

echo "<p id='text_command' style='margin-top:5px; Color:#EDB749;  font-size: 13pt;'>Icons</p>";


	echo '
	<center>
			<div style="width:30%; border: 1px solid black; border-color: #43717a;	background: #1D1F24; border-radius: 4px;">
			  <form action="" method="post" enctype="multipart/form-data">
			  <input type="file" name="filename" accept=".png"/>
				</br>
				<input type="submit" value="Upload" style=" border: 1px solid #000" class="btn btn-default btn">
			  </form>
				</br></br>
				</div>
				</center></form>';



foreach($files2 as $fil)
{
	if ((!preg_match("/fhkjadgjghkshkliy-.txt/",$fil))&&($fil!=".")&&($fil!=".."))
	{
		$nameF = $fil;
		$path = "application/datalogs/files/$user/";


		echo "<tr class='table_bots' style='color: #A4A4A4'>

				<td><a title='$nameF'>$nameF</a></td>
				<td><a title='Icon'><img src='$path/$nameF'></img></a></td>
				<td><a href='application/set/deleteFile.php?t=png&f=$nameF'>Delete</a></td>
				</tr>";
	 }
}
?>
</div>

