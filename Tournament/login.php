<?php
	session_start();
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
	## check connection
	if($mysqli->connect_errno){
		echo "<p>MYSQL error no {$mysqli->connect_errno} : {$mysqli->connect_error}</p>";
//		exit();
	}
	##
	$ID=$_POST['id']; $pw=md5($_POST['passwd']);
	$sql="SELECT * FROM `Users` WHERE id='$ID'";
	$result=$mysqli->query($sql);
	$row=$result->fetch_array();
	if(!$row)
		echo 'Student ID is not exist here';
	else if($row['passwd']!=$pw)
		echo 'wrong password';
	else{
		$_SESSION['id']=$ID;
		echo 'yes';
	}
?>
