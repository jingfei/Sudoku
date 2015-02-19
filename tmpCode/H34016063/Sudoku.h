#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<cstring>
using namespace std;

class Sudoku
{
public:
    Sudoku();
    void GiveQuestion();
    void ReadIn();
    void PrintOut();
    void Solve();
private:
    bool generateBacktrack(int[9][9],int,int);
    bool solveBacktrack(int,int,int[9][9],int&);
    void duplicateMap(int[9][9],int[9][9]);
    int board[9][9];
    int solve_num;
};
