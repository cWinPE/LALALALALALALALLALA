// type: error, ok, info
function show_message(text, type, autoclose)
{
	var aclose = ""|autoclose
	
	$("#messagePanel").hide()
	
	var messageTitle = "Info"
	var mClass = "panel-primary"
	var closeColor = "white"
	
	if(type == "error")
	{
		mClass = "panel-danger"
		messageTitle = "Error"
		closeColor = "darkred"
	}else if(type == "ok"){
		mClass = "panel-success"
		messageTitle = "Success"
		closeColor = "darkgreen"
	}
	
	$("#messageTitle").val(messageTitle)
	$("#messageBody").html(text)
	$("#messageCloseIcon").css("color", closeColor)
	
	$("#messageStyle").removeClass("panel-success")
	$("#messageStyle").removeClass("panel-danger")
	
	$("#messageStyle").addClass(mClass)
	$("#messagePanel").slideToggle()
	
	if(aclose)
		setTimeout(function(){ $("#messagePanel").slideToggle() }, 3000)
}

function select_all_bots()
{
	var total_chks = $('input[type=\"checkbox\"][name=\"elem_id[]\"]')
	
	var chks = $('input[type=\"checkbox\"][name=\"elem_id[]\"]:checked')
	
	if(chks.length > 0 && chks.length < total_chks.length)
		$('input[type=\"checkbox\"][name=\"elem_id[]\"]').each(function(a, e){ $(e).prop('checked', true); })
	else
		$('input[type=\"checkbox\"][name=\"elem_id[]\"]').each(function(a, e){ $(e).prop('checked', !$(e).prop('checked')); })
		
	update_mass_command_visibility()
}

function select_all_injects()
{
	var total_chks = $('input[type="checkbox"][name^="inj["]')
	
	var chks = $('input[type="checkbox"][name^="inj["]:checked')
	
	if(chks.length > 0 && chks.length < total_chks.length)
		$('input[type="checkbox"][name^="inj["]').each(function(a, e){ $(e).prop('checked', true); })
	else
		$('input[type="checkbox"][name^="inj["]').each(function(a, e){ $(e).prop('checked', !$(e).prop('checked')); })
}

function delete_mass_bots()
{
	var chks = $('input[type=\"checkbox\"][name=\"elem_id[]\"]:checked')
	if(chks.length == 0)
	{
		show_message("Select bots first", "error", true)
		return
	}

	if(!confirm('Are you surely want to delete elements?'))
		return


	var data = {
		'a':'admin', 
		'action':'bots'
	}
	
	// var url = "?a=admin&action=bots&";
	for(var i=0;i<chks.length;i++)
	{
		//url += "to_delete[]=" + $(chks[i]).val() + "&"
		data['to_delete['+i+']'] = $(chks[i]).val()
	}
	
	//location.href = url

	$.post('', data, function(data) {
	}).done(function(data){ 
		location.reload()
	})
}

// show Commands panel in Bots List for all selected bots
function mass_command()
{
	var chks = $('input[type=\"checkbox\"][name=\"elem_id[]\"]:checked')
	if(chks.length == 0)
	{
		show_message("Select bots first", "error", true)
		return
	}
	
	var bots = ""
	for(var i=0;i<chks.length;i++)
		bots += $(chks[i]).val() + ","
	
	show_commands(bots)
}

function save_comment_bots(bot_id)
{
	var comm = $('#comment_' + bot_id).val().trim()
	//if(comm == '') allow make comment empty
		//return

	var data = {
		'a':'admin', 
		'action':'bots', 
		'ajax': 'save_comment', 
		'comm_bot_id':bot_id, 
		'comment':comm
	}
	
	$.post('', data, function(data) {
		}).done(function(data){ 
			if(data.indexOf('SAVED_SUCCESS') > -1)
			{
				show_message("Comment saved", "ok", true)
				$('#save_comm_butt_' + bot_id).hide()
			}else
				show_message("Comment not saved", "error", true)
	})
}

function update_mass_command_visibility()
{
	var chks = $('input[type=\"checkbox\"][name=\"elem_id[]\"]:checked')
	if(chks.length == 0)
	{
		$("#mass_commands_panel").addClass("hidden")
	}else{
		$("#mass_commands_panel").removeClass("hidden")
	}
}


// Show commands panel in Bot list for Single Bot or for given IDs
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
		'ids':ids
	}
	
	$.post('', data, function(data) {

	}).done(function(data){ 
		$("#commandsPanelBody").html(data)
	})
	
	$('#commandsPanel').show()
}

function change_page()
{
	$("#page_var").val($("#page_number").val())
	$("#rows_var").val($("#rows_number").val())
	$("#filterform").submit()
}

function get_uninstalled_apps(bot_id)
{
	var data = {
		'a':'admin', 
		'action':'bots', 
		'ajax': 'get_uninstalled_apps', 
		'bot_id':bot_id
	}
	
	$.post('', data, function(data) {
		}).done(function(data){ 
			console.log(data)
			if(data == "")
				show_message("No apps uninstalled yet", "ok", true)
			else
				$('#uninstalled_apps_' + bot_id).html(data)
	})
}

function copyToClip(data)
{
	var tempInput = document.createElement("input");
	tempInput.style = "position: absolute; left: -1000px; top: -1000px";
	tempInput.value = data;
	document.body.appendChild(tempInput);
	tempInput.select();
	document.execCommand("copy");
	document.body.removeChild(tempInput);
}

function show_keylog(bot_id, filter)
{
	$('#loadButton_' + bot_id).hide()
	$('#loadGif_' + bot_id).show()
	
	var data = {
		'a':'admin', 
		'action':'bots', 
		'ajax': 'show_keylog', 
		'bot_id':bot_id,
		'filter':filter
	}
	
	$.post('', data, function(data) {
		document.getElementById('keylog_data_' + bot_id).innerHTML = data
	}).fail(function(data){ 
	
		console.log(data.statusText); 
		console.log(data.responseText); 
		console.log(data); 
	});
}

function showSaveButt(bot_id)
{
	$('#save_comm_butt_' + bot_id).show()
}

function toggle_check(id)
{
	$('#' + id).prop('checked', !$('#' + id).prop('checked'));
}

function select_all_logs(bot_id)
{
	$('#recordsTable_'+bot_id+' input[type="checkbox"][name="log_id[]"]').each(function(a, e){ $(e).prop('checked', !$(e).prop('checked')); })
}

function delete_mass_logs(smart_id, back_to_bot)
{

	var chks = $('input[type="checkbox"][name="log_id[]"]:checked')
	if(chks.length == 0)
	{
		show_message("Select logs first", "error", true)
		return
	}

	if(!confirm('Are you sure?'))
		return
	
	var url = "?a=admin&action=smarts&sub_action=manage&smart_id="+smart_id+"&do=delete_logs&";
	
	for(var i=0;i<chks.length;i++)
		url += "to_delete[]=" + $(chks[i]).val() + "&"

	if(back_to_bot != "")
		location.href = url + "&bot_id=" + back_to_bot
	else
		location.href = url + back_to_bot
}









