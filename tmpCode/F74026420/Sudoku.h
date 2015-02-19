#include<iostream>

class Sudoku{
public:
    Sudoku();
    void GiveQuestion();
    void ReadIn();
    void Solve();
    static const int SudokuSize= 81;
    static const int N= 9;
private:
    int fillInForward(int i);
    int fillInBackward(int i);
    void mapping(int i);
    void hollow();
    bool check(int element[], int n, int a);

    int element1[SudokuSize];
    int element2[SudokuSize];
    int possible[SudokuSize][N];
    int newPossible[SudokuSize][N];
    int possibleCount[SudokuSize];
    int group[N][N];
    int coun;
};
