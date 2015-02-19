#include "Sudoku.h"
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>

#define REVERSE_QUESTION 0

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
{ 0, 0, 0, 7, 0, 8, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0,
6, 0, 0, 0, 3, 0, 0, 0, 8,
0, 0, 0, 1, 0, 4, 0, 0, 0,
5, 0, 0, 0, 2, 0, 0, 0, 7,
0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 5, 0, 6, 0, 0, 0 }
};

Sudoku::Sudoku()
{
	Init();
}

void Sudoku::Init()
{
	status = UNDETERMINED;
	is_reverse = false;
	cnt_question = sizeof(sudoku_question) / (sizeof(int) * 81);

	memset(x_used, 0, sizeof(x_used));
	memset(y_used, 0, sizeof(y_used));
	memset(section_used, 0, sizeof(section_used));
}

void Sudoku::Analyze()
{
	for (int i = 0; status != UNSOLVABLE && i < 81; i++)
	{
		if (table[i] == EMPTY_CELL) continue;
		if (table[i] < EMPTY_CELL)
		{
			status = UNSOLVABLE;
			continue;
		}

		int x = i / 9, y = i % 9;

		if (!x_used[x][table[i]]) x_used[x][table[i]] = true;
		else status = UNSOLVABLE;
		if (!y_used[y][table[i]]) y_used[y][table[i]] = true;
		else status = UNSOLVABLE;
		if (!section_used[section_map[i]][table[i]]) section_used[section_map[i]][table[i]] = true;
		else status = UNSOLVABLE;
	}

	int cnt_tail = 0, cnt_head = 0;
	for (int i = 0, k = 80; status != UNSOLVABLE && i < k; i++, k--)
	{
		if (table[i] != EMPTY_CELL) cnt_head++;
		if (table[k] != EMPTY_CELL) cnt_tail++;
	}

	if (cnt_tail >= cnt_head)
		is_reverse = true;

	printf("is_reverse = %d\n", is_reverse);
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
		scanf("%d", &table[i]);

	Analyze();
}

void Sudoku::Solve()
{
	if (status == UNSOLVABLE)
		printf("0\n");
	else
	{
		if (is_reverse)
			backtracking_tail(80);
		else
			backtracking_head(0);

		if (status == MULTI_SOLUTION)
			printf("2\n");
		else if (status == ONE_SOULUTION)
		{
			printf("1\n");
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
			printf("0\n");
		}
	}
}

void Sudoku::backtracking_tail(int cur)
{
	if (cur == -1)
	{
		if (status == ONE_SOULUTION) status = MULTI_SOLUTION;
		else if (status == UNDETERMINED)
		{
			status = ONE_SOULUTION;

			memcpy(answer, table, sizeof(answer));
		}

		return;
	}

	while(cur >= 0 && table[cur])
		cur--;

	if (cur == -1)
	{
		backtracking_tail(cur);
		return;
	}

	int x = cur / 9, y = cur % 9;
	for (int i = 1; i <= 9 && status != MULTI_SOLUTION; i++)
	{
		if (x_used[x][i] || y_used[y][i] || section_used[section_map[cur]][i]) continue;

		x_used[x][i] = y_used[y][i] = section_used[section_map[cur]][i] = true;
		table[cur] = i;

		backtracking_tail(cur-1);

		table[cur] = EMPTY_CELL;
		x_used[x][i] = y_used[y][i] = section_used[section_map[cur]][i] = false;
	}
}

void Sudoku::backtracking_head(int cur)
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
		backtracking_head(cur);
		return;
	}

	int x = cur / 9, y = cur % 9;
	for (int i = 1; i <= 9 && status != MULTI_SOLUTION; i++)
	{
		if (x_used[x][i] || y_used[y][i] || section_used[section_map[cur]][i]) continue;

		x_used[x][i] = y_used[y][i] = section_used[section_map[cur]][i] = true;
		table[cur] = i;

		backtracking_head(cur+1);

		table[cur] = EMPTY_CELL;
		x_used[x][i] = y_used[y][i] = section_used[section_map[cur]][i] = false;
	}
}
