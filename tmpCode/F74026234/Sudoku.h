#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<fstream> 
using namespace std;

class Sudoku
{
public:
       Sudoku();
       void ReadIn();
       void Solve();
       void GiveQuestion(); 
       
private:
        int k, ans[9][9], tmp[9][9], mut_ans, qus[9][9], qus_x[5][9][9];
        bool row[9][10], col[9][10], sqr[9][10];
        struct
        {
              int a;
              int b;
              int n[9];
              int num;
        }block[81];
        
        void backtracking(int len);
        void use_able();
        
}; 
