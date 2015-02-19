#ifndef SUDOKU_H_
#define SUDOKU_H_

#include <cstdio>

void read_sudoku();
int solve_sudoku();
void output_sudoku();

class Sudoku{
public:
	void GiveQuestion(){
		printf("8 0 0 0 0 0 0 0 0\n"
			   "0 0 3 6 0 0 0 0 0\n"
			   "0 7 0 0 9 0 2 0 0\n"
			   "0 5 0 0 0 7 0 0 0\n"
			   "0 0 0 0 4 5 7 0 0\n"
			   "0 0 0 1 0 0 0 3 0\n"
			   "0 0 1 0 0 0 0 6 8\n"
			   "0 0 8 5 0 0 0 1 0\n"
			   "0 9 0 0 0 0 4 0 0\n");
	}
	void ReadIn(){
		read_sudoku();
	}
	int Solve(){
		int n=solve_sudoku();
		if(n<=1) printf("%d\n", n);
		else
			printf("2\n");
		if(n==1) output_sudoku();

	}
};

#endif