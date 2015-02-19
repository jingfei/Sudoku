//
// Sudoku.h
// sudoku
// Created by Wemy Ju on 03/31/2014.
//

#ifndef SUDOKU
#define SUDOKU

#include <cstdio>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <queue>

using namespace std;

class Sudoku
{
public:
	Sudoku();
	void GiveQuestion();
	void ReadIn();
	void Solve();
private:
	void FindAnswer(int);
	queue<int> unknown;
	int board[9][9];
    int temp[9][9];
	int numOfSol;
	int checkR[9][9];
    int checkC[9][9];
    int checkB[9][9];
};

#endif
