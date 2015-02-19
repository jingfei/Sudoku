#ifndef Sudoku_h
#define Sudoku_h
#include<utility>
#include<vector>
class Sudoku{ 
	typedef std::pair<int,int> Coordinate;
    public:
        Sudoku() : status_(N){}
        void GiveQuestion();
        void ReadIn();
        void Solve();
    private:	
		enum SearchResult{ N, One , Multi };
		void SearchAnswer( int hole );
        int sudoku_[9][9];
		int tempResult_[9][9];
		SearchResult status_;
        std::vector<Coordinate> hole_;
};

#endif
