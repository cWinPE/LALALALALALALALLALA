
<style type="text/css">

.mymagicoverbox_fenetre {
  z-index: 9999;
position: fixed;
top: 75px;
text-align: center;
padding: 5px;
  padding-bottom: 5px;
border-radius: 4px;
margin-left: 16px;
background-color: rgba(138, 36, 42, 0.66);
border: 1px solid #f00;
padding-bottom: 7px;
 
}
.mymagicoverbox_fermer {
  color:#FFFFE0;
  cursor:pointer;
  font-weight:400;
  font-size:14px;
  font-style:normal
  font-family:'Roboto';
}


</style>

<?php 



function ShowMessage($text, $color)
{
echo "
	<script src='http://code.jquery.com/jquery-1.11.1.js'></script>

	<div id='block' class='mymagicoverbox_fenetre mymagicoverbox_fermer' 
	style='  width: 250px; display: block;'>
	$text
	</div>

	<script type='text/javascript'>
	function delete_cookie ( cookie_name )
	{
	  var cookie_date = new Date ( );  
	  cookie_date.setTime ( cookie_date.getTime() - 1 );
	  document.cookie = cookie_name += '=; expires=' + cookie_date.toGMTString();
	}

	$('#block').fadeIn(250);

	$('#block').click(function()
	{
		   $('#block').fadeOut(250); 
		 delete_cookie('msg');
		   
	});
	</script>";
}
?>