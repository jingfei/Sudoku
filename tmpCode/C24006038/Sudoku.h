#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct internal{
    int degree_of_freedom;
    int possibility[10];
    int main_number;

}DelTa;
typedef struct arreY{
    int I_component;
    int J_component;
    int degree_of_freedom;

}precedence;

int solution_type = 0;
precedence precedence_arrey[81];
int solution_template[9][9] = {0};

class Sudoku{
public:
    Sudoku();
    void GiveQuestion();
    void ReadIn();
    void Solve();
private:
    DelTa basis[9][9];

    //------------------------------------------
    void check_solvable();
    void chop_banned_freedom(int, int);
    int refresh_main_number(); //if executed, retuen(10*I + J)+1, else 0
    int Backtracking(int);
    //------------------------------------------
    int check_repeat_when_change(int, int);  //if repeated, return 1
    int row_repeat(int);
    int col_repeat(int);
    int block_repeat(int, int);
    void clean_inner_when_filled(int, int);
};
int QScompare(const void *,const void *);
Sudoku::Sudoku(){}
void Sudoku::GiveQuestion(){
    cout << "1";
}
void Sudoku::ReadIn(){
    int I, J;
    for(I=0;I<9;I++){
        for(J=0;J<9;J++){
            cin >> basis[I][J].main_number;
        }
    }
}
void Sudoku::Solve(){
    int I, J, K, temp;
    //-------------
    for(I=0;I<9;I++){
        for(J=0;J<9;J++){
            basis[I][J].degree_of_freedom = 9;
            for(K=0;K<9;K++) basis[I][J].possibility[K] = 1;
        }
    }
    //-------------
    check_solvable();
    for(I=0;I<9;I++){
        for(J=0;J<9;J++) {
            chop_banned_freedom(I, J);
            if(basis[I][J].main_number >0) clean_inner_when_filled(I,J);
        }
    }
    /*for(I=0;I<9;I++){
        for(J=0;J<9;J++) {
            cout << basis[I][J].degree_of_freedom << " ";
        }
        cout << endl;
    }
    cout<<"---------" << endl;*/
    while(1){
        temp = refresh_main_number(); // remember to clear struct inside to 0
        if(temp == 0) break;
        I = (temp-1)/10;
        J = (temp-1)%10;
        chop_banned_freedom(I, J);
    }
    //-------------------
    temp = 0;      //copy to prece arrey
    for(I=0;I<9;I++){
        for(J=0;J<9;J++){
            precedence_arrey[temp].degree_of_freedom = basis[I][J].degree_of_freedom;
            precedence_arrey[temp].I_component = I;
            precedence_arrey[temp].J_component = J;
            temp++;
        }
    }
    qsort(precedence_arrey, 81, sizeof(precedence), QScompare);
    /*for(I=0;I<81;I++)cout << precedence_arrey[I].degree_of_freedom << " ";
    cout << "\n--------------------\n";*/
    
    if(precedence_arrey[80].degree_of_freedom == 0){
        cout << 1 << endl;
        for(I=0;I<9;I++){
            for(J=0;J<9;J++){
                cout << basis[I][J].main_number << " ";
            }
            cout << endl;
        }
        exit(0);
    }
    //-------------------
    for(I=0;I<81;I++){
        if(precedence_arrey[I].degree_of_freedom > 0)  break;
    }
    //------------------------
    Backtracking(I); //start from smallest DoF
    /* check temp final */
    if(solution_type == 0){
        cout << 0<< "bysol" << endl;
        exit(0);
    }else if(solution_type == 1){
        cout << 1 << "bysol" << endl;
        for(I=0;I<9;I++){
            for(J=0;J<9;J++){
                cout << solution_template[I][J] << " ";
            }
            cout << endl;
        }
    }else{
        cout << 2<< "bysol" << endl;
        exit(0);
    }
}
int Sudoku::refresh_main_number(){//if executed, retuen(10*I + J)+1, else 0
    int I, J, K;
    for(I=0;I<9;I++){
        for(J=0;J<9;J++){
            if(basis[I][J].degree_of_freedom == 1){
                K=1;
                while(basis[I][J].possibility[K]==0) K++;
                basis[I][J].main_number = K;
                basis[I][J].possibility[K] = 0;
                basis[I][J].degree_of_freedom--;
                return 10*I + J + 1;
            }
        }
    }
    return 0;
}
void Sudoku::clean_inner_when_filled(int i, int j){
    basis[i][j].degree_of_freedom = 0;
    int K;
    for(K=0;K<10;K++){
        basis[i][j].possibility[K] = 0;
    }
}
int Sudoku::Backtracking(int I){
    int L, flag, II, JJ;
    if(I<80){
        L = 1;
        flag = 0;
        while(flag < basis[precedence_arrey[I].I_component][precedence_arrey[I].J_component].degree_of_freedom){
            for(;L<10;L++){
                if(basis[precedence_arrey[I].I_component][precedence_arrey[I].J_component].possibility[L]>0)
                    break;
            }
            basis[precedence_arrey[I].I_component][precedence_arrey[I].J_component].main_number = L;
            flag++;
            if(check_repeat_when_change(precedence_arrey[I].I_component, precedence_arrey[I].J_component)== 1)
                continue;
            Backtracking(I+1);
        }
        //basis[precedence_arrey[I].I_component][precedence_arrey[I].J_component].main_number = 0;
        return 1;
    }else{
        L = 1;
        flag = 0;
        while(flag < basis[precedence_arrey[I].I_component][precedence_arrey[I].J_component].degree_of_freedom){
            for(;L<10;L++){ //find non zero to fill
                if(basis[precedence_arrey[I].I_component][precedence_arrey[I].J_component].possibility[L]>0)
                    break;
            }
            basis[precedence_arrey[I].I_component][precedence_arrey[I].J_component].main_number = L;
            flag++;
            if(check_repeat_when_change(precedence_arrey[I].I_component, precedence_arrey[I].J_component)!= 1){
                solution_type++;
                if(solution_type > 1) return 0;
                for(II=0;II<9;II++){
                    for(JJ=0;JJ<9;JJ++){
                        solution_template[II][JJ] = basis[II][JJ].main_number;
                    }
                }
            }
        }
        //basis[precedence_arrey[I].I_component][precedence_arrey[I].J_component].main_number = 0;
        return 1;
    }
}
int QScompare(const void *a,const void *b){
    int A = ((precedence*)a) -> degree_of_freedom;
    int B = ((precedence*)b) -> degree_of_freedom;
    return A-B;
}
void Sudoku::chop_banned_freedom(int i, int j){
    int I, J, K, MaiN = basis[i][j].main_number;
    if(MaiN == 0) return;
    for(I=0;I<9;I++){
        basis[i][I].possibility[MaiN] = 0;
        basis[i][I].degree_of_freedom = 0;
        for(K=1;K<10;K++) basis[i][I].degree_of_freedom += basis[i][I].possibility[K];

        basis[I][j].degree_of_freedom = 0;
        basis[I][j].possibility[MaiN] = 0;
        for(K=1;K<10;K++) basis[I][j].degree_of_freedom += basis[I][j].possibility[K];
    }
    I = (i/3)*3;
    J = (j/3)*3;
    int II, JJ;
    for(II=0;II<3;II++){
        for(JJ=0;JJ<3;JJ++){
            basis[I+II][J+JJ].degree_of_freedom = 0;
            basis[I+II][J+JJ].possibility[MaiN] = 0;
            for(K=1;K<10;K++) basis[I+II][J+JJ].degree_of_freedom += basis[I+II][J+JJ].possibility[K];
        }
    }
    return;
}
int Sudoku::check_repeat_when_change(int i, int j){
    if(row_repeat(i)
       || col_repeat(j)
       || block_repeat(i,j)) return 1;
    return 0;
}
void Sudoku::check_solvable(){
    int I, J, temp = 0;
    //---------------------------------------
    for(I=0;I<9;I++){      //check -1
        for(J=0;J<9;J++){
            if(basis[I][J].main_number<0 || basis[I][J].main_number>9){
                cout << 0 << endl;
                //cout << basis[I][J].main_number << "I=" <<I<<"J="<<J<<endl;
                exit(0);
            }
            if(basis[I][J].main_number > 0) temp++;
        }
    }
    if(temp == 81){
        cout << 1 << endl;
        for(I=0;I<9;I++){
            for(J=0;J<9;J++){
                cout << basis[I][J].main_number << " ";
            }
            cout << endl;
        }
    }
    if(temp < 17) {
        cout << 2 << endl;
        exit(0);
    }
    //-------------------------------------
    for(I=0; I<9; I++){  //check row col repeat
        if(row_repeat(I) || col_repeat(I)){
            cout << 0 << endl;
            exit(0);
        }
    }
    //--------------------------------------
    for(I=0; I<8; I+=3){  //check block repeat
        for(J=0; J<8; J+=3){
            if(block_repeat(I,J)){
                cout << 0 << endl;
                exit(1);
            }
        }
    }
}
int Sudoku::row_repeat(int i){
    int J;
    int arrey[10] = {0};
    for(J=0; J<9; J++){
        arrey[basis[i][J].main_number] +=1;
    }
    for(J=1; J<10; J++){
        if(arrey[J] > 1) return 1;
    }
    return 0;
}
int Sudoku::col_repeat(int i){
    int J;
    int arrey[10] = {0};
    for(J=0; J<9; J++){
        arrey[basis[J][i].main_number] +=1;
    }
    for(J=1; J<10; J++){
        if(arrey[J] > 1) return 1;
    }
    return 0;
}
int Sudoku::block_repeat(int i, int j){
    int I = (i/3)*3, J = (j/3)*3, II, JJ;
    int arrey[10] = {0};
    for(II = 0; II<3;II++){
        for(JJ=0;JJ<3;JJ++){
            arrey[basis[II+I][JJ+J].main_number] +=1;
        }
    }
    for(J=1; J<10; J++){
        if(arrey[J] > 1) return 1;
    }
    return 0;

}
