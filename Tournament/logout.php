<?php
	session_start();
	if($_POST['id']==$_SESSION['id']){
		unset($_SESSION['id']);
		unset($_SESSION['op']);
		session_destroy();
	}
?>
