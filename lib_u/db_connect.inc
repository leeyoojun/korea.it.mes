<?php
class db_connect extends lib_road{
    var $password = "";
    var $version = "";
    var $type = "";
    var $description = "";
    function db_connect_(){
        if ( !( $GLOBALS['conn'] = mysqli_connect("localhost","8084localhost","qwer1234","8084localhost","3308") ) ){
            exit( "MYSQL DB SERVER connect ERROR" );
        }
        mysqli_select_db( $GLOBALS['conn'], "8084localhost" );
        
        mysqli_query( $GLOBALS['conn'], "SET session character_set_client = 'UTF8'");
        mysqli_query( $GLOBALS['conn'], "SET session character_set_connection = 'UTF8'");
        mysqli_query( $GLOBALS['conn'], "SET session character_set_results = 'UTF8'");
        mysqli_query( $GLOBALS['conn'], "SET session character_set_server = 'UTF8'");
    }
    
    function db_close_(){
        if($GLOBALS['conn']){
            mysqli_close($GLOBALS['conn']);
        }
    }
}
?>