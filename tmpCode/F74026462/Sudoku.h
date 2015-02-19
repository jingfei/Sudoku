#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
using namespace std;
class Sudoku
{
  public:
    Sudoku();
    void GiveQuestion();
    void ReadIn();
    void Solve();
    static const int sudokuSize=81;
    bool isCorrect(int map[sudokuSize]);
    void printSolution();
    int solveResult;
  private:
    int map[sudokuSize];
    bool checkUnity(int arr[]);
    int indexOfZero(int map[sudokuSize]);
    int indexOftmp;
    int tmp[sudokuSize];
    string data[10];
    int dataIndex;
    void backtracking();
    void getSolution();
    int Solution[sudokuSize];
};
