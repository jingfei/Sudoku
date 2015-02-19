#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>

using namespace std;
class Sudoku{
public:
    Sudoku();
    void GiveQuestion();
    void ReadIn();
    void Solve();
    int getElement(int index);
    void backtracking(int Len);
    int getans();
private:
    vector <int> vmap, ans;
    int test,tans;
};
