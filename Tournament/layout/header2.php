<html>
	<head>
		<title>SUDOKU tournament</title>
		<link rel="stylesheet" href="./style/top.css">
		<script type="text/javascript" src="./style/jquery-2.0.3.js"></script>
		<script type="text/javascript" src="./style/heartcode-canvasloader-min.js"></script>
		<script type="text/javascript" src="./style/js.js"></script>
	</head>
	<body>
		<div id="logo">
			<hr>
			<div id="top" align="right">
				<div class="top2" onclick="location.href='index.php';">Sudoku</div>
<?php
			if(isset($_SESSION['id'])){
				echo '<div class="top2" onclick="location.href=\'Log.php\';">Record</div>';
				echo '<div class="top2" onclick="Setting();">Setting</div>';
				echo '<div class="top2" onclick="LogOut(\''.$_SESSION['id'].'\');">Log Out</div>';
			}
			else
				echo '<div class="top2" onclick="LogIn();">LOG IN</div>';
?>
			</div>
			<hr>
			<div id="Setting" style="display:none">
				<form onsubmit="return ChName();" action="#">
				<input type="text" id="NewName" placeholder="Change Name (length<16 )" />
				<input type="submit" value="submit" />
				</form>
			<hr>
			</div>
<?php
			if(isset($_SESSION['id'])){
				$ID=$_SESSION['id'];
				$sql="SELECT * FROM `Users` WHERE id='$ID'";
				$result=$mysqli->query($sql);
				$row=$result->fetch_array();
				echo '<div id="RemainTime" align="left">';
				echo 'Hello~ '.$row['name'].'. You have '.$row['challenge'].' chance(s) to challenge.';
				echo '<hr/></div>';
			}
?>
			<img id="big" src="./image/sudoku2.jpg"/>
			<img id="small" src="./image/logo.png"/>
		</div>
