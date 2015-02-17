<?php

class HomeController extends BaseController {

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

			if($isLogin){
				if($rows->id=='test') $rows->addScore = "+0 or -0";
				else if($rows->id!=$isLogin){
					$add=0;
					if($rows->rank>=$rank) $add=1;
					else $add=(int)(($rank-$rows->rank)/5)+2;
					$rows->addScore =  '+'.$add.' or -1';
				}
				else $rows->addScore = '--';
			}
		}
		return View::make('pages.home')
					->with('isLogin', $isLogin)
					->with('users', $users);
	}

//	public function getLog(){
//		return View::make('pages.log');
//	}

	public static function getLog($check){
		$ID = Session::get('id');
		$result = DB::table('Users')->get();
		$limit1=100;
		$limit2=15;
		$name=array();
		foreach($result as $rows)
			$name[$rows->id]=$rows->name;
		$result = DB::table('Log')->orderBy('date', 'desc')->get();
		if($check=="all"){
			echo "<table class='rank'><tr><th>date</th><th>name</th><th>opponent</th><th>check</th><th>result</th></tr>";
			$Count=0;
			foreach($result as $rows){
				if($Count>=$limit1) break;
				$Count++;
				echo "<tr>";
				echo "<td>".$rows->date."</td>";
				echo "<td>".$name[$rows->id]."</td>";
				echo "<td>".$name[$rows->op]."</td>";
				echo "<td>";
				switch($rows->check){
					case 0: 
						echo HTML::image("img/ac.png"); break;
					case 1:
						echo HTML::image("img/ce.png"); break;
					case 2:
						echo HTML::image("img/tle.png"); break;
					case 3:
						echo HTML::image("img/wa.png"); break;
					case 4:
						echo HTML::image("img/err.png"); break;
					case 5:
						echo HTML::image("img/pe.png"); break;
				}
				echo "</td><td>";
				switch($rows->result){
					case 0: 
						echo HTML::image("img/tie.png"); break;
					case 1:
						echo HTML::image("img/win.png"); break;
					case -1:
						echo HTML::image("img/lose.png"); break;
					default: echo "--";
				}
				echo "</td></tr>";
			}
			echo "</table>";
		}
		else{
			echo "<hr style='border-top:dashed 1px;' width='80%'>";
			echo "<h2 style='text-align:center;color:#0060bf'>Your attack</h2>";
			echo "<table class='rank'>";
			echo "<tr><th>date</th><th>name</th><th>opponent</th><th>check</th><th>result</th><th>score</th></tr>";
			$Count=0;
			foreach($result as $rows){
				if($Count>=$limit2) break;
				if($rows->id!=$ID) continue;
				$Count++;
				echo "<tr>";
				echo "<td>".$rows->date."</td>";
				echo "<td>".$name[$rows->id]."</td>";
				echo "<td>".$name[$rows->op]."</td>";
				echo "<td>";
				switch($rows->check){
					case 0: 
						echo HTML::image("img/ac.png"); break;
					case 1:
						echo HTML::image("img/ce.png"); break;
					case 2:
						echo HTML::image("img/tle.png"); break;
					case 3:
						echo HTML::image("img/wa.png"); break;
					case 4:
						echo HTML::image("img/err.png"); break;
					case 5:
						echo HTML::image("img/pe.png"); break;
				}
				echo "</td><td>";
				switch($rows->result){
					case 0: 
						echo HTML::image("img/tie.png"); break;
					case 1:
						echo HTML::image("img/win.png"); break;
					case -1:
						echo HTML::image("img/lose.png"); break;
					default: echo "--";
				}
				echo "</td><td>".$rows->add."</td>";
				echo "</tr>";
			}
			echo "</table><br/>";
			echo "<hr style='border-top:dashed 1px;' width='80%'>";
			echo "<h2 style='text-align:center;color:#0060bf'>Being attacked</h2>";
			echo "<table class='rank'>";
			echo "<tr><th>date</th><th>name</th><th>opponent</th><th>your result</th><th>your score</th></tr>";
			$result = DB::table("Log")->orderBy('date', 'desc')->get();
			$Count=0;
			foreach($result as $rows){
				if($Count>=$limit2) break;
				if($rows->op!=$ID || $rows->result==2) continue;
				$Count++;
				echo "<tr>";
				echo "<td>".$rows->date."</td>";
				echo "<td>".$name[$rows->id]."</td>";
				echo "<td>".$name[$rows->op]."</td>";
				echo "<td>";
				switch($rows->result){
					case 0: 
						echo HTML::image("img/tie.png"); break;
					case 1:
						echo HTML::image("img/win.png"); break;
					case -1:
						echo HTML::image("img/lose.png"); break;
					default: echo "--";
				}
				echo "</td><td>".$rows->op_add."</td>";
				echo "</tr>";
			}
			echo "</table>";
		}
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
		else if($result->passwd==$pw){
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
