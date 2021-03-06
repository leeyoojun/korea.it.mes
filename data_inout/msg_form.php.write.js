$(document).ready(function(){
	script_new_reformdata("#write_msg","myform","/msg_form.php","insert");
    
	/*js 스크립트 불러오기*/
	javascript_onload_src("script_trns_form_submit_ajax");
	javascript_onload_src("script_id_check");
	javascript_onload_src("script_text_check");
	$("#write_msg > button").click(function(){
		if(!script_id_check("myform","rv_id","수신 아이디")){
			return false;
		}else if(!script_text_check("myform","subject","제목을 입력해 주세요!")){
			return false;
		}else if(!script_text_check("myform","content","내용을 입력해 주세요!")){
			return false;
		}else{
			let formData = new FormData(document.getElementById("myform"));
			script_trns_form_submit_ajax(formData,"/msg_box.php?mode=send");
		}
	});
	
	$.ajax({
		url:"/trans_page_file/",
		type:"POST",
		cache:false,
		data:{
			"mod":"data",
			"ajax_link_page":"/header.php"
		},
		dataType:"json",
		success:function(data){
			if(data.userid){
				$("#write_msg > ul > li:nth-child(1) > span:nth-child(2)").text(data.userid);
			}else{
        		alert("로그인 후 이용해 주세요!");
        		location.href='/lgi_form.php';
			}
		},
		error:function(request, status, error){
			alert("데이터 조회 중 오류가 발생 했습니다.");
            console.log("code:" + request.status + "\n" + "message:" + request.responseText + "\n" + "error:" + error);
		}
	});	
});