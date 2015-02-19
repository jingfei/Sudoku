#include "Sudoku.h"
#include <ctime>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

SudokuGen::SudokuGen() // 建構子(Constructor)
{
    srand(time(NULL)); //以物件初始化時間設定為亂數種子
    generator(); //以亂數方法產生數獨棋盤
}

void SudokuGen::generator() //亂數法產生新棋盤
{
    int tmp; //置換用暫存變數
    int numtmp[9] = {1,2,3,4,5,6,7,8,9}; //9宮格內的數字
    vector <int> board(81); //棋盤
    bool check = false; //表示棋盤是否成功產生

    for (i=0;i<81;i++){board[i] = 0;} //初始化棋盤(填入0)

    for (i=0;i<9;i++) //先填入左上角9宮格
//    1 2 3
//    4 5 6
//    7 8 9
    {
        board[i/3*9+i%3] = numtmp[i];
    }

    while(!check) //不斷嘗試直到符合規則的棋盤產生
    {
//        填入數字函式，嘗試失敗超過1000次會回傳false值
        check = board_put(board);
    }

    for (i=0;i<9;i++) //將1-9的數字順序打亂
    {
        j = rand() % 9;
        tmp = numtmp[i];
        numtmp[i] = numtmp[j];
        numtmp[j] = tmp;
    }

    for(i=0;i<81;i++) //將棋盤的數字序置換為新產生的數字序
    {
        board[i] = numtmp[board[i]-1];
    }

    for (i=0;i<SIZE;i++) //將結果寫入new_board變數
        for (j=0;j<SIZE;j++)
        {
            new_board[i][j] = board[i*SIZE+j];
        }

}

vector <int > SudokuGen::get_board() //輸出棋盤至vector變數
{
    vector < int > out_board (SIZE*SIZE);
    for (i=0;i<SIZE;i++)
        for (j=0;j<SIZE;j++)
        {
            out_board[i*SIZE+j] = new_board[i][j];
        }
    return out_board;
}

bool SudokuGen::check_rep(vector<int> board,int pos,int n)
{
    int i;
    for (i=0;i<9;i++)
    {
        if(board[pos/9*9+i]==n) //check橫排上數字是否有重複
        {
            return true; //有重複，回傳true
        }
        if(board[i*9+pos%9]==n) //check直排上數字是否有重複
        {
            return true; //有重複，回傳true
        }
    }
    return false;  //無重複，回傳false
}

bool SudokuGen::board_put(vector<int > &board) //填入數字函式
{
    int pos;
    int count1,count2; //計數器
    bool check = true; //check數字是否重複

    for (j=0;j<9;j++) //填入的數字1-9 (j+1的結果)
    {
        count2 = 0; //計算單一數字填入總共甞試錯誤次數
        for (i=1;i<9;i++) //依序將數字填入其餘八個小九宮格(左上角已經產生)
        {
            pos = i/3*27+i%3*3; //每個小九宮格的起始index
            count1 = 0; //計算單一數字填入甞試錯誤次數
            while (check==true)
            {
                k = rand() % 9;
                check = check_rep(board,pos+k/3*9+k%3,j+1);
                ++count1;
                ++count2;
                if (board[pos+k/3*9+k%3]==0 && check==false) //數字沒有重複，成功填入結束while loop
                {
                    board[pos+k/3*9+k%3] = j+1;
                    check = true;
                    break;
                }
                else
                {
                    check = true;
                }
                if (count1 > 100) // 錯誤超過100次，數字重填
                {
                    for (l=0;l<81;l++)
                    {
                        if (board[l]==j+1)
                        {
                            board[l]=0;
                        }
                    }
                    board[j/3*9+j%3]=j+1;
                    i = 0;
                    break;
                }
                if (count2 > 1000) // 錯誤超過1000次，回傳false並結束函式
                {
                    return false;
                }
            }
        }
    }
    return true; //成功填滿棋盤，回傳true
}

GiveQuestion::GiveQuestion(vector < int > board, int n_hole)
{
    srand(time(NULL));//以物件初始化時間設定為亂數種子
    for (i=0;i<SIZE*SIZE;i++) //建立0到80的數字序列
    {
        number_seres[i] = i;
    }
    for (i=0;i<SIZE;i++)//將輸入的數獨題目寫入至in_board變數
        for (j=0;j<SIZE;j++)
        {
            in_board[i][j] = board[i*SIZE+j];

        }
    board_dig(n_hole);//呼叫挖洞函式
}

void GiveQuestion::board_dig(int n_hole)
{
    int temp; //置換用暫存變數
    copy_board(); //呼叫複製函數
    for (i=0;i<81;i++) //將數字序列打亂
    {
        j = rand()%81;
        temp = number_seres[i];
        number_seres[i] = number_seres[j];
        number_seres[j] = temp;
    }
    for (i=0;i<n_hole;i++)
    {
        dig_board[number_seres[i]/SIZE][number_seres[i]%SIZE] = 0;
    }
}

vector < int > GiveQuestion::get_board()
/*輸出挖完洞的題目至vector變數*/
{
    vector < int > out_board(SIZE*SIZE);
    for (i=0;i<SIZE;i++)
        for (j=0;j<SIZE;j++)
        {
            out_board[i*SIZE+j] = dig_board[i][j];
        }
    return out_board;
}

