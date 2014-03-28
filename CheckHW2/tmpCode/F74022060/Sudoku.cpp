#include"Sudoku.h"
#include <stdlib.h>
#include<cstdio>
#include<cstring>
#include<ctime>
void Sudoku::GiveQuestion()
{
    srand(time(NULL));
    int i=rand()%5;
    switch(i)
    {
    case 1:
        printf("4 0 0 0 0 3 0 0 0\n\
0 6 0 0 0 0 0 9 0\n\
0 0 0 0 0 0 0 0 0\n\
0 0 0 0 0 0 0 0 3\n\
0 5 0 8 6 0 0 0 0\n\
0 0 8 0 0 2 0 0 1\n\
0 0 0 0 0 0 0 0 2\n\
0 0 0 0 0 0 6 5 0\n\
3 0 1 0 0 4 0 0 0\n");
        break;
    case 2:
        printf("4 0 0 0 0 3 0 0 0\n0 6 0 0 0 0 0 9 0\n0 0 0 0 0 0 0 0 0\n0 0 0 0 0 0 0 0 3\n0 5 0 6 8 0 0 0 0\n0 0 8 0 0 2 0 0 1\n0 0 0 0 0 0 0 0 2\n0 0 0 0 0 0 6 5 0\n3 0 1 0 0 4 0 0 0\n");
        break;
    case 3:
        printf("0 0 5 0 0 0 0 0 9\n0 0 0 0 0 0 0 0 0\n7 0 0 6 0 0 1 0 0\n0 0 0 0 0 4 0 0 0\n0 0 0 0 5 9 0 0 3\n2 0 0 0 0 0 0 7 0\n0 0 9 0 0 8 0 0 0\n0 0 0 7 0 0 2 6 0\n0 0 4 0 0 0 0 0 0\n");
        break;
    case 4:
        printf("0 2 3 0 0 0 0 5 0\n0 0 0 0 0 0 9 0 0\n0 0 0 4 0 0 0 0 0\n0 0 0 6 0 0 0 0 0\n0 0 1 0 0 0 0 3 2\n4 0 0 9 0 8 0 0 0\n0 0 0 0 3 7 0 0 0\n0 0 0 0 0 0 0 0 0\n9 0 4 0 0 0 8 0 0\n");
        break;
    case 0:
        printf("0 0 0 0 0 0 0 0 9\n0 0 0 1 0 0 0 0 0\n8 7 0 2 0 0 0 0 0\n0 2 0 0 0 0 0 0 0\n0 0 0 0 0 5 0 8 0\n0 0 4 0 9 0 0 0 0\n5 0 9 0 0 0 0 0 0\n6 0 0 0 0 0 0 0 4\n0 0 0 3 4 0 0 2 0\n");
        break;
    }
}
void Sudoku::ReadIn()
{
    superflag=0;
    for(int i=0;i<9;i++)
    for(int j=0;j<9;j++){
        for(int hihi=1;hihi<=9;hihi++)
        psb2[i][j][hihi]=0;
        psb[i][j]=9;
        mapping[i][j]=0;
        if(i%3==0&&j%3==0)
            for(int a=1;a<=9;a++)
                aqr[i/3][j/3][a]=0;
        }
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
            if(!mapping[i][j])
                scanf("%d",&mapping[i][j]);
            else{
                int tmp;
                scanf("%d",&tmp);
                if(tmp&&tmp!=mapping[i][j])
                    superflag=1;
                continue;
            }
            if(mapping[i][j]&&!superflag){
                aqr[i/3][j/3][mapping[i][j]]=1;
                psb[i][j]=-1;
                for(int x=0;x<9;x++)
                {
                    if(!psb2[x][j][mapping[i][j]])
                    {
                        psb[x][j]--;
                        psb2[x][j][mapping[i][j]]=1;
                        if(!psb[x][j])
                            ck(x,j);
                    }
                }
                for(int y=0;y<9;y++)
                {
                    if(!psb2[i][y][mapping[i][j]])
                    {
                        psb[i][y]--;
                        psb2[i][y][mapping[i][j]]=1;
                        if(!psb[i][y])
                        ck(i,y);
                    }
                }
            }
        }
        return;
}
void Sudoku::Solve()
{
    if(superflag)
    {
        puts("0");
        return;
    }
    flag=0;
    BT(0,0);
    if(flag==1){
        puts("1");
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<8;j++)
            {
                printf("%d ",ansmapping[i][j]);
            }
            printf("%d\n",ansmapping[i][8]);
        }}
    else if (flag==2)   puts("2");
    else puts("0");
    return;
}
void Sudoku::BT(int x,int y)
{
    if(mapping[x][y]){
        BT(x,y+1);
        return;
    }
    if(x==9)
    {
        flag++;
        if(flag==1)
            memcpy(ansmapping,mapping,sizeof(mapping));
        return;
    }
    if(y==9){
        BT(x+1,0);
        return;
    }
    for(int a=1;a<=9;a++)
    {
        if(aqr[x/3][y/3][a])
            goto nxt;
        for(int i=0;i<9;i++)
            if(mapping[i][y]==a)
                goto nxt;
        for(int j=0;j<9;j++)
            if(mapping[x][j]==a)
                goto nxt;
        mapping[x][y]=a;
        aqr[x/3][y/3][a]=1;
        BT(x,y+1);
        if(flag>1)
            return;
        mapping[x][y]=0;
        aqr[x/3][y/3][a]=0;
        nxt:;
    }
    return;
}
void Sudoku::ck(int x,int y)
{
    for(int a=1;a<=9;a++)
        if(!psb2[x][y][a])
        {
        mapping[x][y]=a;
        aqr[x/3][y/3][a]=1;
        psb[x][y]=-1;
        for(int i=0;i<9;i++)
            if(!psb2[i][y][a])
            {
                psb[i][y]--;
                psb2[i][y][a]=1;
                if(!psb[i][y])
                    ck(i,y);
            }
        for(int i=0;i<9;i++)
        if(!psb2[x][i][a])
        {
            psb[x][i]--;
            psb2[x][i][a]=1;
            if(!psb[x][i])
                ck(x,i);
        }
        return;
        }
    return;
}
