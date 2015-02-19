#include <cstdlib>
#include <iostream>
#include <algorithm>  
 #include <string> 
class Sudoku {
 public:
        static const int colSize = 9;
        static const int rowSize = 9;
       
        Sudoku();
        void GiveQuestion(void);
        void ReadIn(void);
        void Solve(void);
        bool checkItem(int count,int map_buffer[colSize][rowSize]);
        void fillBlank(int count);
        void output_check(int check_num);
         
 private: 
              
        int a[9]; int num,num_q;
        int map[colSize][rowSize],new_map[colSize][rowSize];//前存最終棋盤.後存挖空題目 
        int map_question[colSize][rowSize],map_answer[colSize][rowSize];
        
 };
       
 
