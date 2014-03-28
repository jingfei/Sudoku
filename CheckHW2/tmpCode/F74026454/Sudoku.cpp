#include "Sudoku.h"
#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

Sudoku::Sudoku()
{
    for (int i = 0; i < 9; ++i)
    for (int j = 0; j < 9; ++j){
        col[i][j] = 0;
        row[i][j] = 0;
        box[i][j] = 0;
    }
}

void Sudoku::ReadIn()
{
    char buffer[1000];
    int len = fread(buffer, sizeof(char), 1000, stdin);
    buffer[len] = 0;

    int buff_index = 0;
    for (int i = 0; i < 9; ++i){
        for (int j = 0; j < 9; ++j) {
            while (buffer[buff_index] == ' ' || buffer[buff_index] == '\n')
                ++buff_index;
            board[i][j] = buffer[buff_index++] - '0';
        }
    }
}
void Sudoku::Solve()
{
    nOfans = 0;

    for (int i = 0; i < 9; ++i)
    for (int j = 0; j < 9; ++j) {
        if (board[i][j]) {
        row[i][board[i][j]] = true;
        col[j][board[i][j]] = true;
        box[i/3*3+j/3][board[i][j]] = true;
        }
    }

    Pos_Index pos; pos.r = 0, pos.c = 0;

    pos = GetPosition(pos);
    Solve_Sudoku(pos);

    if (nOfans == 0)
        puts("0");
    else if (nOfans == 2)
        puts("2");
    else {
        puts("1");
        for (int i = 0; i < 9; ++i){
            for (int j = 0; j < 8; ++j)
                printf("%d ", ans[i][j]);
            printf("%d\n", ans[i][8]);
        }
    }
}
Pos_Index Sudoku::GetPosition(Pos_Index pos)
{
    for (; pos.r < 9; ++pos.r)
        for (pos.c = 0; pos.c < 9; ++pos.c)
            if (!board[pos.r][pos.c])
                return pos;
    return pos;
}
const int dir[9]= {9,6,7,8,5,3,4,2,1};
void Sudoku::Solve_Sudoku(Pos_Index pos)
{
    if (pos.r == 9) {
        ++nOfans;
        if (nOfans == 1) {
            for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                ans[i][j] = board[i][j];
        }
        return;
    }
    for (int i, j = 0; j < 9; ++j) {
        i = dir[j];
        if (!col[pos.c][i] && !row[pos.r][i] &&
            !box[pos.r/3*3+pos.c/3][i])
        {
            board[pos.r][pos.c] = i;
            col[pos.c][i] = true, row[pos.r][i] = true;
            box[pos.r/3*3+pos.c/3][i] = true;

            Pos_Index nxt_pos = GetPosition(pos);
            Solve_Sudoku(nxt_pos);
            if (nOfans == 2) return;

            board[pos.r][pos.c] = 0;
            col[pos.c][i] = false, row[pos.r][i] = false;
            box[pos.r/3*3+pos.c/3][i] = false;
        }
    }
}
void Sudoku::GiveQuestion()
{
    const int nOfQuestion = 5;

    srand(time(NULL));
    int n = rand() % nOfQuestion + 1;
    switch (n){
    case 1:
        printf("0 0 5 0 0 0 0 0 9\n\
0 0 0 0 0 0 0 0 0\n\
7 0 0 6 0 0 1 0 0\n\
0 0 0 0 0 4 0 0 0\n\
0 0 0 0 5 9 0 0 3\n\
2 0 0 0 0 0 0 7 0\n\
0 0 9 0 0 8 0 0 0\n\
0 0 0 7 0 0 2 6 0\n\
0 0 4 0 0 0 0 0 0\n");
        break;
    case 2:
        printf("0 0 0 8 0 0 0 4 0\n\
7 0 0 0 0 0 0 0 0\n\
0 5 0 0 0 0 0 0 9\n\
0 0 4 0 0 0 0 0 0\n\
0 0 0 0 7 0 0 0 5\n\
8 0 3 6 0 0 0 0 0\n\
2 9 0 0 5 0 0 0 0\n\
0 0 0 0 0 0 0 0 0\n\
0 0 0 4 0 0 8 3 0\n");
        break;
    case 3:
        printf("4 0 0 0 0 3 0 0 0\n\
0 6 0 0 0 0 0 9 0\n\
0 0 0 0 0 0 0 0 0\n\
0 0 0 0 0 0 0 0 3\n\
0 5 0 8 6 0 0 0 0\n\
0 0 8 0 0 2 0 0 1\n\
0 0 0 0 0 0 0 0 2\n\
0 0 0 0 0 0 6 5 0\n\
3 0 1 0 0 4 0 0 0\n");
        break;
    case 4:
        printf("0 0 7 0 0 0 0 0 0\n\
0 0 0 0 0 2 6 0 0\n\
0 9 0 0 0 0 0 0 0\n\
0 0 0 8 0 0 5 1 0\n\
0 0 0 0 0 0 2 0 0\n\
0 3 0 9 7 0 0 0 0\n\
0 0 0 4 0 0 0 0 3\n\
1 2 0 0 0 0 0 0 0\n\
6 0 5 0 0 0 0 0 0\n");
        break;
    case 5:
        printf("4 0 0 0 0 3 0 0 0\n\
0 6 0 0 0 0 0 9 0\n\
0 0 0 0 0 0 0 0 0\n\
0 0 0 0 0 0 0 0 3\n\
0 5 0 6 8 0 0 0 0\n\
0 0 8 0 0 2 0 0 1\n\
0 0 0 0 0 0 0 0 2\n\
0 0 0 0 0 0 6 5 0\n\
3 0 1 0 0 4 0 0 0\n");
        break;
    }
}
