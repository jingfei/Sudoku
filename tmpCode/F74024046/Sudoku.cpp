#include<iostream>
#include<cstdlib>
#include<time.h>
#include<cstdio>
#include"Sudoku.h"
using namespace std ;

const int Sudoku::night[9][9] = {
{1,1,1,2,2,2,3,3,3},
{1,1,1,2,2,2,3,3,3},
{1,1,1,2,2,2,3,3,3},
{4,4,4,5,5,5,6,6,6},
{4,4,4,5,5,5,6,6,6},
{4,4,4,5,5,5,6,6,6},
{7,7,7,8,8,8,9,9,9},
{7,7,7,8,8,8,9,9,9},
{7,7,7,8,8,8,9,9,9}};
const int Sudoku::questionarray[20][81]={{3,5,0,0,0,9,8,4,0,0,0,9,4,0,7,3,0,2,0,0,2,1,0,0,7,0,0,8,0,0,7,0,0,1,3,0,4,0,3,8,0,6,2,0,7,0,2,5,0,0,4,0,0,6,0,0,8,0,0,3,5,0,0,9,0,1,5,0,2,4,0,3,4,9,0,0,0,2,8,0,0},
                                {0,0,6,0,0,1,0,0,4,0,4,0,0,0,7,0,5,9,3,0,9,5,6,0,1,0,8,0,8,7,0,0,2,9,0,3,5,0,0,4,0,9,0,0,2,9,0,2,1,0,0,4,8,0,7,0,5,0,3,6,8,0,1,8,1,0,7,0,0,0,9,0,6,0,0,9,0,0,5,0,0},
                                {8,0,0,0,0,3,4,0,0,0,6,0,0,0,4,7,0,8,0,3,7,6,8,0,0,2,5,0,0,6,9,0,0,0,8,7,1,8,0,3,0,7,0,5,4,7,4,0,0,0,5,9,0,0,3,7,0,0,9,8,6,4,0,2,0,4,1,0,0,0,7,0,0,0,8,4,0,0,0,0,3},
                                {6,0,0,0,0,4,5,0,0,5,0,9,0,1,0,3,0,7,3,2,0,8,0,5,1,6,0,0,5,6,2,0,0,7,0,0,0,0,4,5,0,1,2,0,0,0,0,2,0,0,7,4,5,0,0,1,8,3,0,9,0,7,2,2,0,5,0,7,0,8,0,1,0,0,3,1,0,0,0,0,5},
                                {5,0,0,7,0,6,0,9,0,0,7,8,9,0,0,2,6,0,0,6,9,2,0,0,3,0,7,0,0,1,0,0,3,7,0,6,2,0,0,8,0,7,0,0,9,7,0,4,1,0,0,5,0,0,4,0,5,0,0,9,6,7,0,0,8,3,0,0,4,9,1,0,0,2,0,6,0,1,0,0,5},
                                {7,0,0,6,0,0,0,8,0,0,9,0,0,5,0,0,0,1,0,0,0,0,4,0,3,0,0,0,2,0,7,0,0,4,0,0,0,0,5,8,0,1,6,0,0,0,0,3,0,0,9,0,2,0,0,0,6,0,1,0,0,0,0,8,0,0,0,7,0,0,5,0,0,1,0,0,0,2,0,0,6},
                                {0,0,4,0,0,3,0,9,0,0,0,0,0,0,5,8,0,0,1,0,0,0,0,6,0,2,0,0,0,7,4,0,9,0,6,0,2,0,0,0,0,0,0,0,1,0,5,0,8,0,2,3,0,0,0,3,0,7,0,0,0,0,4,0,0,9,5,0,0,0,0,0,0,8,0,3,0,0,7,0,0},
                                {0,3,0,0,1,0,0,0,6,8,0,0,2,0,0,0,0,9,0,0,0,0,5,0,4,0,0,0,0,7,0,4,3,5,0,0,9,0,0,0,0,0,0,0,8,0,0,2,6,7,0,1,0,0,0,0,1,0,8,0,0,0,0,5,0,0,0,0,7,0,0,3,2,0,0,0,6,0,0,1,0},
                                {0,0,0,0,5,0,0,9,0,0,8,0,0,1,0,0,7,0,4,0,0,0,0,6,0,0,2,0,0,3,7,8,0,5,0,0,0,1,0,0,0,0,0,6,0,0,0,9,0,4,2,3,0,0,6,0,0,3,0,0,0,0,4,0,7,0,0,9,0,0,2,0,0,4,0,0,6,0,0,0,0},
                                {0,0,1,0,8,0,0,0,7,0,0,6,0,0,5,0,0,4,3,9,0,2,0,0,1,0,0,2,0,0,0,0,0,0,3,0,5,0,0,0,0,0,0,0,6,0,4,0,0,0,0,0,0,8,0,0,5,0,0,9,0,6,2,7,0,0,1,0,0,5,0,0,9,0,0,0,2,0,8,0,0},
                                {4,0,0,1,0,0,0,0,5,0,0,9,2,0,7,0,0,3,0,0,0,0,3,0,0,2,0,0,0,0,0,0,0,4,1,2,0,0,3,0,8,0,6,0,0,1,5,4,0,0,0,0,0,0,0,2,0,0,4,0,0,0,0,7,0,0,8,0,9,1,0,0,9,0,0,0,0,3,0,0,6},
                                {0,6,0,8,0,0,5,0,0,0,0,5,6,0,0,4,0,0,4,0,8,0,2,5,0,9,7,0,0,4,1,8,0,2,6,0,0,0,3,0,0,0,7,0,0,0,9,6,0,7,2,3,0,0,6,3,0,5,4,0,8,0,2,0,0,7,0,0,8,1,0,0,0,0,2,0,0,1,0,5,0},
                                {0,2,6,0,0,4,7,0,9,0,8,0,2,6,0,3,0,0,0,0,3,0,5,0,0,0,2,0,4,0,7,0,5,0,0,3,3,6,0,0,0,0,0,9,4,9,0,0,6,0,3,0,7,0,6,0,0,0,1,0,8,0,0,0,0,8,0,7,6,0,4,0,7,0,5,4,0,0,9,3,0},
                                {6,0,0,0,0,7,0,0,2,4,0,0,0,0,2,3,6,0,9,3,0,6,0,1,4,0,0,0,8,4,7,1,0,0,0,9,0,9,0,0,0,0,0,1,0,1,0,0,0,3,9,7,8,0,0,0,3,1,0,6,0,4,8,0,4,1,9,0,0,0,0,6,7,0,0,8,0,0,0,0,5},
                                {3,0,0,0,6,0,5,0,0,2,0,6,0,0,9,0,3,0,5,0,0,4,2,0,7,0,6,7,0,0,9,0,0,0,8,0,1,9,0,3,0,2,0,4,7,0,3,0,0,0,7,0,0,5,8,0,1,0,4,5,0,0,3,0,2,0,7,0,0,4,0,8,0,0,4,0,3,0,0,0,2},
                                {0,3,0,6,0,0,8,0,1,4,0,0,1,0,0,0,0,6,6,2,0,0,9,8,0,5,0,0,0,2,0,0,5,0,1,0,7,0,6,8,0,9,4,0,3,0,1,0,3,0,0,6,0,0,0,6,0,2,3,0,0,8,9,1,0,0,0,0,4,0,0,2,2,0,8,0,0,6,0,3,0},
                                {0,0,4,3,0,6,0,0,2,0,3,5,7,0,0,0,1,6,0,0,6,0,4,0,0,0,7,0,4,0,2,0,7,0,0,1,2,0,1,0,0,0,5,0,4,6,0,0,4,0,1,0,2,0,5,0,0,0,1,0,6,0,0,4,6,0,0,0,3,1,9,0,1,0,0,9,0,4,2,0,0},
                                {0,6,8,0,1,7,2,0,9,0,0,2,0,3,0,0,7,0,0,0,9,2,0,0,0,0,3,0,9,0,7,0,0,0,8,0,2,8,0,3,0,5,0,9,7,0,5,0,0,0,9,0,2,0,1,0,0,0,0,2,8,0,0,0,3,0,0,7,0,9,0,0,9,0,6,5,8,0,7,4,0},
                                {0,1,0,7,0,9,0,3,0,0,4,0,0,0,8,0,0,5,5,0,8,0,1,0,2,7,0,4,7,0,6,0,5,1,0,0,0,0,5,0,0,0,7,0,0,0,0,9,1,0,7,0,4,3,0,3,4,0,7,0,6,0,2,6,0,0,3,0,0,0,8,0,0,8,0,5,0,6,0,9,0},
                                {4,0,0,0,0,2,8,0,0,0,0,2,0,9,0,5,3,0,3,0,9,5,1,0,0,0,2,7,4,0,9,0,0,3,0,0,8,0,0,3,0,1,0,0,7,0,0,3,0,0,7,0,2,6,2,0,0,0,4,9,6,0,3,0,1,5,0,6,0,4,0,0,0,0,4,8,0,0,0,0,1}};

