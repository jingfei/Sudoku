#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include"Sudoku.h"
using namespace std;

int Sudoku::ReadIn(){
    anses[0] = 0;
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
        a[i][j] = 0;
        aa[i][j] = 0;
        }
    }
    cout<<"Enter a sudoku : "<<endl;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++)
        scanf("%d",&a[i][j]);
    }
}

int Sudoku::row_check(int row,int r){
    int j;
    for(j=0;j<9;j++){
        if(a[r][j] == row)
        return 0;
    }
    return 1;
}

int Sudoku::column_check(int column,int c){
    int i;
    for(i=0;i<9;i++){
        if(a[i][c] == column)
        return 0;
    }
    return 1;
}

int Sudoku::square_check(int square,int s,int ss){
    int x=s-(s%3),y=ss-(ss%3);
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++)
            if(a[x+i][y+j] == square)
            return 0;
    }
    return 1;
}

void Sudoku::SolveSudoku(){
    int i,j;
    int number = 0;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if (a[i][j] != 0)
                number++;
        }
    }
    if(number == 81){
        anses[0]++;
        if(anses[0] == 2){
        printf("2\n");
            return;
        }
        for(i=0;i<9;i++){
            for(j=0;j<9;j++)
            aa[i][j]=a[i][j];
        }
            return;
    }

    int input;

    for(i=0;i<9;i++){
        for(j=0;j<9;j++){

            if(a[i][j] == 0){
                for(input=1;input<=9;input++){
                      if(row_check(input,i) == 1 && column_check(input,j) == 1 && square_check(input,i,j) == 1){
                            a[i][j]=input;
                            SolveSudoku();
                            a[i][j] = 0;
                      }
                }
                return;
            }
        }
    }
}

void Sudoku::print_answer(){
    int i,j;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++)
        cout<<aa[i][j]<<" ";
        printf("\n");
    }
}

void Sudoku::Solve(){
SolveSudoku();
if(anses[0] == 0)
    cout<<"0"<<endl;
else if(anses[0] == 1){
    cout<<"1"<<endl;
    print_answer();
}
}

void Sudoku::GiveQuestion(){
int number_of_question = 10;
srand(time(NULL));
int n;
n = rand()%number_of_question;
switch(n){
case 0 :
    printf("0 3 0 0 0 0 0 0 0\n\
0 4 0 0 0 0 0 0 6\n\
0 0 2 8 0 0 0 0 0\n\
0 0 0 0 5 0 7 0 0\n\
0 0 0 0 0 0 8 2 0\n\
0 0 0 0 3 1 0 0 0\n\
0 0 0 0 0 0 0 5 4\n\
0 0 7 0 6 0 0 0 1\n\
0 0 8 0 0 0 0 0 0\n");//111
break;
case 1 :
    printf("0 0 0 0 0 0 0 0 0\n\
8 0 0 2 0 0 0 0 1\n\
0 9 0 0 0 0 0 7 0\n\
0 0 0 0 0 7 0 0 0\n\
0 0 2 0 5 0 0 0 8\n\
4 0 0 0 0 0 2 0 6\n\
0 0 0 8 0 9 4 0 0\n\
0 5 7 0 6 0 0 0 0\n\
0 0 0 0 0 0 0 0 0\n");//236
break;
case 2 :
    printf("0 0 7 0 0 0 0 0 8\n\
0 0 0 0 6 4 0 0 0\n\
0 5 0 0 9 0 0 0 0\n\
0 0 0 0 0 0 0 0 0\n\
8 0 2 5 0 0 0 0 0\n\
0 0 0 0 0 1 6 4 0\n\
0 1 0 0 0 0 0 0 0\n\
4 6 0 0 0 0 0 0 0\n\
0 0 0 0 0 0 0 3 2\n");//83
break;
case 3 :
    printf("0 0 0 0 3 0 0 0 0\n\
0 0 0 0 8 5 0 0 0\n\
0 7 0 0 0 0 0 0 4\n\
0 0 0 0 0 0 0 0 6\n\
0 0 3 0 9 0 0 0 0\n\
0 6 0 0 0 0 0 7 1\n\
0 0 0 0 0 0 8 0 0\n\
0 1 0 6 0 0 0 0 0\n\
0 0 5 9 0 0 3 0 0\n");//120
break;
case 4 :
    printf("2 0 5 0 0 0 0 0 0\n\
0 0 0 0 0 0 0 0 6\n\
0 0 1 0 0 0 0 0 0\n\
0 0 0 0 0 5 0 0 0\n\
0 0 9 0 0 2 0 4 0\n\
0 7 0 0 0 0 0 0 8\n\
0 6 0 0 8 0 0 0 0\n\
0 0 0 0 0 0 5 0 1\n\
0 4 0 0 7 0 0 9 0\n");//147
break;
case 5 :
    printf("0 0 0 8 0 0 0 0 1\n\
0 0 0 0 0 4 9 0 0\n\
0 0 0 2 0 0 0 0 0\n\
2 3 0 0 0 0 0 4 0\n\
0 0 0 0 0 5 6 0 0\n\
8 0 0 0 0 0 0 0 0\n\
0 1 0 0 0 9 0 0 0\n\
0 0 0 0 0 0 0 3 2\n\
0 0 0 0 0 0 7 8 0\n");//68
break;
case 6 :
    printf("0 0 0 0 0 0 0 0 0\n\
0 0 1 0 0 4 0 8 0\n\
0 0 0 0 0 0 0 7 3\n\
0 0 0 0 3 0 0 0 0\n\
0 0 9 0 0 0 4 0 0\n\
0 0 8 6 0 0 0 0 2\n\
3 0 0 0 0 0 0 5 0\n\
2 0 0 0 0 0 0 0 0\n\
0 7 0 0 0 9 8 0 0\n");//288
break;
case 7 :
    printf("0 0 0 0 0 0 0 0 0\n\
0 0 0 0 0 6 7 0 0\n\
9 0 0 2 0 0 0 0 0\n\
1 0 0 0 4 0 0 0 0\n\
0 0 0 0 0 7 3 0 0\n\
5 0 2 0 0 3 6 0 0\n\
0 0 6 0 0 0 0 0 0\n\
0 0 0 0 9 0 0 5 1\n\
0 0 0 0 0 0 0 0 9\n");//139
break;
case 8 :
    printf("0 0 0 0 0 0 0 0 0\n\
2 0 0 0 0 0 0 0 0\n\
0 0 5 4 0 0 0 0 3\n\
0 0 0 0 0 0 0 0 6\n\
4 1 0 0 0 0 0 0 9\n\
8 0 0 0 5 2 0 0 0\n\
0 3 0 9 0 0 0 0 0\n\
0 0 0 0 0 0 0 8 0\n\
0 0 7 0 6 0 0 2 0\n");//540

break;
case 9 :
    printf("0 0 7 0 0 0 0 0 0\n\
0 0 0 0 0 3 0 8 0\n\
0 0 0 0 0 1 0 0 4\n\
0 4 0 0 9 0 0 0 0\n\
0 0 0 0 7 0 0 5 0\n\
2 3 0 0 0 0 0 0 0\n\
0 0 0 0 8 0 0 0 7\n\
0 0 0 0 0 0 4 0 9\n\
0 1 0 0 0 0 6 0 0\n");//69
break;
}
}
