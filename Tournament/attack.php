<?php
	session_start(); 
	if(!isset($_SESSION['id'])){
		echo "<script>alert('Log in please~')</script>";
		echo '<script>location.replace("./index.php");</script>';
	}
	else if(!isset($_SESSION['op'])){
		echo "<script>alert('select an opponent');</script>";
		echo "<script>location.replace('./index.php');</script>";
	}
	$op=$_SESSION['op'];
	$ID=$_SESSION['id'];
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
## check connection
	if($mysqli->connect_errno){
		echo "<p>MySQL error no {$mysqli->connect_errno} : {$mysqli->connect_error}</p>";
		exit();
	}
##
	/*fetch $ID row*/
	$sql="SELECT * FROM `Users` WHERE id='$ID'";
	$result=$mysqli->query($sql);
	$row=$result->fetch_array();
	/***************/
	/*check challenge times*/
	if($row['challenge']<=0){
		$sql="UPDATE `Users` SET challenge=0 WHERE id='$ID'";
		$result=$mysqli->query($sql);
		echo "<script>alert('you challenged too much!!');</script>";
		echo "<script>location.replace('./index.php');</script>";
	}
	/***********************/
	/*find challenge list*/
	$arr=array();
	$arr=unserialize($row['challenge_id']);
	if($arr)
		foreach($arr as $item)
			if($item==$op){
				echo "<script>alert('you have challenged him today');</script>";
				echo "<script>location.replace('/Tournament/');</script>";
				exit();
			}
	/*********************/
	/*minus challenge time*/
	$sql="UPDATE `Users` SET challenge=".(string)($row['challenge']-1)." WHERE id='$ID'";
	$result=$mysqli->query($sql);
	/**********************/
	/*save to challenge list*/
	$arr[]=$op;
	$ser=serialize($arr);
	$sql="UPDATE `Users` SET challenge_id='$ser' WHERE id='$ID'";
	$result=$mysqli->query($sql);
	/************************/
?>
<?php include_once('layout/header.php'); ?>
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
	$sql="SELECT * FROM `Users` WHERE id='$ID'";
	$result=$mysqli->query($sql);
	$row=$result->fetch_array();
	echo $row['header'];
?>
				</textarea></td>
				<td align="center"><textarea id="precpptext" rows="20" cols="500" style="background-color:#c2ffff;width:80%" onkeyup="changeCpp()">
<?php
	$sql="SELECT * FROM `Users` WHERE id='$ID'";
	$result=$mysqli->query($sql);
	$row=$result->fetch_array();
	echo $row['code'];
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
				<img src="../image/button/next.png" class="Button" onclick="GO('<?php echo $op;?>','#step3')"/>
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
			<div class="ButtonDiv" id="BNext" style="display:none">
				<img src="./image/button/next.png" class="Button" onclick="GO('<?php echo $op;?>','#step4')"/>
			</div>
			<div class="ButtonDiv" id="Finish1" style="display:none">
				<img src="./image/button/finish.png" class="Button" onclick="location.href='/Tournament/';"/>
			</div>
		</div>
		<div id="step4" class="main" style="display:none">
			<h1 class="title">Attack -- step #3</h1>
			<div id="canvasloader-container2" class="wrapper" style="display:none"></div>
			<div width="90%" id="Time" style="padding-left:5%;padding-right:5%;">
			</div>
			<div class="ButtonDiv" id="Finish" style="display:none">
				<img src="./image/button/finish.png" class="Button" onclick="location.href='/Tournament/';"/>
			</div>
		</div>
<?php include_once('layout/footer.php'); ?>
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
