<!DOCTYPE html>
<html>
<head>
<meta charset="utf-8">
<title>MYUNGLI 실습예제</title>
<?php include "head.php";?>
<script src="/trans_js/?mod=write"></script>
<link rel="stylesheet" type="text/css" href="./css/member.css">
</head>
<body>
	<header>
    	<?php include "header.php";?>
    </header>
	<section class="fontstyle">
        <div id="main_content">
      		<div id="join_box">
		    <h2>회원 가입</h2>
		    	<div class="form id">
			        <div class="col1">아이디</div>
			        <div class="col2">
						<input type="text" id="u_id" name="u_id" class="fontstyle">
			        </div>  
			        <div class="col3">
			        	<a href="#"><div style="border : medium solid gray;border-radius : 10px;font-size : 12px">중복확인</div></a>
			        </div>                 
		       	</div>
		       	<div class="clear"></div>

		       	<div class="form">
			        <div class="col1">비밀번호</div>
			        <div class="col2">
						<input type="password" id="u_pass" name="u_pass" class="fontstyle" value="">
			        </div>                 
		       	</div>
		       	<div class="clear"></div>
		       	<div class="form">
			        <div class="col1">비밀번호 확인</div>
			        <div class="col2">
						<input type="password" id="u_pass_cf" name="u_pass_cf" class="fontstyle">
			        </div>                 
		       	</div>
		       	<div class="clear"></div>
		       	<div class="form">
			        <div class="col1">이름</div>
			        <div class="col2">
						<input type="text" id="u_name" name="u_name" class="fontstyle" value="">
			        </div>                 
		       	</div>
		       	<div class="clear"></div>
		       	<div class="form email">
			        <div class="col1">이메일</div>
			        <div class="col2">
						<input type="text" id="email1" name="email1" class="fontstyle">@<input type="text" id="email2" name="email2" class="fontstyle">
			        </div>                 
		       	</div>
		       	<div class="clear"></div>
		       	<div class="bottom_line"> </div>
		       	<div class="buttons">
		       	<input type="button" value="저장" style="width : 70px;border : medium solid gray; cursor : pointer;" class="fontstyle" id='abcd'>
              	<input type="reset" value="취소" style="width : 70px;border : medium solid gray; cursor : pointer;" class="fontstyle">
           		</div>
        	</div> <!-- join_box -->
        </div> <!-- main_content -->
	</section> 
	<footer>
    	<?php include "footer.php";?>
    </footer> 
</body>
</html>