<html>
	<head>
		<title>SUDOKU tournament</title>
		<link href='http://fonts.googleapis.com/css?family=Sofadi+One' rel='stylesheet' type='text/css'>
		<link rel="stylesheet" href="./style/index.css">
		<link rel="stylesheet" href="./style/top.css">
		<link rel="stylesheet" href="CppStyle/sh_vim-dark.min.css" />
		<script type="text/javascript" src="CppStyle/sh_cpp.min.js"></script>
		<script type="text/javascript" src="CppStyle/sh_main.min.js"></script>
		<script type="text/javascript" src="./style/jquery-2.0.3.js"></script>
		<script type="text/javascript" src="./style/js.js"></script>
		<script type="text/javascript" src="./style/jquery.flippy.js"></script>
		<script type="text/javascript" src="./style/heartcode-canvasloader-min.js"></script>
	</head>
	<body>
		<div id="logo">
			<hr>
			<div id="top">
			<table width="100%"><tr><td align="left">
		<h1 style="display:table-cell;" >
		
<?php
	if($_SERVER["REQUEST_URI"]=='/Tournament/challenge.php')
		echo 'Challenge';
	else if($_SERVER["REQUEST_URI"]=='/Tournament/attack.php')
		echo 'Attack';
	else echo '<a href="http://judge.imslab.org/Tournament">Sudoku Tournament</a>'
?>
&nbsp</h1></td>
			<td align="right">
				<div 
<?php 
				if($_SERVER["REQUEST_URI"]=='/') 
					echo 'class="topClick top2"'; 
				else echo 'class="top2"';
?> 
				id="Sudoku" onclick="ChFlip('Sudoku');">Sudoku</div>
				<div class="top2" id="Rule" onclick="ChFlip('Rule');">Rule</div>
				<div
<?php
				if($_SERVER["REQUEST_URI"]=="/Tournament/") 
					echo 'class="topClick top2"'; 
				else echo 'class="top2"';
?>
				onclick="location.href='/Tournament/';">Rank</div>
				<div
<?php
				if($_SERVER["REQUEST_URI"]=="/Tournament/Log.php") 
					echo 'class="topClick top2"'; 
				else echo 'class="top2"';
?>
				onclick="location.href='Log.php';">Record</div>
<?php
			if(isset($_SESSION['id'])){
				echo '<div class="top2" onclick="Setting();">Setting</div>';
				echo '<div class="top2" onclick="LogOut(\''.$_SESSION['id'].'\');">Logout</div>';
			}
			else
				echo '<div class="top2" onclick="LogIn();">Login</div>';
?>
			</div>
			</td></tr></table>
			<hr>
			<div id="LogIn" style="display:none">
				<form onsubmit="return LogInCheck();" action="#">
				<input type="text" id="login_id" placeholder="StudentID" />
				<input type="password" id="login_pw" placeholder="Password" />
				<input type="submit" value="submit" />
				</form>
			<hr>
			</div>
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
				echo '<div id="RemainTime">';
				echo '<table style="width:100%"><tr>
				<td class="title" style="width:10%;font-size:inherit"><a href="http://judge.imslab.org/CheckHW2/" target="_blank">Checker</a></td><td style="width:90%;">';
				echo 'Hello~ '.$row['name'].'. You\'re
				<a href="#" onclick="GO();" style="text-decoration:underline;">rank '.$row['rank'].'</a>, 
				and you have '.$row['challenge'].' chance(s) to challenge.';
				echo '</td></tr></table><hr/></div>';
			}
?>
</div>
		<div class="flipbox-container">
				<div class="flipbox">
				<img class="big" src="./image/sudoku.jpg"/></div>
			</div>
			<img class="small" src="./image/logo.png"/>
		</div>
<!--hidden-->
		    <div id="flipImg0" style="display:none;">
				<img class="big" src="../image/sudoku.jpg"/>
		    </div>
		    <div id="flipImg1" style="display:none;">
				<img class="big" src="../image/Sudoku/sudoku2.jpg"/>
		    </div>
		    <div id="flipImg2" style="display:none;">
				<img class="big" src="../image/Sudoku/sudoku3.jpg"/>
		    </div>
		    <div id="flipText" style="display:none;">
				<textarea id="Regu" readonly>
				<?php 
					$file=fopen("Regular.txt","r");
					echo "\n";
					if($file)
						while(!feof($file))
							echo fgets($file);
					fclose($file);
					for($i=0; $i<15; $i++) echo "\n";
				?>
				</textarea>
		    </div>
<!--hidden-->';
