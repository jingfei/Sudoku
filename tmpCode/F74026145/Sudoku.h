#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

class Sudoku{
public:
void GiveQuestion();
void ReadIn();
void Check();
void Zero();
bool Rule(int N,int num);
bool Backtracking(int N);
void Solve();

private:
int s[9][9];
int row[9][10]; 
int column[9][10];
int nine[9][10];
int count;
int ans;
int x[81];   
int y[81];
int map[9][9];
};