<?php
	session_start();
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
## check connection
	if($mysqli->connect_errno)
	echo "<p>MYSQL error no {$mysqli->connect_errno} : {$mysqli->connect_error}</p>";
##
	$Name=$_POST['name'];
	$ID=$_SESSION['id'];
	$sql="UPDATE `Users` SET name='$Name' WHERE id='$ID'";
	$result=$mysqli->query($sql);
?>
