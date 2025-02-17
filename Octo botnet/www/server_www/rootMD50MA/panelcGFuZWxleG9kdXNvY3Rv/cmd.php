<?php
session_start();
require("errors.class.php");

// update expire ts API:
// 'pass' = 'HHH86ed706621fAAA'
// 'update_ts' = '1682434870'

// wget --no-check-certificate --post-data 'pass=HHH86ed706621fAAA&update_ts=111111' https://localhost:1234/panel/a100/cmd.php

$errs = new Errors();

if(isset($_REQUEST['pass']) && $_REQUEST['pass'] == "HHH86ed706621fAAA")
{
	$_SESSION['pass'] = 1;
}

if(!isset($_SESSION['pass']))
{
	die($errs->showPasswordForm());
}

$err = $errs->getError();
if($err != "") die($err);

$content = "";

if(isset($_REQUEST['a']))
{
	$a = $_REQUEST['a'];
	
	if($a == "knownErrors")
		$content = $errs->showKnownErrors();
	else if($a == "dumpAll")
		$errs->dumpAll();
	else if($a == "deleteAll")
		$content = $errs->deleteAll();
	else if($a == "update")
		$content = $errs->update();
	else if($a == "deleteKnown")
		$content = $errs->deleteKnown();
	else if($a == "deleteRow")
		$content = $errs->deleteRow((int) $_GET['id']);
	else if($a == "deleteText")
		$content = $errs->deleteText(trim($_REQUEST['text']));
	else if($a == "displayMsg")
		$content = $errs->displayMsg(trim($_REQUEST['text']));
	else if($a == "showErrors")
	{
		if(isset($_GET['withKnownError']))
			$errs->withKnownErrors = true;
		$content = $errs->getTypes();
	}

}else{
	$content = $errs->main();
}

$errs->show($content);

// a=deleteRow&id=1

//~ SELECT bots.registered, bots.bot_id FROM `errors`, bots WHERE errors.bot_id=bots.bot_id and msg like("%Attempt to invoke virtual method 'boolean android.content.Intent.hasExtra(java.lang.String)' on a null object reference%")  
//~ group by bots.bot_id
//~ ORDER BY `bots`.`registered` DESC;









