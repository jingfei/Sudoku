#include"Sudoku.h" 

Sudoku::Sudoku()
{
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
			map[i][j]=0;
}

void Sudoku::GiveQuestion()
{
	srand(time(NULL));
	int r=rand()%10+0;
	if(r==1) cout<<"0 0 0 0 1 0 8 7 0 0 2 0 0 9 0 0 0 0 0 0 0 5 0 0 0 0 0 2 0 0 0 6 8 0 9 0 0 0 8 0 7 0 3 0 0 0 9 7 0 0 0 0 0 0 0 0 0 0 0 4 6 3 0 0 8 0 0 5 0 0 0 0 0 7 1 3 0 0 9 0 0 "<<endl;
	if(r==2) cout<<"0 0 1 4 3 0 0 8 9 0 0 0 0 0 0 1 0 0 0 0 4 0 0 1 0 0 0 5 0 0 0 0 0 0 0 0 0 2 0 8 6 7 0 0 0 0 6 0 0 9 0 0 0 0 0 0 3 0 0 0 2 0 0 0 0 0 0 0 0 7 1 0 8 0 5 0 4 0 0 3 0 "<<endl;
	if(r==3) cout<<"5 0 8 0 0 0 0 0 0 0 6 0 0 0 0 0 0 0 0 1 0 6 0 0 0 2 4 2 8 0 5 0 0 9 0 3 0 0 9 0 0 4 5 7 0 6 0 0 0 0 0 8 0 0 0 0 0 9 0 6 0 0 0 0 0 0 0 4 0 7 3 0 0 0 0 0 1 0 0 0 0 "<<endl;
	if(r==4) cout<<"0 4 0 1 0 0 0 0 7 6 0 0 0 4 0 0 0 0 7 3 0 0 0 0 2 0 0 0 0 0 0 0 0 8 0 0 0 0 0 5 3 9 0 0 0 2 6 5 0 7 0 0 0 0 0 0 0 0 0 2 5 0 0 0 0 0 4 8 0 0 0 1 0 0 7 0 0 0 6 3 0 "<<endl;
	if(r==5) cout<<"0 1 0 0 0 0 0 0 8 0 0 7 0 3 0 4 5 0 9 0 2 0 0 7 0 0 6 0 0 3 0 5 0 0 0 7 5 0 0 9 0 0 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 4 0 5 2 0 0 7 0 0 0 0 2 3 0 0 0 0 0 0 6 0 0 1 0 "<<endl;
	if(r==6) cout<<"5 0 3 0 0 0 0 9 0 0 6 0 0 7 0 0 2 0 0 0 0 0 0 0 5 0 0 0 2 0 0 0 0 0 0 4 0 1 0 2 5 0 8 0 0 8 0 0 0 0 0 0 6 0 9 0 4 0 6 0 3 0 0 0 0 0 9 0 1 0 0 0 1 0 0 7 0 0 0 8 0 "<<endl;
	if(r==7) cout<<"4 0 3 0 0 8 0 0 0 0 0 0 0 0 0 0 5 0 0 0 0 0 6 0 2 0 0 7 0 5 0 0 0 0 0 1 0 0 0 0 8 0 0 0 0 0 0 0 9 4 0 3 2 0 6 0 1 0 0 0 0 9 0 0 0 0 6 0 3 0 0 0 0 0 7 8 2 0 0 0 0 "<<endl;
	if(r==8) cout<<"0 0 5 1 0 0 0 8 9 0 0 0 0 0 8 0 0 0 0 1 0 6 5 0 0 0 0 0 0 2 0 7 0 0 0 3 5 0 0 0 6 0 0 0 0 6 9 0 5 0 0 0 0 0 0 0 0 0 3 4 7 0 0 0 8 0 2 0 0 3 0 0 0 0 0 0 0 0 4 0 0 "<<endl;
	if(r==9) cout<<"0 2 3 0 0 0 0 0 9 6 0 4 0 8 0 5 0 0 0 0 0 0 0 0 2 0 0 0 0 0 0 0 6 8 0 0 0 0 0 0 2 0 9 0 1 3 0 9 0 4 1 0 0 0 0 1 0 0 0 0 0 0 0 0 0 0 5 0 0 0 0 7 0 0 8 0 1 4 0 6 0 "<<endl;
	if(r==0) cout<<"0 0 2 3 0 0 0 0 9 0 0 8 0 5 0 4 0 0 0 0 0 0 6 9 1 3 0 0 5 0 0 0 0 0 0 7 0 4 0 0 9 0 0 5 0 0 0 3 0 0 0 0 0 0 0 0 0 9 7 0 0 6 0 0 0 0 0 1 2 0 0 3 7 0 0 0 3 0 0 2 0 "<<endl;
}
void Sudoku::ReadIn()
{
	int n;
	for(int i=0;i<9;i++)
		for(int j=0;j<9;j++)
		{
			cin>>n;
			map[i][j]=n;
		} 
}
void Sudoku::Solve()
{
	memset(bx,0,sizeof(bx));
	memset(by,0,sizeof(by));
	memset(bz,0,sizeof(bz));
	solution=0;
	for(int x=0;x<9;x++)
		for(int y=0;y<9;y++)
		{
			if(map[x][y])
			{
				int n=map[x][y];
				bx[x][n]=by[y][n]=bz[x/3][y/3][n]=true;
			}
			answer[x][y]=map[x][y];
		} 
	backtrack(0,0);
	if(solution==0)
		cout<<0<<endl;
	else if(solution>1)
		cout<<2<<endl;
	else
	{
		cout<<1<<endl;
		for(int i=0;i<9;i++)
		{
			for(int j=0;j<9;j++)
				cout<<real_answer[i][j]<<" ";
			cout<<endl;
		}
	}
	
}
void Sudoku::backtrack(int x,int y)
{
	if(y==9)
	{
		x++;
		y=0;
	}
	if(x==9)
	{
		solution++;
		if(solution>1) return;
		
		for(int i=0;i<9;i++)
			for(int j=0;j<9;j++)
				real_answer[i][j]=answer[i][j];
		return;
	}
	if(map[x][y])
	{
		backtrack(x,y+1);
		return;
	}
	for(int n=1;n<=9;n++)
	{
		if(solution>1) break;
		if(!bx[x][n]&&!by[y][n]&&!bz[x/3][y/3][n])
		{
			bx[x][n]=by[y][n]=bz[x/3][y/3][n]=true;
			answer[x][y]=n;
			backtrack(x,y+1);
			
			bx[x][n]=by[y][n]=bz[x/3][y/3][n]=false;
		}
	}
	return;
}
