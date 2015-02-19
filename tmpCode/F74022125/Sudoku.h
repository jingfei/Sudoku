#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <ctime>
using namespace std;

class Sudoku
{
public:
    Sudoku();
    void GiveQuestion();
    void ReadIn();
    void Solve();
    int JudgeRow(int k,int i);
    int JudgeColumn(int k,int j);
    int JudgeSquare(int k,int i,int j);
    void backtracking();
private:
    int site[9][9],check[9][9],number,mark,un;
};
