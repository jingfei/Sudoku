<?php
	require_once("db_const.php");
	session_start();
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
	$ID=$_SESSION['user'];
	$sql="SELECT * from `Users` WHERE id='$ID'";
	$result=$mysqli->query($sql);
	$row=$result->fetch_array();
	switch($row['correct']){
		case 0: echo 'ac'; break;
		case 1: echo 'ce'; break;
		case 2: echo 'tle'; break;
		case 3: echo 'wa'; break;
		case 4: echo 'err'; break;
		case 5: echo 'pe'; break;
	}
?>
