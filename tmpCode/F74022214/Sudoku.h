/*
 * Sudoku.h
 *
 *  Created on: 2014/3/27
 *      Author: LukeWu
 */

#ifndef SUDOKU_H_
#define SUDOKU_H_
#include<vector>

struct possibility{
	int no;
	int num;
	int candidate[10];
};

struct log{
	int no;
	int before;
	int after;
};

class Sudoku {
public:
	Sudoku();
	~Sudoku();
	void ReadIn();
	void Solve();
	void GiveQuestion();
	static const int size = 81;
private:
	bool sure;
	int solvable;
	int map[size];
	std::vector<int> buf;
	std::vector<int> possibility_counter[10];
	std::vector<log> logger;
	possibility possible[size];
	int FindTarget();
	bool DeletePossibility(int position,int num,int x);
	bool FindPossibility(int position,int x);
	void Restore(int position,int num);
	void RestoreCounter(unsigned int log_size);
	void RestorePossibility(int position);
	void fill(int num,bool sure);
	void SwapLevel(int no,int before,int after);
	void Output();	
};

#endif /* SUDOKU_H_ */
