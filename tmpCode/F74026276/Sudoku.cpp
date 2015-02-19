#include"Sudoku.h" 
#include<ctime>
#include<cstdlib>
#include<fstream>
#include<vector> 
#include<iomanip>
vector<int> Vmap(81);
vector<int> Vmap2(81);
vector<int> Voriginal(81);
bool isCorrect;
bool isCorrect2;

void Sudoku::GiveQuestion(){
	srand( time( NULL ) );
				
			int n[9][9];
			char out[9][9];
			int a, b, c, d, e, f, g, h, i;
			
			switch( 1 + rand() % 5 ){
			//ac bd eg fh i
				case 1:
					a = 1 + rand() % 2; c = 3 - a;
					b = 3 + rand() % 2; d = 7 - b;
					e = 5 + rand() % 2; g = 11 - e;
					f = 7 + rand() % 2; h = 15 - f; 
					i = 9;
					break;
			//ei  af  ch  dg b
				case 2: 
					e = 1 + rand() % 2; i = 3 - e;
					a = 3 + rand() % 2; f = 7 - a;
					c = 5 + rand() % 2; h = 11 - c;
					d = 7 + rand() % 2; g = 15 - d;
					b = 9;
					break;
			//ch ga ib df e
				case 3:
					c = 1 + rand() % 2; h = 3 - c ;
					g = 3 + rand() % 2; a = 7 - g;
					i = 5 + rand() % 2; b = 11 - i;
					d = 7 + rand() % 2; f = 15 - d;
					e = 9;
					break;
			//ai bf dg  eh c
				case 4:
					a = 1 + rand() % 2; i = 3 - a ;
					b = 3 + rand() % 2; f = 7 - b;
					d = 5 + rand() % 2; g = 11 - d;
					e = 7 + rand() % 2; h = 15 - e;
					c = 9;
					break;
			//bh eg cd if a
				case 5:
					b = 1 + rand() % 2; h = 3 - b ;
					e = 3 + rand() % 2; g = 7 - e;
					c = 5 + rand() % 2; d = 11 - c;
					i = 7 + rand() % 2; f = 15 - i;
					a = 9;
					break;
			}
			
			n[0][5] = a, n[1][8] = a, n[2][2] = a, n[3][3] = a, n[4][6] = a, n[5][0] = a, n[6][4] = a, n[7][7] = a, n[8][1] = a;
			n[0][3] = b, n[1][6] = b, n[2][0] = b, n[3][4] = b, n[4][7] = b, n[5][1] = b, n[6][5] = b, n[7][8] = b, n[8][2] = b;
			n[0][4] = c, n[1][7] = c, n[2][1] = c, n[3][5] = c, n[4][8] = c, n[5][2] = c, n[6][3] = c, n[7][6] = c, n[8][0] = c;
			n[0][2] = d, n[1][5] = d, n[2][8] = d, n[3][0] = d, n[4][3] = d, n[5][6] = d, n[6][1] = d, n[7][4] = d, n[8][7] = d;
			n[0][0] = e, n[1][3] = e, n[2][6] = e, n[3][1] = e, n[4][4] = e, n[5][7] = e, n[6][2] = e, n[7][5] = e, n[8][8] = e;
			n[0][1] = f, n[1][4] = f, n[2][7] = f, n[3][2] = f, n[4][5] = f, n[5][8] = f, n[6][0] = f, n[7][3] = f, n[8][6] = f;
			n[0][8] = g, n[1][2] = g, n[2][5] = g, n[3][6] = g, n[4][0] = g, n[5][3] = g, n[6][7] = g, n[7][1] = g, n[8][4] = g;
			n[0][6] = h, n[1][0] = h, n[2][3] = h, n[3][7] = h, n[4][1] = h, n[5][4] = h, n[6][8] = h, n[7][2] = h, n[8][5] = h;
			n[0][7] = i, n[1][1] = i, n[2][4] = i, n[3][8] = i, n[4][2] = i, n[5][5] = i, n[6][6] = i, n[7][0] = i, n[8][3] = i;
			
			//ofstream outFile( "output.txt", ios::out );
			
			for( int c = 0 ; c < 30 ; c++ ){
				n[ rand() % 9][ rand() % 9] = 0;
			}
		
			for( int i = 0 ; i < 9 ; i++ ){
				for( int j = 0; j < 9 ; j++){
					out[i][j] = n[i][j] + '0';
					cout << setw(2) << out[i][j];
					p[i][j] = n[i][j];
				}
				cout << endl;
			}	
}
void Sudoku::ReadIn(){
			//ifstream inFile( "output.txt", ios::in );
			
			char in[9][9];
				//-'0' 
				for( int i = 0 ; i < 9 ; i++ ){
					for( int j = 0 ; j < 9 ; j++ ){
						cin >> in[i][j];
						map[i][j] = in[i][j] - '0';
						map2[i][j] = map[i][j];
					}
				}
			Solve1( 0 );
			Solve2( 0 );
			turnArraytoVector();
}

