<!DOCTYPE html>
<html>
<head> 
<meta charset="utf-8">
<title>MYUNGLI 실습예제</title>
<?php include "head.php";?>
<script src="/trans_js/?mod=modify"></script>
<link rel="stylesheet" type="text/css" href="./css/member.css">
</head>
<body> 
	<header>
    	<?php include "header.php";?>
    </header>
	<section class="fontstyle">
        <div id="main_content">
      		<div id="join_box">
			    <h2>회원 정보수정</h2>
    		    	<div class="form id">
				        <div class="col1">아이디</div>
				        <div class="col2" >userid</div>                 
			       	</div>
			       	<div class="clear"></div>

			       	<div class="form">
				        <div class="col1">비밀번호</div>
				        <div class="col2">
							<input type="password" name="u_pass" value="pass">
				        </div>                 
			       	</div>
			       	<div class="clear"></div>
			       	<div class="form">
				        <div class="col1">비밀번호 확인</div>
				        <div class="col2">
							<input type="password" name="u_pass_cf" value="pass">
				        </div>                 
			       	</div>
			       	<div class="clear"></div>
			       	<div class="form">
				        <div class="col1">이름</div>
				        <div class="col2" >
							<input type="text" name="u_name" value="name" class="fontstyle">
				        </div>                 
			       	</div>
			       	<div class="clear"></div>
			       	<div class="form email">
				        <div class="col1">이메일</div>
				        <div class="col2">
							<input type="text" name="email1" value="email1" class="fontstyle">@<input type="text" name="email2" value="email2" class="fontstyle">
				        </div>
			       	</div>
			       	<div class="clear"></div>
			       	<div class="bottom_line"> </div>
			       	<div class="buttons">
	                	<input type="button" value="수정" style="width : 70px;border : medium solid gray" class="fontstyle">
	                	<input type="reset" value="초기화" style="width : 70px;border : medium solid gray" class="fontstyle">
	           		</div>
        	</div> <!-- join_box -->
        </div> <!-- main_content -->
	</section> 
	<footer>
    	<?php include "footer.php";?>
    </footer>
</body>
</html>

