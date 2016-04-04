<?php

class CompileController extends BaseController {

	public function doChecker($job, $data){
		$LogID = $data['LogID'];
		$result = true;
		$result = self::Compile($LogID);
		$Array=array();
		$a=0; $arNum=100;
		while( $a<$arNum ){
			$sn = mt_rand(0,499); 
			if(!in_array($sn,$Array)) $Array[$a++]=$sn;
		}
		if($result){
			foreach($Array as $base){
				for($r=0; $r<9500; $r+=500){
					$result = self::check_ans($LogID,$r+$base);
					if(!$result) break;
				}
				if(!$result) break;
			}
		}
		if($result) $result = self::check_trans($LogID);
		if($result) $result = self::check_give($LogID);
		if($result) self::Record($LogID,0,2,0);
		self::reRank();
		/* speed test */
		$totalTimes=0;
		if($result){
			$pass = true; $passNum=100;
			for($r=9500; $r<9600; $r++){ 
				$pass = self::speedTest($LogID,$r);
				if($pass==-1) break;
				else if($pass==0) ++$totalTimes;
			}
			$level = 6-ceil($totalTimes/5);
			if($level<=0) $level=1;
			if($pass!=-1) self::recordSpeed($LogID,$level);
		}
	}

	public function doAttack($job, $data){
		$LogID = $data['LogID'];
		$op = $data['op'];
		$platform = $data['platform'];
		$self = Session::get('id');
		$final = 0;
		$result = array( "op1"=>null, "self1"=>null, "res1"=>null,
						 "op2"=>null, "self2"=>null, "res2"=>null,
						 "op3"=>null, "self3"=>null, "res3"=>null );
		$result['op1'] = self::Race($LogID, $op, $self, $platform);
		DB::table('Log')->where('id', $LogID)
						->update( array('comment'=> serialize($result)) );
		$result['self1'] = self::Race($LogID, $self, $op, $platform);
		if($result['op1']<$result['self1']){ $result['res1']=-1; --$final; }
		else if($result['op1']>$result['self1']){ $result['res1']=1; ++$final; }
		else $result['res1']=0;
		DB::table('Log')->where('id', $LogID)
						->update( array('comment'=> serialize($result)) );
		$result['op2'] = self::Race($LogID, $op, $self, $platform);
		DB::table('Log')->where('id', $LogID)
						->update( array('comment'=> serialize($result)) );
		$result['self2'] = self::Race($LogID, $self, $op, $platform);
		if($result['op2']<$result['self2']){ $result['res2']=-1; --$final; }
		else if($result['op2']>$result['self2']){ $result['res2']=1; ++$final; }
		else $result['res2']=0;
		DB::table('Log')->where('id', $LogID)
						->update( array('comment'=> serialize($result)) );
		$result['op3'] = self::Race($LogID, $op, $self, $platform);
		DB::table('Log')->where('id', $LogID)
						->update( array('comment'=> serialize($result)) );
		$result['self3'] = self::Race($LogID, $self, $op, $platform);
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
		$tmpCodeDIR = self::$CodePath."/tmpCode/".$ID."/";
		$Solve = self::$CodePath."/tmpCode/".$ID."/Solve";
		$SolveCPP = self::$CodePath."/tmpCode/".$ID."/Solve.cpp";
		$Give = self::$CodePath."/tmpCode/".$ID."/Give";
		$GiveCPP = self::$CodePath."/tmpCode/".$ID."/Give.cpp";
		$Trans = self::$CodePath."/tmpCode/".$ID."/Trans";
		$TransCPP = self::$CodePath."/tmpCode/".$ID."/Trans.cpp";
		$CheckTrans = self::$CodePath."/tmpCode/".$ID."/CheckTrans";
		$CheckTransCPP = self::$CodePath."/tmpCode/".$ID."/CheckTrans.cpp";
		/*compile*/
		exec('g++ -std=c++0x -static -pthread -mavx -c '.$SudokuCPP.' -o '.$SudokuO.' 2>&1',$ce);
		if(!empty($ce)){ self::CompileError($LogID,$ce,$ID); return false; }
		/*make execution file*/
		shell_exec('cp '.$CodeDIR.' '.$tmpCodeDIR);
		exec('g++ -std=c++0x -static -pthread -mavx -o '.$Solve.' '.$SolveCPP.' '.$SudokuO.' 2>&1',$ce);
		if(!empty($ce)){ self::CompileError($LogID,$ce,$ID); return false; }
		exec('g++ -std=c++0x -static -pthread -mavx -o '.$Give.' '.$SudokuO.' '.$GiveCPP.' 2>&1',$ce);
		if(!empty($ce)){ self::CompileError($LogID,$ce,$ID); return false; }
		exec('g++ -std=c++0x -static -pthread -mavx -o '.$Trans.' '.$SudokuO.' '.$TransCPP.' 2>&1',$ce);
		if(!empty($ce)){ self::CompileError($LogID,$ce,$ID); return false; }
		exec('g++ -std=c++0x -static -pthread -mavx -o '.$CheckTrans.' '.$SudokuO.' '.$CheckTransCPP.' 2>&1',$ce);
		if(!empty($ce)){ self::CompileError($LogID,$ce,$ID); return false; }
		/*********************/
		return true;
	}

