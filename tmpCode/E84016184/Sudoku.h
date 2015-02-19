class Sudoku{
public:
	void GiveQuestion();
	void ReadIn();
	void Solve();
private:
	int Q[9][9];
	int Ans[9][9];
	bool mx[9][10],my[9][10],mg[3][3][10];
	bool solvable;
	bool too_much;
	void Recur(int,int);
	void Save();
	void Print();
};