void Sudoku::GiveQuestion()
{
    srand(time(NULL));
    i=rand()%20;


    for(j=0; j<81; j++)
    {
         cout << questionarray[i][j] << " " ;
	   if(j%9==8)
            cout << "\n" ;
    }
}
void Sudoku::ReadIn()
{
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
            scanf("%d",&solvearray[i][j]);
    }

}
void Sudoku::Solve()
{
   	result=0;
	 reSolve(0,0);
if(result==0){cout << result <<endl;}
   if(result==1){
        cout << result <<endl;
     for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++)
                cout << R[i][j] << " " ;
            cout << endl ;
        }
        }
   if(result>=2){cout << "2" <<endl; return;}

	
}
void Sudoku::reSolve(int x, int y)
{
    
    if (completeans()!=1)
    {
        result++;
         for(i=0; i<9; i++)
        {
            for(j=0; j<9; j++)
                R[i][j]=solvearray[i][j] ;
            cout << endl ;
        }
        
        
        return;
    }

         if (x >= 9) return;

    if (solvearray[x][y] != 0)
    {
        if (y == 8) reSolve(x+1, 0);
        else reSolve(x, y+1);
        return;
    }

    for (int num = 1; num <= 9; ++num)
    {
        if(analysis(x, y, num)==1)
        {
            solvearray[x][y] = num;
            if (y == 8) reSolve(x+1, 0);
            else reSolve(x, y+1);
            solvearray[x][y] = 0;
	   
        }
   }

}

