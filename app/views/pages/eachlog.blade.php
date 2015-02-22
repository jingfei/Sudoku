@extends('layouts.navbar')
@section('content')

		<div class="main">
			<h1 class="title">Result</h1>
			{{$result->img}}
			@if($result->comment)
			<div id="Hint">
				<br/>
				<div style="font-size:24px">hint message:</div><br/>
				<textarea style="width:100%;height:500px" readonly>{{$result->comment}}</textarea>
			</div>
			@endif
		</div>
	
<style>
.main img{height:60px; margin:0 5%;}
#Hint{margin:0 5%; text-align:left;}
.main {text-align: center;}
</style>

@stop
