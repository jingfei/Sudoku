#include <iostream>
#include <cstring>

using namespace std;

class Sudoku{
public:
	Sudoku();
	
	bool check(int element, int pos);
	void backtracking(int &pos);

	void ReadIn();
	void GiveQuestion();
	void Solve();


private:
	int map[81];
	int ans_map[81];
	int zero_pos[81];
	int count;
};
