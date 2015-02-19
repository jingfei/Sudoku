#include "Sudoku.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream>

using namespace std;

Sudoku::Sudoku(){
	srand(time(NULL));	
	for(i=0;i<SIZE*SIZE;i++){
		counting[i]=0;}
	for(i=0;i<SIZE*SIZE;i++){
		for(j=0;j<SIZE;j++)
			tag[i][j]=0;}
	found=0;	
}

Sudoku::Sudoku(vector <int> board, int num){
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++)
			in_board[i*SIZE+j]=board[i*SIZE+j];
	}
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++)
			counting[i*SIZE+j]=0;	
	}
	for(i=0;i<SIZE*SIZE;i++){
		for(j=0;j<SIZE;j++)
			tag[i][j]=0;
	}
	found=0;
	setAns(num);
	Solve();
}

Sudoku::Sudoku(vector <int> board, int num, int X){
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++)
			in_board[i*SIZE+j]=board[i*SIZE+j];
	}
	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++)
			counting[i*SIZE+j]=0;	
	}
	for(i=0;i<SIZE*SIZE;i++){
		for(j=0;j<SIZE;j++)
			tag[i][j]=0;
	}
	found=0;
	setAns(num);
	SolveX();
}

void Sudoku::GiveQuestion(){
	int answer=0;
	int tmp;
	int arrtmp[9]={1,2,3,4,5,6,7,8,9};
	vector <int> board (81);
	vector <int> origin_board(81);
	bool check=false;

	for(i=0;i<81;i++)
		board[i]=0;
	for(i=0;i<9;i++)
		board[i/3*9+i%3]=arrtmp[i];
	
	while(!check)
		check=BoardFillin(board);

	for(i=0;i<9;i++){
		j=rand()%9;
		tmp=arrtmp[i];
		arrtmp[i]=arrtmp[j];
		arrtmp[j]=tmp;}
	
	for(i=0;i<81;i++)
		board[i]=arrtmp[board[i]-1];

	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++){
			store_board[i][j]=board[i*SIZE+j];
			origin_board[i*SIZE+j]=store_board[i][j];}}

	while(answer!=1){
		DigBoard();
		
		for(i=0;i<SIZE;i++){
			for(j=0;j<SIZE;j++)
				in_board[i*SIZE+j]=dig_board[i][j];}
		
		Sudoku sol2;
		sol2.Take(in_board);
		sol2.SolveToQuestion();
		answer=sol2.getAns();

		if(answer==1 && board!=sol2.GetBoard())
			answer=0;
		setAns(0);
	}	
		for(i=0;i<SIZE*SIZE;i++){
			cout << in_board[i]<< " ";
			if((i+1)%9==0)
				cout << endl;}

}

bool Sudoku::MoreCheck(vector <int> board, int site, int n){
	int a;
	for(a=0;a<9;a++){
		if(board[(site/9)*9+a]==n)
			return true;
		if(board[a*9+site%9]==n)
			return true;}
	return false;
}

bool Sudoku::BoardFillin(vector <int>& board){
	int site, count1, count2;
	bool check=true;

	for(j=0;j<9;j++){
		count2=0;
		for(i=1;i<9;i++){
			site=(i/3)*27+(i%3)*3;
			count1=0;
			while(check==true){
				k=rand()%9;
				check=MoreCheck(board,site+(k/3)*9+k%3,j+1);
				++count1;
				++count2;
				if(board[site+(k/3)*9+k%3]==0 && check==false){
					board[site+(k/3)*9+k%3]=j+1;
					check=true;
					break;}
				else
					check=true;

				if(count1>100){
					for(l=0;l<81;l++){
						if(board[l]==j+1)
							board[l]=0;}
					board[(j/3)*9+j%3]=j+1;
					i=0;
					break;}
				if(count2>1000)
					return false;}}}
	
	return true;
}

void Sudoku::DigPreprocedure(){
//	int ran=20+rand()%11;
	int ran=40;
	num_reserve=ran;

	for(i=0;i<SIZE;i++){
		for(j=0;j<SIZE;j++)
			dig_board[i][j]=store_board[i][j];}

	for(i=0;i<(SIZE*SIZE);i++)
		clear_order[i]=i;
}

void Sudoku::DigBoard(){
	int tmp;
	DigPreprocedure();
	for(i=0;i<81;i++){
		j=rand()%81;
		tmp=clear_order[i];
		clear_order[i]=clear_order[j];
		clear_order[j]=tmp;}

	for(i=0;i<(81-num_reserve);i++)
		dig_board[clear_order[i]/SIZE][clear_order[i]%9]=0;
}

