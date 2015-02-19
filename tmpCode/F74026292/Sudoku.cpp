#include "Sudoku.h"
#include <time.h>
#include <stdlib.h>
Sudoku::Sudoku() {
  solved=false;
  multiple_answer=false;
  unsolvable=false;
}
void Sudoku::set_sudoku(int _map[9][9]){
	if(!check_sudoku(_map))return;
  for(int i=0;i<9;i++){
	  for(int j=0;j<9;j++){
		  map[i][j]=_map[i][j];
	  }
  }

}
void Sudoku::Solve(){
//must more than 17 to have only solution
	if(unsolvable){
		printf("0\n");
		return;
	}
    std::vector<space> spaces;
    bool possible_num[9];
    int sg_x,sg_y;
    for(int i=0;i<9;i++){
    	for(int j=0;j<9;j++){
    		if(map[j][i]==0){
    			space buff;
    			buff.x=j;
    			buff.y=i;
    			for(int k=0;k<9;k++)possible_num[k]=true;
    			for(int k=0;k<9;k++)if(map[k][i]>0)possible_num[map[k][i]-1]=false;
    			for(int k=0;k<9;k++)if(map[j][k]>0)possible_num[map[j][k]-1]=false;
                sg_x=(j-j%3);//sub_grid
                sg_y=(i-i%3);
                for(int l=sg_y;l<sg_y+3;l++){
                	for(int m=sg_x;m<sg_x+3;m++){
                		if(map[m][l]>0)
                		possible_num[map[m][l]-1]=false;
                	}
                }
                for(int k=0;k<9;k++)
                if(possible_num[k]==true){
                	buff.p_num.push_back(k+1);
                }
    			spaces.push_back(buff);
    		}
    	}
    }
    sol_map(spaces,map);
    if(solved==false)printf("0\n");
    if(multiple_answer)printf("2\n");
    if(!multiple_answer&&solved==true){
    	printf("1\n");
    	for(int i=0;i<9;i++){
    	    	for(int j=0;j<9;j++){
    	    		printf("%d ",answer[i][j]);
    	    	}printf("\n");
    	    }
    }
}
bool Sudoku::solve(int _map[9][9]){
    std::vector<space> spaces;
    bool possible_num[9];
    int sg_x,sg_y;
    for(int i=0;i<9;i++){
    	for(int j=0;j<9;j++){
    		if(_map[j][i]==0){
    			space buff;
    			buff.x=j;
    			buff.y=i;
    			for(int k=0;k<9;k++)possible_num[k]=true;
    			for(int k=0;k<9;k++)if(_map[k][i]>0)possible_num[_map[k][i]-1]=false;
    			for(int k=0;k<9;k++)if(_map[j][k]>0)possible_num[_map[j][k]-1]=false;
                sg_x=(j-j%3);//sub_grid
                sg_y=(i-i%3);
                for(int l=sg_y;l<sg_y+3;l++){
                	for(int m=sg_x;m<sg_x+3;m++){
                		if(_map[m][l]>0)
                		possible_num[_map[m][l]-1]=false;
                	}
                }
                for(int k=0;k<9;k++)
                if(possible_num[k]==true){
                	buff.p_num.push_back(k+1);
                }
    			spaces.push_back(buff);
    		}
    	}
    }
    sol_map(spaces,_map);
    if(solved==false){
    	solved=false;
    	multiple_answer=false;
    	unsolvable=false;
    	return false;
    }
    if(multiple_answer){
    	solved=false;
    	multiple_answer=false;
    	unsolvable=false;
    	return false;
    }
    if(!multiple_answer&&solved==true){
    	solved=false;
    	multiple_answer=false;
    	unsolvable=false;
        return true;
    }
    solved=false;
    multiple_answer=false;
    unsolvable=false;
    return false;
}
void Sudoku::sol_map(std::vector<space> spaces,int _map[9][9]){
 if(multiple_answer)return;
 if(spaces.empty()){//solved!!
  if(solved==false){
	  solved=true;
  for(int i=0;i<9;i++){
	  for(int j=0;j<9;j++){
		  answer[j][i]=_map[j][i];
	  }
   }
  }else{//more than one answer!!
    multiple_answer=true;
    return;
  }
  return;
 }
 int min=10,min_at=0;
 for(unsigned int i=0;i<spaces.size();i++){//find_min
	 if(spaces.at(i).p_num.size()<(unsigned)min){
		 min=spaces.at(i).p_num.size();
		 min_at=i;
	 }
 }
 if(spaces.at(min_at).p_num.size()==0){
	//no answer!!
	 return;
 }else{
	for(unsigned int i=0;i<spaces.at(min_at).p_num.size();i++){
		std::vector<space> s_buff=spaces;
		int s_num=spaces.at(min_at).p_num.at(i);
		_map[spaces.at(min_at).x][spaces.at(min_at).y]=s_num;
		s_buff.at(min_at)=s_buff.at(s_buff.size()-1);
		s_buff.pop_back();
		for(unsigned int j=0;j<s_buff.size();j++){//check same line,row,or sub_grid
			if(s_buff.at(j).x==spaces.at(min_at).x||s_buff.at(j).y==spaces.at(min_at).y||
			find_sub_grid(s_buff.at(j).x,s_buff.at(j).y)==
			find_sub_grid(spaces.at(min_at).x,spaces.at(min_at).y)	){
			for(unsigned int k=0;k<s_buff.at(j).p_num.size();k++){
               if(s_num==s_buff.at(j).p_num.at(k)){
            	   s_buff.at(j).p_num.at(k)=
            	   s_buff.at(j).p_num.at(s_buff.at(j).p_num.size()-1);
                   s_buff.at(j).p_num.pop_back();
               }
			}
		  }
		}
		sol_map(s_buff,_map);
	}
 }
}
void Sudoku::ReadIn(){
	int _map[9][9];
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
		   scanf("%d",&_map[i][j]);
		}
	}
	if(!check_sudoku(_map))return;
	  for(int i=0;i<9;i++){
		  for(int j=0;j<9;j++){
			  map[i][j]=_map[i][j];
		  }
	  }
}
void Sudoku::GiveQuestion(){
int q_map1[9][9]={
8, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 3, 6, 0, 0, 0, 0, 0,
0, 7, 0, 0, 9, 0, 2, 0, 0,
0, 5, 0, 0, 0, 7, 0, 0, 0,
0, 0, 0, 0, 4, 5, 7, 0, 0,
0, 0, 0, 1, 0, 0, 0, 3, 0,
0, 0, 1, 0, 0, 0, 0, 6, 8,
0, 0, 8, 5, 0, 0, 0, 1, 0,
0, 9, 0, 0, 0, 0, 4, 0, 0
};
int q_map2[9][9]={
0, 0, 5, 3, 0, 0, 0, 0, 0,
8, 0, 0, 0, 0, 0, 0, 2, 0,
0, 7, 0, 0, 1, 0, 5, 0, 0,
4, 0, 0, 0, 0, 5, 3, 0, 0,
0, 1, 0, 0, 7, 0, 0, 0, 6,
0, 0, 3, 2, 0, 0, 0, 8, 0,
0, 6, 0, 5, 0, 0, 0, 0, 9,
0, 0, 4, 0, 0, 0, 0, 3, 0,
0, 0, 0, 0, 0, 9, 7, 0, 0
};
/*int q_map3[9][9]={
0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0
};*/
	srand(time(NULL));
	int which;
	which=rand()%2;

	int question[9][9];
	switch(which){
	case 0:
		convert(q_map1,question);
		break;
	case 1:
		convert(q_map2,question);
		break;
	}
	int line_change=rand()%6;
	int line[3];
	switch(line_change){
	case 0:
		line[0]=0;
		line[1]=1;
		line[2]=2;
		break;
	case 1:
		line[0]=1;
		line[1]=2;
		line[2]=0;
		break;
	case 2:
		line[0]=2;
		line[1]=0;
		line[2]=1;
	    break;
	case 3:
		line[0]=0;
		line[1]=2;
		line[2]=1;
		break;
	case 4:
		line[0]=1;
		line[1]=0;
		line[2]=2;
		break;
	case 5:
		line[0]=2;
		line[1]=1;
		line[2]=0;
	}


 for(int i=0;i<9;i++){
	 for(int j=0;j<9;j++){
		 printf("%d ",question[j-(j%3)+line[j%3]][i-(i%3)+line[i%3]]);
	 }printf("\n");
 }


}
void Sudoku::convert(int map[9][9],int _map[9][9]){
	srand(time(NULL));
	 int arr[9];
	  bool buff[9];

	  for(int i=0;i<9;i++){
		  arr[i]=rand()%(9-i);
		  buff[i]=false;
	  }
	  for(int i=0;i<9;i++){
		  for(int j=0;j<9;j++){
			  if(arr[i]==0&&buff[j]==false){
				  arr[i]=j+1;
				  buff[j]=true;
				  break;
			  }
			  if(buff[j]==false)arr[i]--;
		  }
	  }
      for(int i=0;i<9;i++){
    	  for(int j=0;j<9;j++){
    		  if(map[j][i]>0)_map[j][i]=arr[map[j][i]-1];
    		  else _map[j][i]=0;
    	  }
      }
//convert line

}
void Sudoku::GiveQuestion_2(){
  int sudoku_c[9][9];
  for(int i=0;i<9;i++){
	  for(int j=0;j<9;j++){
		  if(i<3)sudoku_c[j][i]=(j+3*i)%9;
		  else{
			  switch(j%3){
			  case 0:
			  case 1:
				  sudoku_c[j][i]=sudoku_c[j+1][i-3];
				  break;
			  case 2:
			      sudoku_c[j][i]=sudoku_c[j-2][i-3];
			  	  break;
			  }
		  }
	  }
  }
  srand(time(NULL));
  int arr[9];
  bool buff[9];

  for(int i=0;i<9;i++){
	  arr[i]=rand()%(9-i);
	  buff[i]=false;
  }
  for(int i=0;i<9;i++){
	  for(int j=0;j<9;j++){
		  if(arr[i]==0&&buff[j]==false){
			  arr[i]=j+1;
			  buff[j]=true;
			  break;
		  }
		  if(buff[j]==false)arr[i]--;
	  }
  }
  for(int i=0;i<9;i++){
	  for(int j=0;j<9;j++){
		  sudoku_c[j][i]=arr[sudoku_c[j][i]];
	  }
  }




  for(int i=0;i<9;i++){
  	 for(int j=0;j<9;j++){
  		 printf("%d ",sudoku_c[j][i]);
  	 }printf("\n");
   }
}
void Sudoku::make_space(int num,int _map[9][9]){

}
bool Sudoku::check_sudoku(int map[9][9]){
	bool line_check[9],row_check[9];
	 for(int i=0;i<9;i++){
		  for(int m=0;m<9;m++)line_check[m]=false;
		  for(int j=0;j<9;j++){
			  if(line_check[map[j][i]-1]&&map[j][i]!=0){
				unsolvable=true;
				return false;
			  }else if(map[j][i]>0){
				line_check[map[j][i]-1]=true;
			  }
		  }
	  }
	 for(int j=0;j<9;j++){//check row
		 for(int m=0;m<9;m++)row_check[m]=false;
		 for(int i=0;i<9;i++){
			 if(map[j][i]!=0){
				 if(!row_check[map[j][i]-1])row_check[map[j][i]-1]=true;
				 else{
					 unsolvable=true;
					 return false;
				 }
			 }
		 }
	 }
	 for(int l=0;l<3;l++){//check sub_grid
		 for(int r=0;r<3;r++){
			 for(int i=0;i<3;i++){
				 bool grid[9]={false};
				 for(int j=0;j<3;j++){
					 if(map[j+3*r][i+3*l]!=0){
						 if(grid[map[j+3*r][i+3*l]-1]==false){
						 grid[map[j+3*r][i+3*l]-1]=true;
					 }else{
						 unsolvable=true;
						 return false;
					 }
					 }
				 }
			 }
		 }
	 }
	return true;
}
int Sudoku::find_sub_grid(int x,int y){
 return (x/3)+3*(y/3);
}