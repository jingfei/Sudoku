//
//	Sudoku.cpp
//	sudoku
//	Created by Wemy Ju on 03/31/2014.
//

#include "Sudoku.h"

using namespace std;

Sudoku::Sudoku()
{
	memset(board, 0, sizeof(board));
    memset(checkR, 0, sizeof(checkR));
    memset(checkC, 0, sizeof(checkC));
    memset(checkB, 0, sizeof(checkB));
    numOfSol = 0;
}

void Sudoku::GiveQuestion()
{
	int i, j, k, l, m, tmp, randnum, temp[9];

	srand(time(NULL));

	for(i=0; i<9; ++i)
		temp[i] = i+1;

	for(i=0; i<8; ++i)
	{
		randnum = rand()%(8-i)+i+1;
		tmp = temp[i];
		temp[i] = temp[randnum];
		temp[randnum] = tmp;
	}

    for(k=0; k<3; ++k)
        for(l=0; l<3; ++l)
            for(i=0; i<3; ++i)
                for(j=0; j<3; ++j)
                    board[(j-k)%3+3*i][(i+l)%3+3*j] = temp[3*k+l];
    
	for(i=0; i<30; ++i)
		board[rand()%9][rand()%9] = 0;

    for(i=0; i<9; ++i)
    {
        for(j=0; j<9; ++j)
            printf("%d ", board[i][j]);
        printf("\n");
    }	
}

void Sudoku::ReadIn()
{
	for(int i=0; i<9; ++i)
		for(int j=0; j<9; ++j)
			scanf("%d", &board[i][j]);
}

void Sudoku::Solve()
{
	int i, j, only, value, count, holdR, holdC, holdV;
    
	for(i=0; i<9; ++i)
    {
        for(j=0, only=0, count=0; j<9; ++j)
        {
			if(board[j][i])
			{
                ++count;
                ++only;
                value = board[j][i];
                if(!checkC[value][j])
                    checkC[value][j] = 1;
                else
                {
                    printf("0\n");
					return;
                }
            }
            else
            {
                ++only;
                holdR = j;
                holdC = i;
                holdV = board[j][i];
            }
        }
        if(only == 1)
        {
            board[holdR][holdC] = holdV;
            checkR[holdV][holdR] = 1;
        }
        if(count<17)
        {
            printf("2\n");
            return;
        }
        
		for(j=0, only=0, count=0; j<9; ++j)
        {
			if(board[i][j])
			{
                ++count;
                ++only;
                value = board[i][j];
                if(!checkR[value][i] && !checkB[value][(i/3)*3+j/3])
                    checkR[value][i] = checkB[value][(i/3)*3+j/3] = 1;
                else
                {
                    printf("0\n");
					return;
                }
            }
            else
            {
                ++only;
                holdR = i;
                holdC = j;
                holdV = board[i][j];
                unknown.push(i);
				unknown.push(j);
            }
        }
        if(only == 1)
        {
            board[holdR][holdC] = holdV;
            checkC[holdV][holdC] = 1;
            unknown.pop();
            unknown.pop();
            --count;
        }
    }
    
                
                
                /*
				value = temp[i][j] = board[i][j];
                if(!checkR[value][i] && !checkC[value][j] && !checkB[value][(i/3)*3+j/3])
                    checkR[value][i] = heckC[value][j] = checkB[value][(i/3)*3+j/3] = 1;
                else
                {
                    printf("0\n");
					return;
                }
			}
			else	// for unknow number
			{
				unknown.push(i);
				unknown.push(j);
                holdR = i;
                holdC = j;
                holdV = j;
			}
        }
    
	if(count<17)
	{
		printf("2\n");
		return;
	}*/
    
	FindAnswer(81-count);
    
	if(!numOfSol)
        printf("0\n");
    else if(numOfSol > 1)
        printf("2\n");
    else
    {
        printf("1\n");
        for(i=0; i<9; ++i)
        {
            for(j=0; j<9; ++j)
                printf("%d ", board[i][j]);
            printf("\n");
        }
    }
}

void Sudoku::FindAnswer(int num)
{
	int x, y, i, j, curx, cury;
	if(!num)
    {
        ++numOfSol;
        for(i=0; i<9; ++i)
            for(j=0; j<9; ++j)
                board[i][j] = temp[i][j];
        return;
    }
    else
    {
        x = unknown.front();
        unknown.pop();
        y = unknown.front();
        unknown.pop();
        for(i=1; i<=9; ++i)
        {
            if(!checkR[i][x])
                if(!checkC[i][y])
                    if(!checkB[i][(x/3)*3+(y/3)])
                    {
                        checkR[i][x] = checkC[i][y] = checkB[i][(x/3)*3+(y/3)] = 1;
                        temp[x][y] = i;
                        FindAnswer(num-1);
                        checkR[i][x] = checkC[i][y] = checkB[i][(x/3)*3+(y/3)] = 0;
                        if(numOfSol > 1)
                            return;
                    }
        }
        unknown.push(x);
        unknown.push(y);
    }
}
