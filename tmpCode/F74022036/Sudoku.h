#include <iostream>
#include<time.h>
#include <cstdio>
#include<cstdlib>
#include<fstream>

using namespace std ;

class Sudoku
{
public:
    Sudoku () ;
    void ReadIn() ;
    void Solve() ;
    void Sudoku_Solve() ;
    int get_count () ;
    int compare_row( int num , int row) ;
    int compar_column( int num , int column) ;
    int compar_night( int num , int row , int column) ;
    void GiveQuestion() ;
private:
    int n[9][9];
    int ans_count ;
    int correct [9][9];
};
