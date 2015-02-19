#include<iostream> 
#include<cstdlib> 
#include<time.h> 
#include<stdio.h>
#include"Sudoku.h"
using namespace std;

int sudo[9][9]={{0}};
int sudo2[9][9]={{0}};
int r=0;

void Sudoku::GiveQuestion()
                           {int numberQ=2;
srand(time(NULL));
int nQ;
nQ=rand()%numberQ;

switch(nQ){

case 0 :
    printf("0 0 7 0 0 0 0 0 8\n\
0 0 0 0 6 4 0 0 0\n\
0 5 0 0 9 0 0 0 0\n\
0 0 0 0 0 0 0 0 0\n\
8 0 2 5 0 0 0 0 0\n\
0 0 0 0 0 1 6 4 0\n\
0 1 0 0 0 0 0 0 0\n\
4 6 0 0 0 0 0 0 0\n\
0 0 0 0 0 0 0 3 2\n");
break;

case 1 :
    printf("2 0 5 0 0 0 0 0 0\n\
0 0 0 0 0 0 0 0 6\n\
0 0 1 0 0 0 0 0 0\n\
0 0 0 0 0 5 0 0 0\n\
0 0 9 0 0 2 0 4 0\n\
0 7 0 0 0 0 0 0 8\n\
0 6 0 0 8 0 0 0 0\n\
0 0 0 0 0 0 5 0 1\n\
0 4 0 0 7 0 0 9 0\n");
break;
}}

     
void Sudoku::ReadIn(){
                                         cout<<"輸入數獨題目第一列:";
                                         scanf("%d%d%d%d%d%d%d%d%d",&sudo[0][0],&sudo[0][1],&sudo[0][2],&sudo[0][3],&sudo[0][4],&sudo[0][5],&sudo[0][6],&sudo[0][7],&sudo[0][8]); 
                                         cout<<"輸入數獨題目第二列:";
                                         scanf("%d%d%d%d%d%d%d%d%d",&sudo[1][0],&sudo[1][1],&sudo[1][2],&sudo[1][3],&sudo[1][4],&sudo[1][5],&sudo[1][6],&sudo[1][7],&sudo[1][8]); 
                                         cout<<"輸入數獨題目第三列:";
                                         scanf("%d%d%d%d%d%d%d%d%d",&sudo[2][0],&sudo[2][1],&sudo[2][2],&sudo[2][3],&sudo[2][4],&sudo[2][5],&sudo[2][6],&sudo[2][7],&sudo[2][8]); 
                                         cout<<"輸入數獨題目第四列:";
                                         scanf("%d%d%d%d%d%d%d%d%d",&sudo[3][0],&sudo[3][1],&sudo[3][2],&sudo[3][3],&sudo[3][4],&sudo[3][5],&sudo[3][6],&sudo[3][7],&sudo[3][8]); 
                                         cout<<"輸入數獨題目第五列:";
                                         scanf("%d%d%d%d%d%d%d%d%d",&sudo[4][0],&sudo[4][1],&sudo[4][2],&sudo[4][3],&sudo[4][4],&sudo[4][5],&sudo[4][6],&sudo[4][7],&sudo[4][8]); 
                                         cout<<"輸入數獨題目第六列:";
                                         scanf("%d%d%d%d%d%d%d%d%d",&sudo[5][0],&sudo[5][1],&sudo[5][2],&sudo[5][3],&sudo[5][4],&sudo[5][5],&sudo[5][6],&sudo[5][7],&sudo[5][8]); 
                                         cout<<"輸入數獨題目第七列:";
                                         scanf("%d%d%d%d%d%d%d%d%d",&sudo[6][0],&sudo[6][1],&sudo[6][2],&sudo[6][3],&sudo[6][4],&sudo[6][5],&sudo[6][6],&sudo[6][7],&sudo[6][8]); 
                                         cout<<"輸入數獨題目第八列:";
                                         scanf("%d%d%d%d%d%d%d%d%d",&sudo[7][0],&sudo[7][1],&sudo[7][2],&sudo[7][3],&sudo[7][4],&sudo[7][5],&sudo[7][6],&sudo[7][7],&sudo[7][8]); 
                                         cout<<"輸入數獨題目第九列:";
                                         scanf("%d%d%d%d%d%d%d%d%d",&sudo[8][0],&sudo[8][1],&sudo[8][2],&sudo[8][3],&sudo[8][4],&sudo[8][5],&sudo[8][6],&sudo[8][7],&sudo[8][8]); 
                                         }
     
