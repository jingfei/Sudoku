@extends('layouts.navbar')
@section('content')

<div class="main">
	<div class="sub-menu">
		<button class="topClick top2 sub-button"><a href="{{URL::to('upload')}}">Checker</a></button>
		<button class="top2 sub-button"><a href="{{URL::to('platform')}}">Challenge</a></button>
	</div>
	{{Form::open(array('url'=>'checker', 'id'=>'uploadForm'))}}
	<div id="step1" style="text-align:center;width:100%;">
		<h1 class="title">Upload</h1>
		<table style="width:90%;display:inline;">	
		<tr>
			<th>main function to create sudoku:</td>
			<th>main function to solve sudoku:</td>
		</tr>
		<tr>
			<td align="center" style="width:50%"><pre class="sh_cpp"><code>main()
	{
		Sudoku ss;
		ss.giveQuestion();
		return 0;
	}</pre></code></td>
			<td align="center"><pre class="sh_cpp"><code>main()
	{
		Sudoku ss;
		ss.readIn();
		ss.solve();
		return 0;
	}</pre></code></td>
		</tr>
		<tr>
			<th>main function to check transformated functions:<br/>(Following is only one of examples.)</td>
			<th>main function to transform sudoku:</td>
		</tr>
		<tr>
			<td align="center" style="width:50%"><pre class="sh_cpp"><code>main()
	{
		Sudoku ss;
		ss.readIn();
		/* put transformated functions here */
		ss.rotate(80);
		ss.flip(0);
		ss.changeNum(3,4);
		ss.solve();
		return 0;
	}</pre></code></td>
			<td align="center"><pre class="sh_cpp"><code>main()
	{
		Sudoku ss;
		ss.readIn();
		ss.transform();
		return 0;
	}</pre></code></td>
		</tr>
		<tr>
			<th><label for="hfile">paste Sudoku.h code here</label></th>
			<th><label for="cppfile">paste Sudoku.cpp code here</label></th>
		</tr> 
		<tr>
			<td align="center"><textarea rows="20" cols="500" style="background-color:#baffba;width:80%" id="prehtext" name="htext" onkeyup="changeH()">{{$header}}</textarea></td>
			<td align="center"><textarea id="precpptext" name="cpptext" rows="20" cols="500" style="background-color:#c2ffff;width:80%" onkeyup="changeCpp()">{{$code}}</textarea></td>
		</tr>
		<tr>
			<th>Sudoku.h file preview</th>
			<th>Sudoku.cpp file preview</th>
		</tr>
		<tr>
			<td align="center" style="width:50%"><pre class="sh_cpp" style="width:420px;height:20pc;overflow-y:scroll;" id="hPreview"></pre></td>
			<td align="center" style="width:50%"><pre class="sh_cpp" style="width:420px;height:20pc;overflow-y:scroll;" id="cppPreview"></pre></td>
		</tr>
		<tr>
			<td colspan="2" align="center">
			{{ HTML::image("img/next.png","",array("class"=>"Button","id"=>"uploadFormSubmit")) }}
			</td>
		</tr>
		</table>
	</div>
</div>

<script>
$(document).ready(function(){
	sh_highlightDocument();
	changeH();
	changeCpp();
	$("#uploadFormSubmit").on("click", function(){
		$(".container").first().prepend('<div id="loading"><div class="sk-folding-cube"><div class="sk-cube1 sk-cube"></div><div class="sk-cube2 sk-cube"></div><div class="sk-cube4 sk-cube"></div><div class="sk-cube3 sk-cube"></div></div><h1>Wait a minute...<br/>or go to <a href="{{URL::to('log')}}">Record</a> page.</h1></div>');
		$("body").css("overflow","hidden");
		$.ajax({
			 type: "POST",
			 url: "{{URL::to('checker')}}",
			 dataType: "text",
			 data: $("#uploadForm").serialize()
		}).done(function(data){ 
			if(data){ 
				$("#loading").remove();
				$("body").css("overflow","auto");
				alert(data);
			}
			else location.href='{{URL::to("log")}}'; 
		});
	});
});
function changeH(){
	var tmp=htmlspecialchars($('#prehtext').val());
	$("#hPreview").html(tmp);
	sh_highlightDocument();
}
function changeCpp(){
	var tmp=htmlspecialchars($('#precpptext').val());
	$("#cppPreview").html(tmp);
	sh_highlightDocument();
}
// javascript 版本的 htmlspecialchars
var htmlspecialchars = function (string, quote_style) {
	string = string.toString();

	string = string.replace(/&/g, '&amp;');
	string = string.replace(/</g, '&lt;');
	string = string.replace(/>/g, '&gt;');

	if (quote_style == 'ENT_QUOTES') {
		string = string.replace(/"/g, '&quot;');
		string = string.replace(/\'/g, '&#039;');
	} else if (quote_style != 'ENT_NOQUOTES') {
		string = string.replace(/"/g, '&quot;');
	}
	
	return string;
}
$(document).delegate('#prehtext,#precpptext', 'keydown', function(e) {
	var keyCode = e.keyCode || e.which;

	if (keyCode == 9) {
		e.preventDefault();
		var start = $(this).get(0).selectionStart;
		var end = $(this).get(0).selectionEnd;

		// set textarea value to: text before caret + tab + text after caret
		$(this).val($(this).val().substring(0, start)
		+ "\t"
		+ $(this).val().substring(end));
		
		// put caret at right position again
//		$(this).get(0).selectionStart =
		$(this).get(0).selectionEnd = start + 1;
	}
});
</script>
	
@stop