int Sudoku::completeans()
{
    for(i=0; i<9; i++)
    {
        for(j=0; j<9; j++)
        {
            if(solvearray[i][j]==0)
                return 1;
        }
    }
}
int Sudoku::analysis(int x, int y, int num)
{
    for(p=0; p<9; p++)
    {
        if(num==solvearray[x][p])
        {
            return 0;
        }
    }
    for(o=0; o<9; o++)
    {
        if(num==solvearray[o][y])
        {
            return 0;
        }
    }
    if(night[x][y]==1)
    {
        if(num==solvearray[0][0])
        {
            return 0;
        }
        else if(num==solvearray[0][1])
        {
            return 0;
        }
        else if(num==solvearray[0][2])
        {
            return 0;
        }
        else if(num==solvearray[1][0])
        {
            return 0;
        }
        else if(num==solvearray[1][1])
        {
            return 0;
        }
        else if(num==solvearray[1][2])
        {
            return 0;
        }
        else if(num==solvearray[2][0])
        {
            return 0;
        }
        else if(num==solvearray[2][1])
        {
            return 0;
        }
        else if(num==solvearray[2][2])
        {
            return 0;
        }
    }
    if(night[x][y]==2)
    {
        if(num==solvearray[0][3])
        {
            return 0;
        }
        else if(num==solvearray[0][4])
        {
            return 0;
        }
        else if(num==solvearray[0][5])
        {
            return 0;
        }
        else if(num==solvearray[1][3])
        {
            return 0;
        }
        else if(num==solvearray[1][4])
        {
            return 0;
        }
        else if(num==solvearray[1][5])
        {
            return 0;
        }
        else if(num==solvearray[2][3])
        {
            return 0;
        }
        else if(num==solvearray[2][4])
        {
            return 0;
        }
        else if(num==solvearray[2][5])
        {
            return 0;
        }
    }
    if(night[x][y]==3)
    {
        if(num==solvearray[0][6])
        {
            return 0;
        }
        else if(num==solvearray[0][7])
        {
            return 0;
        }
        else if(num==solvearray[0][8])
        {
            return 0;
        }
        else if(num==solvearray[1][6])
        {
            return 0;
        }
        else if(num==solvearray[1][7])
        {
            return 0;
        }
        else if(num==solvearray[1][8])
        {
            return 0;
        }
        else if(num==solvearray[2][6])
        {
            return 0;
        }
        else if(num==solvearray[2][7])
        {
            return 0;
        }
        else if(num==solvearray[2][8])
        {
            return 0;
        }
    }
    if(night[x][y]==4)
    {
        if(num==solvearray[3][0])
        {
            return 0;
        }
        else if(num==solvearray[3][1])
        {
            return 0;
        }
        else if(num==solvearray[3][2])
        {
            return 0;
        }
        else if(num==solvearray[4][0])
        {
            return 0;
        }
        else if(num==solvearray[4][1])
        {
            return 0;
        }
        else if(num==solvearray[4][2])
        {
            return 0;
        }
        else if(num==solvearray[5][0])
        {
            return 0;
        }
        else if(num==solvearray[5][1])
        {
            return 0;
        }
        else if(num==solvearray[5][2])
        {
            return 0;
        }
    }
    if(night[x][y]==5)
    {
        if(num==solvearray[3][3])
        {
            return 0;
        }
        else if(num==solvearray[3][4])
        {
            return 0;
        }
        else if(num==solvearray[3][5])
        {
            return 0;
        }
        else if(num==solvearray[4][3])
        {
            return 0;
        }
        else if(num==solvearray[4][4])
        {
            return 0;
        }
        else if(num==solvearray[4][5])
        {
            return 0;
        }
        else if(num==solvearray[5][3])
        {
            return 0;
        }
        else if(num==solvearray[5][4])
        {
            return 0;
        }
        else if(num==solvearray[5][5])
        {
            return 0;
        }
    }
    if(night[x][y]==6)
    {
        if(num==solvearray[3][6])
        {
            return 0;
        }
        else if(num==solvearray[3][7])
        {
            return 0;
        }
        else if(num==solvearray[3][8])
        {
            return 0;
        }
        else if(num==solvearray[4][6])
        {
            return 0;
        }
        else if(num==solvearray[4][7])
        {
            return 0;
        }
        else if(num==solvearray[4][8])
        {
            return 0;
        }
        else if(num==solvearray[5][6])
        {
            return 0;
        }
        else if(num==solvearray[5][7])
        {
            return 0;
        }
        else if(num==solvearray[5][8])
        {
            return 0;
        }
    }
    if(night[x][y]==7)
    {
        if(num==solvearray[6][0])
        {
            return 0;
        }
        else if(num==solvearray[6][1])
        {
            return 0;
        }
        else if(num==solvearray[6][2])
        {
            return 0;
        }
        else if(num==solvearray[7][0])
        {
            return 0;
        }
        else if(num==solvearray[7][1])
        {
            return 0;
        }
        else if(num==solvearray[7][2])
        {
            return 0;
        }
        else if(num==solvearray[8][0])
        {
            return 0;
        }
        else if(num==solvearray[8][1])
        {
            return 0;
        }
        else if(num==solvearray[8][2])
        {
            return 0;
        }
    }
    if(night[x][y]==8)
    {
        if(num==solvearray[6][3])
        {
            return 0;
        }
        else if(num==solvearray[6][4])
        {
            return 0;
        }
        else if(num==solvearray[6][5])
        {
            return 0;
        }
        else if(num==solvearray[7][3])
        {
            return 0;
        }
        else if(num==solvearray[7][4])
        {
            return 0;
        }
        else if(num==solvearray[7][5])
        {
            return 0;
        }
        else if(num==solvearray[8][3])
        {
            return 0;
        }
        else if(num==solvearray[8][4])
        {
            return 0;
        }
        else if(num==solvearray[8][5])
        {
            return 0;
        }
    }
    if(night[x][y]==9)
    {
        if(num==solvearray[6][6])
        {
            return 0;
        }
        else if(num==solvearray[6][7])
        {
            return 0;
        }
        else if(num==solvearray[6][8])
        {
            return 0;
        }
        else if(num==solvearray[7][6])
        {
            return 0;
        }
        else if(num==solvearray[7][7])
        {
            return 0;
        }
        else if(num==solvearray[7][8])
        {
            return 0;
        }
        else if(num==solvearray[8][6])
        {
            return 0;
        }
        else if(num==solvearray[8][7])
        {
            return 0;
        }
        else if(num==solvearray[8][8])
        {
            return 0;
        }

    }

    return 1;
}

