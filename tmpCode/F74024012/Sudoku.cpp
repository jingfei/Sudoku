#include"Sudoku.h"
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void Sudoku:: GiveQuestion()
{
srand(time(NULL));
			ran=(rand()%10)+1;
			if(ran==1)
			{
				cout<<"0"<<" "<<"8"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"6"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"5"<<" "<<"9"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"4"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"3"<<" "<<"7"<<" "<<"0"<<" "<<"0"<<" "<<"9"<<" "<<"1"<<endl;
				cout<<"0"<<" "<<"1"<<" "<<"0"<<" "<<"0"<<" "<<"3"<<" "<<"5"<<" "<<"9"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"3"<<" "<<"9"<<" "<<"6"<<" "<<"0"<<" "<<"0"<<" "<<"1"<<" "<<"0"<<endl;
				cout<<"1"<<" "<<"2"<<" "<<"0"<<" "<<"0"<<" "<<"8"<<" "<<"6"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"4"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"2"<<" "<<"8"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"3"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"5"<<" "<<"0"<<endl;
			}
			else if(ran==2)
			{
				cout<<"9"<<" "<<"0"<<" "<<"0"<<" "<<"4"<<" "<<"0"<<" "<<"1"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"5"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"7"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"2"<<" "<<"0"<<" "<<"0"<<" "<<"3"<<" "<<"9"<<endl;
				cout<<"0"<<" "<<"2"<<" "<<"0"<<" "<<"5"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"8"<<" "<<"7"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"8"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"3"<<" "<<"8"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"7"<<" "<<"0"<<" "<<"5"<<" "<<"0"<<endl;
				cout<<"8"<<" "<<"6"<<" "<<"0"<<" "<<"0"<<" "<<"9"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"9"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"1"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"1"<<" "<<"0"<<" "<<"3"<<" "<<"0"<<" "<<"0"<<" "<<"6"<<endl;
			}
			else if(ran==3)
			{
				cout<<"3"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"4"<<" "<<"0"<<" "<<"0"<<" "<<"7"<<" "<<"1"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"4"<<" "<<"6"<<" "<<"0"<<" "<<"7"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"5"<<" "<<"3"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"9"<<" "<<"0"<<" "<<"0"<<" "<<"8"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"6"<<" "<<"0"<<" "<<"7"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"8"<<" "<<"0"<<" "<<"2"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"3"<<" "<<"0"<<" "<<"0"<<" "<<"1"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"9"<<" "<<"4"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"2"<<" "<<"0"<<" "<<"4"<<" "<<"3"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"2"<<" "<<"8"<<" "<<"0"<<" "<<"0"<<" "<<"1"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"7"<<endl;
			}
			else if(ran==4)
			{
				cout<<"1"<<" "<<"4"<<" "<<"0"<<" "<<"8"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"7"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"2"<<" "<<"5"<<" "<<"0"<<" "<<"0"<<" "<<"1"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"7"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"4"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"6"<<" "<<"0"<<" "<<"7"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"6"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"5"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"4"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"4"<<" "<<"0"<<" "<<"1"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"5"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"2"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"3"<<" "<<"0"<<" "<<"0"<<" "<<"4"<<" "<<"8"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"8"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"9"<<" "<<"0"<<" "<<"1"<<" "<<"6"<<endl;
			}
			else if(ran==5)
			{
				cout<<"0"<<" "<<"4"<<" "<<"0"<<" "<<"3"<<" "<<"0"<<" "<<"8"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"5"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"4"<<" "<<"0"<<" "<<"0"<<" "<<"1"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"4"<<" "<<"9"<<endl;
				cout<<"7"<<" "<<"0"<<" "<<"9"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"2"<<" "<<"6"<<" "<<"0"<<" "<<"7"<<" "<<"0"<<" "<<"4"<<" "<<"5"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"7"<<" "<<"0"<<" "<<"8"<<endl;
				cout<<"2"<<" "<<"5"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"7"<<" "<<"0"<<" "<<"0"<<" "<<"8"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"4"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"1"<<" "<<"0"<<" "<<"3"<<" "<<"0"<<" "<<"6"<<" "<<"0"<<endl;
			}
			else if(ran==6)
			{
				cout<<"0"<<" "<<"2"<<" "<<"1"<<" "<<"0"<<" "<<"0"<<" "<<"9"<<" "<<"0"<<" "<<"4"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"1"<<" "<<"0"<<" "<<"5"<<" "<<"6"<<endl;
				cout<<"9"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"3"<<" "<<"7"<<" "<<"0"<<" "<<"0"<<" "<<"8"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"3"<<" "<<"0"<<" "<<"4"<<" "<<"0"<<" "<<"2"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"8"<<" "<<"0"<<" "<<"0"<<" "<<"9"<<" "<<"6"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"4"<<endl;
				cout<<"5"<<" "<<"7"<<" "<<"0"<<" "<<"8"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"6"<<" "<<"0"<<" "<<"3"<<" "<<"0"<<" "<<"0"<<" "<<"9"<<" "<<"7"<<" "<<"0"<<endl;
			}
			else if(ran==7)
			{
				cout<<"0"<<" "<<"0"<<" "<<"5"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"2"<<" "<<"3"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"2"<<" "<<"0"<<" "<<"3"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"7"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"8"<<" "<<"6"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"1"<<" "<<"3"<<" "<<"0"<<" "<<"9"<<" "<<"5"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"6"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"7"<<" "<<"3"<<" "<<"0"<<" "<<"2"<<" "<<"9"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"8"<<" "<<"7"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"6"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"1"<<" "<<"0"<<" "<<"5"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"9"<<" "<<"4"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"1"<<" "<<"0"<<" "<<"0"<<endl;
			}
			else if(ran==8)
			{
				cout<<"0"<<" "<<"0"<<" "<<"1"<<" "<<"8"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"7"<<" "<<"0"<<" "<<"5"<<" "<<"6"<<endl;
				cout<<"8"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"2"<<" "<<"9"<<" "<<"0"<<" "<<"1"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"6"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"9"<<" "<<"4"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"5"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"4"<<" "<<"8"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"6"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"7"<<" "<<"0"<<" "<<"2"<<" "<<"6"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"8"<<endl;
				cout<<"2"<<" "<<"4"<<" "<<"0"<<" "<<"1"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"3"<<" "<<"2"<<" "<<"0"<<" "<<"0"<<endl;
			}
			else if(ran==9)
			{
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"1"<<" "<<"0"<<" "<<"3"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"4"<<" "<<"0"<<" "<<"9"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"2"<<endl;
				cout<<"7"<<" "<<"0"<<" "<<"0"<<" "<<"6"<<" "<<"0"<<" "<<"5"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"2"<<" "<<"9"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"3"<<" "<<"4"<<" "<<"0"<<" "<<"0"<<" "<<"2"<<" "<<"0"<<" "<<"0"<<" "<<"7"<<" "<<"1"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"2"<<" "<<"8"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"9"<<" "<<"0"<<" "<<"6"<<" "<<"0"<<" "<<"0"<<" "<<"4"<<endl;
				cout<<"5"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"4"<<" "<<"0"<<" "<<"3"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"4"<<" "<<"0"<<" "<<"8"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
			}
			else
			{
				cout<<"1"<<" "<<"9"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"8"<<" "<<"0"<<" "<<"5"<<" "<<"3"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"4"<<" "<<"0"<<" "<<"0"<<" "<<"2"<<" "<<"9"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"5"<<" "<<"0"<<" "<<"0"<<" "<<"7"<<" "<<"9"<<endl;
				cout<<"4"<<" "<<"0"<<" "<<"0"<<" "<<"7"<<" "<<"0"<<" "<<"6"<<" "<<"0"<<" "<<"0"<<" "<<"3"<<endl;
				cout<<"6"<<" "<<"7"<<" "<<"0"<<" "<<"0"<<" "<<"3"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"5"<<" "<<"9"<<" "<<"0"<<" "<<"0"<<" "<<"8"<<" "<<"0"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"4"<<" "<<"1"<<" "<<"0"<<" "<<"6"<<endl;
				cout<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"0"<<" "<<"3"<<" "<<"7"<<endl;
			}

}
int Sudoku:: checkrow(int row,int num)
{
int column;
for(column=0;column<9;column++)
    if(sudoku[row][column]==num)
        return 0 ;
return 1;

}
int Sudoku::checkcolumn(int column,int num)
{
int row;
for(row=0;row<9;row++)
    if(sudoku[row][column]==num)
        return 0;
return 1;
}
int Sudoku::checkblock(int row,int column,int num)
{
row=(row/3)*3 ;
column=(column/3)*3;
int r,c;
for(r=0;r<3;r++)
    for(c=0;c<3;c++)
         if(sudoku[row+r][column+c]==num)
            return 0;
return 1;

}
void Sudoku::navigate(int row,int column)
{
if(column<8)
        solvesudoku(row,column+1);
    else
       solvesudoku(row+1,0);

}
void Sudoku::display()
{
int row,column;
count++;
for(row=0;row<9;row++)
{
for(column=0;column<9;column++)
a[row][column]=sudoku[row][column];
//cout<<count;
}


}
void Sudoku::solvesudoku(int row,int column)
{
if(row==9)
    display();
	if(sudoku[row][column]!=0)
    navigate(row,column);
    else
    {
        int ctr;
        for(ctr=1;ctr<=9;ctr++)
        {
        if((checkrow(row,ctr)==1)&&(checkcolumn(column,ctr)==1)&&(checkblock(row,column,ctr)==1))
        {
            sudoku[row][column]=ctr;
             navigate(row,column);
        }
        }
        sudoku[row][column]=0;
    }


}
void Sudoku::ReadIn()
{
int row,column;
		for(row=0;row<9;row++)
		for(column=0;column<9;column++)
		cin>>sudoku[row][column];
		//cout<<count;
		/*for(row=0;row<9;row++)
		for(column=0;column<9;column++)
		cout<<sudoku[row][column];*/


}
void Sudoku::Solve()
{
	count=0;
			solvesudoku(0,0);
			//cout<<count;
			if(count<9)
			{
				cout<<'0';
			}
			if(count==9)
			{
				cout<<'1'<<endl;
				for(int i=0;i<9;i++)
				{
					for(int j=0;j<9;j++)
					{
						cout<<a[i][j]<<" ";
					}
					cout<<endl;
				}
			}
			if(count>9)
			{
				cout<<'2';
			}



}



