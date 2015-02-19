#ifndef SUDOKU_H
#define SUDOKU_H
#include<vector>
#include<utility>
class Sudoku{
	public:
		Sudoku() :rowClear_() ,colClear_(), cellClear_(),status_(No) { }
		void ReadIn();
		void Solve();
		void GiveQuestion();
	private:
		enum SolveStatus{ No , One, Multi };
		bool inputValid_;
		static char input_[1000], *inputReader_;
		SolveStatus status_;
		bool rowClear_[9][10];
		bool colClear_[9][10];
		bool cellClear_[9][10];
		int tableInput_[9][9];
		int tableResult_[9][9];
		std::vector<std::pair<int,int> > blank_;

		inline int randOneToNine();
		inline int randZeroToEight();
		inline void readInt(int &);
		inline bool Test(int A,int B,int Try);
		void backTrackSearch(int blank = 0);
		bool generateCompleteTable(int blank = 0);
};
#endif
