#include <iostream>
#include <vector>
#include<cstdlib>
#include<ctime>
#include <utility>
#include "Sudoku.h"
using namespace std;

void Sudoku::ReadIn() {
	for (int i=0; i<9; ++i) {
		for (int j=0; j<9; ++j) {
			cin >> map[i][j];
			if (map[i][j] == 0) emp.push_back(Coordinate(i,j));
		}
	}
}

void Sudoku::GiveQuestion() {
	int choice;
	srand(time(NULL));
	choice = rand() % 5 + 1;
	if (choice == 1) cout << "0 0 9 0 0 0 3 2 0" << endl << "0 4 1 0 8 0 0 0 0" << endl << "6 0 0 2 0 0 0 0 0" << endl << "3 9 0 4 0 0 0 0 0" << endl << "0 0 8 0 0 0 5 0 0" << endl << "0 0 0 0 0 5 0 1 3" << endl << "0 0 0 0 0 6 0 0 8" << endl << "0 0 0 0 7 0 6 3 0" << endl << "0 6 7 0 0 0 1 0 0" << endl;
	if (choice == 2) cout << "1 0 0 5 3 0 0 0 0" << endl << "0 0 8 0 0 0 6 5 0" << endl << "0 0 0 0 0 6 0 0 3" << endl << "0 0 6 2 0 0 0 9 0" << endl << "7 0 0 0 0 0 0 0 8" << endl << "0 5 0 0 0 3 1 0 0" << endl << "2 0 0 6 0 0 0 0 0" << endl << "0 7 9 0 0 0 8 0 0 "<< endl << "0 0 0 0 4 2 0 0 1" << endl;
	if (choice == 3) cout << "9 8 0 0 0 0 0 0 2" << endl << "0 0 0 0 2 0 9 0 0" << endl << "0 1 0 0 0 5 0 0 0" << endl << "0 5 0 0 8 0 7 0 0" << endl << "0 0 3 5 0 6 4 0 0" << endl << "0 0 1 0 4 0 0 2 0" << endl << "0 0 0 7 0 0 0 3 0" << endl << "0 0 2 0 6 0 0 0 0"<< endl << "5 0 0 0 0 0 0 9 8" << endl;
	if (choice == 4) cout << "2 8 5 0 0 0 0 0 0" << endl << "0 0 0 0 2 6 0 3 0" << endl << "0 0 0 0 0 8 2 0 0" << endl << "0 0 0 0 0 4 8 0 0" << endl << "0 9 0 1 0 3 0 5 0" << endl << "0 0 4 6 0 0 0 0 0" << endl << "0 0 6 8 0 0 0 0 0" << endl << "0 3 0 9 1 0 0 0 0" << endl << "0 0 0 0 0 0 3 7 1" << endl;
}
void Sudoku::Solve() {
	int output[9][9];
	status = no;
	SearchResult(0);
	if (status == no) cout << '0' << endl;
	else if (status == only) {
		cout << '1' << endl;
		for (int i=0; i<9; ++i) {
			for (int j=0; j<9; ++j) cout << mmap[i][j] << " " ;
			cout << endl;
		}
	}
	else if (status == multi) cout << '2' << endl;
}

Sudoku::Search Sudoku::SearchResult(int location) {
	if (location == emp.size()) {
		if (status == no){
			for(int i = 0;i < 9;++i)
				for(int j = 0;j < 9; ++j)
					mmap[i][j] = map[i][j];
			status = only;
		}else if( status == multi || status == only) {
			status = multi;
			return multi;
		}
		return only;
	}
	for (int n=1; n<=9; n++){
		bool canInsert = true;
		for (int i=0; i<9; ++i) {
			if (map[i][emp[location].second] == n) {
				canInsert = false;
				break;
			}
		}
		if (canInsert) for (int j=0; j<9; ++j) {
			if (map[emp[location].first][j] == n) {
				canInsert = false;
				break;
			}
		}
		if (canInsert) for (int k=0; k<3; ++k) {
			for (int l=0; l<3; ++l) {
				if (map[(emp[location].first/3)*3 + k][(emp[location].second/3)*3 + l] == n) {
					canInsert = false;
					break;
				}
			}
		}
		if (canInsert){
			map[emp[location].first][emp[location].second] = n;
			if(SearchResult(location + 1) == multi) return multi;
			map[emp[location].first][emp[location].second] = 0;
		}
	}
	return only;
}
