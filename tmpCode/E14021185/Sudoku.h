#include <iostream>
#include <vector>
using namespace std;

class Sudoku {
public:
	Sudoku();
	void GiveQuestion();
	vector<int> ReadIn(vector<int>);
	bool Solve(vector<int>, vector<int> &, int);
	bool reverse(vector<int>, vector<int> &, int);
	static const int size=83;
	static const int test=10;
	bool precheck(vector<int>, int);
	int checkzero(vector<int>, int);
	int checkzero_r(vector<int>, int);
	bool checkall(vector<int>);
	void output(vector<int>);
};
