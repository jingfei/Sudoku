#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Sudoku
{
	public:
	  static const int SudokuSize = 81;
	  Sudoku();
	  void SetMap(const int set_map[]);
	  void ReadIn();
	  int GetZeroNum();
	  int GetElement(int index);
	  bool isCorrect();
	  void GiveQuestion();
	  void Solve();
	private:
	  int zero_position[SudokuSize];
	  int zero_num;
	  int ans_num;
	  int state;
	  int blank[SudokuSize];
	  int solution[SudokuSize];
	  int map[SudokuSize];
	  int rest_zero(int question[]);
	  void dig_hole(int board[], const int goal);
	  void backtracking(int to_track[]);
	  bool Check(int check_arr[]);
	  bool check_row(int to_check, int position, int board[]);
	  bool check_column(int to_check, int position, int board[]);
	  bool check_cell(int to_check, int position, int board[]);
};
