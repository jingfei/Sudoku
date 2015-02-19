#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <vector>
#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku(){};

void Sudoku::GiveQuestion()
{
//	freopen("question.txt","w",stdout);
//2i0 0
	srand(time(0));
	int choice=rand() % 2;

	if(choice==0){
		printf("8 0 0 0 0 0 0 0 0\n"
				"0 0 3 6 0 0 0 0 0\n"
				"0 7 0 0 9 0 2 0 0\n"
				"0 5 0 0 0 7 0 0 0\n"
				"0 0 0 0 4 5 7 0 0\n"
				"0 0 0 1 0 0 0 3 0\n"
				"0 0 1 0 0 0 0 6 8\n"
				"0 0 8 5 0 0 0 1 7\n"
				"0 9 0 0 0 0 4 0 0\n");
	}
	else{
		printf("0 0 5 3 0 0 0 0 0\n"
				"8 0 0 0 0 0 0 2 0\n"
				"0 7 0 0 1 0 5 0 0\n"
				"4 0 0 0 0 5 3 0 0\n"
				"0 1 0 0 7 0 0 0 6\n"
				"0 0 3 2 0 0 0 8 0\n"
				"0 6 0 5 0 0 0 0 9\n"
				"0 0 4 0 0 0 0 3 0\n"
				"0 0 0 0 0 9 7 0 0\n");
	}
//10 0
/*
	printf("0 0 0 0 5 0 0 0 0\n"
			"0 0 0 0 0 0 0 7 0\n"
			"0 0 5 0 0 1 0 0 0\n"
			"0 5 0 0 0 0 8 0 6\n"
			"0 0 0 0 4 0 0 2 0\n"
			"2 0 0 1 0 9 0 0 0\n"
			"0 0 0 0 0 0 0 0 0\n"
			"0 3 0 0 0 0 0 1 0\n"
			"0 0 0 3 0 0 0 0 0\n");
*/
//	fclose (stdout);
}

vector<int> Sudoku::ReadIn(vector<int> s)
{
	s.assign(83, 0);
//	freopen("question.txt","r",stdin);
	int count;
	for(count=1; count<size; count++)
		scanf("%d", &s[count]);
//	fclose(stdin);

	return s;
}

bool Sudoku::Solve(vector<int> s, vector<int> & ans, int index)
{
	index=checkzero(s, index);
	if(index==82){
		if(checkall(s)){
			ans=s;
			return true;
		}
		else return false;
	}
	else{
		for(int element=1; element<=9; element++){
			s[index]=element;
			if(precheck(s, index))
				if(Solve(s, ans, index))
					return true;
		}
		return false;
	}
}

bool Sudoku::reverse(vector<int> s, vector<int> & ans_r, int index)
{
	index=checkzero_r(s, index);
	if(index==0){
		if(checkall(s)){
			ans_r=s;
			return true;
		}
		else return false;
	}
	else{
		for(int element=1; element<=9; element++){
			s[index]=element;
			if(precheck(s, index))
				if(reverse(s, ans_r, index))
					return true;
		}
		return false;
	}
}

bool Sudoku::precheck(vector<int> s, int index)
{
	int tmp;
	vector<int> t(test);
//testing column	

	switch(index){
		case 1 ... 9:
			tmp=index;
			break;
		case 10 ... 18:
			tmp=index-9;
			break;
		case 19 ... 27:
			tmp=index-18;
			break;
		case 28 ... 36:
			tmp=index-27;
			break;
		case 37 ... 45:
			tmp=index-36;
			break;
		case 46 ... 54:
			tmp=index-45;
			break;
		case 55 ... 63:
			tmp=index-54;
			break;
		case 64 ... 72:
			tmp=index-63;
			break;
		case 73 ... 81:
			tmp=index-72;
			break;
		default:
			cerr<<"Error1: failed test."<<endl;
			exit(1);
	}
	t.assign(10,0);
	for(;tmp<size;tmp=tmp+9)
		if(++t[s[tmp]] > 1 && s[tmp]!=0){
//cout<<"column "<<s[tmp]<<" "<<t[s[tmp]]<<endl;
			return false;
		}

//testing row
	int row = index-1; row = row / 9;
    switch(row){
        case 0:
            tmp=1;
            break;
        case 1:
            tmp=10;
            break;
        case 2:
            tmp=19;
            break;
        case 3:
            tmp=28;
            break;
        case 4:
            tmp=37;
            break;
        case 5:
            tmp=46;
            break;
        case 6:
            tmp=55;
            break;
        case 7:
            tmp=64;
		 	break;
        case 8:
            tmp=73;
            break;
        default:
            cerr<<"Error2: failed test."<<endl;
			exit(1);
    }
	t.assign(10,0);
    for(int i=0; i<9; tmp++, i++)
        if(++t[s[tmp]] > 1 && s[tmp]!=0){
//cout<<"row"<<endl;
			return false;
		}

//testing cell
//cout<<"testing cell"<<index<<endl;
	switch(index){
		case 1 ... 9:
		case 28 ... 36:
		case 55 ... 63:
			break;
		case 10 ... 18:
		case 37 ... 45:
		case 64 ... 72:
			index=index-9;
			break;
		case 19 ... 27:
		case 46 ... 54:
		case 73 ... 81:
			index=index-18;
			break;
		default:
			cerr<<"Error3: Failed test."<<endl;
			exit(1);
	}
	switch(index){
		case 1: case 4: case 7:
		case 28: case 31: case 34:
		case 55: case 58: case 61:
			break;
		case 2: case 5: case 8:
		case 29: case 32: case 35:
		case 56: case 59: case 62:
			index=index-1;
			break;
		case 3: case 6: case 9:
		case 30: case 33: case 36:
		case 57: case 60: case 63:
			index=index-2;
			break;
		default:
			cerr<<"Error4: Failed test."<<endl;
			exit(1);
	}
	t.assign(10,0);
	int i;
//cout<<index<<endl;
	for(i=1, tmp=index; i<=3; tmp++, i++){
		if(++t[s[tmp]] > 1 && s[tmp]!=0){
//cout<<"cell1"<<endl;
			return false;
		}
	}
	tmp=tmp+6;
//cout<<tmp<<endl;
	for(i=1; i<=3; tmp++, i++){
		if(++t[s[tmp]] > 1 && s[tmp]!=0){
//cout<<"cell2"<<endl;
			return false;
		}
	}
	tmp=tmp+6;
//cout<<tmp<<endl;
	for(i=1; i<=3; tmp++, i++){
		if(++t[s[tmp]] > 1 && s[tmp]!=0){
//cout<<"cell3"<<endl;
			return false;
		}
	}
	
	return true;
}

