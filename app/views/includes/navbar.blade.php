<div id="logo">
	<hr>
	<div id="top">
	<table width="100%"><tr><td align="left">
	<h1 style="display:table-cell;" >
		<a href="{{URL::to('/')}}">Sudoku Tournament</a>
	</h1></td>
	<td align="right">
		<div class="top2" id="Rule" onclick="ChFlip();">Rule</div>
		<div
			@if(Request::path()=="/") class="topClick top2"
			@else class="top2"
			@endif
			onclick="location.href='{{URL::to("/")}}';">Home</div>
		<div
			@if(strpos(Request::path(),"log")!==false) class="topClick top2";
			@else class="top2"
			@endif
			onclick="location.href='{{URL::to("log")}}';">Record</div>
		@if(Session::has('id'))
		<div
			@if(Request::path()=="upload" || Request::path()=="checker")
				class="topClick top2"
			@else class="top2"
			@endif
			onClick="location.href='{{URL::to('upload')}}'">Checker</div>
		<div class="top2" onClick="Setting();">Rename</div>
		<div class="top2" onClick="location.href='{{URL::to("logout")}}'">Logout</div>
		@else
		<div class="top2" onClick="LogIn();">Login</div>
		@endif
	</div>
	</td></tr></table>
	<hr>
	<div id="LogIn" style="display:none">
		{{Form::open()}}
		<input type="text" id="login_id" placeholder="StudentID" />
		<input type="password" id="login_pw" placeholder="Password" />
		<input type="submit" value="submit" />
		{{Form::close()}}
	<hr>
	</div>
	<div id="Setting" style="display:none">
		{{Form::open(array('url'=>'chName'))}}
		<input type="text" name="NewName" placeholder="Change Name (length<16 )" />
		<input type="submit" value="submit" />
		{{Form::close()}}
	<hr>
	</div>
<?php
			if(Session::has('id')){
				$row = DB::table('Users')->where('id',Session::get('id'))->first();
				echo '<div id="RemainTime">';
				echo '<table style="width:100%"><tr>
				<td style="width:90%;">';
				echo 'Hello '.$row->name.',
				<a href="#" onclick="GO();" style="text-decoration:underline;">rank '.$row->rank.'</a>, 
				'.$row->challenge.' chance(s) remained.';
				echo '</td></tr></table><hr/></div>';
			}
?>
</div>
<div class="flipbox-container">
		<div class="flipbox" style="height:500px">
			{{ HTML::image("img/sudoku2.jpg", "", array('class'=>'big')) }}
		</div>
	</div>
	{{ HTML::image("img/logo.png", "", array('class'=>'small')) }}
</div>
<!--hidden-->
	<div id="flipImg" style="display:none">
		{{ HTML::image("img/sudoku2.jpg", "", array('class'=>'big')) }}
	</div>
    <div id="flipText" style="display:none;">
		<textarea id="Regu" readonly>
		<?php 
			$file=fopen("Regular.txt","r");
			echo "\n";
			if($file)
				while(!feof($file))
					echo fgets($file);
			fclose($file);
			for($i=0; $i<15; $i++) echo "\n";
		?>
		</textarea>
    </div>
<!--hidden-->
<script>
$(document).ready(function(){
	$("#LogIn>form").submit(function(e){
		e.preventDefault();
		var login_id=$("#login_id").val();
		var login_pw=$("#login_pw").val();
		$.ajax({
			type: "POST",
			url: "{{URL::to('login')}}",
			data: {
				id: login_id,
				passwd: login_pw
			}
		}).done(function(response){
			if(response==="yes") location.href="{{URL::to('/')}}";
			else alert(response);
		});
	});
});
</script>
