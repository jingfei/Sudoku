#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include"Sudoku.h"
using namespace std;
Sudoku::Sudoku()
{
    int i;
    for(i=0;i<99;i++)
    spacenum[i]=-1;
}
void Sudoku::ReadIn()
{
    int i=0,j=0;
    for(j=1;j<=9;j++)
    {
        for(i=1;i<=9;i++)
        {
            Map[j][i]=0;
        }
    }
    for(j=1;j<=9;j++)
    {
        for(i=1;i<=9;i++)
        {
            cin>>Map[j][i];
        }
    }
}
int Sudoku::trackspace()
{
    int i=0,j=0,n=0;
    for(j=1;j<=9;j++)
    {
        for(i=1;i<=9;i++)
        {
            if(Map[j][i]==0)
            {
                spacenum[n]=i+j*10;
                n++;
            }
        }
    }
    return n;
}
int Sudoku::check_C_R_N(int N,int i,int j)
{
    int x=0,y=0,correct=0,T1=(2*i)/7,T2=(2*j)/7;
    for(y=1;y<=9;y++)//欄=x
    {
        if(N==Map[y][i])
        return -1;

        if(N!=Map[y][i])
        correct++;
    }
    for(x=1;x<=9;x++)//列=y
    {
        if(N==Map[j][x])
        return -1;

        if(N!=Map[j][x])
        correct++;
    }
    for(y=3*T2+1;y<(3*T2+4);y++)
    {
        for(x=3*T1+1;x<(3*T1+4);x++)
        {
            if(N==Map[y][x])
            return -1;

            if(N!=Map[y][x])
            correct++;
        }
    }
    if(correct==27)
    return 1;
}
void Sudoku::pri()
{
    int i=0,j=0;
    for(j=1;j<=9;j++)
    {
        for(i=1;i<=9;i++)
        {
            cout<<ANS[j][i]<<" ";
        }
        cout<<"\n"<<endl;
    }
}
void Sudoku::SolTWO(int n)
{
    int i=0,j=0,check_result=0,SP=0,T1=0,T2=0;
    SP=spacenum[n];
    T1=SP/10;
    T2=SP%10;
    if(SP==-1)
    {
        NOFANS++;
        for(int j=1;j<=9;j++)
        {
            for(int i=1;i<=9;i++)
            {
                ANS[j][i]=Map[j][i];
            }
        }
        return;
    }
    for(i=1;i<=9;i++)
    {
        check_result=check_C_R_N(i,T2,T1);
        if(check_result==1)//i符合規則 1==true -1==false
        {
            Map[T1][T2]=i;//將i填入空格
            SolTWO(n+1); // 遞迴下去填下個空格
            Map[T1][T2]=0;//將i從空格移除
        }
        if(NOFANS>2||NOFANS==2)
        break;
    }
}
void Sudoku::Solve()
{
    trackspace();
    NOFANS=0;
    SolTWO(0);
    if(NOFANS==0)
    cout<<"0\n";
    if(NOFANS==1)
    {
        cout<<"1\n";
        pri();
    }
    if(NOFANS>=2)
    cout<<"2";
}
void Sudoku::GiveQuestion()
{
    int N;
    srand(time(0));
    N=rand() % 4;


    if(N==0)
    {
        cout<<
        "0 0 0 8 0 0 0 5 0\n"<<
        "0 0 0 0 0 0 0 0 0\n"<<
        "9 0 0 0 6 0 1 0 0\n"<<
        "0 0 8 0 0 0 0 0 0\n"<<
        "0 4 0 0 0 0 0 0 9\n"<<
        "0 0 8 0 2 9 3 0 0\n"<<
        "0 2 0 0 0 0 0 8 4\n"<<
        "0 0 0 0 0 0 0 0 0\n"<<
        "1 0 5 0 0 3 0 0 0\n";
    }
    if(N==1)
    {
        cout<<
        "0 0 0 0 0 0 0 0 0\n"<<
        "8 0 0 2 0 0 0 0 1\n"<<
        "0 9 0 0 0 0 0 7 0\n"<<
        "0 0 0 0 0 7 0 0 0\n"<<
        "0 0 2 0 5 0 0 0 0\n"<<
        "4 0 0 0 0 0 2 0 6\n"<<
        "0 0 0 8 0 9 4 0 0\n"<<
        "0 5 7 0 6 0 0 0 0\n"<<
        "0 0 0 0 0 0 0 0 0\n";
    }
    if(N==2)
    {
        cout<<
        "0 0 0 8 0 0 0 5 0\n"<<
        "0 0 0 0 0 0 0 0 0\n"<<
        "9 0 0 0 6 0 1 0 0\n"<<
        "0 0 8 0 0 0 0 0 0\n"<<
        "0 4 0 0 0 0 0 0 9\n"<<
        "0 0 0 0 2 9 3 0 0\n"<<
        "0 2 0 0 0 0 0 8 4\n"<<
        "0 0 0 0 0 0 0 0 0\n"<<
        "1 0 5 0 0 3 0 0 0\n";
    }
    if(N==3)
    {
        cout<<
        "0 0 0 0 0 0 0 0 0\n"<<
        "0 0 1 0 0 4 0 8 0\n"<<
        "0 0 0 0 0 0 0 7 3\n"<<
        "0 0 0 0 3 0 0 0 0\n"<<
        "0 0 9 0 0 0 4 0 0\n"<<
        "0 0 8 6 0 0 0 0 2\n"<<
        "3 0 0 0 0 0 0 5 0\n"<<
        "2 0 0 0 0 0 0 0 0\n"<<
        "0 7 0 0 0 9 8 0 0\n";
    }
    if(N==4)
    {
        cout<<
        "0 0 0 0 0 1 0 0 0\n"<<
        "8 2 0 0 0 0 0 0 6\n"<<
        "5 0 0 0 0 0 0 0 0\n"<<
        "0 0 0 0 0 0 0 0 0\n"<<
        "0 0 0 4 5 0 0 9 0\n"<<
        "0 0 0 0 0 0 1 3 0\n"<<
        "9 8 0 0 0 0 0 0 0\n"<<
        "0 0 1 0 7 0 0 0 0\n"<<
        "0 0 0 2 0 3 0 0 7\n";
    }

}
