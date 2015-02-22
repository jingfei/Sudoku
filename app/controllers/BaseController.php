<?php

class BaseController extends Controller {

	/**
	 * Setup the layout used by the controller.
	 *
	 * @return void
	 */
	protected function setupLayout()
	{
		if ( ! is_null($this->layout))
		{
			$this->layout = View::make($this->layout);
		}
	}

	protected function enCode($pw){
		for($i=0; $i<995; ++$i)
			$pw=md5($pw);
		return $pw;
	}

	protected function reRank(){
		$RANK=1; $realRank=1; $last=0;
		$result = DB::table('Users')
					->orderBy('score','desc')
					->orderBy('id')
					->get();
		foreach($result as $rows){
			$last=$rows->score; $nowID=$rows->id;
			$User = DB::table("Users")
						->where('id', $newID)
						->update( array('rank'=> $RANK) );
			++$realRank;
			if($rows->score < $last) $RANK=$realRank;
		}
	}

	protected function Record($check,$Status,$add1,$comment=null,$op=null,$add2=null){
		$ID = Session::get('id');
		$result = DB::table('Log')
					->insert( array('id'=>$ID, 
									'op'=>$op, 
									'check'=>$check, 
									'result'=>$Status, 
									'add'=>$add1, 
									'op_add'=>$add2, 
									'comment'=>$comment) );
		return $result;
	}

	protected function UpdateScore($Add,$Status){
		$ID = Session::get('id');
		/*get score*/
		$score = DB::table('Users')->where('id', $ID)->first()->score;
		/*update state*/
		$score+=$Add; if($score<0) $score=0;
		$result = DB::talbe('Users')
					->where('id',$ID)
					->update( array( 'correct'=>$Status, 
									 'score'=>$score ) );
		self::reRank();
	}
}
