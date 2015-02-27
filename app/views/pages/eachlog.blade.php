@extends('layouts.navbar')
@section('content')

		<div class="main">
			<h1 class="title">Result</h1>
			{{$result->img}}
			@if($result->op)
			<div>
				<table id="attackResult">
				<tr><th></th>
					<th>opponent's</th>
					<th>yours</th>
					<th>result</th>
				</tr>
				<tr><th>Round 1</th>
					<td>{{$result->comment['op1']}} second(s)</td>
					<td>{{$result->comment['self1']}} second(s)</td>
					<td>@if($result->comment['res1']==0) tie
						@elseif($result->comment['res1']==1) win  
						@elseif($result->comment['res1']==-1) lose
						@endif</td>
				</tr>
				<tr><th>Round 2</th>
					<td>{{$result->comment['op2']}} second(s)</td>
					<td>{{$result->comment['self2']}} second(s)</td>
					<td>@if($result->comment['res2']==0) tie
						@elseif($result->comment['res2']==1) win
						@elseif($result->comment['res2']==-1) lose
						@endif</td>
				</tr>
				<tr><th>Round 3</th>
					<td>{{$result->comment['op3']}} second(s)</td>
					<td>{{$result->comment['self3']}} second(s)</td>
					<td>@if($result->comment['res3']==0) tie
						@elseif($result->comment['res3']==1) win  
						@elseif($result->comment['res3']==-1) lose
						@endif</td>
				</tr>
				</table>
			</div>
			@elseif($result->comment)
			<div id="Hint">
				<br/>
				<div style="font-size:24px">hint message:</div><br/>
				<textarea style="height:20pc;width:100%" readonly>{{$result->comment}}</textarea>
			</div>
			@endif
			@if(!$result->op)
			<div id="Code">
			<table style="width:100%"> 
				<tr>
					<td style="font-size:24px">Sudoku.h</td>
					<td style="font-size:24px">Sudoku.cpp</td>
				</tr>
				<tr>
					<td style="width:50%"><pre class="sh_cpp" style="height:20pc;overflow-y:scroll;" id="hPreview">{{$result->header}}</pre></td>
					<td style="width:50%"><pre class="sh_cpp" style="height:20pc;overflow-y:scroll;" id="cppPreview">{{$result->code}}</pre></td>
				</tr>
			</table>
			</div>
			@endif
		</div>
	
<style>
.main img{height:60px; margin:0 5%;}
#Hint, #Code{
	margin: 0 auto;
	padding:0 5%;
	text-align:left; 
	width:90%;
}
.main {text-align: center;}
</style>
<script>
$(document).ready(function(){
	sh_highlightDocument();
});
</script>

@stop
