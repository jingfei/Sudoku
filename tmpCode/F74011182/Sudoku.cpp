#include"Sudoku.h"

Sudoku::Sudoku(void){
	map.resize(81);
	xLable.resize(9);
	yLable.resize(9);
	gridLable.resize(9);
}

void Sudoku::ReadIn(void){
	char tmpt[81];
	for(int i=0;i<81;++i){
		cin>>tmpt[i];
		map[i]=tmpt[i]-48;
	}
}
		
void Sudoku::Solve(void){
	if( ! initialCheckUnity() ){
		cout<<getCountSolution()<<endl;
		return;
	}
	getAnswer();
	int Count=getCountSolution();
	if(Count==1){
		cout<<getCountSolution()<<endl;
		outAnswer();
	}
	else{
		cout<<getCountSolution()<<endl;
	}
}

void Sudoku::GiveQuestion(void){
	
	srand( time(NULL) );
	int index;
	index=rand()%15;

	for(int j=0;j<9;++j){
		for(int i=0;i<9;++i){
			cout<<Map[index][j][i]<<" ";
		}
		cout<<endl;
	}
}

int Sudoku::initialCheckUnity(void){

	for(int i=0;i<9;++i){
		yLable[i].contain=0;
		xLable[i].contain=0;
		gridLable[i].contain=0;
	}

	vector<int>::iterator it;
	vector<int> t;

	for(int j=0;j<9;++j){
		t.clear();
		for(int i=0;i<9;++i){
			if(map[9*j+i]!=0){
				yLable[j].contain|=(0x0001<<(map[9*j+i]-1));
				t.push_back(map[9*j+i]);
			}
		}
		t.push_back(0);
		it=adjacent_find(t.begin(),t.end());
		if( it != t.end() ){
			return 0;
		}
	}

	for(int i=0;i<9;++i){
		t.clear();
		for(int j=0;j<9;++j){
			if(map[9*j+i]!=0){
				xLable[i].contain|=(0x0001<<(map[9*j+i]-1));
				t.push_back(map[9*j+i]);
			}
		}
		t.push_back(0);
		it=adjacent_find(t.begin(),t.end());
		if( it != t.end() ){
			return 0;
		}
	}

	for(int k=0,index;k<9;++k){
		t.clear();
		for(int i=0;i<9;++i){
			index=(k/3)*27 + (k%3)*3 + (i/3)*9 + (i%3);
			if( map[index] != 0 ){
				gridLable[k].contain |=(0x0001<<(map[index]-1));
				t.push_back(map[index]);
			}
		}
		t.push_back(0);
		it=adjacent_find(t.begin(),t.end());
		if( it != t.end() ){
			return 0;
		}
	}

/*	for(int j=0;j<9;++j){
		for(int i=0;i<9;++i){
			if(map[9*j+i]!=0){
				yLable[j].contain|=(0x0001<<(map[9*j+i]-1));
				xLable[i].contain|=(0x0001<<(map[9*j+i]-1));
				gridLable[(j/3)*3+(i/3)].contain|=(0x0001<<(map[9*j+i]-1));
			}
		}
	}//not nessary
*/
	for(int i=0;i<9;++i){
		yLable[i].contain= ~yLable[i].contain;
		xLable[i].contain= ~xLable[i].contain;
		gridLable[i].contain= ~gridLable[i].contain;
	}

	return 1;
}//initialCheckUnity

int Sudoku::getCountSolution(void){
	return multiAnswer.size();
}

void Sudoku::getAnswer(void){
	solveOne(  map, xLable, yLable, gridLable );
}

void Sudoku::outOriginMap(void){
	for(int j=0;j<81;++j){
		cout<<map[j]<<" ";
		if( j%9 == 8 ){
			cout<<endl;
		}
	}
}
void Sudoku::outAnswer(void){

	for(int k=0;k<multiAnswer.size();++k){
		if(k==1){
			cout<<endl;
		}
		for(int i=0;i<81;++i){
			cout<<multiAnswer.at(k).at(i)<<" ";
			if( i%9 == 8 ){
				cout<<endl;
			}
		}
	}

}

