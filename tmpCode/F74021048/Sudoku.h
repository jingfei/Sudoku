#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Sudoku
{
public:

    int a[10][10],b[10][10],ans,TIME;
	Sudoku();
    void GiveQuestion();
    void ReadIn();
    void Solve();
    int check(int num,int i,int j);
};