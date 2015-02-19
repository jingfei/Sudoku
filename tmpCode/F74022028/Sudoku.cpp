#include "Sudoku.h"

		void Sudoku::ReadIn(){
			char temp;
			for(int i=0; i<81; i++){
				cin >> temp;
				if(temp != ' ') num[i] = temp - '0';
			}
		}
		
		void Sudoku::Solve(){
			ans = 0;
			DFS(0);
			Out();
		}
		
		void Sudoku::GiveQuestion(){
			srand((unsigned)time(NULL));
			int i;
			i = rand() % 6 + 1;
			switch(i){
				case 1:
					cout << "7 4 0 6 3 0 0 0 0\n0 0 0 0 0 0 0 0 0\n0 0 5 2 0 0 0 3 0\n6 0 3 0 0 5 0 4 0\n0 1 0 0 6 0 0 8 0\n0 8 0 7 0 0 2 0 3\n0 7 0 0 0 2 9 0 0\n0 0 0 0 0 0 0 0 0\n0 0 0 0 4 3 0 1 6" << endl;
					break;
				case 2:
					cout << "8 2 0 7 4 0 0 0 0\n0 0 0 0 0 0 0 0 0\n0 0 9 8 0 0 0 1 0\n6 0 8 0 0 5 0 4 0\n0 5 0 0 2 0 0 8 0\n0 7 0 4 0 0 3 0 1\n0 9 0 0 0 2 7 0 0\n0 0 0 0 0 0 0 0 0\n0 0 0 0 9 1 0 3 4" << endl;
					break;
				case 3:
					cout << "0 3 1 7 0 4 0 0 0\n0 0 4 0 1 0 8 0 7\n0 6 0 5 0 0 0 1 9\n2 0 0 0 6 0 3 0 5\n0 9 0 1 0 2 0 6 0\n3 0 6 0 5 0 0 0 4\n5 4 0 0 0 1 0 8 0\n6 0 3 0 2 0 9 0 0\n0 0 0 3 0 9 5 7 0" << endl;
					break;
				case 4:
					cout << "0 8 6 4 9 0 1 2 0\n5 0 2 0 0 0 6 0 9\n0 0 0 0 2 0 0 0 0\n0 7 0 0 0 4 0 0 0\n2 0 0 0 6 0 0 0 4\n0 0 0 3 0 0 0 1 0\n0 0 0 0 4 0 0 3 0\n6 0 5 0 0 0 0 0 1\n0 4 9 0 8 1 0 0 6" << endl;
					break;
				case 5:
					cout << "0 0 7 0 0 3 8 0 0\n6 0 0 4 5 0 0 0 7\n0 0 0 0 0 0 0 0 2\n0 9 8 0 3 0 0 0 4\n0 5 6 0 8 0 9 3 0\n3 0 0 0 1 0 2 5 0\n0 0 0 0 0 0 0 0 0\n9 0 3 0 7 1 0 0 5\n0 0 0 6 0 0 7 0 0" << endl;
					break;
				case 6:
					cout << "2 0 0 0 0 1 0 6 8\n6 0 0 4 0 0 0 0 9\n0 5 0 0 0 0 7 0 2\n0 0 4 8 0 6 0 0 0\n0 1 0 0 0 0 0 3 0\n0 0 0 1 0 3 8 0 0\n7 0 6 0 0 0 4 0 0\n4 0 0 0 0 9 6 0 1\n1 9 0 7 0 0 0 0 0" << endl;
					break;
			}
		}
		
		void Sudoku::Out(){
			if(ans == 1){
				cout << "1" << endl;
				for(int i=0; i<81; i++){
					if((i/9 != 0) && (i%9 == 0))cout << endl;
					cout << ansnum[i] << " ";
				}
			}
			else{
				if(ans == 0) cout << "0";
				if(ans > 1) cout << "2";
			}
			cout << endl;
		}
		
		bool Sudoku::CheckZero(){
			for(int i=0; i<81; i++)
				if(num[i] == 0) return false;
			return true;
		}
		
		bool Sudoku::Check(int index, int n){
			int row = index / 9;
			int column = index % 9;
			
			for(int i=row*9; i<row*9+9 ;i++)
				if(num[i] == n) return false;
				
			for(int i=column; i<column+81; i+=9)
				if(num[i] == n) return false;
			
			int i = row / 3 * 3 * 9 + column / 3 * 3;
			if(num[i] == n || num[i+1] == n || num[i+2] == n || num[i+9] == n || num[i+10] == n || num[i+11] == n || num[i+18] == n || num[i+19] == n || num[i+20] == n) return false;
			
			return true;
		}
		
		int Sudoku::DFS(int index){
			if(index > 80){
				if(CheckZero()){
					for(int i=0 ;i<81; i++)	ansnum[i] = num[i];
					ans += 1;
					return 0;
				}
			}
			
			if(num[index] != 0)DFS(index+1);
			else{
				for(int i=1; i<=9; i++){
					if(Check(index, i) == true){
						num[index] = i;
						DFS(index+1);
						num[index] = 0;
					}
				}
			}
		}