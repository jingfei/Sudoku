#include"Sudoku.h"
using namespace std;


		void Sudoku::ReadIn(){
			int i,j;
			 for(i=0;i<9;i++){
				for(j=0;j<9;j++){
					a[i][j]=0;
				}
			}
			for(i=0;i<9;i++){
				for(j=0;j<9;j++){
					answer[i][j]=0;
				}
			}
			for(i=0;i<9;i++){
				for(j=0;j<9;j++){
					cin >> a[i][j];
				}
			}
		}
		int Sudoku::verticalcheck(int number,int j){
			int m;
			for(m=0;m<9;m++){
				if(a[m][j]==number){
					return 0;
				}
				return 1;
			}
		}
		int Sudoku::standardcheck(int i,int number){
			int m;
			for(m=0;m<9;m++){
				if(a[i][m]==number){
					return 0;
				}
				return 1;
			}
		}
		int Sudoku::squarecheck(int number,int i,int j){
			int m;
			int n;
			if(i=0){
				if(j==0||j==3||j==6){
					for(m=0;m<3;m++){
						for(n=0;n<3;n++){
							if(a[i+m][j+n]==number){
								return 0;
							}
							return 1;
						}
					}
				}
				if(j==1||j==4||j==7){
					for(m=0;m<3;m++){
						for(n=-1;n<2;n++){
							if(a[i+m][j+n]==number){
								return 0;
							}
							return 1;
						}
					}
				}
				if(j==2||j==5||j==8){
					for(m=0;m<3;m++){
						for(n=-2;n<1;n++){
							if(a[i+m][j+n]==number){
								return 0;
							}
							return 1;
						}
					}
				}
			}
			if(i==1||i==4||i==7){
				if(j==0||j==3||j==6){
					for(m=-1;m<2;m++){
						for(n=0;n<3;n++){
							if(a[i+m][j+n]==number){
								return 0;
							}
							return 1;
						}
					}
				}
				if(j==1||j==4||j==7){
					for(m=-1;m<2;m++){
						for(n=-1;n<2;n++){
							if(a[i+m][j+n]==number){
								return 0;
							}
							return 1;
						}
					}
				}
				if(j==2||j==5||j==8){
					for(m=-1;m<2;m++){
						for(n=-2;n<1;n++){
							if(a[i+m][j+n]==number){
								return 0;
							}
							return 1;
						}
					}
				}
			}
			if(i==2||i==5||i==8){
				if(j==0||j==3||j==6){
					for(m=-2;m<1;m++){
						for(n=0;n<3;n++){
							if(a[i+m][j+n]==number){
								return 0;
							}
							return 1;
						}
					}
				}
				if(j==1||j==4||j==7){
					for(m=-2;m<1;m++){
						for(n=-1;n<2;n++){
							if(a[i+m][j+n]==number){
								return 0;
							}
							return 1;
						}
					}
				}
				if(j==2||j==5||j==8){
					for(m=-2;m<0;m++){
						for(n=-2;n<1;n++){
							if(a[i+m][j+n]==number){
								return 0;
							}
							return 1;
						}
					}
				}
			}
		}
	
		void Sudoku::make(){
			int number;
			int i,j;
			i=0;
			j=0;
			if(a[i][j]!=0){
				number=number+a[i][j];
			}
			if(number==405){
				int frequencyofnum;
				frequencyofnum++;
				if(frequencyofnum>1){
					cout << "It has more than one answer" << endl;
					return;
				}
				for(i=0;i<9;i++){
					for(j=0;j<9;j++){
						answer[i][j]=a[i][j]; 
					}
				}
				return;
				
			}
			int writein;
			for(i=0;i<9;i++){
				for(j=0;j<9;j++){
					if(a[i][j]==0){
						for(writein=1;writein<10;writein++){
							if(verticalcheck(writein,j)==1&&standardcheck(i,writein)==1&&squarecheck(writein,i,j)==1){
								a[i][j]=writein;
								make();
								a[i][j]=0; 
							}
						}
					return;
					}	
					
				}
			}
		}
		void Sudoku::Solve(){
			make();
			int i;
			int j;
			for(i=0;i<9;i++){
				cout <<endl;
				for(j=0;j<9;j++){
					cout << answer[i][j] << " " ;
				}
			}
		}
		void Sudoku::GiveQuestion(){
		int a;
		srand(time(NULL));
		a=(rand()%4)+1;
		if(a==1){
			cout << " 0 0 5 3 0 0 0 0 0 " << endl << " 8 0 0 0 0 0 0 2 0 " <<
			endl << " 0 7 0 0 1 0 5 0 0 " << endl << " 4 0 0 0 0 5 3 0 0 " <<
			endl << " 0 1 0 0 7 0 0 0 6 " << endl << " 0 0 3 2 0 0 0 8 0 " <<
			endl << " 0 6 0 5 0 0 0 0 9 " << endl << " 0 0 4 0 0 0 0 3 0 " <<
			endl << " 0 0 0 0 0 9 7 0 0 " << endl; 					
		}
		if(a==2){
			cout << " 0 0 0 0 0 0 0 0 0 " << endl << " 0 0 0 4 0 1 0 0 0 " <<
			endl << " 1 3 0 0 0 0 6 0 4 " << endl << " 0 0 0 0 7 0 0 0 0 " <<
			endl << " 5 0 0 0 0 0 0 0 2 " << endl << " 0 2 8 0 4 0 7 1 0 " <<
			endl << " 0 9 2 8 0 6 5 7 0 " << endl << " 0 0 7 0 0 0 8 0 0 " <<
			endl << " 0 0 0 5 0 7 0 0 0 " << endl; 	
		}
		if(a==3){
			cout << " 0 0 0 7 0 0 0 0 0 " << endl << " 0 6 1 0 0 0 0 0 0 " <<
			endl << " 0 0 0 3 2 0 0 5 0 " << endl << " 0 0 0 0 0 0 0 0 8 " <<
			endl << " 2 0 0 0 5 0 0 0 0 " << endl << " 0 0 0 0 0 1 9 0 6 " <<
			endl << " 0 0 0 0 0 0 0 0 0 " << endl << " 3 0 0 0 0 2 0 7 0 " <<
			endl << " 0 9 0 0 6 8 0 0 0 " << endl; 	
		}
		if(a==4){
			cout << " 8 0 0 0 0 0 0 0 0 " << endl << " 0 0 3 6 0 0 0 0 0 " <<
			endl << " 0 7 0 0 9 0 2 0 0 " << endl << " 0 5 0 0 0 7 0 0 0 " <<
			endl << " 0 0 0 0 4 5 7 0 0 " << endl << " 0 0 0 1 0 0 0 3 0 " <<
			endl << " 0 0 1 0 0 0 0 6 8 " << endl << " 0 0 8 5 0 0 0 1 0 " <<
			endl << " 0 9 0 0 0 0 4 0 0 " << endl;
		}	
		}
