#include "Sudoku.h"
#include<cstdlib>
#include<ctime>
using namespace std;

Sudoku::Sudoku(){
	for(int i=0; i<sudokuSize; ++i)
		map[i] = 0;
}
Sudoku::Sudoku(const int init_map[]){
	for(int i=0; i<sudokuSize; ++i)
		map[i] = init_map[i];
}

void Sudoku::setMap(const int set_map[]){
	for(int i=0; i<sudokuSize; ++i)
		map[i] = set_map[i];
}

int Sudoku::getElement(int index){
	return map[index];
}

void Sudoku::setElement(int index,int value){
	map[index] = value;
}

int Sudoku::getFirstZeroIndex(){
	for(int i=0;i<sudokuSize;++i)
		if(map[i] == 0)
			return i;
	return -1;
}
int Sudoku::checkUnity(int arr[])
{
	int arr_unity[9]; // counters

	for(int i=0; i<9; ++i)
		arr_unity[i] = 0; // initialize
	for(int i=0; i<9; ++i)
		++arr_unity[arr[i]-1]; // count
	for(int i=0; i<9; ++i){
		if(arr_unity[i] > 1) // all element
			return 2; // must be 1
	}
	for(int i=0; i<9; ++i){
		if(arr_unity[i] == 0)
			return 0;
	}
	return 1;
}

int Sudoku::isCorrect(){
	int check_result;
	int check_arr[9];
	int location;
	for(int i=0; i<81; i+=9) // check rows
	{
		for(int j=0; j<9; ++j)
			check_arr[j] = map[i+j];
		check_result = checkUnity(check_arr);
		if(check_result == 2)
			return 2;
		else if(check_result == 0)
			return 0;
	}
	for(int i=0; i<9; ++i) // check columns
	{
		for(int j=0; j<9; ++j)
			check_arr[j] = map[i+9*j];
		check_result = checkUnity(check_arr);
		if(check_result == 2)
			return 2;
		else if(check_result == 0)
			return 0;
	}

	for(int i=0; i<9; ++i) // check cells
	{
		for(int j=0; j<9; ++j){
			location = 27*(i/3)+3*(i%3)+9*(j/3) + (j%3);
			check_arr[j] = map[location];
		}
		check_result = checkUnity(check_arr);
		if(check_result == 2)
			return 2;
		else if(check_result == 0)
			return 0;
	}
	return 1;
}

void Sudoku::GiveQuestion(){
	srandom(time(NULL));
	int tmp;
	tmp=random()%2;
	if(tmp==0){
		cout<<"8 6 5 3 2 9 4 1 7\n"
			"2 4 3 1 7 5 0 0 9\n"
			"1 9 7 6 8 4 5 2 3\n"
			"3 1 9 0 5 8 6 7 4\n"
			"4 2 6 7 0 1 3 5 8\n"
			"5 7 8 4 3 0 1 9 2\n"
			"7 5 4 9 1 3 2 8 6\n"
			"6 8 2 5 4 7 9 3 1\n"
			"9 3 1 8 6 2 7 4 5\n";
	}
	else{
		cout<<"8 6 5 3 2 9 4 1 7\n"
			"2 4 3 1 7 5 0 6 9\n"
			"1 9 0 6 8 4 5 2 3\n"
			"3 1 9 2 5 8 6 7 4\n"
			"4 2 6 7 9 0 3 5 8\n"
			"5 0 8 4 3 6 1 9 2\n"
			"7 5 4 9 1 0 2 8 6\n"
			"6 8 2 0 4 7 9 3 1\n"
			"9 3 0 8 6 2 7 4 5\n";
	}
}
void Sudoku::ReadIn(){
	int tmp;
	for(int i=0;i<81;i++){
		cin>>tmp;
		setElement(i,tmp);
	}
}
void Sudoku::Solve(){
	int count=0,c=0;
	Sudoku question;
	Sudoku answer;
	question.setMap(map);
	if(is_no_sol() == true){
		cout<<"0\n";
		exit(1);
	}
	for(int i=0;i<81;i++)
		if(map[i]!=0)
			c++;
	if(c<27){
		cout<<"2\n";
		exit(1);
	}

	solve(question,answer,count);
	if(count==1){
		cout<<"1\n";
		for(int i=0;i<81;i++){
			cout<<answer.getElement(i) << " ";
			if(i%9==8)
				cout<<endl;
		}
	}
}
bool Sudoku::solve(Sudoku question, Sudoku & answer,int &count){
	int firstZero;
		int valid[9];
	firstZero = question.getFirstZeroIndex();
	if(firstZero == -1)
	{ // end condition
		if(question.isCorrect()== 1){
			answer = question;
			if(count==1)
			return true;
		}
		return false;
	}
	else
	{
		for(int num=1; num<=9; ++num){
			ConfirmCandidate(firstZero,valid);
				if(valid[num-1]!=0){
					question.setElement(firstZero, num);
					if(solve(question,answer,count) == true);
                        return true;
				}
		}
	}
}
void Sudoku::ConfirmCandidate(int index,int *valid){
	for( int i_candidate = 0; i_candidate < 9; i_candidate++ )
		valid[i_candidate] = i_candidate+1;
			for( int colm = 0; colm < 9; colm++ )
			{
				if( map[(index/9)*9+colm] != 0 )
					valid[map[(index/9)*9+colm]-1] = 0;
			}
	for( int line = 0; line < 9; line++ )
	{
		if( map[line*9+index%9] != 0 )
			valid[map[line*9+index%9]-1] = 0;
	}
	for( int line = ((index/9)/3)*3; line < ((index/9)/3)*3+3; line++ )
	{
		for( int colm = ((index%9)/3)*3; colm < ((index%9)/3)*3+3; colm++ )
			if( map[line*9+colm] != 0 )
				valid[map[line*9+colm]-1] = 0;
	}
}
bool Sudoku::is_no_sol(){
	int check_result;
	int check_arr[9];
	int location;
	for(int i=0; i<81; i+=9) // check rows
	{
		for(int j=0; j<9; ++j)
			check_arr[j] = map[i+j];
		check_result = checkUnity(check_arr);
		if(check_result == 2)
			return true;
	}
	for(int i=0; i<9; ++i) // check columns
	{
		for(int j=0; j<9; ++j)
			check_arr[j] = map[i+9*j];
		check_result = checkUnity(check_arr);
		if(check_result == 2)
			return true;
	}

	for(int i=0; i<9; ++i) // check cells
	{
		for(int j=0; j<9; ++j){
			location = 27*(i/3)+3*(i%3)+9*(j/3) + (j%3);
			check_arr[j] = map[location];
		}
		check_result = checkUnity(check_arr);
		if(check_result == 2)
			return true;
	}
	return false;
}
