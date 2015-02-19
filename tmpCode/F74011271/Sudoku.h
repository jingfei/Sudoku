#include <cstdlib>
#include <iostream>
#include <fstream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <vector>
class Sudoku {
	public:
		Sudoku();
		Sudoku(const int init_map[]);
		void setMap(const int set_map[]);
		int getElement(int index);

		void setElement(int index,int value);

		int getFirstZeroIndex();
		bool isCorrect();
		static const int sudokuSize = 81;
		
		bool Solve(Sudoku question, Sudoku & answer);
		void ReadIn();

	private:
		bool checkUnity(int arr[]);
		int map[sudokuSize];
};

class Map{
	public:
		
		void stablish_all ();
		
	private:
		int arr[9];
		int map[9][9];
		void updown ();
		void rightleft ();
		void set_unit ();
};