<?php 
	session_start(); 
	unset($_SESSION['op']);
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
	## check connection
	if ($mysqli->connect_errno) {
		echo "<p>MySQL error no {$mysqli->connect_errno} : {$mysqli->connect_error}</p>";
		exit();
	}
	##
?>
<?php include_once 'layout/header.php'; ?>
<div class="main">
	<h1 class="title">Ranking</h1>
	<table class="rank">
		<thead>
			<tr>
				<th>rank</th>
				<th>name</th>
				<th>score</th>
<?php
			if(isset($_SESSION['id'])){
				$ID=$_SESSION['id'];
				$sql="SELECT * FROM `Users` WHERE id='$ID'";
				$result=$mysqli->query($sql);
				$row=$result->fetch_array();
				$rank=$row['rank'];
				echo '<th>win or lose</th>';
			}
?>
				<th>status</th>
			</tr>
		</thead>
		<tbody>
<?php
	/*fetch $ID row*/
		$arr=array();
	if(isset($_SESSION['id'])){
		$ID=$_SESSION['id'];
		$sql="SELECT * FROM `Users` WHERE id='$ID'";
		$result=$mysqli->query($sql);
		$row=$result->fetch_array();
		$arr=unserialize($row['challenge_id']);
	}
	/***************/
	$sql="SELECT * FROM `Users` ORDER BY `score` DESC, `id`";
	$result=$mysqli->query($sql);
	while($rows=$result->fetch_array()){
		$isChallenge=false;
//		$sql="UPDATE `Users` SET `name` = ".htmlspecialchars($rows['name'], ENT_QUOTES)." WHERE `id` = '".$rows['id']."'";
//		$result3=$mysqli->query($sql);
		if($arr)
			foreach($arr as $item)
				if($item==$rows['id'])
					$isChallenge=true;
		if(!isset($_SESSION['id']) || $isChallenge)
			echo '		<tr>';
		else if($_SESSION['id']==$rows['id'])
			echo '<tr id="self">';
		else if($rows['correct']==0)
			echo '<tr class="enableCh" onclick="Challenge(\''.md5($rows['id']).'\');">';
		else
			echo '<tr>';
		echo '<td>'.$rows['rank'].'</td>
			<td>'.$rows['name'].'</td>
			<td>'.$rows['score'].'</td>';
		if(isset($_SESSION['id'])){
			if($rows['id']=='test')
				echo '<td>+0 or -0</td>';
			else if($rows['id']!=$_SESSION['id']){
				$add=0;
				if($rows['rank']>=$rank) $add=1;
				else $add=(int)(($rank-$rows['rank'])/5)+2;
				echo '<td>+'.$add.' or -1</td>';
			}
			else echo '<td>--</td>';
		}
		if($rows['correct']==0){
			if(isset($_SESSION['id']) && $rows['id']!=$_SESSION['id']){
				if(!$isChallenge)
					echo '<td><img src="./image/challenge2.png"/></td>';
				else
					echo '<td><img src="./image/ac.png" height="33px"/></td>';
			}
			else
				echo '<td><img src="./image/ac.png" height="33px"/></td>';
		}
		else if($rows['correct']==1)
			echo '<td><img src="./image/ce.png" height="33px"/></td>';
		else if($rows['correct']==2)
			echo '<td><img src="./image/tle.png" height="33px"/></td>';
		else if($rows['correct']==3)
			echo '<td><img src="./image/wa.png" height="33px"/></td>';
		else if($rows['correct']==4) 
			echo '<td><img src="./image/err.png" height="33px"/></td>';
		else if($rows['correct']==5) 
			echo '<td><img src="./image/pe.png" height="33px"/></td>';
		echo '</tr>';
	}
?>				
		</tbody>
	</table>
</div>
<script>
function GO(){
	$('body,html').animate({
		scrollTop:  $('#self').offset().top
	}, 800);
}
function Challenge(op){
	method = "post"; 
    var form = document.createElement("form");
    form.setAttribute("method", method);
    form.setAttribute("action", "challenge.php");

    var hiddenField = document.createElement("input");
    hiddenField.setAttribute("type", "hidden");
    hiddenField.setAttribute("name", "op");
    hiddenField.setAttribute("value", op);

    form.appendChild(hiddenField);

    document.body.appendChild(form);
    form.submit();
}
</script>
<?php include_once 'layout/footer.php'; ?>
