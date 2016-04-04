@extends('layouts.navbar')
@section('content')

<div class="main">
	<h1 class="title">Challenge</h1>
	<div id="information">
		{{ HTML::image("img/wanted.jpg") }}
		<table>
			<tr>
				<th>name</th>
				<td>{{$op->name}}</td>
			</tr>
			<tr>
				<th>rank</th>
				<td>{{$op->rank}}</td>
			</tr>
			<tr>
				<th>score</th>
				<td>{{$op->score}}</td>
			</tr>		
		</table>
	</div>
	<div id="regular">
		<?php 
			$file=fopen("Regular.txt","r");
			if($file)
				while(!feof($file))
					echo fgets($file);
			fclose($file);
		?>
	</div><br/>
	<div class="ButtonDiv">
		<h2>Ready to attack?</h2>
		{{ HTML::image("img/go.png","",array("class"=>"Button","onClick"=>"Attack();")) }}
		{{ HTML::image("img/wait.png","",array("class"=>"Button","onClick"=>"location.href='".URL::to('/')."';")) }}
	</div>
</div>
<script>
function Attack(){
	var tmp=confirm("Are you sure to use a chance?");
	if(tmp){
		location.href='{{URL::to("attack/".$pw)}}';
	}
	else location.href="{{URL::to('/')}}";
}
</script>

@stop
