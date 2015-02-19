#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Sudoku.h"
using namespace std;



Sudoku::Sudoku() //Zero initialize
{
	for(int i=0; i<sudokuSize; ++i){
		map[i] = 0;
		zero_Place[i] = -1;}
}

Sudoku::Sudoku(const int init_map[])
{
	for(int i=0; i<sudokuSize; ++i){
		map[i] = init_map[i];
		zero_Place[i] = -1;}
}

void Sudoku::setMap(const int set_map[])
{
	for(int i=0; i<sudokuSize; ++i){
		map[i] = set_map[i];}
}

int Sudoku::getElement(int index)
{
	return map[index];
}

bool Sudoku::checkUnity(int arr[])
{
	int arr_unity[9]; 

	for(int i=0; i<9; ++i)
		arr_unity[i] = 0;
	for(int i=0; i<9; ++i)
		++arr_unity[arr[i]-1];
	for(int i=0; i<9; ++i)
		if(arr_unity[i] != 1)
			return false;
	return true;
}

bool Sudoku::isCorrect()
{
	bool check_result;
	int check_arr[9];
	int location;
	for(int i=0; i<81; i+=9)
	{
		for(int j=0; j<9; ++j)
			check_arr[j] = map[i+j];
		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	}
	for(int i=0; i<9; ++i)
	{
		for(int j=0; j<9; ++j)
			check_arr[ j] = map[i+9*j];
		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	} 
	for(int i=0; i<9; ++i)
	{
		for(int j=0; j<9; ++j)
		{
			location = 27*(i/3) + 3*(i%3)+9*( j/3) + ( j%3);
			check_arr[ j] = map[location];
		}
		check_result =
			checkUnity(check_arr);
		if(check_result == false)
			return false;
	}
	return true;
}


int Sudoku::ReadIn()
{
	int input, i=0, j=0, w=0, check[10]={0}, square;
	
	while(cin >> input){
		map[i] = input;
		if(map[i]==0){
			zero_Place[j] = i;
			j = j + 1;}
		i = i + 1;
		if(i >= 81) break;		
	}

	for(i=0; i<81; i++){   //debug(1~9)
		if(map[i]<0 || map[i]>9){
			cerr<< "The map is invalid!" << endl;}
	}

	for(i=0; i<81; i=i+9){   //debug(rows)
		for(w=1; w<10; w++) check[w] = 0;
		for(j=0; j<9;j++) check[map[i+j]]++;
		for(w=1; w<10; w++){
			if(check[w]>1) cerr << "The map is invalid!" <<endl;}
	}

	for(i=0; i<9; i++){   //debug(columes)
		for(w=1; w<10; w++) check[w] = 0;
		for(j=0; j<9; j++) check[map[i+9*j]]++;	
		for(w=1; w<10; w++){
			if(check[w]>1) cerr<< "The map is invalid!" << endl;}
	}

	for(i=0; i<9; i++){  //debug(squares)
		for(w=1; w<10; w++) check[w] = 0;
		for(j=0; j<9; j++){
			square = 27*(i/3) + 3*(i%3) + 9*(j/3) + (j%3);
			check[map[square]]++;}	
		for(w=1; w<10; w++){
			if(check[w]>1) cerr<< "The map is invalid!" << endl;}
	}
}

