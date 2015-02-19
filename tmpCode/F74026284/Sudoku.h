#include<cstring>
    #include<cstdio>
    #include<algorithm>
	#include<ctime>
	#include<cstdlib>
    #define INF 1000000
    class Sudoku
    {
    public:
    Sudoku();
    void Solve();
    void buildDL();
    void insert(int i, int j);
    void remove(int p);
    void resume(int p);
    void DLX();
    void Initialization(int num);
    void GiveQuestion();
	void ReadIn();
    private:
	int depth;
	int head,size;
	int Answer;
 	int map[81];
	int res[81];
	};					