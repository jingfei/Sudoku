/*#ifndef SUDOKU_H
#define SUDOKU_H*/
#include<iostream>
#include"Sudoku.h"
#define N 81
using namespace std;
Sudoku::Sudoku(){
	for(int i=0;i<N;i++){
		map[i]=0;
	}
}
void Sudoku::ReadIn(){
	int temp;
	for(int i=0;i<81;i++){
		cin>>temp;
		map[i]=temp;
	}
}
void Sudoku::GiveQuestion(){
/*	cout<<"0 0 5 3 0 0 0 0 0"<<endl
	<<"8 0 0 0 0 0 0 2 0"<<endl
	<<"0 7 0 0 1 0 5 0 0"<<endl
	<<"4 0 0 0 0 5 3 0 0"<<endl 
	<<"0 1 0 0 7 0 0 0 6"<<endl
	<<"0 0 3 2 0 0 0 8 0"<<endl 
	<<"0 6 0 5 0 0 0 0 9"<<endl
	<<"0 0 4 0 0 0 0 3 0"<<endl
	<<"0 0 0 0 0 9 7 0 0"<<endl;*/

	cout<<"0 5 0 0 0 0 7 0 0"<<endl
	<<"0 0 4 0 0 0 0 0 8"<<endl
	<<"8 0 3 0 5 1 0 0 0"<<endl
	<<"0 3 0 0 0 7 0 0 5"<<endl 
	<<"0 0 0 5 9 2 0 0 0"<<endl
	<<"6 0 0 4 0 0 0 2 0"<<endl 
	<<"0 0 0 1 7 0 4 0 2"<<endl
	<<"4 0 0 0 0 0 6 0 0"<<endl
	<<"0 0 6 0 0 0 0 9 0"<<endl;
}
void Sudoku::Solve(){
	amount=0;
	Sudoku::Solve1();
	if(amount==1){
		cout<<1<<endl;
		for(int i=0;i<9;i++){
			for(int n=0;n<9;n++){
				cout<<answer[9*i+n]<<" ";
			}
			cout<<endl;
		}
	}
	else if(amount==0){
		cout<<0<<endl;
	}
	else{
		cout<<2<<endl;
	}
}
void Sudoku::Solve1(){
	if(getzero()==-1){
		for(int i=0;i<9;i++){
			for(int n=0;n<9;n++){
				answer[9*i+n]=map[9*i+n];
			}
		}
		amount++;
		return;
	}
	for(int number=1;number<=9;++number){
		if(checkelement(getzero(),number)==true){
			int index=getzero();
			map[index]=number;
			Solve1();
			map[index]=0;
		}
	}
}
bool Sudoku::checkelement(int index,int element){
	int i,temp;
	for(i=0;i<9;i++){
		temp=index+9*i;
		if(temp>=81){
			temp=temp-81;
		}
		if(map[temp]==element){
			return false;
		}
	}
	for(i=0;i<9;i++){
		temp=index-(index%9);
		if(map[temp+i]==element){
			return false;
		}
	}
	int row=index%9;
	int column=index/9;
	if(row<3){
		row=0;
		if(checksquare(row,column,element)==false){
			return false;
		}
	}
	else if(row>=6){
		row=6;
		if(checksquare(row,column,element)==false){
			return false;
		}
	}
	else{
		row=3;
		if(checksquare(row,column,element)==false){
			return false;
		}
	}
	return true;
}
bool Sudoku::checksquare(int row,int column,int element){
	if(column<3){
		column=0;
	}
	else if(column>=6){
		column=6;
	}
	else{
		column=3;
	}
	for(int i=0;i<9;i++){
		if(i<3){
			if(map[row+9*column+i]==element){
				return false;
			}
		}
		else if(i>=6){
			if(map[row+9*column+i+12]==element){
				return false;
			}
		}
		else{
			if(map[row+9*column+i+6]==element){
				return false;
			}
		}
	}
	return true;
}
int Sudoku::getzero(){
	for(int i=0;i<81;i++){
		if(map[i]==0){
			return i;
		}
	}
	return -1;
}
bool Sudoku::checkmap(){
	int tempunity[9],i,n;
	bool checkresult;
	for(i=0;i<81;i=i+9){
		for(n=0;n<9;n++){
			tempunity[n]=map[i+n];
		}
		checkresult=checkunity(tempunity);
		if(checkresult==false){
			return false;
		}
	}
	for(i=0;i<9;i++){
		for(n=0;n<9;n++){
			tempunity[n]=map[i+9*n];
		}
		checkresult=checkunity(tempunity);
		if(checkresult==false){
			return false;
		}
	}
	for(i=0;i<81;i=i+3){
		if(i%9==0){
			i=i+18;
		}
		for(n=0;n<9;n++){
			if(n%9>=3&&n%9<6){
				tempunity[n]=map[i+n+6];
			}
			else if(n%9>=6){
				tempunity[n]=map[i+n+12];
			}
			else{
				tempunity[n]=map[i+n];
			}
		}
		checkresult=checkunity(tempunity);
		if(checkresult==false){
			return false;
		}
	}
	return true;
}
bool Sudoku::checkunity(int inunity[9]){
	int x=0;
	for(int number=1;number<=9;number++){
		for(int n=0;n<9;n++){
			if(inunity[n]==number){
				x++;
			}
		}
		if(x!=1){
			x=0;
			return false;
		}
	}
	return true;
}