int Sudoku::checkzero(vector<int> s, int index)
{
//cout<<index<<" hey"<<endl;
	for(int count=index;;count++){
		if(s[count]==0){
//cout<<count<<s[count]<<endl;
			return count;
		}
	}
}

int Sudoku::checkzero_r(vector<int> s, int index)
{
	for(int count=index;;count--){
		if(s[count]==0){
			return count;
		}
	
	}
}

bool Sudoku::checkall(vector<int> s)
{
//testing rows
	int row, column;
	vector<int> t(test);

	for(row=1; row<=9; row++){
		t.assign(10,0);
		for(column=1; column<=9; column++)
			if(++t[s[(row-1)*9+column]] > 1) return false;
	}

//testing columns
	for(column=1; column<=9; column++){
		t.assign(10,0);
		for(row=1; row<=9; row++)
			if(++t[s[(row-1)*9+column]] > 1) return false;
	}
;
//testing cells
//cout<<"hi?"<<endl;
	int tmp, Cell;
	for(Cell=1; Cell<=9; Cell=Cell+3){
		t.assign(10,0);
//cout<<"0"<<t[1]<<t[2]<<t[3]<<t[4]<<t[5]<<t[6]<<t[7]<<t[8]<<t[9]<<endl;
		for(tmp=Cell; tmp<Cell+3; tmp++){
//cout<<"1st3cells"<<t[1]<<t[2]<<t[3]<<t[4]<<t[5]<<t[6]<<t[7]<<t[8]<<t[9]<<endl;
			if(++t[s[tmp]] > 1) return false;
		}
		for(tmp=Cell+9; tmp<Cell+12; tmp++){
//cout<<"2nd3cells"<<t[1]<<t[2]<<t[3]<<t[4]<<t[5]<<t[6]<<t[7]<<t[8]<<t[9]<<endl;
			if(++t[s[tmp]] > 1) return false;
		}
		for(tmp=Cell+18; tmp<Cell+21; tmp++){
//cout<<"3rd3cells"<<t[1]<<t[2]<<t[3]<<t[4]<<t[5]<<t[6]<<t[7]<<t[8]<<t[9]<<endl;
			if(++t[s[tmp]] > 1) return false;
		}
	}
//cout<<"here?"<<endl;
	for(Cell=28; Cell<=36; Cell=Cell+3){
		t.assign(10,0);
		for(tmp=Cell; tmp<Cell+3; tmp++)
			if(++t[s[tmp]] > 1) return false;
		for(tmp=Cell+9; tmp<Cell+12; tmp++)
			if(++t[s[tmp]] > 1) return false;
		for(tmp=Cell+18; tmp<Cell+21; tmp++)
			if(++t[s[tmp]] > 1) return false;
	}
//cout<<"or here?"<<endl;
	for(Cell=55; Cell<=63; Cell=Cell+3){
		t.assign(10,0);
		for(tmp=Cell; tmp<Cell+3; tmp++)
			if(++t[s[tmp]] > 1) return false;
		for(tmp=Cell+9; tmp<Cell+12; tmp++)
			if(++t[s[tmp]] > 1) return false;
		for(tmp=Cell+18; tmp<Cell+21; tmp++)
			if(++t[s[tmp]] > 1) return false;
	}

	return true;  
}

void Sudoku::output(vector<int> ans)
{
//	freopen("output.txt","w",stdout);
	for(int row=0; row<9; row++){
		for(int column=1; column<=9; column++)
			printf("%d ", ans[row*9+column]);
		printf("\n");
	}
}
