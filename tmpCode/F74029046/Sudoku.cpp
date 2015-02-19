#include "Sudoku.h"
#include<iostream>
#include<cstdlib>

using namespace std;

Sudoku::Sudoku()
{
 for(int i=0;i<sudoku_rl_size;i++)
  for(int j=0;j<sudoku_rl_size;j++)
    map[i][j]=0;
}

void Sudoku::GiveQuestion()
{
 srandom(time(NULL));
 int index[9];
 for(int i=0;i<9;i++)
  index[i]=0;
 bool t=false;
 int s,c=0,g;

 int temp_index[9];
 bool cs[9];
 
 for(int i=0;i<9;i++){
  temp_index[i]=i+1;
  cs[i]=false;}

 while(1){
 g=0;
 for(int j=0;j<9;j++)
   if(cs[j])
    g++;
 if(g==9)
   break;
 s=random()%9;
  if(!cs[s]){
    index[c]=temp_index[s];
    cs[s]=true;
    c++;}
}

int question[sudoku_rl_size][sudoku_rl_size];

int startrow=3;
int startcol=0;
for(int j=0;j<3;j++){
  startrow=3+j;
  startcol=0;
  for(int i=0;i<3;i++)
   question[startrow][startcol+i]=index[j*3+i%3];
  startrow=3+(startrow+2)%3;
  startcol=3;
  for(int i=0;i<3;i++)
   question[startrow][startcol+i]=index[j*3+i%3];
  startrow=3+(startrow+2)%3;;
  startcol=6;
  for(int i=0;i<3;i++)
   question[startrow][startcol+i]=index[j*3+i%3];

  startrow=0+j;
  startcol=0;
  for(int i=0;i<3;i++)
   question[startrow][startcol+i]=index[j*3+((i+1)%3)];
  startrow=0+(startrow+2)%3;
  startcol=3;
  for(int i=0;i<3;i++)
   question[startrow][startcol+i]=index[j*3+((i+1)%3)];
  startrow=0+(startrow+2)%3;;
  startcol=6;
  for(int i=0;i<3;i++)
   question[startrow][startcol+i]=index[j*3+((i+1)%3)];

  startrow=6+j;
  startcol=0;
  for(int i=0;i<3;i++)
   question[startrow][startcol+i]=index[j*3+((i+2)%3)];
  startrow=6+(startrow+2)%3;
  startcol=3;
  for(int i=0;i<3;i++)
   question[startrow][startcol+i]=index[j*3+((i+2)%3)];
  startrow=6+(startrow+2)%3;
  startcol=6;
  for(int i=0;i<3;i++)
   question[startrow][startcol+i]=index[j*3+((i+2)%3)];
}

int vac=0; 
int target=45+random()%11;
int p=0;
int row,col,num;

while(1){
p=0;
vac=0;
for(int i=0;i<9;i++)
 for(int j=0;j<9;j++)
   map[i][j]=question[i][j];

count=0;
row=random()%9;
col=random()%9;
map[row][col]=0;

while(vac<=target){
  p++;
  count=0;
  row=random()%9;
  col=random()%9;
  num=map[row][col];
  map[row][col]=0;
   for(int i=0;i<9;i++)
   for(int j=0;j<=9;j++){
     checkrow[i][j]=false;
     checkcol[i][j]=false;
     checkcell[i][j]=false;
 }

 for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
     if(map[i][j]!=0)
        {
            int temp;
            temp=map[i][j];
            checkrow[i][temp]=true;
            checkcol[j][temp]=true;
            checkcell[(i/3)*3+j/3][temp]=true;
        }

  SolveAnswer(0,0);
  if(count==1&&num!=0){ 
    vac++;}
  else
   map[row][col]=num;
  
  if(p>=200)
   break;  
}
if(vac>=target)
 break;
}

for(int i=0;i<9;i++){
 for(int j=0;j<9;j++)
   cout<<map[i][j]<<" ";
  cout<<endl;}

}

void Sudoku::ReadIn(){
int temp;
for(int i=0;i<sudoku_rl_size;i++)
 for(int j=0;j<sudoku_rl_size;j++)
{
  cin>>temp;
  map[i][j]=temp;
}                    }


bool Sudoku::checkunity(int arr[])
{
 int arr_unity[9];

 for(int i=0;i<9;i++)
  arr_unity[i]=0;
 for(int i=0;i<9;i++)
  if(arr[i]!=0)
   ++arr_unity[arr[i]-1];
 for(int i=0;i<9;i++)
  if(arr_unity[i]!=1&&arr_unity[i]!=0)
   return false;
 return true;
}


bool Sudoku::isCorrect(int map[sudoku_rl_size][sudoku_rl_size])
 {
 bool check_result;
 int check_arr[9];
for(int i=0; i<9; i++) // check rows
 {
 for(int j=0; j<9; j++)
 check_arr[j] = map[i][j];
 check_result = checkunity(check_arr);
 if(check_result == false)
 return false;
 }
for(int i=0; i<9; ++i) // check columns
{
 for(int j=0; j<9; ++j)
 check_arr[j] = map[j][i];
 check_result = checkunity(check_arr);
 if(check_result == false)
 return false;
 }

 for(int i=0; i<9; i++) // check cells
 {
 for(int j=0; j<9; ++j)
  check_arr[j] = map[(i/3)*3+(j/3)][(i%3)*3+(j%3)]; 
  check_result = checkunity(check_arr);
  if(check_result == false)
  return false;
 }
 return true;
 }
 
 void Sudoku::Solve(){
 if(!isCorrect(map)){
  cout<<"0"<<endl;
  return;}

 for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
      answer[i][j]=map[i][j];
 
 
 for(int i=0;i<9;i++)
   for(int j=0;j<=9;j++){
     checkrow[i][j]=false;
     checkcol[i][j]=false;
     checkcell[i][j]=false; 
 }
 
 for(int i=0;i<9;i++)
    for(int j=0;j<9;j++)
     if(map[i][j]!=0)
        {
            int temp;
            temp=map[i][j];
            checkrow[i][temp]=true;
            checkcol[j][temp]=true;
            checkcell[(i/3)*3+j/3][temp]=true;
        }
      count=0;
      SolveAnswer(0,0);
      printanswer();
 }
 
 
 
 
 void Sudoku::SolveAnswer(int i,int j){
   if(count>=2)
     return;
   if(j==9){
    i++;
    j=0;}
   
   if(i==9){
	count++;
	for(int i=0;i<9;i++){
	  for(int j=0;j<9;j++)
	     temp[i][j]=answer[i][j];	  
	}
	return;
     }
 

    if(map[i][j]!=0){
        SolveAnswer(i,j+1);
    	return;
    }
 
    for(int num=1;num<=9;num++)
    if(!checkrow[i][num] && !checkcol[j][num] && !checkcell[(i/3)*3+j/3][num]){
        checkrow[i][num]=true;
        checkcol[j][num]=true;
        checkcell[(i/3)*3+j/3][num]=true;

	answer[i][j]=num;
	SolveAnswer(i,j+1);

	checkrow[i][num]=false;
	checkcol[j][num]=false;
	checkcell[(i/3)*3+j/3][num]=false;
    }
 }

void Sudoku::printanswer(){
 if(count==1){
cout<<"1"<<endl;
  for(int i=0;i<9;i++){
    for(int j=0;j<9;j++)
       cout<<temp[i][j]<<" ";
    cout<<endl;}
}

 else if(count>=2)
    cout<<"2"<<endl;

 
 else
    cout<<"0"<<endl;
}

