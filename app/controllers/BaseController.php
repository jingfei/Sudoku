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

}
