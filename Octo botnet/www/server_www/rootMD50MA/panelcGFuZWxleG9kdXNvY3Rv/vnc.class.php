<?php
require_once "../helpers.php";

//~ define("SCALE", 0.5);

class Vnc
{
	public $displayWidth;
	public $displayHeight;
	public $isLayoutVertical;
	public $has_lockPatternView = false;
	
	public static function formatStatus($bot_id, $data, $btn_size='btn-sm')
	{
		if($data == "") return "";
		//~ var_dump($data);
		 // layout:on|off; screen:on|off; sound:on|off|forbid; backlight:on|off|forbid
		
		if(strstr($data, "screen:on;"))
			$text_only = "";

//~ $vnc = new Vnc();

//~ $bot_id = "492b2d09e0cdbe7956b98de33f8e0c53";
//~ echo $vnc->draw("../data/vnc_{$bot_id}.xml", $bot_id, "1.0", 0, 0);
