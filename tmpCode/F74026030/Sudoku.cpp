#include "Sudoku.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
#define amounts 7
Sudoku::Sudoku(){
	srand(time(NULL));
};
void Sudoku::GiveQuestion(){
	//srand(time(NULL));
	int Q[amounts][9][9]={
	{
	{0,0,6,7,0,0,4,0,0},
	{0,0,0,0,0,0,3,1,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,8,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,6},
	{1,4,0,0,0,0,0,0,0},
	{0,0,2,0,9,0,0,0,5},
	{0,0,0,0,0,4,0,0,0},
	{0,9,0,0,1,3,0,0,7}},
	{
	{0,0,8,4,0,7,0,0,0},
	{0,5,0,0,9,0,0,0,8},
	{0,0,9,0,0,0,0,5,0},
	{0,6,0,0,0,5,0,0,9},
	{0,0,0,0,1,0,0,2,8},
	{8,0,0,9,0,0,0,2,0},
	{0,1,0,0,0,0,7,0,0},
	{7,0,0,0,5,0,0,1,0},
	{0,0,0,2,0,3,9,0,0}},
	{
	{8,6,0,0,2,0,0,0,0},
	{0,0,0,7,0,0,0,5,9},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,6,0,8,0,0},
	{0,4,0,0,0,0,0,0,0},
	{0,0,5,3,0,0,0,0,7},
	{0,0,0,0,0,0,0,0,0},
	{0,2,0,0,0,0,6,0,0},
	{0,0,7,5,0,9,0,0,0}},
	{
	{0,0,4,0,0,1,0,0,0},
	{0,0,0,0,0,0,9,0,0},
	{0,3,0,0,0,0,0,0,0},
	{0,0,0,3,9,0,0,5,0},
	{0,0,7,0,0,0,0,0,2},
	{0,0,0,0,8,0,0,0,0},
	{9,0,5,0,0,6,0,0,0},
	{0,0,0,0,0,7,0,4,1},
	{0,8,0,0,0,0,0,0,0}},
	{
	{4,0,0,0,0,3,0,0,0},
	{0,6,0,0,0,0,0,9,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,3},
	{0,5,0,6,8,0,0,0,0},
	{0,0,8,0,0,2,0,0,1},
	{0,0,0,0,0,0,0,0,2},
	{0,0,0,0,0,0,6,5,0},
	{3,0,1,0,0,4,0,0,0}},
	{
	{0,0,0,0,0,1,0,0,0},
	{0,0,0,0,0,5,0,0,3},
	{0,0,2,0,0,0,0,7,0},
	{1,0,0,0,0,0,0,0,0},
	{8,5,0,0,0,0,0,0,0},
	{0,4,0,0,6,0,0,9,0},
	{0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,5,0,8},
	{0,0,3,0,9,0,2,0,0}},
	{
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0},
	{1,0,0,2,0,0,0,0,0},
	{2,0,0,1,0,0,0,0,0},
	{0,0,0,0,0,0,3,4,0}}
	};
	int hello = rand();
	int random_num = hello%amounts;
	//cout << hello <<" ";
	for (int i=0; i<9; i++){
		for (int j=0; j<9; j++)
			cout << Q[random_num][i][j] << " ";
		cout << "\n";
		}
		
	
	
/*	srand(time(NULL));
	int a = rand();
	if (a % 2 == 1){
		for (int i=0; i<9; i++){
			for (int j=0; j<9; j++)
				cout << "0 ";
			cout << endl;
		}
	}
	else {
		
		for (int i=0; i<9; i++){
			for (int j=0; j<9
	int S[9][9];
	int cell[9]={1,2,3,4,5,6,7,8,9};
	srand(time(NULL));
	//int temp, t;
	for (int i=0; i<9; i++){
		int temp = rand()%9;
		int t = cell[i]; 
		cell[i] = cell[temp];
		cell[temp] = t;
	}
		
	for (int i=0; i<9; i++){
		printf ("%d", cell[i]);
	}

*/		
	/*int *a;
	*a = 1;
	*(a+1) =2;
	return a;*/
}
void Sudoku::ReadIn(){	
	for (int i=0; i<9; i++){
		for (int j=0; j<10; j++){
			row[i][j] = false;
			column[i][j] = false;
			if (j != 9 )
				changeable[i][j] = true;
		}
	}
	for (int i=0; i<3; i++){	
		for (int j=0; j<3; j++){
			for (int k=0; k<10; k++){
				region[i][j][k] = false;
				}
		}
	}
	no_answer = false;
	more_than_one = false;
	have_solved = false;
	change = false;
	for (int i=0; i<9; i++){
		for (int j=0; j<9; j++){
			scanf("%d", &Q[i][j]);
			A[i][j] = 0;
			int t = Q[i][j];
			
			
			
				if(t){
					if (row[i][t] || column[j][t] || region[i/3][j/3][t]){
						no_answer = true;
					}
					
					row[i][t] = column[j][t] = region[i/3][j/3][t] = true;
					changeable[i][j] = false;
				}
			
		}
	}
	
}
void Sudoku::Recur(int n, int m){
	if ( m == 9 ){
		m = 0;
		n = n + 1;
	}
	if ( n == 9 ){
		if (!have_solved){ 
			for(int i=0; i<9; ++i)
				for(int j=0; j<9; ++j)
					A[i][j]=Q[i][j];
			have_solved = true;
			change = true;
			return ;
		}
		else {
			more_than_one = true;
		}
	}
	if (!changeable[n][m])
		Recur(n, m+1);
	else{
		for (int i=1; i<=9; i++){
			if( !row[n][i] && !column[m][i] && !region[n/3][m/3][i] ){
				Q[n][m] = i;	
				row[n][i] = column[m][i] = region[n/3][m/3][i] = true;
				Recur(n,m+1);
				if(more_than_one)return;
				row[n][i] = column[m][i] = region[n/3][m/3][i] = false;
				Q[n][m] = 0;
			}
	}
	}
		
}
void Sudoku::Solve(){
	if (!no_answer){
		Recur(0, 0);
		if(more_than_one)
			cout<<"2\n";
		else {
	/*		bool except = false;
			for (int i=0; i<9; i++){
				for (int j=0; j<9; j++){
					if (A[i][j]>9||A[i][j]<1)
						except = true;	
				}
			}
			if (except)cout<<"0\n";*/
			if(!change)cout<<"0\n";
			else {
				cout<<"1\n";
				for (int i=0; i<9; i++){	
					for (int j=0; j<9; j++)
						cout << A[i][j] << " ";
					cout << endl;
				}
			}
		}
	}
	else {
		cout << "0\n";
	}
}