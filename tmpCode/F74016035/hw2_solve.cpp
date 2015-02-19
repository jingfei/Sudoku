#include <iostream>
#include <cstring>
#include <ctime>
#include <cstdio>
#include "Sudoku.h"
#include "Clock.h"
using namespace std;

int main(int argc, char *argv[]){
	/*file path string*/
	char str[30],ID[10],output[40],fTime[40];
	strcpy(ID,argv[1]);
	strcpy(str,"./tmpCode/"); strcat(str,ID); strcat(str,"/question");
	int Len=strlen(str);
	strcpy(output,"./tmpCode/"); strcat(output,ID); strcat(output,"/output");
	strcpy(fTime,"./tmpCode/"); strcat(fTime,ID); strcat(fTime,"/Time");
	/******************/
	Sudoku ss;
	Clock clk;
	double Time;
	char tmp[40];
	strcpy(tmp,str);
	tmp[Len+2]=tmp[Len];
	/* one question */
	clk.start();
	tmp[Len]='0';
	tmp[Len+1]='0';
	const char *temp=tmp;
	freopen(temp,"r",stdin);
	freopen(output,"w",stdout);
	ss.ReadIn();
	ss.Solve();
	Time=clk.getElapsedTime();
	/****************/
	/* ten question */
	if(Time==0){
		clk.start();
		for(int i=0; i<10; ++i){
			tmp[Len]=(char)(i/10+'0');
			tmp[Len+1]=(char)(i%10+'0');
			const char *temp=tmp;
			freopen(temp,"r",stdin);
			ss.ReadIn();
			ss.Solve();
		}
		Time=clk.getElapsedTime()/10.0;
	}
	/****************/
	/* 100 question */
	if(Time==0){
		clk.start();
		for(int i=0; i<100; ++i){
			tmp[Len]=(char)(i/10+'0');
			tmp[Len+1]=(char)(i%10+'0');
			const char *temp=tmp;
			freopen(temp,"r",stdin);
			ss.ReadIn();
			ss.Solve();
		}
		Time=clk.getElapsedTime()/100.0;
	}
	/****************/
	freopen(fTime,"w",stdout);
	printf("%f\n",Time);
	return 0;
}
