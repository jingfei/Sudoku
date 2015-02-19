#include"Sudoku.h"
#include<iostream>
using namespace std;
#include<cstdlib>
#include<string>

void Sudoku:: GiveQuestion(){


char a[]={'0','0','0','0','0','5','0','2','0',
	  '1','0','0','9','0','0','0','0','0',
	  '4','0','0','0','0','0','0','0','0',
	  '0','0','8','0','0','2','0','0','0',
	  '0','0','0','0','0','0','0','0','1',
	  '0','0','0','0','0','0','9','0','4',
	  '0','0','5','0','0','0','3','0','0',
	  '0','0','0','1','0','0','0','0','7',
	  '0','0','2','4','0','8','0','0','0'};

char b[]={'0','0','0','0','0','0','0','5','8',
	  '0','0','3','0','7','4','0','0','0',
	  '0','0','0','0','0','0','0','0','0',
	  '5','0','0','0','0','0','0','0','0',
	  '0','0','0','0','0','9','3','0','1',
	  '6','0','0','0','0','0','7','0','0',
	  '0','0','0','0','6','0','0','0','0',
	  '0','0','0','8','5','0','0','0','4',
	  '0','0','9','0','0','0','0','0','3'};

char c[]={'0','0','0','0','0','6','8','0','7',
	  '0','0','0','0','0','0','0','0','0',
	  '5','0','4','0','0','0','3','0','0',
	  '0','0','0','7','0','8','6','0','0',
	  '9','0','0','0','4','0','0','5','0',
	  '0','0','0','0','0','0','0','0','0',
	  '0','0','0','0','9','0','0','2','0',
	  '0','6','8','0','0','0','0','0','0',
	  '0','0','0','0','0','0','0','4','0'};

char d[]={'0','0','0','0','5','0','0','9','0',
	  '4','0','0','0','0','0','0','0','2',
	  '0','0','6','7','0','0','0','0','0',
	  '2','0','0','0','0','0','0','0','0',
	  '9','5','0','0','0','0','0','1','0',
	  '0','0','0','6','0','0','0','0','0',
	  '0','0','0','0','0','0','0','0','3',
	  '0','8','0','0','0','0','7','0','6',
	  '0','0','0','0','1','3','0','0','0'};

char e[]={'0','0','0','0','4','0','0','0','0',
	  '0','3','0','0','0','0','6','0','8',
	  '0','0','0','5','2','0','0','0','0',
	  '9','0','5','0','0','0','0','0','0',
	  '0','0','2','0','0','0','0','0','0',
	  '0','0','0','0','0','6','8','0','0',
	  '1','0','0','0','9','0','0','5','0',
	  '0','0','0','0','0','0','0','0','0',
	  '0','8','0','0','0','4','3','0','0'};

int i,r;
srand(time(NULL));
r=(rand()%5)+1;
if(r==1){
for(i=0;i<=80;i++){
if(i%9!=8)
	cout<<d[i]<<" ";
else
	cout<<d[i]<<"\n";
}
}
if(r==2){
for(i=0;i<=80;i++){
if(i%9!=8)
        cout<<c[i]<<" ";
else
        cout<<c[i]<<"\n";
}
}
if(r==3){
for(i=0;i<=80;i++){
if(i%9!=8)
        cout<<d[i]<<" ";
else
        cout<<d[i]<<"\n";
}
}
if(r==4){
for(i=0;i<=80;i++){
if(i%9!=8)
        cout<<e[i]<<" ";
else
        cout<<e[i]<<"\n";
}
}
if(r==5){
for(i=0;i<=80;i++){
if(i%9!=8)
        cout<<c[i]<<" ";
else
        cout<<c[i]<<"\n";
}
}
}

void Sudoku::ReadIn(){
    for(int i=0;i<9;i++){
    	for(int j=0;j<9;j++){
	    cin>>s[i][j];
	    if(s[i][j]<0||s[i][j]>9)
		cout<<"0"<<endl;	
        }
    }
    Check();
}

void Sudoku::Check(){
    for(int i=0;i<9;i++){
        for(int j=0;j<10;j++){ 
            row[i][j]=false;
            column[i][j]=false;
            nine[i][j]=false;
        }
    }
    for(int i=0;i<9;i++){
	for(int j=0;j<9;j++){        
	    if(s[i][j]!=0){
		if(row[i][s[i][j]]==false)
		    row[i][s[i][j]]=true;    
		else
		    cout<<"0"<<endl;
		if(column[j][s[i][j]]==false)
		    column[j][s[i][j]]=true;
		else
		    cout<<"0"<<endl;
		if(nine[3*(i/3)+(j/3)][s[i][j]]==false)
		    nine[3*(i/3)+(j/3)][s[i][j]]=true;	
		else
		    cout<<"0"<<endl;
	    }
	}
    }
}

bool Sudoku::Rule(int N, int num){
   /* N */
    if(row[x[N]][num]==true||column[y[N]][num]==true||nine[3*(x[N]/3)+(y[N]/3)][num]==true)
	return false;
    else{
	return true;
    }
}

bool Sudoku::Backtracking(int N){  /* 回傳值 / 參數型別 */
    if(N==0){
      	++ans;
	if(ans==1){ 
	  for(int i = 0;i < 9;++i)   
	    for(int j = 0;j < 9;++j)
	      map[i][j]=s[i][j];
	}
	if(ans > 1)
	    return true;  //找到第二組解則return true到底 防止非常多組解TLE
	else return false; //continue search solution
    }

    for(int num=1;num<=9;num++){
	if(Rule(N-1, num)==true){
	    s[x[N-1]][y[N-1]]=num;
	    row[x[N-1]][num]=true;
            column[y[N-1]][num]=true;
            nine[3*(x[N-1]/3)+(y[N-1]/3)][num]=true;

	    /* N - 1 */ 
	    if(Backtracking(N-1)) return true;//遞迴下去填下個空格 //Multiple Solution...break!

	    s[x[N-1]][y[N-1]]=0;
            row[x[N-1]][num]=false;
            column[y[N-1]][num]=false;
            nine[3*(x[N-1]/3)+(y[N-1]/3)][num]=false;
	}
    }
    return false; //not multiple solution
}

void Sudoku::Solve(){
    ans=0;
    count=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(s[i][j]==0){
                x[count]=i;
                y[count]=j;
                count++;
            }
        }
    }

    Backtracking(count);
    if(ans==0)
	cout<<"0"<<endl;
    else if(ans==1){
	cout<<"1"<<endl;
	for(int i=0;i<9;i++){
	    for(int j=0;j<9;j++)
		if(j%9!=8)
		    cout<<map[i][j]<<" ";
		else
		    cout<<map[i][j]<<endl;
	}
    }
    else{
	cout<<"2"<<endl;
    }
}