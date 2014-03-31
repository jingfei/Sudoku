<?php
	session_start();
	unset($_SESSION['user']);
	session_destroy();
?>
<html>
	<head>
		<title>Programming Design II hw2 checking</title>
		<link rel="stylesheet" href="style/style.css"/>
		<link rel="stylesheet" href="style/form.css"/>
		<script type="text/javascript" src="script/jquery-2.0.3.js"></script>
		<style>
#SudokuImage{
	position: absolute;
	bottom: 70px;
	display: block;
	right: 30px;
	background: transparent;
	width: 80%;
}
#SudokuImage:hover{
	-webkit-border-radius: 10px;
	-moz-border-radius: 10px;
	border-radius: 10px;
	border: none;
	/* Fallback for web browsers that don't support RGBa */
    background-color: rgb(0, 0, 0);
    /* RGBa with 0.6 opacity */
    background-color: rgba(0, 0, 0, 0.2);
    /* For IE 5.5 - 7*/
    filter:progid:DXImageTransform.Microsoft.gradient(startColorstr=#99000000, endColorstr=#99000000);
    /* For IE 8*/
    -ms-filter: "progid:DXImageTransform.Microsoft.gradient(startColorstr=#99000000, endColorstr=#99000000)";
}
</style>
	</head>
		<script>
function Login(){
	$('.form-1').hide();
	$('#Waiting').show();
	$.ajax({
		type: "POST",
		url: "login.php",
		data:{
			user: $('#user').val(),
			passwd: $('#passwd').val()
		}
	}).done(function(response){
		if(response==='yes') location.replace("attack.php");
		else alert(response);
		$('#Waiting').hide();
		$('.form-1').show();
	});
	return false;
}
		</script>
	<body style="width:100%">
		<h1 align="center" style="padding:20px;">Please login with your student ID and the password used in moodle</h1>
		<form class="form-1" onsubmit="return Login();"> 
		    <p class="field">
		        <input type="text" id="user" placeholder="Student ID">
		        <i class="icon-user icon-large"></i>
		    </p>
		        <p class="field">
		        <input type="password" id="passwd" placeholder="Password">
		        <i class="icon-lock icon-large"></i>
		    </p>        
		    <p class="submit">
		        <button type="submit" name="submit"><i class="icon-arrow-right icon-large"></i></button>
		    </p>
		</form>
		<div id="Waiting" style="text-align:center;margin:60px;display:none;">
			<img src="ajax-loader.gif"/>
		</div>

		<div style="width:80%;text-align:center;">
			<div  id="SudokuImage">
			<a href="http://judge.imslab.org/Tournament"><img src="../image/logo.png"/></a>		
			</div>
		</div>
		<?php include "footer.php"; ?>
	</body>
</html>
