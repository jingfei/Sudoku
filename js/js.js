$(document).ready(function(){
	if($('.top2').length!=1){
		$('.enableCh').css('cursor','pointer');
		$('#rank #self').css('cursor','default');
	}
});

function ChFlip(){
	var tmp;
	if($("#Rule").hasClass("topClick")){
		tmp = $('#flipImg').html();
		$("#Rule").attr("class", "top2");
	}
	else{
		tmp= $('#flipText').html();
		$("#Rule").attr("class", "top2 topClick");
	}
	$(".flipbox").flippy({
		duration: "500",
		direction: "TOP",
		verso: tmp
	});
}

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

function Attack(){
	var tmp=confirm("Are you sure to use a chance?");
	if(tmp) location.replace('attack.php');
	else location.href="/Tournament/";
}

var cl;

function ShowCl1(){
	cl = new CanvasLoader('canvasloader-container');
	cl.setColor('#12e65c'); // default is '#000000'
	cl.setShape('rect'); // default is 'oval'
	cl.setDiameter(59); // default is 40
	cl.setDensity(44); // default is 40
	cl.setRange(1.2); // default is 1.3
	cl.show(); // Hidden by default
	// This bit is only for positioning - not necessary
	var loaderObj = document.getElementById("canvasLoader");
	loaderObj.style["text-align"]="center";
}

function ShowCl2(){
	$("#canvasloader-container").attr("id","tmp");
	$("#canvasLoader").attr("id","tmp2");
	$("#canvasloader-container2").attr("id","canvasloader-container");
	$("#canvasloader-container").show();
	cl = new CanvasLoader('canvasloader-container');
	cl.setColor('#db12e6'); // default is '#000000'
	cl.setShape('spiral'); // default is 'oval'
	cl.setDiameter(59); // default is 40
	cl.setDensity(58); // default is 40
	cl.setRange(1.2); // default is 1.3
	cl.setFPS(22); // default is 24
	cl.show(); // Hidden by default
	// This bit is only for positioning - not necessary
	var loaderObj = document.getElementById("canvasLoader");
	loaderObj.style["text-align"]="center";
}

function CallCheck(j,i,hfile,cppfile,op,Rand){
	if(j==-1)
		$.ajax({
			type: "POST",
			url: "Func.php",
			data: {
				action: 'UpdateScore',
				num: 2,
				a1: 0,
				a2: 0
			}
		}).done(function(data) {
			var tmp="<hr style='border-top:dashed 1px;'/>";
			tmp+="<h1 style='color:#24c0e8;' align='left'>Result:</h1>";
			document.getElementById('Result').innerHTML+=tmp;
			document.getElementById('Result').innerHTML+='<img src="./image/ac.png" /><br/>';
			cl.hide();
			if(op!=='test')
				$('#BNext').html('<img src="./image/button/next.png" class="Button" onclick="GO(\''+op+'\',\'#step4\')"/>');
			else $('#Finish1').show();
		});
	else if(j==0)
		$.ajax({
			url: "Check_give.php",
		}).done(function(respond2) {
			if(!respond2){
				var tmp="<h3 style='color:#0060bf'>GiveQuestion: Accepted</h3>";
				document.getElementById('Result').innerHTML+=tmp;
				CallCheck(j-1,i+1,hfile,cppfile,op,Rand+5);
			}
			else{
				var tmp="<h2 style='color:red'>GiveQuestion: Error~</h2>";
				document.getElementById('Result').innerHTML+=tmp;
				tmp="<hr style='border-top:dashed 1px;'/>";
				tmp+="<h1 style='color:#24c0e8;' align='left'>Result:</h1>";
				document.getElementById('Result').innerHTML+=tmp;
				document.getElementById('Result').innerHTML+=respond2;
				cl.hide();
				$('#Finish1').show();
			}
		});
	else
		$.ajax({
			type: "POST",
			url: "Check.php",
			data: {
				select: $('input[name="Select"]:checked').val(),
				hfile: hfile,
				cppfile: cppfile,
				op: op,
				Rand: Rand
			}
		}).done(function(respond2){
			if(!respond2){
				var tmp="<h3 style='color:#0060bf'>"+i.toString()+": Accepted</h3>";
				document.getElementById('Result').innerHTML+=tmp;
				CallCheck(j-1,i+1,hfile,cppfile,op,Rand+5);
			}
			else{
				var tmp="<h2 style='color:red'>"+i.toString()+": Error~</h2>";
				document.getElementById('Result').innerHTML+=tmp;
				tmp="<hr style='border-top:dashed 1px;'/>";
				tmp+="<h1 style='color:#24c0e8;' align='left'>Result:</h1>";
				document.getElementById('Result').innerHTML+=tmp;
				document.getElementById('Result').innerHTML+=respond2;
				cl.hide();
				$('#Finish1').show();
			}
		});
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

function GO(Pre,Name){
	String.prototype.replaceAt=function(index, character) {
    	return this.substr(0, index) + character + this.substr(index+character.length);
	}
	if(Name==='#step3'){
		ShowCl1();
		var n;
		var hfile=$("#prehtext").val();
/*		n=hfile.search("\\\\n");
		while(n!=-1){
			hfile=hfile.replaceAt(n,"@");
			n=hfile.search("\\\\n");
		}
*/		var cppfile=$("#precpptext").val();
/*		n=cppfile.search("\\\\n");
		while(n!=-1){
			cppfile=cppfile.replaceAt(n,"@");
			n=cppfile.search("\\\\n");
		}
*/		
		$.ajax({
			type: "POST",
			url: "Judge.php",
			data: {
				op: Pre,
				hfile: hfile,
				cppfile: cppfile
			}
		}).done(function(respond){
			var Rand=Math.floor((Math.random()*5)+10);
			if(!respond)  //compile success
				CallCheck(5,1,hfile,cppfile,Pre,Rand);
			else{
				document.getElementById('Result').innerHTML=respond;
				cl.hide();
				$('#Finish1').show();
			}
		});
		$('#step1').hide();
	}
	else if(Name==='#step4'){
		ShowCl2();
		var tmp="<h1 style='color:#24c0e8;'>Average time for solving a question:</h1>";
		tmp+="<table style='width:90%;font-size:20px;padding:2px;text-align:center;'>";
		tmp+="<tr><td width='10%'></td><th width='30%'>first</th><th width='30%'>second</th><th width='30%'>third</th></tr>";
		tmp+="<tr><th>Yours</th><td id='t0'></td><td id='t1'></td><td id='t2'></td></tr>";
		tmp+="<tr><th>Opponent</th><td id='t3'></td><td id='t4'></td><td id='t5'></td></tr>";
		tmp+="<tr><td></td><td id='p0'></td><td id='p1'></td><td id='p2'></td></tr></table>";
		document.getElementById('Time').innerHTML=tmp;
		CallRace(3,0,1,Pre);
		$('#step3').hide();
	}
	$(Name).show();
}

function rSelect(name){
	if(name==='new')
		document.getElementById('CodeText').style.display='inline';
	else
		document.getElementById('CodeText').style.display='none';
}
