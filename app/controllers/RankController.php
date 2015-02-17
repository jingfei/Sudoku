<?php

class RankController extends BaseController {

	public function getRank()
	{
		$isLogin = Session::has('id') ? Session::get('id') : false;
		$arr = array();
		if($isLogin){
			$result = DB::table('Users')->where('id', $isLogin)->first();
			$rank = $result->rank;
			$arr = unserialize($result->challenge_id);
		}
		$users = DB::table('Users')
					->orderBy('score', 'desc')
					->orderBy('id')
					->get();
		foreach($users as $rows){
			$isChallenge = false;
			if($arr)
				foreach($arr as $item)
					if($item==$rows->id)
						$isChallenge=true;
			$rows->isChallenge = $isChallenge;

			if($rows->id=='test') $rows->addScore = "+0 or -0";
			else if($rows->id==$isLogin){
				$add=0;
				if($rows->rank>=$rank) $add=1;
				else $add=(int)(($rank-$rows->rank)/5)+2;
				$rows->addScore =  '+'.$add.' or -1';
			}
			else $rows->addScore = '--';

		}
		return View::make('pages.home')
					->with('isLogin', $isLogin)
					->with('users', $users);
	}

}
