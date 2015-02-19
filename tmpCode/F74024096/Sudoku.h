class Sudoku{
public:
	void GiveQuestion();
	void ReadIn();
	void Solve();
	int backtracking(int, int);
	void init();
	bool check(int, int, int);
private:
	int map[9][9], solution[9][9], ans[9][9];
	int cx[9][10], cy[9][10], cxy[3][3][10];
	int cnt;
};
