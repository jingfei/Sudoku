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
			echo "\n";
			if($file)
				while(!feof($file))
					echo fgets($file)."<br/>";
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
</style>

@stop
