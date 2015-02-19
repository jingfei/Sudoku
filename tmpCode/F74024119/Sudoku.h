#include<iostream>

using namespace std;
class Sudoku
{
public:

    Sudoku();
    void ReadIn();
    int trackspace();
    int check_C_R_N(int N,int x,int y);
    void pri();
    void SolTWO(int n);
    void Solve();
    void GiveQuestion();
private:
    int Map[10][10],spacenum[99],ANS[10][10];
    int NOFANS;

};




