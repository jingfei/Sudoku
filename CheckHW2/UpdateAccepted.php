<?php
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
	session_start();
	$ID=$_SESSION['user'];
	$sql="UPDATE `Users` SET correct=0 WHERE id='$ID'";
	$mysqli->query($sql);
?>

