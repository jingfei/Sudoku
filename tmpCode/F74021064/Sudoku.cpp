#include"Sudoku.h"
void Sudoku::GiveQuestion()
{
    getNumber();
    getQuestion();
}
void Sudoku::getNumber()
{
    srand((unsigned)time(NULL));
    question_number=1/*rand()%1*/;

}
void Sudoku::getQuestion()
{
    if(question_number==0)
    {
        cout<<"0 0 0 0 0 0 0 0 0"<<endl;
        cout<<"0 0 0 0 0 0 0 0 0"<<endl;
        cout<<"0 0 0 0 0 0 1 0 0"<<endl;
        cout<<"0 0 0 0 0 0 0 1 0"<<endl;
        cout<<"0 0 0 0 0 0 0 0 0"<<endl;
        cout<<"0 0 0 0 0 0 0 0 0"<<endl;
        cout<<"1 0 0 0 0 0 0 0 0"<<endl;
        cout<<"0 0 0 1 0 0 0 0 0"<<endl;
        cout<<"0 0 0 0 0 0 0 0 2"<<endl;
    }
    if(question_number==1)
    {
        cout<<"0 0 0 0 0 0 0 1 0"<<endl;
        cout<<"4 0 0 0 0 0 0 0 0"<<endl;
        cout<<"0 2 0 0 0 0 0 0 0"<<endl;
        cout<<"0 0 0 0 5 0 4 0 7"<<endl;
        cout<<"0 0 8 0 0 0 3 0 0"<<endl;
        cout<<"0 0 1 0 9 0 0 0 0"<<endl;
        cout<<"3 0 0 4 0 0 2 0 0"<<endl;
        cout<<"0 5 0 1 0 0 0 0 0"<<endl;
        cout<<"0 0 0 8 0 6 0 0 0"<<endl;
    }
    if(question_number==2)
    {
        cout<<"0 0 8 4 0 0 0 0 0"<<endl;
        cout<<"0 1 0 0 6 0 0 0 0"<<endl;
        cout<<"0 6 0 0 0 5 3 8 0"<<endl;
        cout<<"5 0 0 9 0 0 0 0 2"<<endl;
        cout<<"9 0 0 0 0 0 0 0 7"<<endl;
        cout<<"6 0 0 0 0 7 0 0 1"<<endl;
        cout<<"0 9 4 1 0 0 0 2 0"<<endl;
        cout<<"0 0 0 0 3 0 0 4 0"<<endl;
        cout<<"0 0 0 0 0 8 1 0 0"<<endl;
    }
    if(question_number==3)
    {
        cout<<"0 0 0 0 0 0 0 0 2"<<endl;
        cout<<"0 5 6 0 0 0 1 0 0"<<endl;
        cout<<"0 0 0 0 3 4 0 0 0"<<endl;
        cout<<"0 2 0 1 0 0 0 0 6"<<endl;
        cout<<"0 8 0 0 0 0 0 7 0"<<endl;
        cout<<"7 0 0 0 0 9 0 3 0"<<endl;
        cout<<"0 0 0 2 8 0 0 0 0"<<endl;
        cout<<"0 0 9 0 0 0 5 4 0"<<endl;
        cout<<"3 0 0 0 0 0 0 0 0"<<endl;
    }
    if(question_number==4)
    {
        cout<<"8 0 0 4 0 9 0 0 2"<<endl;
        cout<<"3 0 0 0 0 0 0 0 5"<<endl;
        cout<<"0 5 0 0 0 0 0 4 0"<<endl;
        cout<<"0 0 4 6 0 3 9 0 0"<<endl;
        cout<<"0 0 0 0 0 0 0 0 0"<<endl;
        cout<<"0 0 6 2 0 7 5 0 0"<<endl;
        cout<<"0 3 0 0 0 0 0 1 0"<<endl;
        cout<<"9 0 0 0 0 0 0 0 8"<<endl;
        cout<<"4 0 0 1 0 5 0 0 7"<<endl;
    }
    if(question_number==5)
    {
        cout<<"0 0 8 0 3 0 0 2 0"<<endl;
        cout<<"7 0 0 1 0 0 3 0 0"<<endl;
        cout<<"0 1 0 0 0 5 0 0 0"<<endl;
        cout<<"0 0 2 0 8 0 0 0 6"<<endl;
        cout<<"0 0 0 3 0 9 0 0 0"<<endl;
        cout<<"6 0 0 0 5 0 9 0 0"<<endl;
        cout<<"0 0 0 4 0 0 0 7 0"<<endl;
        cout<<"0 0 1 0 0 7 0 0 4"<<endl;
        cout<<"0 6 0 0 1 0 2 0 0"<<endl;
    }
    if(question_number==6)
    {
        cout<<"0 0 0 0 0 0 0 0 7"<<endl;
        cout<<"0 0 1 0 0 2 0 5 0"<<endl;
        cout<<"0 8 0 9 3 0 0 0 0"<<endl;
        cout<<"0 0 5 0 0 4 0 0 0"<<endl;
        cout<<"0 0 3 0 0 0 8 0 0"<<endl;
        cout<<"0 0 0 7 0 0 6 0 0"<<endl;
        cout<<"0 0 0 0 4 1 0 3 0"<<endl;
        cout<<"0 6 0 8 0 0 9 0 0"<<endl;
        cout<<"7 0 0 0 0 0 0 0 0"<<endl;
    }
    if(question_number==7)
    {
        cout<<"0 0 1 0 6 0 0 8 0"<<endl;
        cout<<"0 8 0 0 0 5 0 0 7"<<endl;
        cout<<"5 0 0 4 0 0 2 0 0"<<endl;
        cout<<"0 0 4 0 0 0 0 1 0"<<endl;
        cout<<"8 0 0 0 0 0 0 0 3"<<endl;
        cout<<"0 2 0 0 0 0 6 0 0"<<endl;
        cout<<"0 0 5 0 0 3 0 0 2"<<endl;
        cout<<"7 0 0 9 0 0 0 6 0"<<endl;
        cout<<"0 3 0 0 1 0 5 0 0"<<endl;
    }
    if(question_number==8)
    {
        cout<<"0 4 8 0 0 0 3 0 0"<<endl;
        cout<<"1 0 0 9 0 7 0 0 0"<<endl;
        cout<<"3 0 0 0 0 4 0 0 6"<<endl;
        cout<<"0 8 0 0 0 0 2 9 0"<<endl;
        cout<<"0 0 0 0 0 0 0 0 0"<<endl;
        cout<<"0 7 1 0 0 0 0 4 0"<<endl;
        cout<<"8 0 0 5 0 0 0 0 9"<<endl;
        cout<<"0 0 0 1 0 2 0 0 5"<<endl;
        cout<<"0 0 4 0 0 0 7 6 0"<<endl;
    }
    if(question_number==9)
    {
        cout<<"0 0 7 0 0 0 0 9 1"<<endl;
        cout<<"5 3 0 0 0 7 8 0 0"<<endl;
        cout<<"0 0 0 0 6 0 0 0 0"<<endl;
        cout<<"7 2 0 0 0 0 0 0 0"<<endl;
        cout<<"0 0 4 1 0 2 3 0 0"<<endl;
        cout<<"0 0 0 0 0 0 0 6 8"<<endl;
        cout<<"0 0 0 0 3 0 0 0 0"<<endl;
        cout<<"0 0 2 9 0 0 0 8 7"<<endl;
        cout<<"1 5 0 0 0 0 4 0 0"<<endl;
    }
    if(question_number==10)
    {
        cout<<"0 5 0 0 0 0 7 0 0"<<endl;
        cout<<"0 0 4 0 0 0 0 0 8"<<endl;
        cout<<"8 0 3 0 5 1 0 0 0"<<endl;
        cout<<"0 3 0 0 0 7 0 0 5"<<endl;
        cout<<"0 0 0 5 9 2 0 0 0"<<endl;
        cout<<"6 0 0 4 0 0 0 2 0"<<endl;
        cout<<"0 0 0 1 7 0 4 0 2"<<endl;
        cout<<"4 0 0 0 0 0 6 0 0"<<endl;
        cout<<"0 0 6 0 0 0 0 9 0"<<endl;
    }
    if(question_number==11)
    {
        cout<<"0 0 0 0 3 7 0 0 0"<<endl;
        cout<<"0 0 3 9 0 0 0 0 0"<<endl;
        cout<<"0 0 4 5 0 0 2 6 0"<<endl;
        cout<<"6 0 0 0 0 0 5 4 0"<<endl;
        cout<<"5 0 0 0 0 0 0 0 2"<<endl;
        cout<<"0 3 1 0 0 0 0 0 7"<<endl;
        cout<<"0 5 9 0 0 3 8 0 0"<<endl;
        cout<<"0 0 0 0 0 6 7 0 0"<<endl;
        cout<<"0 0 0 2 1 0 0 0 0"<<endl;
    }
    if(question_number==12)
    {
        cout<<"0 0 1 0 0 4 0 0 9"<<endl;
        cout<<"8 0 0 9 0 0 7 0 0"<<endl;
        cout<<"0 2 0 0 6 0 0 5 0"<<endl;
        cout<<"0 0 3 0 0 0 0 0 1"<<endl;
        cout<<"0 0 6 0 9 0 0 0 0"<<endl;
        cout<<"5 0 0 0 0 0 3 0 0"<<endl;
        cout<<"0 8 0 0 2 0 0 4 0"<<endl;
        cout<<"0 0 2 0 0 8 0 0 6"<<endl;
        cout<<"3 0 0 4 0 0 5 0 0"<<endl;
    }
    if(question_number==13)
    {
        cout<<"3 2 0 0 0 0 0 0 0"<<endl;
        cout<<"0 0 5 8 0 0 0 7 0"<<endl;
        cout<<"0 0 0 0 0 9 2 0 0"<<endl;
        cout<<"0 0 0 4 7 0 0 3 8"<<endl;
        cout<<"0 0 8 0 0 0 1 0 0"<<endl;
        cout<<"5 9 0 0 2 8 0 0 0"<<endl;
        cout<<"0 0 7 2 0 0 0 0 0"<<endl;
        cout<<"0 1 0 0 0 6 3 0 0"<<endl;
        cout<<"0 0 0 0 0 0 0 8 1"<<endl;
    }
    if(question_number==14)
    {
        cout<<"8 0 0 5 0 0 0 0 3"<<endl;
        cout<<"2 0 0 6 0 7 0 0 8"<<endl;
        cout<<"0 1 0 0 0 4 0 0 0"<<endl;
        cout<<"0 9 0 0 0 0 6 0 0"<<endl;
        cout<<"0 0 8 0 0 0 1 0 0"<<endl;
        cout<<"0 0 4 0 0 0 0 9 0"<<endl;
        cout<<"0 0 0 8 0 0 0 5 0"<<endl;
        cout<<"4 0 0 7 0 9 0 0 2"<<endl;
        cout<<"7 0 0 0 0 1 0 0 6"<<endl;
    }
    if(question_number==15)
    {
        cout<<"0 0 0 0 9 0 0 7 0"<<endl;
        cout<<"0 0 0 0 6 0 0 9 0"<<endl;
        cout<<"0 8 7 0 0 3 4 0 0"<<endl;
        cout<<"2 0 0 7 0 0 0 0 0"<<endl;
        cout<<"6 0 0 1 0 9 0 0 5"<<endl;
        cout<<"0 0 0 0 0 5 0 0 8"<<endl;
        cout<<"0 0 9 5 0 0 3 4 0"<<endl;
        cout<<"0 4 0 0 8 0 0 0 0"<<endl;
        cout<<"0 2 0 0 1 0 0 0 0"<<endl;
    }
    if(question_number==16)
    {
        cout<<"0 9 0 0 5 0 0 0 0"<<endl;
        cout<<"0 0 0 0 0 4 0 0 2"<<endl;
        cout<<"6 0 0 0 0 0 3 0 0"<<endl;
        cout<<"0 0 2 0 0 9 0 0 0"<<endl;
        cout<<"1 3 0 0 0 0 0 5 6"<<endl;
        cout<<"0 0 0 8 0 0 7 0 0"<<endl;
        cout<<"0 0 8 0 0 0 0 0 4"<<endl;
        cout<<"7 0 0 1 0 0 0 0 0"<<endl;
        cout<<"0 0 0 0 3 0 0 9 0"<<endl;
    }
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
void Sudoku::ReadIn()
{
	initSudoku();
	for(k1=0;k1<9;k1++)
    {
        for(k2=0;k2<9;k2++)
        {
            cin>>t;
            if(t>'9'||t<'0') {cout<<0; return;}
            SudokuBlock[k1][k2]=t-'0';
        }
    }
}
void Sudoku::Solve()
{
    for(ca1=0;ca1<9;ca1++)
        for(ca2=0;ca2<9;ca2++)
        Sudokuco[ca1][ca2]=SudokuBlock[ca1][ca2];
         element();
         judge=0;
         looplocate=0;
        solornot=SolveSudoku(0,0);
        if(judge<2)cout<<judge<<endl;
		else cout<<"2"<<endl;
        if(judge==1)
        {
            for(k1=0;k1<9;k1++)
    {
        for(k2=0;k2<9;k2++)
        {
            cout<<Sudokufinal[k1][k2]<<" ";
        }
	cout<<endl;
    }
        }
}
int Sudoku::SolveSudoku(int a,int b)
{
    int c,d,e;
    if(a==9)
    {
        for(k1=0;k1<9;k1++)
            for(k2<0;k2<9;k2++)
            if(Sudokuco[k1][k2]==0) return 0;
        {
            judge++;
            if(judge>1) return 2;
            for(kc1=0;kc1<9;kc1++)
                for(kc2=0;kc2<9;kc2++)
            {
                Sudokufinal[kc1][kc2]=SudokuBlock[kc1][kc2];
            }
        }
    }
    else
    {
         if(b<8)
            {
            c=a;
            d=b+1;
            }
            else
            {
            c=a+1;
            d=0;
            }
        if(Sudokuco[a][b]==0)
        {
            for(e=0;e<9;e++)
            {
            if(SudokuBB[a][b].at(e)!=0)
            {
            cache=SudokuBB[a][b].at(e);
            if(row(a))
            {
                if(column(b))
            {
                    if(block(a,b))
            {

                Sudokuco[a][b]=SudokuBB[a][b].at(e);
                SudokuBlock[a][b]=SudokuBB[a][b].at(e);
                SolveSudoku(c,d);

            }
            }

            }
            }
            Sudokuco[a][b]=0;
            SudokuBlock[a][b]=0;
            }
        }
        else
        {
            SolveSudoku(c,d);
        }
    }
}
void Sudoku::element()
{
    for(k1=0;k1<9;k1++)
        for(k2=0;k2<9;k2++)
        {
            if(SudokuBlock[k1][k2]!=0)
                for(kc1=0;kc1<9;kc1++)
            SudokuBB[k1][k2].push_back(0);
            else
            for(kc1=0;kc1<9;kc1++)
            SudokuBB[k1][k2].push_back(kc1+1);
        }
    for(k1=0;k1<9;k1++)
        for(k2=0;k2<9;k2++)
        for(kc1=0;kc1<9;kc1++)
        {
        if(SudokuBlock[k1][k2]!=0)
        {
            for(l1=0;l1<9;l1++) SudokuBB[l1][k2].at(SudokuBlock[k1][k2]-1)=0;
            for(l2=0;l2<9;l2++) SudokuBB[k1][l2].at(SudokuBlock[k1][k2]-1)=0;
            if(k1>2){
            if(k1>5) ca1=6;
            else ca1=3;}
            else ca1=0;
            if(k2>2){
            if(k2>5) ca2=6;
            else ca2=3;}
            else ca2=0;
            for(l1=ca1;l1<ca1+3;l1++)
            for(l2=ca2;l2<ca2+3;l2++)
            SudokuBB[l1][l2].at(SudokuBlock[k1][k2]-1)=0;
        }
        }
}
int Sudoku::row(int kc1)
{
    if(cache==0) return 1;
    for(kc2=0;kc2<9;kc2++)
        if(cache==SudokuBlock[kc1][kc2]){kc1=0;kc2=0; return 0;}
    return 1;
}
int Sudoku::column(int kc2)
{
    if(cache==0) return 1;
    for(kc1=0;kc1<9;kc1++)
        if(cache==SudokuBlock[kc1][kc2]){kc1=0;kc2=0; return 0;}
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
    if(cache==SudokuBlock[block1][block2]) {kc1=0;kc2=0; return 0;}
    return 1;
}
																																				