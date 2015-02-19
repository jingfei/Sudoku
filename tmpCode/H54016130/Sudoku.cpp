#include"Sudoku.h"

Sudoku::Sudoku()
{
	srand(time(NULL));
	num_ans=0;
	for(int i=1;i<=rangesize;i++)
		for(int j=1;j<=rangesize;j++)
			for(int k=1;k<=rangesize;k++)
				for(int l=1;l<=rangesize;l++)
					map[i][j][k][l]=0;
}
void Sudoku::setMap(const int set_map[])
{
	for(int i=1;i<=rangesize;i++)
		for(int j=1;j<=rangesize;j++)
			for(int k=1;k<=rangesize;k++)
				for(int l=1;l<=rangesize;l++)
					map[i][j][k][l]=set_map[(i-1)*27+(j-1)*9+(k-1)*3+(l-1)];
}
void Sudoku::transin()
{
	for(int i=1;i<=rangesize;i++)
		for(int j=1;j<=rangesize;j++)
			for(int k=1;k<=rangesize;k++)
				for(int l=1;l<=rangesize;l++)
					tempans[i][j][k][l]=map[i][j][k][l];
}
void Sudoku::transout()
{
	for(int i=1;i<=rangesize;i++)
		for(int j=1;j<=rangesize;j++)
			for(int k=1;k<=rangesize;k++)
				for(int l=1;l<=rangesize;l++)
					map[i][j][k][l]=tempans[i][j][k][l];	
}
void Sudoku::getMap()
{
	for(int i=1;i<=rangesize;i++)
		for(int j=1;j<=rangesize;j++)
		{
			for(int k=1;k<=rangesize;k++)
				for(int l=1;l<=rangesize;l++)
					cout<<map[i][j][k][l]<<" ";
			cout<<endl;
		}
}
void Sudoku::dfs()
{
	bool find=false;
	for(int i=1; i<=rangesize && !find; ++i)
	{//cout<<"fori"<<i<<endl;
		for(int j=1; j<=rangesize && !find; ++j)
		{//cout<<"-forj"<<j<<endl;
			for(int k=1; k<=rangesize && !find; ++k)
			{//cout<<"--fork"<<k<<endl;
				for(int l=1; l<=rangesize && !find; ++l)
				{//cout<<"---forl"<<l<<endl;
					if(!map[i][j][k][l])
					{
						find=true;
						for(int o=1; o<=rangesize*rangesize && num_ans<2/*!fin*/; ++o)
						{//cout<<"----foro"<<o<<endl;
							map[i][j][k][l]=o;
							if(check(i, j, k, l))
								dfs();
							if(!fin)
								map[i][j][k][l]=0;
						}
					}
				}
			}
		}
	}
	if(!find)
	{
		num_ans++;
		if(num_ans<2)
			transin();
		else
			fin=true;
	}
}
void Sudoku::dig()
{
	int temp,tem,space;
	bool pos[81];
	srand(time(NULL));
	for(int i=0;i<81;i++)
		pos[i]=false;
	for(int i=0;i<20;)
	{
		num_ans=0;
		temp=0;
		fin=false;
		space=rand()%81;
		while(pos[space])
		{
			space=rand()%81;
		}
		temp=map[space/27+1][(space%27)/9+1][(space%27%9)/3+1][space%27%9%3];
		map[space/27+1][(space%27)/9+1][(space%27%9)/3+1][space%27%9%3]=0;
		transin();
		dfs();
		transout();
		if(num_ans==1)
		{
			pos[space]=true;
			//transout();
			i++;
		}
		//transout();
		else
			map[space/27+1][(space%27)/9+1][(space%27%9)/3+1][space%27%9%3]=temp;
	}
	num_ans=0;
}
void Sudoku::GiveQuestion()
{
	bool used[9];
	srand(time(NULL));
	for(int i=0;i<9;i++)
		used[i]=false;
	for(int j=1;j<=rangesize;j++)
	{
		for(int l=1;l<=rangesize;l++)
		{
			map[1][j][1][l]=rand()%9+1;
			while(used[map[1][j][1][l]-1])
			{
				map[1][j][1][l]=rand()%9+1;
			}
			used[map[1][j][1][l]-1]=true;
		}
	}
	for(int l=1;l<=rangesize;l++)
	{
		for(int j=1;j<=rangesize;j++)
		{
			map[2][j][1][l]=map[1][j][1][l%rangesize+1];
			map[3][j][1][l]=map[1][j][1][l-1+((l-1)!=0?0:3)];
		}
	}
	for(int i=1;i<=rangesize;i++)
	{
		for(int j=1;j<=rangesize;j++)
		{
			for(int l=1;l<=rangesize;l++)
			{
				map[i][j][2][l]=map[i][j%3+1][1][l];
				map[i][j][3][l]=map[i][j-1+((j-1)!=0?0:3)][1][l];
			}
		}
	}
	//cout<<endl;
	dig();
	getMap();
}
void Sudoku::ReadIn()
{
	int readin[81];
	for(int i=0;i<81;i++)
		cin>>readin[i];
	setMap(readin);
}
void Sudoku::Solve()
{
	//Clock clk;
	//clk.start();
	bool find;
	find=false, fin=false;
	for(int i=1; i<=rangesize && !find; ++i)
	{
		//cout<<"fori"<<i<<endl;
		for(int j=1; j<=rangesize && !find; ++j)
		{
			//cout<<"-forj"<<j<<endl;
			for(int k=1; k<=rangesize && !find; ++k)
			{
				//cout<<"--fork"<<k<<endl;
				for(int l=1; l<=rangesize && !find; ++l)
				{
					//cout<<"---forl"<<l<<endl;
					if(!map[i][k][j][l])
					{
						find=true;
						for(int o=1; o<=rangesize*rangesize && num_ans<2/*!fin*/; ++o)
						{
							//cout<<"----foro"<<o<<endl;
							map[i][j][k][l]=o;
							if(check(i, j, k, j))
								dfs();
						}
					}
				}
			}
		}
	}
	if(!num_ans)//fin)
		cout<<num_ans<<endl;
	else
	{
		if(num_ans<2)
		{
			cout<<num_ans<<endl;
			transout();
			getMap();
		}
		else
			cout<<"2"<<endl;
	}
	//cout<<clk.getElapsedTime()<<"seconds"<<endl;
}
bool Sudoku::check(int y1,int y2,int x1,int x2)
{
	bool used[10];
	for(int i=0;i<10;i++)
		used[i]=false;
	for(int j=1;j<=rangesize;j++)//square check
		for(int l=1;l<=rangesize;l++)
			if(map[y1][j][x1][l])
			{
				if(used[map[y1][j][x1][l]]) return false;
				else used[map[y1][j][x1][l]]=true;
			}
	for(int i=0;i<10;i++)
		used[i]=false;
	for(int k=1;k<=rangesize;k++)//row check
		for(int l=1;l<=rangesize;l++)
			if(map[y1][y2][k][l])
			{
				if(used[map[y1][y2][k][l]]) return false;
				else used[map[y1][y2][k][l]]=true;
			}
	for(int i=0;i<10;i++)
		used[i]=false;
	for(int i=1;i<=rangesize;i++)//column check
		for(int j=1;j<=rangesize;j++)
			if(map[i][j][x1][x2])
			{
				if(used[map[i][j][x1][x2]]) return false;
				else used[map[i][j][x1][x2]]=true;
			}
	return true;
}
