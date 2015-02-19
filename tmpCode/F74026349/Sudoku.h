#ifndef _SUDOKU_H_ 
#define _SUDOKU_H_
#define n 9 

class Node{
	public :
		int x , y ; 
		Node(){	} ; 
		Node( int _x , int _y ){
			x = _x , y = _y; 
		
		}
} ; 

class Sudoku{
	public :
		Sudoku() ;
		Sudoku( bool zero ) ;
		void GiveQuestion();
		void ReadIn() ; 
		void Solve() ;	
		void Solve( bool Yes ) ;	
		void print();
		void dfs( int step , int MAX ) ; 
		int find( int bit ); 
		
	private : 
		Node table[90] ; 
		int s[11][11] , prt[11][11]; 
		int row[20] , col[20] , sqr[4][4] ; 
		int cnt , ans ; 
};

#endif 
