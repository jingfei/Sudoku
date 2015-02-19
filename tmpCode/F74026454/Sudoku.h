#ifndef SUDOKU_H
#define SUDOKU_H

struct Pos_Index{
    int r;
    int c;
};

class Sudoku{

public:
    Sudoku();
    void ReadIn();
    void GiveQuestion();
    void Solve();

private:
    void Solve_Sudoku(Pos_Index);
    Pos_Index GetPosition(Pos_Index);

    int nOfans;

    bool col[9][9];
    bool row[9][9];
    bool box[9][9];

    int board[9][9];
    int ans[9][9];
};

#endif // SUDOKU_H
