#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku():counter(0)
{
	int i;
	for(i=0; i<sudokuSize; i++)
		map[i] = 0;
}

Sudoku::Sudoku(int init_map[]):counter(0)
{
	set_map(init_map);
}

void Sudoku::set_element(int index, int value)
{
	map[index] = value;
}

int Sudoku::get_element(int index)
{
	return map[index];
}

void Sudoku::set_map(int arr[])
{
	int i;
	for(i=0; i<sudokuSize; i++)
		map[i] = arr[i];
}

int Sudoku::find_zero()
{
	int i;

	for(i=0; i<sudokuSize; i++)
	{
		if(map[i] == 0)
			return i;
	}

	return -1;

}

bool Sudoku::check_correct(int arr[])
{
	int for_check[9], i, j, index;

	for(i=0; i<sudokuSize; i+=9)
	{
		for(j=0; j<9; j++)
			for_check[j] = map[i+j];
		if(check_unity(for_check)==false)
			return false;				
	}

	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
			for_check[j] = map[i+j*9];
		if(check_unity(for_check)==false)
			return false;
	}

	for(i=0; i<9; i++)
	{
		for(j=0; j<9; j++)
		{
			index = (i%3)*3 + (i/3)*27 + (j%3) + 9*(j/3) ;
			for_check[j] = map[index];
		}
		if(check_unity(for_check)==false)
			return false;
	}

	return true;
}

void Sudoku::output_map()
{
	int i;
	for(i=0; i<sudokuSize; i++)
	{
		cout << map[i] << " ";
		if(i%9==8) cout <<endl;
	}
}

void Sudoku::GiveQuestion()
{
	int i;
	srand(time(NULL));
	i = rand() % 2;

	switch(i)
	{
		case 1:
			{
				cout << "0 8 0 0 0 2 7 1 9" <<endl;
				cout << "4 6 7 3 0 0 0 2 0" <<endl;
				cout << "9 0 2 0 0 7 3 4 0" <<endl;
				cout << "1 0 0 0 0 6 2 5 0" <<endl;
				cout << "0 0 6 0 7 0 8 3 1" <<endl;
				cout << "0 0 8 0 2 0 0 9 4" <<endl;
				cout << "8 2 0 4 0 0 0 7 5" <<endl;
				cout << "0 0 0 2 5 9 1 0 0" <<endl;
				cout << "5 0 3 7 1 8 0 0 0" <<endl;
				break;
			}
		case 2:
			{
				cout << "9 0 0 0 4 7 0 5 3" <<endl;
				cout << "0 4 0 0 2 0 0 7 1" <<endl;
				cout << "0 1 0 8 0 0 0 0 0" <<endl;
				cout << "0 0 5 0 0 0 0 1 9" <<endl;
				cout << "0 8 0 7 6 0 0 0 5" <<endl;
				cout << "0 0 0 0 9 1 4 0 6" <<endl;
				cout << "2 0 0 0 1 0 0 6 0" <<endl;
				cout << "0 0 8 0 0 9 0 0 0" <<endl;
				cout << "6 0 0 0 0 0 3 9 0" <<endl;
				break;
			}

		default:
			break;

	}
}

void Sudoku::ReadIn()
{
	int i;
	for(i=0; i<sudokuSize; i++)
		cin >> map[i];
}


