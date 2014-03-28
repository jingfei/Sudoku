#include "Sudoku.h"
#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;

int Arto_InkalaTemplate[81]={
        8,0,0,0,0,0,0,0,0,
        0,0,3,6,0,0,0,0,0,
        0,7,0,0,9,0,2,0,0,
        0,5,0,0,0,7,0,0,0,
        0,0,0,0,4,5,7,0,0,
        0,0,0,1,0,0,0,3,0,
        0,0,1,0,0,0,0,6,8,
        0,0,8,5,0,0,0,1,0,
        0,9,0,0,0,0,4,0,0
};
int Hard17ClueTemplate[81]={
        0,0,2,0,9,0,3,0,0,
        8,0,5,0,0,0,0,0,0,
        1,0,0,0,0,0,0,0,0,
        0,9,0,0,6,0,0,4,0,
        0,0,0,0,0,0,0,5,8,
        0,0,0,0,0,0,0,0,1,
        0,7,0,0,0,0,2,0,0,
        3,0,0,5,0,0,0,0,0,
        0,0,0,1,0,0,0,0,0
};


Sudoku::Sudoku(){
        for(int i=0; i<sudokuSize; ++i)
                map[i] = 0;
        ans=0;
}
Sudoku::Sudoku(const int init_map[]){
        for(int i=0; i<sudokuSize; ++i)
                map[i] = init_map[i];
        ans=0;
}

void Sudoku::setMap(const int set_map[]){
        for(int i=0; i<sudokuSize; ++i)
                map[i] = set_map[i];
}

int Sudoku::getElement(int index){
        return map[index];
}

int Sudoku::pow2(int x){
        switch(x){
                case 1:
                        return 2;
                case 2:
                        return 4;
                case 3:
                        return 8;
                case 4:
                        return 16;
                case 5:
                        return 32;
                case 6:
                        return 64;
                case 7:
                        return 128;
                case 8:
                        return 256;
                case 9:
                        return 512;
                default:
                        return 0;
        }
}

void Sudoku::setElement(int index, int value){
        map[index] = value;
}

int Sudoku::getFirstZeroIndex(){
        for(int i=0;i<sudokuSize;++i)
                if(map[i] == 0)
                        return i;
        return -1;
}

void Sudoku::ReadIn(){
        int input;
        for(int i=0;i<81;i++){
                cin>>input;
                setElement(i,input);
        }
}

void Sudoku::GiveQuestion(){
        srand(time(NULL));
        int seed=rand()%9;
        int reverse=rand()%3;
        if(reverse==0){
                for(int i=0;i<81;i+=9){
                        for(int j=0;j<9;j++){
                                if(Hard17ClueTemplate[i+j]==0)
                                        cout<<"0";
                                else if(Hard17ClueTemplate[i+j]==(9-seed))
                                        cout<<"9";
                                else
                                        cout<<(Hard17ClueTemplate[i+j]+seed)%9;
                                if(j==8)
                                        cout<<endl;
                                else
                                        cout<<" ";
                        }
                }
        }else if(reverse==1){
                for(int i=0;i<9;i++){
                        for(int j=0;j<9;j++){
                                if(Hard17ClueTemplate[i+9*j]==0)
                                        cout<<"0";
                                else if(Hard17ClueTemplate[i+9*j]==(9-seed))
                                        cout<<"9";
                                else
                                        cout<<(Hard17ClueTemplate[i+9*j]+seed)%9;
                                if(j==8)
                                        cout<<endl;
                                else
                                        cout<<" ";
                        }
                }
        }else{
                for(int i=8;i>=0;i--){
                        for(int j=0;j<9;j++){
                                if(Hard17ClueTemplate[i+9*j]==0)
                                        cout<<"0";
                                else if(Hard17ClueTemplate[i+9*j]==(9-seed))
                                        cout<<"9";
                                else
                                        cout<<(Hard17ClueTemplate[i+9*j]+seed)%9;
                                if(j==8)
                                        cout<<endl;
                                else
                                        cout<<" ";
                        }
                }
        }

}

bool Sudoku::recurSolve(){
        int rowUpper, rowLower, colUpper, colLower, cellFirst, check;
        int firstZero = getFirstZeroIndex();
        if(firstZero == -1){
                if(isCorrect()){
                        ans++;
                        if(ans>1)
                                return true;
                        for(int i=0;i<81;i++)
                                tempMap[i]=map[i];
                        return false;


                }
                else{
                        return false;
                }
        }
        else{
                for(int i=1;i<=9;++i){
                        check=1;
                        rowLower=firstZero-firstZero%9;
                        colLower=firstZero%9;
                        cellFirst=rowLower-rowLower%27+3*(colLower/3);
                        for(int j=0;j<9;j++){
                                if(map[rowLower+j]==i)
                                        check=check*0;
                                if(map[colLower+9*j]==i)
                                        check=check*0;

                                if(map[cellFirst+(j/3)*9+j%3]==i)
                                        check=check*0;
                        }
                        if(check==0)
                                i=i;
                        else{
                                setElement(firstZero,i);
                                if(recurSolve()){
                                        return true;
                                }


                        }
                        setElement(firstZero,0);
                }
                return false;
        }

}

bool Sudoku::isCorrect(){
        int checkRow, checkCol, checkCell;
        for(int i=0;i<9;i++){
                checkRow=0;
                checkCol=0;
                checkCell=0;
                for(int j=0;j<9;j++){
                        checkRow=checkRow+pow2(map[9*i+j]);
                        checkCol=checkCol+pow2(map[i+9*j]);
                        checkCell=checkCell+pow2(map[27*(i/3) + 3*(i%3)+9*( j/3) + ( j%3)]);
                }
                if(checkRow!=1022 || checkCol!=1022 || checkCell!=1022)
                        return false;
        }
        return true;
}

void Sudoku::Solve(){
        recurSolve();
        if(ans==0){
                cout<<"0"<<endl;
        }
        else if(ans==1){
                cout<<"1"<<endl;
                        for(int i=0;i<81;i++){
                                cout<<tempMap[i];
                                if(i%9==8)
                                        cout<<endl;
                                else
                                        cout<<" ";
                        }
        }
        else
                cout<<"2"<<endl;

}