#include <iostream>
#include <vector>
class Sudoku {
	public:
		Sudoku();
		Sudoku(const int init_map[]);
		void setMap(const int set_map[]);
		int getElement(int index);
		void setElement(int index,int value);
		int getFirstZeroIndex();
		int isCorrect();
		static const int sudokuSize = 81;
		void GiveQuestion();
		void ReadIn();
		void Solve();
	private:
		int checkUnity(int arr[]);
		bool solve(Sudoku question, Sudoku & answer,int &count);
		int map[sudokuSize];
		void ConfirmCandidate(int index,int *valid);
		bool is_no_sol();
};
