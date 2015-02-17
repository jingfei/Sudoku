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
	else echo '<a href="/SudokuTournament">Sudoku Tournament</a>'
?>
&nbsp</h1></td>
	<td align="right">
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
		onclick="location.href='log';">Record</div>
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
			{{ HTML::image("img/sudoku2.jpg", "", array('class'=>'big')) }}
		</div>
	</div>
	{{ HTML::image("img/logo.png", "", array('class'=>'small')) }}
</div>
<!--hidden-->
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
<!--hidden-->
