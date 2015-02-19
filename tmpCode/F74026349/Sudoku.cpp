#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include "Sudoku.h" 

Sudoku::Sudoku(){
	memset( s , 0 , sizeof( s ) ) ; 
	memset( row , 0, sizeof( row ) ); 
	memset( col , 0 , sizeof( col ) ); 
	memset( sqr , 0 , sizeof( sqr ) ) ;  
	memset( prt , 0 ,sizeof( prt ) ) ;
	cnt = ans = 0 ; 
}	

Sudoku::Sudoku( bool zero ){
	memset( s , 0 , sizeof( s ) ) ; 
	memset( row , 0, sizeof( row ) ); 
	memset( col , 0 , sizeof( col ) ); 
	memset( sqr , 0 , sizeof( sqr ) ) ;  
	memset( prt , 0 ,sizeof( prt ) ) ;
	cnt = ans = 0 ; 
	
	
}

void Sudoku::ReadIn(){
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			scanf("%d",&s[i][j] ) ;
}

void Sudoku::print(){
	if( ans == 1 ){
		printf("1\n");
		for(int i=0;i<n;++i){
			for(int j=0;j<n-1;++j)
				printf("%d ",prt[i][j] ) ; 	
			printf("%d\n",prt[i][n-1]);
		}
	}
	else printf("%d\n",ans);
}

int Sudoku::find( int bit ){
	for(int i=1;i<=9;++i)
		if( bit & (1<<i) )
			return i ; 	
	return 0 ;
}

void Sudoku::dfs( int step , int MAX ){
	//printf("%d\n",step);
	if( step == cnt ){
		ans++ ; 
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				prt[i][j] = s[i][j] ; 
	}
	else{
		int i = table[step].x , j = table[step].y ; 
		row[i] |= 1 , col[j] |= 1 , sqr[i/3][j/3] |= 1 ;
		
		int bit = row[i] | col[j] | sqr[i/3][j/3] ;  
		bit = ~bit ;
		int now = bit & -bit ; 
		while( now <= (1<<9) ){
			if( ans > MAX )	return ;	
			
			row[i] |= now ;
			col[j] |= now ;
			sqr[i/3][j/3] |= now ; 
			s[i][j] = find( now ); 
		
			
			dfs( step + 1 , MAX ) ;
			
			row[i] ^= now ;
			col[j] ^= now ;
			sqr[i/3][j/3] ^= now ;
			
			bit ^= now ; 
			now = bit & -bit ; 
		}
	}
}

void Sudoku::GiveQuestion(){
	srand( time( 0 ) ) ;
	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
			table[cnt++] = Node( i , j ) ; 
	
	dfs( 0 , rand() % 40000 ) ;
	
	
	int tmp[10][10]; 
	int RAND = rand() % 4 ; 
	if( RAND == 0 ){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)
				tmp[i][j] = prt[i][j] ; 
		}
	}
	else if( RAND == 1 ){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)
				tmp[i][j] = prt[n-i-1][j] ; 
		}
	}
	else if( RAND == 2 ){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)
				tmp[i][j] = prt[i][n-j-1] ; 
		}
	}
	else{
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)
				tmp[i][j] = prt[n-i-1][n-j-1] ; 
		}
	}
	
	bool ok = 1 ; 
	while( ok ){
		memset( row , 0, sizeof( row ) ); 
		memset( col , 0 , sizeof( col ) ); 
		memset( sqr , 0 , sizeof( sqr ) ) ; 
		
		
		int x = rand() % 81 ;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
				s[i][j] = tmp[i][j] ;
			
		s[x/9][x%9] = 0 ;
		Solve( true ) ; 
		
		if( ans > 1 || ans < 1 ){
			for(int i=0;i<n;++i){
				for(int j=0;j<n-1;++j)
					printf("%d ",tmp[i][j] );
				printf("%d\n",tmp[i][n-1]);
			}
			ok = 0 ;
			break;
		}
		
		tmp[x/9][x%9] = 0 ;
	}
}

void Sudoku::Solve( bool Yes ){
	
	cnt = ans = 0 ;
	bool ok =  1;
	for(int i=0;i<n;++i) 
		for(int j=0;j<n;++j){
			if( s[i][j] == 0 )	table[cnt++] = Node( i , j ) ; 
			else{
				if( row[i] & (1<<s[i][j]) )	ok = 0 ;
				if( col[j] & (1<<s[i][j]) )	ok = 0 ;
				if( sqr[i/3][j/3] & (1<<s[i][j]) )	ok = 0 ;
				
				row[i] |= (1<<s[i][j]) ; 
				col[j] |= (1<<s[i][j]) ;
				sqr[i/3][j/3] |= (1<<s[i][j]) ;
			}
		}
	if( ok ) dfs( 0 , 1 ); 
}

void Sudoku::Solve(){
	
	cnt = ans = 0 ;
	bool ok =  1;
	for(int i=0;i<n;++i) 
		for(int j=0;j<n;++j){
			if( s[i][j] == 0 )	table[cnt++] = Node( i , j ) ; 
			else{
				if( row[i] & (1<<s[i][j]) )	ok = 0 ;
				if( col[j] & (1<<s[i][j]) )	ok = 0 ;
				if( sqr[i/3][j/3] & (1<<s[i][j]) )	ok = 0 ;
				
				row[i] |= (1<<s[i][j]) ; 
				col[j] |= (1<<s[i][j]) ;
				sqr[i/3][j/3] |= (1<<s[i][j]) ;
			}
		}
	if( ok ) dfs( 0 , 1 ); 
	print();
}

