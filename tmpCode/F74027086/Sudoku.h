#ifndef SUDOKU_H
#define SUDOKU_H

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<vector>
using namespace std;

class Sudoku {

public:
	void GiveQuestion();
	void Solve();
	void ReadIn();

private:
	int num[9][9];
	bool Compare(int num[][9]);
	int NumberofZeros(int num[][9], int freeCell[][2]);
	bool isCorrect(int i, int j, int num[][9]);
	bool isCorrect(int num[][9]);
};

#endif // SUDOKU_H
