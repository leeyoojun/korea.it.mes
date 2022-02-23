<?php
require_once("$_SERVER[DOCUMENT_ROOT]/../lib/lib_road.inc");

$lib->lib_fun("session_start_print");
$session_start_print->session_start_print_();

$lib->lib_fun("value_check2");
if(!$value_check2->value_check2_(array($_SESSION['userid']))){
    $error = "로그인 후 이용할 수 있습니다.";
    goto error;
}

$lib->lib_fun("db_connect");
$db_connect->db_connect_();

$lib->lib_fun("data_ione_row_return");
$row = $data_ione_row_return->data_ione_row_return_("*","members","id='$_SESSION[userid]'","","");

$email = explode("@", $row["email"]);
$row['email1'] = $email[0];
$row['email2'] = $email[1];

$db_connect->db_close_();

error:
$row['error'] = $error;
$row['Prevent'] = array("Prevent");

$lib->lib_fun("json_connet");
echo $json_connet->json_connet_($row);
?>