<?php

class CompileController extends BaseController {

	public function doChecker($job, $data){
		$LogID = $data['LogID'];
		$result = true;
		$r=rand(10,14);
		if(!self::Compile($LogID)) $result = false;
		else if(!self::check_ans($LogID, $r)) $result=false;
		else if(!self::check_ans($LogID, $r+5)) $result = false;
		else if(!self::check_ans($LogID, $r+10)) $result = false;
		else if(!self::check_ans($LogID, $r+15)) $result = false;
		else if(!self::check_ans($LogID, $r+20)) $result = false;
		else if(!self::check_give($LogID)) $result = false;
		else self::Record($LogID,0,2,0);
		self::reRank();
	}

	public function doAttack($job, $data){
		$LogID = $data['LogID'];
		$op = $data['op'];
		$self = Session::get('id');
		$final = 0;
		$result = array( "op1"=>null, "self1"=>null, "res1"=>null,
						 "op2"=>null, "self2"=>null, "res2"=>null,
						 "op3"=>null, "self3"=>null, "res3"=>null );
		$result['op1'] = self::Race($LogID, $op, $self);
		DB::table('Log')->where('id', $LogID)
						->update( array('comment'=> serialize($result)) );
		$result['self1'] = self::Race($LogID, $op, $self);
		if($result['op1']<$result['self1']){ $result['res1']=-1; --$final; }
		else if($result['op1']>$result['self1']){ $result['res1']=1; ++$final; }
		else $result['res1']=0;
		DB::table('Log')->where('id', $LogID)
						->update( array('comment'=> serialize($result)) );
		$result['op2'] = self::Race($LogID, $op, $self);
		DB::table('Log')->where('id', $LogID)
						->update( array('comment'=> serialize($result)) );
		$result['self2'] = self::Race($LogID, $op, $self);
		if($result['op2']<$result['self2']){ $result['res2']=-1; --$final; }
		else if($result['op2']>$result['self2']){ $result['res2']=1; ++$final; }
		else $result['res2']=0;
		DB::table('Log')->where('id', $LogID)
						->update( array('comment'=> serialize($result)) );
		$result['op3'] = self::Race($LogID, $op, $self);
		DB::table('Log')->where('id', $LogID)
						->update( array('comment'=> serialize($result)) );
		$result['self3'] = self::Race($LogID, $op, $self);
		if($result['op3']<$result['self3']){ $result['res3']=-1; --$final; }
		else if($result['op3']>$result['self3']){ $result['res3']=1; ++$final; }
		else $result['res3']=0;
		DB::table('Log')->where('id', $LogID)
						->update( array('comment'=> serialize($result)) );
		/* change score */
		$rank1 = DB::table('Users')->where('id', $self)->first()->rank;
		$rank2 = DB::table('Users')->where('id', $op)->first()->rank;
		if($final > 0){
			$final = 1;
			$add=0;
			if($rank2>=$rank1) $add=1;
			else $add=(int)(($rank1-$rank2)/5)+2;
			DB::table('Log')->where('id', $LogID)
							->update( array('result'=>$final,
											'add'=> (string)$add,
											'op_add'=>'-1') );
		}
		else if($final<0){ 
			$final = -1;
			$add = 0;
			if($rank1>=$rank2) $add=1;
			else $add=(int)(($rank2-$rank1)/5)+2;
			DB::table('Log')->where('id', $LogID)
							->update( array('result'=>$final,
											'add'=>'-1',
											'op_add'=> (string)$add) );
		}
		else
			DB::table('Log')->where('id', $LogID)
							->update( array('result'=>$final,
											'add'=>'0',
											'op_add'=>'0') );
	}

