#include <vector>
#include <iostream>
#include <fstream>
#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku()
{
	for(int i=0 ; i<sudokuSize ; ++i)
		map[i] = 0;
}
Sudoku::Sudoku(const int init_map[])
{
	for(int i=0 ; i<sudokuSize ; ++i)
		map[i] = init_map[i];
}

void Sudoku::setMap(const int set_map[])
{
	for(int i=0 ; i<sudokuSize ; ++i)
		map[i] = set_map[i];
}

int Sudoku::getElement(int index)
{
	return map[index];
}

bool Sudoku::checkUnity(int arr[])
{
	int arr_unity[9]; // counters

	for(int i=0; i<9; ++i)
		arr_unity[i] = 0; // initialize
	for(int i=0; i<9; ++i)

		++arr_unity[arr[i]-1];
	//

	for(int i=0; i<9; ++i)

		if(arr_unity[i] != 1)
			//


			return false;
	//

	return true;
}


bool Sudoku::isCorrect()
{
	bool check_result;
	int check_arr[9];
	int location;
	for(int i=0; i<81; i+=9) // check rows
	{
		for(int j=0; j<9; ++j)

			check_arr[j] = map[i+j];

		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	}
	for(int i=0; i<9; ++i) // check columns
	{
		for(int j=0; j<9; ++j)

			check_arr[j] = map[i+9*j];

		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	}

	for(int i=0; i<9; ++i) // check cells
	{
		for(int j=0; j<9; ++j)
		{

			location = 27*(i/3) + 3*(i%3) + 9*(j/3) + (j%3);

			check_arr[j] = map[location];
		}

		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	}
	return true;
}
void Sudoku::setElement(int index, int value)
{
	map[index] = value;
}
int Sudoku::getFirstZeroIndex()
{
	for(int i=0;i<sudokuSize;++i)
		if(map[i] == 0)
			return i;
	return -1;
}





void Map::updown(){		 
	int r,c;
	int i,j;
	int temp[3];
	
	for(r=0;r<3;r++){	//把第一行存起來 
		temp[r]=arr[r];
	}
	
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			arr[3*i+j]=arr[3*i+j+3];
		}
	}
	
	for(c=0;c<3;c++){
		arr[6+c]=temp[c];
	}
}

void Map::rightleft(){
	int r,c;
	int i,j;
	int temp[3];
	
	for(r=0;r<3;r++){	//把第一行存起來 
		temp[r]=arr[r];
	}
	
	for(i=0;i<2;i++){
		for(j=0;j<3;j++){
			arr[3*j+i]=arr[3*j+i+1];
		}
	}
	
	for(c=0;c<3;c++){
		arr[3*c+3]=temp[c];
	}
}
void Map::set_unit(){	/*建立隨機的九宮格*/
	int inter[9];
	int j,t,x;
	for(j=0;j<9;j++){
		inter[j]=j+1;
	}
	
	int y=0;
	while(t!=1){
		x=rand()%9+1;
		for(j=0;j<9;j++){
			if(x=inter[j]){
				inter[j]=0;
				arr[y]=x;
				y++;
			}
		}
		if(arr[8]!=0){
			t=1;
			break;
		}
	}
}

void Map::stablish_all(){
	int arr[9];
	int map[9][9];
	int temparr1[9];
	int temparr2[9];
	int i,j;
	
	set_unit();
	
	for(i=0;i<9;i++){
		temparr1[i]=arr[i];
	}
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			map[3+i][3+j]=arr[3*i+j];
		}
	}
	
	updown();
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			map[3+i][j]=arr[3*i+j];
		}
	}
	
	updown();
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			map[3+i][6+j]=arr[3*i+j];
		}
	}
	
	for(i=0;i<9;i++){
		arr[i]=temparr1[i];
	}
	rightleft();
	for(i=0;i<9;i++){	//暫存
		temparr2[i]=arr[i];
	}
	for(j=0;j<3;j++){
		for(i=0;i<3;i++){
			map[i+6][3+j]=arr[3*j+i];
		}
	}
	updown();
	for(j=0;j<3;j++){
		for(i=0;i<3;i++){
			map[i+6][j]=arr[3*j+i];
		}
	}
	updown();
	for(j=0;j<3;j++){
		for(i=0;i<3;i++){
			map[i+6][6+j]=arr[3*j+i];
		}
	}
	
	for(i=0;i<9;i++){
		arr[i]=temparr2[i];
	}
	rightleft();
	for(j=0;j<3;j++){
		for(i=0;i<3;i++){
			map[i][3+j]=arr[3*j+i];
		}
	}
	updown();
	for(j=0;j<3;j++){
		for(i=0;i<3;i++){
			map[i][j]=arr[3*j+i];
		}
	}
	updown();
	for(j=0;j<3;j++){
		for(i=0;i<3;i++){
			map[i][6+j]=arr[3*j+i];
		}
	}
	
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
	
}



bool Sudoku:: Solve(Sudoku question, Sudoku & answer)
{
	int firstZero;
	firstZero = question.getFirstZeroIndex();
	if(firstZero == -1)
	{ // end condition
		if(question.isCorrect())
		{

			answer = question;
			return true;
		}
		else
			return false;
	}


	else
	{

		for(int num=1; num<=9; ++num)
		{

			question.setElement(
					firstZero, num);

			if(Solve(question, answer))
				return true;
		}
		return false;
	}
}
void Sudoku::ReadIn(){
	cout<<"enter the question"<<endl;
	int num;
	for(int i=0;i<81;++i) // read in question
	{
		cin >> num;
		setElement(i, num);
	}
}
int main()
{		
	Sudoku question;
	Sudoku answer;
	
	ReadIn();

	if(Solve(question,answer)== true)
	{
		cout << "Solvable!\n";
		for(int i=0; i<81; i++)
		{
			cout << answer.getElement(i) << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	else
		cout << " Unsolvable!!\n";
}