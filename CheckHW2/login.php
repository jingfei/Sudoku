<?php
//echo get_cfg_var('cfg_file_path').'\n';
//ini_set('display_errors', 1);
//error_reporting(~0);
	/**/
session_start();
require_once("db_const.php");
$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
## check connection
if($mysqli->connect_errno){
	echo "MYSQL error no {$mysqli->connect_errno} : {$mysqli->connect_error}";
	exit();
}
##
$ID=$_POST['user']; $pw=md5($_POST['passwd']);
	if(substr($ID,0,2)=="an") $ID=substr_replace($ID,"AN",0,2);
	else if(substr($ID,0,1)=="c") $ID=substr_replace($ID,"C",0,1);
	else if(substr($ID,0,1)=="e") $ID=substr_replace($ID,"E",0,1);
	else if(substr($ID,0,1)=="f") $ID=substr_replace($ID,"F",0,1);
	else if(substr($ID,0,1)=="h") $ID=substr_replace($ID,"H",0,1);
$sql="SELECT * FROM `Users` WHERE id='$ID'";
$result=$mysqli->query($sql);
$row=$result->fetch_array();
if(!$row)
	echo 'Student ID is not exist here';
else if($row['passwd']==$pw){
	echo 'yes';
	$_SESSION['user']=$ID;
}
else{
	$passwd = htmlspecialchars($_POST['passwd']);
	$user = htmlspecialchars($ID);
	$link = imap_open("{mail.ncku.edu.tw:143/novalidate-cert}",$user,$passwd) ;
//	or die('Cannot connect to Friggin Server: ' . print_r(imap_errors()));
	if($link){
		imap_close($link);//Close the connection
		echo "yes";
		$_SESSION['user']=$ID;
	}
	else{
		imap_close($link);
		echo 'wrong password';
	}
}
?>
