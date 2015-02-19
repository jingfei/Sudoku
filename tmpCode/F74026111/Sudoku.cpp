#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct sudoku_table{
	char num;
	char possibility[10];
}sudoku[9][9], sudoku_ans[9][9];


struct position{
	int x;
	int y;
	position(int X, int Y):x(X), y(Y){}
};

void output_sudoku();
void read_sudoku();
int solve_sudoku();
void check_v(struct position pos);
void check_h(struct position pos);
struct position find_empty(struct position);
void check_square(struct position pos);
int stupid_mode();
int ai_mode();
int easy_mode();

void output_sudoku(){
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<8;j++){
			printf("%c ", sudoku_ans[i][j].num);
		}
		printf("%c\n", sudoku_ans[i][8].num);
	}
}

void read_sudoku(){
	int i=0;
	while(i<81){
		if(scanf("%c", &sudoku[0][i].num)==0) exit(EXIT_FAILURE);
		
		if(sudoku[0][i].num<'0'||sudoku[0][i].num>'9') continue;
		memset(&sudoku[0][i].possibility[0],1,10);
		i++;
	}
}

int stupid_mode(){
	int stupid_count=0;

	struct position pos(0,0);
	//Step 1: stupid mode
	pos=find_empty(pos);
	while(pos.x!=-1){
		//Step 1:
		check_h(pos);
		//Step 2:
		check_v(pos);
		//Step 3: check square
		check_square(pos);
		int i,count=0, last_ans;
		for(i=1;i<=9;i++){
			if(sudoku[pos.y][pos.x].possibility[i]){count++; last_ans=i;}
		}
		if(count==0) return -1;
		if(count==1){
			sudoku[pos.y][pos.x].num=last_ans+'0';
			stupid_count++;
		}

		pos.x++;
		pos=find_empty(pos);
	}

	return stupid_count;
}

int ai_mode()
{
    int i,j,k;
    int ai_mode_count=0;
    for(k=1; k<=9; k++)
    {
        for(i=0; i<9; i+=3)
        {
            for(j=0; j<9; j+=3)
            {
                //check for mini square
                int count=0;
                struct position last_ans(-1,-1);
                int x,y;
                for(x=0; x<3; x++)
                    for(y=0; y<3; y++)
                    {
			if(sudoku[y+i][x+j].num==k){
				count=0; x=3; break;
			}
                        if(sudoku[y+i][x+j].num=='0'&&sudoku[y+i][x+j].possibility[k])
                        {
                            count++;
                            last_ans.x=x;
                            last_ans.y=y;
                        }
                    }
                if(count==1)
                {
                    sudoku[last_ans.y+i][last_ans.x+j].num=k+'0';
                    ai_mode_count++;
                }
            }
        }
    }
    return ai_mode_count;
}

int easy_mode(){
	int a=1,b=0;
	while(a+b){
		while(a){a=stupid_mode(); if(a==-1) return 0;}
		while((b=ai_mode()));
	}
	return 1;
}

int solve_sudoku(){
	int count=0;
	if(!easy_mode()) return 0;
	struct sudoku_table sudoku_bk[9][9];
	memcpy(sudoku_bk, sudoku, sizeof(sudoku));
	
	struct position pos(0,0);
	pos=find_empty(pos);
	if(pos.x!=-1){
		int i;
		for(i=1;i<=9;i++){
			if(sudoku[pos.y][pos.x].possibility[i]){
				sudoku[pos.y][pos.x].num=i+'0';
				count+=solve_sudoku();
				if(count>=2) break;
				memcpy(sudoku,sudoku_bk, sizeof(sudoku));
			}
		}
	}else{
		memcpy(sudoku_ans, sudoku, sizeof(sudoku));
		return 1;
	}

	return count;

}


void check_square(struct position pos){
	//NOT NEED to Assume 1

	struct position pos_sq(0,0);
	if(pos.x>=3&&pos.x<=5) pos_sq.x=3;
	if(pos.x>=6) pos_sq.x=6;
	if(pos.y>=3&&pos.y<=5) pos_sq.y=3;
	if(pos.y>=6) pos_sq.y=6;

	int x,y;
	for(y=0;y<3;y++){
		for(x=0;x<3;x++){
			if((pos_sq.x+x)!=pos.x&&(pos_sq.y+y)!=pos.y){
				sudoku[pos.y][pos.x].possibility[sudoku[pos_sq.y+y][pos_sq.x+x].num-'0']=0;
			}
		}
	}
}

void check_h(struct position pos){
	//Assume 0 ...
	int j;
	for(j=0;j<9;j++){
		if(j!=pos.x)
			sudoku[pos.y][pos.x].possibility[sudoku[pos.y][j].num-'0']=0;
	}
}

void check_v(struct position pos){
	int i;
	for(i=0;i<9;i++){
		if(i!=pos.y)
			sudoku[pos.y][pos.x].possibility[sudoku[i][pos.x].num-'0']=0;
	}
}

struct position find_empty(struct position pos){
	struct position result(-1,-1);
	int i;
	for(i=pos.y*9+pos.x;i<81;i++){
		if(sudoku[0][i].num=='0') {
			result.x=i%9;
			result.y=i/9;
			return result;
		}
	}
	return result;
}
