#include <cstdio>
#include <iostream>

using namespace std;

class Sudoku
{
public:
    void ReadIn();
    void Solve();
    void GiveQuestion();

private:
    int sudoku[100],column[10][10],row[10][10],cell[10][10],DD[100],cnt,ans[100],boom,lala;
    void set_zero();
    void Btracking(int n);
    void print_ans();
};
