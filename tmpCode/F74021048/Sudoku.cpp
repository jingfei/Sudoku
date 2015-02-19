#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "Sudoku.h"
using namespace std;


    int a[10][10],b[10][10],ans,TIME;
	Sudoku::Sudoku()
	{
		ans=0;
		TIME=0;
	}
    void Sudoku::GiveQuestion()
    {
        srand(time(NULL));
        int j;
        string print;
        string q = ("064001020000894030030520004041000800200000490800305000009000706005070001600008200");
        string w = ("520000109800951000016200080000062370063010002200709001002006895008320600650000030");
        string e = ("000250907048600030907108000002065090093002005050017040200500870680000509100090403");
        string r = ("090708014207006508080453009359071806010804700804030921400307190035100402901042080");
        string t = ("070000920008200003090300670000000000700654390400000501000030000003160200000900007");
        string y = ("000010000010007569506400080028005170005003090000100000200000003087000000000008010");
        string u = ("000500760000002800000081000000000000840050010000900507004010070605000009000470380");
        string i = ("837020000602009300004000000400008009000040038500100000000030000008490000000680041");
        string o = ("060000000000960085000704000673000000890000100001000360040000500000007009732809006");
        string p = ("090500001210734000400020005060100008000000090000460000900005007300000006040019000");
        string z = ("360200045000530690087000100000120960003605800028094000001000480075063000240009057");
        if( (rand()%11) == 0 ) print = q;
        if( (rand()%11) == 1 ) print = w;
        if( (rand()%11) == 2 ) print = e;
        if( (rand()%11) == 3 ) print = r;
        if( (rand()%11) == 4 ) print = t;
        if( (rand()%11) == 5 ) print = y;
        if( (rand()%11) == 6 ) print = u;
        if( (rand()%11) == 7 ) print = i;
        if( (rand()%11) == 8 ) print = o;
        if( (rand()%11) == 9 ) print = p;
        if( (rand()%11) == 10 ) print = z;
        for (j=0;j<=80;j++)
        {
            cout << print[j] ;
            if ( ( j%9 ) == 8 ) cout << endl ;
            else cout << " " ;
        }
    }
    void Sudoku::ReadIn()
    {
        int i,j;
        for(i=1;i<=9;i++)
        {
            for(j=1;j<=9;j++)
            {
                a[i][j] = 0;
                b[i][j] = 0;
            }
        }
        for(i=1;i<=9;i++)
        {
            for(j=1;j<=9;j++)
            {
                cin >> a[i][j];
            }
        }
    }
    void Sudoku::Solve()
    {
        int num,i,j,m,n,zero=0,zerox=0,zero_save;
        for(i=1;i<=9;i++)
        {
            for(j=1;j<=9;j++)
            {
                if(a[i][j] == 0)
                {
                    zero++;
                }
            }
        }
        if(TIME == 0)
        {
            zero_save = zero ;
            TIME++;
        }
        if( zero == 0 )
        {
            ans++;
            if(ans > 1)
            {
                cout << "2";
                exit(0);
            }
            for(i=1;i<=9;i++)
            {
                for(j=1;j<=9;j++)
                {
                    b[i][j] = a[i][j];
                }
            }
            return ;
        }
        for(i=1;i<=9;i++)
        {
            for(j=1;j<=9;j++)
            {
                if(a[i][j] == 0)
                {
                    for(num=1;num<=9;num++)
                    {
                        if( check(num,i,j) == 0 )
                        {
                            a[i][j] = num;
                            Solve();
                            a[i][j] = 0;
                        }
                    }
                    for(m=1;m<=9;m++)
                    {
                        for(n=1;n<=9;n++)
                        {
                            if(a[m][n] == 0)
                            {
                                zerox ++;
                            }
                        }
                    }
                    if(zerox == zero_save)
                    {
                        if(ans == 1)
                        {
                            cout << "1" << endl ;
                            for(i=1;i<=9;i++)
                            {
                                for(j=1;j<=9;j++)
                                {
                                    cout << b[i][j];
                                    if (j < 9)
                                    {
                                        cout << " ";
                                    }
                                }
                                cout << endl;
                            }
exit(0);
                        }
                        else if ( ans == 0)
                        {
                            cout << "0" ;
                        }
                    }
                    return; /////!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                }
            }
        }
    }

    int Sudoku::check(int num,int i,int j)
    {
        int m,n;
        for(m=1;m<=9;m++)
        {
            if(num == a[i][m]) return 1;
        }
        for(m=1;m<=9;m++)
        {
            if(num == a[m][j]) return 1;
        }
        if(j == 1 || j == 4 || j == 7 )
        {
            for(n=j+1;n<=j+2;n++)
            {
                if(i == 1 || i == 4 || i == 7 )
                {
                    for(m=i+1;m<=i+2;m++)
                    {
                        if(num == a[m][n]) return 1;
                    }
                }
                if(i == 2 || i == 5 || i == 8 )
                {
                    if(num == a[i+1][n]) return 1;
                    if(num == a[i-1][n]) return 1;
                }
                if(i == 3 || i == 6 || i == 9 )
                {
                    for(m=i-2;m<=i-1;m++)
                    {
                        if(num == a[m][n]) return 1;
                    }
                }
            }
        }
        if(j == 2 || j == 5 || j == 8 )
        {
            if(i == 1 || i == 4 || i == 7 )
            {
                for(m=i+1;m<=i+2;m++)
                {
                    if(num == a[m][j-1]) return 1;
                    if(num == a[m][j+1]) return 1;
                }
            }
            if(i == 2 || i == 5 || i == 8 )
            {
                if(num == a[i-1][j-1]) return 1;
                if(num == a[i-1][j+1]) return 1;
                if(num == a[i+1][j-1]) return 1;
                if(num == a[i+1][j+1]) return 1;
            }
             if(i == 3 || i == 6 || i == 9 )
            {
                for(m=i-2;m<=i-1;m++)
                {
                    if(num == a[m][j-1]) return 1;
                    if(num == a[m][j+1]) return 1;
                }
            }
        }
        if(j == 3 || j == 6 || j == 9 )
        {
            for(n=j-2;n<=j-1;n++)
            {
                if(i == 1 || i == 4 || i == 7 )
                {
                    for(m=i+1;m<=i+2;m++)
                    {
                        if(num == a[m][n]) return 1;
                    }
                }
                if(i == 2 || i == 5 || i == 8 )
                {
                    if(num == a[i+1][n]) return 1;
                    if(num == a[i-1][n]) return 1;
                }
                if(i == 3 || i == 6 || i == 9 )
                {
                    for(m=i-2;m<=i-1;m++)
                    {
                        if(num == a[m][n]) return 1;
                    }
                }
            }
        }
        else return 0;
    }