<?php
require_once("$_SERVER[DOCUMENT_ROOT]/../lib/lib_road.inc");

$lib->lib_fun("session_start_print");
$session_start_print->session_start_print_();

unset($_SESSION["userid"]);
unset($_SESSION["username"]);
unset($_SESSION["userlevel"]);
unset($_SESSION["userpoint"]);

$echo_data = array(
    'Prevent' => array("Prevent")//변수 변동 방지(json_connet라이브러리 문제)
);

$lib->lib_fun("json_connet");
echo $json_connet->json_connet_($echo_data);
?>