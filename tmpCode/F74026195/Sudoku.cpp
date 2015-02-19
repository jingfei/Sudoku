#include "Sudoku.h"

/*** public functions ***/

void Sudoku::GiveQuestion(){
	switch(rand()%10){
		case 0:
			cout<<"0 0 0 0 0 2 1 0 0 "<<endl;
			cout<<"0 8 6 9 0 0 0 5 0 "<<endl;
			cout<<"4 5 0 0 0 6 9 0 0 "<<endl;
			cout<<"0 0 9 0 0 0 0 0 0 "<<endl;
			cout<<"0 6 0 0 0 0 5 0 4 "<<endl;
			cout<<"5 0 0 0 0 0 3 7 0 "<<endl;
			cout<<"7 0 0 0 4 0 0 1 8 "<<endl;
			cout<<"0 0 0 0 9 3 2 0 0 "<<endl;
			cout<<"0 0 0 0 1 0 0 0 0 "<<endl;
			break;
		case 1:
			cout<<"8 0 0 0 6 0 0 0 0 "<<endl;
			cout<<"0 6 0 9 0 3 8 0 0 "<<endl;
			cout<<"9 0 0 0 4 0 5 0 2 "<<endl;
			cout<<"0 0 0 0 0 0 4 0 8 "<<endl;
			cout<<"0 0 0 0 3 0 0 0 0 "<<endl;
			cout<<"0 0 5 4 7 0 1 3 9 "<<endl;
			cout<<"7 8 0 0 5 6 3 0 0 "<<endl;
			cout<<"0 0 0 0 0 0 0 0 0 "<<endl;
			cout<<"0 0 1 0 0 0 2 5 0 "<<endl;

			break;
		case 2:
			cout<<"0 7 0 0 8 0 2 0 0 "<<endl;
			cout<<"5 0 1 0 0 6 0 0 0 "<<endl;
			cout<<"0 0 0 0 7 9 5 0 0 "<<endl;
			cout<<"6 2 0 0 0 8 0 0 7 "<<endl;
			cout<<"0 0 7 0 0 0 0 0 0 "<<endl;
			cout<<"0 0 0 9 3 0 0 0 4 "<<endl;
			cout<<"0 6 0 0 0 5 7 0 3 "<<endl;
			cout<<"0 9 0 4 0 0 0 1 0 "<<endl;
			cout<<"0 1 0 0 0 3 0 0 0 "<<endl;			
			break;
		case 3:
			cout<<"0 4 0 0 0 0 0 0 0 "<<endl;
			cout<<"1 0 0 0 0 5 3 8 0 "<<endl;
			cout<<"0 0 2 0 0 0 6 0 0 "<<endl;
			cout<<"0 0 6 8 0 3 7 9 0 "<<endl;
			cout<<"0 9 0 4 0 0 8 0 0 "<<endl;
			cout<<"0 2 3 0 9 0 4 0 0 "<<endl;
			cout<<"0 1 0 0 0 8 0 6 0 "<<endl;
			cout<<"0 3 8 0 0 0 9 0 0 "<<endl;
			cout<<"5 0 0 0 1 7 0 0 0 "<<endl;
			break;
		case 4:
			cout<<"0 0 5 6 3 0 2 0 0 "<<endl;
			cout<<"0 0 0 2 0 0 0 7 0 "<<endl;
			cout<<"0 0 0 0 0 5 0 0 8 "<<endl;
			cout<<"1 9 2 0 8 0 7 0 0 "<<endl;
			cout<<"7 0 0 0 0 0 0 0 6 "<<endl;
			cout<<"3 0 0 0 5 0 0 0 0 "<<endl;
			cout<<"0 0 0 0 0 3 0 0 1 "<<endl;
			cout<<"8 6 0 0 0 1 5 0 0 "<<endl;
			cout<<"0 2 0 0 4 0 8 0 0 "<<endl;			
			break;
		case 5:
			cout<<"4 5 0 0 0 9 0 7 0 "<<endl;
			cout<<"0 7 0 0 0 0 0 0 0 "<<endl;
			cout<<"3 0 9 0 0 2 4 0 8 "<<endl;
			cout<<"5 0 0 0 9 3 0 0 1 "<<endl;
			cout<<"7 0 0 0 0 4 0 0 3 "<<endl;
			cout<<"6 0 0 7 0 0 0 8 0 "<<endl;
			cout<<"2 0 0 0 0 0 8 0 5 "<<endl;
			cout<<"0 0 0 0 4 5 0 0 7 "<<endl;
			cout<<"0 0 0 2 0 0 9 3 0 "<<endl;			
			break;
		case 6:
			cout<<"0 6 0 0 0 4 0 7 0 "<<endl;
			cout<<"5 0 0 0 0 0 9 0 0 "<<endl;
			cout<<"0 0 1 9 6 8 0 0 4 "<<endl;
			cout<<"7 0 0 0 0 5 0 0 0 "<<endl;
			cout<<"0 0 9 0 1 0 0 0 5 "<<endl;
			cout<<"0 4 0 6 0 0 0 0 0 "<<endl;
			cout<<"0 0 0 4 0 0 0 9 6 "<<endl;
			cout<<"0 0 0 0 2 7 4 0 0 "<<endl;
			cout<<"0 0 0 8 0 0 1 0 7 "<<endl;			
			break;
		case 7:
			cout<<"0 0 0 0 7 0 9 0 0 "<<endl;
			cout<<"0 7 0 0 0 1 0 0 0 "<<endl;
			cout<<"0 8 0 3 0 0 0 0 5 "<<endl;
			cout<<"0 0 3 0 0 6 0 0 0 "<<endl;
			cout<<"0 0 0 0 1 9 2 4 0 "<<endl;
			cout<<"8 1 0 0 4 0 0 0 0 "<<endl;
			cout<<"0 3 2 0 0 7 1 9 0 "<<endl;
			cout<<"5 0 0 0 0 0 4 0 0 "<<endl;
			cout<<"0 0 0 0 0 0 0 6 7 "<<endl;			
			break;
		case 8:
			cout<<"0 0 0 0 0 0 0 5 2 "<<endl;
			cout<<"0 0 4 0 0 0 7 0 0 "<<endl;
			cout<<"8 0 0 0 0 1 0 0 0 "<<endl;
			cout<<"1 0 7 0 0 3 0 0 0 "<<endl;
			cout<<"6 0 0 5 2 0 0 0 0 "<<endl;
			cout<<"0 2 0 0 9 0 0 0 3 "<<endl;
			cout<<"0 7 0 3 0 4 2 0 0 "<<endl;
			cout<<"0 0 0 0 5 0 0 0 1 "<<endl;
			cout<<"0 0 5 0 0 0 4 3 0 "<<endl;			
			break;
		default:
			cout<<"6 7 0 5 0 0 0 0 3 "<<endl;
			cout<<"5 0 0 0 1 0 7 8 0 "<<endl;
			cout<<"0 0 2 0 0 0 0 0 5 "<<endl;
			cout<<"0 0 0 9 0 4 2 0 0 "<<endl;
			cout<<"0 5 0 2 0 0 0 0 0 "<<endl;
			cout<<"0 3 1 0 6 0 0 0 0 "<<endl;
			cout<<"0 0 6 0 0 0 0 0 2 "<<endl;
			cout<<"0 9 0 0 0 3 0 7 0 "<<endl;
			cout<<"0 0 0 7 0 0 0 4 0 "<<endl;			
			break;		
	}
}