int Sudoku::Ans=0;

void Sudoku::ReadIn(){
	for(i=0;i<SIZE*SIZE;i++)
		cin >> in_board[i];
}

void Sudoku::Take(int inx_board[]){
	for(i=0;i<SIZE*SIZE;i++)
		in_board[i]=inx_board[i];
}

void Sudoku::Solve(){
	int check, Max, iMax;
	
	for(i=0;i<SIZE*SIZE;i++){
		if(in_board[i])
			found++;
		else{
			for(j=0;j<SIZE;j++){
				if(in_board[(i/SIZE)*SIZE+j] && !tag[i][in_board[(i/SIZE)*SIZE+j]-1]){
					counting[i]++;
					tag[i][in_board[(i/SIZE)*SIZE+j]-1]=true;}
				if(in_board[j*SIZE+i%SIZE] && !tag[i][in_board[j*SIZE+i%SIZE]-1]){
					counting[i]++;
					tag[i][in_board[j*SIZE+i%SIZE]-1]=true;}

				check=in_board[((i/(SIZE*3))*3+j/3)*SIZE+((i%SIZE)/3)*3+j%3]-1;
				if(in_board[((i/(SIZE*3))*3+j/3)*SIZE+((i%SIZE)/3)*3+j%3] && !tag[i][check]){
					counting[i]++;
					tag[i][check]=true;}
	}}}

	for(i=0;i<SIZE*SIZE;i++){
		if(!in_board[i] && counting[i]==8){
			counting[i]=0;
			found++;
			for(j=0;j<SIZE;j++){
				if(!tag[i][j]){
					in_board[i]=j+1;
					for(k=0;k<SIZE;k++){
						if(!in_board[(i/SIZE)*SIZE+k] && !tag[(i/SIZE)*SIZE+k][j]){
							counting[(i/SIZE)*SIZE+k]++;
							tag[(i/SIZE)*SIZE+k][j]=true;}
						if(!in_board[k*SIZE+i%SIZE] && !tag[k*SIZE+i%SIZE][j]){
							counting[k*SIZE+i%SIZE]++;
							tag[k*SIZE+i%SIZE][j]=true;}
						check=((i/(SIZE*3))*3+k/3)*SIZE+((i%SIZE)/3)*3+k%3;
						if(!in_board[check] && !tag[check][j]){
							counting[check]++;
							tag[check][j]=true;}
	}}}
	i=-1;}}

	if(found==81)
		setAns(Ans+1);
	else{
		Max=0;
		iMax=-1;
		for(i=0;i<SIZE*SIZE;i++){
			if(counting[i] > Max){
				Max=counting[i];
				iMax=i;}
		}
		for(j=0;j<SIZE;j++){
			if(!tag[iMax][j]){
				in_board[iMax]=j+1;
				Sudoku *tmp=new Sudoku(GetBoard(), getAns(), 1);
				delete tmp;}
		}
	}

	int answer=getAns();
	if(answer==0 || answer==1)
		cout << answer << endl;
	else if(answer>=2)
		cout << "2" << endl;
	
	if(answer==1){
		vector <int> result (81);
		for(i=0;i<SIZE*SIZE;i++)
			result[i]=in_board[i];
		print_board(result);
	}
}

