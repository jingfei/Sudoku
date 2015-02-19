#include <cstdio>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;

class Sudoku {
	public:
		Sudoku();
		void GiveQuestion();
		void ReadIn();
		void Solve();
	private:
		vector<int> question;

		int getFirstZeroIndex(vector<int>& v);
		bool isValid(vector<int>& v);
		bool isCorrect(vector<int>& v);
		void backtrack(vector<int>& q, vector<int>& a, int& n);
};
