class Sudoku{
	public:
	Sudoku();
	Sudoku(const int init_map[]);
	void setMap(const int set_map[]);
	int getElement(int index);
	bool isCorrect();
	static const int sudokuSize = 81;
	void setElement(int index,int value);
	int getFirstZeroIndex();
	void ReadIn();
	void GiveQuestion();
	bool recurSolve();
	void Solve();

	private:
	int ans;
	int pow2(int x);
	int map[sudokuSize];
	int tempMap[sudokuSize];
};