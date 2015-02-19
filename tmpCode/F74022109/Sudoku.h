#include<iostream>
using namespace std;

class Sudoku
{
public:
    Sudoku();
    void GiveQuestion();
    void ReadIn();
    void Solve();
    static const int magnitude_Sudoku = 81;
private:
    bool determinezero();
    int tempmap[magnitude_Sudoku], ans[magnitude_Sudoku];
    int cnt_ans;
    bool determineCorrect();
    bool checkUnity(int arr[]);

    void SolveIt();
};
