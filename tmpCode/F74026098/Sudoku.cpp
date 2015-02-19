#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku(){ 
	memset(map, 0, sizeof(map));
	memset(ans_map, 0, sizeof(ans_map)); 
	memset(zero_pos, 0, sizeof(zero_pos));
	count=0;
}

int i, j, k, l;
int row[9]={0};
int col[9]={0};
int cell[9]={0};
bool Sudoku::check(int element, int pos){
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	memset(cell, 0, sizeof(cell));
	//check row
	for(k=(pos/9)*9; k<((pos/9)+1)*9; k++)
		if(map[k]!=0) row[map[k]]++;
	//check col
	for(k=pos%9; k<=(pos%9)+9*8; k+=9)
		if(map[k]!=0) col[map[k]]++;
	//check cell
	l=(pos%9) - ((pos%9)%3) + ((pos/9) - ((pos/9)%3))*9;  
	for(k=l; k<l+3; k++)
		if(map[k]!=0) cell[map[k]]++;
	for(k=l+9; k<l+12; k++)
		if(map[k]!=0) cell[map[k]]++;
	for(k=l+18; k<l+21; k++)
		if(map[k]!=0) cell[map[k]]++;

	for(k=0; k<9; k++)
		if(row[k]>1 || col[k]>1 || cell[k]>1) return false;
	if(row[element]==0 && col[element]==0 && cell[element]==0)
		return true;
	else return false;
}

void Sudoku::backtracking(int &pos){
	if(zero_pos[pos]==0 && count<2){
		if(count==0)
			for(i=0; i<81; i++)
				ans_map[i]=map[i];

		count++;		
		return;
	}

	for(j=1; j<=9; j++){
		if(check(j, zero_pos[pos])==true){
			map[zero_pos[pos]]=j;
			pos++;
			backtracking(pos);

			pos--;
			map[zero_pos[pos]]=0;
		}
	}
}

void Sudoku::ReadIn(){
	int zero=0;
	for(i=0; i<81; i++){
		cin>>map[i];
		if(map[i]==0)	{zero_pos[zero]=i; zero++;}
	}
}

void Sudoku::GiveQuestion(){
	int random;
	int que[81]={9, 2, 1, 0, 0, 7, 0, 0, 0,
                0, 0, 0, 0, 0, 0, 9, 0, 0,
					 0, 4, 7, 5, 0, 0, 0, 2, 1,
					 0, 0, 6, 0, 0, 3, 0, 5, 0,
					 7, 0, 2, 0, 0, 0, 0, 0, 0,
					 3, 0, 0, 8, 0, 6, 2, 0, 9,
					 0, 0, 0, 6, 0, 9, 0, 0, 0,
					 0, 0, 8, 0, 0, 0, 1, 0, 0,
					 0, 0, 0, 0, 3, 1, 7, 0, 0};

	for(i=0; i<81; i++){
		if(i%9 == 8) cout<<que[i]<<endl;
		else cout<<que[i]<<" ";
	}
}

void Sudoku::Solve(){
	int pos=0;
	backtracking(pos);

	switch(count){
		case 0:
			cout<<count; break;
		case 1:
			cout<<1<<endl;
			for(i=0; i<81; i++){
				if(i%9 == 8) cout<<ans_map[i]<<endl;
				else cout<<ans_map[i]<<" ";
			}
			break;
		case 2:
			cout<<count; break;
	}
}
