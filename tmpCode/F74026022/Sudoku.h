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