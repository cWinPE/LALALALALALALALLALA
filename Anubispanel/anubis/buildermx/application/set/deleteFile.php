<?php

	$type=htmlspecialchars(isset($_GET["t"]) ? $_GET["t"] : "");
	$file=htmlspecialchars(isset($_GET["f"]) ? $_GET["f"] : "");
	if(($type=="nums")&&($file != "")){
		$path = "../datalogs/numers/$file.html";
		unlink("$path");
		header ("Location:?cont=numbers");
	}
	if(($type=="files")&&($file != "")){
		$path = "../datalogs/files/$file";
		unlink("$path");
		header ("Location:?cont=files");
	}
	if(($type=="png")&&($file != "")){
		$user = $_SESSION['panel_user'];
		$path = "../datalogs/files/$user/$file";
		unlink("$path");
		header ("Location:?cont=icons");
	}

	if(($type=="apk")&&($file != "")){

		$path = "../../../tasks/$file";
		
		unlink("$path");
		header ("Location:../../?cont=apks");
	}

?>
