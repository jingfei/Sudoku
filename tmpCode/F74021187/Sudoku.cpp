#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include"Sudoku.h"
using namespace std;

char *Sudoku::inputReader_;
char Sudoku::input_[1000];

int Sudoku::randOneToNine(){
	return randZeroToEight() + 1;
}
int Sudoku::randZeroToEight(){
	return rand() % 9;
}
/*
bool Sudoku::generateCompleteTable(int blank){
	if(blank == 81)return true; //finish
	int startTry = randOneToNine()
	   ,endTry = (startTry - 1 == 0) ? 9 : startTry - 1;
	int X = blank / 9, Y = blank % 9;
	for(int Try = startTry; ; ++Try){
		if(Try > 9)Try = 1;
		if(Test(X,Y,Try)){
			tableResult_[X][Y] = Try;
			rowClear_[X][Try] = true;
			colClear_[Y][Try] = true;
			cellClear_[X / 3 * 3 + Y / 3][Try] = true;
			if(generateCompleteTable(blank + 1))return true;
			rowClear_[X][Try] = false;
			colClear_[Y][Try] = false;
			cellClear_[X / 3 * 3 + Y / 3][Try] = false;
		}
		if(Try == endTry)break;
	}
	return false;
}
*/
void Sudoku::GiveQuestion(){
	srand(clock());
	char numberConvert[9] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9};
	for(int i = 0;i < 9;++i){
		int randomIndex = randZeroToEight();
		// swap 
		int temp = numberConvert[randomIndex];
		numberConvert[randomIndex] = numberConvert[i];
		numberConvert[i] = temp;
	}
	static char out[] = "4 0 0 0 0 3 0 0 0\n"
						"0 6 0 0 0 0 0 9 0\n"
						"0 0 0 0 0 0 0 0 0\n"
						"0 0 0 0 0 0 0 0 3\n"
						"0 5 0 8 6 0 0 0 0\n"
						"0 0 8 0 0 2 0 0 1\n"
						"0 0 0 0 0 0 0 0 2\n"
						"0 0 0 0 0 0 6 5 0\n"
						"3 0 1 0 0 4 0 0 0\n";
	char *start = out;
	while(*start){
		if(*start <= '9' && *start >= '1')
			putchar(numberConvert[*start - '1'] + '0');
		else putchar(*start);
		++start;
	}
}

void Sudoku::readInt(int &out){
/*
 * Contest *
	while(*inputReader_ < '0' || *inputReader_ > '9')
		++inputReader_;
	out = *inputReader_++ - '0';
*/
	if(scanf("%d",&out)!=1 || out > 9 || out < 0) {
		 inputValid_ = false;
	};
}

void Sudoku::ReadIn(){
	register int row,col;
	int temp;
/*
 * Contest *
	fread( input_ ,1000,1,stdin);
	inputReader_ = input_;
*/	inputValid_ = true;
	for(row = 0;row < 9;++row){
		for(col = 0;col < 9;++col){
			readInt(temp);
			tableInput_[row][col] = temp;
			rowClear_[row][temp] = true;
			colClear_[col][temp] = true;
			cellClear_[row / 3 * 3 + col / 3][temp] = true;
			if(temp == 0)blank_.push_back( make_pair(row,col) );
		}
	}
	if(inputValid_ == false){
	    puts("0");
	    exit(0);
	}
}
void Sudoku::Solve(){
	backTrackSearch();
	if(status_  == No){
		puts("0");
	}else if(status_ == One){
		puts("1");
		for(int row = 0;row < 9;++row){
			putchar( tableResult_[row][0] + '0');
			for(int col = 1;col < 9;++col){
				putchar( ' ' );
				putchar( tableResult_[row][col] + '0');
			}
			puts("");
		}
	}else{ // Multi
		puts("2");
	}
}
bool Sudoku::Test(int A,int B,int Try){
	if(rowClear_[A][Try] || colClear_[B][Try] || cellClear_[A / 3 * 3 + B / 3][Try])
		return false; 
	return true;
}
void Sudoku::backTrackSearch(int blank){
	if(blank == blank_.size()){ // Finish Search
		if(status_ == No){
			memcpy((void *)tableResult_, (void *)tableInput_ , sizeof(int) * 81);
			status_ = One;
		}else status_ = Multi;
		return;
	}
	int X = blank_[blank].first, Y = blank_[blank].second;
	for(int Try = 1; Try <= 9; ++Try){
		if(Test(X,Y,Try)){
			// Fill
			tableInput_[X][Y] = Try;
			rowClear_[X][Try] = true, colClear_[Y][Try] = true;
			cellClear_[X / 3 * 3 + Y / 3][Try] = true;
			// Try Next
			backTrackSearch(blank+1);
			if(status_ == Multi) return;
			// Recover status
			tableInput_[X][Y] = 0;
			rowClear_[X][Try] = false, colClear_[Y][Try] = false;
			cellClear_[X / 3 * 3 + Y / 3][Try] = false;
		}
	}
}
