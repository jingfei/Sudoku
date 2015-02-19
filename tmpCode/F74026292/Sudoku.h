#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#ifndef SUDOKU_H_
#define SUDOKU_H_

class Sudoku {
public:
	struct space{
		int x,y;
		int sub_grid;
		std::vector<int>p_num;
	};
	Sudoku();
	void Solve();
	void ReadIn();
	void GiveQuestion_2();
	void GiveQuestion();
	void set_sudoku(int[9][9]);
    int map[9][9];
    int answer[9][9];
    bool solved,multiple_answer,unsolvable;
private:
bool solve(int _map[9][9]);
void convert(int map[9][9],int _map[9][9]);
bool check_sudoku(int[9][9]);
int find_sub_grid(int x,int y);
void sol_map(std::vector<space>,int [9][9]);
void make_space(int num,int _map[9][9]);
};

#endif
