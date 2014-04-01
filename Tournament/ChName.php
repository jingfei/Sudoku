<?php
	session_start();
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
## check connection
	if($mysqli->connect_errno)
	echo "<p>MYSQL error no {$mysqli->connect_errno} : {$mysqli->connect_error}</p>";
##
	$Name=htmlspecialchars($_POST['name'], ENT_QUOTES);
	$Name=addslashes($Name);
	$Name=trim($Name);
	if(strlen($Name)>0 && strlen($Name)<17 && isset($_SESSION['id'])){
		$ID=$_SESSION['id'];
		$sql="UPDATE `Users` SET name='$Name' WHERE id='$ID'";
		$result=$mysqli->query($sql);
	}
?>
