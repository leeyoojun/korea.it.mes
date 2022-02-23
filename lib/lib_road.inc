<?php
require_once("$_SERVER[DOCUMENT_ROOT]/../lib/ysolib.inc");
$lib = new lib_road();
$lib->lib_road_dir_("$_SERVER[DOCUMENT_ROOT]/../lib");
$lib->ulib_road_dir_("$_SERVER[DOCUMENT_ROOT]/../lib_u");
$lib->lib_token_("81582e5eff9b893383def8c5987971d8fe3fd1e7a7e54c341e9f222bb3ab2334");
$lib->lib_password_("");
$lib->update_yn = "Y";
$lib->upload_yn = "Y";
$lib->lib_start();

$lib->lib_fun("tellers_trans");
$tellers_trans->tellers_trans_();
?>