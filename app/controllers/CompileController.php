<?php

class CompileController extends BaseController {

	public function doChecker($job, $data){
		$LogID = $data['LogID'];
		$result = true;
		if(!self::Compile($LogID)) $result = false;
		else{
			for($r=0; $r<10000; $r++)
				if(!self::check_ans($LogID,$r)){
					$result = false;
					break;
				}
		}
		if($result){
			if(!self::check_give($LogID)) $result=false;
		}
		if($result) self::Record($LogID,0,2,0);
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
		$result['self1'] = self::Race($LogID, $self, $op);
		if($result['op1']<$result['self1']){ $result['res1']=-1; --$final; }
		else if($result['op1']>$result['self1']){ $result['res1']=1; ++$final; }
		else $result['res1']=0;
		DB::table('Log')->where('id', $LogID)
						->update( array('comment'=> serialize($result)) );
		$result['op2'] = self::Race($LogID, $op, $self);
		DB::table('Log')->where('id', $LogID)
						->update( array('comment'=> serialize($result)) );
		$result['self2'] = self::Race($LogID, $self, $op);
		if($result['op2']<$result['self2']){ $result['res2']=-1; --$final; }
		else if($result['op2']>$result['self2']){ $result['res2']=1; ++$final; }
		else $result['res2']=0;
		DB::table('Log')->where('id', $LogID)
						->update( array('comment'=> serialize($result)) );
		$result['op3'] = self::Race($LogID, $op, $self);
		DB::table('Log')->where('id', $LogID)
						->update( array('comment'=> serialize($result)) );
		$result['self3'] = self::Race($LogID, $self, $op);
		if($result['op3']<$result['self3']){ $result['res3']=-1; --$final; }
		else if($result['op3']>$result['self3']){ $result['res3']=1; ++$final; }
		else $result['res3']=0;
		DB::table('Log')->where('id', $LogID)
						->update( array('comment'=> serialize($result)) );
		/* change score */
		$score1 = DB::table('Users')->where('id', $self)->first()->score;
		$score2 = DB::table('Users')->where('id', $op)->first()->score;
		if($final > 0){
			$final = 1;
			$add=0;
			if($score1>=$score2) $add=1;
			else $add=(int)(($score2-$score1)/5)+2;
			DB::table('Log')->where('id', $LogID)
							->update( array('result'=>$final,
											'add'=> (string)$add,
											'op_add'=>'-1') );
			self::UpdateScore($add,0);
			$score = DB::table('Users')->where('id', $op)->first()->score;
			$result = DB::table('Users')
						->where('id',$op)
						->update( array( 'score'=>$score-1 ) );
		}
		else if($final<0){ 
			$final = -1;
			$add = 0;
			if($score2>=$score1) $add=1;
			else $add=(int)(($score1-$score2)/5)+2;
			DB::table('Log')->where('id', $LogID)
							->update( array('result'=>$final,
											'add'=>'-1',
											'op_add'=> (string)$add) );
			self::UpdateScore(-1,0);
			$score = DB::table('Users')->where('id', $op)->first()->score;
			$result = DB::table('Users')
						->where('id',$op)
						->update( array( 'score'=>$score+$add ) );
		}
		else
			DB::table('Log')->where('id', $LogID)
							->update( array('result'=>$final,
											'add'=>'0',
											'op_add'=>'0') );
		self::reRank();
	}

