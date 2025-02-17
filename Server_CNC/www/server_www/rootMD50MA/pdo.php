<?php

if(!class_exists('Db')) {  
class Db
{
	public $conn;
	public $is_connected = false;
	private $dbg = false;
	public $sqls = array();
	private $lastError = "";
	
	public function connect($db_name='', $user='', $pass='')
	{
		$db_name = ($db_name)? $db_name : MYSQL_DB_NAME;
		$db_user = ($user)? $user : MYSQL_USER;
		$db_pass = ($pass)? $pass : MYSQL_PASS;
		
		$this->sqls = array();
		
		try {
			$this->conn = new PDO("mysql:host=localhost;dbname=" . $db_name .";charset=utf8", $db_user, $db_pass);
			$this->conn->exec("set names utf8");
			$this->conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			$this->is_connected = true;
		}catch(PDOException $e){
			echo $e->getMessage();
		}
		
		return $this->is_connected;
	}

	public function check_connection($db_name, $db_user, $db_pass)
	{
		try {
			new PDO("mysql:host=localhost;dbname=" . $db_name .";charset=utf8", $db_user, $db_pass);
		}catch(PDOException $e){
			
			if(stristr($e->getMessage(), "Unknown database")) return "NO_DB";
			if(stristr($e->getMessage(), "Access denied")) return "ACCESS_DENIED";
			echo $e->getMessage();
		}
		
		return "OK";
	}
	
	public function create_db($db_name, $db_user, $db_pass)
	{

		try {
			$dbh = new PDO("mysql:host=localhost", $db_user, $db_pass);
			$dbh->exec("CREATE DATABASE `$db_name`;");

		} catch (PDOException $e) {
			print("DB ERROR: ". $e->getMessage());
			return false;
		}
    
		return true;
	}
	
	public function escape($string, $is_binary=false)
	{
		if($is_binary)
			return $this->conn->quote($string, PDO::PARAM_LOB);
		else
		{
			$quoted = $this->conn->quote($string, PDO::PARAM_STR);
			return ($quoted != false)? $quoted : "''";
		}
	}
	
	// http://php.net/manual/en/pdostatement.fetch.php  PDO::FETCH_BOTH
	function fetch($sql, $return=false, $params=array(), $fetch_type=PDO::FETCH_ASSOC)
	{
		$this->lastError = "";
		if($params == null) $params = array();
		
		$this->sqls[] = $sql;
		$sth = $this->conn->prepare($sql);
		
		if(sizeof($params))
		foreach($params as $param)
		{
			if(sizeof($param) == 4)
				$sth->bindParam($param[0], $param[1], $param[2], $param[3]);
			else
				$sth->bindParam($param[0], $param[1], $param[2]);
		}

		try{
			$res = $sth->execute();
		} catch (PDOException $e) {
			if($this->dbg) print("DB FETCH ERROR: ". $e->getMessage());
			$this->lastError = $e->getMessage();
			return false;
		}

		if($this->dbg)
			print("SQL: " . $sql . "; RESULT: " . $res);
		
		if($return)
			return $sth->fetchAll($fetch_type);
	}

	public function getLastError()
	{
		return $this->lastError;
	}
	
}
}
