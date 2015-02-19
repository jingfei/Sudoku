#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Sudoku{
	public:
		Sudoku();
		void ReadIn();
		int verticalcheck(int number,int j);
		int standardcheck(int i,int number);
		int squarecheck(int number,int i,int j);
		void make();
		void Solve();
		void GiveQuestion();
	private:
		int a[9][9];
		int answer[9][9];
		
};