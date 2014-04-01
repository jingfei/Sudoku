#include <iostream>
#include <cstring>
#include <cstdio>
#include "Sudoku.h"
#include <unistd.h>
using namespace std;

int main(int argc, char *argv[]){
	usleep(1000000);
	char str[30],ID[10];
	strcpy(ID,argv[1]);
	strcpy(str,"./tmpCode/"); strcat(str,ID); strcat(str,"/question");
	int Len=strlen(str);
	Sudoku ss;
	char tmp[40];
	strcpy(tmp,str);
	tmp[Len+2]=tmp[Len];
//	for(int i=0; i<100; ++i){
	int i=0;
		tmp[Len]=(char)(i/10+'0');
		tmp[Len+1]=(char)(i%10+'0');
		const char *temp=tmp;
		freopen(temp,"w",stdout);
		ss.GiveQuestion();
//	}
	return 0;
}