	private function check_trans($LogID){
		$ID = Session::get('id');
		/* cmd: $CodePath/tmpCode/$ID/Trans $CodePath $input $output */
		$cmd= self::$CodePath.'/tmpCode/'.$ID.'/Trans '.self::$CodePath.' /outputs/transInput /tmpCode/'.$ID.'/transOutput';
		$timeout=30; //seconds
		$Wrong=null;
		$Result = true;
		$stdout=null; $errout=null;
		/*check timelimit*/
		if(self::exec_timeout($cmd, $timeout, $stdout, $errout)){
			$Wrong='transform(): time limited exceed';
			self::UpdateScore(-5,2);
			self::Record($LogID,2,2,-5,$Wrong);
			$Result = false;
		}
		/*****************/
		/*check answer*/
		else{
			$outputPath=self::$CodePath.'/tmpCode/'.$ID.'/transOutput';
			if(!file_exists($outputPath)){
				$Wrong = "transform(): no output";
				$Result = false;
				self::UpdateScore(-5,3);
				self::Record($LogID,3,2,-5,$Wrong);
			} else {
				/* input file: $CodePath/outputs/transInput */
				$outputFile = fopen($outputPath, "r");
				$content = "";
				$i = 0;
				$num = array(0,0,0,0,0,0,0,0,0,0);
				$ans_num = array(1,4,5,5,5,6,6,7,8,34);
				while(!feof($outputFile)) {
					$c = fgetc($outputFile);
					if(!strlen($c)) continue;
					else if(ctype_digit($c)) ++$num[$c];
					else if(!ctype_space($c)) $Result = false;
					$content .= $c;
				}
				fclose($outputFile);
				if($num[0]!==34) $Result = false;
				sort($num);
				if($num!==$ans_num) $Result = false;
				if(!$Result){
					$Wrong = "transform() function Error.\n\nYour output:\n";
					$Wrong .= $content;
					self::UpdateScore(-5,5);
					self::Record($LogID,5,2,-5,$Wrong);
				}
				shell_exec("rm ".$outputPath);
			}
		}
		return $Result;
		
	}

