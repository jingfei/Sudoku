#include "Sudoku.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

Sudoku::Sudoku()
{
	for(int i=0; i<sudokuSize; ++i){
		map[i] = 0;
		PlacesOfZero[i] = 100;
	}
}
Sudoku::Sudoku(const int init_map[])
{
	for(int i=0; i<sudokuSize; ++i){
		map[i] = init_map[i];
		PlacesOfZero[i] = 100;
	}
}

void Sudoku::setMap(const int set_map[])
{
	for(int i=0; i<sudokuSize; ++i)
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
		++arr_unity[arr[i]-1]; // count
	for(int i=0; i<9; ++i)
		if(arr_unity[i] != 1) // all element
			return false; // must be 1
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
			check_arr[ j] = map[i+9*j];
		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	} 
	for(int i=0; i<9; ++i) // check cells
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

int Sudoku::Ans = 0;

void Sudoku :: setAns(int a)
{
	Ans = a;
}

int Sudoku::ReadIn()
{
	int a, i=0, j=0, check[10]={0}, w=0, loca;
	while(cin >> a){
		map[i] = a;
		if(map[i]==0){
			PlacesOfZero[j] = i;
			j++;
		}
		i++;
		if(i >=81)
			break;
	}
	for(i=0;i<81;i++){
		if(map[i]<0|| map[i]>10){
			cerr<< "invalid map" << endl;
		}
	}
	for(i=0;i<81;i=i+9){
		for(w=1;w<10;w++)
			check[w] = 0;
		for(j=0; j<9;j++)
			check[map[i+j]]++;
		for(w=1;w<10;w++)
			if(check[w]>1)
				cerr << "invalid map2" <<endl;
	}
	for(i=0;i<9;i++){
		for(w=1;w<10;w++)
			check[w] = 0;

		for(j=0;j<9;j++)
			check[map[i+9*j]]++;
		for(w=1;w<10;w++)
			if(check[w]>1)
				cerr<< "invalid map3" << endl;
	}
	for(i=0;i<9;i++){
		for(w=1;w<10;w++)
			check[w] = 0;
		for(j=0;j<9;j++){
			loca = 27*(i/3) + 3*(i%3)+9*( j/3) + ( j%3);
			check[map[loca]]++;
		}	
		for(w=1;w<10;w++){
			if(check[w]>1)
				cerr<<"invalid map4"<< endl;
		}
	}
}

