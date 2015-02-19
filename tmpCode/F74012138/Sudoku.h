#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <cstdio>
#include <cstdlib>
#include <ctime>

class Sudoku{
public:
	void GiveQuestion();
	void ReadIn();
	int Solve();
};

#endif