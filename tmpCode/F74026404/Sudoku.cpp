#include "Sudoku.h"
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

Sudoku::Sudoku(){
    srand(time(NULL));
    GiveQuestion();
}
void Sudoku::GiveQuestion(){
    int tmp;
    int numtmp[9] = {1,2,3,4,5,6,7,8,9};
    vector <int> map(81);
    bool check = false; 
    for (a=0;a<81;a++){map[a] = 0;}
    for (a=0;a<9;a++) {
        map[a/3*9+a%3] = numtmp[i];
    }
    for (a=0;a<9;a++) 
    {
        b = rand() % 9;
        tmp = numtmp[a];
        numtmp[a] = numtmp[b];
        numtmp[b] = tmp;
    }    
	for(a=0;a<81;a++) {
        map[a] = numtmp[map[a]-1];
    }
	for (a=0;a<SIZE;a++)
        for (b=0;b<SIZE;b++){
            new_map[a][b] = map[a*SIZE+b];
        }
}

bool Sudoku::check_rep(vector<int> map,int pos,int n){
    int a;
    for (a=0;a<9;a++){
        if(map[pos/9*9+a]==n||map[a*9+pos%9]==n) {
           return true; 
        }
    }
    return false; 
}
bool Sudoku::map_put(vector<int > &map) {
    int pos;
    int count1,count2;
    bool check = true; 
    for (b=0;b<9;b++){ 
        count2 = 0; 
        for (a=1;a<9;a++){
            pos = a/3*27+a%3*3;
            count1 = 0;
            while (check==true){
                c = rand() % 9;
                check = check_rep(map,pos+c/3*9+c%3,b+1);
                ++count1;
                ++count2;
                if (map[pos+c/3*9+c%3]==0 && check==false) {
                    map[pos+c/3*9+c%3] = b+1;
                    check = true;
                    break;
                }
                else{
                    check = true;
                }
                if (count1 > 100){
                    for (d=0;d<81;d++){
                        if (map[d]==b+1){
                            map[d]=0;
                        }
                    }
                    map[b/3*b+b%3]=b+1;
                    a = 0;
                    break;
                }
                if (count2 > 1000){
                    return false;
                }
            }
        }
    }
    return true; }

vector < int > Sudoku::get_map()
{    vector < int > out_map(SIZE*SIZE);
    for (i=0;i<SIZE;i++)
        for (j=0;j<SIZE;j++){
            out_map[i*SIZE+j] = dig_map[i][j];
        }
    return out_map;
}
   
//--------------------------------------------------------------------------

void Sudoku::copy_map(){
        for (i=0;i<SIZE;i++)
        for (j=0;j<SIZE;j++){
            dig_map[i][j] = in_map[i][j];
        }
}

void Sudoku::map_dig(int n_hole) {
    int temp; 
    copy_map();
    for (i=0;i<81;i++){
       j = rand()%81;
        temp = number_seres[i];
        number_seres[i] = number_seres[j];
        number_seres[j] = temp;
    }
    for (i=0;i<n_hole;i++){
        dig_map[number_seres[i]/SIZE][number_seres[i]%SIZE] = 0;
    }
}



    void Sudoku::DigSudoku(vector < int > map, int n_hole)
{
    srand(time(NULL));
    for (i=0;i<SIZE*SIZE;i++){ 
        number_seres[i] = i;
    }
    for (i=0;i<SIZE;i++){
       for (j=0;j<SIZE;j++){
            in_map[i][j] = map[i*SIZE+j];
        }
    map_dig(n_hole);
}}


//-----------------------------------------------------------

int Sudoku::Ans = 0; 
void Sudoku::SolSudoku(vector<int> map,int A){
    for (i=0;i<SIZE;i++)
        for (j=0;j<SIZE;j++){
            in_map1[i*SIZE+j] = map[i*SIZE+j];
        }
    for (i=0;i<SIZE;i++)
        for (j=0;j<SIZE;j++){
            count[i*SIZE+j] = 0;
        }
    for (i=0;i<SIZE*SIZE;i++)
        for (j=0;j<SIZE;j++){
            tag[i][j]=0;
        }
    Found = 0;
    setAns(A);
    Solve();
}
void Sudoku::Solve()
{
    int check, Max, iMax;
    for (i=0;i<SIZE*SIZE;i++){
        if (in_map1[i]){
            Found++;
        }
        else{
            for (j=0;j<SIZE;j++){
                if (in_map1[((i/SIZE)*(SIZE)+j)] && !tag[i][in_map1[(i/(SIZE)*SIZE+j)]-1]){
                    count[i]++;
                    tag[i][in_map1[(i/SIZE)*SIZE+j]-1] = true;
                }
                if (in_map1[j*SIZE+i%SIZE] && !tag[i][in_map1[j*SIZE+i%SIZE]-1]){
                    count[i]++;
                    tag[i][in_map1[j*SIZE+i%SIZE]-1] = true;
                }
                check = in_map1[((i/(SIZE*3))*3+j/3)*SIZE + ((i%SIZE)/3)*3+j%3] - 1;
                if (in_map1[((i/(SIZE*3))*3+j/3)*SIZE + ((i%SIZE)/3)*3+j%3] && !tag[i][check]){
                    count[i]++;
                    tag[i][check] = true;
                }
            }
        }
    }
    for (i=0;i<SIZE*SIZE;i++){
        if (!in_map1[i] && count[i]==8){
            count[i] = 0;
            Found++;
            for (j=0;j<SIZE;j++){
                if(!tag[i][j]){
                   in_map1[i] = j+1;
                    for (k=0;k<SIZE;k++){
                        if (!in_map1[(i/SIZE)*SIZE+k] && !tag[(i/SIZE)*SIZE+k][j]){
                            count[(i/SIZE)*SIZE+k]++;
                            tag[(i/SIZE)*SIZE+k][j] = true;
                        }
                        if (!in_map1[k*SIZE+i%SIZE] && !tag[k*SIZE+i%SIZE][j]){
                            count[k*SIZE+i%SIZE]++;
                            tag[k*SIZE+i%SIZE][j] = true;
                        }
                        check = ((i/(SIZE*3))*3+k/3)*SIZE + ((i%SIZE)/3)*3+k%3;
                        if (!in_map1[check] && !tag[check][j]){
                            count[check]++;
                            tag[check][j] = true;
                        }

                    }
                }
            }
            i = -1; 
        }
    }
    if (Found == 81) {
        setAns(Ans+1);
    }
}
int Sudoku::getAns() {
    return Ans;
}
void Sudoku::setAns(int A){
    Ans = A;
}