void Sudoku::Solve(){
                                        int p,q; 
                                                                                                     
                                        begin:                                                       //begin在此 
                                        int count[9][9]={{0}},number[9][9][9]={{{0}}};//初始化   count存可能的"次數" number存可能的"數字"
                                        
                                        for(p=0;p<9;p++){
                                                         for(q=0;q<9;q++){
                                                                          if(sudo[p][q]==0){
                                                                                            int ab[10]={0};
                                                                                            
                                                                                            
                                                                                            if(sudo[p][0]==1) ab[1]+=1;                                //測橫 
                                                                                            else if(sudo[p][0]==2) ab[2]+=1;
                                                                                            else if(sudo[p][0]==3) ab[3]+=1;
                                                                                            else if(sudo[p][0]==4) ab[4]+=1;
                                                                                            else if(sudo[p][0]==5) ab[5]+=1;
                                                                                            else if(sudo[p][0]==6) ab[6]+=1;
                                                                                            else if(sudo[p][0]==7) ab[7]+=1;
                                                                                            else if(sudo[p][0]==8) ab[8]+=1;
                                                                                            else if(sudo[p][0]==9) ab[9]+=1;
                  
                                                                                            if(sudo[p][1]==1) ab[1]+=1;
                                                                                            else if(sudo[p][1]==2) ab[2]+=1;
                                                                                            else if(sudo[p][1]==3) ab[3]+=1;
                                                                                            else if(sudo[p][1]==4) ab[4]+=1;
                                                                                            else if(sudo[p][1]==5) ab[5]+=1;
                                                                                            else if(sudo[p][1]==6) ab[6]+=1;
                                                                                            else if(sudo[p][1]==7) ab[7]+=1;
                                                                                            else if(sudo[p][1]==8) ab[8]+=1;
                                                                                            else if(sudo[p][1]==9) ab[9]+=1;
                  
                                                                                            if(sudo[p][2]==1) ab[1]+=1;
                                                                                            else if(sudo[p][2]==2) ab[2]+=1;
                                                                                            else if(sudo[p][2]==3) ab[3]+=1;
                                                                                            else if(sudo[p][2]==4) ab[4]+=1;
                                                                                            else if(sudo[p][2]==5) ab[5]+=1;
                                                                                            else if(sudo[p][2]==6) ab[6]+=1;
                                                                                            else if(sudo[p][2]==7) ab[7]+=1;
                                                                                            else if(sudo[p][2]==8) ab[8]+=1;
                                                                                            else if(sudo[p][2]==9) ab[9]+=1;
                  
                                                                                            if(sudo[p][3]==1) ab[1]+=1;
                                                                                            else if(sudo[p][3]==2) ab[2]+=1;
                                                                                            else if(sudo[p][3]==3) ab[3]+=1;
                                                                                            else if(sudo[p][3]==4) ab[4]+=1;
                                                                                            else if(sudo[p][3]==5) ab[5]+=1;
                                                                                            else if(sudo[p][3]==6) ab[6]+=1;
                                                                                            else if(sudo[p][3]==7) ab[7]+=1;
                                                                                            else if(sudo[p][3]==8) ab[8]+=1;
                                                                                            else if(sudo[p][3]==9) ab[9]+=1;
                  
                                                                                            if(sudo[p][4]==1) ab[1]+=1;
                                                                                            else if(sudo[p][4]==2) ab[2]+=1;
                                                                                            else if(sudo[p][4]==3) ab[3]+=1;
                                                                                            else if(sudo[p][4]==4) ab[4]+=1;
                                                                                            else if(sudo[p][4]==5) ab[5]+=1;
                                                                                            else if(sudo[p][4]==6) ab[6]+=1;
                                                                                            else if(sudo[p][4]==7) ab[7]+=1;
                                                                                            else if(sudo[p][4]==8) ab[8]+=1;
                                                                                            else if(sudo[p][4]==9) ab[9]+=1;
                  
                                                                                            if(sudo[p][5]==1) ab[1]+=1;
                                                                                            else if(sudo[p][5]==2) ab[2]+=1;
                                                                                            else if(sudo[p][5]==3) ab[3]+=1;
                                                                                            else if(sudo[p][5]==4) ab[4]+=1;
                                                                                            else if(sudo[p][5]==5) ab[5]+=1;
                                                                                            else if(sudo[p][5]==6) ab[6]+=1;
                                                                                            else if(sudo[p][5]==7) ab[7]+=1;
                                                                                            else if(sudo[p][5]==8) ab[8]+=1;
                                                                                            else if(sudo[p][5]==9) ab[9]+=1;
                  
                                                                                            if(sudo[p][6]==1) ab[1]+=1;
                                                                                            else if(sudo[p][6]==2) ab[2]+=1;
                                                                                            else if(sudo[p][6]==3) ab[3]+=1;
                                                                                            else if(sudo[p][6]==4) ab[4]+=1;
                                                                                            else if(sudo[p][6]==5) ab[5]+=1;
                                                                                            else if(sudo[p][6]==6) ab[6]+=1;
                                                                                            else if(sudo[p][6]==7) ab[7]+=1;
                                                                                            else if(sudo[p][6]==8) ab[8]+=1;
                                                                                            else if(sudo[p][6]==9) ab[9]+=1;
                  
                                                                                            if(sudo[p][7]==1) ab[1]+=1;
                                                                                            else if(sudo[p][7]==2) ab[2]+=1;
                                                                                            else if(sudo[p][7]==3) ab[3]+=1;
                                                                                            else if(sudo[p][7]==4) ab[4]+=1;
                                                                                            else if(sudo[p][7]==5) ab[5]+=1;
                                                                                            else if(sudo[p][7]==6) ab[6]+=1;
                                                                                            else if(sudo[p][7]==7) ab[7]+=1;
                                                                                            else if(sudo[p][7]==8) ab[8]+=1;
                                                                                            else if(sudo[p][7]==9) ab[9]+=1;
                  
                                                                                            if(sudo[p][8]==1) ab[1]+=1;
                                                                                            else if(sudo[p][8]==2) ab[2]+=1;
                                                                                            else if(sudo[p][8]==3) ab[3]+=1;
                                                                                            else if(sudo[p][8]==4) ab[4]+=1;
                                                                                            else if(sudo[p][8]==5) ab[5]+=1;
                                                                                            else if(sudo[p][8]==6) ab[6]+=1;
                                                                                            else if(sudo[p][8]==7) ab[7]+=1;
                                                                                            else if(sudo[p][8]==8) ab[8]+=1;
                                                                                            else if(sudo[p][8]==9) ab[9]+=1;
                  
/********************************************************************************************************************************************************************************************/            
                  
                  
                  
                                                                                            if(sudo[0][q]==1) ab[1]+=1;                                          //測列 
                                                                                            else if(sudo[0][q]==2) ab[2]+=1;
                                                                                            else if(sudo[0][q]==3) ab[3]+=1;
                                                                                            else if(sudo[0][q]==4) ab[4]+=1;
                                                                                            else if(sudo[0][q]==5) ab[5]+=1;
                                                                                            else if(sudo[0][q]==6) ab[6]+=1;
                                                                                            else if(sudo[0][q]==7) ab[7]+=1;
                                                                                            else if(sudo[0][q]==8) ab[8]+=1;
                                                                                            else if(sudo[0][q]==9) ab[9]+=1;
                  
                                                                                            if(sudo[1][q]==1) ab[1]+=1;
                                                                                            else if(sudo[1][q]==2) ab[2]+=1;
                                                                                            else if(sudo[1][q]==3) ab[3]+=1;
                                                                                            else if(sudo[1][q]==4) ab[4]+=1;
                                                                                            else if(sudo[1][q]==5) ab[5]+=1;
                                                                                            else if(sudo[1][q]==6) ab[6]+=1;
                                                                                            else if(sudo[1][q]==7) ab[7]+=1;
                                                                                            else if(sudo[1][q]==8) ab[8]+=1;
                                                                                            else if(sudo[1][q]==9) ab[9]+=1;
                  
                                                                                            if(sudo[2][q]==1) ab[1]+=1;
                                                                                            else if(sudo[2][q]==2) ab[2]+=1;
                                                                                            else if(sudo[2][q]==3) ab[3]+=1;
                                                                                            else if(sudo[2][q]==4) ab[4]+=1;
                                                                                            else if(sudo[2][q]==5) ab[5]+=1;
                                                                                            else if(sudo[2][q]==6) ab[6]+=1;
                                                                                            else if(sudo[2][q]==7) ab[7]+=1;
                                                                                            else if(sudo[2][q]==8) ab[8]+=1;
                                                                                            else if(sudo[2][q]==9) ab[9]+=1;
                  
                                                                                            if(sudo[3][q]==1) ab[1]+=1;
                                                                                            else if(sudo[3][q]==2) ab[2]+=1;
                                                                                            else if(sudo[3][q]==3) ab[3]+=1;
                                                                                            else if(sudo[3][q]==4) ab[4]+=1;
                                                                                            else if(sudo[3][q]==5) ab[5]+=1;
                                                                                            else if(sudo[3][q]==6) ab[6]+=1;
                                                                                            else if(sudo[3][q]==7) ab[7]+=1;
                                                                                            else if(sudo[3][q]==8) ab[8]+=1;
                                                                                            else if(sudo[3][q]==9) ab[9]+=1;
                  
                                                                                            if(sudo[4][q]==1) ab[1]+=1;
                                                                                            else if(sudo[4][q]==2) ab[2]+=1;
                                                                                            else if(sudo[4][q]==3) ab[3]+=1;
                                                                                            else if(sudo[4][q]==4) ab[4]+=1;
                                                                                            else if(sudo[4][q]==5) ab[5]+=1;
                                                                                            else if(sudo[4][q]==6) ab[6]+=1;
                                                                                            else if(sudo[4][q]==7) ab[7]+=1;
                                                                                            else if(sudo[4][q]==8) ab[8]+=1;
                                                                                            else if(sudo[4][q]==9) ab[9]+=1;
                  
                                                                                            if(sudo[5][q]==1) ab[1]+=1;
                                                                                            else if(sudo[5][q]==2) ab[2]+=1;
                                                                                            else if(sudo[5][q]==3) ab[3]+=1;
                                                                                            else if(sudo[5][q]==4) ab[4]+=1;
                                                                                            else if(sudo[5][q]==5) ab[5]+=1;
                                                                                            else if(sudo[5][q]==6) ab[6]+=1;
                                                                                            else if(sudo[5][q]==7) ab[7]+=1;
                                                                                            else if(sudo[5][q]==8) ab[8]+=1;
                                                                                            else if(sudo[5][q]==9) ab[9]+=1;
                  
                                                                                            if(sudo[6][q]==1) ab[1]+=1;
                                                                                            else if(sudo[6][q]==2) ab[2]+=1;
                                                                                            else if(sudo[6][q]==3) ab[3]+=1;
                                                                                            else if(sudo[6][q]==4) ab[4]+=1;
                                                                                            else if(sudo[6][q]==5) ab[5]+=1;
                                                                                            else if(sudo[6][q]==6) ab[6]+=1;
                                                                                            else if(sudo[6][q]==7) ab[7]+=1;
                                                                                            else if(sudo[6][q]==8) ab[8]+=1;
                                                                                            else if(sudo[6][q]==9) ab[9]+=1;
                  
                                                                                            if(sudo[7][q]==1) ab[1]+=1;
                                                                                            else if(sudo[7][q]==2) ab[2]+=1;
                                                                                            else if(sudo[7][q]==3) ab[3]+=1;
                                                                                            else if(sudo[7][q]==4) ab[4]+=1;
                                                                                            else if(sudo[7][q]==5) ab[5]+=1;
                                                                                            else if(sudo[7][q]==6) ab[6]+=1;
                                                                                            else if(sudo[7][q]==7) ab[7]+=1;
                                                                                            else if(sudo[7][q]==8) ab[8]+=1;
                                                                                            else if(sudo[7][q]==9) ab[9]+=1;
                  
                                                                                            if(sudo[8][q]==1) ab[1]+=1;
                                                                                            else if(sudo[8][q]==2) ab[2]+=1;
                                                                                            else if(sudo[8][q]==3) ab[3]+=1;
                                                                                            else if(sudo[8][q]==4) ab[4]+=1;
                                                                                            else if(sudo[8][q]==5) ab[5]+=1;
                                                                                            else if(sudo[8][q]==6) ab[6]+=1;
                                                                                            else if(sudo[8][q]==7) ab[7]+=1;
                                                                                            else if(sudo[8][q]==8) ab[8]+=1;
                                                                                            else if(sudo[8][q]==9) ab[9]+=1;
                  
/****************************************************************************************************************************************************************************************************/                  
                  
                                                                                            int p1,q1;                                                                             //測九宮格 
                                                                                            if(p<=2&&q<=2){
                                                                                                           for(p1=0;p1<=2;p1++){
                                                                                                                                for(q1=0;q1<=2;q1++){
                                                                                                                                                     if(sudo[p1][q1]==1) ab[1]+=1;
                                                                                                                                                     if(sudo[p1][q1]==2) ab[2]+=1;
                                                                                                                                                     if(sudo[p1][q1]==3) ab[3]+=1;
                                                                                                                                                     if(sudo[p1][q1]==4) ab[4]+=1;
                                                                                                                                                     if(sudo[p1][q1]==5) ab[5]+=1;
                                                                                                                                                     if(sudo[p1][q1]==6) ab[6]+=1;
                                                                                                                                                     if(sudo[p1][q1]==7) ab[7]+=1;
                                                                                                                                                     if(sudo[p1][q1]==8) ab[8]+=1;
                                                                                                                                                     if(sudo[p1][q1]==9) ab[9]+=1;
                                                                                                                                                     }
                                                                                                                                }
                                                                                                           }
                  
                                                                                            else if(p>=3&&p<=5&&q<=2){
                                                                                                                      for(p1=3;p1<=5;p1++){
                                                                                                                                           for(q1=0;q1<=2;q1++){
                                                                                                                                                                if(sudo[p1][q1]==1) ab[1]+=1;
                                                                                                                                                                if(sudo[p1][q1]==2) ab[2]+=1;
                                                                                                                                                                if(sudo[p1][q1]==3) ab[3]+=1;
                                                                                                                                                                if(sudo[p1][q1]==4) ab[4]+=1;
                                                                                                                                                                if(sudo[p1][q1]==5) ab[5]+=1;
                                                                                                                                                                if(sudo[p1][q1]==6) ab[6]+=1;
                                                                                                                                                                if(sudo[p1][q1]==7) ab[7]+=1;
                                                                                                                                                                if(sudo[p1][q1]==8) ab[8]+=1;
                                                                                                                                                                if(sudo[p1][q1]==9) ab[9]+=1;
                                                                                                                                                                }
                                                                                                                                           }
                                                                                                                      }
                  
                                                                                           else if(p>=6&&p<=8&&q<=2){
                                                                                                                     for(p1=6;p1<=8;p1++){
                                                                                                                                          for(q1=0;q1<=2;q1++){
                                                                                                                                                               if(sudo[p1][q1]==1) ab[1]+=1;
                                                                                                                                                               if(sudo[p1][q1]==2) ab[2]+=1;
                                                                                                                                                               if(sudo[p1][q1]==3) ab[3]+=1;
                                                                                                                                                               if(sudo[p1][q1]==4) ab[4]+=1;
                                                                                                                                                               if(sudo[p1][q1]==5) ab[5]+=1;
                                                                                                                                                               if(sudo[p1][q1]==6) ab[6]+=1;
                                                                                                                                                               if(sudo[p1][q1]==7) ab[7]+=1;
                                                                                                                                                               if(sudo[p1][q1]==8) ab[8]+=1;
                                                                                                                                                               if(sudo[p1][q1]==9) ab[9]+=1;
                                                                                                                                                               }
                                                                                                                                          }
                                                                                                                     }
                  
                                                                                          else if(p<=2&&q>=3&&q<=5){
                                                                                                                    for(p1=0;p1<=2;p1++){
                                                                                                                                         for(q1=3;q1<=5;q1++){
                                                                                                                                                              if(sudo[p1][q1]==1) ab[1]+=1;
                                                                                                                                                              if(sudo[p1][q1]==2) ab[2]+=1;
                                                                                                                                                              if(sudo[p1][q1]==3) ab[3]+=1;
                                                                                                                                                              if(sudo[p1][q1]==4) ab[4]+=1;
                                                                                                                                                              if(sudo[p1][q1]==5) ab[5]+=1;
                                                                                                                                                              if(sudo[p1][q1]==6) ab[6]+=1;
                                                                                                                                                              if(sudo[p1][q1]==7) ab[7]+=1;
                                                                                                                                                              if(sudo[p1][q1]==8) ab[8]+=1;
                                                                                                                                                              if(sudo[p1][q1]==9) ab[9]+=1;
                                                                                                                                                              }
                                                                                                                                         }
                                                                                                                    }
                  
                                                                                          else if(p>=3&&p<=5&&q>=3&&q<=5){
                                                                                                                          for(p1=3;p1<=5;p1++){
                                                                                                                                               for(q1=3;q1<=5;q1++){
                                                                                                                                                                    if(sudo[p1][q1]==1) ab[1]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==2) ab[2]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==3) ab[3]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==4) ab[4]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==5) ab[5]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==6) ab[6]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==7) ab[7]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==8) ab[8]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==9) ab[9]+=1;
                                                                                                                                                                    }
                                                                                                                                               }
                                                                                                                          }
                  
                                                                                          else if(p>=6&&p<=8&&q>=3&&q<=5){
                                                                                                                          for(p1=6;p1<=8;p1++){
                                                                                                                                               for(q1=3;q1<=5;q1++){
                                                                                                                                                                    if(sudo[p1][q1]==1) ab[1]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==2) ab[2]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==3) ab[3]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==4) ab[4]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==5) ab[5]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==6) ab[6]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==7) ab[7]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==8) ab[8]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==9) ab[9]+=1;
                                                                                                                                                                    }
                                                                                                                                               }
                                                                                                                          }
                  
                                                                                          else if(p<=2&&q>=6&&q<=8){
                                                                                                                    for(p1=0;p1<=2;p1++){
                                                                                                                                         for(q1=6;q1<=8;q1++){
                                                                                                                                                              if(sudo[p1][q1]==1) ab[1]+=1;
                                                                                                                                                              if(sudo[p1][q1]==2) ab[2]+=1;
                                                                                                                                                              if(sudo[p1][q1]==3) ab[3]+=1;
                                                                                                                                                              if(sudo[p1][q1]==4) ab[4]+=1;
                                                                                                                                                              if(sudo[p1][q1]==5) ab[5]+=1;
                                                                                                                                                              if(sudo[p1][q1]==6) ab[6]+=1;
                                                                                                                                                              if(sudo[p1][q1]==7) ab[7]+=1;
                                                                                                                                                              if(sudo[p1][q1]==8) ab[8]+=1;
                                                                                                                                                              if(sudo[p1][q1]==9) ab[9]+=1;
                                                                                                                                                              }
                                                                                                                                         }
                                                                                                                    }
                  
                                                                                          else if(p>=3&&p<=5&&q>=6&&q<=8){
                                                                                                                          for(p1=3;p1<=5;p1++){
                                                                                                                                               for(q1=6;q1<=8;q1++){
                                                                                                                                                                    if(sudo[p1][q1]==1) ab[1]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==2) ab[2]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==3) ab[3]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==4) ab[4]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==5) ab[5]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==6) ab[6]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==7) ab[7]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==8) ab[8]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==9) ab[9]+=1;
                                                                                                                                                                    }
                                                                                                                                               }
                                                                                                                          }
                  
                                                                                          else if(p>=6&&p<=8&&q>=6&&q<=8){
                                                                                                                          for(p1=6;p1<=8;p1++){
                                                                                                                                               for(q1=6;q1<=8;q1++){
                                                                                                                                                                    if(sudo[p1][q1]==1) ab[1]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==2) ab[2]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==3) ab[3]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==4) ab[4]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==5) ab[5]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==6) ab[6]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==7) ab[7]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==8) ab[8]+=1;
                                                                                                                                                                    if(sudo[p1][q1]==9) ab[9]+=1;
                                                                                                                                                                    }
                                                                                                                                               }
                                                                                                                          }
                                                                                          int xyz;
                                                                                          for(xyz=1;xyz<=9;xyz++){
                                                                                                                  if(ab[xyz]==0){count[p][q]+=1;
                                                                                                                                number[p][q][xyz]=xyz;
                                                                                                                                }
                                                                                                                  
                                                                                                                  }                                                
                                                                                           
                                                                                            }
                                                                        
                                                                          }
                                                        
                                                         }

                                 int xxxx,yyyy,aaaa,xxx1,yyy1,abcd;
                                 for(xxxx=0;xxxx<9;xxxx++){
                                                           for(yyyy=0;yyyy<9;yyyy++){
                                                                                     if(count[xxxx][yyyy]==1){
                                                                                                              int zzzz;
                                                                                                              for(zzzz=1;zzzz<=9;zzzz++) {
                                                                                                                                         if(number[xxxx][yyyy][zzzz]!=0) {
                                                                                                                                                                         sudo[xxxx][yyyy]=number[xxxx][yyyy][zzzz];
                                                                                                                                                                         abcd=zzzz;
                                                                                                                                                                         }
                                                                                                                                         }
                                                                                                              count[xxxx][yyyy]=0;
                                                                                                              number[xxxx][yyyy][zzzz]=0;
                                                                                     
                                                                                     
                                                                                     
                                                                                     for(aaaa=0;aaaa<9;aaaa++){
                                                                                                               if(number[xxxx][aaaa][abcd]!=0) {
                                                                                                                                               number[xxxx][aaaa][abcd]=0;
                                                                                                                                               count[xxxx][aaaa]-=1;
                                                                                                                                               }
                                                                                                               }
                                                                                                               
                                                                                                               
                                                                                     for(aaaa=0;aaaa<9;aaaa++){
                                                                                                               if(number[aaaa][yyyy][abcd]!=0){
                                                                                                                                               number[aaaa][yyyy][abcd]=0;
                                                                                                                                               count[aaaa][yyyy]-=1;
                                                                                                                                               }
                                                                                                               }
                                                                                     
                                                                                                               
                                                                                     
                                                                                     
                                                                                     if(xxxx<=2&&yyyy<=2){
                                                                                                           for(xxx1=0;xxx1<=2;xxx1++){
                                                                                                                                for(yyy1=0;yyy1<=2;yyy1++){
                                                                                                                                                     if(number[xxx1][yyy1][abcd]!=0){
                                                                                                                                                                                     number[xxx1][yyy1][abcd]=0;
                                                                                                                                                                                     count[xxx1][yyy1]-=1;
                                                                                                                                                                                     }
                                                                                                                                                     }
                                                                                                                                }                     
                                                                                                           }
                  
                                                                                     else if(xxxx>=3&&xxxx<=5&&yyyy<=2){
                                                                                                                      for(xxx1=3;xxx1<=5;xxx1++){
                                                                                                                                           for(yyy1=0;yyy1<=2;yyy1++){
                                                                                                                                                                if(number[xxx1][yyy1][abcd]!=0){
                                                                                                                                                                                     number[xxx1][yyy1][abcd]=0;
                                                                                                                                                                                     count[xxx1][yyy1]-=1;
                                                                                                                                                                                     }
                                                                                                                                                                }
                                                                                                                                           }
                                                                                                                      }
                  
                                                                                           else if(xxxx>=6&&xxxx<=8&&yyyy<=2){
                                                                                                                     for(xxx1=6;xxx1<=8;xxx1++){
                                                                                                                                          for(yyy1=0;yyy1<=2;yyy1++){
                                                                                                                                                               if(number[xxx1][yyy1][abcd]!=0){
                                                                                                                                                                                     number[xxx1][yyy1][abcd]=0;
                                                                                                                                                                                     count[xxx1][yyy1]-=1;
                                                                                                                                                                                     }
                                                                                                                                                               }
                                                                                                                                          }
                                                                                                                     }
                  
                                                                                          else if(xxxx<=2&&yyyy>=3&&yyyy<=5){
                                                                                                                    for(xxx1=0;xxx1<=2;xxx1++){
                                                                                                                                         for(yyy1=3;yyy1<=5;yyy1++){
                                                                                                                                                              if(number[xxx1][yyy1][abcd]!=0){
                                                                                                                                                                                     number[xxx1][yyy1][abcd]=0;
                                                                                                                                                                                     count[xxx1][yyy1]-=1;
                                                                                                                                                                                     }
                                                                                                                                                              }
                                                                                                                                         }
                                                                                                                    }
                  
                                                                                          else if(xxxx>=3&&xxxx<=5&&yyyy>=3&&yyyy<=5){
                                                                                                                          for(xxx1=3;xxx1<=5;xxx1++){
                                                                                                                                               for(yyy1=3;yyy1<=5;yyy1++){
                                                                                                                                                                    if(number[xxx1][yyy1][abcd]!=0){
                                                                                                                                                                                     number[xxx1][yyy1][abcd]=0;
                                                                                                                                                                                     count[xxx1][yyy1]-=1;
                                                                                                                                                                                     }
                                                                                                                                                                    }
                                                                                                                                               }
                                                                                                                          }
                  
                                                                                          else if(xxxx>=6&&xxxx<=8&&yyyy>=3&&yyyy<=5){
                                                                                                                          for(xxx1=6;xxx1<=8;xxx1++){
                                                                                                                                               for(yyy1=3;yyy1<=5;yyy1++){
                                                                                                                                                                    if(number[xxx1][yyy1][abcd]!=0){
                                                                                                                                                                                     number[xxx1][yyy1][abcd]=0;
                                                                                                                                                                                     count[xxx1][yyy1]-=1;
                                                                                                                                                                                     }
                                                                                                                                                                    }
                                                                                                                                               }
                                                                                                                          }
                  
                                                                                          else if(xxxx<=2&&yyyy>=6&&yyyy<=8){
                                                                                                                    for(xxx1=0;xxx1<=2;xxx1++){
                                                                                                                                         for(yyy1=6;yyy1<=8;yyy1++){
                                                                                                                                                              if(number[xxx1][yyy1][abcd]!=0){
                                                                                                                                                                                     number[xxx1][yyy1][abcd]=0;
                                                                                                                                                                                     count[xxx1][yyy1]-=1;
                                                                                                                                                                                     }
                                                                                                                                                              }
                                                                                                                                         }
                                                                                                                    }
                  
                                                                                          else if(xxxx>=3&&xxxx<=5&&yyyy>=6&&yyyy<=8){
                                                                                                                          for(xxx1=3;xxx1<=5;xxx1++){
                                                                                                                                               for(yyy1=6;yyy1<=8;yyy1++){
                                                                                                                                                                    if(number[xxx1][yyy1][abcd]!=0){
                                                                                                                                                                                     number[xxx1][yyy1][abcd]=0;
                                                                                                                                                                                     count[xxx1][yyy1]-=1;
                                                                                                                                                                                     }
                                                                                                                                                                    }
                                                                                                                                               }
                                                                                                                          }
                  
                                                                                          else if(xxxx>=6&&xxxx<=8&&yyyy>=6&&yyyy<=8){
                                                                                                                          for(xxx1=6;xxx1<=8;xxx1++){
                                                                                                                                               for(yyy1=6;yyy1<=8;yyy1++){
                                                                                                                                                                    if(number[xxx1][yyy1][abcd]!=0){
                                                                                                                                                                                     number[xxx1][yyy1][abcd]=0;
                                                                                                                                                                                     count[xxx1][yyy1]-=1;
                                                                                                                                                                                     }
                                                                                                                                                                    }
                                                                                                                                               }
                                                                                                                          }
                                                                                          }                                                                                     
                                                                                     
                                                                                     }
                                                           }
                                              
                                               
                                                           
                  int bbbb,cccc;
                  for(bbbb=0;bbbb<9;bbbb++){
                                            for(cccc=0;cccc<9;cccc++){
                                                                      if(count[bbbb][cccc]==1) goto begin;
                                                                      }
                                            }
                                
                                
                  
                  int aaaa1,bbbb1,ffff1=0;
                  for(aaaa1=0;aaaa1<9;aaaa1++){
                                              for(bbbb1=0;bbbb1<9;bbbb1++){
                                                                           if(sudo[aaaa1][bbbb1]==0) ffff1+=1; 
                                                                           }
                                              }
                                              
                  int ya,yaya;
                                              
                  if(ffff1==0)
                               {                           
                                cout<<'1'<<endl;     
                                for(ya=0;ya<9;ya++){
                                                          for(yaya=0;yaya<9;yaya++){
                                                                                    cout<<sudo[ya][yaya]<<' ';
                                                                                    }
                                                          cout<<endl;
                                                          }
                                system("pause");
                                }
                 
                  
                  else {
                       Solve2();
                       if(r>=2) {cout<<'2'<<endl;system("pause");}
                       if(r==1) {cout<<'1'<<endl;
                                 for(ya=0;ya<9;ya++){
                                                     for(yaya=0;yaya<9;yaya++){
                                                                               cout<<sudo2[ya][yaya]<<' ';
                                                                               }
                                                     cout<<endl;
                                                     }
                                system("pause");
                                }
                       if(r==0) {cout<<'0'<<endl;system("pause");}
                       }
                           
                  }
     