int Sudoku::solveOne(vector<int> Test, vector<Pixel> X, vector<Pixel> Y, vector<Pixel> G){
	int check1;
	int check2;
	int check3;
	int i;
	unsigned int tmpt;
	vector<int> t;

	while(1){

		check1=0;
		check2=0;

		for(i=0;i<81;++i){
			if(Test[i]==0){
				check1++;
				tmpt=X[i%9].contain & Y[i/9].contain & G[(i/27)*3+((i%9)/3)].contain;

				if( tmpt == 0 ){
					return 0;
				}

				t.clear();
				for(int n=1;n<10;++n){
					if( ( tmpt>>(n-1) ) & 0x0001 ){
						t.push_back(n);
					}
				}

				if( t.size()==1 ){
					check2++;
					Test[i]=t.at(0);
					X[i%9].contain &= ~( 0x0001 << (t.at(0)-1) );
					Y[i/9].contain &= ~( 0x0001 << (t.at(0)-1) );
					G[(i/27)*3+((i%9)/3)].contain &= ~( 0x0001 << (t.at(0)-1) );
				}

			}//if(test[i]==0)
		}//for(i<81)

		if(check1==0){
			multiAnswer.push_back(Test);
			return 1;//good answer output
		}

		if(check2==0){
			if( solveMulti(Test,X,Y,G) ){
				return 1;
			}
			else{
				return 0;
			}
		}

	}//while(1)
}

int Sudoku::solveMulti(vector<int> Test, vector<Pixel> X, vector<Pixel> Y, vector<Pixel> G){

	vector<int> t;
	unsigned int tmpt;

	for(int i=0;i<81;++i){
		if(Test[i]==0){

			tmpt=X[i%9].contain & Y[i/9].contain & G[(i/27)*3+((i%9)/3)].contain;

			t.clear();
			for(int n=1;n<10;++n){
				if( ( tmpt>>(n-1) ) & 0x0001 ){
					t.push_back(n);
				}
			}

			for(int k=0;k<t.size();++k){

				Test[i]=t.at(k);
				X[i%9].contain &= ~( 0x0001 << (t.at(k)-1) );
				Y[i/9].contain &= ~( 0x0001 << (t.at(k)-1) );
				G[(i/27)*3+((i%9)/3)].contain &= ~( 0x0001 << (t.at(k)-1) );

				if( solveOne( Test, X, Y, G) == 1 ){
					if( multiAnswer.size() > 1 ){
						return 1;
					}
				}

				X[i%9].contain |= ( 0x0001 << (t.at(k)-1) );
				Y[i/9].contain |= ( 0x0001 << (t.at(k)-1) );
				G[(i/27)*3+((i%9)/3)].contain |= ( 0x0001 << (t.at(k)-1) );
			}

			return 0;//guess all and failure

		}//if(test[i]==0)

	}//for(i<81)

}//function end

