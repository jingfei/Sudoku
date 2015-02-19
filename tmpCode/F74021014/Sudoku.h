#include<iostream>

using namespace std;

typedef struct blank{
    int x;
    int y;
    int num[9];
    int amount;
    int point;
}Blank;
int ok=0;
Blank start[82]={0};
int blank_amount=0;

class Sudoku{
      public:
             int GiveQuestion();
             int ReadIn();
             int Solve();
             
             int check_fill(int x,int y,int map1[9][9]);
             int link(int,int);
             int get(int,int);
             int geta(int,int);
             int def();
      private:
              int map[9][9];
              int ans[9][9];
                    
};
             
