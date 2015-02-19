#ifndef SUDOKU_H 
#define SUDOKU_H
#define SIZE 9
#include <vector>
using namespace std;

class Sudoku { 
public:
	Sudoku();

	void GiveQuestion();
	bool check_rep(vector<int>,int,int);
	bool map_put(vector<int>&);
//==========================================================	
        void DigSudoku(vector < int >, int);
        void map_dig(int); 
	void copy_map(); 	
//================================================================	
	void SolSudoku(vector<int>,int);
	static int Ans;
	    void Solve(); 
    vector < int > get_map(); 
    int getAns(); 
	
	
private:
	int new_map[SIZE][SIZE];
	int a,b,c,d;
//============================================================	
	int m,n;
   int in_map[SIZE][SIZE];
    int dig_map[SIZE][SIZE];
    int number_seres[SIZE*SIZE]; 
//=========================================================	
    int i,j,k;
    int count[SIZE*SIZE]; 
    int Found; 
    bool tag[SIZE*SIZE][SIZE];
    void setAns(int A); 
int in_map1[SIZE*SIZE];
} ;
	#endif