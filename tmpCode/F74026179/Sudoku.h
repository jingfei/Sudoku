#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
class Sudoku {
public:
Sudoku();
void GiveQuestion();
void ReadIn();
void Solve();
void OAO();
int QAQ(int i);
int checkout(int i,int j);
private:
int map[81];
int answer,copy[81],ans[81][10];
};
