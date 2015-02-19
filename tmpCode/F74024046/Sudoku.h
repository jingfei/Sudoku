#include<iostream>
#include<cstdlib>
#include<time.h>
#include<cstdio>
using namespace std ;

class Sudoku
{
public:
    void GiveQuestion();
     void ReadIn();
	void Solve();
     void reSolve(int,int);
     int completeans();
     int analysis(int x, int y, int num);
private:
     int i,j,num,o,p;
     static const int questionarray[20][81];
     int solvearray[9][9],R[9][9];
     static const int night[9][9];
     int result;
};

