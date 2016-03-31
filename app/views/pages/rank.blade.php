@extends('layouts.navbar')
@section('content')

<div class="main">
	<div class="sub-menu">
		<button class="top2 sub-button"><a href="{{URL::to('status')}}">Status</a></button>
		<button class="topClick top2 sub-button"><a href="{{URL::to('rank')}}">Basic</a></button>
		<button class="top2 sub-button"><a href="{{URL::to('rank')}}">Advanced</a></button>
	</div>
	<h1 class="title">Ranking</h1>
	<table class="rank">
		<thead>
			<tr>
				<th>rank</th>
				<th>name</th>
				<th>score</th>
				@if($isLogin) <th>win or lose</th> @endif
				<th>status</th>
			</tr>
		</thead>
		<tbody>
			@foreach($users as $rows) @if($rows->id!=='admin')
				@if(!$isLogin || $rows->isChallenge) <tr>
				@elseif($isLogin == $rows->id) <tr id="self">
				@elseif($challenge_time==0) <tr> 
				@elseif($rows->correct==0 && $isAC) 
					<tr class="enableCh" onClick="location.href='{{URL::to("challenge/".$rows->pw)}}';">
				@else <tr>
				@endif

				<td> {{$rows->rank}} </td>
				<td> {{$rows->name}} </td>
				<td> {{$rows->score}} </td>

				@if($isLogin) <td> {{$rows->addScore}} </td> @endif
				
				<td>
				@if($rows->correct==0)
					@if($isLogin && $rows->id!=$isLogin && !$rows->isChallenge && $isAC && $challenge_time)
						{{ HTML::image("img/challenge2.png") }}
					@else
						{{ HTML::image("img/ac.png","",array("height"=>"33px")) }}
					@endif
				@elseif($rows->correct==1)
					{{ HTML::image("img/ce.png","",array("height"=>"33px")) }}
				@elseif($rows->correct==2)
					{{ HTML::image("img/tle.png","",array("height"=>"33px")) }}
				@elseif($rows->correct==3)
					{{ HTML::image("img/wa.png","",array("height"=>"33px")) }}
				@elseif($rows->correct==4)
					{{ HTML::image("img/err.png","",array("height"=>"33px")) }}
				@elseif($rows->correct==5)
					{{ HTML::image("img/pe.png","",array("height"=>"33px")) }}
				@endif
				</td></tr>
			@endif @endforeach
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

$(document).ready(function(){
	$(".enableCh").hover(function(){
		$(" td img",this).attr("src","{{asset('img/challenge.png')}}");
	}, function(){
		$(" td img",this).attr("src","{{asset('img/challenge2.png')}}");
	});
});
</script>

@stop
