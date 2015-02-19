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

	public function uploadPage($_id){
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
