<?php

if(!isset($_GET["f"]) || !file_exists("../../../tasks/" . $_GET["f"])) die;

$name = htmlspecialchars($_GET["f"]);
$path = "../../../tasks/" . $name;

$data = file_get_contents($path);

header("Content-Type: application/x-force-download; name={$name}");
header("Content-Disposition: attachment;filename={$name}\n");
header("Expires: Mon, 1 Dec 1999 00:00:00 GMT\n");
header("Accept-Ranges: bytes\n");
header("Pragma: private\n");
header("Cache-control: private\n");

die($data);


?>
