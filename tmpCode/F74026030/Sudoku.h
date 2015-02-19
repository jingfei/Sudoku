
//using namespace std;
class Sudoku{
	public:
		Sudoku();
		void Solve();
		void ReadIn();
		void Recur(int n, int m);
		void GiveQuestion();
	private:
		int Q[9][9], A[9][9];
		bool no_answer, more_than_one, have_solved, change;
		bool row[9][10], column[9][10], region[3][3][10], changeable[9][9];
};