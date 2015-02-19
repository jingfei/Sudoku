#include"Sudoku.h"
#include<iostream>
#include<cstdlib>
#include<fstream>
#include<ctime>

using namespace std;

Sudoku::Sudoku(){
    for(int i= 0; i< 81; i++){
        element2[i]= 0;
        for(int j= 0; j< 9; j++)
            possible[i][j]= j+1;
    }
    coun= 0;
}



void Sudoku::GiveQuestion(){
    int a, b, i, j, k, x, y;

    srand(time(NULL));
    a= rand()%N+1;
    b= a;
    for(i= 0; i< N; i++){
        b= a;
        for(j= 0; j< N; j++){
            group[i][j]=(b >9)? b%N : b;
        b++;
        }
    }
    mapping(0);

    for(i= 0; i< N; i++)
        for(j= 0; j< N; j++)
            switch(element2[i*N+j]){
            case 1:element2[i*N+j]= group[i][0];
                    break;
            case 2:element2[i*N+j]= group[i][1];
                    break;
            case 3:element2[i*N+j]= group[i][2];
                    break;
            case 4:element2[i*N+j]= group[i][3];
                    break;
            case 5:element2[i*N+j]= group[i][4];
                    break;
            case 6:element2[i*N+j]= group[i][5];
                    break;
            case 7:element2[i*N+j]= group[i][6];
                    break;
            case 8:element2[i*N+j]= group[i][7];
                    break;
            case 9:element2[i*N+j]= group[i][8];
                    break;
        }
        hollow();

    ofstream fout("stdout.txt", ios::out);

    for(i= 0; i< 9; i++){
        for(j= 0; j< 9; j++)
            fout<<element2[i+j*9]<<" ";
    fout<<endl;
    }
    return;
}


void Sudoku::ReadIn(){
    int element_count= 0, tem_m[SudokuSize];

    ifstream fin("stdin.txt", ios::in);

    while(fin>>tem_m[element_count++]){
        if(element_count > SudokuSize){
            cout<<"Wrong input file!!"<<endl;
            exit(1);
        }
    }
    for(int i= 0; i< SudokuSize; i++)
        element1[i]= tem_m[i];
}




void Sudoku::Solve(){
    int i, j, k;
//Possible number=========================================================
    for(i= 1; i<= N; i++)
        for(j= 0; j< SudokuSize; j++)
            if(element1[j] == i){
                for(k= 0; k< N; k++){
                    possible[j][k]= 0;
                    possible[(j/N)*N+k][i-1]= 0;
                    possible[j%N+N*k][i-1]= 0;
                }
                possible[j][i-1]= i;
            }
//New possible numbew======================================================
    for(i= 0; i< SudokuSize; i++){
        k= 0;
        for(j= 0; j< N; j++){
            newPossible[i][j]= 0;
            if(possible[i][j] != 0){
                newPossible[i][k]= possible[i][j];
                k++;
            }
        }
        possibleCount[i]= k;
    }

//Determine===============================================================================
    ofstream fout("stdout.txt", ios::out);

    if(fillInForward(0) == 0){fout<<"0"<<endl; return;}

    coun= 0;
    fillInBackward(0);

    for(i= 0; i< SudokuSize-1; i++) if(element1[i] != element2[i]){fout<<"2"<<endl; return;}

    fout<<"1"<<endl;
    for(i= 0; i< N; i++){
        for(j= 0; j< N; j++)
            fout<<element1[i*N+j]<<" ";
        fout<<endl;
    }
    return;
}


//Fill In Forward==========================================================================
int Sudoku::fillInForward(int i)
{
    int j;

    if(coun == SudokuSize)return 1;

    if(newPossible[i][0] == 0) return 0;

    for(j= 0; j< possibleCount[i]; j++){
        if (check(element1, i, newPossible[i][j]) == true){
            element1[i]= newPossible[i][j];
            coun++;
            fillInForward(++i);
            if(coun == SudokuSize) return 1;

            element1[i--]= 0;
            coun--;
        }
    }
}


//Fill in Backward========================================================================
int Sudoku::fillInBackward(int i)
{
    int j;

    if(coun == SudokuSize) return 1;

    if(newPossible[i][0] == 0) return 0;

    for(j= possibleCount[i]; j>= 0; j--){
        if (check(element2, i, newPossible[i][j]) == true){
            element2[i]= newPossible[i][j];
            coun++;
            fillInBackward(++i);
            if(coun == SudokuSize) return 1;

            element2[i--]= 0;
            coun--;
        }
    }
}



void Sudoku::mapping(int i)
{
    int j;

    if(coun == SudokuSize) return;

    for(j= 0; j< N; j++){
        if (check(element2, i, possible[i][j]) == true){
            element2[i]= possible[i][j];
            coun++;
            mapping(++i);
            if(coun == SudokuSize) return;

            element2[i--]= 0;
            coun--;
        }
    }
}



void Sudoku::hollow()
{
   int a, i, j;
   srand(time(NULL));
   coun= 0;

   while(coun < 50){
    a= rand()%81;
    if(element2[a] == 0) continue;
    element2[a]= 0;
    coun++;
   }
    return;
}




bool Sudoku::check(int element[], int n, int a)
{
    int x, y, x1, y1;
    x= n%N; y= n/N;

    if(x < 3) x1= 0;
    if(x >= 3 && x < 6) x1= 3;
    if(x >= 6) x1= 6;
    if(y < 3) y1= 0;
    if(y >= 3 && y < 6) y1= 3;
    if(y >= 6) y1= 6;

    for(int i= x1; i< x1+3; i++)
        for(int j= y1; j< y1+3; j++)
            if( ((x != i)&&(y != j)) && (element[i+N*j] == a)) return false;

    for(int i= 0; i< N; i++)
        if(((N*y+i != n) && (element[N*y+i] == a)) || ((x+N*i != n) && (element[x+N*i] == a))) return false;

    return true;
}
