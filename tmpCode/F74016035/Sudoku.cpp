#include "Sudoku.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

Sudoku::Sudoku()
{
	count = 0;
}
int Sudoku::getAnswer(Map question, Map & answer)
{
	int firstZero = 0; 
	vector<int>num_psb;
	firstZero = question.getFirstZeroIndex();

	if(firstZero == -1)
	{ // end condition
		if(question.isCorrect())
		{
			answer = question;
			count += 1;
			if(count == 2)
				return 2;
			return 0;		
		}

		else
			return 0;
	}


	else
	{  num_psb = question.check_only(firstZero);

		for(int num=0; num<num_psb.size(); ++num)
		{ 

			question.setElement(firstZero, num_psb.at(num)+1);

			if(getAnswer(question, answer) >= 1)
			{
				if(count ==2)
					return 2;
				else if(count == 1)
					return 0;
			}

		}
		return 0;
	}
}


void Sudoku::ReadIn()
{ 
	int num;
	//ifstream infile("infile",ios::in);
	for(int i=0;i<81;++i) // read in question
	{
		cin >> num;
		question.setElement(i, num);
	}

}

void Sudoku::Solve()
{
	int solution;
	solution = getAnswer(question, answer);

	if(solution == 0 && !answer.isCorrect()) 
		cout << "0\n";

	else if(solution == 2)
		cout << "2\n";

	else
	{
		cout << "1\n";
		for(int i=0; i<81; i++)
		{
			cout << answer.getElement(i) << " ";
			if(i%9==8)
				cout << endl;
		}
	}

}

void Sudoku::GiveQuestion()
{
	int a, b;
	vector<int>take;
	srand(time(NULL));

take:
	for(int i=0 ; i<81 ; ++i)
		{
		question.setElement(i, 0);
		answer.setElement(i, 0);}

	for(int i=0 ; i<81 ; ++i)
	{	take = question.check_only(i);
		b = take.size();
		if(b == 0)
			goto take;
		a = rand()%b;
		question.setElement(i, take.at(a)+1);

	}

		
for(int i=0; i<45 ; ++i)
question.setElement(rand()%81, 0);

	if(getAnswer(question, answer) == 0 && answer.isCorrect() == true)
	{	
		for(int i=0 ; i<81 ; ++i)
		{cout << answer.getElement(i) << " ";
			if((i+1)%9 == 0)
				cout << endl;
		}
	}

		else
			goto take;
}
Map::Map()
{
	for(int i=0 ; i<sudokuSize ; ++i)
		map[i] = 0;
}

int Map::getElement(int index)
{
	return map[index];
}

bool Map::checkUnity(int arr[])
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
int check_get()
{



}
bool Map::isCorrect()
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

vector<int>Map::check_only(int zero)
{int arr_exist[9];
	vector<int>arr_return;
	int row, col, cell, area_i;
	for(int i=0; i<9 ; ++i)
		arr_exist[i] = 0;

	row = zero/9;
	col = zero%9;
	area_i = (col/3) + 3*(row/3);
	for(int j=0; j<9; ++j)
	{	
		if(map[row*9+j] != 0)
			arr_exist[map[row*9+j]-1] = 1; 	
		if(map[col+j*9] != 0)
			arr_exist[map[col+j*9]-1] = 1;

		cell = 27*(area_i/3) + 3*(area_i%3) + 9*(j/3) + (j%3);	

		if(map[cell] != 0)  
			arr_exist[map[cell]-1] = 1;
	}

	for(int i=0; i<9 ;++i)
		if(arr_exist[i] == 0)
			arr_return.push_back(i) ;

	return arr_return;
}



void Map::setElement(int index, int value)
{
	map[index] = value;
}

int Map::getFirstZeroIndex()
{
	for(int i=0;i<sudokuSize;++i)
		if(map[i] == 0)
			return i;
	return -1;
}
