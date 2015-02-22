<?php

class AttackController extends BaseController {

	public function challengeInfo($_id)
	{
		if(!Session::has('id')) return '<script>alert("please login");</script>'.Redirect::to('/');
		$result = DB::table('Users')->get();
		$op = null;
		foreach($result as $rows){
			$thisPW = self::enCode($rows->newid.$rows->id);
			if($thisPW === $_id)
				return View::make('pages.challenge')
						->with('op', $rows)
						->with('pw', $thisPW);
		}
		return '<script>alert("no such opponent");</script>'.Redirect::to('/');
	}

	public function uploadPage(){
		if(!Session::has('id')) return '<script>alert("please login");</script>'.Redirect::to('/');
		return View::make('pages.upload');
	}

	public function checker(){
		if(!Session::has('id')) return '<script>alert("please login");</script>'.Redirect::to('/');
		$header = Input::get('htext');
		$code = Input::get('cpptext');
		$ID = Session::get('id');
		/* files */
		$SudokuH = asset("tmpCode/".$ID."/Sudoku.h");
		$SudokuCPP = asset("tmpCode/".$ID."/Sudoku.cpp");
		$SudokuO = asset("tmpCode/".$ID."/Sudoku.o");
		$ClockO = asset("tmpCode/".$ID."/Clock.o");
		$CodeDIR = asset("Code/*");
		$tmpCodeDIR = asset("tmpCode/".$ID."/");
		$hw2_check = asset("tmpCode/".$ID."/hw2_check");
		$hw2_checkCPP = asset("tmpCode/".$ID."/hw2_check.cpp");
		$hw2_solve = asset("tmpCode/".$ID."/hw2_solve");
		$hw2_solveCPP = asset("tmpCode/".$ID."/hw2_solve.cpp");
		$hw2_give_question = asset("tmpCode/".$ID."/hw2_give_question");
		$hw2_give_questionCPP = asset("tmpCode/".$ID."/hw2_give_question.cpp");
		$hw2_check_give = asset("tmpCode/".$ID."/hw2_check_give");
		$hw2_check_giveCPP = asset("tmpCode/".$ID."/hw2_check_give.cpp");
		/*save code to file*/
		$fileh = fopen($SudokuH,"w");
		fwrite($fileh,$header); fclose($fileh);
		$filecpp = fopen($SudokuCPP,"w");
		fwrite($filecpp,$code); fclose($filecpp);
		/*update code to SQL*/
		$header = mysql_real_escape_string($header);
		$code = mysql_real_escape_string($code);
		$result = DB::table('Users')
					->where('id', $ID)
					->update( array('header'=>$header, 'code'=>$code) );
		/*compile*/
		exec('g++ -c '.$SudokuCPP.' -o '.$SudokuO.' 2>&1',$ce);
		if(!empty($ce)) self::CompileError($ce,$ID);
		/*make execution file*/
		shell_exec('cp '.$CodeDIR.' '.$tmpCodeDIR);
		exec('g++ -o '.$hw2_check.' '.$hw2_checkCPP.' '.$SudokuO.' 2>&1',$ce);
		if(!empty($ce)) self::CompileError($ce,$ID);
		exec('g++ '.$hw2_solveCPP.' '.$SudokuO.' '.$ClockO.' -o '.$hw2_solve.' 2>&1',$ce);
		if(!empty($ce)) self::CompileError($ce,$ID);
		exec('g++ -o '.$hw2_give_question.' '.$SudokuO.' '.$hw2_give_questionCPP.' 2>&1',$ce);
		if(!empty($ce)) self::CompileError($ce,$ID);
		exec('g++ -o '.$hw2_check_give.' '.$hw2_check_giveCPP.' 2>&1',$ce);
		if(!empty($ce)) self::CompileError($ce,$ID);
		/*********************/
		return View::make('pages.checker');
	}

	private function check_give(){
		$cmd=asset('tmpCode/'.$ID.'/hw2_give_question').' '.$ID;
		$timeout=30; //seconds
		$Wrong=null;
		/*check timelimit*/
		if(exec_timeout($cmd, $timeout)){
			$Wrong='time limited exceed';
			UpdateScore(-5,2);
			Record(2,2,-5,$Wrong);
		}
		/*****************/
		/*check answer*/
		else{
			$Check=exec(sprintf($cmd." 2>&1 & echo $!"),$pidArr);
			if($Check){ 
				$Wrong = "presentation error\n1. You should have exactly 81 digits.\n2. They're in the range of 0 to 9.\n\nYour GiveQuestion() output:\n";
				$pePath=asset("tmpCode/".$ID."/".$Check);
				$file = fopen($pePath,"r");
				if($file)
					while(!feof($file)){
						$peCode.=fgets($file);
						$peCode.="\n";
					}
				fclose($file);
				UpdateScore(-5,5);
				Record(5,2,-5,$Wrong);
			}
		}
		shell_exec("rm ".asset("tmpCode/".$ID."/question*") );
		return $Wrong;
	}

	public function ploadPage($_id){
		if(!Session::has('id')) return '<script>alert("please login");</script>'.Redirect::to('/');
		$User = DB::table('Users')->where('id', Session::get('id'))->first();
		if($User->challenge<=0){
			$result = DB::table('Users')
						->where('id', Session::get('id'))
						->update(array('challenge'=>0));
			return '<script>alert("you challenge too much");</script>'.Redirect::to('/');
		}

		$result = DB::table('Users')->get();
		$op = null;
		foreach($result as $rows){
			$thisPW = self::enCode($rows->newid.$rows->id);
			if($thisPW === $_id)
				$op = $rows->id;
		}
		/*find challenge list*/
		$arr=array();
		$arr=unserialize($User->challenge_id);
		if($arr)
			foreach($arr as $item)
				if($item===$op){
					return "<script>alert('you have challenged him today');</script>".Redirect::to('/');
				}
		/*********************/
		/*minus challenge time & save to challenge list*/
		$arr[]=$op;
		$ser=serialize($arr);
		$result = DB::table('Users')
					->where('id', Session::get('id'))
					->update(array('challenge'=> ($User->challenge-1),
								   'challenge_id' => $ser));
		/***********************************************/
		return View::make('pages.upload')
					->with('op', $op);
	}

	private function CompileError($ce,$ID){
		$questionALL = asset("tmpCode/".$ID."/question*");
		shell_exec("rm ".$questionALL);
		$msg = "";
		foreach($ce as $item) $msg+=$item.'\n';
		$score = DB::talbe("Users")->where('id', $ID)->first()->score;
		$score-=5; if($score<0) $score=0;
		$result = DB::table('Users')
					->where('id', $ID)
					->update( array('correct'=>1, 'score'=> $score) );
		self::reRank();
		self::Record(1,2,-5,$msg);
	}

}
