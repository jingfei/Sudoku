#include <iostream>
#include <cstring>
#include <cstdio>
#include "Sudoku.h"
using namespace std;

int main(int argc, char *argv[]){
	char str[30],Correct[40],ID[10];
	Sudoku ss;
	strcpy(ID,argv[1]);
	strcpy(str,"./outputs/question"); strcat(str,argv[2]);
	strcpy(Correct,"./tmpCode/"); strcat(Correct,ID); strcat(Correct,"/Correct");
	printf("%s\n%s\n",str,Correct);
	freopen(str,"r",stdin);
	ss.ReadIn();
	/* solve question */
	freopen(Correct,"w",stdout);
	ss.Solve();
	/******************/
	return 0;
}
