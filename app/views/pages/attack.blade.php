@extends('layouts.navbar')
@section('content')

<div id="step4" class="main" style="display:none">
	<h1 class="title">Attack -- step #3</h1>
	<div id="canvasloader-container2" class="wrapper" style="display:none"></div>
	<div width="90%" id="Time" style="padding-left:5%;padding-right:5%;">
	</div>
	<div width="90%" style="padding-left:5%; padding-right:5%;">
		注意事項:
		<ol>
			<li>如果解題時間為0sec，有兩種可能：解題時間少於0.0001或是對方的giveQuestion()有問題</li>
			<li>如果readIn()或solve()有問題，會拿到 100 sec (逾時)</li>
			<li>目前給的時限是 60 sec，超過會拿到 100 sec (逾時)</li>
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
