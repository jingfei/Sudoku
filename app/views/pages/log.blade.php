@extends('layouts.navbar')
@section('content')

		<div class="main">
		@if(Session::has('id') && Session::get('id')!=='admin')
			<div class="sub-menu">
				<button class="topClick top2 sub-button" id="yours">yours</button>
				<button class="top2 sub-button" id="all">all</button>
			</div>
		@endif
			<h1 class="title">Record</h1>
			@if(Session::has('id') && Session::get('id')!=='admin')
			<div id="fortable">
				<hr style='border-top:dashed 1px;' width='80%'>
				<h2 style='text-align:center;color:#0060bf'>Your attack</h2>
				<table class='rank'>
					<tr><th>date</th>
						<th>name</th>
						<th>opponent</th>
						<th>result</th>
						<th>speed level</th>
					</tr>
					@foreach($spec as $rows)

					@if($rows->url!=null)
					<tr onClick='location.href="{{$rows->url}}"' style='cursor:pointer'>
					@else <tr>
					@endif

						<td>{{$rows->date}}</td>
						<td>{{$name[$rows->studentID]}}</td>
						<td>{{$rows->op ? $name[$rows->op] : "--"}}</td>
						<td>{{$rows->img}}</td>
						<td>{{$rows->speed}}</td>
					</tr>
					@endforeach
				</table>
				<br/>

				<hr style='border-top:dashed 1px;' width='80%'>
				<h2 style='text-align:center;color:#0060bf'>Being attacked</h2>
				<table class='rank'>
					<tr><th>date</th>
						<th>name</th>
						<th>opponent</th>
						<th>result</th>
					</tr>
					@foreach($attacked as $rows)
					<tr onClick='location.href="{{$rows->url}}"' style='cursor:pointer'>
						<td>{{$rows->date}}</td>
						<td>{{$name[$rows->studentID]}}</td>
						<td>{{$name[$rows->op]}}</td>
						<td>{{$rows->img}}</td>
					</tr>
					@endforeach
				</table>
			</div>
			@endif
			<div id="fortable2" @if(Session::has('id') && Session::get('id')!=='admin') style="display:none" @endif >
				<table class='rank'>
					<tr><th>date</th>
						<th>name</th>
						<th>opponent</th>
						<th>result</th>
					</tr>
					@foreach($all as $rows)

					@if($rows->url)
					<tr onClick='location.href="{{$rows->url}}"' style='cursor:pointer'>
					@else <tr>
					@endif

						<td>{{$rows->date}}</td>
						<td>{{$name[$rows->studentID]}}</td>
						<td>{{$rows->op ? $name[$rows->op] : "--"}}</td>
						<td>{{$rows->img}}</td>
					</tr>
					@endforeach
				</table>
			</div>
		</div>
<script>
	$(document).ready(function(){
		$("#yours").on('click',function(e){
			e.preventDefault();
			$("#fortable").show();
			$("#fortable2").hide();
			$(this).addClass("topClick");
			$("#all").removeClass("topClick");
		});
		$("#all").on('click',function(e){
			e.preventDefault();
			$("#fortable2").show();
			$("#fortable").hide();
			$(this).addClass("topClick");
			$("#yours").removeClass("topClick");
		});
	});
</script>
<style type="text/css">
	table img{height:33px;}
</style>
	
@stop
