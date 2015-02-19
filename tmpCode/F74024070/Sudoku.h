#include <iostream>
#include <string>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;



class Sudoku {

	public:
	int cal(int question[],int,int&,int&);
	void GiveQuestion();
	void ReadIn();
	void Solve();
	int check(int question[]);
	int no_so();
	int check_no(int check_arr[]);
	int correct();
	private:
	int question[81];
	};



