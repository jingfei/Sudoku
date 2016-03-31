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
		if(!Session::has('id')) return 'Please login';
		$header = Input::get('htext');
		$code = Input::get('cpptext');
		$ID = Session::get('id');
		if(!$header || !$code) return 'Please fill in both header and cpp code.';
		/* files */
		$SudokuH = self::$CodePath."/tmpCode/".$ID."/Sudoku.h";
		$SudokuCPP = self::$CodePath."/tmpCode/".$ID."/Sudoku.cpp";
		/* find forbidden functions */
		$forbid = array("dirent","readdir","opendir");
		foreach( $forbid as $findme )
			if(strpos($header,$findme)!==false || strpos($code,$findme)!==false) {
				$LogID = self::newRecord($header, $code);
				self::Record($LogID,4,2,0,"Do not use dirent library.");
				return;
			}
		/*save code to file*/
		$fileh = fopen($SudokuH,"w");
		fwrite($fileh,$header); fclose($fileh);
		$filecpp = fopen($SudokuCPP,"w");
		fwrite($filecpp,$code); fclose($filecpp);
		$LogID = self::newRecord($header, $code);
		Queue::push('CompileController@doChecker', array('LogID'=>$LogID));
		return; 
	}

	public function attack($_id){
		if(!Session::has('id')) return '<script>alert("please login");</script>';
		$ID = Session::get('id');
		/* check challenge times and platform */
		$User = DB::table('Users')->where('id', Session::get('id'))->first();
		$platform = $User->platform;
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
			if($thisPW === $_id){
				$op = $rows->id;
				if($rows->platform !== $platform)
					return '<script>alert("different platform with your opponent");</script>'.Redirect::to('/');
			}
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
		Queue::push('CompileController@doAttack', array('LogID'=>$LogID,'op'=>$op,'platform'=>$platform));
		return Redirect::to('log');
	}

	public function platform(){
		if(!Session::has('id')) return '<script>alert("please login");</script>';
		$ID = Session::get('id');
		$result = DB::table('Users')
						->where('id', $ID)
						->first();
		if($result->platform==1) return Redirect::to('rank/1/1');
		else if($result->platform==2) return Redirect::to('rank/2/1');
		else return Redirect::to('choose');
	}

	public function choose($selection=0){
		if(!Session::has('id')) return '<script>alert("please login");</script>';
		$ID = Session::get('id');
		/* if the user has chose the platform */
		$result = DB::table('Users')
						->where('id', $ID)
						->first();
		if($result->platform==1 || $result->platform==2)
			return Redirect::to('platform');
		/* if he has selection */
		if($selection==1 || $selection==2){
			$result = DB::table('Users')
						->where('id', $ID)
						->update(array('platform'=>$selection));
			return Redirect::to('platform');
		}
		/* to make selection */
		return View::make('pages.choose');
	}
	
}
