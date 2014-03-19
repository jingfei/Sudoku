<?php
/* change line 7 $timeout to modify timeout */
	include "Timeout.php";
	session_start();
	$ID=$_SESSION['user'];
	$cmd='./tmpCode/'.$ID.'/hw2_give_question '.$ID;
	$timeout=30; //seconds
	$Wrong=false;
	/*check timelimit*/
	if(exec_timeout($cmd, $timeout)){
		echo '<img src="StatusImg/tle.png" />';
		$Wrong=true;
	}
	/*****************/
	/*check answer*/
	else{
		$Check=exec('./tmpCode/'.$ID.'/hw2_check_give '.$ID);
		if($Check){ 
			echo '<img src="StatusImg/pe.png" />';
			$Wrong=true;
			//wrongQuestion
			echo "<div>";
			echo "<h2 style='color:#0060bf'>1. You should have exactly 81 digits.<br/>2. They're in the range of 0 to 9.</h2>";
			echo "<table style='font-size:30px;padding:5px;text-align:center;' align='center'><tr><th style='color:blue'>Your GiveQuestion() output</th></tr>";
			$pePath="./tmpCode/".$ID."/".$Check;
			$file = fopen($pePath,"r");
			if($file)
				while(!feof($file)){
					$peCode.="<tr><td>";
					$peCode.=fgets($file);
					$peCode.="</td></tr>";
				}
			fclose($file);
			echo $peCode;
			echo "</table></div>";
		}
	}
	shell_exec("rm ./tmpCode/".$ID."/question*");
	/******************/
?>
