#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Sudoku.h"
using namespace std;

void Sudoku::GiveQuestion(){
	int Q1[9][9]={
	{5,3,0,0,7,0,0,0,0},
	{6,0,0,1,9,5,0,0,0},
	{0,9,8,0,0,0,0,6,0},
	{8,0,0,0,6,0,0,0,3},
	{4,0,0,8,0,3,0,0,1},
	{7,0,0,0,2,0,0,0,6},
	{0,6,0,0,0,0,2,8,0},
	{0,0,0,4,1,9,0,0,5},
	{0,0,0,0,8,0,0,7,9}};
	int Q2[9][9]={
	{0,6,0,1,0,4,0,5,0},
	{0,0,8,3,0,5,6,0,0},
	{2,0,0,0,0,0,0,0,1},
	{8,0,0,4,0,7,0,0,6},
	{0,0,6,0,0,0,3,0,0},
	{7,0,0,9,0,1,0,0,4},
	{5,0,0,0,0,0,0,0,2},
	{0,0,7,2,0,6,9,0,0},
	{0,4,0,5,0,8,0,7,0}};	
	srand(time(NULL));
	int r=rand()%2;
	if(r==0)
		for(int i=0; i<9; ++i){
			for(int j=0; j<9; ++j)
				printf("%d ",Q1[i][j]);
			printf("\n");
		}
	else
		for(int i=0; i<9; ++i){
			for(int j=0; j<9; ++j)
				printf("%d ",Q2[i][j]);
			printf("\n");
		}
}

void Sudoku::Save(){
	for(int i=0; i<9; ++i)
		for(int j=0; j<9; ++j)
			Ans[i][j]=Q[i][j];
}

void Sudoku::Print(){
	if(!solvable) printf("0\n");
	else if(!too_much){
		printf("1\n");
		for(int i=0; i<9; ++i){
			for(int j=0; j<9; ++j)
				printf("%d ",Ans[i][j]);
			printf("\n");
		}
	}
	else printf("2\n");
}

void Sudoku::Recur(int i,int j){
	if(too_much) return;
	if(j==9){++i;j=0;}
	if(i==9){
		if(!solvable) solvable=true;
		else{ too_much=true; return; }
		Save(); 
		return;
	}	
	if(Q[i][j])Recur(i,j+1);
	for(int k=1; k<=9; ++k)
		if(!Q[i][j] && !mx[i][k] && !my[j][k] && !mg[i/3][j/3][k]){
			Q[i][j]=k;
			mx[i][k]=my[j][k]=mg[i/3][j/3][k]=true;
			Recur(i,j+1);
			Q[i][j]=0;
			mx[i][k]=my[j][k]=mg[i/3][j/3][k]=false;
		}
}

void Sudoku::ReadIn(){
	memset(mx,false,sizeof(mx));
	memset(my,false,sizeof(my));
	memset(mg,false,sizeof(mg));
	solvable=true; too_much=false;
	for(int i=0; i<9; ++i)
		for(int j=0; j<9; ++j){
			scanf("%d",&Q[i][j]);
			int tmp=Q[i][j];
			if(mx[i][tmp] || my[j][tmp] || mg[i/3][j/3][tmp]) 
				solvable=false;
			if(tmp)
				mx[i][tmp]=my[j][tmp]=mg[i/3][j/3][tmp]=true;
		}
}

void Sudoku::Solve(){
	if(solvable){
		solvable=false;
		Recur(0,0);
	}
	Print();
}
