@extends('layouts.navbar')
@section('content')

<div id="step3" class="main">
	<h1 class="title">Checker</h1>
	<div width="90%" id="Result" style="text-align:center;padding-left:5%;padding-right:5%;">
	</div>
	<div id="canvasloader-container" class="wrapper"></div>
	<div class="ButtonDiv" id="BNext">
	</div>
	<div class="ButtonDiv" id="Finish1" style="display:none">
		{{ HTML::image("img/finish.png","",array("class"=>"Button","onClick"=>"location.href='".URL::to('/')."'")) }}
	</div>
</div>
<script>
$(document).ready(function(){
	ShowCl1();
});
</script>
	
@stop
