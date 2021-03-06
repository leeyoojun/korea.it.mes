$(document).ready(function(){

	script_new_reformdata("#main_content","myform","/mem_modify_form.php","update");	
	$('#myform').append($('<input/>',{type:'hidden',name:'u_id',value:''}));
	
	/*js 스크립트 불러오기*/
	javascript_onload_src("script_trns_form_submit_ajax");
	javascript_onload_src("script_id_check");
	javascript_onload_src("script_2notvalue_check");
	javascript_onload_src("script_pass_check");
	javascript_onload_src("script_text_check");
	javascript_onload_src("script_email_check2");

	$(".buttons > input:nth-child(1)").click(function(){
		if(!script_id_check("myform","u_id"," 아이디")){
			return false;
		}else if(!script_pass_check("myform","u_pass","비밀번호")){
			return false;
		}else if(!script_2notvalue_check("myform","u_pass","u_pass_cf","비밀번호가 일치하지 않습니다.")){
			return false;
		}else if(!script_text_check("myform","u_name","이름를 입력해 주세요!")){
			return false;
		}else if(!script_email_check2("myform","email1","email2","이메일을 입력해 주세요!")){
			return false;
		}else{
			let formData = new FormData(document.getElementById("myform"));
			script_trns_form_submit_ajax(formData,"/mem_modify_form.php");
		}
	});
	
	$(".buttons > input:last-child").click(function(){
		document.myform.reset();
	});	
	
	$.ajax({
		url:'/trans_page_file/',
		type:'POST',
		cache:false,
		data:{
			"mod":"data"
		},
		dataType:'json',
		success: function(data){
			if(!data.id){
				alert(data.error);
				location.href="/";
			}else{
				$(".id .col2").text(data.id);
				$("input[name='u_id']").val(data.id);
				$("input[name='u_pass']").val(data.pass);
				$("input[name='u_pass_cf']").val(data.pass);
				$("input[name='u_name']").val(data.name);
				$("input[name='email1']").val(data.email1);
				$("input[name='email2']").val(data.email2);
			}
		},
		error:function(request, status, error){
			alert("데이터 조회중 오류가 발생했습니다. 관리자에게 문의해 주세요.");
            console.log("code:" + request.status + "\n" + "message:" + request.responseText + "\n" + "error:" + error);
		}
	});
});