<?php 
require_once("$_SERVER[DOCUMENT_ROOT]/../lib/lib_road.inc");

$lib->lib_fun("session_start_print");
$session_start_print->session_start_print_();

$_POST['send_id'] ? $send_id = $_POST['send_id'] : $send_id = $_SESSION["userid"];

$rv_id = $_POST['rv_id'];
$subject = $_POST['subject'];
$content = $_POST['content'];


if(!$send_id) {
    $error = "로그인 후 이용해 주세요!";
    goto error;
}

$lib->lib_fun("value_check2");
if(!$value_check2->value_check2_(array($rv_id,$subject,$content))){
    $error = "인자가 부족하여 처리 할 수 없습니다.";
    goto error;
}

$subject = htmlspecialchars($subject, ENT_QUOTES);
$content = htmlspecialchars($content, ENT_QUOTES);

$lib->lib_fun("db_connect");
$db_connect->db_connect_();

$lib->lib_fun("dbi_total_counter");
$num_record = $dbi_total_counter->dbi_total_counter_("members","id='$rv_id'");

if($num_record){
    $lib->lib_fun("dbi_insert");
    $sql = $dbi_insert->dbi_insert_("message","send_id, rv_id, subject, content,  regist_day","'$send_id', '$rv_id', '$subject', '$content', '$regist_day'");
    
    if($sql){
        $error = "입력 중 오류가 발생했습니다.";
    }
} else {
    $error = "수신 아이디가 잘못 되었습니다!";
}

$db_connect->db_close_();

error:
$echo_data = array(
    'error' => $error,
    'Prevent' => array("Prevent")//변수 변동 방지(json_connet라이브러리 문제)
);

$lib->lib_fun("json_connet");
echo $json_connet->json_connet_($echo_data);
?>