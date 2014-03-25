<?php
	session_start(); 
	if(!isset($_SESSION['user'])){
		echo "<script>alert('Log in please~')</script>";
		echo '<script>location.replace(".");</script>';
	}
?>
<html>
	<head>
		<title>Programming Design II hw2 checking</title>
		<link rel="stylesheet" href="style/style.css" />
		<link rel="stylesheet" href="CppStyle/sh_vim-dark.min.css" />
		<script type="text/javascript" src="CppStyle/sh_cpp.min.js"></script>
		<script type="text/javascript" src="CppStyle/sh_main.min.js"></script>
		<script type="text/javascript" src="script/jquery-2.0.3.js"></script>
		<script type="text/javascript" src="script/script.js"></script>
		<script type="text/javascript" src="script/heartcode-canvasloader-min.js"></script>
	</head>
	<body onload="sh_highlightDocument();">
		<img src="StatusImg/logout.png" style="position:fixed;width:100px;height:100px;cursor:pointer" onclick="location.href='.'"/>
		<div id="step1" style="padding:0 5% 5% 5%;width:100%">
			<h1 style="width:90%;text-align:center;color:#f58732;padding:3% 0;">Upload your code ~</h1>
			<table id="UploadTable" width="90%" style="display:inline;">	
			<tr>
				<th>main function to create sudoku</td>
				<th>main function to solve sudoku</td>
			</tr>
			<tr>
				<td align="center"><pre class="sh_cpp"><code>main()
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
				<th colspan="2" class="lang">Select Language</th>
			</tr> 
			<tr>
				<td colspan="2" style="padding-left:35%" class="lang">
					<input type="radio" name="lang" checked/>
					&nbsp;C++ use command g++ file_name.cpp  <br/>
					<input type="radio" name="lang"/>
					&nbsp;C++11 use command g++ -std=c++0x file_name.cpp
				</td>
			</tr>
			<tr>
				<th><label for="hfile">paste Sudoku.h code here</label></th>
				<th><label for="cppfile">paste Sudoku.cpp code here</label></th>
			</tr> 
			<tr>
				<td align="center"><textarea rows="20" style="background-color:#baffba;width:80%" id="prehtext" onkeyup="changeH()"></textarea></td>
				<td align="center"><textarea id="precpptext" rows="20" style="background-color:#c2ffff;width:80%" onkeyup="changeCpp()"></textarea></td>
			</tr>
			<tr>
				<th>Sudoku.h file preview</th>
				<th>Sudoku.cpp file preview</th>
			</tr>
				<td align="center" style="width:50%"><pre class="sh_cpp" style="width:80%;height:20pc;overflow-y:scroll;" id="hPreview"></pre></td>
				<td align="center" style="width:50%"><pre class="sh_cpp" style="width:80%;height:20pc;overflow-y:scroll;" id="cppPreview"></pre></td>
			<tr>
			</tr>
			<tr>
				<td colspan="2" align="center">
				<img src="StatusImg/next.png" class="Button" onclick="Check()" style="cursor:pointer"/>
				</td>
			</tr>
		</table>
		</div>
		<div id="step2" style="display:none;padding:5%;"><br/>
			<h1 style="color:#f58723; padding-left:5%;">Check Your Code...</h1>
			<div width="90%" id="Result" style="text-align:center;padding-left:5%;padding-right:5%;">
			</div>
			<div id="canvasloader-container" class="wrapper"></div>
			<div class="ButtonDiv" id="Finish1" style="display:none;text-align:center;width:90%;padding-left:5%;padding-right:5%;">
				<hr style='border-top:dashed 1px #c7ba99;'/>
				<img src="../image/button/finish.png" class="Button" onclick="ReturnStep1();" style="cursor:pointer"/>
			</div>
		</div>
<?php include "footer.php" ?>
	</body>
</html>
<script>
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
