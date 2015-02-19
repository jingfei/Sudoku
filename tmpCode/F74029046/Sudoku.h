#include<iostream>
using namespace std;

class Sudoku{
public:
  Sudoku();
  static const int sudoku_rl_size=9;
  void GiveQuestion();
  void ReadIn();
  bool checkunity(int arr[]);
  bool isCorrect(int map[sudoku_rl_size][sudoku_rl_size]);
  void Solve();
  void SolveAnswer(int i,int j);
  void printanswer();

private:
  int map[sudoku_rl_size][sudoku_rl_size];
  int answer[sudoku_rl_size][sudoku_rl_size];
  int temp[sudoku_rl_size][sudoku_rl_size];
  int count;
  bool checkrow[sudoku_rl_size][sudoku_rl_size+1];
  bool checkcol[sudoku_rl_size][sudoku_rl_size+1];
  bool checkcell[sudoku_rl_size][sudoku_rl_size+1];
};