	private function check_ans($LogID, $r){
		$ID=Session::get('id');
		/* change $r to string and add 0 to 4 digits */
		$r = (string)$r;
		while(strlen($r)<4) $r = '0'.$r;
		$QusPath = '/outputs/Q/'.$r;
		$AnsPath = "/outputs/A/".$r;
		/* cmd: $CodePath/tmpCode/$ID/Solve $CodePath $input $output */
		if($r>=9000 && $r<9500)
			$cmd= self::$CodePath.'/tmpCode/'.$ID.'/CheckTrans '.self::$CodePath.' '.$QusPath.' /tmpCode/'.$ID.'/Correct';
		else
			$cmd= self::$CodePath.'/tmpCode/'.$ID.'/Solve '.self::$CodePath.' '.$QusPath.' /tmpCode/'.$ID.'/Correct';
		$QusPath = self::$CodePath.$QusPath;
		$AnsPath = self::$CodePath.$AnsPath;
		$timeout=30; //seconds
		$Wrong=null; 
		$Result = true;
		$stdout=null; $errout=null;
		/* Problem */
		$Problem="Problem:\n";
		$file = fopen($QusPath,"r");
		if($file)
			while(!feof($file)){
				$Problem.=fgets($file);
			}
		fclose($file);
		$Problem.="\n";
		/*check timelimit*/
		if(self::exec_timeout($cmd, $timeout, $stdout, $errout)){
			$Wrong="solve() or transform functions time limited exceed.\n\n".$Problem;
			self::UpdateScore(-5,2);
			self::Record($LogID,2,2,-5,$Wrong);
			$Result = false;
		}
		/*****************/
		/*check answer*/
		else if(!file_exists(self::$CodePath.'/tmpCode/'.$ID.'/Correct')){
			$Wrong="solve() or transformation (flip, rotate, changeXXX) functions ternimate unexpectedly.\n\n".$Problem;
			self::UpdateScore(-5,4);
			self::Record($LogID,4,2,0,$Wrong);
			$Result = false;
		}
		else{
			$CodePath= self::$CodePath."/tmpCode/".$ID."/Correct";
			$Check=exec('diff -w -B '.$AnsPath.' '.$CodePath);
			if($Check){ 
				$Wrong = $Problem;
				//ansCode
				$Wrong .= "Correct:\n";
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

	private function recordSpeed($LogID,$level){
		$ID=Session::get('id');
		$result = DB::table('Log')
					->where('id', $LogID)
					->update( array('speed'=>$level) );
	}

	private function speedTest($LogID,$r){
		$ID=Session::get('id');
		/* change $r to string and add 0 to 4 digits */
		$r = (string)$r;
		while(strlen($r)<4) $r = '0'.$r;
		$QusPath = '/outputs/Q/'.$r;
		$AnsPath = "/outputs/A/".$r;
		/* cmd: $CodePath/tmpCode/$ID/CheckTrans $CodePath $input $output */
		if($r>=9500 && $r<9520)
			$cmd= self::$CodePath.'/tmpCode/'.$ID.'/CheckTrans '.self::$CodePath.' '.$QusPath.' /tmpCode/'.$ID.'/Speed';
		/* cmd: $CodePath/tmpCode/$ID/Solve $CodePath $input $output */
		else
			$cmd= self::$CodePath.'/tmpCode/'.$ID.'/Solve '.self::$CodePath.' /outputs/Q/'.$r.' /tmpCode/'.$ID.'/Speed';

		$QusPath = self::$CodePath.$QusPath;
		$AnsPath = self::$CodePath.$AnsPath;
		$timeout=10; //seconds
		$Wrong=null; 
		$Result = 1;
		$stdout=null; $errout=null;
		/* Problem */
		$Problem="Problem:\n";
		$file = fopen($QusPath,"r");
		if($file)
			while(!feof($file)){
				$Problem.=fgets($file);
			}
		fclose($file);
		$Problem.="\n";
		/*check timelimit*/
		if(self::exec_timeout($cmd,$timeout,$stdout,$errout)){ 
			$Result=0;
		}
		/*****************/
		/*check answer*/
		else if(!file_exists(self::$CodePath.'/tmpCode/'.$ID.'/Speed')){
			$Wrong="solve() or transformation (flip, rotate, changeXXX) functions ternimate unexpectedly.\n\n".$Problem;
			self::UpdateScore(-5,4);
			self::Record($LogID,4,2,0,$Wrong);
			$Result = -1;
		}
		else{
			$CodePath= self::$CodePath."/tmpCode/".$ID."/Speed";
			$Check=exec('diff -w -B '.$AnsPath.' '.$CodePath);
			if($Check){ 
				$Wrong = $Problem;
				//ansCode
				$Wrong .= "Correct:\n";
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
				$Result = -1;
				self::UpdateScore(-5,3);
				self::Record($LogID,3,2,-5,$Wrong);
			}
		}
		shell_exec("rm ".self::$CodePath."/tmpCode/".$ID."/Speed");
		/******************/
		return $Result;
	}

	private function check_give($LogID){
		$ID = Session::get('id');
		/* cmd: $CodePath/tmpCode/$ID/Give $CodePath $output */
		$cmd=self::$CodePath.'/tmpCode/'.$ID.'/Give '.self::$CodePath.' /tmpCode/'.$ID.'/giveOutput';
		$timeout=30; //seconds
		$Wrong=null;
		$Result = true;
		$stdout=null; $errout=null;
		/*check timelimit*/
		if(self::exec_timeout($cmd, $timeout, $stdout, $errout)){
			$Wrong='giveQuestion(): time limited exceed';
			self::UpdateScore(-5,2);
			self::Record($LogID,2,2,-5,$Wrong);
			$Result = false;
		}
		/*****************/
		/*check answer*/
		else{
			$outputPath=self::$CodePath.'/tmpCode/'.$ID.'/giveOutput';
			if(!file_exists($outputPath)){
				$Wrong = "giveQuestion(): no output";
				$Result = false;
				self::UpdateScore(-5,3);
				self::Record($LogID,3,2,-5,$Wrong);
			} else {
				$outputFile = fopen($outputPath, "r");
				$content = "";
				$i = 0; $j = 0;
				while(!feof($outputFile)) {
					$c = fgetc($outputFile);
					if(!strlen($c)) continue;
					else if(ctype_digit($c)) ++$i;
					else if(ctype_space($c)) ++$j;
					else if(!ctype_space($c)) $Result = false;
					$content .= $c;
				}
				fclose($outputFile);
				if($i!=81 || $j<81) $Result = false;
				if(!$Result){
					$Wrong = "Presentation error:\n1. You should have exactly 81 digits.\n2. They're in the range of 0 to 9.\n3. They should all separated by at least a space or a new line.\n\nYour giveQuestion() output:\n";
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
	private function Race($LogID, $a, $b, $method){  // a solve
		$ID = Session::get('id');
		if($method==1){
			/* cmd: $CodePath/tmpCode/$ID/Give $CodePath $output */
			$bGIVE=self::$CodePath.'/tmpCode/'.$b.'/Give '.self::$codepath.' /tmpcode/'.$id.'/giveOutput';
			/* cmd: $CodePath/tmpCode/$ID/Solve $CodePath $input $output */
			$aSOLVE=self::$CodePath.'/tmpCode/'.$a.'/Solve '.self::$CodePath.' /tmpCode/'.$ID.'/giveOutput /tmpCode/'.$ID.'/Correct';
		} else if($method==2){
			/* cmd: $CodePath/tmpCode/$ID/Give $CodePath $output */
			$aGIVE=self::$CodePath.'/tmpCode/'.$a.'/Give '.self::$CodePath.' /tmpCode/'.$ID.'/giveOutput';
			/* cmd: $CodePath/tmpCode/$ID/Solve $CodePath $input $output */
			$bTRANS=self::$CodePath.'/tmpCode/'.$b.'/Trans '.self::$CodePath.' /tmpCode/'.$ID.'/giveOutput /tmpCode/'.$ID.'/transOutput';
			/* cmd: $CodePath/tmpCode/$ID/Solve $CodePath $input $output */
			$aSOLVE2=self::$CodePath.'/tmpCode/'.$a.'/Solve '.self::$CodePath.' /tmpCode/'.$ID.'/transOutput /tmpCode/'.$ID.'/Correct';
		}
		$stdout = "";
		$errout = "";
		$timeout = 60;
		$timeuse = 0;
		/* method 1 */
		if($method==1) {
			/* give question time out */
			if(self::exec_timeout($bGIVE,$timeout,$stdout,$errout) || 
					!file_exists(self::$codepath.'/tmpcode/'.$id.'/giveOutput'))
				return -1;
			/* solve time out */
			else{
				$start = microtime(true);
			  $isTimeout = self::exec_timeout($aSOLVE,$timeout,$stdout,$errout) ||
									!file_exists(self::$codepath.'/tmpcode/'.$id.'/Correct');
		  	$timeuse = microtime(true) - $start;
				if($isTimeout) return 100;
			}
		}
		/* method 2 */
		else if($method==2){
			if(self::exec_timeout($aGIVE,$timeout,$stdout,$errout) ||
					!file_exists(self::$codepath.'/tmpcode/'.$id.'/giveOutput'))
				return 100;
			else if(self::exec_timeout($bTRANS,$timeout,$stdout,$errout) || 
							!file_exists(self::$codepath.'/tmpcode/'.$id.'/transOutput'))
				return -1;
			else{
				$start = microtime(true);
			  $isTimeout = self::exec_timeout($aSOLVE2,$timeout,$stdout,$errout) ||
									!file_exists(self::$codepath.'/tmpcode/'.$id.'/Correct');
				$timeuse += (microtime(true) - $start);
				if($isTimeout) return 100;
			}
		}

		return $timeuse;
	}
}

