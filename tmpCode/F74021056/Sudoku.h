#include<iostream>
#include<iomanip>
#include<vector>
#include<fstream>
#include<cstdlib>
#include<time.h> 
#define SIZE 9
using namespace std;


class Sudoku{
	public:
		Sudoku();
		void GiveQuestion();
		void ReadIn();
		void mysolve(int);
		void Solve();
	private:
		int map[81];
		vector<int> print;
		int no;
		int count;
};