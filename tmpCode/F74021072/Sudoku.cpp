#include"Sudoku.h"
void Sudoku::GiveQuestion()
{
	ifstream fin("lib",ios::in);
	srand(time(NULL));
	question=rand()%5+1;
	for(loop=0;loop<question;loop++)
	{
		getline(fin,line);
	}
	for(loop=0;loop<9;loop++)
	{
		for(temp_loop=0;temp_loop<9;temp_loop++)
		{
			cout<<line[(loop*9)+temp_loop]<<" ";
		}
		cout<<endl;
	}
}
void Sudoku::ReadIn()
{
	map=(int*)malloc(81*sizeof(int));
	for(loop=0;loop<9;loop++)
	{
		for(temp_loop=0;temp_loop<9;temp_loop++)
		{
			cin>>map[(loop*9)+temp_loop]; 
		}	
	}
}
void Sudoku::Solve()
{
	for(loop=0;loop<9;loop++)
	{
		for(temp_loop=0;temp_loop<9;temp_loop++)
		{
			new_map[loop][temp_loop]=map[loop*9+temp_loop];
		}
	}
	find_insert();
	print_result();
}
void Sudoku::find_insert()
{
	for(loop=0;loop<9;loop++)
	{
		for(temp_loop=0;temp_loop<9;temp_loop++)
		{
			if(new_map[loop][temp_loop]==0)
			{
				for(num=1;num<=9;num++)
				{
					if(rule(num,loop,temp_loop)==true)
					{
						new_map[loop][temp_loop]=num;
						find_insert();
						new_map[loop][temp_loop]=0;
					}
				}
			}
		}
	}
		return;
}
bool Sudoku::rule(int num,int loop,int temp_loop)
{
	for(i=0;i<9;i++)
	{
		if(new_map[loop][i]==num) return false;
	}
	for(i=0;i<9;i++)
	{
		if(new_map[i][temp_loop]==num) return false;
	}
	if(((loop+1)%3)!=0) remainder_row=1;
	else remainder_row=0;
	if(((temp_loop+1)%3)!=0) remainder_cl=1;
	else remainder_cl=0;
	square_start_row=((loop+1)/3+remainder_row)*3;
	square_start_cl=((temp_loop+1)/3+remainder_cl)*3;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			if(new_map[square_start_row-i-1][square_start_cl-j-1]==num)
			{
				return false;
			} 
		} 
	}
	return true;	
}
void Sudoku::print_result()
{
	cout<<"1"<<endl;
		for(loop=0;loop<9;loop++)
	{
		for(temp_loop=0;temp_loop<9;temp_loop++)
		{
			cout<<new_map[loop][temp_loop]<<" ";
		}
		cout<<endl;
	}
}