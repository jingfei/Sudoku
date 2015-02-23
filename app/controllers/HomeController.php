<?php

class HomeController extends BaseController {

	public function getRank()
	{
		$isLogin = Session::has('id') ? Session::get('id') : false;
		$arr = array();
		$isAC = false;
		if($isLogin){
			$result = DB::table('Users')->where('id', $isLogin)->first();
			$rank = $result->rank;
			$arr = unserialize($result->challenge_id);
			$result = DB::table('Log')->where('studentID', $isLogin)->orderBy('date', 'desc')->first();
			$isAC = $result ? $result->check==0 ? true : false : false;
		}
		$users = DB::table('Users')
					->orderBy('score', 'desc')
					->orderBy('id')
					->get();
		foreach($users as $rows){
			$isChallenge = false;
			$Log = DB::table('Log')->where('studentID', $rows->id)->orderBy('date', 'desc')->first();
			if($Log) $rows->correct=$Log->check;
			else $rows->correct=4;
			if($arr)
				foreach($arr as $item)
					if($item==$rows->id)
						$isChallenge=true;
			$rows->isChallenge = $isChallenge;

			if($isLogin){
				if($rows->id=='test') $rows->addScore = "+0 or -0";
				else if($rows->id!=$isLogin){
					$add=0;
					if($rows->rank>=$rank) $add=1;
					else $add=(int)(($rank-$rows->rank)/5)+2;
					$rows->addScore =  '+'.$add.' or -1';
				}
				else $rows->addScore = '--';
				
				/* encode for challenge id */
				$rows->pw = self::enCode($rows->newid.$rows->id);

			}
		}
		return View::make('pages.home')
					->with('isLogin', $isLogin)
					->with('isAC', $isAC)
					->with('users', $users);
	}

	private function logStatus($result){
		if(!$result->op)
			switch($result->check){
				case 0:  return HTML::image("img/ac.png"); break;
				case 1:  return HTML::image("img/ce.png"); break;
				case 2:  return HTML::image("img/tle.png"); break;
				case 3:  return HTML::image("img/wa.png"); break;
				case 4:  return HTML::image("img/err.png"); break;
				case 5:  return HTML::image("img/pe.png"); break;
				case 6:  return HTML::image("img/pending.png"); break;
				default: return "--";
			}
		else
			switch($result->result){
				case 0:  return HTML::image("img/tie.png"); break;
				case 1:  return HTML::image("img/win.png"); break;
				case -1: return HTML::image("img/lose.png"); break;
				default: return "--";
			}
		return "--";
	}

	public function logPage($_id=null){
		if(!$_id) return self::getLog(); 
		$ID = Session::get('id');
		$result = DB::table('Log')->where('id', $_id)->first();
		$result->header = htmlspecialchars($result->header, ENT_QUOTES);
		$result->code = htmlspecialchars($result->code, ENT_QUOTES);
		if(!$result) return App::abort(404);
		if($result->studentID==$ID || $result->op==$ID){
			/* get result */
			$result->img = self::logStatus($result);
			return View::make('pages.eachlog')
						->with('result', $result);
		}
		return App::abort(404);
	}

	private function getLog(){
		$ID = Session::get('id');
		$result = DB::table('Users')->get();
		$limit_all=100;
		$limit_spec=15;
		$name=array();
		foreach($result as $rows)
			$name[$rows->id]=$rows->name;
		/* for all record */
		$all = DB::table('Log')
					->orderBy('date', 'desc')
					->take($limit_all)
					->get();
		foreach($all as $rows){
			if($rows->studentID==$ID)
				$rows->url = URL::to('log/'.$rows->id);
			else if($rows->op && $rows->op==$ID)
				$rows->url = URL::to('log/'.$rows->id);
			else $rows->url = null;
			$rows->img = self::logStatus($rows);
		}
		/* for spec record */
		$spec = DB::table('Log')
					->where('studentID', $ID )
					->orderBy('date', 'desc')
					->take($limit_spec)
					->get();
		foreach($spec as $rows){
			$rows->url = URL::to('log/'.$rows->id);
			$rows->img = self::logStatus($rows);
		}
		/* for attacked record */
		$attacked = DB::table("Log")
						->where('op', $ID)
						->orderBy('date', 'desc')
						->take($limit_spec)
						->get();
		foreach($attacked as $rows){
			$rows->url = URL::to('log/'.$rows->id);
			$rows->img = self::logStatus($rows);
		}
		return View::make('pages.log')
					->with('name', $name)
					->with('all', $all)
					->with('spec', $spec)
					->with('attacked', $attacked);
	}

	public function login(){
		$ID=htmlspecialchars(Input::get('id'), ENT_QUOTES); 
		$pw=md5(Input::get('passwd'));
		if(substr($ID,0,2)=="an") $ID=substr_replace($ID,"AN",0,2);
		else if(substr($ID,0,1)=="c") $ID=substr_replace($ID,"C",0,1);
		else if(substr($ID,0,1)=="e") $ID=substr_replace($ID,"E",0,1);
		else if(substr($ID,0,1)=="f") $ID=substr_replace($ID,"F",0,1);
		else if(substr($ID,0,1)=="h") $ID=substr_replace($ID,"H",0,1);
		$result = DB::table('Users')->where('id',$ID)->first();
		if(!$result)
			return 'Student ID is not exist here';
		else if($result->passwd===$pw){
			Session::put('id',$ID);
			return 'yes';
		}
		else{
			$passwd = Input::get('passwd');
			$user = $ID;
			$link = @imap_open("{mail.ncku.edu.tw:143/novalidate-cert}",$user,$passwd) ;
		//	or die('Cannot connect to Friggin Server: ' . print_r(imap_errors()));
			if($link){
				imap_close($link);//Close the connection
				Session::put('id',$ID);
				return "yes";
			}
			else{
				imap_close($link);
				return 'wrong password';
			}
		}
	}

	public function logout(){
		if(Session::has('id')){
			Session::forget('id');
			Session::forget('op');
		}
		return Redirect::to('/');
	}

	public function chName(){
		$Len = strlen(Input::get('NewName'));
		if($Len>16 || $Len===0) 
			return "<script>alert('The length of name is 1 to 16');</script>".Redirect::to('/');
		$newName = htmlspecialchars(Input::get('NewName'), ENT_QUOTES);
		$newName = addslashes($newName);
		$newName = trim($newName);
		$result = DB::table('Users')
					->where('id',Session::get('id'))
					->update(array('name' => $newName));
			return Redirect::to('/');
	}

}