	private function Compile($LogID){
		$ID = Session::get('id');
		/* files */
		$SudokuH = self::$CodePath."/tmpCode/".$ID."/Sudoku.h";
		$SudokuCPP = self::$CodePath."/tmpCode/".$ID."/Sudoku.cpp";
		$SudokuO = self::$CodePath."/tmpCode/".$ID."/Sudoku.o";
		$ClockO = self::$CodePath."/tmpCode/".$ID."/Clock.o";
		$CodeDIR = self::$CodePath."/Code/*";
		$tmpCodeDIR = self::$CodePath."/tmpCode/".$ID."/";
		$hw2_check = self::$CodePath."/tmpCode/".$ID."/hw2_check";
		$hw2_checkCPP = self::$CodePath."/tmpCode/".$ID."/hw2_check.cpp";
		$hw2_solve = self::$CodePath."/tmpCode/".$ID."/hw2_solve";
		$hw2_solveCPP = self::$CodePath."/tmpCode/".$ID."/hw2_solve.cpp";
		$hw2_give_question = self::$CodePath."/tmpCode/".$ID."/hw2_give_question";
		$hw2_give_questionCPP = self::$CodePath."/tmpCode/".$ID."/hw2_give_question.cpp";
		$CheckSudokuO = self::$CodePath."/tmpCode/".$ID."/CheckSudoku.o";
		$CheckSudokuCPP = self::$CodePath."/tmpCode/".$ID."/CheckSudoku.cpp";
		$hw2_check_give = self::$CodePath."/tmpCode/".$ID."/hw2_check_give";
		$hw2_check_giveCPP = self::$CodePath."/tmpCode/".$ID."/hw2_check_give.cpp";
		/*compile*/
		exec('g++ -c '.$SudokuCPP.' -o '.$SudokuO.' 2>&1',$ce);
		if(!empty($ce)){ self::CompileError($LogID,$ce,$ID); return false; }
		/*make execution file*/
		shell_exec('cp '.$CodeDIR.' '.$tmpCodeDIR);
		exec('g++ -o '.$hw2_check.' '.$hw2_checkCPP.' '.$SudokuO.' 2>&1',$ce);
		if(!empty($ce)){ self::CompileError($LogID,$ce,$ID); return false; }
		exec('g++ '.$hw2_solveCPP.' '.$SudokuO.' '.$ClockO.' -o '.$hw2_solve.' 2>&1',$ce);
		if(!empty($ce)){ self::CompileError($LogID,$ce,$ID); return false; }
		exec('g++ -o '.$hw2_give_question.' '.$SudokuO.' '.$hw2_give_questionCPP.' 2>&1',$ce);
		if(!empty($ce)){ self::CompileError($LogID,$ce,$ID); return false; }
		exec('g++ -o '.$CheckSudokuO.' -c '.$CheckSudokuCPP.' 2>&1',$ce);
		if(!empty($ce)){ self::CompileError($LogID,$ce,$ID); return false; }
		exec('g++ -o '.$hw2_check_give.' '.$hw2_check_giveCPP.' '.$CheckSudokuO.' 2>&1',$ce);
		if(!empty($ce)){ self::CompileError($LogID,$ce,$ID); return false; }
		/*********************/
		return true;
	}

	private function check_ans($LogID, $r){
		$ID=Session::get('id');
		$cmd= self::$CodePath.'/tmpCode/'.$ID.'/hw2_check '.$ID.' '.(string)$r;
		$timeout=30; //seconds
		$Wrong=null; 
		$Result = true;
		$stdout=null; $errout=null;
		/*check timelimit*/
		if(self::exec_timeout($cmd, $timeout, $stdout, $errout)){
			$Wrong='Solve(): time limited exceed';
			self::UpdateScore(-5,2);
			self::Record($LogID,2,2,-5,$Wrong);
			$Result = false;
		}
		/*****************/
		/*check answer*/
		else if(!file_exists(self::$CodePath.'/tmpCode/'.$ID.'/Correct')){
			$Wrong='file not exist, please contact with TA';
			self::UpdateScore(0,4);
			self::Record($LogID,4,2,0,$Wrong);
			$Result = false;
		}
		else{
			$AnsPath= self::$CodePath."/outputs/ans/ans".(string)$r;
			$CodePath= self::$CodePath."/tmpCode/".$ID."/Correct";
			$Check=exec('diff -w -B '.$AnsPath.' '.$CodePath);
			if($Check){ 
				self::UpdateScore(-5,3);
				self::Record($LogID,3,2,-5,$Wrong);
				//ansCode
				$Wrong = "Correct:\n";
				$file = fopen($AnsPath,"r");
				if($file)
					while(!feof($file)){
						$Wrong.=fgets($file);
					}
				fclose($file);
				//waCode
				$Wrong .= "\nYours:\n";
				$file = fopen($CodePath,"r");
				if($file)
					while(!feof($file)){
						$Wrong.=fgets($file);
					}
				fclose($file);
				$Result = false;
			}
		}
		shell_exec("rm ".self::$CodePath."/tmpCode/".$ID."/question*");
		shell_exec("rm ".self::$CodePath."/tmpCode/".$ID."/Correct");
		/******************/
		return $Result;
	}

