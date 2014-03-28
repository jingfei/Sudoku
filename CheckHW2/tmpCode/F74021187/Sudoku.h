#ifndef SUDOKU_H
#define SUDOKU_H
#include<vector>
#include<utility>
class Sudoku{
	public:
		Sudoku() { tableToSearch_ = &tableResult_; }
		void ReadIn();
		void Solve();
		void GiveQuestion();
	private:
		typedef std::vector<std::pair<int,int> >::iterator BlankIterator; 
		enum SolveStatus{ No , One, Multi };

		/* ReadIn() won't be thread safe if input[] is static */
		static char input_[1000], *inputReader_;
		int (*tableToSearch_)[9][9];
		int tabletemp_[9][9];
		int tableResult_[9][9];
		std::vector<std::pair<int,int> > blank_;

		void inline readInt(int &);
		SolveStatus dfs(BlankIterator&, BlankIterator&);
};
#endif

