#include<iostream>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cstdio>
#include <ctime>

using namespace std;

class Sudoku
{
public:
    Sudoku();
    void GiveQuestion();
    void ReadIn();
    void Solve();
    static const int magnitude_Sudoku = 81;
private:
    bool determinezero();
    int tempmap[magnitude_Sudoku], ans[magnitude_Sudoku];
    int cnt_ans;
    bool determineCorrect();
    bool checkUnity(int arr[]);

    void SolveIt();
};

Sudoku::Sudoku()
{
    cnt_ans = 0;
}

void Sudoku::GiveQuestion()
{
    int question1[] = {9,0,0,2,4,0,5,7,0,
                       3,1,0,8,0,0,0,9,0,
                       4,7,0,0,0,0,8,3,0,
                       6,9,0,7,0,8,0,0,0,
                       0,5,4,0,6,0,0,0,0,
                       1,0,0,5,0,0,0,0,0,
                       5,4,1,9,3,0,0,0,0,
                       7,8,0,0,0,1,0,0,0,
                       0,0,0,0,0,0,0,0,0
                      };
    int question2[] = {2,6,7,0,5,0,0,8,0,
                       4,0,5,8,2,0,3,7,0,
                       0,8,0,6,0,0,4,5,0,
                       3,0,2,0,9,5,0,0,0,
                       0,0,0,2,0,8,7,0,0,
                       8,5,0,0,6,0,2,0,0,
                       5,2,1,0,8,0,0,0,0,
                       7,3,6,4,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0
                      };
    int question3[] = {7,0,9,1,3,0,2,5,0,
                       2,0,0,4,9,0,6,3,0,
                       3,6,0,0,0,0,4,1,0,
                       9,0,5,2,1,0,0,6,0,
                       1,3,4,0,0,9,5,0,0,
                       0,0,0,0,4,0,0,0,0,
                       4,1,2,9,0,0,0,0,0,
                       5,9,0,0,2,1,0,0,0,
                       0,0,0,0,0,0,0,0,0
                      };
    int question4[] = {0,0,3,2,5,0,4,9,1,
                       0,5,0,1,3,9,0,0,0,
                       6,0,0,8,4,0,5,2,0,
                       8,0,0,0,0,0,0,4,0,
                       0,0,0,4,0,0,1,0,8,
                       0,4,0,0,2,0,0,0,5,
                       2,1,4,6,0,0,0,0,0,
                       0,0,0,0,7,0,8,0,0,
                       0,0,0,0,0,2,3,0,0
                      };
    int question5[] = {0,7,4,0,6,0,5,0,1,
                       8,0,2,0,3,0,4,6,0,
                       6,0,0,0,0,4,0,0,0,
                       0,0,3,7,1,0,0,2,0,
                       2,0,0,0,4,5,1,7,0,
                       0,0,5,0,0,0,3,0,0,
                       5,0,0,8,0,0,0,0,0,
                       0,0,0,9,0,0,0,0,0,
                       0,3,8,4,5,6,2,0,0
                      };
    int question6[] = {0,2,0,0,0,9,0,8,0,
                       6,0,5,0,0,0,0,3,0,
                       1,3,0,0,0,0,0,0,4,
                       2,0,3,7,0,0,1,4,0,
                       0,4,6,1,0,0,8,0,0,
                       0,8,1,0,9,0,0,0,0,
                       3,1,2,8,0,0,4,9,0,
                       5,0,0,9,1,0,0,0,0,
                       0,0,0,0,0,0,0,0,3
                      };

    srand(time(NULL));

    int i = rand() % 6;
    int j;
    if(i == 1)
    {
        for(j = 0; j < magnitude_Sudoku ; j++)
        {
            cout << question1[j] << " " ;
            if((j + 1) % 9 == 0)
                cout << "\n";
        }
    }
    else if(i == 2)
    {
        for(j = 0; j < magnitude_Sudoku; j++)
        {
            cout << question2[j] << " " ;
            if((j + 1) % 9 == 0)
                cout << "\n";
        }
    }
    else if(i == 3)
    {
        for(j = 0; j < magnitude_Sudoku; j++)
        {
            cout << question3[j] << " " ;
            if((j + 1) % 9 == 0)
                cout << "\n";
        }
    }
    else if(i == 4)
    {
        for(j = 0; j < magnitude_Sudoku; j++)
        {
            cout << question4[j] << " " ;
            if((j + 1) % 9 == 0)
                cout << "\n";
        }
    }
    else if(i == 5)
    {
        for(j = 0; j < magnitude_Sudoku; j++)
        {
            cout << question5[j] << " " ;
            if((j + 1) % 9 == 0)
                cout << "\n";
        }
    }
    else
    {
        for(j = 0; j < magnitude_Sudoku; j++)
        {
            cout << question6[j] << " " ;
            if((j + 1) % 9 == 0)
                cout << "\n";
        }
    }

}

