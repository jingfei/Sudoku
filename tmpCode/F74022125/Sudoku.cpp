#include "Sudoku.h"
using namespace std;

    Sudoku::Sudoku()
    {
        mark=0; un=0;
    }

    void Sudoku::GiveQuestion()
    {
       int store[81];
       int number_store[9] = {1,2,3,4,5,6,7,8,9};
       int p,q,r;
       string topic;
       string a("142506970030192605960400028403001060051709234620305009070003481306917050014070390");
       string b("523091640900570831010346500307018065085700310641230708009007080406983102032150976");
       string c("035940602420360057106052390318070026070806049960010730043590201201003075657024980");
       string d("702503014040906872008024030904007021370201980201300007017050200420138090630472158");
       srand( time( NULL ));

       for (p=0;p<9;p++)
       {
          q = rand() % 9;
          r = number_store[p];
          number_store[p] = number_store[q];
          number_store[q] = r;
       }
       switch((rand()%4)+1)
       {
          case 1:
               topic=a;
               break;
          case 2:
               topic=b;
               break;
          case 3:
               topic=c;
               break;
          case 4:
               topic=d;
               break;
       }
       cout<<endl;

       for(q=0;q<81;q++)
       {
          switch(topic[q])
          {
            case '0':
                store[q]=0;
                break;
            case '1':
                store[q]=number_store[0];
                break;
            case '2':
                store[q]=number_store[1];
                break;
            case '3':
                store[q]=number_store[2];
                break;
            case '4':
                store[q]=number_store[3];
                break;
            case '5':
                store[q]=number_store[4];
                break;
            case '6':
                store[q]=number_store[5];
                break;
            case '7':
                store[q]=number_store[6];
                break;
            case '8':
                store[q]=number_store[7];
                break;
            case '9':
                store[q]=number_store[8];
                break;

          }
       }
       for(p=1;p<82;p++)
       {
          cout << store[p-
          1] << " ";
          if((p%9)==0)
          {
              cout << endl;
          }
       }
    }

    void Sudoku::ReadIn()
    {
        int i,j,k;
        cout << "Please enter a sudoku:\n";

        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                cin >> site[i][j];
            }
        }
        cout<<endl;
    }

    void Sudoku::Solve()
    {
        int i,j;
        mark=0;

        backtracking();

        if(mark==0)
        {
            cout << "0\n";
        }
        else if(mark==1)
        {
            cout << "1\n";
            for(i=0;i<9;i++)
            {
                for(j=0;j<9;j++)
                {
                    cout << check[i][j] << " ";
                }
                cout << endl;
            }
        }
        else
        {
            cout << "2\n";
        }
    }

    int Sudoku::JudgeRow(int k,int i)
    {
        int p;
        for(p=0;p<9;p++)
        {
            if(k == site[i][p])
            {
                return 1;
            }
        }
        return 0;
    }

    int Sudoku::JudgeColumn(int k,int j)
    {
        int p;
        for(p=0;p<9;p++)
        {
            if(k == site[p][j])
            {
                return 1;
            }
        }
        return 0;
    }

    int Sudoku::JudgeSquare(int k,int i,int j)
    {
        int m,n;
        m = i - (i%3);
        n = j - (j%3);

        for (int x=1;x<3;x++)
        {
            for (int y=1;y<3;y++)
            {
                if(site[m+x][n+y] == k)
                {
                    return 1;
                }
            }
        }
        return 0;
    }

    void Sudoku::backtracking()
    {
        un++;
        if(un>50000000)
        {
           mark=0;
           return;
        }

        int i,j,k;
        int blank=0;
        for(i=0;i<9;i++)
        {
            for(j=0;j<9;j++)
            {
                if(site[i][j]==0)
                {
                    blank++;
                }
            }
        }

        if(blank==0)
        {
            mark++;
            if(mark>1)
            {
                return;
            }
            for(i=0;i<9;i++)
            {
                for(j=0;j<9;j++)
                {
                    check[i][j] = site[i][j];
                }
            }
            return;
        }

        for(i=8;i>=0;i--)
        {
            for(j=8;j>=0;j--)
            {
                if(site[i][j]==0)
                {
                    for(k=1;k<=9;k++)
                    {
                        if(JudgeSquare(k,i,j)==0 && JudgeRow(k,i)==0 && JudgeColumn(k,j)==0)
                        {
                            site[i][j]=k;
                            backtracking();
                            if (mark > 1) return;
                            site[i][j]=0;
                        }
                    }
                    return;
                }
            }
        }
    }