#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#define TWO_DIM 9
#define ONE_DIM 81 
using namespace std;
class Sudoku{
public:
Sudoku();
/*create sudoku---------------------------------------*/
void GiveQuestion();
/*create sudoku---------------------------------------*/

/*solve  sudoku---------------------------------------*/
void ReadIn();
void Solve();
/*solve  sudoku---------------------------------------*/

private:
/*member  sudoku--------------------------------------*/
int one[ONE_DIM];
int two[TWO_DIM][TWO_DIM];
int judge[TWO_DIM][TWO_DIM];
int a,b,c,d,e,f,g,h,k;
int static const blank = 30;
/*create sudoku---------------------------------------*/
void process_number(){
int num[TWO_DIM][TWO_DIM]={{1,2,3,4,5,6,7,8,9},
{2,1,3,4,5,6,8,9,7},
{8,7,9,5,4,6,1,2,3},
{5,4,6,1,2,3,9,8,7},
{9,8,5,6,3,2,4,7,1},
{7,5,3,9,6,4,8,2,1},
{4,5,1,2,3,6,9,7,8},
{4,5,8,7,9,6,2,1,3},
{9,1,5,3,2,4,7,8,6}};
srand(time(NULL));
int i=rand()%10;
a=num[i][0];
b=num[i][1];
c=num[i][2];
d=num[i][3];
e=num[i][4];
f=num[i][5];
g=num[i][6];
h=num[i][7];
k=num[i][8];
}
void create_center_new(){
two[3][3]=a;
two[3][4]=b;
two[3][5]=c;
two[4][3]=d;
two[4][4]=e;
two[4][5]=f;
two[5][3]=g;
two[5][4]=h;
two[5][5]=k;
}
void top_down_new(){
for(int i=3;i<6;i++){
	two[i-3][4]= two[i][3];
	two[i-3][3]= two[i][5];
	two[i-3][5]= two[i][4];
	
	two[i+3][4]= two[i][5];
	two[i+3][5]= two[i][3];
	two[i+3][3]= two[i][4];
	}
}
void left_right_new(){
for(int i=3;i<6;i++){
	two[4][i-3] = two[3][i];
	two[5][i-3] = two[4][i];
	two[3][i-3] = two[5][i];
	
	two[3][i+3] = two[4][i];
	two[4][i+3] = two[5][i];
	two[5][i+3] = two[3][i];
	}
}
void left_top_down_new(){
for(int i=3;i<6;i++){
	two[i-3][0]= two[i][1];
	two[i-3][1]= two[i][2];
	two[i-3][2]= two[i][0];
	
	two[i+3][0]= two[i][2];
	two[i+3][1]= two[i][0];
	two[i+3][2]= two[i][1];
	}
}
void right_top_down_new(){
for(int i=3;i<6;i++){
	two[i-3][6]= two[i][7];
	two[i-3][7]= two[i][8];
	two[i-3][8]= two[i][6];
	
	two[i+3][6]= two[i][8];
	two[i+3][7]= two[i][6];
	two[i+3][8]= two[i][7];
	}
}

void choose_blank_new(){
int count;
count = blank;
srand(time(NULL));
for(;count!=0;){
	int q=rand()%10;
	int w=rand()%10;
	if(two[q][w]!=0){
	two[q][w]=0;
	count--;}
}

for(int i=0;i<9;i++){
	for(int j=0;j<9;j++){
	cout<<two[i][j]<<" ";	
	}
	cout<<endl;
}

}


/*create sudoku---------------------------------------*/

/*solve  sudoku---------------------------------------*/
void read_from_stdin(){
for(int m=0;m<9;m++){
	for(int n=0;n<9;n++){
		cin>>two[m][n];
	}
}
}

void solve(){
		int count_a=0;
        int i,j,k;
		int blank=0;

        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(two[i][j]==0)
                {
                    for(k=1;k<=9;k++)
                    {
                        if(cube(k,i,j)==0 && row(k,i)==0 && col(k,j)==0)
                        {
                            two[i][j]=k;
                            solve();
                            two[i][j]=0;
                        }

                    }
                    return;
                }
            }
        }
		
		for(i=0;i<9;i++)//得到空白格數
        {
            for(j=0;j<9;j++)
            {
                if(two[i][j]==0)
                {
                    blank++;
                }
            }
        }
        if(blank==0)
        {
			solve_two();
			check_sudo();
		
        }	
		else {
		cout<<"-1"<<endl;//無解
		
		}
}

