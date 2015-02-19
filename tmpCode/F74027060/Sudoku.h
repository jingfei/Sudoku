#include"sudoku.h"

Sudoku::Sudoku(char *inname)
{
	int i=0, j=0; 
	int temp;  
	ifstream infile(inname); 
	if (!infile) 
	{ 
		cout << "There was a problem opening file " << inname << " for reading." << endl; 
	}  
	while (infile >> temp) 
	{ 
		num[i][j] = temp; i++; 
		if(i==9) 
		{ 
			j++; i=0; 
		} 
	} 
	for(int k=0; k<9;k++) 
	{ 
		for(int l=0; l<9;l++) 
		{ cout << num[k][l] << " "; 
		} 
		cout << endl; 
	}
	cout<<endl;
}

void Sudoku::setinput()
{
	cout << "Enter a Sudoku puzzle:" << endl;
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> num[i][j];
}

void Sudoku::getoutput()
{
	if (!isValid(num))
		cout << "Invalid input" << endl;
	else if (search(num))
	{
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
				cout<< num[i][j] << " ";
			cout << endl;
		}
	}
	else
		cout << "doesn't have solution" << endl;

}

int Sudoku::List(int grid[][9], int freeCellList[][2])
{

	int numberOfFreeCells = 0;

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (grid[i][j] == 0)
			{
				freeCellList[numberOfFreeCells][0] = i;
				freeCellList[numberOfFreeCells][1] = j;
				numberOfFreeCells++;
			}

			return numberOfFreeCells;
}


bool Sudoku::search(int num[][9])
{
	int k = 0; 
	bool found = false; 

	int freeCell[81][2];
	int numberOfFreeCells = List(num, freeCell);

	while (!found)
	{
		int i = freeCell[k][0];
		int j = freeCell[k][1];
		if (num[i][j] == 0)
			num[i][j] = 1; 

		if (isValid(i, j, num))
		{
			if (k + 1 == numberOfFreeCells)
			{ 
				found = true; 
			}
			else
			{ 
				k++;
			}
		}
		else if (num[i][j] < 9)
		{
			num[i][j] = num[i][j] + 1; 
		}
		else
		{ 
			while (num[i][j] == 9)
			{
				num[i][j] = 0; 
				if (k == 0)
				{
					return false; 
				}
				k--; 
				i = freeCell[k][0];
				j = freeCell[k][1];
			}

			num[i][j] = num[i][j] + 1; 
		}
	}

	return true; 
}


bool Sudoku::isValid(int i, int j, int num[][9])
{

	for (int column = 0; column < 9; column++)
		if (column != j && num[i][column] == num[i][j])
			return false;


	for (int row = 0; row < 9; row++)
		if (row != i && num[row][j] == num[i][j])
			return false;


	for (int row = (i / 3) * 3; row < (i / 3) * 3 + 3; row++)
		for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; col++)
			if (row != i && col != j && num[row][col] == num[i][j])
				return false;

	return true; 
}


bool Sudoku::isValid(int num[][9])
{

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (num[i][j] != 0)
				if (!isValid(i, j, num))
					return false;


	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if ((num[i][j] < 0) || (num[i][j] > 9))
				return false;

	return true; 
}