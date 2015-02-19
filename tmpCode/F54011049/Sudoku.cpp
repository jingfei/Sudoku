#include "Sudoku.h"

#define MAX_CASE 100

using namespace std;

Sudoku::Sudoku ()
{
	for (int i = 0; i < sudokuSize; i++)
		map[i] = 0;
}

Sudoku::Sudoku (const int init_map[])
{
	for (int i = 0; i < sudokuSize; i++)
		map[i] = init_map[i];
}

void Sudoku::setMap (const int set_map[])
{
	for (int i = 0; i < sudokuSize; i++)
		map[i] = set_map[i];
}

int Sudoku::getElement (int index)
{
	return map[index];
}

void Sudoku::setElement(int index, int value)
{
	map[index] = value;
}

int Sudoku::getFirstZeroIndex()
{
	for (int i = 0; i < sudokuSize; i++)
		if (map[i] == 0)
			return i;
	return -1;
}

bool Sudoku::checkUnity (int arr[])
{
	int arr_unity[10];

	for (int i = 0; i < 10; i++)
		arr_unity[i] = 0;
	for (int i = 0; i < 9; i++)
		arr_unity[arr[i]] ++;  //  count

	for (int i = 1; i < 10; i++) {  //  all element must be 1
		if (arr_unity[i] > 1)
			return false;
	}
	return true;
}

bool Sudoku::isCorrect ()
{
	bool check_result;
	int check_arr[9];
	int location;
	for (int i = 0; i < 81; i += 9) {  //  check rows
		for (int j = 0; j < 9; j++)
			check_arr[j] = map[i+j];
		check_result = checkUnity (check_arr);
		if (check_result == false)
			return false;
	}													

	for (int i = 0; i < 9; i++) {  //  check columns
		for (int j = 0; j < 9; j++)
			check_arr[j] = map[i+9*j];
		check_result = checkUnity (check_arr);
		if (check_result == false)
			return false;
	}												

	for (int i = 0; i < 9; i++) {  //  check cells
		for (int j = 0; j < 9; j++) {
			location = 27*(i/3) + 3*(i%3) + 9*(j/3) + (j%3);
			check_arr[j] = map[location];
		}
		check_result = checkUnity (check_arr);
		if (check_result == false)
			return false;
	}													

	return true;
}

void Sudoku::GiveQuestion ()
{
	int map[81] = {0};
	int list[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int set_zero[81];
	int k, tmp;

	srand (time (NULL));

	for (int i = 0; i < 9; i++) {
		k = rand () % 9;
		tmp = list[i];
		list[i] = list[k];
		list[k] = tmp;
	}

	for (int i = 0; i < 81; i++)
		set_zero[i] = i;
	for (int i = 0; i < 81; i++) {
		k = rand () % 81;
		tmp = set_zero[i];
		set_zero[i] = set_zero[k];
		set_zero[k] = set_zero[i];
	}

	map[7] = map[12] = map[19] = map[31] = map[38] = map[53] = map[59] = map[69] = map[72] = list[0];
	map[3] = map[9]  = map[24] = map[34] = map[40] = map[47] = map[55] = map[71] = map[77] = list[1];
	map[4] = map[16] = map[20] = map[32] = map[37] = map[51] = map[62] = map[63] = map[75] = list[2];
	map[8] = map[14] = map[18] = map[30] = map[43] = map[46] = map[60] = map[65] = map[76] = list[3];
	map[2] = map[15] = map[22] = map[35] = map[36] = map[50] = map[57] = map[70] = map[73] = list[4];
	map[5] = map[10] = map[26] = map[29] = map[42] = map[49] = map[54] = map[66] = map[79] = list[5];
	map[6] = map[11] = map[23] = map[27] = map[39] = map[52] = map[58] = map[64] = map[80] = list[6];
	map[1] = map[17] = map[21] = map[33] = map[41] = map[45] = map[61] = map[67] = map[74] = list[7];
	map[0] = map[13] = map[25] = map[28] = map[44] = map[48] = map[56] = map[68] = map[78] = list[8];

	k = rand () % 25 + 35;

	for (int i = 0; i <= k; i++)
		map[set_zero[i]] = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 8; j++)
			cout << map[i*9+j] << " ";
		cout << map[i*9+8] << endl;
	}
}

void Sudoku::ReadIn ()
{
	int set_map[81];

	for (int i = 0; i < 81; i++)
		scanf ("%d", &set_map[i]);

	setMap (set_map);
}

bool Sudoku::Solve ()
{
	int firstZero;
	firstZero = getFirstZeroIndex();
	
	if (firstZero == -1) {  // end condition
		if(isCorrect ()) {
			cout << 1 << endl;
			for (int i = 0; i < 9; i++) {
				for (int j = 0; j < 8; j++)
					cout <<  map[i*9+j] << " ";
				cout << map[i*9+8] << endl;
			}
			return true;
		}
		else
			return false;
	}
	else {
		for (int num = 1; num <= 9; num++) {
			setElement(firstZero, num);
			if(isCorrect ()) {
				if (Solve ())
					return true;
			}
		}

		return false;
	}
}