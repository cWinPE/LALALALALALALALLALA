<?php

require("../config.php");
require("../pdo.php");
require("stats.class.php");

$st = new Stats();
if(!$st->connect()) die;
die($st->show());
