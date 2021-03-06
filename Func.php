<?php

if(isset($_POST['action'])){
	if($_POST['num']==0)
		call_user_func($_POST['action']);
	else if($_POST['num']==1)
		call_user_func($_POST['action'],$_POST['a1']);
	else if($_POST['num']==2)
		call_user_func($_POST['action'],$_POST['a1'],$_POST['a2']);
}

function ChallengeAdd1(){
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
	$ID=$_SESSION['id'];
	$sql="UPDATE  `Users` SET  `challenge` =  `challenge` +1 WHERE  `id` = '$ID'";
	$result=$mysqli->query($sql);
}

function reRank(){
	$ID=$_SESSION['id'];
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
	$RANK=1; $realRank=1;
	$sql="SELECT * FROM `Users` ORDER BY `score` DESC, `id`";
	$result=$mysqli->query($sql);
	$rows=$result->fetch_array();
	$last=$rows['score']; $nowID=$rows['id'];
	$sql="UPDATE `Users` SET rank=".(string)($RANK)." WHERE id='$nowID'";
	$result2=$mysqli->query($sql);
	while($rows=$result->fetch_array()){
		$realRank++;
		if($rows['score'] < $last) $RANK=$realRank;
		$last=$rows['score']; $nowID=$rows['id'];
		$sql="UPDATE `Users` SET rank=".(string)($RANK)." WHERE id='$nowID'";
		$result2=$mysqli->query($sql);
	}
}

function UpdateCode($code,$header){
	$ID=$_SESSION['id'];
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
	/*translate (avoid '\n' problem)*/
//	$header=str_replace("@n","\\n",$header);
//	$code=str_replace("@n","\\n",$code);
	/*save*/
	$fileh = fopen("./tmpCode/".$ID."/Sudoku.h","w");
	fwrite($fileh,$header); fclose($fileh);
	$filecpp = fopen("./tmpCode/".$ID."/Sudoku.cpp","w");
	fwrite($filecpp,$code); fclose($filecpp);
	/*update*/
	$header = mysql_real_escape_string($header);
	$code = mysql_real_escape_string($code);
	$sql="UPDATE `Users` SET header='$header' WHERE id='$ID'";
	$result=$mysqli->query($sql);
	$sql="UPDATE `Users` SET code='$code' WHERE id='$ID'";
	$result=$mysqli->query($sql);
}

function compile_error($ce,$score,$op){
	$ID=$_SESSION['id'];
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
	echo '<img src="./image/ce.png" /><br/>';
	if($op!='test') echo '<h1 style="color:red;">score -1</h1><hr style="border-top:dashed 1px;"/>';
	echo '<p>';
	foreach($ce as $item) echo $item.'<br/>';
	echo '</p>';
	if($op!='test' && $score>0){
		$sql="UPDATE `Users` SET score=".(string)($score-1)." WHERE id='$ID'";
		$result2=$mysqli->query($sql);
		reRank();
	}
	$sql="UPDATE `Users` SET correct=1 WHERE id='$ID'";
	$result2=$mysqli->query($sql);
}

function UpdateScore($Add,$Status){
	$ID=$_SESSION['id'];
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
	/*get score*/
	$sql="SELECT * FROM `Users` WHERE id='$ID'";
	$result=$mysqli->query($sql);
	$row=$result->fetch_array();
	$score=$row['score'];
	/***********/	
	/*update state*/
	$sql="UPDATE `Users` SET correct=$Status WHERE id='$ID'";
	$result2=$mysqli->query($sql);
	/**************/
	reRank();
	if($Add<0 && $score<=0) return;
	$sql="UPDATE `Users` SET score=".(string)($score+$Add)." WHERE id='$ID'";
	$result2=$mysqli->query($sql);
}

function exec_timeout($cmd, $timeout) {
/**
 * Execute a command and return it's output. Either wait until the command exits or the timeout has expired.
 *
 * @param string $cmd     Command to execute.
 * @param number $timeout Timeout in seconds.
 * @return string Output of the command.
 * @throws \Exception
 */
	// File descriptors passed to the process.
	$descriptors = array(
		0 => array('pipe', 'r'),  // stdin
		1 => array('pipe', 'w'),  // stdout
		2 => array('pipe', 'w')   // stderr
	);

	// Start the process.
	$process = proc_open($cmd, $descriptors, $pipes);

//	  if (!is_resource($process)) {
//	    throw new \Exception('Could not execute process');
//	  }

  	// Set the stdout stream to none-blocking.
//	  stream_set_blocking($pipes[1], 0);

  	// Turn the timeout into microseconds.
  	$timeout = $timeout * 1000000;

  	// Output buffer.
	$buffer = '';
	$error = '';

  	// While we have time to wait.
  	$Result=true;
  	while ($timeout > 0) {
  		$start = microtime(true);

  	  	// Wait until we have output or the timer expired.
  	  	$read  = array($pipes[1]);
  	  	$other = array();
  	  	stream_select($read, $other, $other, 0, $timeout);

  	  	// Get the status of the process.
  	  	// Do this before we read from the stream,
  	  	// this way we can't lose the last bit of output if the process dies between these functions.
  	  	$status = proc_get_status($process);

  	  	// Read the contents from the buffer.
  	  	// This function will always return immediately as the stream is none-blocking.
	  	$buffer .= stream_get_contents($pipes[1]);
	  	// Check if there were any errors.
	    $buffer .= stream_get_contents($pipes[2]);
  	  	if (!$status['running']) {
  	  		$Result=false;
  	  		//Break from this loop if the process exited before the timeout.
  	  		break;
  	  	}

  		// Subtract the number of microseconds that we waited.
  		$timeout -= (microtime(true) - $start) * 1000000;
  	}


//  if (!empty($errors)) {
//    throw new \Exception($errors);
//  }

  // Kill the process in case the timeout expired and it's still running.
  // If the process already exited this won't do anything.
	if($status['running']) { //process ran too long, kill it
	    //close all pipes that are still open
	    fclose($pipes[1]); //stdout
	    fclose($pipes[2]); //stderr
	    //get the parent pid of the process we want to kill
	    $ppid = $status['pid'];
	    //use ps to get all the children of this process, and kill them
	    $pids = preg_split('/\s+/', `ps -o pid --no-heading --ppid $ppid`);
	    foreach($pids as $pid) {
	        if(is_numeric($pid)) {
	//            echo "Killing $pid\n";
	            posix_kill($pid, 9); //9 is the SIGKILL signal
	        }
	    }
	        
	    proc_close($process);
	}
	else{
	 	 // Close all streams.
		fclose($pipes[0]);
	  	fclose($pipes[1]);
	  	fclose($pipes[2]);
	  	proc_close($process);
	}
  	return $Result;
}

