<div id="logo" 
		@if(Request::path()=="/")
		style="background:rgba(255,255,255,0.3);top:50px;font-size:1.3em;width:100%;border-radius:0;left:0;position:absolute;height:auto"
		@endif >
	<div id="top" style="position:absolute;width:100%;z-index:10;background:rgba(255,255,255,0.4);top:30px;">
	<hr>
	<table width="100%" style="padding:0 50px"><tr><td align="left">
	<h1 style="display:table-cell;cursor:default" >
		@if(Request::path()==('/')) Program Design II
		@else <a href="{{URL::to('/')}}">Sudoku<br/> Tournament</a>
		@endif
	</h1></td>
	<td align="right">
		@if(Request::path()=="/")
		<div class="top2" id="Rule" onclick=" $('html, body').animate({ scrollTop: $('#RuleArticle').offset().top }, 1000);">Rule</div>
		@endif
		<div
			@if(Request::path()=="status") class="topClick top2"
			@else class="top2"
			@endif
			onclick="location.href='{{URL::to("status")}}';">Status</div>
		@if(Session::has('id'))
<!--		<div
			@if(Request::path()=="contest") class="topClick top2";
			@else class="top2"
			@endif
			onclick="location.href='{{URL::to("contest")}}';">Contest</div>
			-->
		@endif
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
				echo 'Hello '.'
				<a href="#" onclick="GO();" style="text-decoration:underline;font-weight:bold;">'.$row->name.'</a>, 
				'.$row->challenge.' chance(s) remained.';
				echo '</td></tr></table><hr/></div>';
			}
?>
</div>
@if(Request::path()!="/")
<div id="BigIMG" style="background:#f1ebeb">
{{ HTML::image("img/sudoku2.jpg", "", array('class'=>'big')) }}
</div>
	{{ HTML::image("img/logo.png", "", array('class'=>'small','style'=>'bottom:10%')) }}
@endif
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
