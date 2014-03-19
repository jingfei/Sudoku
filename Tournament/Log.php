<?php 
	session_start();
	require_once("db_const.php");
	$mysqli=new mysqli(DB_HOST,DB_USER,DB_PASS,DB_NAME);
	## check connection
	if ($mysqli->connect_errno) {
		echo "<p>MySQL error no {$mysqli->connect_errno} : {$mysqli->connect_error}</p>";
		exit();
	}
	##
	include_once 'layout/header.php'; 
?>
		<div class="main">
<?php
		if(isset($_SESSION['id'])){
			echo '<form style="text-align:right;padding-right:10px;font-size:20px;color:#0060bf">
				view:&nbsp&nbsp
				<input type="radio" value="spec" name="log" checked="checked"/>yours
				<input type="radio" value="all" name="log"/>all
			</form>
			<hr>';
		}
?>
			<h1 class="title">Record</h1>
			<div id="fortable">
<?php 
			include 'Func.php'; 
			if(isset($_SESSION['id'])) getLog('spec'); 
			else getLog('all');
?>
			</div>
		</div>
<script>
	$(document).ready(function(){
		$('input[type=radio][name=log]').change(function() {
			if (this.value == 'all') {
				$.ajax({
					type: "POST",
					url: "Func.php",
					data: {
						action: 'getLog',
						num: 1,
						a1: 'all'
					}
				}).done(function(respond){
					document.getElementById('fortable').innerHTML=respond;
				});
			}		
			else{
				$.ajax({
					type: "POST",
					url: "Func.php",
					data: {
						action: 'getLog',
						num: 1,
						a1: 'spec'
					}
				}).done(function(respond){
					document.getElementById('fortable').innerHTML=respond;
				});
			}
		});
	});
</script>
<style type="text/css">
	table img{height:33px;}
</style>
<?php include_once 'layout/footer.php'; ?>
