#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Sudoku.h"

using namespace std;

void Sudoku::set_zero()
{
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            column[i][j]=row[i][j]=cell[i][j]=0;
        }
    }
    cnt=0;
    boom=0;
    lala=0;
}

void Sudoku::ReadIn()
{
    int i;
    set_zero();
    for(i=0;i<81;i++){
        cin >> sudoku[i];
        DD[i]=0;
        if(sudoku[i]>0 && sudoku[i] <10){
            row[i/9][sudoku[i]]++;
            column[i%9][sudoku[i]]++;
            cell[(i/27)*3+(i%9)/3][sudoku[i]]++;
            DD[i]++;
        }
        else if (sudoku[i])lala++;
    }
}

void Sudoku::Btracking(int n)
{
    int i;
    if(boom) return;
    if(n==81){
        for(i=0;i<81;i++){
            ans[i]=sudoku[i];
        }
        cnt++;
        if(cnt==2) boom++;
        return;
    }
    if(DD[n]){
        Btracking(n+1);
        return;
    }
    for(i=1;i<=9;i++){
        if(!row[n/9][i] && !column[n%9][i] && !cell[(n/27)*3+(n%9)/3][i]){
            sudoku[n]=i;
            row[n/9][i]++;
            column[n%9][i]++;
            cell[(n/27)*3+(n%9)/3][i]++;
            Btracking(n+1);
            row[n/9][i]--;
            column[n%9][i]--;
            cell[(n/27)*3+(n%9)/3][i]--;
        }
    }
}

void Sudoku::print_ans()
{
    int i;
    if(!cnt) cout << "0" << endl;
    else if(cnt==1){
        cout << "1" << endl;
        for(i=0;i<81;i++){
            cout << ans[i];
            if(i%9==8){
                cout << endl;
            }
            else cout << " ";
        }
    }
    else cout << "2" << endl;
}

void Sudoku::Solve()
{
    if(lala){
        puts("0");
        return;
    }
    Btracking(0);
    print_ans();
}

void Sudoku:: GiveQuestion()
{
    int i;
    srand(time(NULL));
    int QUE[4][81]={
        {
        5,0,0,0,0,0,0,3,2,
        0,9,0,0,4,6,0,0,0,
        3,0,0,0,0,0,0,0,0,
        0,0,0,1,0,0,7,0,0,
        0,7,0,0,2,0,0,4,0,
        0,0,9,0,0,4,0,0,0,
        0,0,0,0,0,0,0,0,3,
        0,0,0,5,8,0,0,2,0,
        6,1,0,0,0,2,0,0,8
        },
        {
        5,0,0,0,0,0,0,0,9,
        0,2,0,1,0,0,0,7,0,
        0,0,8,0,0,0,3,0,0,
        0,4,0,0,0,2,0,0,0,
        0,0,0,0,5,0,0,0,0,
        0,0,0,7,0,6,0,1,0,
        0,0,3,0,0,0,8,0,0,
        0,6,0,0,0,4,0,2,0,
        9,0,0,0,0,0,0,0,5
        },
        {
        5,0,0,0,0,0,0,0,9,
        0,2,0,1,0,0,0,7,0,
        0,0,8,0,0,0,3,0,0,
        0,4,0,7,0,2,0,0,0,
        0,0,0,0,5,0,0,0,0,
        0,0,0,0,0,6,0,1,0,
        0,0,3,0,0,0,8,0,0,
        0,6,0,0,0,4,0,2,0,
        9,0,0,0,0,0,0,0,5
        },
        {
        4,0,0,8,0,6,0,0,0,
        0,0,0,0,0,0,0,3,0,
        0,0,0,0,0,0,8,1,0,
        1,0,7,0,0,5,0,0,0,
        9,0,0,0,2,0,0,0,0,
        0,0,0,3,0,0,2,0,9,
        0,7,3,0,0,0,0,0,0,
        0,1,0,0,0,0,0,0,0,
        0,0,0,4,0,2,0,0,7
        }

    };
    int tmp=rand()%4;
    for(i=0;i<81;i++){
        cout << QUE[tmp][i];
        if(i%9==8) cout << endl;
        else cout << " ";
    }
}
