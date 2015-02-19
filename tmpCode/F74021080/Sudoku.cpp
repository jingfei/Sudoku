#include<iostream>
#include<iomanip>
#include<fstream>
#include<cstdlib>
#include "Sudoku.h"
using namespace std;
Sudoku::Sudoku(){ con=0; her=0;
z=0;
for(i=0;i<81;i++)
mapping[i]=0;
int map1[9][9]=
{{3,6,0,2,0,0,0,4,5},
{0,0,0,5,3,0,6,9,0},
{0,8,7,0,0,0,1,0,0},
{0,0,0,1,2,0,9,6,0},
{0,0,3,6,0,5,8,0,0},
{0,2,8,0,9,4,0,0,0},
{0,0,1,0,0,0,4,8,0},
{0,7,5,0,6,3,0,0,0},
{2,4,0,0,0,9,0,5,7}};

int map2[9][9]=
{{9,8,2,0,5,0,4,1,3},
{3,4,6,1,0,0,0,0,0},
{0,0,0,0,4,0,0,2,0},
{0,2,9,6,1,7,3,8,4},
{0,3,8,0,2,9,0,5,0},
{7,0,4,5,0,0,0,0,0},
{0,9,0,0,6,5,0,0,8},
{2,5,3,8,0,0,9,0,1},
{0,0,7,3,9,1,2,0,5}};
int map3[9][9]=
{{0,5,0,0,0,0,7,0,0},
{0,0,4,0,0,0,0,0,8},
{8,0,3,0,5,1,0,0,0},
{0,3,0,0,0,7,0,0,5},
{0,0,0,5,9,2,0,0,0},
{6,0,0,4,0,0,0,2,0},
{0,0,0,1,7,0,4,0,2},
{4,0,0,0,0,0,6,0,0},
{0,0,6,0,0,0,0,9,0}};

srandom(time(NULL));
int j,k=0,a = random()%4;
if(a==0)
{for(i=0;i<9;i++)
  { for(j=0;j<9;j++)
    {map[k]=map1[i][j];
	k=k+1;}
    }}
if(a==1)
{for(i=0;i<9;i++)
  { for(j=0;j<9;j++)
    {map[k]=map2[i][j];
    k=k+1;
	}}}
if(a==2)
{for(i=0;i<9;i++)
  { for(j=0;j<9;j++)
   { map[k]=map3[i][j];
    k=k+1;
	}}}	
	if(a==3)
	{int map4[81]={9,8,2,7,5,6,4,1,3,0,4,6,1,8,2,5,0,9,1,7,5,9,4,3,8,2,6,0,2,9,6,1,7,3,8,4,6,3,8,4,2,0,1,5,7,7,1,4,5,3,8,6,9,2,4,9,1,2,6,5,7,3,8,2,0,3,8,7,4,9,6,1,8,6,7,3,9,1,2,4,5};	
	for(i=0;i<81;i++)
	map[i]=map4[i];
	}

	
	
}
void Sudoku::GiveQuestion()
{
for( i=0;i<81;i++){
		cout<<setw(2)<<map[i];
		if((i+1)%9==0){cout<<"\n";}}
}


void Sudoku::ReadIn()
{int num;
	for( i=0;i<81;i++){
		cin>>num;
		map[i]=num;}
}
 void Sudoku::Solve()
{int ii=0;
int j=0,w=0,x,y,yes=0;
while(ii<4){
z=0;
for(i=0;i<81;i++)
{ if(map[i]==0){ 
  z=z+1;}
}
 for(i=0;i<z;i++)
 store[i]=0;
 
x=0;
for(i=0;i<81;i++)
{if(map[i]==0)
 {store[x]=i;
 x=x+1;}}
 
 x=0;
 while(x<z)
 {y=0;
 for(w=1;w<=9;w++)
 {  
 if(checkUnity(w,store[x])==1&&isCorrect(w,store[x])==1)
 {y=y+1;if(y>1){break;}
 yes=w;}}
 if(y==0){con=0;}
 if(y==1)
 {map[store[x]]=yes;}
 x=x+1;
 }
 ii=ii+1;
 }
 int cc=0;
 for(i=0;i<81;i++)
 {if(map[i]!=0){cc=cc+1;}}
 
 if(cc==81)
 {con=1;
  answer();	} 
 



else
{con=0;
 solvemap();
 answer();}
}

 void Sudoku::solvemap()
 {
 int x;
  her=0;
 do{
  map[store[her]]=map[store[her]]+1;
  if(map[store[her]]>9)
  {
  map[store[her]]=0;
  her=her-1;}
  else
  {//cout<<checkUnity(map[store[her]],store[her])<<" "<<isCorrect(map[store[her]],store[her])<<"|";
  if(checkUnity(map[store[her]],store[her])==1&&isCorrect(map[store[her]],store[her])==1)
     {
       her=her+1;
      }
  }
}while(her>=0&&her<z);

int cc=0;
for(i=0;i<81;i++)
{if(map[i]==0)
  cc=cc+1;}
  
 if(cc==81)
{con=2;}
x=0;
for(i=0;i<81;i++)
{if(map[i]==0)
 {store[x]=i;
 x=x+1;}}
 if(x%2==0){con=2;}
 else{con=0;}

   
 }

void Sudoku::setMap(const int set_map[])
{
}
void Sudoku::answer(){
 int i;
     if(con==0)
	  {cout<<0<<endl;
	   /*for(i=0;i<81;i++){
        cout<<map[i]<<" ";
        if((i+1)%9==0){cout<<"\n";}
    }*/}
	  if(con==1)
	  {cout<<1<<endl;
	  for(i=0;i<81;i++){
        cout<<map[i]<<" ";
        if((i+1)%9==0){cout<<"\n";}
    }}
	  if(con==2)
	   {cout<<2<<endl;
	  /*for(i=0;i<81;i++){
        cout<<map[i]<<" ";
        if((i+1)%9==0){cout<<"\n";}
    }*/}
    
}

bool Sudoku::checkUnity(int Uni,int w)
{
    int x=(w/9)/3; int y=(w%9)/3;
  int whe=(x*3)*9+(y*3);
    for(i = 0; i < 3; i++){
            if((whe+i)!=w&&map[whe+i] == Uni)
            return 0;
			if((whe+9+i)!=w&&map[whe+9+i]==Uni)
			{
			return 0;}
			if((whe+18+i)!=w&&map[whe+18+i]==Uni)
			{
			return 0;}
    }
	
    return 1;
 }
 bool Sudoku::isCorrect(int numb,int r)
 {
//row
 for(int j=0;j<9;j++){
        if(((r/9)*9+j)!=r&&map[(r/9)*9+j] == numb)
        return 0;
    }
//column
 for(int j=0;j<9;j++){
        if((9*j)+(r%9)!=r&&map[(9*j)+(r%9)] == numb)
        return 0;
    }

 return 1;
 }

