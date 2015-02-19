#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
/*** classes ***/
class Blank{	
	public:
		int row;
		int col;
		int group;
		vector<int> possible;
	
		Blank(){}
		
		Blank(int r,int c,int g){
			row=r;
			col=c;
			group=g;
			for(int i=1;i<10;i++){
				possible.push_back(i);
			}
		}
};

class Sudoku{
	public:
		Sudoku(){
			srand(time(NULL));
		}
		
		void GiveQuestion();
		void ReadIn();
		void Solve();

	private:
		int SudokuMap[9][9];
		int AnswerMap[9][9];

		//print AnswerMap
		void Print();
		//Only-Method Solve
		void Only(int &res,vector<Blank> &list);

};