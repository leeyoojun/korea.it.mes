<?php 
require_once("$_SERVER[DOCUMENT_ROOT]/../lib/lib_road.inc");

$id = $_POST["u_id"];
$pass = $_POST["u_pass"];

$lib->lib_fun("value_check2");
if(!$value_check2->value_check2_(array($id,$pass))){
    $error = "인자가 부족하여 처리 할 수 없습니다.";
    goto error;
}

$lib->lib_fun("db_connect");
$db_connect->db_connect_();

$lib->lib_fun("data_ione_row_return");
$row = $data_ione_row_return->data_ione_row_return_("*","members","id='$id'","","");

$db_connect->db_close_();

if (!$row['id']) {
    $error = "등록되지 않은 아이디입니다!";
} else {
    if ($pass != $row["pass"]) {
        $error = "비밀번호가 틀립니다!";
    } else {
        $lib->lib_fun("session_start_print");
        $session_start_print->session_start_print_();
        
        $_SESSION["userid"] = $row["id"];
        $_SESSION["username"] = $row["name"];
        $_SESSION["userlevel"] = $row["level"];
        $_SESSION["userpoint"] = $row["point"];
    }
}

error:
$echo_data = array(
    'error' => $error,
    'Prevent' => array("Prevent")//변수 변동 방지(json_connet라이브러리 문제)
);

$lib->lib_fun("json_connet");
echo $json_connet->json_connet_($echo_data);
?>