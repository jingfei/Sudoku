<?php
	require_once("db_const.php");
	include 'Func.php';
	$ID=$_SESSION['id'];
	$op=$_POST['op'];
	$r=$_POST['Rand'];
//	srand(mktime()); $r=rand()%25+10; 
	$cmd='./tmpCode/'.$ID.'/hw2_check '.$ID.' '.(string)$r;
	$timeout=30; //seconds
	$Wrong=false; 
	/*check timelimit*/
	if(exec_timeout($cmd, $timeout)){
		echo '<img src="./image/tle.png" /><h1 style="color:red;">score -1</h1>';
		UpdateScore(-1,2);
		$Wrong=true;
		Record($op,2,-2,'-1','0');
	}
	/*****************/
	/*check answer*/
	else if(!is_file('./tmpCode/'.$ID.'/Correct')){
		$Wrong=true; 
		$Mes='file not exist, please contact with TA';
		echo '<img src="./image/err.png" /><h1 style="color:red;">score -1</h1><h1>'.$Mes.'</h1>';
		UpdateScore(0,4);
		Record($op,3,-2,'0','0');
	}
	else{
		$AnsPath="./outputs/ans/ans".(string)$r;
		$CodePath="./tmpCode/".$ID."/Correct";
		$Check=exec('diff -w -B '.$AnsPath.' '.$CodePath);
		if($Check){ 
			echo '<img src="./image/wa.png" /><h1 style="color:red;">score -1</h1>';
			UpdateScore(-1,3);
			Record($op,3,-2,'-1','0');
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
			echo "<div style='display:inline-block;margin-right:10%;' width='40%'>".$ansCode."</div>";
			echo "<div style='display:inline-block;margin-left:10%;' width='40%'>".$waCode."</div>";
		}
	}
	shell_exec("rm ./tmpCode/".$ID."/question*");
	shell_exec("rm ./tmpCode/".$ID."/Correct");
	/******************/
?>
