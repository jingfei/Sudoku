#include<iostream>
#include<cstdlib>
#include"Sudoku.h"
using namespace std;

Sudoku::Sudoku()
    {
        for(i = 0; i < 9; i++)
        {
            for(j = 0; j < 9; j++)
                map[i][j] = 0;
        }
    };

    void Sudoku::GiveQuestion()
    {
        int r;
    Sudoku su;
    srand(time(NULL));
    r = (rand()%10) + 1;
        if(r == 1)
        {
            cout << " 0 0 6 3 0 0 9 2 4 " << endl;
            cout << " 4 8 0 9 1 0 0 5 7 " << endl;
            cout << " 2 0 7 4 6 5 0 0 0 " << endl;
            cout << " 5 6 2 8 7 0 0 0 1 " << endl;
            cout << " 0 3 8 1 0 4 7 6 0 " << endl;
            cout << " 7 0 0 0 3 6 5 9 8 " << endl;
            cout << " 0 0 0 6 9 3 2 0 5 " << endl;
            cout << " 6 4 0 0 2 8 0 1 9 " << endl;
            cout << " 3 2 9 0 0 1 8 0 0 " << endl;
        }
        if(r == 2)
        {
            cout << " 8 0 0 6 3 0 0 2 0 " << endl;
            cout << " 0 0 6 0 2 8 0 5 0 " << endl;
            cout << " 3 0 0 0 0 0 8 0 6 " << endl;
            cout << " 0 0 9 0 0 5 0 7 0 " << endl;
            cout << " 4 0 5 0 0 0 9 0 1 " << endl;
            cout << " 0 1 0 7 0 0 6 0 0 " << endl;
            cout << " 2 0 4 0 0 0 0 0 3 " << endl;
            cout << " 0 5 5 3 4 0 1 0 0 " << endl;
            cout << " 0 9 0 0 7 6 0 8 0 " << endl;
        }
        if(r == 3)
        {
            cout << " 0 0 0 5 2 0 7 0 0 " << endl;
            cout << " 0 4 0 6 0 0 0 3 5 " << endl;
            cout << " 1 0 9 0 0 8 4 0 0 " << endl;
            cout << " 0 0 6 0 3 0 0 0 0 " << endl;
            cout << " 5 2 0 0 0 0 0 9 1 " << endl;
            cout << " 0 0 0 0 8 0 2 0 0 " << endl;
            cout << " 0 0 4 7 0 0 9 0 3 " << endl;
            cout << " 6 9 0 0 0 3 0 2 0 " << endl;
            cout << " 0 0 1 0 5 2 0 0 0 " << endl;
        }
        if(r == 4)
        {
            cout << " 0 0 0 0 4 6 0 3 5 " << endl;
            cout << " 0 5 8 0 0 0 1 0 0 " << endl;
            cout << " 0 0 0 7 0 0 0 4 9 " << endl;
            cout << " 0 0 0 9 5 0 6 0 0 " << endl;
            cout << " 9 0 0 0 0 0 0 0 2 " << endl;
            cout << " 0 0 7 0 8 4 0 0 0 " << endl;
            cout << " 3 2 0 0 0 1 0 0 0 " << endl;
            cout << " 0 0 6 0 0 0 3 2 0 " << endl;
            cout << " 1 8 0 6 2 0 0 0 0 " << endl;
        }
        if(r == 5)
        {
            cout << " 0 0 0 0 7 0 0 0 5 " << endl;
            cout << " 0 7 2 0 0 0 0 3 0 " << endl;
            cout << " 0 0 6 0 2 1 4 0 0 " << endl;
            cout << " 0 0 0 0 0 7 8 0 0 " << endl;
            cout << " 3 0 0 0 0 0 0 0 1 " << endl;
            cout << " 0 0 7 9 0 0 0 0 0 " << endl;
            cout << " 0 0 9 7 3 0 5 0 0 " << endl;
            cout << " 0 3 0 0 0 0 9 4 0 " << endl;
            cout << " 8 0 0 0 1 0 0 0 0 " << endl;
        }
        if(r == 6)
        {
            cout << " 8 0 4 9 0 0 6 5 7 " << endl;
            cout << " 2 0 0 1 5 4 0 8 0 " << endl;
            cout << " 5 3 9 0 6 8 4 0 0 " << endl;
            cout << " 7 8 0 0 9 6 1 3 0 " << endl;
            cout << " 0 4 1 0 7 0 2 6 0 " << endl;
            cout << " 0 2 3 4 1 0 0 7 9 " << endl;
            cout << " 0 0 2 5 8 0 3 4 6 " << endl;
            cout << " 0 7 0 3 2 1 0 0 8 " << endl;
            cout << " 3 5 8 0 0 9 7 0 1 " << endl;
        }
        if(r == 7)
        {
            cout << " 3 8 0 0 9 0 0 7 0 " << endl;
            cout << " 0 0 0 7 0 0 6 9 2 " << endl;
            cout << " 6 0 0 4 0 0 1 0 0 " << endl;
            cout << " 0 0 3 0 0 4 2 0 0 " << endl;
            cout << " 0 2 0 8 0 5 0 4 0 " << endl;
            cout << " 0 0 9 3 0 0 7 0 0 " << endl;
            cout << " 0 0 8 0 0 9 0 0 5 " << endl;
            cout << " 1 5 6 0 0 8 0 0 0 " << endl;
            cout << " 0 3 0 0 1 0 0 2 6 " << endl;
        }
        if(r == 8)
        {
            cout << " 0 5 1 4 0 0 0 0 0 " << endl;
            cout << " 0 0 4 0 0 5 0 0 2 " << endl;
            cout << " 0 2 0 0 6 0 1 4 0 " << endl;
            cout << " 8 0 0 0 9 6 0 0 0 " << endl;
            cout << " 0 6 2 0 0 0 9 8 0 " << endl;
            cout << " 0 0 0 3 4 0 0 0 7 " << endl;
            cout << " 0 9 3 0 8 0 0 1 0 " << endl;
            cout << " 4 0 0 1 0 0 7 0 0 " << endl;
            cout << " 0 0 0 0 0 4 8 2 0 " << endl;
        }
        if(r == 9)
        {
            cout << " 0 4 0 0 6 0 0 2 0 " << endl;
            cout << " 9 0 5 0 3 0 0 0 6 " << endl;
            cout << " 0 0 7 0 0 0 0 0 4 " << endl;
            cout << " 0 9 0 8 0 0 1 5 0 " << endl;
            cout << " 0 0 0 9 0 4 0 0 0 " << endl;
            cout << " 0 8 6 0 0 2 0 9 0 " << endl;
            cout << " 6 0 0 0 0 0 3 0 0 " << endl;
            cout << " 3 0 0 0 2 0 5 0 9 " << endl;
            cout << " 0 5 0 0 8 0 0 6 0 " << endl;
        }
        if(r == 10)
        {
            cout << " 0 2 0 3 0 0 0 0 0 " << endl;
            cout << " 4 0 0 0 0 9 2 0 0 " << endl;
            cout << " 3 0 6 8 0 0 0 1 0 " << endl;
            cout << " 0 0 0 0 6 0 1 0 0 " << endl;
            cout << " 0 5 0 0 0 0 0 8 0 " << endl;
            cout << " 0 0 8 0 5 0 0 0 0 " << endl;
            cout << " 0 6 0 0 0 2 9 0 4 " << endl;
            cout << " 0 0 7 6 0 0 0 0 1 " << endl;
            cout << " 0 0 0 0 0 7 0 6 0 " << endl;
        }
    }


    void Sudoku::ReadIn()
    {
    int i,j;
    for(i=0;i<9;i++)
    {
        for(j=0;j<9;j++)
        cin >> map[i][j];
    }
    }



    void Sudoku::Solve()
    {
        k = 0;
        l = 0;
        if(map[0][0] == 0)
            for(i = 0;i < 9; i++)
                map[0][0]++;
        for(i = 0; i < 9; i++)
        {
            for(j = 0; j < 9; j++)
            {
                if(map[i][j]==0)
                {
                    item[k++]=i;
                    jtem[l++]=j;

                    while(1)
                    {
                        map[i][j]++;
                        if(map[i][j]>9)
                        {
                            map[i][j] = 0;
                            i = item[--k];
                            j = jtem[--l];
                            if(i < 0 || j < 0)
                            {
                                cout << "2" << endl;
                                exit(1);
                            }
                        }
                        else
                        {
                        check(i, j);
                        if(check(i, j) != -1)
                            break;
                        }


                    }
                }
            }
        }
        cout << "1" <<endl;
        for(i = 0; i < 9; i++)
        {
            for(j = 0; j < 9; j++)
            {
                cout << map[i][j] << " ";
            }
            cout << endl;
        }



    }






    int Sudoku::check(int i, int j)
    {
        a = i;
        b = j;
        for(c =0; c < 10; c++)
            count1[c] = 0;

        for(j = 0; j < 9; j++)
        {
            count1[map[i][j]]++;
            for(n = 1; n <= 9; n++)
            {
                if(count1[n] > 1)
                    return -1;
            }
        }
        i = a;
        j = b;
        for(c =0; c < 10; c++)
            count1[c] = 0;

        for(i = 0; i < 9; i++)
        {
            count1[map[i][j]]++;
            for(n = 1; n <= 9; n++)
            {
                if(count1[n] > 1)
                    return -1;
            }
        }
        i = a;
        j = b;
        for(c =0; c < 10; c++)
            count1[c] = 0;
        area = 0;
        if(i >= 0 && i < 3 && j >= 0 && j <3)
            area = 1;
        if(i >= 0 && i < 3 && j >= 3 && j <6)
            area = 2;
        if(i >= 0 && i < 3 && j >= 6 && j <9)
            area = 3;
        if(i >= 3 && i < 6 && j >= 0 && j <3)
            area = 4;
        if(i >= 3 && i < 6 && j >= 3 && j <6)
            area = 5;
        if(i >= 3 && i < 6 && j >= 6 && j <9)
            area = 6;
        if(i >= 6 && i < 9 && j >= 0 && j <3)
            area = 7;
        if(i >= 6 && i < 9 && j >= 3 && j <6)
            area = 8;
        if(i >= 6 && i < 9 && j >= 6 && j <9)
            area = 9;

        if(area == 1)
        {
            for(i = 0; i < 3; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    count1[map[i][j]]++;
                    for(n = 1; n <= 9; n++)
                    {
                        if(count1[n] > 1)
                            return -1;
                    }
                }
            }
        }
        if(area == 2)
        {
            for(i = 0; i < 3; i++)
            {
                for(j = 3; j < 6; j++)
                {
                    count1[map[i][j]]++;
                    for(n = 1; n <= 9; n++)
                    {
                        if(count1[n] > 1)
                            return -1;
                    }
                }
            }
        }
        if(area == 3)
        {
            for(i = 0; i < 3; i++)
            {
                for(j = 6; j < 9; j++)
                {
                    count1[map[i][j]]++;
                    for(n = 1; n <= 9; n++)
                    {
                        if(count1[n] > 1)
                            return -1;
                    }
                }
            }
        }
        if(area == 4)
        {
            for(i = 3; i < 6; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    count1[map[i][j]]++;
                    for(n = 1; n <= 9; n++)
                    {
                        if(count1[n] > 1)
                            return -1;
                    }
                }
            }
        }
        if(area == 5)
        {
            for(i = 3; i < 6; i++)
            {
                for(j = 3; j < 6; j++)
                {
                    count1[map[i][j]]++;
                    for(n = 1; n <= 9; n++)
                    {
                        if(count1[n] > 1)
                            return -1;
                    }
                }
            }
        }
        if(area == 6)
        {
            for(i = 3; i < 6; i++)
            {
                for(j = 6; j < 9; j++)
                {
                    count1[map[i][j]]++;
                    for(n = 1; n <= 9; n++)
                    {
                        if(count1[n] > 1)
                            return -1;
                    }
                }
            }
        }
        if(area == 7)
        {
            for(i = 6; i < 9; i++)
            {
                for(j = 0; j < 3; j++)
                {
                    count1[map[i][j]]++;
                    for(n = 1; n <= 9; n++)
                    {
                        if(count1[n] > 1)
                            return -1;
                    }
                }
            }
        }
        if(area == 8)
        {
            for(i = 6; i < 9; i++)
            {
                for(j = 3; j < 6; j++)
                {
                    count1[map[i][j]]++;
                    for(n = 1; n <= 9; n++)
                    {
                        if(count1[n] > 1)
                            return -1;
                    }
                }
            }
        }
        if(area == 9)
        {
            for(i = 6; i < 9; i++)
            {
                for(j = 6; j < 9; j++)
                {
                    count1[map[i][j]]++;
                    for(n = 1; n <= 9; n++)
                    {
                        if(count1[n] > 1)
                            return -1;
                    }
                }
            }
        }


        for(c =0; c < 10; c++)
            count1[c] = 0;
    }


