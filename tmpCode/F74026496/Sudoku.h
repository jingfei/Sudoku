#include<iostream>
#include<cstdlib>
#include<fstream>
using namespace std;
class Sudoku
{
public:
 int i, n,pro1[81],pro2[81],pro3[81],pro4[81],pro5[81],pro6[81],pro7[81];
 int arr[81],final[81];
 int num;

 void print(int arr[81]);
 void GiveQuestion();
 void ReadIn();
 bool ans_check(int x, int &ans);
 bool ques_check();
 void equal();
 void print();
 bool fill(int n);
 bool Solve();
};
