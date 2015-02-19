#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku()
{
	tans = 0;
}
void Sudoku::GiveQuestion()
{
    int a = rand()%4;
    if(a==1)cout<<"0 0 0 0 1 0 8 7 0"<<endl<<"0 2 0 0 9 0 0 0 0"<<endl<<"0 0 0 5 0 0 0 0 0"<<endl<<"2 0 0 0 6 8 0 9 0"<<endl<<"0 0 8 0 7 0 3 0 0"<<endl<<"0 9 7 0 0 0 0 0 0"<<endl<<"0 0 0 0 0 4 6 3 0"<<endl<<"080050000"<<endl<<"071300900";
    if(a==2)cout<<"0 0 1 4 3 0 0 8 9"<<endl<<"0 0 0 0 0 0 1 0 0"<<endl<<"0 0 4 0 0 1 0 0 0"<<endl<<"5 0 0 0 0 0 0 0 0"<<endl<<"0 2 0 8 6 7 0 0 0"<<endl<<"0 6 0 0 9 0 0 0 0"<<endl<<"0 0 3 0 0 0 2 0 0"<<endl<<"0 0 0 0 0 0 7 1 0"<<endl<<"8 0 5 0 4 0 0 3 0";
    if(a==3)cout<<"5 0 8 0 0 0 0 0 0"<<endl<<"0 6 0 0 0 0 0 0 0"<<endl<<"0 1 0 6 0 0 0 2 4"<<endl<<"2 8 0 5 0 0 9 0 3"<<endl<<"0 0 9 0 0 4 5 7 0"<<endl<<"6 0 0 0 0 0 8 0 0"<<endl<<"0 0 0 9 0 6 0 0 0"<<endl<<"0 0 0 0 4 0 7 3 0"<<endl<<"0 0 0 0 1 0 0 0 0";
    if(a==4)cout<<"0 4 0 1 0 0 0 0 7"<<endl<<"6 0 0 0 4 0 0 0 0"<<endl<<"7 3 0 0 0 0 2 0 0"<<endl<<"0 0 0 0 0 0 8 0 0"<<endl<<"0 0 0 5 3 9 0 0 0"<<endl<<"2 6 5 0 7 0 0 0 0"<<endl<<"0 0 0 0 0 2 5 0 0"<<endl<<"0 0 0 4 8 0 0 0 1"<<endl<<"0 0 7 0 0 0 6 3 0";
}
void Sudoku::ReadIn()
{
    int tmp;
    while(cin >> tmp)
    {
        vmap.push_back(tmp);

    }
}
void Sudoku::Solve()
{
    int now=0;
    backtracking(now);
    cout<<getans()<<endl;
    if(getans() == 1)
    {
        for(int i=0; i<=80; i++)
        {
            cout<<ans.at(i);
            if(i % 9 == 8 )
                cout << endl;
        }
    }
}
int Sudoku::getans()
{
    if(tans>1)return 2;
    if(tans==1) return 1;
    if(tans==0) return 0;
}
void Sudoku::backtracking(int now)
{
    if(now==81)
    {
    	if (tans == 0)
			ans = vmap;
        tans++;
        return;
    }
    if(vmap.at(now)==0)
    {
        for(int i=0; i<=9; i++)
        {
            if(now<9)
            {
            	test = 0;
                for(int len=0; len<=8; len++)
                {
                    if(i==vmap.at(len))
                        test++;
                }
                for(int k=0; k<=8; k++)
                {
                    if(i==vmap.at(now+9*k))
                        test++;
                }
                if(now%3 ==0)
                    if(i==vmap.at(now+1)||i==vmap.at(now+2)||i==vmap.at(now+9)||i==vmap.at(now+10)||i==vmap.at(now+11)||i==vmap.at(now+18)||i==vmap.at(now+19)||i==vmap.at(now+20))
                        test++;
                if(now%3 ==1)
                    if(i==vmap.at(now-1)||i==vmap.at(now+1)||i==vmap.at(now+8)||i==vmap.at(now+9)||i==vmap.at(now+10)||i==vmap.at(now+17)||i==vmap.at(now+18)||i==vmap.at(now+19))
                        test++;
                if(now%3 ==2)
                    if(i==vmap.at(now-2)||i==vmap.at(now-1)||i==vmap.at(now+7)||i==vmap.at(now+8)||i==vmap.at(now+9)||i==vmap.at(now+16)||i==vmap.at(now+17)||i==vmap.at(now+18))
                        test++;
                if(test==0)
                    vmap.at(now)=i;
            }
            if(now>8 && now<18)
            {
            	test = 0;
                for(int len=9; len<=17; len++)
                {
                    if(i==vmap.at(len))
                        test++;
                }
                for(int k=(-1); k<=7; k++)
                {
                    if(i==vmap.at(now+9*k))
                        test++;
                }
                if(now%3 ==0)
                    if(i==vmap.at(now-9)||i==vmap.at(now-8)||i==vmap.at(now-7)||i==vmap.at(now+1)||i==vmap.at(now+2)||i==vmap.at(now+9)||i==vmap.at(now+10)||i==vmap.at(now+11))
                        test++;
                if(now%3==1)
                    if(i==vmap.at(now-10)||i==vmap.at(now-9)||i==vmap.at(now-8)||i==vmap.at(now-1)||i==vmap.at(now+1)||i==vmap.at(now+8)||i==vmap.at(now+9)||i==vmap.at(now+10))
                        test++;
                if(now%3==2)
                    if(i==vmap.at(now-11)||i==vmap.at(now-10)||i==vmap.at(now-9)||i==vmap.at(now-1)||i==vmap.at(now-2)||i==vmap.at(now+7)||i==vmap.at(now+8)||i==vmap.at(now+9))
                        test++;
                if(test==0)
                    vmap.at(now)=i;
            }
            if(now>17 && now<27)
            {
            	test = 0;
                for(int len=18; len<=26; len++)
                {
                    if(i==vmap.at(len))
                        test++;
                }
                for(int k=(-2); k<=6; k++)
                {
                    if(i==vmap.at(now+9*k))
                        test++;
                }
                if(now%3 ==0)
                    if(i==vmap.at(now-18)||i==vmap.at(now-17)||i==vmap.at(now-16)||i==vmap.at(now-9)||i==vmap.at(now-8)||i==vmap.at(now-7)||i==vmap.at(now+1)||i==vmap.at(now+2))
                        test++;
                if(now%3 ==1)
                    if(i==vmap.at(now-19)||i==vmap.at(now-18)||i==vmap.at(now-17)||i==vmap.at(now-10)||i==vmap.at(now-9)||i==vmap.at(now-8)||i==vmap.at(now-1)||i==vmap.at(now+1))
                        test++;
                if(now%3 ==2)
                    if(i==vmap.at(now-20)||i==vmap.at(now-19)||i==vmap.at(now-18)||i==vmap.at(now-11)||i==vmap.at(now-10)||i==vmap.at(now-9)||i==vmap.at(now-2)||i==vmap.at(now-1))
                        test++;
                if(test==0)
                    vmap.at(now)=i;
            }
            if(now>26 && now<36)
            {
            	test = 0;
                for(int len=27; len<=35; len++)
                {
                    if(i==vmap.at(len))
                        test++;
                }
                for(int k=(-3); k<=5; k++)
                {
                    if(i==vmap.at(now+9*k))
                        test++;
                }
                if(now%3 ==0)
                    if(i==vmap.at(now+1)||i==vmap.at(now+2)||i==vmap.at(now+9)||i==vmap.at(now+10)||i==vmap.at(now+11)||i==vmap.at(now+18)||i==vmap.at(now+19)||i==vmap.at(now+20))
                        test++;
                if(now%3 ==1)
                    if(i==vmap.at(now-1)||i==vmap.at(now+1)||i==vmap.at(now+8)||i==vmap.at(now+9)||i==vmap.at(now+10)||i==vmap.at(now+17)||i==vmap.at(now+18)||i==vmap.at(now+19))
                        test++;
                if(now%3 ==2)
                    if(i==vmap.at(now-2)||i==vmap.at(now-1)||i==vmap.at(now+7)||i==vmap.at(now+8)||i==vmap.at(now+9)||i==vmap.at(now+16)||i==vmap.at(now+17)||i==vmap.at(now+18))
                        test++;
                if(test==0)
                    vmap.at(now)=i;
            }
            if(now>35 && now<45)
            {
            	test = 0;
                for(int len=36; len<=44; len++)
                {
                    if(i==vmap.at(len))
                        test++;
                }
                for(int k=(-4); k<=4; k++)
                {
                    if(i==vmap.at(now+9*k))
                        test++;
                }
                if(now%3 ==0)
                    if(i==vmap.at(now-9)||i==vmap.at(now-8)||i==vmap.at(now-7)||i==vmap.at(now+1)||i==vmap.at(now+2)||i==vmap.at(now+9)||i==vmap.at(now+10)||i==vmap.at(now+11))
                        test++;
                if(now%3==1)
                    if(i==vmap.at(now-10)||i==vmap.at(now-9)||i==vmap.at(now-8)||i==vmap.at(now-1)||i==vmap.at(now+1)||i==vmap.at(now+8)||i==vmap.at(now+9)||i==vmap.at(now+10))
                        test++;
                if(now%3==2)
                    if(i==vmap.at(now-11)||i==vmap.at(now-10)||i==vmap.at(now-9)||i==vmap.at(now-1)||i==vmap.at(now-2)||i==vmap.at(now+7)||i==vmap.at(now+8)||i==vmap.at(now+9))
                        test++;
                if(test==0)
                    vmap.at(now)=i;
            }
            if(now > 44 && now<54)
            {
            	test = 0;
                for(int len=45; len<=53; len++)
                {
                    if(i==vmap.at(len))
                        test++;
                }
                for(int k=(-5); k<=3; k++)
                {
                    if(i==vmap.at(now+9*k))
                        test++;
                }
                if(now%3 ==0)
                    if(i==vmap.at(now-18)||i==vmap.at(now-17)||i==vmap.at(now-16)||i==vmap.at(now-9)||i==vmap.at(now-8)||i==vmap.at(now-7)||i==vmap.at(now+1)||i==vmap.at(now+2))
                        test++;
                if(now%3 ==1)
                    if(i==vmap.at(now-19)||i==vmap.at(now-18)||i==vmap.at(now-17)||i==vmap.at(now-10)||i==vmap.at(now-9)||i==vmap.at(now-8)||i==vmap.at(now-1)||i==vmap.at(now+1))
                        test++;
                if(now%3 ==2)
                    if(i==vmap.at(now-20)||i==vmap.at(now-19)||i==vmap.at(now-18)||i==vmap.at(now-11)||i==vmap.at(now-10)||i==vmap.at(now-9)||i==vmap.at(now-2)||i==vmap.at(now-1))
                        test++;
                if(test==0)
                    vmap.at(now)=i;
            }
            if(now>53 && now<63)
            {
            	test = 0;
                for(int len=54; len<=62; len++)
                {
                    if(i==vmap.at(len))
                        test++;
                }
                for(int k=(-6); k<=2; k++)
                {
                    if(i==vmap.at(now+9*k))
                        test++;
                }
                if(now%3 ==0)
                    if(i==vmap.at(now+1)||i==vmap.at(now+2)||i==vmap.at(now+9)||i==vmap.at(now+10)||i==vmap.at(now+11)||i==vmap.at(now+18)||i==vmap.at(now+19)||i==vmap.at(now+20))
                        test++;
                if(now%3 ==1)
                    if(i==vmap.at(now-1)||i==vmap.at(now+1)||i==vmap.at(now+8)||i==vmap.at(now+9)||i==vmap.at(now+10)||i==vmap.at(now+17)||i==vmap.at(now+18)||i==vmap.at(now+19))
                        test++;
                if(now%3 ==2)
                    if(i==vmap.at(now-2)||i==vmap.at(now-1)||i==vmap.at(now+7)||i==vmap.at(now+8)||i==vmap.at(now+9)||i==vmap.at(now+16)||i==vmap.at(now+17)||i==vmap.at(now+18))
                        test++;
                if(test==0)
                    vmap.at(now)=i;
            }
            if(now>62 && now<72)
            {
            	test = 0;
                for(int len=63; len<=71; len++)
                {
                    if(i==vmap.at(len))
                        test++;
                }
                for(int k=(-7); k<=1; k++)
                {
                    if(i==vmap.at(now+9*k))
                        test++;
                }
                if(now%3 ==0)
                    if(i==vmap.at(now-9)||i==vmap.at(now-8)||i==vmap.at(now-7)||i==vmap.at(now+1)||i==vmap.at(now+2)||i==vmap.at(now+9)||i==vmap.at(now+10)||i==vmap.at(now+11))
                        test++;
                if(now%3==1)
                    if(i==vmap.at(now-10)||i==vmap.at(now-9)||i==vmap.at(now-8)||i==vmap.at(now-1)||i==vmap.at(now+1)||i==vmap.at(now+8)||i==vmap.at(now+9)||i==vmap.at(now+10))
                        test++;
                if(now%3==2)
                    if(i==vmap.at(now-11)||i==vmap.at(now-10)||i==vmap.at(now-9)||i==vmap.at(now-1)||i==vmap.at(now-2)||i==vmap.at(now+7)||i==vmap.at(now+8)||i==vmap.at(now+9))
                        test++;
                if(test==0)
                    vmap.at(now)=i;
            }
            if(now>71 && now<81)
            {
            	test = 0;
                for(int len=72; len<=80; len++)
                {
                    if(i==vmap.at(len))
                        test++;
                }
                for(int k=(-8); k<=0; k++)
                {
                    if(i==vmap.at(now+9*k))
                        test++;
                }
                if(now%3 ==0)
                    if(i==vmap.at(now-18)||i==vmap.at(now-17)||i==vmap.at(now-16)||i==vmap.at(now-9)||i==vmap.at(now-8)||i==vmap.at(now-7)||i==vmap.at(now+1)||i==vmap.at(now+2))
                        test++;
                if(now%3 ==1)
                    if(i==vmap.at(now-19)||i==vmap.at(now-18)||i==vmap.at(now-17)||i==vmap.at(now-10)||i==vmap.at(now-9)||i==vmap.at(now-8)||i==vmap.at(now-1)||i==vmap.at(now+1))
                        test++;
                if(now%3 ==2)
                    if(i==vmap.at(now-20)||i==vmap.at(now-19)||i==vmap.at(now-18)||i==vmap.at(now-11)||i==vmap.at(now-10)||i==vmap.at(now-9)||i==vmap.at(now-2)||i==vmap.at(now-1))
                        test++;
                if(test==0)
                    vmap.at(now)=i;
            }
            if (vmap.at(now)!=0)
			{
				backtracking(now+1);
				vmap.at(now)=0;
			}
        }
    }
    else
        backtracking(now+1);
}


