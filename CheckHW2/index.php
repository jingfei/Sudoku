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
	<body>
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
		<?php include "footer.php"; ?>
	</body>
</html>
