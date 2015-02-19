class Sudoku
{
public:
    Sudoku();
    void GiveQuestion();
    void ReadIn();
    void Solve();
    int check(int i, int j);

private:
    int i, j, n, m, c, area, k, l, a, b;
    int map[9][9];
    int count1[10];
    int item[81], jtem[81];

};
