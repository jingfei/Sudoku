#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

bool Check(){
	int n,i=0;
	while(scanf("%d",&n)!=EOF){
		++i;
		if(n<0 || n>9) return false;
	}
	if(i<81) return false;
	return true;
}

int main(int argc, char *argv[]){
	char str[30],ID[10];
	strcpy(ID,argv[1]);
	strcpy(str,"./tmpCode/"); strcat(str,ID); strcat(str,"/question");
	int Len=strlen(str);
	char tmp[40];
	strcpy(tmp,str);
	tmp[Len+2]=tmp[Len];
	for(int i=0; i<100; ++i){
		tmp[Len]=(char)(i/10+'0');
		tmp[Len+1]=(char)(i%10+'0');
		const char *temp=tmp;
		freopen(temp,"r",stdin);
		if(!Check()){
			printf("question%02d\n",i);
			break;
		}
	}
	return 0;
}
