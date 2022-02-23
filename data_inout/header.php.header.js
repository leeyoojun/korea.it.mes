$(document).ready(function(){
	$.ajax({
		url:'/trans_page_file/',
		type:'POST',
		cache:false,
		data:{
			"mod":"data",
			"ajax_link_page":"/header.php"
		},
		dataType:'json',
		success:function(data){
			if(!data.userid){
				$("#top_menu > li:nth-child(n+6)").hide();
			}else{
				var logged = data.username+"("+data.userid+")님[Level:"+data.userlevel+", point:"+data.userpoint+"]";
				$("#top_menu > li:nth-child(7)").text(logged);
				$("#top_menu > li:nth-child(-n+6)").hide();
			}
			
			if(data.userlevel=="1"){
				$("#top_menu > li:nth-child(n+14)").show();
			}else{
				$("#top_menu > li:nth-child(n+14)").hide();				
			}
		},
		error:function(request, status, error){
			console.log("code:" + request.status + "\n" + "message:" + request.responseText + "\n" + "error:" + error);		
		}
	});

	javascript_onload_src("script_trns_form_submit_ajax");
	$("#top_menu > li:nth-child(13)").click(function(){
		let formData = new FormData();
		formData.append("ajax_link_page", "/header.php");
		formData.append("mod", "logout");
		script_trns_form_submit_ajax(formData,"/index.php");		
	});	
});