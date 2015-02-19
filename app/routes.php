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

Route::get('/', 'HomeController@getRank' );

Route::get('log', function(){return View::make('pages.log');} );

Route::post('login', 'HomeController@login' );

Route::get('logout', 'HomeController@logout' );

Route::post('chName', 'HomeController@chName' );

Route::get('challenge/{_id}', 'AttackController@challengeInfo' );