void print_sudo(){
int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
		cout << two[i][j] << " ";
		}
		cout<<endl;
    }

}

void check_sudo(){
int i,j;
		for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(judge[i][j]==0)
                {
                 cout<<"-1"<<endl;//無解
                return;
				}
            }
        }
		
		for(i=0;i<9;i++){
            for(j=0;j<9;j++)
            {
                if(two[i][j]!=judge[i][j])
                {
                    cout<<"0"<<endl;//多數解
					return;
                }
				else{
				cout<<"1"<<endl;//唯一解
				print_sudo();
				}
            }
        }

}

void solve_two(){
        int i,j,k;
        for(i=8;i>=0;i--)
        {
            for(j=8;j>=0;j--)
            {
                if(two[i][j]==0)
                {
                    for(k=1;k<=9;k++)
                    {
                        if(cube(k,i,j)==0 && row(k,i)==0 && col(k,j)==0)
                        {
                            judge[i][j]=k;
                            solve_two();
                            judge[i][j]=0;
                        }

                    }
                    return;
                }
            }
        }
		

}

int cube(int k,int m,int n){
		if((m<=2)&&(m>=0)&&(n<=2)&&(n>=0)){
			for(m=0;m<=2;m++){
				for(n=0;n<=2;n++){
				if(two[m][n]==k){
					return -1;
					}
				}
			}
		}
		else if((m<=2)&&(m>=0)&&(n<=5)&&(n>=3)){
			for(m=0;m<=2;m++){
				for(n=3;n<=5;n++){
				if(two[m][n]==k){
					return -1;
					}
				}
			}
		}
		else if((m<=2)&&(m>=0)&&(n<=8)&&(n>=6)){
		for(m=0;m<=2;m++){
				for(n=6;n<=8;n++){
				if(two[m][n]==k){
					return -1;
					}
				}
			}
		}	
		else if((m<=5)&&(m>=3)&&(n<=2)&&(n>=0)){
		for(m=3;m<=5;m++){
				for(n=0;n<=2;n++){
				if(two[m][n]==k){
					return -1;
					}
				}
			}
		}	
		else if((m<=5)&&(m>=3)&&(n<=5)&&(n>=3)){
		for(m=3;m<=5;m++){
				for(n=3;n<=5;n++){
				if(two[m][n]==k){
					return -1;
					}
				}
			}
		}	
		
		else if((m<=5)&&(m>=3)&&(n<=8)&&(n>=6)){
		for(m=3;m<=5;m++){
				for(n=6;n<=8;n++){
				if(two[m][n]==k){
					return -1;
					}
				}
			}
		}	
		
		else if((m<=8)&&(m>=6)&&(n<=2)&&(n>=0)){
		for(m=6;m<=8;m++){
				for(n=0;n<=2;n++){
				if(two[m][n]==k){
					return -1;
					}
				}
			}
		}	
		
		else if((m<=8)&&(m>=6)&&(n<=5)&&(n>=3)){
			for(m=6;m<=8;m++){
				for(n=3;n<=5;n++){
				if(two[m][n]==k){
					return -1;
					}
				}
			}
		}	
		
		else if((m<=8)&&(m>=6)&&(n<=8)&&(n>=6)){
			for(m=6;m<=8;m++){
				for(n=6;n<=8;n++){
				if(two[m][n]==k){
					return -1;
					}
				}
			}
		}	
		
return 0;
}

int row(int k,int i){
for(int m=0;m<9;i++){
	if(two[i][m]==k){
	return -1;
	}
}
return 0;
}

int col(int k,int j){
for(int m=0;m<9;m++){
	if(two[m][j]==k){
	return -1;
	}
}
return 0;
}


};