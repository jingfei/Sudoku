#include<iostream>
#include<string>
#include<cstdlib>
#include<cstdio>
#include<time.h>

using namespace std;

class Sudoku
{
public:
	Sudoku();
    void GiveQuestion();
    void ReadIn();
    void Solve();
    void IWannaSolveIt(int x, int y);
    int judge();
    int judgenum(int x, int y, int ans);
private:
    static const int givenum[5][81];
    int cnt_ans;
    int solvesudoku[9][9], correct_ans[9][9];
};