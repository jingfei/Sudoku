#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cstdio>
#include<fstream>
#include"Sudoku.h"
using namespace std;
int Sudoku::ReadIn(){
    anscount=0;
    int i,j,n;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
        	temp[i][j]=0;
        	answer[i][j]=0;
        }
    }
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
        	cin>>n;
        	temp[i][j]=n;
        }
    }
}
int Sudoku::rcheck(int fill,int r){
    int j;
    for(j=0;j<9;j++){
        if(temp[r][j]==fill)
        return 0;
    }
    return 1;
}
int Sudoku::ccheck(int fill,int c){
    int i;
    for(i=0;i<9;i++){
        if(temp[i][c]==fill)
        return 0;
    }
    return 1;
}
int Sudoku::scheck(int fill,int m,int n){
	int i,j,x=m-(m%3),y=n-(n%3);
    for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            if(temp[x+i][y+j]==fill)
            return 0;
    }
    return 1;
}
void Sudoku::Solve2(){
    int i,j,k;
    int fill=0;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(temp[i][j]!=0)
                fill++;
        }
    }
    if(fill==81){
        anscount++;
        for(i=0;i<9;i++){
            for(j=0;j<9;j++)
            	answer[i][j]=temp[i][j];
        }
        return;
    }
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(temp[i][j]==0){
                for(k=1;k<=9;k++){
                      if(rcheck(k,i)==1&&ccheck(k,j)==1&&scheck(k,i,j)==1){
                            temp[i][j]=k;
                            Solve2();
                            temp[i][j] = 0;
                      }
                }
                return;
            }
        }
    }
}
void Sudoku::answers(){
	int i,j;
	if(anscount == 0)
    	cout<<"0"<<endl;
	else if(anscount == 1){
		cout<<"1"<<endl;
		for(i=0;i<9;i++){
        	for(j=0;j<9;j++)
        		cout<<answer[i][j]<<" ";
        		printf("\n");
    	}
	}
	else if(anscount >= 2)
    	cout<<"2"<<endl;
}
void Sudoku::Solve(){
	Solve2();
	answers();
}
void Sudoku::GiveQuestion(){
	srand(time(NULL));
	int i=10,j;
	j=rand()%i+1;
	if(j==1){
		printf("0 1 0 0 0 0 0 5 0\n8 0 0 7 2 0 0 0 0\n0 0 0 0 0 0 0 6 0\n0 0 0 0 0 5 0 9 0\n7 0 0 0 0 0 0 0 3\n0 0 0 0 0 0 0 0 2\n0 0 0 8 0 0 0 0 7\n0 6 0 0 0 0 0 0 0\n0 5 0 0 0 9 0 1 0\n");
	}
	if(j==2){
		printf("5 0 6 0 0 0 0 0 0\n0 2 0 0 0 9 0 0 0\n0 0 0 7 0 0 0 0 1\n0 0 0 0 0 0 0 1 7\n0 0 0 0 0 0 0 0 8\n0 0 0 0 5 2 0 0 0\n0 0 8 0 0 0 0 0 0\n0 0 1 0 0 0 3 0 0\n0 0 0 0 4 0 2 9 0\n");
	}
	if(j==3){
		printf("5 0 0 0 0 0 0 0 0\n0 0 3 0 4 0 0 0 0\n0 0 0 8 0 0 0 6 0\n0 0 0 0 5 3 0 0 0\n0 6 0 0 0 0 0 0 0\n1 8 0 0 0 0 0 7 0\n0 0 0 1 0 0 0 0 0\n0 7 0 0 0 0 0 0 5\n0 0 2 0 0 0 3 0 4\n");
	}
	if(j==4){
		printf("0 0 1 0 0 0 9 8 0\n7 0 0 0 0 0 0 0 0\n0 0 0 0 2 0 1 0 0\n6 0 0 8 0 0 0 0 0\n0 0 0 9 0 0 0 0 0\n4 0 0 0 0 0 0 0 3\n0 0 8 0 0 0 0 0 0\n0 0 9 0 3 5 0 0 0\n0 0 0 0 4 0 0 0 6\n");
	}
	if(j==5){
		printf("0 0 0 0 7 0 8 4 0\n0 0 0 0 0 0 0 0 0\n6 5 0 8 0 0 0 0 0\n2 0 0 0 0 5 0 0 0\n0 0 0 0 0 0 0 0 0\n0 0 7 0 0 0 3 0 0\n0 0 4 1 3 0 0 0 0\n0 0 0 0 0 0 0 2 0\n1 0 0 0 0 0 0 5 6\n");
	}
	if(j==6){
		printf("0 0 5 0 0 0 0 0 0\n6 0 1 0 0 3 0 0 0\n0 0 0 7 0 0 0 2 0\n8 0 0 0 0 0 0 0 0\n0 4 0 2 9 0 0 0 0\n0 0 0 0 0 0 1 0 5\n0 0 0 0 0 0 0 0 0\n0 2 0 0 0 0 0 9 0\n0 0 0 0 0 1 0 8 6\n");
	}
	if(j==7){
		printf("0 1 0 6 0 0 0 0 0\n0 0 0 0 7 0 0 0 4\n9 0 0 0 0 0 2 0 0\n0 0 0 8 0 4 0 9 0\n0 7 2 0 0 0 0 0 0\n3 0 0 0 0 0 0 0 0\n0 0 0 0 0 9 0 0 0\n0 8 0 0 0 0 0 1 0\n0 0 0 0 3 2 0 0 0\n");
	}
	if(j==8){
		printf("0 0 0 0 0 6 0 0 0\n0 0 0 0 0 0 1 2 0\n8 7 0 3 0 0 0 0 0\n0 0 0 0 0 0 0 0 5\n0 3 5 0 0 0 6 0 0\n0 0 0 7 0 8 0 0 0\n4 0 2 0 9 0 0 0 0\n0 0 0 0 0 0 0 0 7\n0 0 1 0 0 0 0 0 0\n");
	}
	if(j==9){
		printf("0 0 0 5 1 0 0 0 3\n0 0 0 2 0 0 0 0 0\n4 9 0 0 0 0 8 0 0\n0 7 0 0 0 0 0 0 0\n8 0 0 0 0 0 0 0 0\n0 0 0 1 0 0 0 2 0\n3 2 0 0 0 4 0 0 0\n0 0 0 0 0 0 0 0 6\n0 0 5 0 0 0 1 0 0\n");
	}
	if(j==10){
		printf("0 0 0 1 2 0 0 0 0\n0 0 7 0 0 0 0 0 5\n0 0 0 4 0 0 0 6 0\n0 0 0 0 0 6 0 0 8\n0 4 0 0 0 0 1 0 0\n0 0 0 0 0 5 0 0 0\n5 0 0 0 0 0 0 0 0\n8 0 6 0 0 0 0 7 0\n0 0 0 9 0 0 2 0 0\n");
	}
}