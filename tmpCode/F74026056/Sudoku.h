/****************
 *	Sudoku		*
 *	By Jim Lai  *
 *	ID:F74026056*
 ****************/
#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<fstream>

using namespace std;

class Sudoku{
	public:
		
		Sudoku(){

		}
		
		void GiveQuestion(){
			unique_solution = false;
			//while(!unique_solution){
				create_sudoku();
				//get_answer();
				set_block(40);
				print_out_sudoku();						//在這裡可以調控空格數，通常48以上就要花很久的時間 
				//cout<<"question:"<<endl;
				//get_test();
				//cout<<"answer:"<<endl;
				transver_array();
				solve_sudoku(0,0);					//從solve_question搬過來的 
				//testify();							//從solve_question搬過來的 
				unique_solution = unique_check();
				
				//} 
		//	print_out_sudoku();
			
		}
		
		void create_sudoku(){
			int start_num=1;
			srand((unsigned) time(NULL));
			for(i=0;i<9;i++){
				
				for(j=0;j<9;j++){
					array_sudoku[i][j]=start_num;
					start_num++;
					if(start_num==10){
						start_num=1;
					}
					
				}
				
				switch(start_num){
				 	case 1:
				 	start_num=4;
				 	break;
					case 4:
					start_num=7;
					break;
					case 7:
					start_num=9;
					break;
					case 9:
					start_num=3;
					break;
					case 3:
					start_num=6;
					break;
					case 6:
					start_num=8;
					break;
					case 8:
					start_num=2;
					break;
					case 2:
					start_num=5;
					break;
					case 5:
					start_num=1;
					break;
					
				}
			}
			
			for(i=0;i<3;i++){
			arrange_sudoku_row(0);
			arrange_sudoku_column(0);
			}
			
			for(i=1;i<10;i++){
			//arrange_special_row(i,0);
			arrange_special_column(i,0);
			}
			
			for(i=0;i<3;i++){
			arrange_sudoku_row(0);
			arrange_sudoku_column(0);
			}
			
			
		}
		
		int arrange_sudoku_row(int k){
			if(k==9){
				return 0;
			}
			int row_temp[9];
			for(i=0;i<3;i++)
			{
				int x=rand()%3;
				int y=rand()%3;
				while(y==x){
				y=rand()%3;
				}
				
				for(j=0;j<9;j++){
					row_temp[j]=array_sudoku[x+k][j];
					array_sudoku[x+k][j]=array_sudoku[y+k][j];
					array_sudoku[y+k][j]=row_temp[j];	
				}
				
				
			}
			k+=3;
			return arrange_sudoku_column(k);
		}
		
		int arrange_sudoku_column(int k){
			if(k==9){
				return 0;
			}
			int column_temp[9];
			for(i=0;i<3;i++)
			{
				int x=rand()%3;
				int y=rand()%3;
				while(y==x){
				y=rand()%3;
				}
				
				for(j=0;j<9;j++){
					column_temp[j]=array_sudoku[j][x+k];
					array_sudoku[j][x+k]=array_sudoku[j][y+k];
					array_sudoku[j][y+k]=column_temp[j];	
				}
				
				
			}
			k+=3;
			return arrange_sudoku_row(k);
		}
		
		//----------------------------------------------------------------------
		 
		int arrange_special_row(int num,int k){     //有問題，無用處 
			if(k==9){
				return 0;
			}
			int row_temp[9];
			int record[3],un=0;
			for(i=0;i<9;i++){
				for(j=0;j<9;j++){
					if(array_sudoku[i][j]==num&&j<k+3&&j>=k){
						record[un]=i;
						un++;
						break;	
					}
				}
			}
			
			int x=(rand()+1)%3;
			int y=(rand()+2)%3;
			while(y==x){
			y=rand()%3;
			}
			
			for(j=0;j<9;j++){
					row_temp[j]=array_sudoku[record[x]][j];
					array_sudoku[record[x]][j]=array_sudoku[record[y]][j];
					array_sudoku[record[y]][j]=row_temp[j];	
			}
			
			k+=3;
			return arrange_special_row(num,k);
		}
		
		
		//---------------------------------------------------------------------- 
		
