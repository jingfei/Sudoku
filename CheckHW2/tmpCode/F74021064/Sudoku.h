#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>
#include<cmath>
class Sudoku
{
public:
	void initSudoku();
    int ReadIn();
    void GiveQuestion();
    void Solve();
    int row(int k1);
	int column(int k2);
	int block(int k1,int k2);
private:
	int SudokuBlock[9][9],SudokuEle[9];
	int k1,k2;
	int kc1,kc2;
	int cache;
	int block1,block2;
	int solve;
};
