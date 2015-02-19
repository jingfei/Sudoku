#include<iostream>
#include<vector>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include"Sudoku.h"
using namespace std;
void Sudoku::ReadIn(){
    int k = 0;
    for(int i = 0; i < 9; ++i){
        for(int j = 0; j < 9; ++j){
            cin >>sudoku_[i][j];
            if(sudoku_[i][j] == 0) 
				hole_.push_back( make_pair(i,j) );
        }
    }
}
void Sudoku::Solve(){
	SearchAnswer(0);
	if(status_ == N){
		cout <<"0"<< endl;
	}else if(status_ == One){
		cout <<"1"<< endl;
		for(int i = 0; i < 9; ++i){
			for(int j = 0; j < 9; ++j){
				cout <<tempResult_[i][j] << ' ';
			}
			cout << endl;
		}
	}else{
		cout <<"2"<< endl;
	}
}
void Sudoku::SearchAnswer(int hole){
	if(status_ == Multi)return;
	if(hole == hole_.size()){
		if(status_ == N ){
			memcpy((void*)tempResult_, (void*)sudoku_, 81 * sizeof(int));
			status_ = One;
		}else{
			status_ = Multi;
		}
		return;
	}
	const int X = hole_[hole].first,Y = hole_[hole].second;
	for(int n = 1; n <= 9; ++n){
		bool canInsert = true;
		for(int i = 0; i < 9; ++i){
			if(sudoku_[X][i] == n)
				canInsert = false;
		}
		if(canInsert)for(int j = 0; j < 9; ++j){
			if(sudoku_[j][Y] == n)
				canInsert = false;
		}
		if(canInsert)for(int i = X/3 * 3; i < X/3 * 3 + 3; ++i){
			for(int j = Y/3*3; j < Y/3*3 + 3; ++j){
				if(sudoku_[i][j] == n)
					canInsert = false;
			}
		}
		if(canInsert){
			sudoku_[X][Y] = n;
			SearchAnswer(hole+1);
			sudoku_[X][Y] = 0;
			if(status_ == Multi) return;
		}
	}
}
void Sudoku::GiveQuestion(){
	srand(time(NULL));
	if(rand()%5 == 0)
		cout << "0 0 0 0 3 0 1 0 0"<< endl <<"0 4 0 5 0 0 2 0 0"<< endl <<"7 0 0 0 0 8 9 0 0"<< endl <<"6 0 0 0 0 7 0 8 0"<< endl <<"9 0 0 0 0 2 0 0 3"<< endl <<"0 5 0 0 0 0 0 0 4"<< endl <<"0 0 1 6 0 0 0 0 5"<< endl <<"0 0 8 0 0 9 0 0 6"<< endl <<"0 0 3 0 1 0 0 0 0"<< endl;
	else if(rand()%5 == 1)
		cout << "2 0 0 0 0 9 0 0 0"<< endl <<"0 0 6 0 0 0 7 0 0"<< endl <<"0 5 0 0 8 0 0 0 4"<< endl <<"3 0 0 0 1 0 0 0 8"<< endl <<"9 0 0 0 0 2 0 0 5"<< endl <<"4 0 0 0 0 0 0 0 6"<< endl <<"1 0 0 0 3 0 0 9 0"<< endl <<"0 0 7 0 0 0 1 0 0"<< endl <<"0 0 0 5 0 0 0 0 3"<< endl;
	else if(rand()%5 == 2)
		cout << "2 0 0 9 0 0 0 6 0"<< endl <<"0 7 0 3 0 0 4 0 0"<< endl <<"0 0 8 0 0 0 0 0 0"<< endl <<"0 0 1 5 0 0 0 0 9"<< endl <<"6 0 0 0 0 0 0 0 2"<< endl <<"4 0 0 7 0 0 3 0 0"<< endl <<"0 0 0 0 0 0 1 0 0"<< endl <<"0 0 5 0 0 6 0 8 0"<< endl <<"0 9 0 0 0 8 0 0 7"<< endl;
	else if(rand()%5 == 3)
		cout << "7 0 0 9 0 0 0 6 0"<< endl <<"0 8 0 0 0 0 0 0 0"<< endl <<"0 3 0 0 0 1 0 0 2"<< endl <<"5 0 0 0 0 4 0 0 1"<< endl <<"6 0 0 0 0 0 0 0 7"<< endl <<"9 0 0 0 2 0 0 0 3"<< endl <<"1 0 0 5 0 0 0 9 0"<< endl <<"0 0 0 0 0 0 0 4 0"<< endl <<"0 5 0 0 0 3 0 0 6"<< endl;
	else
		cout << "0 0 0 0 0 1 6 0 0"<< endl <<"0 0 9 4 0 0 2 0 0"<< endl <<"0 0 7 0 0 5 8 0 0"<< endl <<"3 0 0 0 0 7 0 0 1"<< endl <<"6 0 0 0 0 0 0 0 5"<< endl <<"4 0 0 0 0 8 0 0 9"<< endl <<"0 0 2 9 0 0 1 0 0"<< endl <<"0 0 3 0 0 4 5 0 0"<< endl <<"0 0 6 1 0 0 0 0 0"<< endl;
}
