#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;
class Sudoku
{
	public:
		Sudoku(){}
		void GiveQuestion();
		void Solve();
		void ReadIn();
		void find_insert();
		bool rule(int num,int loop,int temp_loop);
		void print_result();
	private:
		int question,loop,temp_loop,new_map[9][9];
		int num,i,j,k,remainder_row,remainder_cl,square_start_row,square_start_cl;
		int* map;
		bool check;
		string line;
};