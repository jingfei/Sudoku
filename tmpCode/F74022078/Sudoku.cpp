#include "Sudoku.h"
Sudoku::Sudoku()
{
  	int i;
	for(i = 0; i < SudokuSize; i++)
	{
		map[i] = 0;
		zero_position[i] = 0;
		blank[i] = 0;
	}
	ans_num = 0;
	zero_num = 0;
	state = 0;
}
void Sudoku::SetMap(const int set_map[])
{
  	int i;
	for(i = 0; i < SudokuSize; i++)
	  map[i] = set_map[i];
}
void Sudoku::ReadIn()
{
	int i;
	for(i = 0; i < Sudoku::SudokuSize; i++)
	  cin >> Sudoku::map[i];
  	zero_num = rest_zero(Sudoku::map);
}
  
int Sudoku::GetZeroNum()
{
 	return zero_num;
}

int Sudoku::GetElement(int index)
{
  	return map[index];
}
	  
bool Sudoku::isCorrect() 
{
  	bool check_result; 
  	int check_arr[9]; 
  	int location; 
    for(int i = 0; i < 81; i += 9)    // check rows
  	{
  		for(int j = 0; j < 9; j++)
  		  check_arr[j] = map[i+j];
  		check_result= Check(check_arr); 
  		if(check_result== false) 
  		  return false; 
  	}
  	for(int i = 0; i < 9; i++)   // check columns 
  	{ 
  		for(int j = 0; j < 9; j++) 
  		  check_arr[j] = map[i+9*j]; 
  		check_result= Check(check_arr); 
  		if(check_result == false) 
  		  return false; 
  	}
	for(int i = 0; i < 9; i++)   // check cells 
	{
		for(int j = 0; j < 9; j++) 
		{ 
			location = 27*(i/3) + 3*(i%3) + 9*(j/3) + (j%3); 
			check_arr[j] = map[location]; 
		} 
		check_result = Check(check_arr); 
		if(check_result == false) 
		  return false; 
	} 
		return true; 
}
	  