void GiveQuestion::copy_board()
/*
複製棋盤函式
copy in_board into dig_board
*/
{
    for (i=0;i<SIZE;i++)
        for (j=0;j<SIZE;j++)
        {
            dig_board[i][j] = in_board[i][j];
        }
}

int SolveSudoku::Ans = 0; //數獨解個數計數器 (Global變數)
SolveSudoku::SolveSudoku(vector<int> board,int A)
{
    for (i=0;i<SIZE;i++)
        for (j=0;j<SIZE;j++)
        {
            in_board[i*SIZE+j] = board[i*SIZE+j];
        }
    //初始化 count, tag, Found變數
    for (i=0;i<SIZE;i++)
        for (j=0;j<SIZE;j++)
        {
            count[i*SIZE+j] = 0;
        }
    for (i=0;i<SIZE*SIZE;i++)
        for (j=0;j<SIZE;j++)
        {
            tag[i][j]=0;
        }
    Found = 0;
    setAns(A);
    sol();
}

void SolveSudoku::sol()
{
    int check, Max, iMax;
    /* 一般解法
    Found: 計算已知數字的個數
    count, tag: 掃描直、橫排又九宮格找出空格裡排除的數字
    */
    for (i=0;i<SIZE*SIZE;i++)
    {
        if (in_board[i])
        {
            Found++;
        }
        else
        {
            for (j=0;j<SIZE;j++)
            {
                if (in_board[(i/SIZE)*SIZE+j] && !tag[i][in_board[(i/SIZE)*SIZE+j]-1])
                {
                    count[i]++;
                    tag[i][in_board[(i/SIZE)*SIZE+j]-1] = true;
                }
                if (in_board[j*SIZE+i%SIZE] && !tag[i][in_board[j*SIZE+i%SIZE]-1])
                {
                    count[i]++;
                    tag[i][in_board[j*SIZE+i%SIZE]-1] = true;
                }
                check = in_board[((i/(SIZE*3))*3+j/3)*SIZE + ((i%SIZE)/3)*3+j%3] - 1;
                if (in_board[((i/(SIZE*3))*3+j/3)*SIZE + ((i%SIZE)/3)*3+j%3] && !tag[i][check])
                {
                    count[i]++;
                    tag[i][check] = true;

                }
            }
        }
    }
    /* 將排除數字有8個的空格填入正確的數字&增加Found個數
    並更新其直、橫排、九宮格內之空格的count, tag
    */
    for (i=0;i<SIZE*SIZE;i++)
    {
        if (!in_board[i] && count[i]==8)
        {
            count[i] = 0;
            Found++;
            for (j=0;j<SIZE;j++)
            {
                if(!tag[i][j])
                {
                    in_board[i] = j+1;
                    for (k=0;k<SIZE;k++)
                    {
                        if (!in_board[(i/SIZE)*SIZE+k] && !tag[(i/SIZE)*SIZE+k][j])
                        {
                            count[(i/SIZE)*SIZE+k]++;
                            tag[(i/SIZE)*SIZE+k][j] = true;
                        }
                        if (!in_board[k*SIZE+i%SIZE] && !tag[k*SIZE+i%SIZE][j])
                        {
                            count[k*SIZE+i%SIZE]++;
                            tag[k*SIZE+i%SIZE][j] = true;
                        }
                        check = ((i/(SIZE*3))*3+k/3)*SIZE + ((i%SIZE)/3)*3+k%3;
                        if (!in_board[check] && !tag[check][j])
                        {
                            count[check]++;
                            tag[check][j] = true;
                        }

                    }
                }
            }
            i = -1; //新填入空格數字就重新開始迴圈
        }

    }
    if (Found == 81) //全部空格數字都找到
    {
        setAns(Ans+1); //數獨解個數加1
    }
    else //一般解法不行，只好用暴力解了XD
    {
        //找出排除數字最多的空格
        Max = 0;
        iMax = -1;
        for (i=0;i<SIZE*SIZE;i++)
        {
            if (count[i] > Max)
            {
                Max = count[i];
                iMax = i;
            }
        }
        //暴力解開始!!
        //從排除數字最多的空格開始猜答案，把每個有可能的解法都跑一次
        for (j=0;j<SIZE;j++)
        {
            if(!tag[iMax][j])
            {
                in_board[iMax] = j+1;
                /*
                建立一個新的解題物件，並把目前數獨解個數代入
                若有新的解，將會更新數獨解(Ans)的個數，in_board則為其解
                若題目有多重解(Ans>1)，in_board只會紀錄下最後一組的數獨解
                */
                SolveSudoku *tmp = new SolveSudoku(get_board(),getAns());
                //刪除此物件，並開始下一個可能解(節省記憶體的用量)
                delete tmp;
            }
        }
    }
}

vector < int > SolveSudoku::get_board() //取得數獨解答
{
    vector <int> out_board(SIZE*SIZE);
    for (i=0;i<SIZE*SIZE;i++)
    {
        out_board[i] = in_board[i];
    }
    return out_board;
}

int SolveSudoku::getAns() //取得數獨解答的個數
{
    return Ans;
}

void SolveSudoku::setAns(int A)//設定數獨解答的個數
{
    Ans = A;
}