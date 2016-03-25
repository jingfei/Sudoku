@extends('layouts.navbar')
@section('content')

		<div class="main">
		@if(Session::has('id') && Session::get('id')!=='admin')
			<form style="text-align:right;padding-right:10px;font-size:20px;color:#0060bf">
				view:&nbsp;&nbsp;
				<input type="radio" value="spec" name="log" checked="checked"/>yours
				<input type="radio" value="all" name="log"/>all
			</form>
			<hr>
		@endif
			<h1 class="title">Record</h1>
			@if(Session::has('id') && Session::get('id')!=='admin')
			<div id="fortable">
				<hr style='border-top:dashed 1px;' width='80%'>
				<h2 style='text-align:center;color:#0060bf'>Your attack</h2>
				<table class='rank'>
					<tr><th>date</th>
						<th>name</th>
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
						<th>result</th>
						<th>speed level</th>
					</tr>
					@foreach($attacked as $rows)
					<tr onClick='location.href="{{$rows->url}}"' style='cursor:pointer'>
						<td>{{$rows->date}}</td>
						<td>{{$name[$rows->studentID]}}</td>
						<td>{{$rows->img}}</td>
						<td>{{$rows->speed}}</td>
					</tr>
					@endforeach
				</table>
			</div>
			@endif
			<div id="fortable2" @if(Session::has('id') && Session::get('id')!=='admin') style="display:none" @endif >
				<table class='rank'>
					<tr><th>date</th>
						<th>name</th>
						<th>result</th>
						<th>speed level</th>
					</tr>
					@foreach($all as $rows)

					@if($rows->url)
					<tr onClick='location.href="{{$rows->url}}"' style='cursor:pointer'>
					@else <tr>
					@endif

						<td>{{$rows->date}}</td>
						<td>{{$name[$rows->studentID]}}</td>
						<td>{{$rows->img}}</td>
						<td>{{$rows->speed}}</td>
					</tr>
					@endforeach
				</table>
			</div>
		</div>
<script>
	$(document).ready(function(){
		$('input[type=radio][name=log]').change(function() {
			if(this.value=="all"){
				$("#fortable2").show();
				$("#fortable").hide();
			}
			else{
				$("#fortable").show();
				$("#fortable2").hide();
			}
		});
	});
</script>
<style type="text/css">
	table img{height:33px;}
</style>
	
@stop
