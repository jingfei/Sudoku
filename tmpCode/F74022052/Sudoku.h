#include <iostream>
#include <vector>
using namespace std;

struct Coordinate {
	int first;
	int second;
	Coordinate(int f, int s): first(f), second(s){}
};
class Sudoku {
public:
	Sudoku(){}
	void ReadIn();
	void GiveQuestion();
	void Solve();
private:
	int map[9][9];
	int mmap[9][9];
	vector <Coordinate> emp;
	enum Search{no, only, multi};
	Search status;
	Search SearchResult(int location);
};
