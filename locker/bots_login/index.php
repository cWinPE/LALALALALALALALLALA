<?php
include_once "../config.php";
    try {
        $conn = new  PDO('mysql:host='.SERVER.';dbname='.DB, USER, PASSWORD);
        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    } catch(PDOException $e) {
        header("Location:../setdb.php");
    }
?>


<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
<head>
    <title>LOGIN PAGE</title>
</head>
<body>
    <?php 
    if(isset($_COOKIE["msg"]))
    {
        if($_COOKIE["msg"]=="!")
        {
            include_once "msg.php";
            ShowMessage("Invalid authorization data","#8A242A ");
        }
    }
    ?>
<center style="position: fixed;left: 35%;top: 15%;">
<div class="container">
    <br><br><br>

    <div class="utama" id="login">
        <form class="from" action="../login_data.php" method="POST" autocomplete="off">
            <h3>Welcome</h3>
            <div class="norma">
                <textarea class="text_key" id="login" name="login" type="text" required placeholder="Enter authorization key"></textarea>
            </div>
            <br>
            <div style="display: block;height: 35px;">
                <div class="kolom" style="float: right;">
                  <button title="session" class="loger" onclick="location.href='../index.php'"></button>
                  <button type="submit" class="comer">Submit Request</button>
                </div>
            </div>
        </form>
    </div>

    <br><br>

    <div class="row tall-row">
        <div class="col-md-offset-8" style="margin-left: auto;text-align: center;">
            <p style="color: #f00;">Create by <a href="https://t.me/bleckrosemaza" style="color: #f00; font-weight: bold;text-decoration: none;">Bleck Rose Maza</a> &copy; 2022</p>
        </div>
    </div>

</div>
</center>
   <style>
     html { background-image: url(../images/logo_black.jpg)!important;background-size: cover !important;font-family: monospace; }
     form > h3 { color: #0f0;text-align: left;font-weight: normal;font-size: 21px;margin:20px 0 10px 0; }
    .text_key { resize: none;width:93%;background-color: #343247;border: 1px solid #00ffbf;border-radius: 0.25rem;height:139px;outline:none;color:#ecf5ff;font-size:18px;padding:0.375rem 0.75rem;line-height: 1.4; }
    .text_key:focus { border:1px solid #00ffbf;-webkit-box-shadow: 0 0 0.2em #00ffbf; }
    .utama { border:2px solid red;align-content:center;width:350px;padding:19px;border-radius:5px;background-color:#080808; }
    .text_key::placeholder { color: #9da4ac;font-size: 16px;font-family: monospace; }
    .loger { padding: 10px;border-radius: 21px;border: 4px solid #a6a6a5;position: relative;top: -5px;margin-right: 10px;background-color:red; }
    .loger:focus { background-color:black; }
    .comer { padding:6px 12px;border: 1px solid red;color: red;background:transparent;font-family: monospace; }
    .comer:focus { color: lime;border:1px solid lime; }
    .comer:hover { color: black;background-color:red; }
   </style>
</body>
</html>
