#include <iostream>
#include <cstring>
#include <cstdio>
#include "CheckSudoku.h"
using namespace std;

bool Check(){
	int n,i=0,Count;
	while( (Count = scanf("%d",&n) )!=EOF){
		if(Count==0) return false;
		++i;
		if(!(n>=0 && n<=9)) return false;
	}
	if(i<81) return false;
	return true;
}

bool Check2(){
	CheckSudoku CS;
	CS.ReadIn();
	if(CS.Solve()==1) return true;
	return false;
}

int main(int argc, char *argv[]){
	char str[30],ID[10];
	strcpy(ID,argv[1]);
	strcpy(str,"./tmpCode/"); strcat(str,ID); strcat(str,"/question");
	int Len=strlen(str);
	char tmp[40];
	strcpy(tmp,str);
	tmp[Len+2]=tmp[Len];
//	for(int i=0; i<10; ++i){
	int i=0;
		tmp[Len]=(char)(i/10+'0');
		tmp[Len+1]=(char)(i%10+'0');
		const char *temp=tmp;
		freopen(temp,"r",stdin);
		if(!Check()){
			printf("question%02d\n",i);
//			break;
		}
		else{
			freopen(temp,"r",stdin);
			if(!Check2()){
				printf("question%02d\n",i);
//				break;
			}
		}
//	}
	return 0;
}
