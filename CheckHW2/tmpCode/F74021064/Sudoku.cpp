using namespace std;
#include"Sudoku.h"
void Sudoku::GiveQuestion()
{

}
void Sudoku::initSudoku()
{
	for(k1=0;k1<9;k1++)
    {
        for(k2=0;k2<9;k2++)
        {
            SudokuBlock[k1][k2]=0;
        }
    }
}
int Sudoku::ReadIn()
{
	initSudoku();
	ifstream inFile("question.txt", ios::in);
	for(k1=0;k1<9;k1++)
    {
        for(k2=0;k2<9;k2++)
        {
            inFile>>SudokuBlock[k1][k2];
        }
    }
}
void Sudoku::Solve()
{
    for(k1=0;k1<9;k1++)
    {
        for(k2=0;k2<9;k2++)
        {
            cout<<SudokuBlock[k1][k2]<<" ";
        }
	cout<<endl;
    }

}
int Sudoku::row(int kc1)
{
    if(cache==0) return 1;
    for(kc2=0;kc2<9;kc2++)
        if(cache==SudokuBlock[kc1][kc2])return 0;
    return 1;
}
int Sudoku::column(int kc2)
{
    if(cache==0) return 1;
    for(kc1=0;kc1<9;kc1++)
        if(cache==SudokuBlock[kc1][kc2])return 0;
    return 1;
}
int Sudoku::block(int kc1,int kc2)
{
    if(cache==0) return 1;
    if(kc1<3) kc1=0;
    else if(kc1<6) kc1=3;
    else kc1=6;
    if(kc2<3) kc2=0;
    else if(kc2<6) kc2=3;
    else kc2=6;
    for(block1=kc1;block1<(kc1+3);block1++)
    for(block2=kc2;block2<(kc2+3);block2++)
    if(cache==SudokuBlock[block1][block2]) return 0;
    return 1;
}