const int Sudoku::Map[15][9][9]=
{
	{
		{ 7, 0, 0, 0, 0, 8, 0, 0, 0},
		{ 0, 1, 0, 0, 2, 0, 0, 0, 6},
		{ 0, 0, 5, 0, 0, 0, 9, 0, 0},
		{ 4, 0, 0, 0, 0, 3, 8, 0, 0},
		{ 6, 0, 0, 0, 0, 0, 0, 0, 7},
		{ 0, 0, 9, 0, 0, 5, 0, 0, 2},
		{ 0, 0, 3, 0, 0, 0, 4, 0, 0},
		{ 8, 0, 0, 0, 1, 0, 0, 5, 0},
		{ 0, 0, 0, 7, 0, 0, 0, 0, 1},
	},
	{
		{ 6, 0, 0, 0, 0, 0, 4, 0, 0},
		{ 0, 0, 7, 0, 0, 1, 0, 0, 0},
		{ 0, 9, 0, 0, 0, 8, 3, 0, 0},
		{ 0, 5, 0, 0, 2, 0, 0, 0, 9},
		{ 4, 0, 0, 0, 0, 0, 0, 0, 6},
		{ 8, 0, 0, 0, 0, 7, 0, 1, 0},
		{ 0, 0, 2, 5, 0, 0, 0, 7, 0},
		{ 0, 0, 0, 3, 0, 0, 8, 0, 0},
		{ 0, 0, 4, 0, 0, 0, 0, 0, 2},
	},
	{
		{ 3, 0, 0, 0, 6, 0, 0, 0, 5},
		{ 0, 0, 0, 8, 0, 0, 0, 9, 0},
		{ 0, 2, 0, 0, 4, 0, 0, 1, 0},
		{ 7, 0, 0, 0, 0, 0, 3, 0, 0},
		{ 0, 0, 5, 0, 2, 0, 4, 0, 0},
		{ 0, 0, 6, 0, 1, 0, 0, 0, 8},
		{ 0, 9, 0, 0, 5, 0, 0, 2, 0},
		{ 0, 4, 0, 0, 0, 7, 0, 0, 0},
		{ 5, 0, 0, 0, 3, 0, 0, 0, 4},
	},
	{
		{ 0, 8, 0, 0, 0, 5, 0, 0, 0},
		{ 3, 0, 0, 0, 0, 0, 0, 0, 6},
		{ 0, 0, 4, 0, 0, 1, 0, 9, 0},
		{ 2, 0, 0, 7, 0, 0, 0, 3, 0},
		{ 0, 5, 0, 0, 0, 0, 0, 4, 0},
		{ 0, 1, 0, 8, 0, 0, 0, 0, 9},
		{ 0, 7, 0, 2, 0, 0, 8, 0, 0},
		{ 6, 0, 0, 0, 0, 0, 0, 0, 2},
		{ 0, 0, 0, 9, 0, 0, 0, 5, 0},
	},
	{
		{ 2, 0, 0, 9, 0, 0, 0, 8, 0},
		{ 0, 0, 0, 0, 7, 0, 3, 0, 0},
		{ 0, 0, 4, 0, 0, 1, 6, 0, 0},
		{ 5, 0, 0, 0, 0, 4, 1, 0, 0},
		{ 9, 0, 0, 0, 0, 0, 0, 0, 2},
		{ 0, 0, 6, 0, 3, 0, 0, 0, 7},
		{ 0, 0, 8, 5, 0, 0, 4, 0, 0},
		{ 0, 0, 7, 0, 6, 0, 0, 0, 0},
		{ 0, 1, 0, 0, 0, 8, 0, 0, 9},
	},
	{
		{ 0, 0, 3, 0, 0, 0, 0, 9, 0},
		{ 7, 0, 0, 0, 2, 0, 0, 0, 0},
		{ 8, 0, 0, 0, 0, 5, 6, 0, 0},
		{ 0, 0, 4, 0, 0, 1, 5, 0, 0},
		{ 0, 2, 0, 9, 0, 0, 0, 3, 0},
		{ 0, 0, 6, 0, 0, 0, 8, 0, 0},
		{ 0, 0, 1, 4, 0, 0, 0, 0, 7},
		{ 0, 0, 0, 0, 8, 0, 0, 0, 4},
		{ 0, 6, 0, 0, 0, 0, 2, 0, 0},
	},
	{
		{ 0, 0, 1, 0, 0, 0, 9, 0, 0},
		{ 0, 3, 0, 8, 0, 0, 7, 0, 0},
		{ 0, 4, 0, 0, 0, 6, 0, 0, 0},
		{ 0, 0, 5, 0, 2, 0, 0, 1, 0},
		{ 7, 0, 0, 0, 0, 0, 0, 0, 3},
		{ 0, 6, 0, 0, 4, 0, 8, 0, 0},
		{ 0, 0, 0, 5, 0, 0, 0, 2, 0},
		{ 9, 0, 0, 0, 0, 7, 0, 4, 0},
		{ 0, 0, 7, 0, 0, 0, 6, 0, 0},
	},
	{
		{ 0, 0, 7, 8, 0, 0, 0, 1, 0},
		{ 0, 5, 0, 0, 0, 6, 2, 0, 0},
		{ 0, 0, 0, 0, 3, 0, 0, 9, 0},
		{ 0, 4, 0, 0, 0, 0, 5, 0, 0},
		{ 0, 0, 8, 0, 0, 7, 6, 0, 0},
		{ 0, 0, 1, 0, 0, 2, 0, 3, 0},
		{ 0, 9, 0, 0, 4, 0, 0, 0, 0},
		{ 0, 0, 6, 1, 0, 0, 0, 7, 0},
		{ 0, 2, 0, 0, 0, 3, 8, 0, 0},
	},
	{
		{ 0, 6, 0, 0, 5, 0, 0, 0, 9},
		{ 0, 0, 4, 0, 0, 0, 0, 1, 0},
		{ 8, 0, 0, 0, 2, 0, 0, 0, 0},
		{ 0, 7, 0, 0, 0, 3, 0, 0, 6},
		{ 2, 0, 0, 0, 8, 0, 0, 0, 5},
		{ 9, 0, 0, 0, 0, 0, 0, 4, 0},
		{ 0, 0, 0, 0, 7, 0, 0, 0, 3},
		{ 0, 1, 0, 0, 0, 0, 8, 0, 0},
		{ 5, 0, 0, 0, 4, 0, 0, 9, 0},
	},
	{
		{ 0, 0, 9, 0, 0, 0, 0, 3, 0},
		{ 0, 2, 0, 8, 0, 0, 0, 0, 0},
		{ 0, 6, 0, 7, 0, 0, 0, 4, 0},
		{ 0, 1, 0, 0, 0, 0, 5, 0, 0},
		{ 8, 0, 0, 0, 3, 0, 0, 0, 2},
		{ 0, 0, 7, 6, 0, 0, 0, 9, 0},
		{ 0, 5, 0, 0, 0, 1, 0, 6, 0},
		{ 0, 0, 0, 0, 0, 4, 0, 8, 0},
		{ 0, 9, 0, 0, 0, 0, 1, 0, 0},
	},
	{
		{ 0, 3, 0, 0, 0, 4, 7, 0, 0},
		{ 0, 0, 0, 0, 8, 0, 0, 2, 0},
		{ 5, 0, 0, 9, 0, 0, 0, 0, 6},
		{ 1, 0, 0, 0, 0, 0, 4, 0, 0},
		{ 0, 7, 0, 5, 0, 0, 0, 3, 0},
		{ 0, 0, 9, 0, 0, 2, 0, 0, 8},
		{ 6, 0, 0, 0, 0, 1, 0, 0, 9},
		{ 0, 4, 0, 0, 7, 0, 0, 0, 0},
		{ 0, 0, 5, 8, 0, 0, 0, 4, 0},
	},
	{
		{ 7, 0, 0, 9, 0, 0, 0, 2, 0},
		{ 3, 0, 0, 0, 0, 0, 0, 5, 0},
		{ 8, 0, 0, 6, 0, 0, 0, 0, 0},
		{ 0, 0, 4, 0, 0, 0, 0, 1, 0},
		{ 9, 0, 0, 8, 0, 0, 0, 0, 3},
		{ 0, 6, 0, 0, 5, 0, 7, 0, 0},
		{ 0, 0, 0, 0, 0, 4, 0, 0, 9},
		{ 0, 1, 0, 0, 0, 0, 0, 0, 8},
		{ 0, 2, 0, 0, 0, 1, 0, 0, 6},
	},
	{
		{ 0, 7, 0, 8, 0, 0, 2, 0, 0},
		{ 0, 0, 0, 0, 1, 0, 0, 3, 0},
		{ 4, 0, 0, 0, 0, 6, 0, 5, 0},
		{ 0, 9, 0, 0, 0, 4, 7, 0, 0},
		{ 5, 0, 0, 2, 0, 0, 0, 0, 8},
		{ 0, 0, 6, 3, 9, 0, 0, 1, 0},
		{ 0, 8, 0, 7, 0, 0, 0, 0, 9},
		{ 0, 2, 0, 0, 8, 0, 0, 0, 0},
		{ 0, 0, 7, 0, 0, 1, 0, 8, 0},
	},
	{
		{ 2, 0, 0, 7, 0, 0, 0, 4, 0},
		{ 0, 0, 3, 0, 9, 0, 0, 8, 0},
		{ 0, 0, 0, 0, 0, 1, 5, 0, 0},
		{ 6, 0, 0, 0, 0, 0, 0, 0, 2},
		{ 0, 9, 0, 0, 3, 0, 0, 7, 0},
		{ 4, 0, 0, 0, 0, 5, 0, 0, 1},
		{ 0, 0, 8, 6, 0, 0, 0, 0, 0},
		{ 0, 7, 0, 0, 4, 0, 9, 0, 0},
		{ 0, 1, 0, 0, 0, 3, 0, 0, 8},
	},
	{
		{ 9, 0, 0, 6, 0, 0, 0, 0, 0},
		{ 0, 0, 4, 1, 0, 0, 0, 0, 5},
		{ 0, 2, 0, 0, 0, 0, 7, 0, 0},
		{ 0, 3, 0, 0, 0, 8, 0, 2, 0},
		{ 6, 0, 0, 0, 0, 0, 0, 0, 9},
		{ 0, 7, 0, 5, 0, 0, 0, 1, 0},
		{ 0, 0, 8, 0, 0, 0, 0, 4, 0},
		{ 1, 0, 0, 0, 0, 3, 6, 0, 0},
		{ 0, 0, 0, 0, 0, 2, 0, 0, 8},
	}
};
