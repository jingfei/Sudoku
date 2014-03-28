#include "Sudoku.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define DEBUG 1

const int Sudoku::section_map[81] = {
	1, 1, 1, 2, 2, 2, 3, 3, 3,
	1, 1, 1, 2, 2, 2, 3, 3, 3,
	1, 1, 1, 2, 2, 2, 3, 3, 3,
	4, 4, 4, 5, 5, 5, 6, 6, 6,
	4, 4, 4, 5, 5, 5, 6, 6, 6,
	4, 4, 4, 5, 5, 5, 6, 6, 6,
	7, 7, 7, 8, 8, 8, 9, 9, 9,
	7, 7, 7, 8, 8, 8, 9, 9, 9,
	7, 7, 7, 8, 8, 8, 9, 9, 9 };

const int Sudoku::sudoku_question[][81] = {
{ 0, 0, 0, 0, 0, 0, 0, 8, 0,
0, 0, 0, 0, 2, 0, 6, 4, 0,
0, 0, 6, 7, 0, 1, 0, 0, 0,
0, 0, 5, 8, 4, 0, 0, 0, 2,
9, 0, 0, 0, 3, 0, 0, 0, 7,
2, 0, 0, 0, 9, 5, 1, 0, 0,
0, 0, 0, 3, 0, 9, 8, 0, 0,
0, 5, 9, 0, 6, 0, 0, 0, 0,
0, 3, 0, 0, 0, 0, 0, 0, 0 }
,
{ 0, 0, 0, 0, 0, 0, 0, 0, 9,
0, 0, 0, 0, 0, 0, 6, 4, 0,
0, 0, 6, 7, 8, 1, 0, 0, 0,
3, 0, 5, 0, 0, 7, 0, 6, 0,
9, 0, 0, 0, 3, 0, 0, 0, 7,
0, 7, 0, 6, 0, 0, 1, 0, 8,
0, 0, 0, 3, 1, 9, 8, 0, 0,
0, 5, 9, 0, 0, 0, 0, 0, 0,
8, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 0, 0, 0, 0, 0, 6, 0, 8, 0,
0, 8, 0, 9, 0, 0, 0, 4, 1,
0, 9, 0, 0, 0, 0, 0, 0, 3,
0, 0, 5, 0, 4, 0, 0, 6, 2,
0, 0, 0, 0, 3, 0, 0, 0, 0,
2, 7, 0, 0, 9, 0, 1, 0, 0,
6, 0, 0, 0, 0, 0, 0, 7, 0,
7, 5, 0, 0, 0, 8, 0, 1, 0,
0, 3, 0, 5, 0, 0, 0, 0, 0 }
,
{ 0, 0, 0, 0, 0, 0, 7, 0, 0,
0, 0, 0, 0, 2, 0, 0, 4, 0,
0, 0, 6, 0, 0, 1, 0, 2, 0,
3, 0, 5, 8, 0, 7, 9, 0, 0,
9, 0, 0, 0, 3, 0, 0, 0, 7,
0, 0, 4, 6, 0, 5, 1, 0, 8,
0, 4, 0, 3, 0, 0, 8, 0, 0,
0, 5, 0, 0, 6, 0, 0, 0, 0,
0, 0, 1, 0, 0, 0, 0, 0, 0 }
,
{ 0, 2, 0, 0, 0, 6, 7, 0, 9,
5, 0, 0, 9, 0, 0, 0, 4, 0,
4, 0, 0, 0, 0, 0, 0, 0, 3,
0, 0, 5, 0, 0, 7, 0, 6, 0,
0, 0, 0, 0, 3, 0, 0, 0, 0,
0, 7, 0, 6, 0, 0, 1, 0, 0,
6, 0, 0, 0, 0, 0, 0, 0, 5,
0, 5, 0, 0, 0, 8, 0, 0, 4,
8, 0, 1, 5, 0, 0, 0, 9, 0 }
,
{ 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 8, 0, 9, 0, 0, 6, 4, 0,
0, 9, 0, 0, 8, 1, 5, 0, 0,
3, 0, 5, 0, 0, 7, 0, 0, 2,
0, 0, 0, 0, 3, 0, 0, 0, 0,
2, 0, 0, 6, 0, 0, 1, 0, 8,
0, 0, 2, 3, 1, 0, 0, 7, 0,
0, 5, 9, 0, 0, 8, 0, 1, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 0, 0, 0, 0, 0, 0, 7, 8, 0,
0, 0, 0, 9, 2, 0, 0, 4, 0,
4, 0, 0, 0, 0, 0, 0, 0, 3,
0, 0, 5, 0, 4, 7, 0, 6, 2,
0, 0, 0, 0, 3, 0, 0, 0, 0,
2, 7, 0, 6, 9, 0, 1, 0, 0,
6, 0, 0, 0, 0, 0, 0, 0, 5,
0, 5, 0, 0, 6, 8, 0, 0, 0,
0, 3, 1, 0, 0, 0, 0, 0, 0 }
,
{ 0, 2, 0, 0, 0, 6, 0, 0, 0,
5, 0, 0, 9, 0, 0, 0, 0, 0,
0, 9, 0, 0, 0, 0, 0, 2, 3,
0, 1, 0, 8, 0, 7, 0, 0, 2,
0, 0, 8, 0, 3, 0, 4, 0, 0,
2, 0, 0, 6, 0, 5, 0, 3, 0,
6, 4, 0, 0, 0, 0, 0, 7, 0,
0, 0, 0, 0, 0, 8, 0, 0, 4,
0, 0, 0, 5, 0, 0, 0, 9, 0 }
,
{ 0, 0, 0, 0, 5, 0, 0, 0, 0,
0, 8, 7, 9, 0, 3, 0, 0, 0,
4, 0, 6, 0, 0, 0, 0, 2, 0,
0, 1, 0, 0, 0, 7, 9, 6, 0,
0, 0, 0, 0, 3, 0, 0, 0, 0,
0, 7, 4, 6, 0, 0, 0, 3, 0,
0, 4, 0, 0, 0, 0, 8, 0, 5,
0, 0, 0, 2, 0, 8, 3, 1, 0,
0, 0, 0, 0, 7, 0, 0, 0, 0 }
,
{ 0, 0, 0, 0, 0, 0, 0, 8, 0,
5, 0, 0, 9, 0, 0, 6, 0, 0,
4, 0, 0, 7, 0, 0, 0, 2, 3,
0, 0, 5, 0, 0, 7, 0, 0, 2,
9, 0, 0, 0, 3, 0, 0, 0, 7,
2, 0, 0, 6, 0, 0, 1, 0, 0,
6, 4, 0, 0, 0, 9, 0, 0, 5,
0, 0, 9, 0, 0, 8, 0, 0, 4,
0, 3, 0, 0, 0, 0, 0, 0, 0 }
,
{ 7, 0, 8, 0, 0, 0, 3, 0, 0,
0, 0, 0, 2, 0, 1, 0, 0, 0,
5, 0, 0, 0, 0, 0, 0, 0, 0,
0, 4, 0, 0, 0, 0, 0, 2, 6,
3, 0, 0, 0, 8, 0, 0, 0, 0,
0, 0, 0, 1, 0, 0, 0, 9, 0,
0, 9, 0, 6, 0, 0, 0, 0, 4,
0, 0, 0, 0, 7, 0, 5, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0 }
,
{ 0, 0, 1, 6, 0, 0, 0, 0, 0,
0, 0, 3, 7, 0, 0, 0, 0, 0,
4, 5, 0, 0, 0, 9, 3, 0, 0,
3, 2, 0, 0, 0, 6, 5, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 9, 5, 0, 0, 0, 4, 1,
0, 0, 4, 1, 0, 0, 0, 3, 9,
0, 0, 0, 0, 0, 2, 7, 0, 0,
0, 0, 0, 0, 0, 8, 1, 0, 0 }
};

