#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
using namespace std;

class Sudoku{
public:
  static const int Size=9;
  Sudoku();
  void GiveQuestion();
  void ReadIn();
  void Solve();
  void print();
private:
  int map[Size][Size], map2[9][9];
  int row[Size][9+1], column[Size][9+1], box[Size][9+1];
  struct space{
    int r, c, b, value;
  }S[Size*Size];
  int Sn;
  int findbox(int i, int j);
  int question[32][Size*Size];
};