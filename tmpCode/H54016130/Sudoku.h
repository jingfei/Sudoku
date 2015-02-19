#include<iostream>
#include<cstdlib>
#include<cstring>
#include<ctime>
using namespace std;

class Sudoku{
	public:
		Sudoku();
		void setMap(const int set_map[]);
		void transin();
		void transout();
		void getMap();
		void dfs();
		void dig();
		void GiveQuestion();
		void ReadIn();
		void Solve();
		static const int rangesize=3;
	private:
		bool check(int y1,int y2,int x1,int x2);
		bool fin;
		int num_ans;
		int tempans[rangesize+1][rangesize+1][rangesize+1][rangesize+1];
		int map[rangesize+1][rangesize+1][rangesize+1][rangesize+1];
};
