/*
	Sudoku.cpp //securtiy
	http://judge.imslab.org/
	reference: http://www.slyar.com/blog/sudoku-cpp.html
*/
//#define TEST
#include <cstdio> //scanf, printf
#include <cstdlib> //exit, rand, srand
#include <vector> //vector
#include <ctime> //time
using namespace std;
#ifndef TEST
#include "Sudoku.h"
#endif // TEST

#ifdef TEST
class Sudoku{
public:
	void GiveQuestion(); //for hw2_give_question
	void ReadIn(); //for hw2_solve
	void Solve(); //for hw2_solve
private:
	int table[81]; //one dimension
	int tmpTable[81];
	int countAns;
	vector<int> unsolvedIndex;
	void analyze(int index, int buffer[], int& countBuffer);
	void PrintTable(int[]);
	void One();
	void copyTable(int des[], int source[]);
	int Backtracking(int index);
	void GiveAnswer();
	void MakeTable(int index);
	int trySolve();
	void tryRead();
	void tryOne();
	void tryBacktracking(int index);
};
#endif // TEST
/**Method**/
void Sudoku::copyTable(int des[], int source[]){
	for(int i=0; i<81; i++){
		des[i] = source[i];
	}
}
void Sudoku::analyze(int index, int buffer[], int& countBuffer){
	int i;
	int lll, rrr;
	//initialize
	for(lll=0; lll<9; lll++){
		buffer[lll] = 0;
	}
	countBuffer = 0;
	//row
	lll = (index/9)*9;
	rrr = (index/9 + 1)*9 - 1;
	for(i=lll; i<=rrr; i++){
		if(table[i]!=0){
			if(buffer[ table[i]-1 ]==0){
				buffer[ table[i]-1 ] = 1;
				countBuffer++;
			}
		}
	}
	//column
	lll = index%9;
	rrr = lll + 72;
	for(i=lll; i<=rrr; i+=9){
		if(table[i]!=0){
			if(buffer[ table[i]-1 ]==0){
				buffer[ table[i]-1 ] = 1;
				countBuffer++;
			}
		}
	}
	//square
	lll = (index/9)*9;
	lll = (lll/27)*27 + (index%9)/3 * 3;
	rrr = lll+20;
	for(i=lll; i<=rrr; i++){
		if(table[i]!=0){
			if(buffer[ table[i]-1 ]==0){
				buffer[ table[i]-1 ] = 1;
				countBuffer++;
			}
		}
		if(i%3==2){
			i += (7-1);
		}
	}
	/**
	00 01 02  03 04 05  06 07 08
	09 10 11  12 13 14  15 16 17
	18 19 20  21 22 23  24 25 26

	27 28 29
	36 37 38
	45 46 47

	54
	63
	72
	*/
}
//
int Sudoku::Backtracking(int index){
	int i, j, res;
	int buffer[9];
	int countBuffer;
	analyze(unsolvedIndex[index], buffer, countBuffer);
	if(index+1==unsolvedIndex.size()){
		//the final table
		for(i=0; i<9 && countBuffer<9; i++){
			if(buffer[i]==0){
				buffer[i] = 1;
				table[ unsolvedIndex[index] ] = i+1;
				copyTable(tmpTable, table);
				countAns++;
				if(countAns>=2){
					return 2;
				}
				buffer[i] = 0;
				table[ unsolvedIndex[index] ] = 0;
			}
		}
	}else{
		for(i=0; i<9 && countBuffer<9; i++){
			if(buffer[i]==0){
				buffer[i] = 1;
				table[ unsolvedIndex[index] ] = i+1;
				Backtracking(index+1);
				if(countAns>=2){return 2;}
				buffer[i] = 0;
				table[ unsolvedIndex[index] ] = 0;
			}
		}
	}
	return 0;
}
void Sudoku::One(){
	int i, j;
	int buffer[9];
	int countBuffer;
	for(i=0; i<unsolvedIndex.size(); i++){
		analyze(unsolvedIndex[i], buffer, countBuffer);
		if(countBuffer==9){
			//no answer
			return;
		}else if(countBuffer==8){
			//one answer
			for(j=0; j<9; j++){
				if(buffer[j]==0){
					table[ unsolvedIndex[i] ] = j+1;
					unsolvedIndex.erase(unsolvedIndex.begin() + i);
					break;
				}
			}
			i = -1;
		}
	}
	return;
}
/** Rule **/
void Sudoku::ReadIn(){
	int i;
	for(i=0; i<81; i++){
		scanf("%d", &table[i]); //read data
		if(table[i]==0){
			unsolvedIndex.push_back(i);
		}else if(table[i]<0 || table[i]>9){
			printf("0\n");
			exit(1);
		}
	}
	return;
}
void Sudoku::Solve(){
	One();
	if(unsolvedIndex.empty()){
		printf("1\n");
		PrintTable(table);
		return;
	}
	//initialize
	countAns = 0;
	Backtracking(0);
	if(countAns==0){
		printf("0\n");
	}else if(countAns==1){
		printf("1\n");
		PrintTable(tmpTable);
	}else{
		printf("2\n");
	}
	return;
}
void Sudoku::PrintTable(int ary[]){
	for(int i=0; i<81; i++){
		if(i%9==0){
			if(i!=0)
				printf("\n");
			printf("%d", ary[i]);
		}else{
			printf(" %d", ary[i]);
		}
	}
	printf("\n");
	return;
}
void Sudoku::tryRead(){
	int i;
	if(!unsolvedIndex.empty()){
		unsolvedIndex.pop_back();
	}
	for(i=0; i<81; i++){
		if(table[i]==0){
			unsolvedIndex.push_back(i);
		}
	}
	return;
}
void Sudoku::tryOne(){
	int i, j;
	int buffer[9];
	int countBuffer;
	for(i=0; i<unsolvedIndex.size(); i++){
		analyze(unsolvedIndex[i], buffer, countBuffer);
		if(countBuffer==9){
			//no answer
			return;
		}else if(countBuffer==8){
			//one answer
			for(j=0; j<9; j++){
				if(buffer[j]==0){
					table[ unsolvedIndex[i] ] = j+1;
					unsolvedIndex.erase(unsolvedIndex.begin() + i);
					break;
				}
			}
			i = -1;
		}
	}
	return;
}
void Sudoku::tryBacktracking(int index){
	int i, j, res;
	int buffer[9];
	int countBuffer;
	analyze(unsolvedIndex[index], buffer, countBuffer);
	if(index+1==unsolvedIndex.size()){
		//the final table
		for(i=0; i<9; i++){
			if(buffer[i]==0){
				buffer[i] = 1;
				table[ unsolvedIndex[index] ] = i+1;
				copyTable(tmpTable, table);
				countAns++;
				if(countAns>=2){
					return;
				}
				buffer[i] = 0;
				table[ unsolvedIndex[index] ] = 0;
			}
		}
		return;
	}
	for(i=0; i<9; i++){
		if(buffer[i]==0){
			buffer[i] = 1;
			table[ unsolvedIndex[index] ] = i+1;
			tryBacktracking(index+1);
			if(countAns>=2){
				return;
			}
			buffer[i] = 0;
			table[ unsolvedIndex[index] ] = 0;
		}
	}
}
int Sudoku::trySolve(){
	tryRead();
	tryOne();
	if(unsolvedIndex.empty()){
		return 1;
	}
	//initialize
	countAns = 0;
	tryBacktracking(0);
	if(countAns==0){
		return 0;
	}else if(countAns==1){
		return 1;
	}else{
		return 2;
	}
}
void Sudoku::MakeTable(int index){
	int i, tmp, res;
	tmp = table[index];
	table[index] = 0;
	copyTable(tmpTable, table);
	res = trySolve();
	if(res!=1){
		//¤£¬O°ß¤@¸Ñ
		copyTable(table, tmpTable);
		table[index] = tmp;
	}else{
		copyTable(table, tmpTable);
	}
	if(index<=79){
		if(res==1){
			res = rand()%5;
		}else{
			res = 1;
		}
		MakeTable(index+res);
	}
	return;
}
void Sudoku::GiveAnswer(){
	srand(time(NULL));
	int i, j, flag;
	int numAllocate[9];
	int ansTemplate[]={9,2,5,6,3,1,7,8,4,
						8,1,7,5,2,4,6,3,9,
						3,4,6,9,7,8,1,5,2,
						1,7,9,3,5,2,4,6,8,
						6,8,2,1,4,7,5,9,3,
						5,3,4,8,9,6,2,7,1,
						4,6,8,7,1,3,9,2,5,
						7,9,1,2,8,5,3,4,6,
						2,5,3,4,6,9,8,1,7};
	//
	flag = rand()%3;
	copyTable(table, ansTemplate);
	for(i=0; i<9; i++){
		numAllocate[i] = rand()%9 + 1;
		for(j=i-1; j>=0; j--){
			if(numAllocate[i] == numAllocate[j]){
				i--;
				break;
			}
		}
	}
	for(i=0; i<81; i++){
		//change the number
		table[i] = numAllocate[ table[i]-1 ];
	}
}
void Sudoku::GiveQuestion(){
	GiveAnswer();
	srand(time(NULL));
	MakeTable(rand()%3); //unfill the table
	int i=0, j=0;
	for(i=0; i<9; i++){
		printf("%d", table[i*9]);
		for(j=1; j<9; j++){
			printf(" %d", table[i*9+j]);
		}
		printf("\n");
	}
	return;
}


#ifdef TEST
int main(){
	freopen("question.txt", "r", stdin);
	class Sudoku ss;
	ss.ReadIn();
	ss.Solve();
	return 0;
}
#endif // TEST