	private function Compile($LogID){
		$ID = Session::get('id');
		/* files */
		$SudokuH = self::$CodePath."/tmpCode/".$ID."/Sudoku.h";
		$SudokuCPP = self::$CodePath."/tmpCode/".$ID."/Sudoku.cpp";
		$SudokuO = self::$CodePath."/tmpCode/".$ID."/Sudoku.o";
		$CodeDIR = self::$CodePath."/Code/*";
		$ClockO = self::$CodePath."/tmpCode/".$ID."/Clock.o";
		$tmpCodeDIR = self::$CodePath."/tmpCode/".$ID."/";
		$Solve = self::$CodePath."/tmpCode/".$ID."/Solve";
		$SolveCPP = self::$CodePath."/tmpCode/".$ID."/Solve.cpp";
		$hw2_solve = self::$CodePath."/tmpCode/".$ID."/hw2_solve";
		$hw2_solveCPP = self::$CodePath."/tmpCode/".$ID."/hw2_solve.cpp";
		$Give = self::$CodePath."/tmpCode/".$ID."/Give";
		$GiveCPP = self::$CodePath."/tmpCode/".$ID."/Give.cpp";
		$CheckSudokuO = self::$CodePath."/tmpCode/".$ID."/CheckSudoku.o";
		$CheckSudokuCPP = self::$CodePath."/tmpCode/".$ID."/CheckSudoku.cpp";
		/*compile*/
		exec('g++ -std=c++0x -c '.$SudokuCPP.' -o '.$SudokuO.' 2>&1',$ce);
		if(!empty($ce)){ self::CompileError($LogID,$ce,$ID); return false; }
		/*make execution file*/
		shell_exec('cp '.$CodeDIR.' '.$tmpCodeDIR);
		exec('g++ -std=c++0x -o '.$Solve.' '.$SolveCPP.' '.$SudokuO.' 2>&1',$ce);
		if(!empty($ce)){ self::CompileError($LogID,$ce,$ID); return false; }
		exec('g++ -std=c++0x '.$hw2_solveCPP.' '.$SudokuO.' '.$ClockO.' -o '.$hw2_solve.' 2>&1',$ce);
		if(!empty($ce)){ self::CompileError($LogID,$ce,$ID); return false; }
		exec('g++ -std=c++0x -o '.$Give.' '.$SudokuO.' '.$GiveCPP.' 2>&1',$ce);
		if(!empty($ce)){ self::CompileError($LogID,$ce,$ID); return false; }
		exec('g++ -std=c++0x -o '.$CheckSudokuO.' -c '.$CheckSudokuCPP.' 2>&1',$ce);
		if(!empty($ce)){ self::CompileError($LogID,$ce,$ID); return false; }
		/*********************/
		return true;
	}

	private function check_ans($LogID, $r){
		$r = (string)$r;
		$ID=Session::get('id');
		/* cmd: $CodePath/tmpCode/$ID/Solve $CodePath $ID $r */
		$cmd= self::$CodePath.'/tmpCode/'.$ID.'/Solve '.self::$CodePath.' '.$ID.' '.$r;
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
			$Wrong='no outputs';
			self::UpdateScore(-5,4);
			self::Record($LogID,4,2,0,$Wrong);
			$Result = false;
		}
		else{
			$AnsPath= self::$CodePath."/outputs/A/".$r;
			$CodePath= self::$CodePath."/tmpCode/".$ID."/Correct";
			$Check=exec('diff -w -B '.$AnsPath.' '.$CodePath);
			if($Check){ 
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
				self::UpdateScore(-5,3);
				self::Record($LogID,3,2,-5,$Wrong);
			}
		}
		shell_exec("rm ".self::$CodePath."/tmpCode/".$ID."/question*");
		shell_exec("rm ".self::$CodePath."/tmpCode/".$ID."/Correct");
		/******************/
		return $Result;
	}

	private function check_give($LogID){
		$ID = Session::get('id');
		$cmd=self::$CodePath.'/tmpCode/'.$ID.'/Give '.self::$CodePath.' '.$ID.' giveOutput';
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
			$outputPath=self::$CodePath.'/tmpCode/'.$ID.'/giveOutput';
			if(!file_exists($outputPath)){
				$Wrong = "GiveQuestion(): no output file";
				$Result = false;
				self::UpdateScore(-5,3);
				self::Record($LogID,3,2,-5,$Wrong);
			} else {
				$outputFile = fopen($outputPath, "r");
				$content = "";
				$i = 0;
				while(!feof($outputFile)) {
					$c = fgetc($outputFile);
					if(!strlen($c)) continue;
					else if(ctype_digit($c)) ++$i;
					else if(!ctype_space($c)) $Result = false;
					$content .= $c;
				}
				fclose($outputFile);
				if($i!=81) $Result = false;
				if(!$Result){
					$Wrong = "Presentation error:\n1. You should have exactly 81 digits.\n2. They're in the range of 0 to 9.\n\nYour GiveQuestion() output:\n";
					$Wrong .= $content;
					self::UpdateScore(-5,5);
					self::Record($LogID,5,2,-5,$Wrong);
				}
				shell_exec("rm ".$outputPath);
			}
		}
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
		$aCMD= self::$CodePath.'/tmpCode/'.$b.'/Give '.$ID;
		$bCMD= self::$CodePath.'/tmpCode/'.$a.'/hw2_solve '.$ID;
		$stdout = "";
		$errout = "";
		/* give question time out */
		if(self::exec_timeout($aCMD,$timeout,$stdout,$errout))
			return -1;
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