void Sudoku::ReadIn()
{
    int k;
    for(k = 0; k < magnitude_Sudoku; k++)
        cin >> tempmap[k];
}

void Sudoku::Solve()
{
    SolveIt();

    if (cnt_ans == 0)
        cout << "0" << endl;
    else if (cnt_ans == 1)
    {
        cout << "1" << endl;
        int x = 0;
        while(x < magnitude_Sudoku)
        {
            cout << ans[x] << " ";
            if((x + 1) % 9 == 0)
                cout << "\n";
            x++;
        }
    }
    else cout << "2" << endl;
}

void Sudoku::SolveIt()
{
    int numarray[10];
    int c,x,y,i;
    int z = 0;
    bool j,k;
    memset(numarray,0,sizeof(numarray));
    j = determineCorrect();

    if(j == false)
    {
    }
    else
    {
        k = determinezero();
        if(k == false)
        {
            for(c = 0 ; c < magnitude_Sudoku && cnt_ans < 2; c++)
            {
                if(tempmap[c] == 0)
                {
                    for(x = c - (c % 9) ; x - (c - (c % 9)) <= 8; x++)
                    {
                        if(tempmap[x] != 0)
                            numarray[tempmap[x]]++;
                    }
                    for(y = c % 9; y - (c % 9) <= 71; y += 9)
                    {
                        if(tempmap[y] != 0)
                            numarray[tempmap[y]]++;
                    }
                    for(i = 1; i <= 9; i++)
                    {
                        if(numarray[i] == 0)
                        {
                            tempmap[c] = i;
                            SolveIt();
                            tempmap[c] = 0;
                        }
                    }

                    return;
                }
            }
        }
        else
        {
            
            cnt_ans++;
            if (cnt_ans == 1)
                memcpy(ans, tempmap, sizeof(ans));
        }
    }
}

bool Sudoku::determinezero()
{
    int z;
    for(z = 0; z < magnitude_Sudoku; z++)
    {
        if(tempmap[z] == 0)
            return false;
    }
    return true;
}


bool Sudoku::determineCorrect()
{
    bool check_result;
    int check_arr[9];
    int location;
    for(int i=0; i<81; i+=9)
    {
        for(int j=0; j<9; ++j)
            check_arr[j] = tempmap[i+j];
        check_result = checkUnity(check_arr);
        if(check_result == false)
        {
            return false;
        }
    }
    for(int i=0; i<9; ++i)
    {
        for(int j=0; j<9; ++j)
            check_arr[j] = tempmap[i+9*j];
        check_result = checkUnity(check_arr);
        if(check_result == false)
        {
            return false;
        }
    }

    for(int i=0; i<9; ++i)
    {
        for(int j=0; j<9; ++j)
        {
            location = 27*(i/3) + 3*(i%3) +9*(j/3) + (j%3);
            check_arr[j] = tempmap[location];
        }
        check_result = checkUnity(check_arr);
        if(check_result == false)
        {
            return false;
        }
    }
    return true;
}

bool Sudoku::checkUnity(int arr[])
{
    int arr_unity[10];
    memset(arr_unity,0,sizeof(arr_unity));
    for(int i=0; i<9; ++i)
        ++arr_unity[arr[i]];

    for(int i=1; i<=9; ++i)
    {
        if(arr_unity[i] > 1)
        {
            return false;
        }
    }
    return true;
}
