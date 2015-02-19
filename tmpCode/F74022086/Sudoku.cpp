#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "Sudoku.h"
#include "Clock.h"
#include <ctime>

using namespace std;

/* a sudoku board is born and initialized */
Sudoku::Sudoku() {
	for(int i=0;i<9;i++) for(int j=0;j<9;j++) {Ans[i][j]=Board[i][j]=0;}
	Solved=0;
}

void Sudoku::GiveQuestion(){
	int i, j, Dice;
	int Template[6][9][9] = {
		{
			{0,0,0,7,0,8,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{6,0,0,0,3,0,0,0,8},
			{0,0,0,1,0,4,0,0,0},
			{5,0,0,0,2,0,0,0,7},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,5,0,6,0,0,0} },
		{
			{0,0,0,1,0,0,0,0,0},
			{0,0,0,2,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,2,1},
			{0,0,0,0,0,0,0,0,0},
			{1,2,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,2,0,0,0},
			{0,0,0,0,0,1,0,0,0} },
		{
			{0,0,0,1,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,1},
			{0,0,0,0,9,0,0,0,0},
			{1,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,0,0,0,0},
			{0,0,0,0,0,1,0,0,0} },
		{
			{5,0,0,0,0,0,0,0,9},
			{0,2,0,1,0,0,0,7,0},
			{0,0,8,0,0,0,3,0,0},
			{0,4,0,0,0,4,0,0,0},
			{0,0,0,0,5,0,0,0,0},
			{0,0,0,7,0,6,0,1,0},
			{0,0,3,0,0,0,8,0,0},
			{0,6,0,0,0,4,0,2,0},
			{9,0,0,0,0,0,0,0,5} },
		{
			{5,0,0,0,0,0,0,0,9},
			{0,2,0,1,0,0,0,7,0},
			{0,0,8,0,0,0,3,0,0},
			{0,4,0,0,0,2,0,0,0},
			{0,0,0,0,5,0,0,0,0},
			{0,0,0,7,0,6,0,1,0},
			{0,0,3,0,0,0,8,0,0},
			{0,6,0,0,0,4,0,2,0},
			{9,0,0,0,0,0,0,0,5} },
		{
			{5,0,0,0,0,0,0,0,9},
			{0,2,0,1,0,0,0,7,0},
			{0,0,8,0,0,0,3,0,0},
			{0,4,0,7,0,2,0,0,0},
			{0,0,0,0,5,0,0,0,0},
			{0,0,0,0,0,6,0,1,0},
			{0,0,3,0,0,0,8,0,0},
			{0,6,0,0,0,4,0,2,0},
			{9,0,0,0,0,0,0,0,5} } };

	srand(time(0));
	Dice = rand()%6;
	for(i=0;i<9;i++) for(j=0;j<9;j++) Board[i][j] = Template[Dice][i][j];
	Output();
}
	
/* output the sudoku board to stdout */
void Sudoku::Output() {
	int i, j;
	for(i=0;i<9;i++) {
		cout << Board[i][0];
		for(j=1;j<9;j++) cout << " " << Board[i][j]; 
		cout << endl;
	}
	cout << endl;
}

/* Heuristics: Fewer-Option First, Hard-First or Easy-Last Policy */
void Sudoku::Heuristics( ) {
	int i, j, k, h, n;

	// Collecting the blank cells with all possible digits
	N=0;
	for(i=0;i<9;i++) for(j=0;j<9;j++) if(!Board[i][j]){ I[N]=i; J[N++]=j; }

	// Checking and cancel the impossible digits
	for(k=0; k<N; k++){
		i=I[k]; j=J[k];
		for(h=1; h<=9; h++) Available[i][j][h]=1;
		for(h=0; h<9; h++) Available[i][j][Board[i][h]]=0;
		for(h=0; h<9; h++) Available[i][j][Board[h][j]]=0;
		for(h=0; h<3; h++) for(n=0; n<3; n++)
			Available[i][j][Board[(i/3)*3+h][(j/3)*3+n]]=0;
		Available[i][j][0]=0;
		for(h=1; h<=9; h++) Available[i][j][0] += Available[i][j][h];		
	}

	QuickSort(0, N-1);
}
	/* Unique-First Policy: Sorting the heuristics (Optioin Count) */
void Sudoku::QuickSort(int a, int z) {
	if(a<z) {
		int s=Split(a, z);
		QuickSort(a, s-1);
		QuickSort(s+1,z);
	}
}

/* Pivot-Spliting for Quick Sorting */
int Sudoku::Split(int a, int z) {
	int Ip=I[a], Jp=J[a], Pivot=Available[I[a]][J[a]][0];
	for(;;) {
		while(a < z && Pivot <= Available[I[z]][J[z]][0]) z--;
		if (a >= z) break;
		I[a] = I[z]; J[a]=J[z]; a++;
		while (a < z && Available[I[a]][J[a]][0] <= Pivot) a++;
		if(a >= z) break;
		I[z] = I[a]; J[z] = J[a]; z--; 
	}
	I[z] = Ip; J[z]=Jp;		
	return z;
}

/* Read a sudoku from stdin */
int Sudoku::ReadIn() {
	int i, j;
	cout << "Input a Sudoku board with 9x9 entries:\n";
	for(i=0; i<9; i++) for(j=0; j<9; j++) cin >> Board[i][j];
	return 1;
}

/* Read a sudoku from file, say, question.txt */
int Sudoku::ReadIn(char FileName[]) {
	int i, j;
	ifstream inFile(FileName, ios::in);
	if(!inFile) {cerr << "Failed opening inFile" << endl; return 0;}
	for(i=0; i<9; i++) for(j=0; j<9; j++) inFile >> Board[i][j];
	return 1;
}

/* Solve a sudoku from file question.txt */

int Sudoku::Solve() {
	int i, j, S;

	S=Solve1();
	cout << S << endl;
	if(S==1) {for(i=0;i<9;i++) for(j=0;j<9;j++) Board[i][j] = Ans[i][j]; Output();}
	return S;
}

int Sudoku::Solve1() {
	int i, j, k, So, S=0;
	Heuristics( );
	if(N==0) {
		if(!Solved) for(i=0;i<9;i++) for(j=0;j<9;j++) Ans[i][j] = Board[i][j];
		Solved=1;
		return 1;
	}
	i=I[0]; j=J[0];
	if(Available[i][j][0]==0) return 0;
	for(k=1; k<=9; k++){
		if(Available[i][j][k]==0) continue;
		Board[i][j]=k;
		So=Solve1();
		S += So;
		if(S>1) break;
	}
	if(S==0) {Board[i][j]=0; return 0;}
	else if(S>1) return 2;
	else {Board[i][j]=0; return 1;}
}