void Sudoku::Solve(){
	vector<Blank> blanklist;
//Scan blanklist
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			if(SudokuMap[i][j]==0){
				Blank newBlank(i,j,(i/3)*3+(j/3));
				blanklist.push_back(newBlank);
			}
		}
	}
	
//Fill possible list
	for(i=0;i<blanklist.size();i++){
		for(j=0;j<9;j++){
			int k;
			for(k=0;k<blanklist[i].possible.size();k++){
				if((blanklist[i].possible[k])==SudokuMap[blanklist[i].row][j]){
					blanklist[i].possible.erase(blanklist[i].possible.begin()+k);
					break;
				}
			}
			for(k=0;k<blanklist[i].possible.size();k++){
				if((blanklist[i].possible[k])==SudokuMap[j][blanklist[i].col]){
					blanklist[i].possible.erase(blanklist[i].possible.begin()+k);
					break;
				}
			}
			for(k=0;k<blanklist[i].possible.size();k++){
				if((blanklist[i].possible[k])==SudokuMap[((blanklist[i].row)/3)*3+(j/3)][((blanklist[i].col)/3)*3+(j%3)]){
					blanklist[i].possible.erase(blanklist[i].possible.begin()+k);
					break;
				}
			}
		}
	}
		
	int result=0;
//Step1:Only-Method
	Only(result,blanklist);
	
	switch(result){
		case 0:
			cout<<"0"<<endl;
			break;
		case 1:
			cout<<"1"<<endl;
			Print();
			break;
		default:
			cout<<"2"<<endl;
			break;
	}
	
 }

void Sudoku::ReadIn(){
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cin>>SudokuMap[i][j];
		}
	}
}

/*** private functions ***/

void Sudoku::Print(){
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			cout<<AnswerMap[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

void Sudoku::Only(int &res,vector<Blank> &list){
	vector<Blank> clone=list;
	int i,j,k;
	//deduce blank
	for((i=clone.size()-1);i>-1;i--){
		if(clone[i].possible.size()==1){
			int putn=clone[i].possible[0];
			Blank serve=clone[i];
			SudokuMap[clone[i].row][clone[i].col]=putn;
			clone.erase(clone.begin()+i);
			
			for(j=0;j<clone.size();j++){
				if((clone[j].row==serve.row)||(clone[j].col==serve.col)||(clone[j].group==serve.group)){
					for(k=0;k<clone[j].possible.size();k++){
						if(clone[j].possible[k]==putn){
							clone[j].possible.erase(clone[j].possible.begin()+k);
							break;
						}
					}
				}
			}
			
			continue;
		}
		if(clone[i].possible.size()==0){
			return;
		}
	}
	
	//Terminal
	if(clone.size()==0){
		if(res==1){
			res=2;
			return;
		}else{
			res=1;
			for(i=0;i<9;i++){
				for(j=0;j<9;j++){
					AnswerMap[i][j]=SudokuMap[i][j];
				}
			}
			return;
		}
	}
	
	int index=clone.size()-1;
	//Branch
	for(i=0;i<clone[index].possible.size();i++){
		int putn=clone[index].possible[i];
		Blank serve=clone[index];
		vector<int> reclist;
		
		SudokuMap[clone[index].row][clone[index].col]=putn;
		clone.erase(clone.begin()+index);
		for(j=0;j<clone.size();j++){
			if((clone[j].row==serve.row)||(clone[j].col==serve.col)||(clone[j].group==serve.group)){
				for(k=0;k<clone[j].possible.size();k++){
					if(clone[j].possible[k]==putn){
						reclist.push_back(j);
						clone[j].possible.erase(clone[j].possible.begin()+k);
						break;
					}
				}
			}
		}
		
		Only(res,clone);
		
		if(res==2){
			return;
		}
		
		for(j=0;j<reclist.size();j++){
			clone[reclist[j]].possible.push_back(putn);
		}
		clone.push_back(serve);
	}
}

