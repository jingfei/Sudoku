<?php
	session_start();
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
## check connection
	if($mysqli->connect_errno)
	echo "<p>MYSQL error no {$mysqli->connect_errno} : {$mysqli->connect_error}</p>";
##
	$Name=$_POST['name'];
	$tmp=strpos($Name,'&');
	while( $Name[0]=='&' || $tmp ){
		$Name=substr_replace($Name,"&amp",$tmp,1);
		$tmp=strpos($Name,'&',$tmp+1);
	}
	$tmp=strpos($Name,'<');
	while( $Name[0]=='<' || $tmp ){
		$Name=substr_replace($Name,"&lt",$tmp,1);
		$tmp=strpos($Name,'<',$tmp+1);
	}
	$tmp=strpos($Name,'>');
	while( $Name[0]=='>' || $tmp ){
		$Name=substr_replace($Name,"&gt",$tmp,1);
		$tmp=strpos($Name,'>',$tmp+1);
	}
	$ID=$_SESSION['id'];
	$sql="UPDATE `Users` SET name='$Name' WHERE id='$ID'";
	$result=$mysqli->query($sql);
?>
