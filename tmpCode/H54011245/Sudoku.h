#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cstdio>

class Sudoku
{
   public:
       Sudoku();
       Sudoku(const int init_map[]);
       void setMap(const int set_map[]);
       int getElement(int index);
       void setElement(int index, int value);
       int getFirstZeroIndex();
       bool isCorrect();
       bool isCorrect2();
       void push(int i);
       int pop();
       void display();
       static const int sudokuSize =81;
       void GiveQuestion();
       bool GiveQuestion1();
       bool GiveQuestion0();
       void ReadIn();
       void Solve();
       int Solve0();
       bool solve1(Sudoku question, Sudoku & answer);
       bool solve2(Sudoku question, Sudoku & answer);
       int gettemp();

   private:
       bool checkUnity(int arr[]);
       bool checkUnity2(int arr[]);
       int map[sudokuSize];
       int temp;
       int tempNumber[81];

};
