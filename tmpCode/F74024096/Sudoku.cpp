#include<iostream>
#include <string.h>
#include <time.h>
#include <cstdlib>
#include"Sudoku.h"

using namespace std;

void Sudoku::GiveQuestion()
{
	srand(time(0));
	int x = rand()%3;
	if(x==0)
	cout << "5 3 0 0 7 0 0 0 0\n\
6 0 0 1 9 5 0 0 0\n\
0 9 8 0 0 0 0 6 0\n\
8 0 0 0 6 0 0 0 3\n\
4 0 0 8 0 3 0 0 1\n\
7 0 0 0 2 0 0 0 6\n\
0 6 0 0 0 0 2 8 0\n\
0 0 0 4 1 9 0 0 5\n\
0 0 0 0 8 0 0 7 9\n";
	else if(x==1) cout <<
"0 0 5 3 0 0 0 0 0\n\
8 0 0 0 0 0 0 2 0\n\
0 7 0 0 1 0 5 0 0\n\
4 0 0 0 0 5 3 0 0\n\
0 1 0 0 7 0 0 0 6\n\
0 0 3 2 0 0 0 8 0\n\
0 6 0 5 0 0 0 0 9\n\
0 0 4 0 0 0 0 3 0\n\
0 0 0 0 0 9 7 0 0\n";
	else if(x==2) cout <<
"0 0 5 3 0 0 0 0 0\n\
8 0 0 0 0 0 0 2 0\n\
0 7 0 0 1 0 5 0 0\n\
4 0 0 0 0 5 3 0 0\n\
0 1 0 0 7 0 0 0 6\n\
0 0 3 2 0 0 0 8 0\n\
0 6 0 5 0 0 0 0 9\n\
0 0 4 0 0 0 0 0 0\n\
0 0 0 0 0 9 7 0 0\n";
}

void Sudoku::init()
{
	cnt = 0;
	memset(cx, 0, sizeof(cx));
	memset(cy, 0, sizeof(cy));
	memset(cxy, 0, sizeof(cxy));
	for(int i=0; i<9; i++)
		for(int j=0 ; j<9; j++)
			solution[i][j] = map[i][j];
}

void Sudoku::ReadIn()
{
	for(int i=0; i<9; i++)
		for(int j=0; j<9; j++)
			cin >> map[i][j];
	init();
}

void print(int solution[][9])
{
	for(int i=0; i<9; i++)
	{
		for(int j=0; j<9; j++)
		{
			cout << solution[i][j] << " ";
		}
		cout << endl;
	}
}

void Sudoku::Solve()
{
	int i, j;
	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			if(map[i][j] == 0) continue;
			if(!check(i, j, map[i][j]))
			{
				cout << 0 << endl;
				return;
			}
			cx[i][map[i][j]] = cy[j][map[i][j]] = cxy[i/3][j/3][map[i][j]] = 1;
		}
	}
	int cnt = backtracking(0, 0);
	cout << cnt << endl;
	if(cnt == 1)
		print(ans);
}

bool Sudoku::check(int x, int y, int val)
{
	return !cx[x][val] && !cy[y][val] && !cxy[x/3][y/3][val];
}

int Sudoku::backtracking(int x, int y)
{
	//cout << x << " " << y << endl;
	//print(solution);
	if(y == 9) x++, y=0;
	if(x == 9)
	{
		for(int i=0; i<9; i++)
			for(int j=0; j<9; j++)
				ans[i][j] = solution[i][j];
		cnt++;
		return cnt;
	}
	else if(map[x][y] != 0) backtracking(x, y+1);
	else
	{
		for(int i=1; i<=9; i++)
		{
			//if(check(solution, x, y, i))
			if(check(x, y, i))
			{
				cx[x][i] = cy[y][i] = cxy[x/3][y/3][i] = 1;
				solution[x][y] = i;
				if(backtracking(x, y+1) == 2) return 2;
				solution[x][y] = 0;
				if(cnt == 2) return 2;
				cx[x][i] = cy[y][i] = cxy[x/3][y/3][i] = 0;
			}
		}
	}
	return cnt;
}