		int arrange_special_column(int num,int k){
			if(k==9){
				return 0;
			}
			int column_temp[9];
			int record[3],un=0;
			for(i=0;i<9;i++){
				for(j=0;j<9;j++){
					if(array_sudoku[i][j]==num&&i<k+3&&i>=k){
						record[un]=j;
						un++;
						break;	
					}
				}
			}
			
			int x=(rand()+1)%3;
			int y=(rand()+2)%3;
			while(y==x){
			y=rand()%3;
			}
			
			for(j=0;j<9;j++){
					column_temp[j]=array_sudoku[j][record[x]];
					array_sudoku[j][record[x]]=array_sudoku[j][record[y]];
					array_sudoku[j][record[y]]=column_temp[j];	
			}
			
			k+=3;
			return arrange_special_column(num,k);
		}
		
		int set_block(int block_number){
			if(block_number==0){
				return 0;	
			}
			int x,y;
			
			do{
				x=(rand()+3)%9;
				y=(rand()+7)%9;
			}while(array_sudoku[x][y]==0);
			
			array_sudoku[x][y]=0;
			return set_block(block_number-1);
		}
		
		void print_out_sudoku(){
			ofstream output("output.txt",ios::out);
			
			//
			char clone[9][9];
			
			for(i=0;i<9;i++){
				for(j=0;j<9;j++){
					switch(array_sudoku[i][j]){
						case 0:
						clone[i][j]='0';
						break;
						case 1:
						clone[i][j]='1';
						break;
						case 2:
						clone[i][j]='2';
						break;
						case 3:
						clone[i][j]='3';
						break;
						case 4:
						clone[i][j]='4';
						break;
						case 5:
						clone[i][j]='5';
						break;
						case 6:
						clone[i][j]='6';
						break;
						case 7:
						clone[i][j]='7';
						break;
						case 8:
						clone[i][j]='8';
						break;
						case 9:
						clone[i][j]='9';
						break; 
					}
				}
			}
			
			
			
			//
			
			for(i=0;i<9;i++){
				for(j=0;j<9;j++){
					cout<<clone[i][j]<<" ";
				}
				cout<<endl;
			}
			
		}
		                  
		void get_test(){
			for(i=0;i<9;i++){
				for(j=0;j<9;j++){
					cout<<array_sudoku[i][j];
				}
				cout<<endl;
			}
					
		}
		
		void get_answer(){
			ofstream output("ReferenceAnswer.txt",ios::out);
			output<<"The reference answer is:"<<endl; 
			char clone[9][9];
			
					for(i=0;i<9;i++){
				for(j=0;j<9;j++){
					switch(array_sudoku[i][j]){
						case 0:
						clone[i][j]='0';
						break;
						case 1:
						clone[i][j]='1';
						break;
						case 2:
						clone[i][j]='2';
						break;
						case 3:
						clone[i][j]='3';
						break;
						case 4:
						clone[i][j]='4';
						break;
						case 5:
						clone[i][j]='5';
						break;
						case 6:
						clone[i][j]='6';
						break;
						case 7:
						clone[i][j]='7';
						break;
						case 8:
						clone[i][j]='8';
						break;
						case 9:
						clone[i][j]='9';
						break; 
					}
				}
			}
			
			
			for(i=0;i<9;i++){
				for(j=0;j<9;j++){
					output<<array_sudoku[i][j]<<" ";
				}
				output<<endl;
			}
			
		}
		
		
		bool unique_check(){
			for(int i=0;i<9;i++){
				for(int j=0;j<9;j++){
					if(arr_sudoku[i][j]==0){
						return false;
					}
				}
			}
			return true;
		}
		
