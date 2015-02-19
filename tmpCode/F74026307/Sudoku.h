#include<iostream>
#define N 81
using namespace std;
class Sudoku{
	public:
		Sudoku();
		void ReadIn();
		void GiveQuestion();
		void Solve();
		void Solve1();
	private:
		int map[N],answer[N],amount;
		bool checkelement(int index,int element);
		bool checksquare(int row,int column,int element);
		int getzero();
		bool checkmap();
		bool checkunity(int inunity[9]);
};
