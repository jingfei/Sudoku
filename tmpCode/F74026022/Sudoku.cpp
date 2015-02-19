#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;
class Sudoku{
public:
	Sudoku();
	void GiveQuestion();
	void ReadIn();
	void compare(int col , int row , int trylevel);
	void compare2(int col , int row , int trylevel);
	void Solve();
	void solve(int col , int row , int trylevel , int direction);
	void solve2(int col , int row , int trylevel , int direction);
	void setsolvable();
	int getsolvable();
	void setsudoku();
	void printsudoku();
private:
	int col , row , num;
	int solvable;
	int sudoku[9][9] , solution[9][9] , sudoku2[9][9];
	int tryanswer[81] , trylevel;
	int original_sudoku[9][9];
};

using namespace std;
Sudoku::Sudoku(){
	solvable=0;
	for(int i=0;i<81;i++)
		tryanswer[i]=1;
}
void Sudoku::GiveQuestion(){
	srand(time(NULL));
	int a=(rand()%2);
	if(a==0)
	cout << "0 8 6 0 0 0 7 2 0" << endl << "0 2 0 0 0 0 0 9 0" << endl << "0 0 0 8 0 5 0 0 0" << endl << "1 0 0 7 0 8 0 0 3" << endl << "0 0 8 0 0 0 9 0 0" << endl << "5 0 0 9 0 4 0 0 1" << endl << "0 0 0 6 0 2 0 0 0" << endl << "0 9 0 0 0 0 0 8 0" << endl << "0 6 3 0 0 0 4 7 0" << endl;
	else
	cout << "4 0 0 5 0 0 8 3 0" << endl << "0 5 8 0 0 3 0 0 9" << endl << "0 6 1 0 0 9 0 0 4" << endl << "7 0 0 2 0 0 9 4 0" << endl << "0 0 0 0 0 0 0 0 0" << endl << "0 4 3 0 0 5 0 0 1" << endl << "5 0 0 4 0 0 1 7 0" << endl << "1 0 0 3 0 0 6 5 0" << endl << "0 8 7 0 0 2 0 0 3" << endl;
}
void Sudoku::ReadIn(){
	setsudoku();
}
void Sudoku::compare(int col ,int row , int trylevel){
	int sign=0;	
	for(int j=0;j<=8;j++)
		if(sudoku[col][j]==tryanswer[trylevel]||sudoku[j][row]==tryanswer[trylevel]){
			sign=1;
			break;
		}
	if(sign==0)
		for(int j=0;j<=2;j++)
			for(int k=0;k<=2;k++)
				if(sudoku[col-(col%3)+j][row-(row%3)+k]==tryanswer[trylevel]){
					sign=1;
					break;
				}
	if(sign==0){
		sudoku[col][row]=tryanswer[trylevel];
		solve(col , row+1 , trylevel+1 , 1);	
		}
	else if(tryanswer[trylevel]<9){
		tryanswer[trylevel]++;
		compare(col , row , trylevel);
	}
	else{
		tryanswer[trylevel]=1;
		sudoku[col][row]=0;
		solve(col , row-1 , trylevel-1 , 2);
	}
}
void Sudoku::compare2(int col ,int row , int trylevel){
        int sign=0;
        for(int j=0;j<=8;j++)
                if(sudoku[col][j]==tryanswer[trylevel]||sudoku[j][row]==tryanswer[trylevel]){
                        sign=1;
                        break;
                }
        if(sign==0)
                for(int j=0;j<=2;j++)
                        for(int k=0;k<=2;k++)
                                if(sudoku[col-(col%3)+j][row-(row%3)+k]==tryanswer[trylevel]){
                                        sign=1;
                                        break;
                                }
        if(sign==0){
                sudoku[col][row]=tryanswer[trylevel];
                solve2(col , row+1 , trylevel+1 , 1);
                }
        else if(tryanswer[trylevel]>1){
                tryanswer[trylevel]--;
                compare2(col , row , trylevel);
        }
        else{
                tryanswer[trylevel]=9;
                sudoku[col][row]=0;
                solve2(col , row-1 , trylevel-1 , 2);
        }
}
void Sudoku::Solve(){
	solve(0 , 0 , 0 , 1);
	printsudoku();
}
void Sudoku::solve(int col , int row , int trylevel , int direction){
	if(trylevel<0)
		return;
	if(direction==1){
		if(col==8&&(row==8||row==9)&&sudoku[8][8]!=0){
			for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
			solution[i][j]=sudoku[i][j];
			solvable++;
			for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
			sudoku[i][j]=original_sudoku[i][j];
			for(int i=0;i<81;i++)
                		tryanswer[i]=9;
			solve2(0 , 0 , 0 , 1);
			return;
		}
		if(solvable>=2)
			return;
		if(col<8&&row==9){
			col++;
			row=0;
		}
		if(original_sudoku[col][row]!=0)
			solve(col , row+1 , trylevel , 1);
		else{
			compare(col , row , trylevel);	
		}
	}
	else{
        if(solvable>=2)
           	return;
		if(col>0&&row==(-1)){
			col--;
			row=8;
		}
                if(original_sudoku[col][row]!=0)
                        solve(col , row-1 , trylevel , 2);
                else{
                        compare(col , row , trylevel);
                }
	}
}
void Sudoku::solve2(int col , int row , int trylevel , int direction){
        	if(trylevel<0)
				return;
			if(direction==1){
                if(col==8&&row==8&&sudoku[col][row]!=0){
                        if(memcmp(sudoku , solution , sizeof(sudoku))!=0)
                        	solvable++;
						else
                        	return;
                }
                if(solvable>=2)
                        return;
                if(col<8&&row==9){
                        col++;
                        row=0;
                }
                if(original_sudoku[col][row]!=0)
                        solve2(col , row+1 , trylevel , 1);
                else{
                        compare2(col , row , trylevel);
                }
        }
        else{
                if(solvable>=2)
                        return;
                if(col>0&&row==(-1)){
                        col--;
                        row=8;
                }
                if(original_sudoku[col][row]!=0)
                        solve2(col , row-1 , trylevel , 2);
                else{
                        compare2(col , row , trylevel);
                }
        }
}
void Sudoku::setsolvable(){
	cin >> solvable;
}
int Sudoku::getsolvable(){
	return solvable;
}
void Sudoku::setsudoku(){
	for(int i=0;i<9;i++)
	for(int j=0;j<9;j++)
	cin >> original_sudoku[i][j];
	for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
			sudoku[i][j]=original_sudoku[i][j];
}
void Sudoku::printsudoku(){
	if(solvable==0)
	cout << "0" << endl;
	else if(solvable==1){
		cout << "1" << endl;
		for(int i=0;i<9;i++){
		for(int j=0;j<9;j++)
		cout << solution[i][j] << " " ;
		cout << endl;
		}
	}
	else
	cout << "2" << endl;
}