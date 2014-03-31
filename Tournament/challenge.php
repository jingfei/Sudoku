<?php
	session_start(); 
	if(!isset($_SESSION['id'])){
		echo "<script>alert('Log in please~')</script>";
		echo '<script>location.replace("./index.php");</script>';
	}
	else if(!isset($_POST['op'])){
		echo "<script>alert('select an opponent');</script>";
		echo "<script>location.replace('./index.php');</script>";
	}
	$op=$_POST['op'];
	$_SESSION['op']=$op;
	$ID=$_SESSION['id'];
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
## check connection
	if($mysqli->connect_errno){
		echo "<p>MySQL error no {$mysqli->connect_errno} : {$mysqli->connect_error}</p>";
		exit();
	}
##
	if($op!='test'){
		$sql="SELECT * FROM `Users` WHERE id='$ID'";
		$result=$mysqli->query($sql);
		$row=$result->fetch_array();
		if($row['challenge']<=0){
			$sql="UPDATE `Users` SET challenge=0 WHERE id='$ID'";
			$result=$mysqli->query($sql);
			echo "<script>alert('you challenged too much!!');</script>";
			echo "<script>location.replace('./index.php');</script>";
		}
		/*find challenge list*/
		$arr=array();
		$arr=unserialize($row['challenge_id']);
		if($arr)
			foreach($arr as $item)
				if($item==$op){
					echo "<script>alert('you have challenged him today');</script>";
					echo "<script>location.replace('./index.php');</script>";
					exit();
				}
		/*********************/
	}
	else echo "<script>location.replace('attack.php');</script>";
?>
<? include_once('layout/header.php'); ?>
		<div class="main">
			<h1 class="title">Challenge</h1>
			<div id="information">
				<img src="./image/wanted.jpg"/>
				<table>
<?php					
	$sql="SELECT * FROM `Users` WHERE id='$op'";
	$result=$mysqli->query($sql);
	$row=$result->fetch_array();
	echo '<tr><th>name</th><td>'.$row['name'].'</td></tr>
					<tr><th>rank</th><td>'.$row['rank'].'</td></tr>
					<tr><th>score</th><td>'.$row['score'].'</td></tr>';
?>
				</table>
			</div>
			<div id="regular">
				<textarea wrap="off" rows="10" cols="55" style="font-size:15px;background:#cacaca;color:#0060bf;font-weight:bold" readonly>
				<?php 
					$file=fopen("Regular.txt","r");
					echo "\n";
					if($file)
						while(!feof($file))
							echo fgets($file);
					fclose($file);
				?>
				</textarea>	
			</div><br/>
			<div class="ButtonDiv">
				<h2>Ready to attack?</h2>
				<img src="./image/button/go.png" class="Button" onclick="Attack();"/> 
				<img src="./image/button/wait.png" class="Button" onclick="location.href='/Tournament/';"/> 
			</div>
		</div>
<?php include_once('layout/footer.php'); ?>
