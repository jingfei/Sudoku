#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "CheckSudoku.h"
using namespace std;

void CheckSudoku::Save(){
    for(int i=0; i<9; ++i)
        for(int j=0; j<9; ++j)
            Ans[i][j]=Q[i][j];
}

void CheckSudoku::Recur(int i,int j){
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

void CheckSudoku::ReadIn(){
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

/*no answer: 0, exactly one: 1, too much: 2*/
int CheckSudoku::Solve(){
    if(solvable){
        solvable=false;
        Recur(0,0);
    }
	if(!solvable) return 0;
	else if(!too_much) return 1;
	else return 2;
}

