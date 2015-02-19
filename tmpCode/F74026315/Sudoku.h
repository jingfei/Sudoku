#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

struct Type_P{
	int num;
	int R;
	int C;
	int K;
	vector<int> P;
};
struct Type_Map{
	int m[9][9];
	bool row[9][9]; 
	bool col[9][9];	
	bool cell[9][9];
	Type_Map(){
		memset(m,0,81*sizeof(int));
		memset(row,0,81*sizeof(bool));
		memset(col,0,81*sizeof(bool));
		memset(cell,0,81*sizeof(bool));
	}
};

class Sudoku{
public:
	void GiveQuestion(void);
	void ReadIn(void);
	int Solve(void);
private:
	Type_Map Map,RMap;
	vector<Type_P> Waiting,RWaiting;
	vector<Type_Map> SMap;
	vector< vector<Type_P> > SWaiting;
	int CheckReadIn;
	void SetPossible(int,int);
	bool SetMap(int,int,int);
	bool FindPossible(int);
	bool DeleteOnePossible(int);
	void ReturnMap(Type_Map);
	
};
