<?php
//Запуск сессий;
session_start();
if (isset($_POST['login']) && isset($_POST['password']))
{
include_once "config.php";
include_once "msg.php";
// получаем данные из формы с авторизацией
$login = $_POST['login'];
$password = $_POST['password'];
//проверка пароля и логина
$connection = new PDO('mysql:host='.SERVER.';dbname='.DB, USER, PASSWORD);
$connection->exec('SET NAMES utf8');
$sql = "SELECT * FROM t_user";

	$login_ = "";
	$password_ =  "";
	$access = "";

	foreach($connection->query($sql) as $row)
	{
		$login_ = $row['login'];
		$password_ = $row['password'];
		$access = $row['access'];

		if($login_ == $login) break;
	}

	if (($login == $login_)&&($password == $password_))
	{
		$_SESSION['panel_user']=$login;
		$_SESSION['access']=$access;


		setcookie("msg");
		header("Location: /index.php");
	}
	else
	{
		setcookie("msg", "!");

		header("Location: /index.php");
		echo "Логин и пароль введен неверно!";
	}
}
?>
