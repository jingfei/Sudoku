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
		$headerpath = self::$CodePath.'/tmpCode/'.Session::get('id')."/Sudoku.h";
		$codepath = self::$CodePath."/tmpCode/".Session::get('id')."/Sudoku.cpp";
		/* get header file */
		$header = "";
		if(file_exists($headerpath)){
			$hfile=fopen(self::$CodePath.'/tmpCode/'.Session::get('id')."/Sudoku.h","r");
			if($hfile)
				while(!feof($hfile))
					$header .= fgets($hfile);
			fclose($hfile);
		}
		/* get cpp file */
		$code = "";
		if(file_exists($codepath)){
			$cppfile=fopen(self::$CodePath."/tmpCode/".Session::get('id')."/Sudoku.cpp","r");
			if($cppfile)
				while(!feof($cppfile))
					$code .= fgets($cppfile);
			fclose($cppfile);
		}

		return View::make('pages.upload')
					->with('header',$header)
					->with('code', $code);
	}

	public function checker(){
		if(!Session::has('id')) return '<script>alert("please login");</script>'.Redirect::to('/');
		$header = Input::get('htext');
		$code = Input::get('cpptext');
		$ID = Session::get('id');
		/* files */
		$SudokuH = self::$CodePath."/tmpCode/".$ID."/Sudoku.h";
		$SudokuCPP = self::$CodePath."/tmpCode/".$ID."/Sudoku.cpp";
		/*save code to file*/
		$fileh = fopen($SudokuH,"w");
		fwrite($fileh,$header); fclose($fileh);
		$filecpp = fopen($SudokuCPP,"w");
		fwrite($filecpp,$code); fclose($filecpp);
		/*update code to SQL*/
	//	$header = mysql_real_escape_string($header);
	//	$code = mysql_real_escape_string($code);
		$result = DB::table('Users')
					->where('id', $ID)
					->update( array('header'=>$header, 'code'=>$code) );
		Queue::push('CompileController@doChecker');
		return Redirect::to('log');
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


}
