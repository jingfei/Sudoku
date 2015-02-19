#include <iostream>
#include <cstdlib>
using namespace std;

class Sudoku{
	public:
		void ReadIn();
		void Solve();
		void GiveQuestion();
		void Out();
		bool CheckZero();
		bool Check(int index, int n);
		int DFS(int index);
		
	private:
		int num[81];
		int ans;
		int ansnum[81];
};