void Sudoku::SolveToQuestion(){
	int check, Max, iMax;

	for(i=0;i<SIZE*SIZE;i++){
		if(in_board[i])
			found++;
		else{
			for(j=0;j<SIZE;j++){
				if(in_board[(i/SIZE)*SIZE+j] && !tag[i][in_board[(i/SIZE)*SIZE+j]-1]){
					counting[i]++;
					tag[i][in_board[(i/SIZE)*SIZE+j]-1]=true;}
				if(in_board[j*SIZE+i%SIZE] && !tag[i][in_board[j*SIZE+i%SIZE]-1]){
					counting[i]++;
					tag[i][in_board[j*SIZE+i%SIZE]-1]=true;}

				check=in_board[((i/(SIZE*3))*3+j/3)*SIZE+((i%SIZE)/3)*3+j%3]-1;
				if(in_board[((i/(SIZE*3))*3+j/3)*SIZE+((i%SIZE)/3)*3+j%3] && !tag[i][check]){
					counting[i]++;
					tag[i][check]=true;}
	}}}

	for(i=0;i<SIZE*SIZE;i++){
		if(!in_board[i] && counting[i]==8){
			counting[i]=0;
			found++;
			for(j=0;j<SIZE;j++){
				if(!tag[i][j]){
					in_board[i]=j+1;
					for(k=0;k<SIZE;k++){
						if(!in_board[(i/SIZE)*SIZE+k] && !tag[(i/SIZE)*SIZE+k][j]){
							counting[(i/SIZE)*SIZE+k]++;
							tag[(i/SIZE)*SIZE+k][j]=true;}
						if(!in_board[k*SIZE+i%SIZE] && !tag[k*SIZE+i%SIZE][j]){
							counting[k*SIZE+i%SIZE]++;
							tag[k*SIZE+i%SIZE][j]=true;}
						check=((i/(SIZE*3))*3+k/3)*SIZE+((i%SIZE)/3)*3+k%3;
						if(!in_board[check] && !tag[check][j]){
							counting[check]++;
							tag[check][j]=true;}
	}}}
	i=-1;}}

	if(found==81)
		setAns(Ans+1);
	else{
		Max=0;
		iMax=-1;
		for(i=0;i<SIZE*SIZE;i++){
			if(counting[i] > Max){
				Max=counting[i];
				iMax=i;}
		}
		for(j=0;j<SIZE;j++){
			if(!tag[iMax][j]){
				in_board[iMax]=j+1;
				Sudoku *tmp=new Sudoku(GetBoard(), getAns(), 1);
				delete tmp;}
		
		}
	}
}

void Sudoku::SolveX(){
	int check, Max, iMax;
	
	for(i=0;i<SIZE*SIZE;i++){
		if(in_board[i])
			found++;
		else{
			for(j=0;j<SIZE;j++){
				if(in_board[(i/SIZE)*SIZE+j] && !tag[i][in_board[(i/SIZE)*SIZE+j]-1]){
					counting[i]++;
					tag[i][in_board[(i/SIZE)*SIZE+j]-1]=true;}
				if(in_board[j*SIZE+i%SIZE] && !tag[i][in_board[j*SIZE+i%SIZE]-1]){
					counting[i]++;
					tag[i][in_board[j*SIZE+i%SIZE]-1]=true;}

				check=in_board[((i/(SIZE*3))*3+j/3)*SIZE+((i%SIZE)/3)*3+j%3]-1;
				if(in_board[((i/(SIZE*3))*3+j/3)*SIZE+((i%SIZE)/3)*3+j%3] && !tag[i][check]){
					counting[i]++;
					tag[i][check]=true;}
	}}}

	for(i=0;i<SIZE*SIZE;i++){
		if(!in_board[i] && counting[i]==8){
			counting[i]=0;
			found++;
			for(j=0;j<SIZE;j++){
				if(!tag[i][j]){
					in_board[i]=j+1;
					for(k=0;k<SIZE;k++){
						if(!in_board[(i/SIZE)*SIZE+k] && !tag[(i/SIZE)*SIZE+k][j]){
							counting[(i/SIZE)*SIZE+k]++;
							tag[(i/SIZE)*SIZE+k][j]=true;}
						if(!in_board[k*SIZE+i%SIZE] && !tag[k*SIZE+i%SIZE][j]){
							counting[k*SIZE+i%SIZE]++;
							tag[k*SIZE+i%SIZE][j]=true;}
						check=((i/(SIZE*3))*3+k/3)*SIZE+((i%SIZE)/3)*3+k%3;
						if(!in_board[check] && !tag[check][j]){
							counting[check]++;
							tag[check][j]=true;}
	}}}
	i=-1;}}

	if(found==81)
		setAns(Ans+1);
	else{
		Max=0;
		iMax=-1;
		for(i=0;i<SIZE*SIZE;i++){
			if(counting[i] > Max){
				Max=counting[i];
				iMax=i;}
		}
		for(j=0;j<SIZE;j++){
			if(!tag[iMax][j]){
				in_board[iMax]=j+1;
				Sudoku *tmp=new Sudoku(GetBoard(), getAns(), 1);
				delete tmp;}
		}
	}
}

vector <int> Sudoku::GetBoard(){
	vector <int> out_board(SIZE*SIZE);
	for(i=0;i<SIZE*SIZE;i++)
		out_board[i]=in_board[i];

	return out_board;
}

int Sudoku::getAns(){
	return Ans;
}

void Sudoku::print_board(vector <int> board){
	int i;
	for(i=0;i<board.size();i++){
		cout << board[i] << " ";
		if((i+1)%9==0)
			cout << endl;
	}
	cout << endl;
}

void Sudoku::setAns(int A){
	Ans=A;
}