		void transver_array(){
			for(int i=0;i<9;i++){
				for(int j=0;j<9;j++){
					arr_sudoku[i][j]=array_sudoku[i][j];	
					}
				}
			}
	
		void ReadIn(){
			answer=0;
			remove("SolveResult.txt");
			inputfile();
		}
		
		int check_blank(){
			int sum=0;
			for(int i=0;i<9;i++){
				for(int j=0;j<9;j++){
					if(arr_sudoku[i][j]==0){
						sum++;
					}
				}
			}
			return sum;
		}
		
		bool check_right(int set_row,int set_column){
			cout<<""; 
			if(set_row==9){return true;}
			 int rcheck[10],ccheck[10];
			 for(int i=1;i<10;i++){
			 	rcheck[i]=0;
			 	ccheck[i]=0;
			 }
			 for(int i=0;i<9;i++){
			 	int k = arr_sudoku[set_row][i];
			 	rcheck[k]=rcheck[k]+1;
			 	k = arr_sudoku[i][set_column];
			 	ccheck[k]=ccheck[k]+1;
			 }
			 
			 int out = 0;
			 for(int i=1;i<10;i++){
			 	int m = rcheck[i];
			 	//cout<<m;
			 	if(m>1){
			 		 out = 1;
			 		 //cout<<"X";
			 	}
			 	m = ccheck[i];
			 	//cout<<m;
			 	if(m>1){
			 		 out = 1;
			 		 //cout<<"X";
			 	}
			 	}
			 	
			 	if(out==0){
			 		//cout<<" B ";
			 		return set_column==8?(check_right(set_row+1,0)):(check_right(set_row,set_column+1));
			 	}
			 	else{
			 		return false;
			 	}
			 
			 
		}
		
		void Solve(){
			
			
			/*if(!right){
				cout<<"0";
			}	*/	
			
			right = false;
			right = check_right(0,0);
			//cout<<right;
			
			int blank = check_blank();
			
			if(!right){
				cout<<"0";
			}else{
			
			//right = true;
			//right = check_right(0,0);
			
			solve_sudoku(0,0);
			check_answer();//#
			//testify();
			
			
			input_colsudoku();
			sudoku_into_possibility();
			
			
			/*
			for(int i=0;i<9;i++){
				for(int j=0;j<9;j++){
					assume_way(i,j);
				}
			}*/
			control = false ;
				if(blank>=45&&right==true){
					cout<<"2";
				}
				else{
				
			

				arrange_all_possibility_input(0,0);
			
			//initial_table();
			//arrange_all_possibility_input(0,0);
			if(control){
				cout<<"2";
			}
			else
			{
			delete_same_answer(1,2);
			duel_with_true_answer();
			//get_record();
			print_out_answer();	
			}
			
			 
		
			
		}
		}
			
		}
		
		void inputfile(){
			ifstream input("output.txt",ios::in);
			for(int i=0;i<9;i++){
				for(int j=0;j<9;j++){
					cin>>char_arr_sudoku[j][i];
					char transform[1];
					transform[0]=char_arr_sudoku[j][i];
					arr_sudoku[i][j]=atoi(transform);
				}
			}
			input.close();
		}
		
		
		void testify(){
			//ofstream output("SolvingResult.txt",ios::app);// 3/26
			for(int i=0;i<9;i++){
				for(int j=0;j<9;j++){
					cout<<arr_sudoku[i][j];
					//output<<arr_sudoku[i][j];	// 3/26
				}
				cout<<endl;
				//output<<endl;	
			}
			//output<<endl<<"---------------------"<<endl;// 3/26
		}
		
		
		//-------------------------------------------
		
