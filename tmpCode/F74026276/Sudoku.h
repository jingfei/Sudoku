#include<iostream>
using namespace std;



class Sudoku{
	public:	
		void GiveQuestion();
		void ReadIn();
		int Solve1( int n );
		int Solve2( int n );
		bool Check( int n, int N );
		bool Check2( int n, int N );
		void turnArraytoVector();
		void Solve();
	private:
		int map[9][9];
		int map2[9][9];
		int original[9][9];
		int p[9][9];
		int Ans;
}; 