function Race($op,$Status){  //1:a solve, 2:b solve
	$ID=$_SESSION['id'];
	$timeout=120; //seconds
	if($Status==1){
		$cmd1='./tmpCode/'.$op.'/hw2_give_question '.$ID;
		$cmd='./tmpCode/'.$ID.'/hw2_solve '.$ID;
		if(exec_timeout($cmd1,30))
			echo '0';
		else if(exec_timeout($cmd,$timeout))
			echo 'TLE';
		else{
			$fileTime = fopen("./tmpCode/".$ID."/Time","r");
		//	if(!$fileTime){ echo 'Time'.var_export(error_get_last()); exit();}
			$Time=fgets($fileTime);
			fclose($fileTime);
			shell_exec('rm ./tmpCode/'.$ID.'/question*');
			shell_exec('rm ./tmpCode/'.$ID.'/Time');
			//something wrong challenge +1
			echo $Time;
		}
	}
	else{
		$cmd1='./tmpCode/'.$ID.'/hw2_give_question '.$ID;
		$cmd='./tmpCode/'.$op.'/hw2_solve '.$ID;
		if(exec_timeout($cmd1,30))
			echo '0';
		else if(exec_timeout($cmd,$timeout))
			echo 'TLE';
		else{
			$fileTime = fopen("./tmpCode/".$ID."/Time","r");
			$Time=fgets($fileTime);
			fclose($fileTime);
			shell_exec('rm ./tmpCode/'.$ID.'/question*');
			shell_exec('rm ./tmpCode/'.$ID.'/Time');
			echo $Time;
		}
	}
}

function Record($op,$check,$Status,$add1,$add2){
	if($op=='test') return;
	$ID=$_SESSION['id'];
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
	if($Status!=-2)
		$sql="INSERT INTO `Log`(`id`,`op`,`check`,`result`,`add`,`op_add`)  VALUES ('$ID','$op',$check,$Status,'$add1','$add2')";
	else
		$sql="INSERT INTO `Log`(`id`,`op`,`check`,`add`)  VALUES ('$ID','$op',$check,'$add1')";
	$mysqli->query($sql);

}

function RaceResult($Status,$op){ //1:win,0:tie,-1:lose
	$ID=$_SESSION['id'];
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
	/*your rank*/
	$sql="SELECT * FROM `Users` WHERE id='$ID'";
	$result=$mysqli->query($sql);
	$row=$result->fetch_array();
	$rank=$row['rank'];
	$score=$row['score'];
	/**/	
	/*opponent's code*/
	$sql="SELECT * FROM `Users` WHERE id='$op'";
	$result=$mysqli->query($sql);
	$row=$result->fetch_array();
	$rank_op = $row['rank'];
	$score_op = $row['score'];
	/****************/
	
	if($Status=='1'){
		$add=1;
		if($rank_op>=$rank) $add=1;
		else $add=(int)(($rank-$rank_op)/5)+2;
		$sql="UPDATE `Users` SET score=".(string)($score+$add)." WHERE id='$ID'";
		$result=$mysqli->query($sql);
	//	echo '<p>'.$mysqli->error.'</p>';
		if($score_op>0){
			$sql="UPDATE `Users` SET score=".(string)($score_op-1)." WHERE id='$op'";
			$result=$mysqli->query($sql);
		}
		Record($op,0,$Status,'+'.$add,'-1');
		echo '+'.$add;
	}
	else if($Status=='0'){
		$sql="UPDATE `Users` SET score=".(string)($score+1)." WHERE id='$ID'";
		$result=$mysqli->query($sql);
		$sql="UPDATE `Users` SET score=".(string)($score_op+1)." WHERE id='$op'";
		$result=$mysqli->query($sql);
		Record($op,0,$Status,'+1','+1');
		echo "+1";
	}
	else{
		$add=0;
		if($rank>=$rank_op) $add=1;
		else $add=(int)(($rank_op-$rank)/5)+2;
		$sql="UPDATE `Users` SET score=".(string)($score_op+$add)." WHERE id='$op'";
		$result=$mysqli->query($sql);
		if($score>0){
			$sql="UPDATE `Users` SET score=".(string)($score-1)." WHERE id='$ID'";
			$result=$mysqli->query($sql);
		}
		Record($op,0,$Status,'-1','+'.$add);
		echo "-1";
	}
	reRank();
}

?>
