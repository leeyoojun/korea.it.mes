$(document).ready(function(){
	javascript_onload_src("script_trns_form_submit_ajax");
	javascript_onload_src("script_id_check");
	javascript_onload_src("script_2notvalue_check");
	javascript_onload_src("script_pass_check");
	javascript_onload_src("script_text_check");
	javascript_onload_src("script_email_check2");
	
	script_new_reformdata("#main_content","myform","/mem_form.php","insert");
	$('#myform').append($('<input/>',{type:'hidden',name:'id_dup',value:''}));
	
	$(".buttons > input:first-child").click(function(){
		if(!script_id_check("myform","u_id","아이디")){
			return false;
		}else if(!script_2notvalue_check("myform","u_pass","u_pass_cf","비밀번혹 일치하지 않습니다.")){
			return false;
		}else if(!script_text_check("myform","u_name","이름을 입력해 주세요.")){
			return false;
		}else if(!script_email_check2("myform","email1","email2","이메일을 입력해 주세요!")){
			return false;
		}else{
			let formData = new FormData(document.getElementById("myform"));
			script_trns_form_submit_ajax(formData,"/index.php");
		}
	});
	
	javascript_onload_src("script_win_open");
	$(".col3 > a > div").click(function(){
		script_win_open('mem_chk_id.php?u_id='+$("input[name=u_id]").val(),"mem_check","350","200","y");		
	});
	
	$(".buttons > input:last-child").click(function(){
		$("#myform")[0].reset();
	});
});