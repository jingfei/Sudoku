#include<iostream>
#include<fstream>
#include<cstdlib>
#include"Sudoku.h"
using namespace std;

Sudoku::Sudoku()
{
	ansn = 0;
	ze_total = 0;
	for (int i = 0;i < sudokuSize; ++i){
		init_map[i] = 0;
		map[i] = 0;
		ans_map[i];
	}
}

int Sudoku::ReadIn()
{
	int i,j;
	i = 0;
	j = 0;
	while(i < sudokuSize){
		cin >> init_map[i];
		map[i] = init_map[i];
		if (init_map[i] == 0){
			record.at(j) = i;
			j++;
		}
		i++;
	}
	ze_total = j;
	return j - 1;
}

bool Sudoku::Solve(int n)
{
	int i, j, l, row, col, m, num_a[9], ze_th, chk, stp, num_chk[9];
	for (i = 0;i < 9;i++)
		num_a[i] = i + 1;
	
	ze_th = record.at(n);
	chk = ze_th % 9;
	while (chk < 81){
		for (i = 0;i < 9;i++){
			if(map[chk] == num_a[i])
				num_a[i] = 0;
		}
		chk = chk + 9;		

	}
	chk = ze_th / 9;
	chk = chk * 9;
	i = 0;
	while (i < 9){	
		for (j = 0;j < 9;j++){
			if(map[chk + i] == num_a[j])
				num_a[i] = 0;
		}
		i++;
	}
	i = 0;
	while (i < 9){
		while(num_a[i] == 0){
			i++;
			if (i == 9){
				return false;
			}
		}
		map[ze_th] = num_a[i];

		stp = n;
		if (stp == 0){
			for (row = 0;row < 9;row + 3){
				for (col = 0;col < 9;col + 3){
					for (m = 0;m < 9;m++)
						num_chk[m] = m + 1;
					for (j = 0;j < 9;j++)
						for (m = 0;m < 3;m++){
							if (map[(row * 9 + m) + col * 9] == num_chk[j])
								num_chk[j] = 0;
							if (map[(row * 9 + m) + col * 9 + 1] == num_chk[j])
								num_chk[j] = 0;
							if (map[(row * 9 + m) + col * 9 + 2] == num_chk[j])
								num_chk[j] = 0;	
						}
					for (j = 0;j < 9;j++)
						if (num_chk[j] != 0){
							return false;
							break;
						}					
				}																					if (row == 6 && col == 6){
					ansn++;			
					for (l = 0;l < sudokuSize;l++)
						ans_map[i] = map[i];
					i++;
				}
	
			}
		}
		if(Solve(n - 1) == false)i++;
	}		
}
	
int Sudoku::Getelements (int i)
{
	return ans_map[i];
}

int Sudoku::Getansn ()
{
	return ansn;
}






	


















	
