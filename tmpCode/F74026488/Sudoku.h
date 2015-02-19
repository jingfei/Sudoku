#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
using namespace std;

using namespace std;
class Sudoku{
        public:
                Sudoku();
                void GiveQuestion();
                void ReadIn();
                void find_possible();
                int check(int,int,int);
                int fill();
                void fill_max();
                int Solve();
        private:
        int map[9][9];
        int sum_map[9][9];
        int num_map[9][9][9];
        int new_sum[9][9];
        int ans[1];
        int result_map[9][9];
};
