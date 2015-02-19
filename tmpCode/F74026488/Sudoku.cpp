#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<ctime>
#include"Sudoku.h"
using namespace std;

        Sudoku::Sudoku()
        {
                ans[0]=0;
                for(int i=0;i<9;i++)
                {

                        for(int j=0;j<9;j++)
                        {
                                map[i][j]=0;
                                sum_map[i][j]=0;
                                new_sum[i][j]=0;
                                result_map[i][j]=0;
                                for(int k=0;k<9;k++)
                                        num_map[i][j][k]=0;
                        }
                }
        }

    void Sudoku::GiveQuestion(){
        int temp,a,b,c,d,e,f,g,h,i;        int check[9];
        for(int i=0;i<9;i++)
            check[i]=0;
        srand(time(NULL));
        for(int j=0;j<9;j++)
        {
            int k=rand()%9+1;
            if(check[k-1]==0)
            {
                check[k-1]=1;

                switch(j)
                {
                    case 0:a=k;
                    case 1:b=k;
                    case 2:c=k;
                    case 3:d=k;
                    case 4:e=k;
                    case 5:f=k;
                    case 6:g=k;
                    case 7:h=k;
                    case 8:i=k;
                }
            }
            else j--;
        }

        int map[9][9]={
        {h,i,g,b,c,a,e,f,d},
        {b,c,a,e,f,d,h,i,g},
        {e,f,d,h,i,g,b,c,a},
        {g,h,i,a,b,c,d,e,f},
        {a,b,c,d,e,f,g,h,i},
        {d,e,f,g,h,i,a,b,c},
        {i,g,h,c,a,b,f,d,e},
        {c,a,b,f,d,e,i,g,h},
        {f,d,e,i,g,h,c,a,b}
        };

        for(int x=0;x<9;x++)
        {
            int num=rand()%5+1;
            for(int y=0;y<num;y++)
            {
                int xx=rand()%9;
                map[xx][x]=0;
            }
        }


        for(int q=0;q<9;q++)
        {
            for(int w=0;w<9;w++)
            {
                cout<<map[q][w]<<" ";
            }
            cout<<'\n';
        }

    }
    void Sudoku::ReadIn()
    {
        int x,y;
        cout<<"Enter a Sudoku:"<<endl;
        for(y=0;y<9;y++)
        {
              scanf("%d%d%d%d%d%d%d%d%d",&map[y][0],&map[y][1],&map[y][2],&map[y][3],&map[y][4],&map[y][5],&map[y][6],&map[y][7],&map[y][8]);
        }
    }
        void Sudoku::find_possible()
    {
        int count[9],xx,yy,sum=0;
        for(int i=0;i<9;i++)
            count[i]=1;

        for(int y=0;y<9;y++)
        {
            for(int x=0;x<9;x++)
            {
                //for(int i=0;i<9;i++)
                    //cout<<"x:"<<x<<" y:"<<y<<" count:"<<count[i]<<" ";
                //system("pause");
                if(map[y][x]==0)
                {
                    for(int k=0;k<9;k++)
                    {
                        if(map[y][k]!=0)
                            count[map[y][k]-1]=0;
                        //cout<<"count[map[y][k]-1]:"<<count[map[y][k]-1]<<" "<<"map[y][k]:"<<map[y][k]<<" ";
                        //system("pause");
                    }
                    for(int k=0;k<9;k++)
                    {
                        if(map[k][x]!=0)
                            count[map[k][x]-1]=0;
                        //cout<<"count[map[k][x]-1]:"<<count[map[k][x]-1]<<" "<<"map[k][x]:"<<map[k][x]<<" ";
                        //system("pause");
                    }
                    //
                    //for(int i=0;i<9;i++)
                       //cout<<count[i]<<" ";
                    //cout<<endl;
                    //
                    xx=x/3;
                    yy=y/3;
                    for(int i=yy*3;i<=yy*3+2;i++)
                    {
                        for(int j=xx*3;j<=xx*3+2;j++)
                        {
                            if(map[i][j]!=0)
                                count[map[i][j]-1]=0;
                            //cout<<"count[map[i][j]-1]:"<<count[map[i][j]-1]<<" "<<"map[i][j]:"<<map[i][j]<<" ";
                            //system("pause");
                        }
                    }
                    for(int i=0;i<9;i++)
                    {
                        sum=sum+count[i];
                        sum_map[y][x]=sum;
                        if(count[i]==1)
                            num_map[y][x][i]=1;

                    }
                    for(int i=0;i<9;i++)
                        count[i]=1;
                    sum=0;
                }

                //
                //cout<<"X:"<<x<<" Y:"<<y<<" sum map:"<<sum_map[x][y]<<"Map:"<<map[x][y];
                //system("pause");
                //
            }
        }
        /*for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<sum_map[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<"-----------"<<endl;*/

    }
        int Sudoku::check(int x,int y,int num)
    {
        for(int i=0;i<9;i++)
            if(map[y][i]==num)
                return 0;
        for(int i=0;i<9;i++)
            if(map[i][x]==num)
                return 0;
        int xx=x/3;
        int yy=y/3;
        for(int i=yy*3;i<=yy*3+2;i++)
        {
            for(int j=xx*3;j<=xx*3+2;j++)
            {
                if(map[i][j]==num)
                return 0;
            }
        }
        return 1;
    }
    int Sudoku::fill()
    {
        int temp,count=0,undo=0;
        while(1)
        {
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                    new_sum[i][j]=sum_map[i][j];
            }

            for(int y=0;y<9;y++)
            {
                for(int x=0;x<9;x++)
                {
                    if(sum_map[y][x]==1)
                    {
                        for(int z=0;z<9;z++)
                        {
                            //cout<<num_map[y][x][z]<<" "<<" y:"<<y<<" x:"<<x<<" z:"<<z<<endl;
                                //system("pause");
                            if(num_map[y][x][z]==1)
                            {
                                map[y][x]=z+1;
                                temp=z;
                                //cout<<"IN:"<<map[y][x]<<endl;
                            }
                        }
                        //cout<<"**************************";
                        for(int i=0;i<9;i++)
                        {
                                if(num_map[y][i][temp]==1)

                                {
                                    num_map[y][i][temp]=0;
                                    new_sum[y][i]=sum_map[y][i]-1;
                                    /*if(y==0 && i==3)
                                        cout<<"a";*/
                                }
                                    //cout<<"Y:"<<y<<" X:"<<x<<" i:"<<i<<" temp:"<<temp<<" num_map:"<<num_map[y][i][temp]<<" sum:"<<sum_map[y][i]<<endl;
                                    //system("pause");
                        }
                        for(int i=0;i<9;i++)
                        {
                                if(num_map[i][x][temp]==1)
                                {
                                    num_map[i][x][temp]=0;
                                    new_sum[i][x]=sum_map[i][x]-1;
                                    /*if(i==0 && x==3)
                                    {
                                        cout<<"b";
                                        cout<<"Y:"<<y<<" X:"<<x<<" i:"<<i<<" temp:"<<temp<<" num_map:"<<num_map[i][x][temp]<<" sum:"<<sum_map[i][x]<<endl;
                                    }*/
                                }
                                    //cout<<"Y:"<<y<<" X:"<<x<<" i:"<<i<<" temp:"<<temp<<" num_map:"<<num_map[i][x][temp]<<" sum:"<<sum_map[i][x]<<endl;
                                    //system("pause");
                        }
                        int xx=x/3;
                        int yy=y/3;
                        for(int i=yy*3;i<=yy*3+2;i++)
                        {
                            for(int j=xx*3;j<=xx*3+2;j++)
                            {
                                if(num_map[i][j][temp]==1)
                                {
                                    num_map[i][j][temp]=0;
                                    new_sum[i][j]=sum_map[i][j]-1;
                                    /*if(i==0 && j==3)
                                    {
                                        cout<<"c";
                                        cout<<"Y:"<<y<<" X:"<<x<<" i:"<<i<<" j:"<<j<<" temp:"<<temp<<" num_map:"<<num_map[i][j][temp]<<" sum:"<<sum_map[i][j]<<endl;
                                    }*/
                                }
                                //cout<<"Y:"<<y<<" X:"<<x<<" i:"<<i<<" j:"<<j<<" temp:"<<temp<<" num_map:"<<num_map[i][j][temp]<<" sum:"<<sum_map[i][j]<<endl;
                                //system("pause");
                            }
                        }
                    }
                }
            }
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                    sum_map[i][j]=new_sum[i][j];
            }
            /*cout<<"s------------"<<endl;
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    cout<<sum_map[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"n------------"<<endl;
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    cout<<new_sum[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"------------"<<endl;
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    cout<<map[i][j]<<" ";
                }
                cout<<endl;
            }
            cout<<"------------"<<endl;*/
            for(int m=0;m<9;m++)
            {
                for(int n=0;n<9;n++)
                {

                    //cout<<count<<endl;
                    if(sum_map[m][n]==1)
                    {
                        count++;

                    }
                }
            }

            //cout<<count<<endl;
            if(count==0)
                break;
            count=0;

            for(int i=0;i<9;i++)
                        {
                           for(int j=0;j<9;j++)
                                {
                                     //cout<<count<<endl;
                                       if(map[i][j]==0)
                                      {
                                    undo++;
                                        }
                        }
                        }
        /*for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    result_map[i][j]=map[i][j];
                    //cout<<result_map[i][j]<<" ";
                }
                //cout<<endl;
            }
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<map[i][j]<<" ";
            }
           cout<<endl;
        }
        cout<<"------------"<<endl;*/
        if(undo!=0) return undo;
        else return 0;
        }
    }
        void Sudoku::fill_max()
    {
        int sum=0;
        if(ans[0] > 2)
            return;
        for(int y=0;y<9;y++)
        {
            for(int x=0;x<9;x++)
            {
                if(map[y][x]!=0)
                    sum++;
            }
        }
        //cout<<sum<<endl;
        //system("pause");
        if(sum==81)
        {

            ans[0]++;
            //cout<<ans[0]<<endl;
            if(ans[0] == 2)
            {
                cout<<"2"<<endl;
                return;
            }
            for(int i=0;i<9;i++)
            {
                for(int j=0;j<9;j++)
                    result_map[i][j]=map[i][j];
            }
            /*for(int i=0;i<9;i++)
                {
                    for(int j=0;j<9;j++)
                    {
                        cout<<result_map[i][j]<<" ";
                    }
                    cout<<endl;
                }*/
            return;
        }
        for(int y=0;y<9;y++)
        {
            for(int x=0;x<9;x++)
            {
                if(map[y][x]==0)
                {
                    for(int z=0;z<9;z++)
                    {
                        if(num_map[y][x][z]==1)
                        {
                            if(check(x,y,z+1)==1)
                            {
                                map[y][x]=z+1;
                                fill_max();
                                map[y][x]=0;
                            }
                        }
                    }
                    return;
                }

            }
        }

    }
        int Sudoku::Solve()
    {
        int check=0;
        find_possible();
        //check=fill();
        if(1/*check!=0*/)
        {
            fill_max();
            if(ans[0] == 0)
                cout<<"0"<<endl;
            else if(ans[0] == 1)
            {
               cout<<"1"<<endl;
                for(int i=0;i<9;i++)
                {
                    for(int j=0;j<9;j++)
                    {
                        cout<<result_map[i][j]<<" ";
                    }
                    cout<<endl;
                }
            }
        }
        /*else if(check==0)
        {
            cout<<"1"<<endl;
            for(int i=0;i<9;i++)
                {
                    for(int j=0;j<9;j++)
                    {
                        cout<<result_map[i][j]<<" ";
                    }
                    cout<<endl;
                }
        }
*/
    }