Sudoku::Sudoku()
{
	status = UNDETERMINED;
	cnt_question = sizeof(sudoku_question) / (sizeof(int) * 81);

	memset(x_used, 0, sizeof(x_used));
	memset(y_used, 0, sizeof(y_used));
	memset(section_used, 0, sizeof(section_used));
}

void Sudoku::GiveQuestion()
{
	srand(time(NULL));

	const int *pQuestion = sudoku_question[rand() % cnt_question];

	for (int i = 0; i < 9; i++)
	{
		for (int k = 0; k < 9; k++)
		{
			if (!k) printf("%d", pQuestion[i*9+k]);
			else printf(" %d", pQuestion[i*9+k]);
		}
		putchar('\n');
	}
}

void Sudoku::ReadIn()
{
	status = UNDETERMINED;

	for (int i = 0; i < 81; i++)
	{
		scanf("%d", &table[i]);

		int x = i / 9, y = i % 9;

		if (table[i] == EMPTY_CELL) continue;
		if (table[i] < EMPTY_CELL)
		{
			status = UNSOLVABLE;
			continue;
		}

		if (!x_used[x][table[i]]) x_used[x][table[i]] = true;
		else status = UNSOLVABLE;
		if (!y_used[y][table[i]]) y_used[y][table[i]] = true;
		else status = UNSOLVABLE;
		if (!section_used[section_map[i]][table[i]]) section_used[section_map[i]][table[i]] = true;
		else status = UNSOLVABLE;
	}
}

void Sudoku::Solve()
{
	if (status == UNSOLVABLE)
	{
		puts("0");
	}
	else
	{
		backtracking(0);

		if (status == MULTI_SOLUTION)
		{
			puts("2");
		}
		else if (status == ONE_SOULUTION)
		{
			puts("1");
			for (int i = 0; i < 9; i++)
			{
				for (int k = 0; k < 9; k++)
				{
					if (!k) printf("%d", answer[i*9+k]);
					else printf(" %d", answer[i*9+k]);
				}
				putchar('\n');
			}
		}
		else
		{
			status = UNSOLVABLE;
			puts("0");
		}
	}
}

void Sudoku::backtracking(int cur)
{
	if (cur == 81)
	{
		if (status == ONE_SOULUTION) status = MULTI_SOLUTION;
		else if (status == UNDETERMINED)
		{
			status = ONE_SOULUTION;

			memcpy(answer, table, sizeof(answer));
		}

		return;
	}

	while(cur < 81 && table[cur])
		cur++;

	if (cur == 81)
	{
		backtracking(cur);
		return;
	}

	int x = cur / 9, y = cur % 9;
	for (int i = 1; i <= 9 && status != MULTI_SOLUTION; i++)
	{
		if (x_used[x][i] || y_used[y][i] || section_used[section_map[cur]][i]) continue;

		x_used[x][i] = y_used[y][i] = section_used[section_map[cur]][i] = true;
		table[cur] = i;

		backtracking(cur+1);

		table[cur] = EMPTY_CELL;
		x_used[x][i] = y_used[y][i] = section_used[section_map[cur]][i] = false;
	}
}
