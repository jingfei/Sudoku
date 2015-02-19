#include<iostream>
#include<vector>
class sudoku{
	public:
		sudoku();
		sudoku(const int init_map[]);
		void setMap(const int set_map[]);
		int getElement(int index);
		void setElement(int index,int value);
		int getFirstZeroIndex();
		bool isCorrect();
		static const int sudokuSize=81;
		int map[sudokuSize];
	private:
		bool checkUnity(int arr[]);
};

class Sudoku{
	public:
		Sudoku();
		void GiveQuestion();
		bool solve(sudoku question,sudoku & answer);
		void Solve();
		void ReadIn();
	private:
		sudoku question;
		sudoku answer;
		int solNum;
};
