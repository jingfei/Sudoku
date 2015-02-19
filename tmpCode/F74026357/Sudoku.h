/*
	Sudoku.h //user
*/
#include <vector> //vector
using namespace std;
class Sudoku{
public:
	void GiveQuestion(); //for hw2_give_question
	void ReadIn(); //for hw2_solve
	void Solve(); //for hw2_solve
private:
	int table[81]; //one dimension
	int tmpTable[81];
	int countAns;
	vector<int> unsolvedIndex;
	void analyze(int index, int buffer[], int& countBuffer);
	void PrintTable(int[]);
	void One();
	void copyTable(int des[], int source[]);
	int Backtracking(int index);
	void GiveAnswer();
	void MakeTable(int index);
	int trySolve();
	void tryRead();
	void tryOne();
	void tryBacktracking(int index);
};