void Sudoku::Solve()
{
	int i;
	my_solve();

	if(counter == 0)
		cout << 0;

	else if(counter == 1)
	{
		cout << 1 << endl;
		for(i=0; i<sudokuSize; i++)
		{
			cout << answer[i] << " ";
			if(i%9==8) cout <<endl;
		}
	}

	else
		cout << 2;

}

		void my_solve()
		{
			int index, count=0, i, j, k;

			index = find_zero();
			

					
			if(index == -1)
			{
				if(check_correct(map)==true)
				{
					for(i=0; i<sudokuSize; i++)
						answer[i] = map[i];
					counter++;
				}
				else return;
			}
			
			else
			{
				if(index >= 0 && index < 9)
				{	
					for(i=1; i<=9; i++)
					{
						set_element(index, i);
						
						for(j=0; j<9; j++)
						{
							if(j==index)	continue;
							else if(map[index] == map[j])
								break;
							else	count++;
						}
						
						if(count!=8)
						{
							count = 0;
							continue;
						}	
						else
						{
							count =0;

							for(k=1; k<9; k++)
							{
								if(map[index] == map[index+k*9])
									break;
								else count++; 
								
							}
							if(count!=8)
							{
								count = 0;
								continue;
							}
							else
							{
								
								switch(index)
								{
									case 0:
										{
											if(map[index] == map[1] || map[index] == map[2]
											|| map[index] == map[9]	|| map[index] == map[10]
											|| map[index] == map[11]|| map[index] == map[18]
											|| map[index] == map[19]|| map[index] == map[20])
											{
												count = 0;
												break;
											}
											else
											{
												count = 1;
												break;
											}
										}
									case 1:
										{
											if(map[index] == map[0] || map[index] == map[2]
											|| map[index] == map[9]	|| map[index] == map[10]
											|| map[index] == map[11]|| map[index] == map[18]
											|| map[index] == map[19]|| map[index] == map[20])
											{
												count = 0;
												break;
											}
											else
											{
												count = 1;
												break;
											}
										}
									case 2:
										{
											if(map[index] == map[0] || map[index] == map[1]
											|| map[index] == map[9]	|| map[index] == map[10]
											|| map[index] == map[11]|| map[index] == map[18]
											|| map[index] == map[19]|| map[index] == map[20])
											{
												count = 0;
												break;
											}
											else
											{
												count = 1;
												break;
											}
										}
									case 3:
										{
											if(map[index] == map[4] || map[index] == map[5]
											|| map[index] == map[12]|| map[index] == map[13]
											|| map[index] == map[14]|| map[index] == map[21]
											|| map[index] == map[22]|| map[index] == map[23])
											{
												count = 0;
												break;
											}
											else
											{
												count = 1;
												break;
											}
										}
									case 4:
										{
											if(map[index] == map[3] || map[index] == map[5]
											|| map[index] == map[12]|| map[index] == map[13]
											|| map[index] == map[14]|| map[index] == map[21]
											|| map[index] == map[22]|| map[index] == map[23])
											{
												count = 0;
												break;
											}
											else
											{
												count = 1;
												break;
											}
										}
									case 5:
										{
											if(map[index] == map[3] || map[index] == map[4]
											|| map[index] == map[12]|| map[index] == map[13]
											|| map[index] == map[14]|| map[index] == map[21]
											|| map[index] == map[22]|| map[index] == map[23])
											{
												count = 0;
												break;
											}
											else
											{
												count = 1;
												break;
											}
										}
									case 6:
										{
											if(map[index] == map[7] || map[index] == map[8]
											|| map[index] == map[15]|| map[index] == map[16]
											|| map[index] == map[17]|| map[index] == map[24]
											|| map[index] == map[25]|| map[index] == map[26])
											{
												count = 0;
												break;
											}
											else
											{
												count = 1;
												break;
											}
										}
									case 7:
										{
											if(map[index] == map[6] || map[index] == map[8]
											|| map[index] == map[15]|| map[index] == map[16]
											|| map[index] == map[17]|| map[index] == map[24]
											|| map[index] == map[25]|| map[index] == map[26])
											{
												count = 0;
												break;
											}
											else
											{
												count = 1;
												break;
											}
										}
									case 8:
										{
											if(map[index] == map[6] || map[index] == map[7]
											|| map[index] == map[15]|| map[index] == map[16]
											|| map[index] == map[17]|| map[index] == map[24]
											|| map[index] == map[25]|| map[index] == map[26])
											{
												count = 0;
												break;
											}
											else
											{
												count = 1;
												break;
											}
										}
																
										default: break;
									}
									
								if(count == 0)
									continue;
								else
								{
									my_solve();
									set_element(index, 0);
								}
							}
						}
					}
					
				}
			
			
				else if(index < 18)
				{
					for(i=1; i<=9; i++)
					{
						set_element(index, i);
						for(j=9; j<18; j++)
						{
							if(j==index)	continue;
							else if(map[index] == map[j])
								break;
							else	count++;
						}
						
						if(count!=8)
						{
							count = 0;
							continue;
						}	
						else
						{
							count =0;
							
							for(k=-1; k<8; k++)
							{
								if(k==0)	continue;
								else if(map[index] == map[index+k*9])
									break;
								else count++; 
								
							}
							if(count!=8)
							{
								count = 0;
								continue;
							}
							else
							{   	
								switch(index)
								{
										case 9:
											{
												if(map[index] == map[0] || map[index] == map[1]
												|| map[index] == map[2]	|| map[index] == map[10]
												|| map[index] == map[11]|| map[index] == map[18]
												|| map[index] == map[19]|| map[index] == map[20])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 10:
											{
												if(map[index] == map[0] || map[index] == map[1]
												|| map[index] == map[2]	|| map[index] == map[9]
												|| map[index] == map[11]|| map[index] == map[18]
												|| map[index] == map[19]|| map[index] == map[20])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 11:
											{
												if(map[index] == map[0] || map[index] == map[1]
												|| map[index] == map[2]	|| map[index] == map[9]
												|| map[index] == map[10]|| map[index] == map[18]
												|| map[index] == map[19]|| map[index] == map[20])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 12:
											{
												if(map[index] == map[3] || map[index] == map[4]
												|| map[index] == map[5]	|| map[index] == map[13]
												|| map[index] == map[14]|| map[index] == map[21]
												|| map[index] == map[22]|| map[index] == map[23])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 13:
											{
												if(map[index] == map[3] || map[index] == map[4]
												|| map[index] == map[5]	|| map[index] == map[12]
												|| map[index] == map[14]|| map[index] == map[21]
												|| map[index] == map[22]|| map[index] == map[23])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 14:
											{
												if(map[index] == map[3] || map[index] == map[4]
												|| map[index] == map[5]	|| map[index] == map[12]
												|| map[index] == map[13]|| map[index] == map[21]
												|| map[index] == map[22]|| map[index] == map[23])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 15:
											{
												if(map[index] == map[6] || map[index] == map[7]
												|| map[index] == map[8]	|| map[index] == map[16]
												|| map[index] == map[17]|| map[index] == map[24]
												|| map[index] == map[25]|| map[index] == map[26])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 16:
											{
												if(map[index] == map[6] || map[index] == map[7]
												|| map[index] == map[8]	|| map[index] == map[15]
												|| map[index] == map[17]|| map[index] == map[24]
												|| map[index] == map[25]|| map[index] == map[26])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 17:
											{
												if(map[index] == map[6] || map[index] == map[7]
												|| map[index] == map[8]	|| map[index] == map[15]
												|| map[index] == map[16]|| map[index] == map[24]
												|| map[index] == map[25]|| map[index] == map[26])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
																
										default: break;
									}
									
									
								if(count == 0)
									continue;
								else
								{
									my_solve();
									set_element(index, 0);
								}
							}
						}
					}
				}
				else if(index < 27)
				{
					for(i=1; i<=9; i++)
					{
						set_element(index, i);
						for(j=18; j<27; j++)
						{
							if(j==index)	continue;
							else if(map[index] == map[j])
								break;
							else	count++;
						}
						
						if(count!=8)
						{
							count = 0;
							continue;
						}	
						else
						{
							count =0;
							
							for(k=-2; k<7; k++)
							{
								if(k==0)	continue;
								else if(map[index] == map[index+k*9])
									break;
								else count++; 
								
							}
							if(count!=8)
							{
								count = 0;
								continue;
							}
							else
							{
								
   	
								switch(index)
								{
										case 18:
											{
												if(map[index] == map[0] || map[index] == map[1]
												|| map[index] == map[2]	|| map[index] == map[9]
												|| map[index] == map[10]|| map[index] == map[11]
												|| map[index] == map[19]|| map[index] == map[20])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 19:
											{
												if(map[index] == map[0] || map[index] == map[1]
												|| map[index] == map[2]	|| map[index] == map[9]
												|| map[index] == map[10]|| map[index] == map[11]
												|| map[index] == map[18]|| map[index] == map[20])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 20:
											{
												if(map[index] == map[0] || map[index] == map[1]
												|| map[index] == map[2]	|| map[index] == map[9]
												|| map[index] == map[10]|| map[index] == map[11]
												|| map[index] == map[18]|| map[index] == map[19])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 21:
											{
												if(map[index] == map[3] || map[index] == map[4]
												|| map[index] == map[5]	|| map[index] == map[12]
												|| map[index] == map[13]|| map[index] == map[14]
												|| map[index] == map[22]|| map[index] == map[23])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 22:
											{
												if(map[index] == map[3] || map[index] == map[4]
												|| map[index] == map[5]	|| map[index] == map[12]
												|| map[index] == map[13]|| map[index] == map[14]
												|| map[index] == map[21]|| map[index] == map[23])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 23:
											{
												if(map[index] == map[3] || map[index] == map[4]
												|| map[index] == map[5]	|| map[index] == map[12]
												|| map[index] == map[13]|| map[index] == map[14]
												|| map[index] == map[21]|| map[index] == map[22])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 24:
											{
												if(map[index] == map[6] || map[index] == map[7]
												|| map[index] == map[8]	|| map[index] == map[15]
												|| map[index] == map[16]|| map[index] == map[17]
												|| map[index] == map[25]|| map[index] == map[26])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 25:
											{
												if(map[index] == map[6] || map[index] == map[7]
												|| map[index] == map[8]	|| map[index] == map[15]
												|| map[index] == map[16]|| map[index] == map[17]
												|| map[index] == map[24]|| map[index] == map[26])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 26:
											{
												if(map[index] == map[6] || map[index] == map[7]
												|| map[index] == map[8]	|| map[index] == map[15]
												|| map[index] == map[16]|| map[index] == map[17]
												|| map[index] == map[24]|| map[index] == map[25])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
																
										default: break;
									}
									
									
								if(count == 0)
									continue;
								else
								{
									my_solve();
									set_element(index, 0);
								}
							}
						}
						
					}
				}
				else if(index < 36)
				{
					for(i=1; i<=9; i++)
					{
						set_element(index, i);
						for(j=27; j<36; j++)
						{
							if(j==index)	continue;
							else if(map[index] == map[j])
								break;
							else	count++;
						}
						
						if(count!=8)
						{
							count = 0;
							continue;
						}	
						else
						{
							count =0;
							
							for(k=-3; k<6; k++)
							{
								if(k==0)	continue;
								else if(map[index] == map[index+k*9])
									break;
								else count++; 
								
							}
							if(count!=8)
							{
								count = 0;
								continue;
							}
							else
							{
								
   	
								switch(index)
								{
										case 27:
											{
												if(map[index] == map[28] || map[index] == map[29]
												|| map[index] == map[36] || map[index] == map[37]
												|| map[index] == map[38] || map[index] == map[45]
												|| map[index] == map[46] || map[index] == map[47])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 28:
											{
												if(map[index] == map[27] || map[index] == map[29]
												|| map[index] == map[36] || map[index] == map[37]
												|| map[index] == map[38] || map[index] == map[45]
												|| map[index] == map[46] || map[index] == map[47])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 29:
											{
												if(map[index] == map[27] || map[index] == map[28]
												|| map[index] == map[36] || map[index] == map[37]
												|| map[index] == map[38] || map[index] == map[45]
												|| map[index] == map[46] || map[index] == map[47])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 30:
											{
												if(map[index] == map[31] || map[index] == map[32]
												|| map[index] == map[39] || map[index] == map[40]
												|| map[index] == map[41] || map[index] == map[48]
												|| map[index] == map[49] || map[index] == map[50])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 31:
											{
												if(map[index] == map[30] || map[index] == map[32]
												|| map[index] == map[39] || map[index] == map[40]
												|| map[index] == map[41] || map[index] == map[48]
												|| map[index] == map[49] || map[index] == map[50])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 32:
											{
												if(map[index] == map[30] || map[index] == map[31]
												|| map[index] == map[39] || map[index] == map[40]
												|| map[index] == map[41] || map[index] == map[48]
												|| map[index] == map[49] || map[index] == map[50])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 33:
											{
												if(map[index] == map[34] || map[index] == map[35]
												|| map[index] == map[42] || map[index] == map[43]
												|| map[index] == map[44] || map[index] == map[51]
												|| map[index] == map[52] || map[index] == map[53])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 34:
											{
												if(map[index] == map[33] || map[index] == map[35]
												|| map[index] == map[42] || map[index] == map[43]
												|| map[index] == map[44] || map[index] == map[51]
												|| map[index] == map[52] || map[index] == map[53])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 35:
											{
												if(map[index] == map[33] || map[index] == map[34]
												|| map[index] == map[42] || map[index] == map[43]
												|| map[index] == map[44] || map[index] == map[51]
												|| map[index] == map[52] || map[index] == map[53])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
																
										default: break;
									}
									
									
								if(count == 0)
									continue;
								else
								{
									my_solve();
									set_element(index, 0);
								}
							}
						}
						
						
					}
				}
			
				else if(index < 45)
				{
					for(i=1; i<=9; i++)
					{
						set_element(index, i);
						for(j=36; j<45; j++)
						{
							if(j==index)	continue;
							else if(map[index] == map[j])
								break;
							else	count++;
						}
						
						if(count!=8)
						{
							count = 0;
							continue;
						}	
						else
						{
							count =0;
							
							for(k=-4; k<5; k++)
							{
								if(k==0)	continue;
								else if(map[index] == map[index+k*9])
									break;
								else count++; 
								
							}
							if(count!=8)
							{
								count = 0;
								continue;
							}
							else
							{
								
   	
								switch(index)
								{
										case 36:
											{
												if(map[index] == map[27] || map[index] == map[28]
												|| map[index] == map[29] || map[index] == map[37]
												|| map[index] == map[38] || map[index] == map[45]
												|| map[index] == map[46] || map[index] == map[47])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 37:
											{
												if(map[index] == map[27] || map[index] == map[28]
												|| map[index] == map[29] || map[index] == map[36]
												|| map[index] == map[38] || map[index] == map[45]
												|| map[index] == map[46] || map[index] == map[47])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 38:
											{
												if(map[index] == map[27] || map[index] == map[28]
												|| map[index] == map[29] || map[index] == map[36]
												|| map[index] == map[37] || map[index] == map[45]
												|| map[index] == map[46] || map[index] == map[47])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 39:
											{
												if(map[index] == map[30] || map[index] == map[31]
												|| map[index] == map[32] || map[index] == map[40]
												|| map[index] == map[41] || map[index] == map[48]
												|| map[index] == map[49] || map[index] == map[50])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 40:
											{
												if(map[index] == map[30] || map[index] == map[31]
												|| map[index] == map[32] || map[index] == map[39]
												|| map[index] == map[41] || map[index] == map[48]
												|| map[index] == map[49] || map[index] == map[50])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 41:
											{
												if(map[index] == map[30] || map[index] == map[31]
												|| map[index] == map[32] || map[index] == map[39]
												|| map[index] == map[40] || map[index] == map[48]
												|| map[index] == map[49] || map[index] == map[50])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 42:
											{
												if(map[index] == map[33] || map[index] == map[34]
												|| map[index] == map[35] || map[index] == map[43]
												|| map[index] == map[44] || map[index] == map[51]
												|| map[index] == map[52] || map[index] == map[53])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 43:
											{
												if(map[index] == map[33] || map[index] == map[34]
												|| map[index] == map[35] || map[index] == map[42]
												|| map[index] == map[44] || map[index] == map[51]
												|| map[index] == map[52] || map[index] == map[53])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 44:
											{
												if(map[index] == map[33] || map[index] == map[34]
												|| map[index] == map[35] || map[index] == map[42]
												|| map[index] == map[43] || map[index] == map[51]
												|| map[index] == map[52] || map[index] == map[53])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
																
										default: break;
									}
									
									
								if(count == 0)
									continue;
								else
								{
									my_solve();
									set_element(index, 0);
								}
							}
						}
						
						
					}
				}
				
				else if(index < 54)
				{
					for(i=1; i<=9; i++)
					{
						set_element(index, i);
						for(j=45; j<54; j++)
						{
							if(j==index)	continue;
							else if(map[index] == map[j])
								break;
							else	count++;
						}
						
						if(count!=8)
						{
							count = 0;
							continue;
						}	
						else
						{
							count =0;
							
							for(k=-5; k<4; k++)
							{
								if(k==0)	continue;
								else if(map[index] == map[index+k*9])
									break;
								else count++; 
								
							}
							if(count!=8)
							{
								count = 0;
								continue;
							}
							else
							{
								
   	
								switch(index)
								{
										case 45:
											{
												if(map[index] == map[27] || map[index] == map[28]
												|| map[index] == map[29] || map[index] == map[36]
												|| map[index] == map[37] || map[index] == map[38]
												|| map[index] == map[46] || map[index] == map[47])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 46:
											{
												if(map[index] == map[27] || map[index] == map[28]
												|| map[index] == map[29] || map[index] == map[36]
												|| map[index] == map[37] || map[index] == map[38]
												|| map[index] == map[45] || map[index] == map[47])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 47:
											{
												if(map[index] == map[27] || map[index] == map[28]
												|| map[index] == map[29] || map[index] == map[36]
												|| map[index] == map[37] || map[index] == map[38]
												|| map[index] == map[45] || map[index] == map[46])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 48:
											{
												if(map[index] == map[30] || map[index] == map[31]
												|| map[index] == map[32] || map[index] == map[39]
												|| map[index] == map[40] || map[index] == map[41]
												|| map[index] == map[49] || map[index] == map[50])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 49:
											{
												if(map[index] == map[30] || map[index] == map[31]
												|| map[index] == map[32] || map[index] == map[39]
												|| map[index] == map[40] || map[index] == map[41]
												|| map[index] == map[48] || map[index] == map[50])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 50:
											{
												if(map[index] == map[30] || map[index] == map[31]
												|| map[index] == map[32] || map[index] == map[39]
												|| map[index] == map[40] || map[index] == map[41]
												|| map[index] == map[48] || map[index] == map[49])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 51:
											{
												if(map[index] == map[33] || map[index] == map[34]
												|| map[index] == map[35] || map[index] == map[42]
												|| map[index] == map[43] || map[index] == map[44]
												|| map[index] == map[52] || map[index] == map[53])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 52:
											{
												if(map[index] == map[33] || map[index] == map[34]
												|| map[index] == map[35] || map[index] == map[42]
												|| map[index] == map[43] || map[index] == map[44]
												|| map[index] == map[51] || map[index] == map[53])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 53:
											{
												if(map[index] == map[33] || map[index] == map[34]
												|| map[index] == map[35] || map[index] == map[42]
												|| map[index] == map[43] || map[index] == map[44]
												|| map[index] == map[51] || map[index] == map[52])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
																
										default: break;
									}
									
									
								if(count == 0)
									continue;
								else
								{
									my_solve();
									set_element(index, 0);
								}
							}
						}
						
						
					}
				}
		
				else if(index < 63)
				{
					for(i=1; i<=9; i++)
					{
						set_element(index, i);
						for(j=54; j<63; j++)
						{
							if(j==index)	continue;
							else if(map[index] == map[j])
								break;
							else	count++;
						}
						
						if(count!=8)
						{
							count = 0;
							continue;
						}	
						else
						{
							count =0;
							
							for(k=-6; k<3; k++)
							{
								if(k==0)	continue;
								else if(map[index] == map[index+k*9])
									break;
								else count++; 
								
							}
							if(count!=8)
							{
								count = 0;
								continue;
							}
							else
							{
								
   	
								switch(index)
								{
										case 54:
											{
												if(map[index] == map[55] || map[index] == map[56]
												|| map[index] == map[63] || map[index] == map[64]
												|| map[index] == map[65] || map[index] == map[72]
												|| map[index] == map[73] || map[index] == map[74])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 55:
											{
												if(map[index] == map[54] || map[index] == map[56]
												|| map[index] == map[63] || map[index] == map[64]
												|| map[index] == map[65] || map[index] == map[72]
												|| map[index] == map[73] || map[index] == map[74])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 56:
											{
												if(map[index] == map[54] || map[index] == map[55]
												|| map[index] == map[63] || map[index] == map[64]
												|| map[index] == map[65] || map[index] == map[72]
												|| map[index] == map[73] || map[index] == map[74])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 57:
											{
												if(map[index] == map[58] || map[index] == map[59]
												|| map[index] == map[66] || map[index] == map[67]
												|| map[index] == map[68] || map[index] == map[75]
												|| map[index] == map[76] || map[index] == map[77])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 58:
											{
												if(map[index] == map[57] || map[index] == map[59]
												|| map[index] == map[66] || map[index] == map[67]
												|| map[index] == map[68] || map[index] == map[75]
												|| map[index] == map[76] || map[index] == map[77])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 59:
											{
												if(map[index] == map[57] || map[index] == map[58]
												|| map[index] == map[66] || map[index] == map[67]
												|| map[index] == map[68] || map[index] == map[75]
												|| map[index] == map[76] || map[index] == map[77])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 60:
											{
												if(map[index] == map[61] || map[index] == map[62]
												|| map[index] == map[69] || map[index] == map[70]
												|| map[index] == map[71] || map[index] == map[78]
												|| map[index] == map[79] || map[index] == map[80])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 61:
											{
												if(map[index] == map[60] || map[index] == map[62]
												|| map[index] == map[69] || map[index] == map[70]
												|| map[index] == map[71] || map[index] == map[78]
												|| map[index] == map[79] || map[index] == map[80])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 62:
											{
												if(map[index] == map[60] || map[index] == map[61]
												|| map[index] == map[69] || map[index] == map[70]
												|| map[index] == map[71] || map[index] == map[78]
												|| map[index] == map[79] || map[index] == map[80])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
																
										default: break;
									}
									
									
								if(count == 0)
									continue;
								else
								{
									my_solve();
									set_element(index, 0);
								}
							}
						}
						
						
					}
				}
				else if(index < 72)
				{
					for(i=1; i<=9; i++)
					{
						set_element(index, i);
						for(j=63; j<72; j++)
						{
							if(j==index)	continue;
							else if(map[index] == map[j])
								break;
							else	count++;
						}
						
						if(count!=8)
						{
							count = 0;
							continue;
						}	
						else
						{
							count =0;
							
							for(k=-7; k<2; k++)
							{
								if(k==0)	continue;
								else if(map[index] == map[index+k*9])
									break;
								else count++; 
								
							}
							if(count!=8)
							{
								count = 0;
								continue;
							}
							else
							{
								
   	
								switch(index)
								{
										case 63:
											{
												if(map[index] == map[54] || map[index] == map[55]
												|| map[index] == map[56] || map[index] == map[64]
												|| map[index] == map[65] || map[index] == map[72]
												|| map[index] == map[73] || map[index] == map[74])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 64:
											{
												if(map[index] == map[54] || map[index] == map[55]
												|| map[index] == map[56] || map[index] == map[63]
												|| map[index] == map[65] || map[index] == map[72]
												|| map[index] == map[73] || map[index] == map[74])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 65:
											{
												if(map[index] == map[54] || map[index] == map[55]
												|| map[index] == map[56] || map[index] == map[63]
												|| map[index] == map[64] || map[index] == map[72]
												|| map[index] == map[73] || map[index] == map[74])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 66:
											{
												if(map[index] == map[57] || map[index] == map[58]
												|| map[index] == map[59] || map[index] == map[67]
												|| map[index] == map[68] || map[index] == map[75]
												|| map[index] == map[76] || map[index] == map[77])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 67:
											{
												if(map[index] == map[57] || map[index] == map[58]
												|| map[index] == map[59] || map[index] == map[66]
												|| map[index] == map[68] || map[index] == map[75]
												|| map[index] == map[76] || map[index] == map[77])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 68:
											{
												if(map[index] == map[57] || map[index] == map[58]
												|| map[index] == map[59] || map[index] == map[66]
												|| map[index] == map[67] || map[index] == map[75] 
												|| map[index] == map[76] || map[index] == map[77])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 69:
											{
												if(map[index] == map[60] || map[index] == map[61]
												|| map[index] == map[62] || map[index] == map[70]
												|| map[index] == map[71] || map[index] == map[78]
												|| map[index] == map[79] || map[index] == map[80])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 70:
											{
												if(map[index] == map[60] || map[index] == map[61]
												|| map[index] == map[62] || map[index] == map[69]
												|| map[index] == map[71] || map[index] == map[78]
												|| map[index] == map[79] || map[index] == map[80])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 71:
											{
												if(map[index] == map[60] || map[index] == map[61]
												|| map[index] == map[62] || map[index] == map[69]
												|| map[index] == map[70] || map[index] == map[78]
												|| map[index] == map[79] || map[index] == map[80])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
																
										default: break;
									}
									
									
								if(count == 0)
									continue;
								else
								{
									my_solve();
									set_element(index, 0);
								}
							}
						}
						
					}
				}
				
				else if(index < 81)
				{
					for(i=1; i<=9; i++)
					{
						set_element(index, i);
						for(j=72; j<81; j++)
						{
							if(j==index)	continue;
							else if(map[index] == map[j])
								break;
							else	count++;
						}
						
						if(count!=8)
						{
							count = 0;
							continue;
						}	
						else
						{
							count =0;
							
							for(k=-8; k<1; k++)
							{
								if(k==0)	continue;
								else if(map[index] == map[index+k*9])
									break;
								else count++; 
								
							}
							if(count!=8)
							{
								count = 0;
								continue;
							}
							else
							{
								
   	
								switch(index)
								{
										case 72:
											{
												if(map[index] == map[54] || map[index] == map[55]
												|| map[index] == map[56] || map[index] == map[63]
												|| map[index] == map[64] || map[index] == map[65]
												|| map[index] == map[73] || map[index] == map[74])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 73:
											{
												if(map[index] == map[54] || map[index] == map[55]
												|| map[index] == map[56] || map[index] == map[63]
												|| map[index] == map[64] || map[index] == map[65]
												|| map[index] == map[72] || map[index] == map[74])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 74:
											{
												if(map[index] == map[54] || map[index] == map[55]
												|| map[index] == map[56] || map[index] == map[63]
												|| map[index] == map[64] || map[index] == map[65]
												|| map[index] == map[72] || map[index] == map[73])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 75:
											{
												if(map[index] == map[57] || map[index] == map[58]
												|| map[index] == map[59] || map[index] == map[66]
												|| map[index] == map[67] || map[index] == map[68]
												|| map[index] == map[76] || map[index] == map[77])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 76:
											{
												if(map[index] == map[57] || map[index] == map[58]
												|| map[index] == map[59] || map[index] == map[66]
												|| map[index] == map[67] || map[index] == map[68]
												|| map[index] == map[75] || map[index] == map[77])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 77:
											{
												if(map[index] == map[57] || map[index] == map[58]
												|| map[index] == map[59] || map[index] == map[66]
												|| map[index] == map[67] || map[index] == map[68]
												|| map[index] == map[75] || map[index] == map[76])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 78:
											{
												if(map[index] == map[60] || map[index] == map[61]
												|| map[index] == map[62] || map[index] == map[69]
												|| map[index] == map[70] || map[index] == map[71]
												|| map[index] == map[79] || map[index] == map[80])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 79:
											{
												if(map[index] == map[60] || map[index] == map[61]
												|| map[index] == map[62] || map[index] == map[69]
												|| map[index] == map[70] || map[index] == map[71]
												|| map[index] == map[78] || map[index] == map[80])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
										case 80:
											{
												if(map[index] == map[60] || map[index] == map[61]
												|| map[index] == map[62] || map[index] == map[69]
												|| map[index] == map[70] || map[index] == map[71]
												|| map[index] == map[78] || map[index] == map[79])
												{
													count = 0;
													break;
												}
												else
												{
													count = 1;
													break;
												}
											}
																
										default: break;
									}
									
									
								if(count == 0)
									continue;
								else
								{
									my_solve();
									set_element(index, 0);
								}
							}
						}
						
						
					}
				}
			}
		}

bool Sudoku::check_unity(int arr[9])	
{
	int i, check_unity[9];

	for(i=0; i<9; ++i)
		check_unity[i] = 0;

	for(i=0; i<9; i++)
		check_unity[arr[i]-1]++;

	for(i=0; i<9; i++)
	{
		if(check_unity[i]!=1)
			return false;
	}

	return true;
}
