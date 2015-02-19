#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<string>
#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;
class Sudoku
{
public:
	void initSudoku();
    void ReadIn();
    void GiveQuestion();
    void Solve();
    void getNumber();
    void getQuestion();
    void element();
    int BigJudge();
    int SolveSudoku(int a,int b);
    int row(int k1);
	int column(int k2);
	int block(int k1,int k2);
private:
	int SudokuBlock[9][9],Sudokuco[9][9],Sudokufinal[9][9];
	char t;
	int k1,k2,looplocate;
	int kc1,kc2,l1,l2;
	int ca1,ca2,can1,can2,solornot;
	int cache,judge;
	int block1,block2;
	int solve;
	int question_number;
	vector<int> SudokuBB[9][9];
};
																																				