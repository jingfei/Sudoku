#include "Sudoku.h"  
using namespace std;
         Sudoku::Sudoku(){
        
                 //初始化 
                 int k,p; num=0;num_q=0; 
                  
                 for(k=0;k<colSize;++k)
                 {
                                       a[k]=0;
                                       for(p=0;p<rowSize;++p)
                                       {
                                                             new_map[k][p]=0;
                                                             map[k][p]=0;
                                                             map_question[k][p]=0;
                                                             map_answer[k][p]=0;
                                       }
                 }
                  
            /*     srand(time(NULL));
                 
                 int i;//隨機產生範圍1-9的數字且不能重複地存入陣列a中
             for(i=0;i<9;i++){a[i]=(rand()% 9)+1;}
             while(a[0]==a[1]){a[1]=(rand()% 9)+1;}
             while(a[0]==a[2] || a[1]==a[2]){a[2]=(rand()% 9)+1;}
             while(a[0]==a[3] || a[1]==a[3] || a[2]==a[3]){a[3]=(rand()% 9)+1;}
             while(a[0]==a[4] || a[1]==a[4] || a[2]==a[4] || a[3]==a[4]){a[4]=(rand()% 9)+1;}
             while(a[0]==a[5] || a[1]==a[5] || a[2]==a[5] || a[3]==a[5] || a[4]==a[5]){a[5]=(rand()% 9)+1;}
             while(a[0]==a[6] || a[1]==a[6] || a[2]==a[6] || a[3]==a[6] || a[4]==a[6] || a[5]==a[6]){a[6]=(rand()% 9)+1;}
             while(a[0]==a[7] || a[1]==a[7] || a[2]==a[7] || a[3]==a[7] || a[4]==a[7] || a[5]==a[7] || a[6]==a[7]){a[7]=(rand()% 9)+1;}              
             while(a[0]==a[8] || a[1]==a[8] || a[2]==a[8] || a[3]==a[8] || a[4]==a[8] || a[5]==a[8] || a[6]==a[8] || a[7]==a[8]){a[8]=(rand()% 9)+1;}  
             while(a[0]==a[9] || a[1]==a[9] || a[2]==a[9] || a[3]==a[9] || a[4]==a[9] || a[5]==a[9] || a[6]==a[9] || a[7]==a[9] || a[8]==a[9]){a[9]=(rand()% 9)+1;}
             
             int aa[9][9]={{a[7],a[8],a[6],a[0],a[2],a[1],a[4],a[5],a[3]},
                      {a[1],a[2],a[0],a[3],a[5],a[4],a[7],a[8],a[6]},
                      {a[4],a[5],a[3],a[6],a[8],a[7],a[1],a[2],a[0]},
                      {a[6],a[7],a[8],a[2],a[1],a[0],a[3],a[4],a[5]},
                      {a[0],a[1],a[2],a[5],a[4],a[3],a[6],a[7],a[8]},
                      {a[3],a[4],a[5],a[8],a[7],a[6],a[0],a[1],a[2]},
                      {a[8],a[6],a[7],a[1],a[0],a[2],a[5],a[3],a[4]},
                      {a[2],a[0],a[1],a[4],a[3],a[5],a[8],a[6],a[7]},
                      {a[5],a[3],a[4],a[7],a[6],a[8],a[2],a[0],a[1]}};
                for(k=0;k<9;k++){for(p=0;p<9;p++){map[k][p]=aa[k][p];}}//new_map[k][p]=aa[k][p];
           
        */ 
 
} //end of Sudoku()
                  
        void Sudoku::GiveQuestion(void){ //出題函數 
                 
int k,p;//給二維陣列跑索引值               
int sample1[9][9]={{8, 0, 0, 0, 0, 0, 0, 0, 0},//以下有三種題庫 
{0, 0, 3, 6, 0, 0, 0, 0, 0},
{0, 7, 0, 0, 9, 0, 2, 0, 0},
{0, 5, 0, 0, 0, 7, 0, 0, 0},
{0, 0, 0, 0, 4, 5, 7, 0, 0},
{0, 0, 0, 1, 0, 0, 0, 3, 0},
{0, 0, 1, 0, 0, 0, 0, 6, 8},
{0, 0, 8, 5, 0, 0, 0, 1, 0},
{0, 9, 0, 0, 0, 0, 4, 0, 0}};

int sample2[9][9]={{1, 0, 0, 3, 0, 0, 5, 0, 0},
{0, 2, 0, 0, 4, 0, 0, 6, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0},
{7, 0, 0, 2, 0, 4, 1, 0, 0},
{0, 8, 0, 1, 9, 0, 0, 2, 0},
{0, 0, 0, 0, 8, 0, 0, 0, 0},
{3, 0, 0, 5, 0, 0, 7, 0, 0},
{0, 4, 0, 0, 6, 0, 0, 8, 0},
{0, 0, 0, 0, 0, 0, 0, 0, 0}};

int sample3[9][9]={{8, 0, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 3, 6, 0, 0, 0, 0, 0},
{0, 7, 0, 0, 9, 0, 2, 0, 0},
{0, 5, 0, 0, 0, 7, 0, 0, 0},
{0, 0, 0, 0, 4, 5, 7, 0, 0},
{0, 0, 0, 1, 0, 0, 0, 3, 0},
{0, 0, 1, 0, 0, 0, 0, 6, 8},
{0, 0, 8, 5, 0, 0, 0, 1, 0},
{0, 9, 0, 0, 0, 0, 4, 0, 0}};

srand(time(NULL));
int key=(rand()% 30)+1;//隨機選題 
 
if(key<=10){
           for(k=0;k<9;++k){for(p=0;p<9;p++){new_map[k][p]=sample1[k][p];}}
           }
else if(key<=20 && key>10){
           for(k=0;k<9;++k){for(p=0;p<9;p++){new_map[k][p]=sample2[k][p];}}
           }
else  {
           for(k=0;k<9;++k){for(p=0;p<9;p++){new_map[k][p]=sample3[k][p];}}
           }
        
   /* 
          int n,x,y,i,j,item;
             
             srand(time(NULL));
             n=(rand()% 5)+65; //隨機留數以成為題目 
                
             while(n>0){
                      x=(rand()% 9)-1;
                      y=(rand()% 9)-1;
                                                                 
                      if(new_map[x][y]==0){
                                           new_map[x][y]=map[x][y];
                                           n--;
                                           }
                      }//end of while
             
             
             */ 
              
    for(k=0;k<9;++k)//印出題目
    {
                    for(p=0;p<9;++p)
                    {
                                    cout<<new_map[k][p]<<" "; 
                    }
                    cout<<endl;  
    }
     
}//end of GiveQuestion() 
  
