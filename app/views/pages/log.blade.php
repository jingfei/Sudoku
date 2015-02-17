@extends('layouts.navbar')
@section('content')

		<div class="main">
		@if(Session::has('id'))
			<form style="text-align:right;padding-right:10px;font-size:20px;color:#0060bf">
				view:&nbsp;&nbsp;
				<input type="radio" value="spec" name="log" checked="checked"/>yours
				<input type="radio" value="all" name="log"/>all
			</form>
			<hr>;
		@endif
			<h1 class="title">Record</h1>
			@if(Session::has('id'))
			<div id="fortable">{{HomeController::getLog('spec')}}</div>
			<div id="fortable2" style="display:none">{{HomeController::getLog('all')}}</div>
			@else
			<div id="fortable2">{{HomeController::getLog('all')}}</div>
			@endif
		</div>
<script>
	$(document).ready(function(){
		$('input[type=radio][name=log]').change(function() {
			if(this.value=="all"){
				$("#fortable2").show();
				$("#fortable").hide();
			}
			else{
				$("#fortable").show();
				$("#fortable2").hide();
			}
		});
	});
</script>
<style type="text/css">
	table img{height:33px;}
</style>
	
@stop
