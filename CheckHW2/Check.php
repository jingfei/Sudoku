<?php
/* change line 9 $timeout to modify timeout */
	include 'Timeout.php';
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
	session_start();
	$ID=$_SESSION['user'];
	$r=$_POST['Rand'];
	$cmd='./tmpCode/'.$ID.'/hw2_check '.$ID.' '.(string)$r;
	$timeout=30; //seconds
	$Wrong=false; 
	/*check timelimit*/
	if(exec_timeout($cmd, $timeout)){
		echo '<img src="StatusImg/tle.png" />';
		$sql="UPDATE `Users` SET correct=2 WHERE id='$ID'";
		$mysqli->query($sql);
		$Wrong=true;
	}
	/*****************/
	/*check answer*/
	else if(!is_file('./tmpCode/'.$ID.'/Correct')){
		$Wrong=true; 
		$Mes='file not exist, please contact with TA';
		echo '<img src="StatusImg/err.png" /><h1>'.$Mes.'</h1>';
		$sql="UPDATE `Users` SET correct=4 WHERE id='$ID'";
		$mysqli->query($sql);
	}
	else{
		$AnsPath="./outputs/ans/ans".(string)$r;
		$CodePath="./tmpCode/".$ID."/Correct";
		$Check=exec('diff -w -B '.$AnsPath.' '.$CodePath);
		if($Check){ 
			echo '<img src="StatusImg/wa.png" /><br/>';
			$sql="UPDATE `Users` SET correct=3 WHERE id='$ID'";
			$mysqli->query($sql);
			$Wrong=true;
			//ansCode
			$ansCode="<table style='font-size:30px;padding:5px;'><tr><th style='color:blue'>Answer</th></tr>";
			$file = fopen($AnsPath,"r");
			if($file)
				while(!feof($file)){
					$ansCode.="<tr><td>";
					$ansCode.=fgets($file);
					$ansCode.="</td></tr>";
				}
			fclose($file);
			$ansCode.="</table>";
			//waCode
			$waCode="<table style='font-size:30px;padding:5px;'><tr><th style='color:blue'>Yours</th></tr>";
			$file = fopen($CodePath,"r");
			if($file)
				while(!feof($file)){
					$waCode.="<tr><td>";
					$waCode.=fgets($file);
					$waCode.="</td></tr>";
				}
			fclose($file);
			$waCode.="</table>";
			echo "<div style='display:inline-block;margin-right:10%;vertical-align:top;' width='40%'>".$ansCode."</div>";
			echo "<div style='display:inline-block;margin-left:10%;vertical-align:top;' width='40%'>".$waCode."</div>";
		}
	}
	shell_exec("rm ./tmpCode/".$ID."/question*");
	shell_exec("rm ./tmpCode/".$ID."/Correct");
	/******************/
?>
