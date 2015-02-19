#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;
class Sudoku {
	public:
		Sudoku();
		void ReadIn();
		void setMap(const int set_map[]);
		int getElement(int index);
		void Solve();
        void setElement(int index,int value);

		int getFirstZeroIndex();
		bool isCorrect();
		static const int sudokuSize = 81;
		void GiveQuestion();

	private:
	    void FindFirst(int a,vector<int>&);
		bool checkUnity(int arr[]);
		bool search();
		int solvee();
		int map[sudokuSize];
		int answer[sudokuSize];
		int count;
		int arr1[sudokuSize];
        int arr2[sudokuSize];
        int arr3[sudokuSize];
};