	private function check_give($LogID){
		$ID = Session::get('id');
		$cmd=self::$CodePath.'/tmpCode/'.$ID.'/hw2_give_question'.' '.$ID;
		$timeout=30; //seconds
		$Wrong=null;
		$Result = true;
		$stdout=null; $errout=null;
		/*check timelimit*/
		if(self::exec_timeout($cmd, $timeout, $stdout, $errout)){
			$Wrong='GiveQuestion(): time limited exceed';
			self::UpdateScore(-5,2);
			self::Record($LogID,2,2,-5,$Wrong);
			$Result = false;
		}
		/*****************/
		/*check answer*/
		else{
//			$Check=exec(sprintf($cmd." 2>&1 & echo $!"),$pidArr);
			if($stdout){ 
				$Wrong = "presentation error\n1. You should have exactly 81 digits.\n2. They're in the range of 0 to 9.\n\nYour GiveQuestion() output:\n";
				$pePath=self::$CodePath."/tmpCode/".$ID."/".$stdout;
				$file = fopen($pePath,"r");
				if($file)
					while(!feof($file)){
						$peCode.=fgets($file);
						$peCode.="\n";
					}
				fclose($file);
				self::UpdateScore(-5,5);
				self::Record($LogID,5,2,-5,$Wrong);
				$Result = false;
			}
		}
		shell_exec("rm ".self::$CodePath."/tmpCode/".$ID."/question*" );
		return $Result;
	}

	private function CompileError($LogID,$ce,$ID){
		$questionALL = self::$CodePath."/tmpCode/".$ID."/question*";
		shell_exec("rm ".$questionALL);
		$msg = "";
		foreach($ce as $item){
			$pos = strpos($item, self::$CodePath);
			if($pos !== false){
				$Len = strlen(self::$CodePath);
				$item = substr($item, $pos+$Len);
			}
			$msg.=$item."\n";
		}
		$score = DB::table("Users")->where('id', $ID)->first()->score;
		$score-=5; if($score<0) $score=0;
		$result = DB::table('Users')
					->where('id', $ID)
					->update( array('score'=> $score) );
		self::reRank();
		self::Record($LogID,1,2,-5,$msg);
	}

	// Race function return seconds, $timeout+10 for TLE
	private function Race($LogID, $a, $b){  // a solve
		$ID = Session::get('id');
		$timeout = 30;
		$aCMD= self::$CodePath.'/tmpCode/'.$b.'/hw2_give_question '.$ID;
		$bCMD= self::$CodePath.'/tmpCode/'.$a.'/hw2_solve '.$ID;
		$stdout = "";
		$errout = "";
		/* give question time out */
		if(self::exec_timeout($aCMD,$timeout,$stdout,$errout))
			return 0;
		/* solve time out */
		else if(self::exec_timeout($bCMD,$timeout,$stdout,$errout))
			return $timeout+10;
		else{
			$fileTime = fopen( self::$CodePath."/tmpCode/".$ID."/Time","r");
			$Time=fgets($fileTime);
			fclose($fileTime);
			shell_exec('rm '.self::$CodePath.'/tmpCode/'.$ID.'/question*');
			shell_exec('rm '.self::$CodePath.'/tmpCode/'.$ID.'/Time');
			return $Time;
		}
	}

}