int Sudoku :: Solve(int index)
{
	int  i, j, NumToDel, count=0, w=0, y=0, tem_count, tem_PossAnscount, z=0;
	for(i=0;i<81;i++){
		if(map[i]!=0){
			PossAns[i][0] = 0;
			for(j=1;j<10;j++){
				PossAns[i][j]=0;
			}
			count++;
		}		
		else{
			PossAns[i][0] = 9;
			for(j=1;j<10;j++){
				PossAns[i][j] = 1;
			}		
		}
	}

	for(i=0;i<81;i++){
		if(PlacesOfZero[i] == 100)
			break;
		for(j=0;j<9;j++){
			NumToDel = map[(PlacesOfZero[i]/9)*9+j];
			if(NumToDel!=0 && PossAns[PlacesOfZero[i]][NumToDel]!=0){
				PossAns[PlacesOfZero[i]][NumToDel] = 0;
				PossAns[PlacesOfZero[i]][0]--;
			}
		}

	}
	for(i=0;i<81;i++){
		if(PlacesOfZero[i] == 100)
			break;
		for(j=0;j<9;j++){
			NumToDel = map[(PlacesOfZero[i]%9)+j*9];
			if(NumToDel!=0 && PossAns[PlacesOfZero[i]][NumToDel]!=0){
				PossAns[PlacesOfZero[i]][NumToDel] = 0;
				PossAns[PlacesOfZero[i]][0]--;
			}
		}

	}
	for(i=0;i<81;i++){
		if(PlacesOfZero[i] == 100)
			break;
		for(j=0;j<9;j++){
			NumToDel = map[27*((PlacesOfZero[i]/9)/3) + (PlacesOfZero[i]%9)-((PlacesOfZero[i]%9)%3)+9*(j/3) + (j%3)];
			if(NumToDel!=0 && PossAns[PlacesOfZero[i]][NumToDel]!=0){
				PossAns[PlacesOfZero[i]][NumToDel] = 0;
				PossAns[PlacesOfZero[i]][0]--;
			}
		}
	}
	while(1){
		for(i=0;i<81;i++){
			if(PossAns[i][0] == 1){
				for(j=1;j<10;j++){
					if(PossAns[i][j]==1){
						map[i]=j;
						PossAns[i][j]=0;
						PossAns[i][0]=0;
						count++;
						for(w=0;w<9;w++){
							if(PossAns[(i/9)*9+w][0]>0 && PossAns[(i/9)*9+w][j]==1){
								PossAns[(i/9)*9+w][j]=0;
								PossAns[(i/9)*9+w][0]--;
							}
						}

						for(w=0;w<9;w++){
							if(PossAns[i%9 + w*9][0]>0 && PossAns[i%9 + w*9][j]==1){
								PossAns[i%9 + w*9][0]--;
								PossAns[i%9 + w*9][j]=0;
							}
						}

						for(w=0;w<9;w++){
							if(PossAns[27*((i/9)/3) + ((i%9)-(i%3)%3) + 9*(w/3) + w%3][0]>0 && PossAns[27*((i/9)/3) + ((i%9)-(i%3)%3) + 9*(w/3) + w%3][j]==1){
								PossAns[27*((i/9)/3) + ((i%9)-(i%3)%3) + 9*(w/3) + w%3][0]--;
								PossAns[27*((i/9)/3) + ((i%9)-(i%3)%3) + 9*(w/3) + w%3][j]=0;
							}
						}
						break;
					}
				}		
			}
		}	
		y=0;
		for(i=0;i<81;i++){
			if(PossAns[i][0]!=1){
				y++;
			}
		}
		if(y==81){
			break;
		}
	}
	if(isCorrect()){
		setAns(Ans+1);
		for(w=0;w<81;w++)
			result[w] = map[w];
	}
	else{
		for(i=0;i<82;i++){
			if(map[i]==0)
				break;
		}				//????選???i
		if(i>=81){
			goto end;			
		}
		for(j=1;j<10;j++){
			if(PossAns[i][j]==1){
				map[i] = j;
				if(isCorrect()){
					setAns(Ans+1);
					for(w=0;w<81;w++)
						result[w] = map[w];
				}
				else{
					if(i==80){
						map[i] = 0;
						PossAns[i][j] = 0;
						Solve();	
					}
					else
						Solve();
				}
			}
			else
				;//????瞏?????
		}
		if(i==80)
			for(w=1;w<10;w++)
				PossAns[i][w] = 1;
		map[i] = 0;
	}
end:
	//	cout << Ans;


	if(Ans==1){
		cout << 1 << endl;
		for(w=0;w<81;w++){
			cout << result[w] << " ";
			if(w%9==8)
				cout <<endl;
		}	
		exit(1);
	}
	else{ 
		cout << 2 << endl;
		exit(1);
	}
}
int Sudoku::GiveQuestion()
{
	int i,random, j;



	int question1[sudokuSize]={0,2,0,6,0,4,1,0,0,0,0,0,0,0,0,7,2,8,8,0,0,1,0,7,6,0,5,0,8,4,0,0,0,0,1,0,3,0,0,9,0,0,0,5,2,2,0,1,5,0,0,0,0,4,0,0,0,0,0,5,0,0,0,6,0,2,7,0,0,0,0,0,0,0,0,0,9,0,0,3,0};
	int question2[sudokuSize]={0,5,4,0,0,6,9,0,0,0,7,0,2,0,9,0,4,8,0,0,2,3,0,0,1,0,0,0,4,0,0,0,0,2,3,6,0,0,9,0,3,2,0,0,0,0,0,0,6,0,0,7,0,0,0,0,3,0,9,7,0,0,0,0,0,0,4,0,0,5,1,9,0,0,0,0,0,0,6,0,0};
	int question3[sudokuSize]={0,6,0,8,3,0,2,5,0,0,0,0,0,0,0,0,0,0,1,3,0,0,6,5,8,0,7,0,7,4,0,2,0,0,0,9,0,2,0,9,7,0,0,3,0,0,8,0,0,0,3,7,0,2,0,0,0,1,9,0,3,0,0,0,0,0,3,0,7,1,0,6,2,1,0,0,8,0,9,0,0};
	int question4[sudokuSize]={0,7,0,1,0,2,5,0,6,3,0,0,0,0,0,0,7,0,0,2,0,0,0,6,0,1,0,0,4,0,0,1,0,9,0,0,0,0,3,0,7,0,0,0,2,7,5,9,8,2,0,1,6,4,0,0,0,0,0,0,6,0,3,0,0,1,2,0,0,0,0,5,2,0,0,0,0,0,4,9,0};
	int question5[sudokuSize]={0,0,1,3,6,4,0,8,0,0,0,7,0,8,0,0,0,2,5,8,6,0,9,0,3,0,0,0,0,4,0,0,6,0,0,0,0,5,0,0,0,9,4,3,6,0,6,2,0,0,0,0,0,0,4,0,3,9,0,5,0,0,0,0,0,0,0,7,0,1,5,4,0,0,0,1,0,8,0,9,0};
	int question6[sudokuSize]={0,0,0,0,0,7,0,0,1,0,0,7,0,0,9,0,2,0,8,0,0,0,0,0,4,6,0,0,0,3,0,0,0,0,0,0,0,7,0,1,2,4,0,3,9,0,0,1,9,3,0,2,7,5,7,8,0,0,0,3,0,0,0,9,0,5,0,0,0,7,0,2,4,0,0,0,8,0,0,0,0};
	int question7[sudokuSize]={0,1,0,8,9,0,0,0,5,6,0,3,0,0,0,8,0,7,0,0,0,0,3,0,0,9,0,1,0,0,0,0,0,0,4,8,0,0,0,3,4,8,0,0,1,0,7,0,0,0,0,6,0,9,0,0,0,1,0,3,0,7,0,9,8,0,0,0,0,0,0,3,0,0,7,0,0,2,1,8,0};
	int question8[sudokuSize]={0,0,0,0,6,7,0,1,0,0,9,0,0,0,0,0,0,8,7,0,3,0,8,0,0,0,0,1,8,2,0,7,0,0,0,3,0,3,0,0,0,2,0,0,6,0,0,0,0,3,1,8,5,0,2,0,0,7,5,0,0,0,0,3,4,0,0,0,0,0,8,7,0,5,0,0,1,8,6,0,0};
	int question9[sudokuSize]={0,0,6,0,0,0,8,0,4,0,4,1,5,0,0,0,0,0,2,0,0,8,0,0,0,0,0,3,6,2,9,0,0,7,0,0,9,0,0,0,8,3,0,6,0,5,0,0,0,1,0,0,0,3,6,5,0,3,2,0,4,7,1,0,8,0,4,0,9,0,3,0,4,0,0,6,7,0,0,0,0};
	int question10[sudokuSize]={0,0,0,8,2,0,0,6,0,0,0,0,3,9,6,0,0,0,0,0,3,4,0,0,5,0,0,0,9,0,0,0,2,0,0,3,3,2,0,0,1,0,8,5,4,8,5,0,7,3,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,1,0,3,0,7,9,0,3,0,0,6,7,0,8,2};
	int question11[sudokuSize]={8,5,0,0,0,0,0,4,2,0,1,0,0,0,0,6,8,0,0,0,4,0,0,6,0,1,0,6,0,8,1,0,0,2,0,0,9,0,2,8,0,5,0,0,0,0,4,0,0,0,0,0,0,0,0,8,3,6,9,1,0,2,5,0,0,0,2,5,0,1,0,8,0,0,5,0,7,8,0,0,0};
	int question12[sudokuSize]={0,0,0,0,0,0,3,0,0,0,0,6,0,0,0,0,0,5,0,2,0,5,3,0,7,0,1,0,9,0,4,8,3,0,2,0,0,1,0,0,9,7,0,0,8,0,0,8,0,0,5,0,7,0,9,0,0,0,6,4,2,5,3,5,0,2,0,0,1,0,9,0,0,8,0,0,0,0,6,0,7};
	int question13[sudokuSize]={0,0,1,5,0,0,7,0,0,6,0,4,0,7,0,1,0,0,0,8,0,1,0,6,5,0,2,1,0,5,7,2,0,0,0,3,2,0,0,0,3,0,0,0,1,0,0,9,6,0,0,2,8,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,5,0,0,0,8,4,6,9,0,7,0,2,5};
	int question14[sudokuSize]={0,0,5,4,0,0,0,6,1,0,0,0,6,0,0,7,0,9,0,6,1,0,7,8,0,5,0,7,0,2,0,0,6,0,0,4,0,0,0,7,0,0,8,0,6,3,0,0,9,0,0,0,2,0,5,0,0,0,6,0,0,4,0,0,0,0,0,0,7,1,0,0,0,2,4,3,0,9,0,7,0};
	int question15[sudokuSize]={0,0,2,4,0,9,8,0,6,9,8,0,3,6,0,4,0,0,0,1,0,0,8,0,0,0,0,0,0,0,9,3,8,0,1,7,0,0,1,0,0,6,0,0,0,0,7,0,0,4,0,2,9,0,0,0,0,0,0,0,0,6,0,2,0,0,6,7,0,0,3,9,0,0,0,1,0,0,7,8,0};
	int question16[sudokuSize]={9,0,4,1,0,0,8,0,0,1,0,0,0,0,0,5,0,0,0,3,8,0,0,0,0,4,0,6,0,3,0,4,0,0,0,8,0,0,0,5,2,8,0,0,0,0,0,0,3,0,9,0,0,1,0,0,5,0,0,0,0,9,0,0,0,6,0,9,0,3,8,7,0,0,0,0,0,7,4,0,5};
	int question17[sudokuSize]={2,0,0,0,8,0,4,0,7,4,0,0,0,0,0,0,8,6,8,0,0,2,1,0,3,0,0,7,0,0,0,9,2,5,0,0,0,2,0,0,0,8,0,0,0,1,0,0,7,3,5,9,0,4,3,0,7,0,0,9,0,0,0,0,0,2,5,0,0,0,0,3,9,1,0,0,0,0,0,0,0};
	int question18[sudokuSize]={5,7,9,0,0,0,8,0,0,0,3,4,0,9,0,0,2,6,0,1,2,0,7,4,0,5,0,0,0,0,0,8,3,0,0,0,0,9,0,0,6,2,1,0,0,0,0,0,4,0,0,0,3,0,9,0,0,0,0,8,0,0,3,3,0,6,2,5,0,0,0,0,0,8,7,0,0,0,5,0,0};
	int question19[sudokuSize]={1,7,0,9,5,0,8,0,2,0,0,2,0,0,3,6,0,0,0,0,8,0,2,0,5,7,0,0,0,0,0,0,0,0,0,0,9,0,4,1,0,0,0,0,0,6,8,0,2,0,5,0,0,4,0,0,0,5,0,0,4,2,0,0,2,0,8,0,0,3,0,5,0,5,0,3,0,0,1,6,7};
	int question20[sudokuSize]={0,8,4,6,0,1,0,9,0,0,2,0,7,0,4,5,0,0,9,0,0,3,8,0,0,0,0,2,4,0,0,7,6,8,0,0,0,7,0,4,3,0,0,0,0,0,0,1,0,2,9,7,0,4,0,0,0,0,0,0,0,0,2,6,9,0,0,0,8,0,0,0,0,1,0,0,0,0,4,0,0};



	random =time(NULL)%20;

	if(random==0){
		for(i=0;i<81;i++){
			cout << question1[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==1){
		for(i=0;i<81;i++){
			cout << question2[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==2){
		for(i=0;i<81;i++){
			cout << question3[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==3){
		for(i=0;i<81;i++){
			cout << question4[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==4){
		for(i=0;i<81;i++){
			cout << question5[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==5){
		for(i=0;i<81;i++){
			cout << question6[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==6){
		for(i=0;i<81;i++){
			cout << question7[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==7){
		for(i=0;i<81;i++){
			cout << question8[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==8){
		for(i=0;i<81;i++){
			cout << question9[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==9){
		for(i=0;i<81;i++){
			cout << question10[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==10){
		for(i=0;i<81;i++){
			cout << question11[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==11){
		for(i=0;i<81;i++){
			cout << question12[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==12){
		for(i=0;i<81;i++){
			cout << question13[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==13){
		for(i=0;i<81;i++){
			cout << question14[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==14){
		for(i=0;i<81;i++){
			cout << question15[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==15){
		for(i=0;i<81;i++){
			cout << question16[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==16){
		for(i=0;i<81;i++){
			cout << question17[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==17){
		for(i=0;i<81;i++){
			cout << question18[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==18){
		for(i=0;i<81;i++){
			cout << question19[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}
	if(random==19){
		for(i=0;i<81;i++){
			cout << question20[i] << " ";
			if(i%9==8)
				cout << endl;
		}
	}



}






