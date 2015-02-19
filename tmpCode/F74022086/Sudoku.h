#include <iostream>
using namespace std;

class Sudoku {
	int Board[9][9], Ans[9][9], Solved, Available[9][9][10], I[81], J[81], N;

	public:

	Sudoku(); /* a sudoku board is born and initialized */
	void GiveQuestion();		
	void Output(); /* output the sudoku board to stdout */
	void Heuristics( );/* Heuristics: Fewer-Option First, Hard-First or Easy-Last Policy */
	void QuickSort(int, int);/* Unique-First Policy: Sorting the heuristics (Optioin Count) */
	int Split(int, int);/* Pivot-Spliting for Quick Sorting */
	int Choose(int, int);/* Randomly Choosing an available digit */
	int ReadIn();/* Read a sudoku from stdin */
	int ReadIn(char[]);/* Read a sudoku from file, say, question.txt */
	int Solve();/* Solve a sudoku from file question.txt */
	int Solve1();/* Solve a sudoku from file question.txt */
};
