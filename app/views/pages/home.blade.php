@extends('layouts.navbar')
@section('content')

<div id="BigIMG" style="width:100%;height:100%;position:fixed;z-index:-1;top:0;left:0">
{{ HTML::image("img/sudoku.jpg", "", array('class'=>'big')) }}
</div>
<div>
	{{ HTML::image("img/logo.png", "", array('class'=>'small','style'=>'bottom:10%')) }}
</div>
	<div id="hidden" style="position:relative;z-index:-1"></div>
    <div id="RuleArticle" style="position:relative; width:100%;">
		<div class="title" style="padding:30px;font-size:3.5em">Rule</div>
		<div id="Regu" style="background:rgba(255,255,255,0.4);margin:0 5%;padding:5%;border-radius:10px;width:80%;font-size:1.4em">
		<?php 
			$file=fopen("Regular.txt","r");
			if($file)
				while(!feof($file))
					echo fgets($file);
			fclose($file);
		?>
		</div>
    </div>
<!--hidden-->
<script>
$(document).ready(function(){
	$("#hidden").height( $(window).height());
});
$(window).load(function(){
	$(".container").fadeIn('slow');
});
</script>
<style>
body{margin:0;}
.container{display:none;}
#Regu{
	font-family: 'Source Sans Pro', sans-serif;
	width:100%;
	height: 100%;
	background: #f1ebeb;
	color: #0060bf;
	font-weight:bold;
	font-size: 18px;
	border:none;
	overflow: auto;
}
#Regu h2{ font-size: 45px; font-weight: bold; margin-top:0;}
#Regu h3{ font-family: 'Source Sans Pro', sans-serif; font-size: 28px; font-weight: 400; line-height: 32px; margin: 0 0 24px; }
</style>

@stop