		int solve_sudoku(int set_row,int set_column){
			cout<<"";//不能刪，不然有BUG 
			initialize_arr_sudoku_sol();
			
			if(set_row==9){return 0;}
			if(arr_sudoku[set_row][set_column]!=0){
				return set_column==8?(solve_sudoku(set_row+1,0)):(solve_sudoku(set_row,set_column+1));
			}else{
				solve_row(set_row);
				solve_column(set_column);
				solve_square(set_row,set_column);
			
			    /*
				for(int i=1;i<10;i++){
				cout<<i<<":"<<arr_sudoku_sol[i]<<endl;
				}*/
			
				int k = check();
				
				if(k==0){
					return set_column==8?(solve_sudoku(set_row+1,0)):(solve_sudoku(set_row,set_column+1));
				}else{
					arr_sudoku[set_row][set_column]=k;
					return solve_sudoku(0,0);
				}
			}
		}
		
		void initialize_arr_sudoku_sol(){
			for(int i=0;i<10;i++){
				arr_sudoku_sol[i]=true;
			}
		}
		
		void solve_row(int set_row){
				for(int j=0;j<9;j++){
					if(arr_sudoku[set_row][j]==0){
						continue;
					}
					int k=arr_sudoku[set_row][j];
					arr_sudoku_sol[k]=false;
				}
			
		}
		
		void solve_column(int set_column){
			for(int i=0;i<9;i++){
					if(arr_sudoku[i][set_column]==0){
						continue;
					}
					int k=arr_sudoku[i][set_column];
					arr_sudoku_sol[k]=false;
				}
		}
		
		void solve_square(int set_row,int set_column){
			if(set_row<3&&set_column<3){
				solve_square_stage2(0,0);
			}else if(set_row<3&&3<=set_column&&set_column<6){
				solve_square_stage2(0,3);
			}else if(set_row<3&&6<=set_column&&set_column<9){
				solve_square_stage2(0,6);
			}else if(3<=set_row&&set_row<6&&set_column<3){
				solve_square_stage2(3,0);
			}else if(3<=set_row&&set_row<6&&3<=set_column&&set_column<6){
				solve_square_stage2(3,3);
			}else if(3<=set_row&&set_row<6&&6<=set_column&&set_column<9){
				solve_square_stage2(3,6);
			}else if(6<=set_row&&set_row<9&&set_column<3){
				solve_square_stage2(6,0);
			}else if(6<=set_row&&set_row<9&&3<=set_column&&set_column<6){
				solve_square_stage2(6,3);
			}else if(6<=set_row&&set_row<9&&6<=set_column&&set_column<9){
				solve_square_stage2(6,6);
			}
			
		}
		
		void solve_square_stage2(int row,int column){
			int temp[10],t=0;
			for(int i=row;i<row+3;i++){
				for(int j=column;j<column+3;j++){
					temp[t]=arr_sudoku[i][j];
					t++;
				}
			}
			
			for(int i=0;i<10;i++){
				int k = temp[i];
				arr_sudoku_sol[k]=false;
			}
			
		}
		
		int check(){
			int time=0,answer=0;
			for(int t=1;t<10;t++){
				if(arr_sudoku_sol[t]==true){
					answer=t;
					time++;
				}
			}
				if(time==1){
					return answer;
				}else{
					return 0;
				}
			
		}
		
		//--------------------------------------------
		//--------------假設法************************
			int assume_way(int set_row,int set_column){
				initialize_arr_sudoku_sol();
				solve_row(set_row);
				solve_column(set_column);
				solve_square(set_row,set_column);
				assume(set_row,set_column);
				return 0;
			}
			
			void assume(int set_row,int set_column){
				int temp[10],t=0;
				for(int i=1;i<10;i++){
					temp[i]=0;
				}
				
				for(int i=1;i<10;i++){
					if(arr_sudoku_sol[i]==true){
						temp[t]=i;
						t++;
					}
				}
				
				
				for(int i=1;i<10;i++){
					if(temp[i]==0){
						continue;
					}
					arr_sudoku[set_row][set_column]=temp[i];//arr_sudoku_sol[i];
					solve_sudoku(0,0);
					check_answer();	//#				
					//testify();
					
					//possible_true_row();
					
					input_originalsudoku();//
					cout<<endl;
					cout<<"("<<set_row<<","<<set_column<<")"<<endl;
				}
				
				
			}
			
