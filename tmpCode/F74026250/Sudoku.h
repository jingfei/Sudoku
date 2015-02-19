#include<iostream>
#include<cstdio> 
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;

class Sudoku
{
public:
	int answer[9][9],real_answer[9][9];
	int solution;
	bool bx[9][10],by[9][10],bz[3][3][10];
	Sudoku();
	void GiveQuestion();
	void ReadIn();
	void Solve();
	void backtrack(int,int);
private:
	int map[9][9];
};