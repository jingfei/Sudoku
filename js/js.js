$(document).ready(function(){
	if($('.top2').length!=1){
		$('.enableCh').css('cursor','pointer');
		$('#rank #self').css('cursor','default');
	}
});

function LogIn(){
	if(document.getElementById('LogIn').style.display==="none"){
		var Height=$('#LogIn').height();
		$('#LogIn').height(0);
		$('#LogIn').show();
		$('#LogIn').animate({height:Height}, 1000, 'swing');
	}
	else{
		$('#LogIn').hide();
	}
}

function Setting(){
	if(document.getElementById('Setting').style.display==="none"){
		var Height=$('#Setting').height();
		$('#Setting').height(0);
		$('#Setting').show();
		$('#Setting').animate({height:Height}, 1000, 'swing');
	}
	else{
		$('#Setting').hide();
	}
}

var T=new Array(6);

function AfterRace(op){
	var win=0,lose=0;
	for(var i=0; i<3; ++i){
		var tmp1="p"+i.toString();
		if(T[i]<T[i+3]){
			++win;
			tmp="<img src='./image/win.png' height='70%' />";
		}
		else if(T[i]===T[i+3]){
			tmp="<img src='./image/tie.png' height='70%' />";
		}
		else{
			++lose;
			tmp="<img src='./image/lose.png' height='70%' />";
		}
		document.getElementById(tmp1).innerHTML=tmp;
	}
	tmp='<hr style="width:90%;border-top:dashed 1px;"/>';
	var Status;
	if(win>lose){
		tmp+='<img src="./image/win2.png" />';
		Status=1;
	}
	else if(win===lose){
		tmp+='<img src="./image/tie2.png" />';
		Status=0;
	}
	else{
		tmp+='<img src="./image/lose2.png" />';
		Status=-1;
	}
	document.getElementById('Time').innerHTML+=tmp;
	$.ajax({
		type: "POST",
		url: "Func.php",
		data: {
			action: 'RaceResult',
			num: 2,
			a1: Status.toString(),
			a2: op
		}
	}).done(function(data) {
		tmp='<h1 style="color:red">score '+data+'</h1>';
		document.getElementById('Time').innerHTML+=tmp;
		$('#Finish').show();
		cl.hide();
	});
}

function CallRace(j,i,Status,op){
	if(j==0){
		if(Status==1)
			CallRace(3,i,2,op);
		else
			AfterRace(op);
	}
	else{
		$.ajax({
			type: "POST",
			url: "Func.php",
			data: {
				action: 'Race',
				num: 2,
				a2: Status.toString(),
				a1: op
			}
		}).done(function(respond){
			var tmp1="t"+i.toString();
			var tmp=respond;
			if(!tmp){
				alert("something wrong there, please try again");
				$.ajax({ 
					type: "POST", 
					url: "Func.php", 
					data: {
						action: 'ChallengeAdd1',
						num: 0
					} 
				}).done(function(respond){
					location.href="/Tournament/";
				});
			}
			else if(tmp==='TLE'){
				tmp+="</td>";
				T[i]=Number.MAX_VALUE;
			}
			else{
				tmp+=" seconds</td>";
				T[i]=parseFloat(respond);
			}
			if(tmp){
				document.getElementById(tmp1).innerHTML=tmp;
				CallRace(j-1,i+1,Status,op);
			}
		});
	}
}

function rSelect(name){
	if(name==='new')
		document.getElementById('CodeText').style.display='inline';
	else
		document.getElementById('CodeText').style.display='none';
}