int Sudoku :: Solve()
{
	int i, j, NumToDel, count=0, w=0, y=0, tem_count, tem_PossAnscount, z=0;
	if(index == 0){
		for(i=0;i<81;i++){
			if(map[i]!=0){   
				Possible_Ans[i][0] = 0;
				for(j=1;j<10;j++){
					Possible_Ans[i][j]=0;
				}
				count++; //counter for ≠0
			}		
			else{
				Possible_Ans[i][0] = 9; //9 possibilities
				for(j=1;j<10;j++){
					Possible_Ans[i][j] = 1; //1~9
				}		
			}
		}

		for(i=0;i<81;i++){
			if(zero_Place[i] == -1) //delete possibilities(rows)
				break;
			for(j=0;j<9;j++){
				NumToDel = map[(zero_Place[i]/9)*9+j];
				if(NumToDel!=0 && Possible_Ans[zero_Place[i]][NumToDel]!=0){
					Possible_Ans[zero_Place[i]][NumToDel] = 0;
					Possible_Ans[zero_Place[i]][0]--;
				}
			}

		}
		for(i=0;i<81;i++){     //delete possibilities(columes)
			if(zero_Place[i] == -1)
				break;
			for(j=0;j<9;j++){
				NumToDel = map[(zero_Place[i]%9)+j*9];
				if(NumToDel!=0 && Possible_Ans[zero_Place[i]][NumToDel]!=0){
					Possible_Ans[zero_Place[i]][NumToDel] = 0;
					Possible_Ans[zero_Place[i]][0]--;
				}
			}

		}
		for(i=0;i<81;i++){    //delete possibilities(squares)
			if(zero_Place[i] == -1)
				break;
			for(j=0;j<9;j++){
				NumToDel = map[27*((zero_Place[i]/9)/3) + (zero_Place[i]%9)-((zero_Place[i]%9)%3)+9*(j/3) + (j%3)];
				if(NumToDel!=0 && Possible_Ans[zero_Place[i]][NumToDel]!=0){
					Possible_Ans[zero_Place[i]][NumToDel] = 0;
					Possible_Ans[zero_Place[i]][0]--;
				}
			}
		}
	}
	while(1){
		for(i=0;i<81;i++){
			if(Possible_Ans[i][0] == 1){ 
				for(j=1;j<10;j++){
					if(Possible_Ans[i][j]==1){
						map[i]=j;
						Possible_Ans[i][j]=0;
						Possible_Ans[i][0]=0;
						count++;
						break;
					}
				}		
			}
		}	
		y=0;
		for(i=0;i<81;i++){
			if(Possible_Ans[i][0]!=1){
				y++;
			}
		}
		if(y==81){
			break;
		}
	}
	
		
}
int Sudoku::GiveQuestion()
{
	int i, random, j;


	int Q1[sudokuSize]={7,3,0,0,0,1,0,0,4,0,0,0,3,7,0,0,0,0,0,5,0,0,0,4,0,3,9,0,8,0,0,0,0,0,0,3,0,0,4,0,0,0,6,8,0,9,0,0,0,0,0,4,0,0,0,0,8,0,0,6,0,0,1,0,0,2,0,0,0,0,5,0,5,7,0,0,8,0,0,0,0};
	int Q2[sudokuSize]={0,0,7,5,0,0,0,0,0,0,0,0,4,8,0,0,0,6,0,8,0,0,2,0,0,0,9,0,3,0,9,0,0,2,0,0,0,0,1,0,0,0,3,0,0,0,0,0,0,0,4,7,6,1,2,0,0,8,0,0,0,0,0,0,0,6,7,0,9,0,8,0,7,0,0,0,0,0,0,0,0};
	int Q3[sudokuSize]={0,6,0,8,3,0,2,5,0,0,0,0,0,0,0,0,0,0,1,3,0,0,6,5,8,0,7,0,7,4,0,2,0,0,0,9,0,2,0,9,7,0,0,3,0,0,8,0,0,0,3,7,0,2,0,0,0,1,9,0,3,0,0,0,0,0,3,0,7,1,0,6,2,1,0,0,8,0,9,0,0};
	int Q4[sudokuSize]={9,0,0,0,0,4,0,0,0,0,0,0,0,3,5,0,4,0,0,8,0,0,0,0,6,0,0,0,0,5,0,0,0,0,0,1,8,0,0,0,6,0,0,0,3,6,0,3,0,2,0,0,0,0,5,6,0,2,0,0,0,0,0,0,0,0,0,0,9,0,7,0,0,4,0,0,5,0,8,1,0};
	int Q5[sudokuSize]={0,0,1,3,6,4,0,8,0,0,0,7,0,8,0,0,0,2,5,8,6,0,9,0,3,0,0,0,0,4,0,0,6,0,0,0,0,5,0,0,0,9,4,3,6,0,6,2,0,0,0,0,0,0,4,0,3,9,0,5,0,0,0,0,0,0,0,7,0,1,5,4,0,0,0,1,0,8,0,9,0};
	int Q6[sudokuSize]={0,0,0,0,0,0,0,8,0,3,0,0,0,0,0,0,0,4,0,6,5,0,0,0,9,0,0,0,0,3,0,0,8,6,1,0,0,7,0,1,0,5,0,0,0,0,0,0,0,3,6,2,0,0,5,0,9,4,0,0,0,0,3,0,1,7,0,0,0,0,0,6,0,0,8,2,0,0,0,0,0};
	int Q7[sudokuSize]={0,1,0,8,9,0,0,0,5,6,0,3,0,0,0,8,0,7,0,0,0,0,3,0,0,9,0,1,0,0,0,0,0,0,4,8,0,0,0,3,4,8,0,0,1,0,7,0,0,0,0,6,0,9,0,0,0,1,0,3,0,7,0,9,8,0,0,0,0,0,0,3,0,0,7,0,0,2,1,8,0};
	int Q8[sudokuSize]={0,0,3,0,0,0,0,0,0,4,0,0,6,9,0,0,0,8,0,2,0,0,0,0,0,0,5,8,0,1,0,0,4,0,0,0,0,0,0,0,7,1,0,6,3,0,6,0,9,0,0,0,8,4,3,0,0,0,0,7,0,1,0,0,0,0,0,0,0,5,0,2,0,7,0,0,4,0,0,0,0};
	int Q9[sudokuSize]={0,0,6,0,0,0,8,0,4,0,4,1,5,0,0,0,0,0,2,0,0,8,0,0,0,0,0,3,6,2,9,0,0,7,0,0,9,0,0,0,8,3,0,6,0,5,0,0,0,1,0,0,0,3,6,5,0,3,2,0,4,7,1,0,8,0,4,0,9,0,3,0,4,0,0,6,7,0,0,0,0};
	int Q10[sudokuSize]={8,0,0,0,0,0,6,0,0,0,0,0,0,3,2,0,0,0,0,0,0,4,0,0,7,2,0,0,9,7,0,0,0,0,3,0,0,0,0,0,0,5,2,0,0,0,0,5,0,0,0,0,8,0,9,3,0,1,0,0,0,0,6,0,0,0,0,8,0,0,0,0,6,2,0,0,0,9,3,1,0};
	int Q11[sudokuSize]={8,5,0,0,0,0,0,4,2,0,1,0,0,0,0,6,8,0,0,0,4,0,0,6,0,1,0,6,0,8,1,0,0,2,0,0,9,0,2,8,0,5,0,0,0,0,4,0,0,0,0,0,0,0,0,8,3,6,9,1,0,2,5,0,0,0,2,5,0,1,0,8,0,0,5,0,7,8,0,0,0};
	int Q12[sudokuSize]={0,0,0,0,0,0,3,0,0,0,0,6,0,0,0,0,0,5,0,2,0,5,3,0,7,0,1,0,9,0,4,8,3,0,2,0,0,1,0,0,9,7,0,0,8,0,0,8,0,0,5,0,7,0,9,0,0,0,6,4,2,5,3,5,0,2,0,0,1,0,9,0,0,8,0,0,0,0,6,0,7};
	int Q13[sudokuSize]={0,0,7,5,0,0,0,2,0,0,0,0,0,3,0,0,0,0,0,1,4,0,0,0,0,8,0,0,0,0,0,0,3,0,9,8,1,0,0,0,2,0,4,0,0,6,0,0,4,0,0,0,1,0,2,0,0,0,0,0,0,6,0,0,0,0,2,6,0,9,7,0,7,8,0,0,0,9,0,0,3};
	int Q14[sudokuSize]={0,0,5,4,0,0,0,6,1,0,0,0,6,0,0,7,0,9,0,6,1,0,7,8,0,5,0,7,0,2,0,0,6,0,0,4,0,0,0,7,0,0,8,0,6,3,0,0,9,0,0,0,2,0,5,0,0,0,6,0,0,4,0,0,0,0,0,0,7,1,0,0,0,2,4,3,0,9,0,7,0};
	int Q15[sudokuSize]={0,0,1,0,0,7,5,6,0,2,0,0,6,0,0,3,0,0,0,4,0,0,0,0,0,0,0,0,0,9,0,0,6,0,0,0,0,0,7,3,0,0,1,4,0,0,0,0,0,0,0,0,3,2,0,0,0,1,8,0,7,0,0,0,0,0,4,0,0,0,0,0,0,6,0,5,0,3,0,8,1};
	int Q16[sudokuSize]={9,0,4,1,0,0,8,0,0,1,0,0,0,0,0,5,0,0,0,3,8,0,0,0,0,4,0,6,0,3,0,4,0,0,0,8,0,0,0,5,2,8,0,0,0,0,0,0,3,0,9,0,0,1,0,0,5,0,0,0,0,9,0,0,0,6,0,9,0,3,8,7,0,0,0,0,0,7,4,0,5};
	int Q17[sudokuSize]={2,0,0,0,8,0,4,0,7,4,0,0,0,0,0,0,8,6,8,0,0,2,1,0,3,0,0,7,0,0,0,9,2,5,0,0,0,2,0,0,0,8,0,0,0,1,0,0,7,3,5,9,0,4,3,0,7,0,0,9,0,0,0,0,0,2,5,0,0,0,0,3,9,1,0,0,0,0,0,0,0};
	int Q18[sudokuSize]={0,0,0,3,0,0,0,0,6,0,0,1,0,6,9,0,0,0,6,0,0,0,0,0,4,8,1,0,4,7,0,0,0,0,0,0,0,0,0,0,5,0,0,0,3,1,5,0,0,0,0,0,0,7,0,0,0,4,0,6,2,0,0,0,9,0,1,0,8,0,0,0,0,0,8,0,2,0,0,0,0};
	int Q19[sudokuSize]={1,7,0,9,5,0,8,0,2,0,0,2,0,0,3,6,0,0,0,0,8,0,2,0,5,7,0,0,0,0,0,0,0,0,0,0,9,0,4,1,0,0,0,0,0,6,8,0,2,0,5,0,0,4,0,0,0,5,0,0,4,2,0,0,2,0,8,0,0,3,0,5,0,5,0,3,0,0,1,6,7};
	int Q20[sudokuSize]={0,8,4,6,0,1,0,9,0,0,2,0,7,0,4,5,0,0,9,0,0,3,8,0,0,0,0,2,4,0,0,7,6,8,0,0,0,7,0,4,3,0,0,0,0,0,0,1,0,2,9,7,0,4,0,0,0,0,0,0,0,0,2,6,9,0,0,0,8,0,0,0,0,1,0,0,0,0,4,0,0};



	random = time(NULL) % 20 + 1;
	switch(random){
		case 1:
		    for(i=0; i<81; i++){
			cout << Q1[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 2:
		    for(i=0; i<81; i++){
			cout << Q2[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 3:
		    for(i=0; i<81; i++){
			cout << Q3[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 4:
		    for(i=0; i<81; i++){
			cout << Q4[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 5:
		    for(i=0; i<81; i++){
			cout << Q5[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 6:
		    for(i=0; i<81; i++){
			cout << Q6[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 7:
		    for(i=0; i<81; i++){
			cout << Q7[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 8:
		    for(i=0; i<81; i++){
			cout << Q8[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 9:
		    for(i=0; i<81; i++){
			cout << Q9[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 10:
		    for(i=0; i<81; i++){
			cout << Q10[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 11:
		    for(i=0; i<81; i++){
			cout << Q11[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 12:
		    for(i=0; i<81; i++){
			cout << Q12[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 13:
		    for(i=0; i<81; i++){
			cout << Q13[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 14:
		    for(i=0; i<81; i++){
			cout << Q14[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 15:
		    for(i=0; i<81; i++){
			cout << Q15[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 16:
		    for(i=0; i<81; i++){
			cout << Q16[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 17:
		    for(i=0; i<81; i++){
			cout << Q17[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 18:
		    for(i=0; i<81; i++){
			cout << Q18[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 19:
		    for(i=0; i<81; i++){
			cout << Q19[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;
		case 20:
		    for(i=0; i<81; i++){
			cout << Q20[i] << " ";
			if(i%9==8)
				cout << endl;
		    }
		    break;                             
	}
}
