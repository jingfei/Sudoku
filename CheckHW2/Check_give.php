<?php
/* change line 7 $timeout to modify timeout */
	include "Timeout.php";
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
	session_start();
	$ID=$_SESSION['user'];
	$cmd='./tmpCode/'.$ID.'/hw2_give_question '.$ID;
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
	else{
		$Check=exec('./tmpCode/'.$ID.'/hw2_check_give '.$ID);
		if($Check){ 
			echo '<img src="StatusImg/pe.png" />';
			$sql="UPDATE `Users` SET correct=5 WHERE id='$ID'";
			$mysqli->query($sql);
			$Wrong=true;
			//wrongQuestion
			echo "<div>";
			echo "<h2 style='color:#0060bf'>1. You should have exactly 81 digits.<br/>2. They're in the range of 0 to 9.<br/>3. Exactly one solution here.</h2>";
			echo "<table style='font-size:30px;padding:5px;text-align:center;' align='center'><tr><th style='color:blue'>Your GiveQuestion() output</th></tr>";
			$pePath="./tmpCode/".$ID."/".$Check;
			$file = fopen($pePath,"r");
			if($file)
				while(!feof($file)){
					$peCode.="<tr><td>";
					$peCode.=fgets($file);
					$peCode.="</td></tr>";
				}
			else{
				echo "GiveQuestion() outputs no file!!<br/>";
				exit();	
			}
			fclose($file);
			echo $peCode;
			echo "</table></div>";
		}
	}
	shell_exec("rm ./tmpCode/".$ID."/question*");
	/******************/
?>