void Sudoku::Solve2(){       

                     int x12345,y12345,z12345=0;
                     for(x12345=0;x12345<9;x12345++){
                                                     for(y12345=0;y12345<9;y12345++){
                                                                                     if(sudo[x12345][y12345]!=0) z12345++;
                                                                                                                 
                                                                                     }
                                                    }
                                                                      
                     if(z12345==81)
                     {
                                   r+=1;
                                   if(r==1)
                                   {
                                       int nn1,mm1;
                                       for(nn1=0;nn1<9;nn1++){
                                                              for(mm1=0;mm1<9;mm1++) sudo2[nn1][mm1]=sudo[nn1][mm1];                   
                                                              }    
                                   }
                     } 

                  
                  int xy1,xy2,xy3,xy4,xy5,xy6=0,xy7;
                  
                  for(xy1=0;xy1<9;xy1++){                                                                           
                                     for(xy2=0;xy2<9;xy2++){
                                                      if(sudo[xy1][xy2] == 0){
                                                                        for(xy3=1;xy3<=9;xy3++)
                                                                                               {                                //xy3 要測的數字(1~9)          xy6計算是否行列九有相同數字 
                                                                                                 for(xy4=0;xy4<9;xy4++){if(sudo[xy4][xy2]==xy3) xy6+=1;}
                                                                                                 for(xy5=0;xy5<9;xy5++){if(sudo[xy1][xy5]==xy3) xy6+=1;}
                                                                                                                                        
                                                                                                                                               
                                                                                                                                               int g,h;
                                                                                                                                               
                                                                                                                                               if(xy1<=2&&xy2<=2){
                                                                                                                                                                  for(g=0;g<=2;g++){
                                                                                                                                                                                    for(h=0;h<=2;h++){
                                                                                                                                                                                                      if(sudo[g][h]==xy3) xy6+=1;
                                                                                                                                                                                                      }
                                                                                                                                                                                    }                     
                                                                                                                                                                  }
                  
                                                                                                                                               else if(xy1>=3&&xy1<=5&&xy2<=2){
                                                                                                                                                                               for(g=3;g<=5;g++){
                                                                                                                                                                                                 for(h=0;h<=2;h++){
                                                                                                                                                                                                                   if(sudo[g][h]==xy3) xy6+=1;
                                                                                                                                                                                                                   }
                                                                                                                                                                                                 }
                                                                                                                                                                               }
                  
                                                                                                                                               else if(xy1>=6&&xy1<=8&&xy2<=2){
                                                                                                                                                                               for(g=6;g<=8;g++){
                                                                                                                                                                                                 for(h=0;h<=2;h++){
                                                                                                                                                                                                                   if(sudo[g][h]==xy3) xy6+=1;
                                                                                                                                                                                                                   }
                                                                                                                                                                                                 }
                                                                                                                                                                               }
                  
                                                                                                                                               else if(xy1<=2&&xy2>=3&&xy2<=5){
                                                                                                                                                                               for(g=0;g<=2;g++){
                                                                                                                                                                                                 for(h=3;h<=5;h++){
                                                                                                                                                                                                                   if(sudo[g][h]==xy3) xy6+=1;
                                                                                                                                                                                                                   }
                                                                                                                                                                                                 }
                                                                                                                                                                               }
                  
                                                                                                                                               else if(xy1>=3&&xy1<=5&&xy2>=3&&xy2<=5){
                                                                                                                                                                                       for(g=3;g<=5;g++){
                                                                                                                                                                                                         for(h=3;h<=5;h++){
                                                                                                                                                                                                                           if(sudo[g][h]==xy3) xy6+=1;
                                                                                                                                                                                                                           }
                                                                                                                                                                                                         }
                                                                                                                                                                                       }
                  
                                                                                                                                               else if(xy1>=6&&xy1<=8&&xy2>=3&&xy2<=5){
                                                                                                                                                                                       for(g=6;g<=8;g++){
                                                                                                                                                                                                         for(h=3;h<=5;h++){
                                                                                                                                                                                                                           if(sudo[g][h]==xy3) xy6+=1;
                                                                                                                                                                                                                           }
                                                                                                                                                                                                         }
                                                                                                                                                                                       }
                  
                                                                                                                                               else if(xy1<=2&&xy2>=6&&xy2<=8){
                                                                                                                                                                               for(g=0;g<=2;g++){
                                                                                                                                                                                                 for(h=6;h<=8;h++){
                                                                                                                                                                                                                   if(sudo[g][h]==xy3) xy6+=1;
                                                                                                                                                                                                                   }
                                                                                                                                                                                                 }
                                                                                                                                                                               }
                  
                                                                                                                                               else if(xy1>=3&&xy1<=5&&xy2>=6&&xy2<=8){
                                                                                                                                                                                       for(g=3;g<=5;g++){
                                                                                                                                                                                                         for(h=6;h<=8;h++){
                                                                                                                                                                                                                           if(sudo[g][h]==xy3) xy6+=1;
                                                                                                                                                                                                                           }
                                                                                                                                                                                                         }
                                                                                                                                                                                       }
                  
                                                                                                                                               else if(xy1>=6&&xy1<=8&&xy2>=6&&xy2<=8){
                                                                                                                                                                                       for(g=6;g<=8;g++){
                                                                                                                                                                                                         for(h=6;h<=8;h++){
                                                                                                                                                                                                                           if(sudo[g][h]==xy3) xy6+=1;
                                                                                                                                                                                                                           }
                                                                                                                                                                                                         }
                                                                                                                                                                                       }
                                                                                                                                               
                                                                                                                                               
                                                                                                                                               
                                                                                                                            
                                                                                                     
                                                                       /********************************************************************************************************************/                              
                                                                                                     
                                                                                                     
                                                                                                     if(xy6==0){
                                                                                                                sudo[xy1][xy2]=xy3;
                                                                                                                Solve2();
                                                                                                                sudo[xy1][xy2] = 0;
                                                                                                                }
                                                                                                     else xy6=0;
                                                                                                     
                                                                                               }
                                                                       return;
                                                                       }
                                                      }
                                          }
                         
                  
                  }
																																																																												