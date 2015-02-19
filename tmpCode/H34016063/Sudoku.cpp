#include"Sudoku.h"

Sudoku::Sudoku()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            board[i][j]=0;
    }
}

void Sudoku::GiveQuestion()
{
    srand(time(NULL));
    for(int i=0;i<3;i++)
    {
        int a=rand()%9;
        int b=rand()%9;
        int first=rand()%9+1;
        board[a][b]=first;
    }
    generateBacktrack(board,0,0);
    int tmp[9][9];
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            tmp[i][j]=0;
    }
    do
    {
        for(int i=0;i<20;i++)
        {
            int a=rand()%9;
            int b=rand()%9;
            board[a][b]=0;
            board[b][a]=0;
        }
        duplicateMap(tmp,board);
        generateBacktrack(board,0,0);
    }while(!generateBacktrack(board,0,0));
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            board[i][j]=tmp[i][8-j];
    }
    PrintOut();
}

void Sudoku::ReadIn()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cin>>board[i][j];
    }
}

void Sudoku::PrintOut()
{

    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void Sudoku::Solve()
{
    int tmp[9][9];
    solve_num=0;
    solveBacktrack(0,0,tmp,solve_num);
    if(solve_num==1)
    {
        cout<<1<<endl;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
                cout<<tmp[i][j]<<" ";
            cout<<endl;
        }
    }
    else if(solve_num>1)
        cout<<2<<endl;
    else
        cout<<0<<endl;
}

bool Sudoku::generateBacktrack(int A[9][9],int x,int y)
{
    if(x>8)
        return true;
    if(!A[x][y])
    {
        bool row[10],col[10],box[10];//the row, the column, and the box which A[x][y] belog to
        queue<int> validnumber;
        memset(row,0,10);
        memset(col,0,10);
        memset(box,0,10);
        for(int i=0;i<9;i++)
        {
            row[A[x][i]]=1;
            col[A[i][y]]=1;
        }
        for(int i=3*(x/3);i<3*(x/3)+3;i++)
        {
            for(int j=3*(y/3);j<3*(y/3)+3;j++)
                box[A[i][j]]=1;
        }
        for(int i=1;i<=9;i++)
        {
            if(!row[i]&&!col[i]&&!box[i])
            {
                validnumber.push(i);
            }
        }
        while(!validnumber.empty())//if there is no valid number, we should go back and change the previous number
        {
            A[x][y]=validnumber.front();
            validnumber.pop();
            int next_x,next_y;
            if(y+1>8)
            {
                next_x=x+1;
                next_y=0;
            }
            else
            {
                next_x=x;
                next_y=y+1;
            }
            if(generateBacktrack(A,next_x,next_y))
                return true;
            A[x][y]=0;
        }
    }
    else
    {
        int next_x,next_y;
        if(y+1>8)
        {
            next_x=x+1;
            next_y=0;
        }
        else
        {
            next_x=x;
            next_y=y+1;
        }
        if(generateBacktrack(A,next_x,next_y))
                return true;
    }
    return false;
}

bool Sudoku::solveBacktrack(int x,int y,int tmp[9][9],int& solve_num)
{
    if(x>8)
    {
        if(solve_num==0)
        {
            for(int i=0;i<9;i++)
                for(int j=0;j<9;j++)
                    tmp[i][j]=board[i][j];
        }
        solve_num++;
        return true;
    }
    if(!board[x][y])
    {
        bool row[10],col[10],box[10];//the row, the column, and the box which board[x][y] belog to
        queue<int> validnumber;
        memset(row,0,10);
        memset(col,0,10);
        memset(box,0,10);
        for(int i=0;i<9;i++)
        {
            row[board[x][i]]=1;
            col[board[i][y]]=1;
        }
        for(int i=3*(x/3);i<3*(x/3)+3;i++)
        {
            for(int j=3*(y/3);j<3*(y/3)+3;j++)
                box[board[i][j]]=1;
        }
        for(int i=1;i<=9;i++)
        {
            if(!row[i]&&!col[i]&&!box[i])
            {
                validnumber.push(i);
            }
        }
        while(!validnumber.empty())//if there is no valid number, we should go back and change the previous number
        {
            board[x][y]=validnumber.front();
            validnumber.pop();
            int next_x,next_y;
            if(y+1>8)
            {
                next_x=x+1;
                next_y=0;
            }
            else
            {
                next_x=x;
                next_y=y+1;
            }
            solveBacktrack(next_x,next_y,tmp,solve_num);
            board[x][y]=0;
        }
    }
    else
    {
        int next_x,next_y;
        if(y+1>8)
        {
            next_x=x+1;
            next_y=0;
        }
        else
        {
            next_x=x;
            next_y=y+1;
        }
        solveBacktrack(next_x,next_y,tmp,solve_num);
    }
    return false;
}

void Sudoku::duplicateMap(int board_1[9][9],int board_2[9][9])
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            board_1[i][j]=board_2[i][j];
        }
    }
}
