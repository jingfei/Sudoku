var Step2Text;
$(document).ready(function(){
	Step2Text=$('#step2').html();
});

function ReturnStep1(){
	var Src="StatusImg/";
	$('#step2').html(Step2Text);
	$('#step1').show();
	$('#step2').hide();
	$.ajax({url:"GetStatus.php"}).done(function(respond){
		Src=Src+respond+".png";
		$('#StatusImg').attr("src",Src);
	});
}

var c1;
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

function CallCheck(j,i,Rand){
	if(j==-1){
		var tmp="<hr style='border-top:dashed 1px #c7ba99;'/>";
		tmp+="<h1 style='color:#f58723;' align='left'>Result:</h1>";
		document.getElementById('Result').innerHTML+=tmp;
		$.ajax({url:"UpdateAccepted.php"});
		document.getElementById('Result').innerHTML+='<img src="StatusImg/ac.png" /><br/>';
		cl.hide();
		$('#Finish1').show();
	}
	else if(j==0)
		$.ajax({
			url: "Check_give.php",
		}).done(function(respond2) {
			if(!respond2){
				var tmp="<h3 style='color:black'>GiveQuestion: Accepted</h3>";
				document.getElementById('Result').innerHTML+=tmp;
				CallCheck(j-1,i+1,Rand+5);
			}
			else{
				var tmp="<h2 style='color:red'>GiveQuestion: Error~</h2>";
				document.getElementById('Result').innerHTML+=tmp;
				tmp="<hr style='border-top:dashed 1px #c7ba99;'/>";
				tmp+="<h1 style='color:#f58723;' align='left'>Result:</h1>";
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
				Rand: Rand
			}
		}).done(function(respond2){
			if(!respond2){
				var tmp="<h3 style='color:black'>"+i.toString()+": Accepted</h3>";
				document.getElementById('Result').innerHTML+=tmp;
				CallCheck(j-1,i+1,Rand+5);
			}
			else{
				var tmp="<h2 style='color:red'>"+i.toString()+": Error~</h2>";
				document.getElementById('Result').innerHTML+=tmp;
				tmp="<hr style='border-top:dashed 1px #c7ba99;'/>";
				tmp+="<h1 style='color:#f58723;' align='left'>Result:</h1>";
				document.getElementById('Result').innerHTML+=tmp;
				document.getElementById('Result').innerHTML+=respond2;
				cl.hide();
				$('#Finish1').show();
			}
		});
}

function Check(){
	ShowCl1();
	$('#step1').hide();
	$('#step2').show();
	var n;
	var hfile=$("#prehtext").val();
	var cppfile=$("#precpptext").val();
	if(!hfile || !cppfile){
		alert("Please paste your code");
		$('#step1').show();
		$('#step2').hide();
		cl.hide();
		return;
	}
	$.ajax({
		type: "POST",
		url: "Judge.php",
		data: {
			hfile: hfile,
			cppfile: cppfile
		}//,
//		error: function(xhr, textStatus, error){
//			alert(xhr.statusText);
//			alert(textStatus);
//			alert(error);
//		}
	}).done(function(respond){
//		alert(respond);
		var Rand=Math.floor((Math.random()*5)+10);
		if(!respond)  //compile success
			CallCheck(5,1,Rand);
		else{
			document.getElementById('Result').innerHTML=respond;
			cl.hide();
			$('#Finish1').show();
		}
	});
}

