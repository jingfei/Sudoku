@extends('layouts.navbar')
@section('content')

		<div class="main">
			<h1 class="title">Result</h1>
			{{$result->img}}
			@if($result->comment)
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
