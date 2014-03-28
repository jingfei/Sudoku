#include<stdio.h>

#include<stdlib.h>

#include<string.h>

#include<iostream>

#include<time.h>

#define SIZE 9



using namespace std;

int RandomSudoku(int sudoku[SIZE][SIZE],int x,int y);

int FindPossibleNum(int sudoku[SIZE][SIZE],int candidate[SIZE],int x,int y);

int isOK(int sudoku[SIZE][SIZE],int x,int y);

int main()

{

int sudoku[SIZE][SIZE],i,j,run=1,num;

char ch;

srand(time(NULL));

memset(sudoku,0,SIZE*SIZE*sizeof(int));

//第一部分 

RandomSudoku(sudoku,0,0);

//顯示出來 

for(i=0;i<SIZE;i++)

{

for(j=0;j<SIZE;j++)

cout<<sudoku[i][j]<<' ';

cout<<'\n';

}

system("pause");

return 0;

}



int isOK(int sudoku[SIZE][SIZE],int x,int y)

{

bool num[SIZE];

int i,j;

memset(num,0,SIZE*sizeof(bool));

//檢查列 

for(i=0;i<SIZE;i++)

if(sudoku[x][i]!=0)

if(num[sudoku[x][i]-1])

return 0;

else

num[sudoku[x][i]-1]=true;

memset(num,0,SIZE*sizeof(bool));

//檢查行 

for(i=0;i<SIZE;i++)

if(sudoku[i][y]!=0)

if(num[sudoku[i][y]-1])

return 0;

else

num[sudoku[i][y]-1]=true;

memset(num,0,SIZE*sizeof(bool));

//檢查九宮格 

for(i=(x/3)*3;i<(x/3+1)*3;i++)

{

for(j=(y/3)*3;j<(y/3+1)*3;j++)

if(sudoku[i][j]!=0)

if(num[sudoku[i][j]-1])

return 0;

else

num[sudoku[i][j]-1]=true;

}

return 1;

}

int FindPossibleNum(int sudoku[SIZE][SIZE],int candidate[SIZE],int x,int y) 
{ 
int count=0,i; 

for(i=1;i<=SIZE;i++) 
{ 
sudoku[x][y]=i; 
if(isOK(sudoku,x,y)) 
//如果可以，就把i加到候選數字中 
candidate[count++]=i; 
sudoku[x][y]=0; 
} 
return count; 
}

int RandomSudoku(int sudoku[SIZE][SIZE],int x,int y) 
{ 
int rand_index,methods,candidate[SIZE],temp; 
if(x==SIZE) 
if(y==SIZE-1) 
return 1; 
else 
{ 
x=0; 
y++; 
} 
methods=FindPossibleNum(sudoku,candidate,x,y);
while(methods>0) 
{ 
rand_index=rand()%methods; 
temp=candidate[rand_index]; 
candidate[rand_index]=candidate[methods-1]; 
candidate[methods-1]=temp; 
sudoku[x][y]=temp; 
if(RandomSudoku(sudoku,x+1,y)) 
return 1; 
sudoku[x][y]=0; 
methods--; 
} 
return 0; 
}