			//----------------------------------------
			void possible_true_row(){
				int target_row;
				int filled_num;
				int time=0;
				for(int i=0;i<9;i++){
					filled_num=0;
					for(int j=0;j<9;j++){
						if(arr_sudoku[i][j]!=0){
							filled_num++;
						}
						if(filled_num==9){
							target_row = i;
							time++;
							break;
						}
					}
					
					//possibility_into_array();
					//solve_sudoku(0,0);
					//testify();
					
					
				}
				
				if(time==1){
					for(int j=0;j<9;j++){
					assume_possibility[target_row][j]=arr_sudoku[target_row][j]	;
					}
				}
					
			}
			
			void sudoku_into_possibility(){
				for(int i=0;i<9;i++){
					for(int j=0;j<9;j++){
						assume_possibility[i][j]=arr_sudoku[i][j];
					}
				}
			}
			
			void possibility_into_array(){
					for(int i=0;i<9;i++){
						for(int j=0;j<9;j++){
							arr_sudoku[i][j]=assume_possibility[i][j];	
						}
					}
			}
			
			//--------------------------------------
			
			void input_colsudoku(){
				for(int i=0;i<9;i++){
					for(int j=0;j<9;j++){
					col_arr_sudoku[i][j]=arr_sudoku[i][j];
					assume_possibility[i][j]=arr_sudoku[i][j];	
					}
				}
			}
			
			void input_originalsudoku(){
				for(int i=0;i<9;i++){
					for(int j=0;j<9;j++){
					arr_sudoku[i][j]=col_arr_sudoku[i][j];	
					}
				}
			}
			
			//---------列舉法-------------------------
			int arrange_all_possibility_input(int set_row,int set_column){
				cout<<"";
				//ofstream output("progress.txt",ios::app);
				if(set_row==9){
					int N;
					//cout<<"end!"<<endl;
					N = check_answer();//#
					if(N==1){
						control = true;
					}
					//testify();
					//temp_output();
					input_originalsudoku();
					return 0;
				}
				if(control){
					return 0;
				}
				if(arr_sudoku[set_row][set_column]!=0){
					//cout<<set_row<<","<<set_column<<endl;
					return set_column==8? arrange_all_possibility_input(set_row+1,0):arrange_all_possibility_input(set_row,set_column+1);
				}else{
				arrange_assume(set_row,set_column);
				return set_column==8? arrange_all_possibility_input(set_row+1,0):arrange_all_possibility_input(set_row,set_column+1);}
			}
			
			int arrange_assume(int set_row,int set_column){
				if(control){
					return 0;
				}
				solve_sudoku(0,0);
				
				initialize_arr_sudoku_sol();
				solve_row(set_row);
				solve_column(set_column);
				solve_square(set_row,set_column);
				
				//get_table(set_row,set_column);
				
				for(int i=1;i<10;i++){
					if(arr_sudoku_sol[i]==false){
						continue;
					}else{
						if(control){
							return 0;
						}
						arr_sudoku[set_row][set_column]=i;
						solve_sudoku(0,0);
						return set_column==8? arrange_all_possibility_input(set_row+1,0):arrange_all_possibility_input(set_row,set_column+1);
					}
				}
				return 0;
			}
			
			void initial_table(){
				for(int i=0;i<9;i++){
					for(int j=0;j<9;j++){
						for(int k=1;k<10;k++){
							solvable_table[i][j][k]=false;	
						}
						input_data_into_table(i,j);
					}
				}
				
			}
			
			void input_data_into_table(int set_row,int set_column){
				initialize_arr_sudoku_sol();
				solve_row(set_row);
				solve_column(set_column);
				solve_square(set_row,set_column);
				for(int i=1;i<10;i++){
					if(arr_sudoku_sol[i]==true){
						solvable_table[set_row][set_column][i]=true;
					}
				}
				
			}
			
