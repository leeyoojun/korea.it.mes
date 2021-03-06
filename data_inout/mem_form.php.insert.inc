<?php 
require_once("$_SERVER[DOCUMENT_ROOT]/../lib/lib_road.inc");

$id   = $_POST["u_id"];
$pass = $_POST["u_pass"];
$name = $_POST["u_name"];
$email1  = $_POST["email1"];
$email2  = $_POST["email2"];

$lib->lib_fun("value_check2");
if(!$value_check2->value_check2_(array($id,$pass,$name,$email1,$email2))){
    $error = "인자가 부족하여 처리 할 수 없습니다.";
    goto error;
}

$email = $email1."@".$email2;
$regist_day = date("Y-m-d (H:i)");  // 현재의 '년-월-일 (시:분)'을 저장

$lib->lib_fun("db_connect");
$db_connect->db_connect_();

$lib->lib_fun("dbi_insert");
$sql = $dbi_insert->dbi_insert_("members","id, pass, name, email, regist_day, level, point","'$id', '$pass', '$name', '$email', '$regist_day', 9, 0");

$db_connect->db_close_();

if($sql){
    $error = "입력 중 오류가 발생했습니다.";
}

error:
$echo_data = array(
    'error' => $error,
    'Prevent' => array("Prevent")//변수 변동 방지(json_connet라이브러리 문제)
);

$lib->lib_fun("json_connet");
echo $json_connet->json_connet_($echo_data);
?>