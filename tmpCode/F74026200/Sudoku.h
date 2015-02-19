#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
using namespace std;

class Sudoku{
public:
    int ReadIn();
    int row_check(int ,int );
    int column_check(int ,int );
    int square_check(int ,int ,int );
    void SolveSudoku();
    void print_answer();
    void Solve();
    void GiveQuestion();
private:
    int anses[1];
    int a[9][9];
    int aa[9][9];
};