			void update_table(){
				for(int i=0;i<9;i++){
					for(int j=0;j<9;j++){
						int k = arr_sudoku[i][j];
						solvable_table[i][j][k] = true;
					}
				}
			}
			
			void get_table(int set_row,int set_column){
				for(int k=1;k<10;k++){
					arr_sudoku_sol[k]=solvable_table[set_row][set_column][k];
				}
			}
			
			
			

			
			//------------------------------------------------------- 2014/3/29
			
			
			int check_answer(){
				for(int i=0;i<9;i++){
					for(int j=0;j<9;j++){
						if(arr_sudoku[i][j]==0){
							return 0;
						}
					}
				}
				
				int same ;
				for(int i=1;i<=answer;i++){
					same = 0;
					
					for(int j=0;j<9;j++){
						for(int k=0;k<9;k++){
							if(record_answer[i][j][k]==arr_sudoku[j][k]){
								same++;	
							}	
						}
					}
					if(same==81){
						return 0;
					}
				}
				
				answer++;
				for(int j=0;j<9;j++){
					for(int k=0;k<9;k++){
						record_answer[answer][j][k]=arr_sudoku[j][k];
						//cout<<arr_sudoku[j][k]<<" ";//*
					}
					//cout<<endl;//*
				}
				//cout<<endl;//*
				
				if(answer==2){
					return 1;
				}
				return 0;
				
			}
			
			int delete_same_answer(int start,int comared){
			
				if(record_answer[start][0][0] == (-1)){
					return (answer >= start+1)? delete_same_answer(start+1,start+2):0;
				}
				if(record_answer[comared][0][0] == (-1)){
					return (answer >= comared+1 )? delete_same_answer(start,comared+1):delete_same_answer(start+1,start+2);
				}
				
					int same = 0;
					
					for(int j=0;j<9;j++){
						for(int k=0;k<9;k++){
							if(record_answer[start][j][k]==0){
								record_answer[start][0][0] = -1;
								return (answer >= start+1)? delete_same_answer(start+1,start+2):0;
							}
							
							if(record_answer[comared][j][k]==0){
								record_answer[comared][0][0] = -1;
								return (answer >= comared+1 )? delete_same_answer(start,comared+1):delete_same_answer(start+1,start+2);
							}
							if(record_answer[start][j][k]==record_answer[comared][j][k]){
								same++;
							}
						} 
					}
					
					if(same==81){
						record_answer[comared][0][0] = -1;
					}
				return (answer >= comared+1)? delete_same_answer(start,comared+1):delete_same_answer(start+1,start+2);
			}
			
			void duel_with_true_answer(){
				int true_number = answer;
				for(int i=1;i<=answer;i++){
					if(record_answer[i][0][0]==(-1)){
						true_number--;
					}
				}
				record_original_answer = answer;
				answer = true_number;
			}
			
			void get_record(){
				cout<<"answer:"<<answer<<endl;
			}
			
			void print_out_answer(){
				ofstream output("SolveResult.txt",ios::app);
				int number = 1;
				for(int i=1;i<=record_original_answer;i++){
					if(record_answer[i][0][0]==(-1)){
						continue;
					}
					cout<<number<<endl;
					
					for(int j=0;j<9;j++){
						
						for(int k=0;k<9;k++){
							cout<<record_answer[i][j][k]<<" ";
						}
						cout<<endl;
					}
					cout<<endl;
					number++;
					break;
				}
				if(number==1){
					cout<<"0";
				}
				
			}
			

		
		//-----------------***************************
		
	private:
		bool arr_sudoku_sol[10];	//true=有可能;false=不可能 
		char char_arr_sudoku[9][9];
		int arr_sudoku[9][9];
		int col_arr_sudoku[9][9];
		int assume_possibility[9][9];
		int answer,record_original_answer;
		int record_answer[82][9][9];
		int i,j;
		int array_sudoku[9][9];
		bool unique_solution;
		bool solvable_table[9][9][10];
		bool control;
		bool right;
		
}; 