int Sudoku::Solve1( int n ){
			if( map[n/9][n%9] != 0 ){
		        Solve1( n + 1 );
		    }
		    else{
		        for( int i = 1 ; i <= 9; i++ ){
		            if( Check(n, i) == true ){
		                map[n/9][n%9] = i;
		                Solve1( n + 1 );
		                if( isCorrect == true){
		                	return 0;
						}
		                map[n/9][n%9] = 0;
		            }
		        }
		    }
		    if( n >= 81 ){
		        isCorrect = true;
		        return 0;
		    }
}
int Sudoku::Solve2( int n ){
		    if( map2[n/9][n%9] != 0 ){
		        Solve2( n + 1 );
		    }
		    else{
		        for( int i = 9 ; i >= 1; i-- ){
		            if( Check2(n, i) == true ){
		                map2[n/9][n%9] = i;
		                Solve2( n + 1 );
		                if( isCorrect2 == true){
		                	return 0;
						}
		                map2[n/9][n%9] = 0;
		            }
		        }
		    }
		    if( n >= 81 ){
		        isCorrect2 = true;
		        return 0;
		    }
}
bool Sudoku::Check( int n, int N ){
			for( int i = 0; i < 9; i++ ){
		  		int j = n / 9;
		        if ( map[j][i] == N ){
		        return false;
				}
		    }
			for( int i = 0 ; i < 9 ; i++ ){
		        int j = n % 9;
		        if ( map[i][j] == N ){
		        	return false;
				}
		    }
		 
		    int x = n / 9 / 3 * 3;
		 	int y = n % 9 / 3 * 3;
		 
		    for( int i = x ; i < x + 3 ; i++ ){
		        for( int j = y ; j < y + 3 ; j++ ){
		            if( map[i][j] == N ){
		            	return false;
					}
		      	}
		    }
			return true;
}
bool Sudoku::Check2( int n, int N ){
			for( int i = 0; i < 9; i++ ){
		  		int j = n / 9;
		        if ( map2[j][i] == N ){
		        return false;
				}
		    }
			for( int i = 0 ; i < 9 ; i++ ){
		        int j = n % 9;
		        if ( map2[i][j] == N ){
		        	return false;
				}
		    }
		 
		    int x = n / 9 / 3 * 3;
		 	int y = n % 9 / 3 * 3;
		 
		    for( int i = x ; i < x + 3 ; i++ ){
		        for( int j = y ; j < y + 3 ; j++ ){
		            if( map2[i][j] == N ){
		            	return false;
					}
		      	}
		    }
			return true;
}
void Sudoku::turnArraytoVector(){
			//ifstream inFile( "output.txt", ios::in );
			char in[9][9];
			
			for( int i = 0 ; i < 9 ; i++ ){
				for( int j = 0 ; j < 9 ; j++ ){
					cin >> in[i][j];
					original[i][j] = in[i][j] - '0';
				}
			}
			//??頧riginal
			Voriginal.at(0) = original[0][0]; Voriginal.at(1) = original[0][1]; Voriginal.at(2) = original[0][2]; Voriginal.at(3) = original[0][3]; Voriginal.at(4) = original[0][4];Voriginal.at(5) = original[0][5]; Voriginal.at(6) = original[0][6]; Voriginal.at(7) = original[0][7]; Voriginal.at(8) = original[0][8];
			Voriginal.at(9) = original[1][0]; Voriginal.at(10) = original[1][1];Voriginal.at(11) = original[1][2]; Voriginal.at(12) = original[1][3];Voriginal.at(13) = original[1][4]; Voriginal.at(14) = original[1][5]; Voriginal.at(15) = original[1][6];Voriginal.at(16) = original[1][7];Voriginal.at(17) = original[1][8];
			Voriginal.at(18) = original[2][0]; Voriginal.at(19) = original[2][1];Voriginal.at(20) = original[2][2]; Voriginal.at(21) = original[2][3];Voriginal.at(22) = original[2][4];Voriginal.at(23) = original[2][5];Voriginal.at(24) = original[2][6];Voriginal.at(25) = original[2][7];Voriginal.at(26) = original[2][8];
			Voriginal.at(27) = original[3][0]; Voriginal.at(28) = original[3][1]; Voriginal.at(29) = original[3][2]; Voriginal.at(30) = original[3][3]; Voriginal.at(31) = original[3][4]; Voriginal.at(32) = original[3][5]; Voriginal.at(33) = original[3][6]; Voriginal.at(34) = original[3][7];Voriginal.at(35) = original[3][8];
			Voriginal.at(36) = original[4][0]; Voriginal.at(37) = original[4][1]; Voriginal.at(38) = original[4][2]; Voriginal.at(39) = original[4][3]; Voriginal.at(40) = original[4][4]; Voriginal.at(41) = original[4][5]; Voriginal.at(42) = original[4][6]; Voriginal.at(43) = original[4][7];Voriginal.at(44) = original[4][8];
			Voriginal.at(45) = original[5][0]; Voriginal.at(46) = original[5][1]; Voriginal.at(47) = original[5][2]; Voriginal.at(48) = original[5][3]; Voriginal.at(49) = original[5][4]; Voriginal.at(50) = original[5][5]; Voriginal.at(51) = original[5][6]; Voriginal.at(52) = original[5][7];Voriginal.at(53) = original[5][8];
			Voriginal.at(54) = original[6][0]; Voriginal.at(55) = original[6][1]; Voriginal.at(56) = original[6][2]; Voriginal.at(57) = original[6][3]; Voriginal.at(58) = original[6][4]; Voriginal.at(59) = original[6][5]; Voriginal.at(60) = original[6][6]; Voriginal.at(61) = original[6][7];Voriginal.at(62) = original[6][8];
			Voriginal.at(63) = original[7][0]; Voriginal.at(64) = original[7][1]; Voriginal.at(65) = original[7][2]; Voriginal.at(66) = original[7][3]; Voriginal.at(67) = original[7][4]; Voriginal.at(68) = original[7][5]; Voriginal.at(69) = original[7][6]; Voriginal.at(70) = original[7][7];Voriginal.at(71) = original[7][8];
			Voriginal.at(72) = original[8][0]; Voriginal.at(73) = original[8][1]; Voriginal.at(74) = original[8][2]; Voriginal.at(75) = original[8][3]; Voriginal.at(76) = original[8][4]; Voriginal.at(77) = original[8][5]; Voriginal.at(78) = original[8][6]; Voriginal.at(79) = original[8][7];Voriginal.at(80) = original[8][8];
			//??Vmap
			Vmap.at(0) = map[0][0]; Vmap.at(1) = map[0][1]; Vmap.at(2) = map[0][2]; Vmap.at(3) = map[0][3]; Vmap.at(4) = map[0][4];Vmap.at(5) = map[0][5]; Vmap.at(6) = map[0][6]; Vmap.at(7) = map[0][7]; Vmap.at(8) = map[0][8];
			Vmap.at(9) = map[1][0]; Vmap.at(10) = map[1][1];Vmap.at(11) = map[1][2]; Vmap.at(12) = map[1][3];Vmap.at(13) = map[1][4]; Vmap.at(14) = map[1][5]; Vmap.at(15) = map[1][6];Vmap.at(16) = map[1][7];Vmap.at(17) = map[1][8];
			Vmap.at(18) = map[2][0]; Vmap.at(19) = map[2][1];Vmap.at(20) = map[2][2]; Vmap.at(21) = map[2][3];Vmap.at(22) = map[2][4];Vmap.at(23) = map[2][5];Vmap.at(24) = map[2][6];Vmap.at(25) = map[2][7];Vmap.at(26) = map[2][8];
			Vmap.at(27) = map[3][0]; Vmap.at(28) = map[3][1]; Vmap.at(29) = map[3][2]; Vmap.at(30) = map[3][3]; Vmap.at(31) = map[3][4]; Vmap.at(32) = map[3][5]; Vmap.at(33) = map[3][6]; Vmap.at(34) = map[3][7];Vmap.at(35) = map[3][8];
			Vmap.at(36) = map[4][0]; Vmap.at(37) = map[4][1]; Vmap.at(38) = map[4][2]; Vmap.at(39) = map[4][3]; Vmap.at(40) = map[4][4]; Vmap.at(41) = map[4][5]; Vmap.at(42) = map[4][6]; Vmap.at(43) = map[4][7];Vmap.at(44) = map[4][8];
			Vmap.at(45) = map[5][0]; Vmap.at(46) = map[5][1]; Vmap.at(47) = map[5][2]; Vmap.at(48) = map[5][3]; Vmap.at(49) = map[5][4]; Vmap.at(50) = map[5][5]; Vmap.at(51) = map[5][6]; Vmap.at(52) = map[5][7];Vmap.at(53) = map[5][8];
			Vmap.at(54) = map[6][0]; Vmap.at(55) = map[6][1]; Vmap.at(56) = map[6][2]; Vmap.at(57) = map[6][3]; Vmap.at(58) = map[6][4]; Vmap.at(59) = map[6][5]; Vmap.at(60) = map[6][6]; Vmap.at(61) = map[6][7];Vmap.at(62) = map[6][8];
			Vmap.at(63) = map[7][0]; Vmap.at(64) = map[7][1]; Vmap.at(65) = map[7][2]; Vmap.at(66) = map[7][3]; Vmap.at(67) = map[7][4]; Vmap.at(68) = map[7][5]; Vmap.at(69) = map[7][6]; Vmap.at(70) = map[7][7];Vmap.at(71) = map[7][8];
			Vmap.at(72) = map[8][0]; Vmap.at(73) = map[8][1]; Vmap.at(74) = map[8][2]; Vmap.at(75) = map[8][3]; Vmap.at(76) = map[8][4]; Vmap.at(77) = map[8][5]; Vmap.at(78) = map[8][6]; Vmap.at(79) = map[8][7];Vmap.at(80) = map[8][8];
			//??Vmap2
			Vmap2.at(0) = map2[0][0]; Vmap2.at(1) = map2[0][1]; Vmap2.at(2) = map2[0][2]; Vmap2.at(3) = map2[0][3]; Vmap2.at(4) = map2[0][4];Vmap2.at(5) = map2[0][5]; Vmap2.at(6) = map2[0][6]; Vmap2.at(7) = map2[0][7]; Vmap2.at(8) = map2[0][8];
			Vmap2.at(9) = map2[1][0]; Vmap2.at(10) = map2[1][1];Vmap2.at(11) = map2[1][2]; Vmap2.at(12) = map2[1][3];Vmap2.at(13) = map2[1][4]; Vmap2.at(14) = map2[1][5]; Vmap2.at(15) = map2[1][6];Vmap2.at(16) = map2[1][7];Vmap2.at(17) = map2[1][8];
			Vmap2.at(18) = map2[2][0]; Vmap2.at(19) = map2[2][1];Vmap2.at(20) = map2[2][2]; Vmap2.at(21) = map2[2][3];Vmap2.at(22) = map2[2][4];Vmap2.at(23) = map2[2][5];Vmap2.at(24) = map2[2][6];Vmap2.at(25) = map2[2][7];Vmap2.at(26) = map[2][8];
			Vmap2.at(27) = map2[3][0]; Vmap2.at(28) = map2[3][1]; Vmap2.at(29) = map2[3][2]; Vmap2.at(30) = map2[3][3]; Vmap2.at(31) = map2[3][4]; Vmap2.at(32) = map2[3][5]; Vmap2.at(33) = map2[3][6]; Vmap2.at(34) = map2[3][7];Vmap2.at(35) = map[3][8];
			Vmap2.at(36) = map2[4][0]; Vmap2.at(37) = map2[4][1]; Vmap2.at(38) = map2[4][2]; Vmap2.at(39) = map2[4][3]; Vmap2.at(40) = map2[4][4]; Vmap2.at(41) = map2[4][5]; Vmap2.at(42) = map2[4][6]; Vmap2.at(43) = map2[4][7];Vmap2.at(44) = map[4][8];
			Vmap2.at(45) = map2[5][0]; Vmap2.at(46) = map2[5][1]; Vmap2.at(47) = map2[5][2]; Vmap2.at(48) = map2[5][3]; Vmap2.at(49) = map2[5][4]; Vmap2.at(50) = map2[5][5]; Vmap2.at(51) = map2[5][6]; Vmap2.at(52) = map2[5][7];Vmap2.at(53) = map[5][8];
			Vmap2.at(54) = map2[6][0]; Vmap2.at(55) = map2[6][1]; Vmap2.at(56) = map2[6][2]; Vmap2.at(57) = map2[6][3]; Vmap2.at(58) = map2[6][4]; Vmap2.at(59) = map2[6][5]; Vmap2.at(60) = map2[6][6]; Vmap2.at(61) = map2[6][7];Vmap2.at(62) = map[6][8];
			Vmap2.at(63) = map2[7][0]; Vmap2.at(64) = map2[7][1]; Vmap2.at(65) = map2[7][2]; Vmap2.at(66) = map2[7][3]; Vmap2.at(67) = map2[7][4]; Vmap2.at(68) = map2[7][5]; Vmap2.at(69) = map2[7][6]; Vmap2.at(70) = map2[7][7];Vmap2.at(71) = map[7][8];
			Vmap2.at(72) = map2[8][0]; Vmap2.at(73) = map2[8][1]; Vmap2.at(74) = map2[8][2]; Vmap2.at(75) = map2[8][3]; Vmap2.at(76) = map2[8][4]; Vmap2.at(77) = map2[8][5]; Vmap2.at(78) = map2[8][6]; Vmap2.at(79) = map2[8][7];Vmap2.at(80) = map[8][8];
}
void Sudoku::Solve(){
				
			if( map[0][0] != p[0][0] && map[0][1] != p[0][1] && map[0][2] != p[0][2] && map[0][3] != p[0][3] && map[0][4] != p[0][4] && map[0][5] != p[0][5] && map[0][6] != p[0][6] && map[0][7] != p[0][7] &&  map[0][8] != p[0][8] ){
				if( Vmap != Vmap2 ){
					Ans = 2;
					cout << Ans << endl;
				}
				else{	
					Ans = 1;
					cout << Ans << endl;
					for( int i = 0 ; i < 9 ; i++ ){
						for( int j = 0 ; j < 9 ; j++ ){
							cout << map[i][j];
						}
						cout << endl;
					}
				}
			}				
			else{
					Ans = 0;
					cout << Ans << endl; 
			}		
} 