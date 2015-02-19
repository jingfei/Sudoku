#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdlib>
#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku(void){
    for (int i=0; i<SudokuSize; i++){
        s[i] = 0;
        solve[i] = 0;
        row[i] = 0;
        col[i] = 0;
        cel[i] = 0;
        if (i>64) continue;
        zero[i] = 0;
        zero_stack[i] = 0;
    }
    number = 0;
    check = 1;
    finish = 0;
}
void Sudoku::GiveQuestion(void){
    //據說是世界最難數獨
    int a[SudokuSize] = {8,0,0,0,0,0,0,0,0,
                         0,0,3,6,0,0,0,0,0,
                         0,7,0,0,9,0,2,0,0,
                         0,5,0,0,0,7,0,0,0,
                         0,0,0,0,4,5,7,0,0,
                         0,0,0,1,0,0,0,3,0,
                         0,0,1,0,0,0,0,6,8,
                         0,0,8,5,0,0,0,1,0,
                         0,9,0,0,0,0,4,0,0};
    srand(time(NULL));
    int turn = rand()%5;
    int turn_row;
    int turn_col;
    int turn_space;
    int temp;
    //隨機排列
    for (int i=0; i<turn; i++){
        turn_row = rand()%3;
        turn_col = rand()%3;
        turn_space = rand()%2;

        for(int j=0+(turn_row*27); j<9+(turn_row*27); j++){
            temp = a[j];
            a[j] = a[j+9];
            a[j+9] = temp;
        }
        for(int j=0+turn_col*3; j<81+turn_col*3; j = j+9){
            temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
        }
        for(int j=0+turn_space*27; j<27+turn_space*27; j++){
            temp = a[j];
            a[j] = a[j+27];
            a[j+27] = temp;
        }
    }
    //印出
    for (int j=0; j<SudokuSize; j++){
        cout << a[j] << " ";
        if (j%9 == 8) cout <<endl;
    }
    return;
}
void Sudoku::ReadIn(void){
    //ReadIn 同時檢查是否合法(不檢查多組解)
    for (int i=0; i<SudokuSize; i++){
        cin >> s[i];
        //設定0的位置stack
        if (s[i]==0){
            zero[number] = i;
            number++;
        }
        //判斷是否違規
        else    Check(i);
        if (check == 0) return;
    }
    //判斷是否過少資訊
    if (number > 64)
        check = 2;
    return;
}
void Sudoku::Solve(void){
    // 0:無解 1:一解 2:多解
    // 先判斷ReadIn有沒有發現錯誤
    if (check == 0){
        cout << check;
        return;
    }
    if (check == 2){
        cout << check;
        return;
    }
    //如果都沒有0
    if (number == 0){
        cout << check << endl;
        for (int i=0; i<SudokuSize; i++){
            cout << s[i] << " ";
            if (i%9 == 8) cout << endl;
        }
        return;
    }


    //開始實際解
    for (int i=0; i<SudokuSize; i++){
        init_row[i] = row[i];
        init_col[i] = col[i];
        init_cel[i] = cel[i];
    }
    number--;
    int total = number;     //判斷是否無解
    int index;
    while(number > -1){
        index = zero[number];
        for (int i=zero_stack[number]; i<9; i++){
            check = 1;
            s[index] = i+1;
            zero_stack[number] = i+1;
            Check(index);
            if (check == 1) break;
        }
        if(check == 0){
            Back(index,total);
            if (finish == 2) return;
        }
        else number--;
    }
    //判斷多組解
    finish = 1;
    number++;
    index = zero[number];
    for (int i=0; i<SudokuSize; i++)
        solve[i] = s[i];
    int locationrow = (index/9)*9 + s[index]-1;
    int locationcol = (index%9)*9 + s[index]-1;
    int locationcel = 27*((index/9)/3)  + 9*((index%9)/3) + s[index]-1;
    row[locationrow] = init_row[locationrow];
    col[locationcol] = init_col[locationcol];
    cel[locationcel] = init_cel[locationcel];

    if(solve[index] == 9) check = 0;

    while(number > -1){
        index = zero[number];
        for (int i=zero_stack[number]; i<9; i++){
            check = 1;
            s[index] = i+1;
            zero_stack[number] = i+1;
            Check(index);
            if (check == 1) break;
        }
        if(check == 0){
            Back(index,total);
            if (finish==2)return;
        }
        else number--;
    }

    cout << 2;

    return;
}
void Sudoku::Check(int i){
    int locationrow = (i/9)*9 + s[i]-1;
    int locationcol = (i%9)*9 + s[i]-1;
    int locationcel = 27*((i/9)/3)  + 9*((i%9)/3) + s[i]-1;

    if ( row[locationrow] == 1 || col[locationcol] == 1 || cel[locationcel] == 1){
        check = 0;
        return;
    }
    else {
        row[locationrow] = 1;
        col[locationcol] = 1;
        cel[locationcel] = 1;
    }
    return;
}
void Sudoku::Back(int i, int total){
    zero_stack[number] = 0;
    s[i] = 0;
    number++;
    if (number > total && finish != 1){
        cout << 0;
        finish = 2;
        return;
    }
    else if(number > total){
        cout << 1 << endl;
        for (int j=0; j<SudokuSize; j++){
            cout << solve[j] << " ";
            if (j%9 == 8) cout <<endl;
        }
        finish = 2;
        return;
    }
    i = zero[number];
    int locationrow = (i/9)*9 + s[i]-1;
    int locationcol = (i%9)*9 + s[i]-1;
    int locationcel = 27*((i/9)/3)  + 9*((i%9)/3) + s[i]-1;
    row[locationrow] = init_row[locationrow];
    col[locationcol] = init_col[locationcol];
    cel[locationcel] = init_cel[locationcel];
    return;
}