//以下函數為解題相關函數            
 
 void Sudoku::ReadIn(void){//此函數可讀入使用者輸入的題目 
     
    string buf1,buf2,buf3,buf4,buf5,buf6,buf7,buf8,buf9;
    cout<<"請輸入題目: (每九個數字為一行,數字之間請以空格隔開,共輸入九行)"<<endl;
  
    getline(cin,buf1);
    getline(cin,buf2);
    getline(cin,buf3);
    getline(cin,buf4);
    getline(cin,buf5);
    getline(cin,buf6);
    getline(cin,buf7);
    getline(cin,buf8);
    getline(cin,buf9);
    
      for(int i=0,j=0;i<9;++i)
    { 
          
            map_question[0][i]=atoi((buf1.substr(j,1)).c_str());
            map_question[1][i]=atoi((buf2.substr(j,1)).c_str());
            map_question[2][i]=atoi((buf3.substr(j,1)).c_str());
            map_question[3][i]=atoi((buf4.substr(j,1)).c_str());
            map_question[4][i]=atoi((buf5.substr(j,1)).c_str());
            map_question[5][i]=atoi((buf6.substr(j,1)).c_str());
            map_question[6][i]=atoi((buf7.substr(j,1)).c_str());
            map_question[7][i]=atoi((buf8.substr(j,1)).c_str());
            map_question[8][i]=atoi((buf9.substr(j,1)).c_str());
            j=2+j;
             
    } 
             
   
}//end of ReadIn() 
 
 void Sudoku::Solve(void){
      
      fillBlank(0); 
      output_check(num);
      
 }//end of Solve() 
 
    
 bool Sudoku::checkItem(int count,int map_buffer[colSize][rowSize]){  
    int row = count / 9;  //計算列的索引 
    int col = count % 9;  //計算行的索引 
    int j;  
      
    for(j=0;j<9;++j){  
        if(map_buffer[row][j] == map_buffer[row][col] && j != col){  
            return false;  
        }  
    }  
     
    for(j=0;j<9;++j){  
        if(map_buffer[j][col] == map_buffer[row][col] && j != row){  
            return false;  
        }  
    }  
    
    //檢查九宮格  
    int tempRow = row / 3 * 3;  
    int tempCol = col / 3 * 3;  
    for(j = tempRow; j < tempRow + 3;++j){  
        for(int k = tempCol; k < tempCol + 3; ++k){  
            if(map_buffer[j][k] == map_buffer[row][col] && j != row && k != col){  
                return false;  
            }  
        }  
    }  
    return true;  
}//end of checkItem()



void Sudoku::fillBlank(int count){  
if(num>1)
     {
                 cout<<"2"<<endl;  //若找到2個解則直接結束程式 ,印出2代表多重解                  
                 exit(1);
     }
    if(count == 81){  
         num++; //計算有幾個解 
         
         for(int i = 0; i < 9; ++i)
         {
            for(int j =  0; j < 9; ++j)
            {
                    map_answer[i][j]=map_question[i][j];  //填入最終解答                           
            }
             
         }          
    return;   
    }  
    
    
    int row = count / 9;  
    int col = count % 9;  
    if(map_question[row][col] == 0){  
        for(int i = 1; i <= 9; ++i){  
            map_question[row][col] = i;   
            if(checkItem(count,map_question)){   
                fillBlank(count+1);  
            }
        }  
        map_question[row][col] = 0;  
    }else{  
        fillBlank(count+1);  
    }  
}//end of  fillBlank() 

void Sudoku::output_check(int check_num){//檢查是否為單一解 
if(num>1)
     {
                 cout<<"2"<<endl; //多重解                     
                 exit(1);
     }     
     else if(check_num==1) 
            { 
                  cout<<"1"<<endl;//單一解 
                  for(int i = 0; i < 9; ++i){
                             for(int j =  0; j < 9; ++j){
                                     cout<<map_answer[i][j]<<" ";
                             }
                  cout<<endl;
                  }
                  exit(1); 
            }
      else      
            {
                cout<<"0"<<endl;  //無解           
                exit(1);
                
            }
          
}//end of output_check() 

 

 
