#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
#ifndef Sudocu_H
#define Sudocu_H
class Sudoku
{
	public:
		
		int a[9][9];
		int ran;	
		int sudoku[9][9];
		int count;
void GiveQuestion();
int checkrow(int row ,int num );
int checkcolumn(int column,int num);
int checkblock(int row,int column,int num);
void navigate(int row ,int column);
void display();
void solvesudoku(int row,int column);
void ReadIn();
void Solve();

};
#endif
