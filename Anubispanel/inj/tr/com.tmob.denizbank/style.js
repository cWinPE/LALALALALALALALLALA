$(function(){
	
	
	var slider_items = $('.slider-item ul li'),
		slider_buttons = $('.slider-button ul li');
	
	
	slider_items.filter(':not(:first)').hide();
	slider_buttons.filter(':first').addClass('active');
	
	
	
});