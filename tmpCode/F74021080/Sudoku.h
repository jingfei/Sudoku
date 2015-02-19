#include <iostream>
 class Sudoku {
 public:
 int mapping[81];
  Sudoku();
  Sudoku(const int init_map[]);
  int i,k;
  int con;
  int z;
  int store[70];
  int her;
  void answer();
  void GiveQuestion();
  void ReadIn();
  void Solve();
  void solvemap();
  void setMap(const int set_map[]); 
  int getElement(int index); 
  bool isCorrect(int numb,int r);
  static const int sudokuSize = 81;
  private:
  bool checkUnity(int Uni,int w); 
  int map[sudokuSize];

 };