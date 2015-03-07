<?php

class BaseController extends Controller {

	/**
	 * Setup the layout used by the controller.
	 *
	 * @return void
	 */

	protected static $CodePath = "/home/jingfei/Sudoku";

	protected function setupLayout()
	{
		if ( ! is_null($this->layout))
		{
			$this->layout = View::make($this->layout);
		}
	}

	protected function enCode($pw){
		for($i=0; $i<995; ++$i)
			$pw=md5($pw);
		return $pw;
	}

	protected function reRank(){
		$RANK=1; $realRank=1; $last=0;
		$result = DB::table('Users')
					->orderBy('score','desc')
					->orderBy('id')
					->get();
		foreach($result as $rows){
			if($rows->score < $last) $RANK=$realRank;
			$nowID=$rows->id;
			$User = DB::table("Users")
						->where('id', $nowID)
						->update( array('rank'=> $RANK) );
			$realRank++;
			$last=$rows->score; 
		}
	}

	protected function Record($LogID, $check,$Status,$add1,$comment=null,$add2=null){
		$result = DB::table('Log')
					->where('id', $LogID)
					->update( array('check'=>$check, 
									'result'=>$Status, 
									'add'=>$add1, 
									'op_add'=>$add2, 
									'comment'=>$comment) );
		return $result;
	}

	protected function newRecord($header, $code, $op=null){
		$ID = Session::get('id');
		$result = DB::table('Log')
					->insertGetId( array('studentID'=>$ID,
										 'op'=>$op,
										 'header'=>$header,
										 'code'=>$code) );
		return $result;
	}

	protected function UpdateScore($Add,$Status){
		$ID = Session::get('id');
		/*get score*/
		$score = DB::table('Users')->where('id', $ID)->first()->score;
		/*update state*/
		$score+=$Add; if($score<0) $score=0;
		$result = DB::table('Users')
					->where('id',$ID)
					->update( array( 'score'=>$score ) );
	}
	
	protected function exec_timeout($cmd,$timeout,&$stdout,&$errout){
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
		  stream_set_blocking($pipes[1], 0);
		  stream_set_blocking($pipes[2], 0);
	
	  	// Turn the timeout into microseconds.
	  	$timeout = $timeout * 100000;
	  	// Output buffer.
		$stdout = '';
		$errout = '';
	
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
		  	$stdout .= stream_get_contents($pipes[1]);
		  	// Check if there were any errors.
		    $errout .= stream_get_contents($pipes[2]);
	  	  	if (!$status['running']) {
	  	  		$Result=false;
	  	  		//Break from this loop if the process exited before the timeout.
	  	  		break;
	  	  	}
	
	  		// Subtract the number of microseconds that we waited.
	  		$timeout -= (microtime(true) - $start) * 100000;
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
		    //        echo "Killing $pid\n";
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
}
