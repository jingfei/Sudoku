#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#include"Sudoku.h"
using namespace std;
void Sudoku::GiveQuestion(){
	printf("5 3 0 0 7 0 0 0 0\n"
		   "6 0 0 1 9 5 0 0 0\n"
		   "0 9 8 0 0 0 0 6 0\n"
		   "8 0 0 0 6 0 0 0 3\n"
		   "4 0 0 8 0 3 0 0 1\n"
		   "7 0 0 0 2 0 0 0 6\n"
		   "0 6 0 0 0 0 2 8 0\n"
		   "0 0 0 4 1 9 0 0 5\n"
		   "0 0 0 0 8 0 0 7 9\n");
}

void Sudoku::readInt(int &out){
	scanf("%d",&out);	
}

void Sudoku::ReadIn(){
	register int row,col;
	int temp;

	//fread( input_ )
	//inputReader_ = input_;

	for(row = 0;row < 9;++row){
		for(col = 0;col < 9;++col){
			readInt(temp);
			tableResult_[row][col] = temp;
			tableResult_[row][col] = temp;
			if(temp == 0)blank_.push_back( make_pair(row,col) );
		}
	}
}
void Sudoku::Solve(){
	BlankIterator start = blank_.begin() ,end = blank_.end();
	switch( dfs(start,end) ){
		case No:
			puts("0");
			break;
		case One:
			puts("1");
			for(int row = 0;row < 9;++row){
				putchar( tableResult_[row][0] + '0');
				for(int col = 1;col < 9;++col){
					putchar( ' ' );
					putchar( tableResult_[row][col] + '0');
				}
				puts("");
			}
			break;
		case Multi:
			puts("2");
			break;
	}
}
Sudoku::SolveStatus Sudoku::dfs(BlankIterator &blank,BlankIterator &end){
	if(blank == end)return One;
	int A = (*blank).first, B = (*blank).second;
	bool GetSolution = false;
	for(int Try = 1; Try <= 9; ++Try){
		bool trySuccess = true;

		for(int i = 0;i < 9;++i){
			if((*tableToSearch_)[A][i] == Try)
			{ trySuccess = false; break; }
		}
		if(trySuccess){
			for(int i = 0;i < 9;++i){
				if((*tableToSearch_)[i][B] == Try)
				{ trySuccess = false; break; }
			}
		}
		if(trySuccess){
			for(int i = (A / 3) * 3; i < (A / 3) * 3 + 3;++i){ 
				for(int j = (B / 3) * 3; j < (B / 3) * 3 + 3 ;++j){
					if((*tableToSearch_)[i][j] == Try){ trySuccess = false;break; }
				}
			}
		}
		if(trySuccess){
			(*tableToSearch_)[A][B] = Try;
			Sudoku::SolveStatus result = dfs(++blank,end);
			if(result == One){
				if(!GetSolution){
					if(tableToSearch_ != &tabletemp_){
						memcpy((void *)tabletemp_,(void *)tableResult_,sizeof(int) * 81);
					}
						tableToSearch_ = &tabletemp_;
						GetSolution = true;
				}else return Multi;
			}else if(result == Multi){
				return Multi;
			}
			(*tableToSearch_)[A][B] = 0;
			--blank;
		}
	}
	if(GetSolution) return One; 
	else return No;
}