void Sudoku::GiveQuestion()
{
	int appear[9] = {0};
	int order[9] = {0};
	unsigned int seed;
	seed = static_cast<unsigned int>( time(NULL) );
	srand(seed);
	for(int i = 0; i < 9; i++)
	{
		int j = rand()%9;
		if(appear[j] == 0)
		{
			appear[j]++;
			order[i] = (j+1);
		}
		else
		  i--;
	}
	int board[SudokuSize] = {1,2,3,4,5,6,7,8,9,
							 4,5,6,7,8,9,1,2,3,
							 7,8,9,1,2,3,4,5,6,
							 2,3,1,5,6,4,8,9,7,
							 5,6,4,8,9,7,2,3,1,
							 8,9,7,2,3,1,5,6,4,
							 3,1,2,6,4,5,9,7,8,
							 6,4,5,9,7,8,3,1,2,
							 9,7,8,3,1,2,6,4,5};
	for(int i = 0; i < SudokuSize; i++)
	{
		if(board[i] == 1)
		  board[i] = order[0];
		else if(board[i] == 2)
		  board[i] = order[1];
		else if(board[i] == 3)
		  board[i] = order[2];
		else if(board[i] == 4)
		  board[i] = order[3];
		else if(board[i] == 5)
		  board[i] = order[4];
		else if(board[i] == 6)
		  board[i] = order[5];
		else if(board[i] == 7)
		  board[i] = order[6];
		else if(board[i] == 8)
		  board[i] = order[7];
		else if(board[i] == 9)
		  board[i] = order[8];
	}
/*	int ques[SudokuSize] = {1,1,1,1,1,1,0,1,1,
							1,0,0,0,1,1,1,1,1,
							1,0,1,0,1,0,0,1,0,
							0,0,1,0,0,1,0,1,0,
							1,0,1,1,1,1,0,0,0,
							0,1,0,1,0,0,1,1,0,
							0,1,1,0,1,0,1,0,1,
							1,1,0,0,1,1,0,0,1,
							0,1,0,1,0,1,1,1,1};
	for(int i = 0; i < SudokuSize; i++)
	{
		if(ques[i] == 0)
		board[i] = 0;
	}
*/	
	int n = 81;
	while(1)
	{
		dig_hole(board, n);
		if(state != 1)
		{
			state = 0;
			n--;
		}
		else break;
	}
	for(int i = 0; i < SudokuSize; i++)
	  blank[i] = 0;
	ans_num = 0;
	zero_num = 0;
	state = 0;
	for(int j = 0; j < SudokuSize; j++)
	{
		cout << board[j] << " ";
		if(j%9 == 8)
		  cout << endl;
	}
}
void Sudoku::dig_hole(int board[], const int goal)
{
	int tmp, buffer, tmp_blank[SudokuSize] = {0};
	for(int i = 0; i < SudokuSize; i++)
	{
		if(blank[i] == 1)
		  tmp_blank[i] = 1;
	}
	ans_num = 0;
	if(zero_num >= goal)
	{
		state = 1;
		return;
	}
	for(int i = 0; i < SudokuSize - zero_num; i++)
	{
		while(tmp_blank[(tmp = rand()%81)] != 0);
		tmp_blank[tmp] = 1;
		buffer = board[tmp];
		board[tmp] = 0;
		zero_num++;
		backtracking(board);
		if(ans_num == 1)
		{
			blank[tmp] = 1;
			dig_hole(board, goal);
			if(state == 1)
			  return;
		}
		board[tmp] = buffer;
		zero_num--;
		blank[tmp] = 0;
	}
}
void Sudoku::backtracking(int to_track[])  //notice: you have to check if ans_num is initialized yet
{
	int j = 0;
	for(int i = 0; i < SudokuSize; i++)  //trace zeroes' positions
	{
		if(to_track[i] == 0)
		  zero_position[j++] = i;
	}
	zero_num = rest_zero(to_track);
	if(ans_num > 1)
	  return;
	if(zero_num == 0)
	{
		ans_num++;
		for(int i = 0; i < SudokuSize; i++)
		  solution[i] = to_track[i];
		return;
	}
	for(int i = 1; i <= 9; i++)
	{
		if(check_row(i, zero_position[zero_num-1], to_track) && check_column(i, zero_position[zero_num-1], to_track) && check_cell(i, zero_position[zero_num-1], to_track)) //check from the last zero
		{
			to_track[(zero_position[--zero_num])] = i;
			backtracking(to_track);
			to_track[(zero_position[zero_num++])] = 0;
		}
	}
}
void Sudoku::Solve()
{
	backtracking(map);
	if(ans_num > 1)
	  cout << "2" << endl;
	else if(ans_num == 0)
	  cout << "0" << endl;
	else
	{
		cout << "1" << endl;
		for(int j = 0; j < SudokuSize; j++)
		{
			cout << solution[j] << " ";
			if(j%9 == 8)
			  cout << endl;
		}
	}
}
int Sudoku::rest_zero(int question[])
{
  	int rest = 0;
	for(int i = 0; i < SudokuSize; i++)
	{
		if(question[i] == 0)
		  rest++;
	}
	return rest;
}
bool Sudoku::Check(int check_arr[])
{
  	int arr_unity[9]; 
	for(int i = 0; i < 9; i++)
	  arr_unity[i] = 0;   //initializes
	for(int i = 0; i < 9; i++)
	  arr_unity[check_arr[i]-1]++;
	for(int i = 0; i < 9; i++) 
	  if(arr_unity[i] != 1) 
	    return false; 
	return true; 
}
bool Sudoku::check_row(int to_check, int position, int board[])
{
  	if(to_check == 0)
	  cerr << "to_check = 0\n";
	int row = position/9;
	for(int i = 0; i < 9; i++)
	{
		if(to_check == board[row*9+i])
		  return false;
	}
	return true;
}
bool Sudoku::check_column(int to_check, int position, int board[])
{
  	if(to_check == 0)
	  cerr << "to_check = 0\n";
	int column = position%9;
	for(int i = 0; i < 9; i++)
	{
		if(to_check == board[(9*i)+column])
		  return false;
	}
	return true;
}
bool Sudoku::check_cell(int to_check, int position, int board[])
{
  	if(to_check == 0)
	  cerr << "to_check = 0\n";
	int cell = (position/27)*3 + (position%9)/3;
	for(int i = 0; i < 9; i++)
	{
		if(to_check == board[(cell/3)*27 + (cell%3)*3 + (i/3)*9 + i%3])
		  return false;
	}
	return true;
}

