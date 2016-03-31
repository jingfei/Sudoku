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
		$result = DB::table('Log')
					->where('studentID', Session::get('id'))
					->orderBy('date', 'desc')
					->first();
		if($result){ $header = $result->header; $code = $result->code; }
		else{ $header = ""; $code = ""; }
		return View::make('pages.upload')
					->with('header',$header)
					->with('code', $code);
	}

	public function checker(){
		if(!Session::has('id')) return '<script>alert("please login");</script>'.Redirect::to('/');
		$header = Input::get('htext');
		$code = Input::get('cpptext');
		$ID = Session::get('id');
		if(!$header || !$code) return '<script>alert("recieved no code here");</script>'.Redirect::to('/');
		/* files */
		$SudokuH = self::$CodePath."/tmpCode/".$ID."/Sudoku.h";
		$SudokuCPP = self::$CodePath."/tmpCode/".$ID."/Sudoku.cpp";
		/* find forbidden functions */
		$forbid = array("dirent","readdir","opendir");
		foreach( $forbid as $findme )
			if(strpos($header,$findme)!==false || strpos($code,$findme)!==false) {
				$LogID = self::newRecord($header, $code);
				self::Record($LogID,4,2,0,"Do not use dirent library.");
				return Redirect::to('log');
			}
		/*save code to file*/
		$fileh = fopen($SudokuH,"w");
		fwrite($fileh,$header); fclose($fileh);
		$filecpp = fopen($SudokuCPP,"w");
		fwrite($filecpp,$code); fclose($filecpp);
		$LogID = self::newRecord($header, $code);
		Queue::push('CompileController@doChecker', array('LogID'=>$LogID));
		return Redirect::to('log');
	}

	public function attack($_id){
		if(!Session::has('id')) return '<script>alert("please login");</script>'.Redirect::to('/');
		$ID = Session::get('id');
		/* check challenge times */
		$User = DB::table('Users')->where('id', Session::get('id'))->first();
		if($User->challenge<=0){
			$result = DB::table('Users')
						->where('id', Session::get('id'))
						->update(array('challenge'=>0));
			return '<script>alert("you challenge too much");</script>'.Redirect::to('/');
		}
		/* find op */
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
		/* files */
		$SudokuH = self::$CodePath."/tmpCode/".$ID."/Sudoku.h";
		$SudokuCPP = self::$CodePath."/tmpCode/".$ID."/Sudoku.cpp";
		/*read file code*/
		$fileh = fopen($SudokuH,"r");
		$header = fread($fileh,filesize($SudokuH)); fclose($fileh);
		$filecpp = fopen($SudokuCPP,"r");
		$code = fread($filecpp,filesize($SudokuCPP)); fclose($filecpp);
		$LogID = self::newRecord($header, $code, $op);
		Queue::push('CompileController@doAttack', array('LogID'=>$LogID,'op'=>$op));
		return Redirect::to('log');
	}
}
