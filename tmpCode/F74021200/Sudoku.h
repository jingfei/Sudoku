#include<iostream>
#include<vector>
using namespace std;
class Sudoku {
public:
	Sudoku();
	int ReadIn();
	bool Solve(int n);
	void GiveQuestion();
	int Getelements(int i);
	int Getansn();
	static const int sudokuSize = 81;
private:
	int init_map[sudokuSize], map[sudokuSize], ans_map[sudokuSize], ze_total;
	vector<int> record;
	int ansn;
};	
