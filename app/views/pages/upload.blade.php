@extends('layouts.navbar')
@section('content')

<div id="step1" class="main" style="text-align:center">
	<h1 class="title">Attack -- step #1</h1>
	<table style="width:90%;display:inline;">	
	<tr>
		<th>main function to create sudoku:</td>
		<th>main function to solve sudoku:</td>
	</tr>
	<tr>
		<td align="center" style="width:50%"><pre class="sh_cpp"><code>main()
{
	freopen("output.txt","w",stdout);
	Sudoku ss;
	ss.GiveQuestion();
	return 0;
}</pre></code></td>
		<td align="center"><pre class="sh_cpp"><code>main()
{
	freopen("output.txt","r",stdin);
	Sudoku ss;
	ss.ReadIn();
	ss.Solve();
	return 0;
}</pre></code></td>
	</tr>
	<tr>
		<th><label for="hfile">paste Sudoku.h code here</label></th>
		<th><label for="cppfile">paste Sudoku.cpp code here</label></th>
	</tr> 
	<tr>
		<td align="center"><textarea rows="20" cols="500" style="background-color:#baffba;width:80%" id="prehtext" onkeyup="changeH()">
<?php
	$hfile=fopen(asset('tmpCode/'.Session::get('id')."/Sudoku.h"),"r");
	if($hfile)
		while(!feof($hfile))
			echo fgets($hfile);
	fclose($hfile);
?>
		</textarea></td>
		<td align="center"><textarea id="precpptext" rows="20" cols="500" style="background-color:#c2ffff;width:80%" onkeyup="changeCpp()">
<?php
	$cppfile=fopen(asset("tmpCode/".Session::get('id')."/Sudoku.cpp"),"r");
	if($cppfile)
		while(!feof($cppfile))
			echo fgets($cppfile);
	fclose($cppfile);
?>
		</textarea></td>
	</tr>
	<tr>
		<th>Sudoku.h file preview</th>
		<th>Sudoku.cpp file preview</th>
	</tr>
	<tr>
		<td align="center" style="width:50%"><pre class="sh_cpp" style="width:420px;height:20pc;overflow-y:scroll;" id="hPreview"></pre></td>
		<td align="center" style="width:50%"><pre class="sh_cpp" style="width:420px;height:20pc;overflow-y:scroll;" id="cppPreview"></pre></td>
	<tr>
	</tr>
	<tr>
		<td colspan="2" align="center">
		{{ HTML::image("img/next.png","",array("class"=>"Button","onClick"=>"GO('".$op."','#step3')")) }}
		</td>
	</tr>
	</table>
</div>
<div id="step3" class="main" style="display:none">
	<h1 class="title">Attack -- step #2</h1>
	<h1 style="color:#24c0e8; padding-left:5%;">Check Your Code:</h1>
	<div width="90%" id="Result" style="text-align:center;padding-left:5%;padding-right:5%;">
	</div>
	<div id="canvasloader-container" class="wrapper"></div>
	<div class="ButtonDiv" id="BNext">
	</div>
	<div class="ButtonDiv" id="Finish1" style="display:none">
		{{ HTML::image("img/finish.png","",array("class"=>"Button","onClick"=>"location.href='".URL::to('/')."'")) }}
	</div>
</div>
<div id="step4" class="main" style="display:none">
	<h1 class="title">Attack -- step #3</h1>
	<div id="canvasloader-container2" class="wrapper" style="display:none"></div>
	<div width="90%" id="Time" style="padding-left:5%;padding-right:5%;">
	</div>
	<div width="90%" style="padding-left:5%; padding-right:5%;">
		注意事項:
		<ol>
			<li>比賽進行中請勿按重新整理，有些人的程式會跑比較久，就請各位等一下囉</li>
			<li>如果解題時間為0sec，有兩種可能：解題時間少於0.0001或是對方的GiveQuestion()有問題</li>
			<li>如果ReadIn()或Solve()有問題，會拿到TLE(逾時)，該次判定為輸</li>
			<li>目前給的時限是120sec，超過會拿到TLE(逾時)，該次認定為輸</li>
			<li>如果很不幸，一直遇到error，那請檢查你的code有沒有呼叫exit(0)，如果有，請改成return等等，因為網站會呼叫solve()多於一次</li>
			<li>如果有其他網站上的問題麻煩截圖，寄信給助教或到moodle留言，會盡快處理的~~ :)</li>
		</ol>
	</div>
	<div class="ButtonDiv" id="Finish" style="display:none">
		{{ HTML::image("img/finish.png","",array("class"=>"Button","onClick"=>"location.href='".URL::to('/')."'")) }}
	</div>
</div>
<script>
$(document).ready(function(){
	sh_highlightDocument();
	changeH();
	changeCpp();
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
