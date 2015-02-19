#define SIZE 9
#include <vector>
using namespace std;

class SudokuGen
{
    public:
        SudokuGen();
        void generator(); //亂數法產生新棋盤 (初始化時建構子就會呼叫一次)
        vector<int > get_board(); //輸出棋盤至vector變數
        bool check_rep(vector<int>,int,int); //偵測填入數字是否重複、符合規則，不符合會回傳false值
        bool board_put(vector<int>&); //填入數字函式，嘗試失敗超過1000次會回傳false值
    private:
        int new_board[SIZE][SIZE]; //棋盤
        int i,j,k,l; //迴圈用變數
};

class GiveQuestion
{
    public:
        GiveQuestion(vector < int >, int); //建構子
        void board_dig(int); //挖洞函式
        vector < int > get_board(); //輸出棋盤至vector變數
        void copy_board(); //複製棋盤函式
    private:
        int i,j; //迴圈用變數
        int in_board[SIZE][SIZE]; //輸入棋盤
        int dig_board[SIZE][SIZE]; //輸出棋盤(挖完洞)
        int number_seres[SIZE*SIZE]; //數字序列
};

class SolveSudoku
{
    public:
        static int Ans; //數獨解個數計數器 (這是個Global的變數)
        SolveSudoku(vector<int>,int); //建構子
        void sol(); //解題函式
        vector < int > get_board(); //取得數獨解
        int getAns(); //取得數獨解的個數

    private:
        int i,j,k; //迴圈用變數
        int in_board[SIZE*SIZE]; //數獨題目
        int count[SIZE*SIZE]; //每個空格排除數字個數
        int Found; //已知空格數字的個數
        bool tag[SIZE*SIZE][SIZE]; //每個空格排除的數字
        void setAns(int A); //設定Ans變數
};