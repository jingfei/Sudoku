#include <iostream>

 class Sudoku
 {

 public:

    Sudoku();
//    Sudoku(const int grille_initiale[][]);

    void GiveQuestion();
    void ReadIn();
    void Solve();

    bool absentSurLigne (int k, int tabla[9][9], int i);// bool sor(int s,int o,int n);
    bool absentSurColonne (int k, int tabla[9][9], int j);//bool oszlop(int s,int o,int n);
    bool absentSurBloc (int k, int tabla[9][9], int i, int j);
    bool check (int tabla[9][9], int position) ;// bool negyzet(int s,int o,int n);

    static const int sudoku_size = 9;

 private:

    int tabla[9][9];
    int un , tmp;


 };
