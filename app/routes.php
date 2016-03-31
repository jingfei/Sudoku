<?php

/*
|--------------------------------------------------------------------------
| Application Routes
|--------------------------------------------------------------------------
|
| Here is where you can register all of the routes for an application.
| It's a breeze. Simply tell Laravel the URIs it should respond to
| and give it the Closure to execute when that URI is requested.
|
*/

Route::get('/', 
			function(){
				if(Session::has('id')) return Redirect::to('status');
				else return View::make('pages.home');
			} );

Route::get('rank', 'HomeController@getRank' );
Route::get('status', 'HomeController@getStatus' );

Route::get('log/{_id?}', 'HomeController@logPage' );

Route::post('login', 'HomeController@login' );

Route::get('logout', 'HomeController@logout' );

Route::post('chName', 'HomeController@chName' );

Route::get('challenge/{_id}', 'AttackController@challengeInfo' );

Route::get('upload', 'AttackController@uploadPage' );

Route::post('checker', 'AttackController@checker' );

Route::get('attack/{_id}', 'AttackController@attack' );

Route::get('platform', 'AttackController@platform' );

Route::get('choose', function(){ return View::make('pages.choose'); } );

