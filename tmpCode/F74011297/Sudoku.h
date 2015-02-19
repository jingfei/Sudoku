class Sudoku{
    public:
        Sudoku(void);
        void GiveQuestion(void);
        void ReadIn(void);
        void Solve(void);

        static const int SudokuSize = 81;
    private:
        int s[SudokuSize];
        int solve[SudokuSize];
        int row[SudokuSize];
        int col[SudokuSize];
        int cel[SudokuSize];
        int init_row[SudokuSize];
        int init_col[SudokuSize];
        int init_cel[SudokuSize];
        int zero[64];
        int zero_stack[64];
        int number;
        int check;
        int finish;

        void Check(int i);
        void Back(int i, int total);
};
