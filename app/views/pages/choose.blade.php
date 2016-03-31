@extends('layouts.navbar')
@section('content')

<div class="main">
	<div class="sub-menu">
		<button class="top2 sub-button"><a href="{{URL::to('upload')}}">Checker</a></button>
		<button class="topClick top2 sub-button"><a href="{{URL::to('rank')}}">Challenge</a></button>
	</div>
	<div style="width:80%;margin:auto">
		<h2 style='color:#0060bf'>Please select one platform:</h2>
		<div style="color:gray;font-size:1.1em;">You cannot change your selection after clicking on it. Think twice before you do!</div>
		<ul>
		  <li><a href="{{URL::to('choose/1')}}" class="round green">Basic<span class="round">You will need to solve your opponent’s Sudoku board and give him a board to solve it. </span></a></li>
			<li><a href="{{URL::to('choose/2')}}" class="round yellow">Advanced<span class="round">Two board need to be solved: one is your opponent’s, the another is yours; However, the second one is transformed by your opponent.</span></a></li>
		</ul> 
	</div>
</div>

<style>
* {
	-moz-box-sizing: border-box;
	-o-box-sizing: border-box;
	-webkit-box-sizing: border-box;
	box-sizing: border-box;
}

ul {
	margin: 30px auto;
	text-align: center;
}

li {
	list-style: none;
	position: relative;
	display: inline-block;
	width: 200px;
	height: 200px;
	margin: 50px;
}

@-moz-keyframes rotate {
	0% {transform: rotate(0deg);}
	100% {transform: rotate(-360deg);}
}

@-webkit-keyframes rotate {
	0% {transform: rotate(0deg);}
	100% {transform: rotate(-360deg);}
}

@-o-keyframes rotate {
	0% {transform: rotate(0deg);}
	100% {transform: rotate(-360deg);}
}

@keyframes rotate {
	0% {transform: rotate(0deg);}
	100% {transform: rotate(-360deg);}
}

.round {
	display: block;
	position: absolute;
	left: 0;
	top: 0;
	width: 100%;
	height: 100%;
	padding-top: 65px;		
	text-decoration: none;		
	text-align: center;
	font-size: 40px;		
	text-shadow: 0 1px 0 rgba(255,255,255,.7);
	font-family: "Hammersmith One", sans-serif;		
	-webkit-transition: all .25s ease-in-out;
	-o-transition: all .25s ease-in-out;
	-moz-transition: all .25s ease-in-out;
	transition: all .25s ease-in-out;
	box-shadow: 2px 2px 7px rgba(0,0,0,.2);
	border-radius: 300px;
	z-index: 1;
	border-width: 4px;
	border-style: solid;
}

.round:hover {
	width: 130%;
	height: 130%;
	left: -15%;
	top: -15%;
	font-size: 33px;
	padding-top: 38px;
	-webkit-box-shadow: 5px 5px 10px rgba(0,0,0,.3);
	-o-box-shadow: 5px 5px 10px rgba(0,0,0,.3);
	-moz-box-shadow: 5px 5px 10px rgba(0,0,0,.3);
	box-shadow: 5px 5px 10px rgba(0,0,0,.3);
	z-index: 2;
	border-size: 10px;
	-webkit-transform: rotate(-360deg);
	-moz-transform: rotate(-360deg);
	-o-transform: rotate(-360deg);
	transform: rotate(-360deg);
}

a.green {
	background-color: rgba(1,151,171,1);
	color: rgba(0,63,71,1);
	border-color: rgba(0,63,71,.2);
}

a.green:hover {
	color: rgba(1,151,171,1);
}

a.yellow {
	background-color: rgba(252,227,1,1);
	color: rgba(153,38,0,1);
	border-color: rgba(153,38,0,.2);
}

a.yellow:hover {
	color: rgba(252,227,1,1);
}

.round span.round {
	display: block;
	opacity: 0;
	-webkit-transition: all .5s ease-in-out;
	-moz-transition: all .5s ease-in-out;
	-o-transition: all .5s ease-in-out;
	transition: all .5s ease-in-out;
	font-size: 1px;
	border: none;
	padding: 25% 20% 0 20%;
	color: #fff;
}

.round span:hover {
	opacity: .85;
	font-size: 25px;
	-webkit-text-shadow: 0 1px 1px rgba(0,0,0,.5);
	-moz-text-shadow: 0 1px 1px rgba(0,0,0,.5);
	-o-text-shadow: 0 1px 1px rgba(0,0,0,.5);
	text-shadow: 0 1px 1px rgba(0,0,0,.5);	
}

.green span {
	background: rgba(0,63,71,.7);		
}

.yellow span {
	background: rgba(161,145,0,.7);	
}
</style>

@stop