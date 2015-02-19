#define SIZE 9
#include <vector>
using namespace std;

class Sudoku{
	public:
		Sudoku();
		Sudoku(vector <int> board, int num);
		Sudoku(vector <int> board, int num, int X);

		void GiveQuestion();
		bool MoreCheck(vector <int> board, int site, int n);
		bool BoardFillin(vector <int>& board);
		
		void DigPreprocedure();
		void DigBoard();

		static int Ans;
		void ReadIn();
		void Take(int inx_board[]);
		void Solve();
		void SolveToQuestion();
		void SolveX();
		vector <int> GetBoard();
		int getAns();
		
		void print_board(vector <int> board);

	private:
		int store_board[SIZE][SIZE];
		int i, j, k, l;
		
		int num_reserve;
		int dig_board[SIZE][SIZE];
		int clear_order[SIZE*SIZE];

		int in_board[SIZE*SIZE];
		int counting[SIZE*SIZE];
		int found;
		bool tag[SIZE*SIZE][SIZE];
		void setAns(int A);
};