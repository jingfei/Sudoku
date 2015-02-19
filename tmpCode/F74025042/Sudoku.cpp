#include "Sudoku.h"

Sudoku::Sudoku()
    {
		cnt_ans = 0;
	}
void Sudoku::GiveQuestion()
    {
        const int givenum[5][81]= {
        {0,0,5,3,0,0,0,0,0,8,0,0,0,0,0,0,2,0,0,7,0,0,1,0,5,0,0,4,0,0,0,0,5,3,0,0,0,1,0,0,7,0,0,0,6,0,0,3,2,0,0,0,8,0,0,6,0,5,0,0,0,0,9,0,0,4,0,0,0,0,3,0,0,0,0,0,0,9,7,0,0},
        {0,0,0,6,0,0,0,7,0,7,0,0,1,4,5,6,0,0,2,0,0,0,0,3,0,4,0,0,0,1,3,0,0,8,0,0,0,6,0,0,8,0,0,9,0,0,0,9,0,0,7,5,0,0,0,7,0,8,0,0,0,0,6,0,0,2,7,5,4,0,0,8,0,5,0,0,0,1,0,0,0},
        {0,0,0,6,0,0,1,4,2,0,2,6,0,0,0,0,0,0,7,0,0,0,0,4,0,0,9,0,0,0,0,0,6,2,0,0,0,6,0,9,0,1,0,5,0,0,0,5,3,0,0,0,0,0,9,0,0,4,0,0,0,0,7,0,0,0,0,0,0,8,1,0,8,4,2,0,0,7,0,0,0},
        {0,0,0,3,0,0,5,0,0,0,0,0,0,4,0,0,8,0,0,1,0,5,7,9,4,0,3,5,0,2,0,0,0,0,0,0,0,0,4,0,0,0,1,0,0,0,0,0,0,0,0,9,0,7,4,0,7,9,1,5,0,3,0,0,6,0,0,8,0,0,0,0,0,0,1,0,0,3,0,0,0},
        {9,1,0,0,0,0,0,5,0,0,0,3,0,0,9,0,2,1,0,0,0,4,0,2,0,0,0,0,8,0,0,4,0,9,0,2,0,0,0,0,7,0,0,0,0,5,0,4,0,6,0,0,1,0,0,0,0,5,0,6,0,0,0,2,5,0,7,0,0,8,0,0,0,3,0,0,0,0,0,9,5},
        };
        srand(time(NULL));
        int i = (rand()%5);
        for(int j=0; j<81; j++)
        {
            cout << givenum[i][j] << " ";
            if(j%9==8)
            {
                cout << endl ;
            }

        }
    }
void Sudoku::ReadIn()
    {
        for(int a=0; a<9; a++)
        {
            for(int b=0; b<9; b++)
                scanf("%d",&solvesudoku[a][b]);
        }
    }
void Sudoku::Solve()
    {
    	IWannaSolveIt(0,0);
    	if (cnt_ans == 0)
			cout << "0" << endl;
		else if (cnt_ans == 1)
		{
			cout << "1" << endl;
			for(int a=0; a<9; a++)
			{
				for(int b=0; b<9; b++)
				{
					cout << correct_ans[a][b] << " ";
				}
				cout << endl;
			}
		}
		else cout << "2" << endl;
    }
void Sudoku::IWannaSolveIt(int x, int y)
    {
        if(judge() != 1)
        {
        	cnt_ans++;

        	if (cnt_ans == 1)
			{
				for(int a=0; a<9; a++)
				{
					for(int b=0; b<9; b++)
					{
						correct_ans[a][b] = solvesudoku[a][b];
					}
				}
			}

            return;
        }

        if(solvesudoku[x][y] == 0)
        {
            for(int ans=1; ans<=9; ++ans)
            {
                if(judgenum(x, y, ans) == 1)
                {
                    solvesudoku[x][y] = ans;

                    if (y == 8)
                        IWannaSolveIt(x+1, 0);
                    else
                        IWannaSolveIt(x, y+1);

                    solvesudoku[x][y] = 0;
                }
            }
        }
        else
        {
            if (y == 8)
                IWannaSolveIt(x+1, 0);
            else
                IWannaSolveIt(x, y+1);
        }
    }
int Sudoku::judge()
    {
        for(int a=0; a<9; a++)
        {
            for(int b=0; b<9; b++)
                if(solvesudoku[a][b] == 0)
                    return 1;
        }

        return 0;
    }
int Sudoku::judgenum(int x, int y, int ans)
    {
    	int a, b;
        for(a=0; a<9; a++)
        {
            if(solvesudoku[a][y] == ans)
                return 0;
        }
        for(a=0; a<9; a++)
        {
            if(solvesudoku[x][a] == ans)
                return 0;
        }
        for(a=x/3*3; a<x/3*3+3; a++)
        {
            for(b=y/3*3; b<y/3*3+3; b++)
                if(solvesudoku[a][b] == ans)
                    return 0;
        }

        return 1;
    }