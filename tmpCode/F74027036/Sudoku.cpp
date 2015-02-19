#include "Sudoku.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <time.h>
#include <cmath>


#define LEVEL 45

using namespace std;

Sudoku::Sudoku()
{
    // b=1;
     un=0; un++;
     tmp=0;
      /*for( int i =0; i < 9;  i++)
        for (int j=0; j < 9; j++)
        tabla[i][j]=0;*/
}

void Sudoku::GiveQuestion()
{


  int i,j,aux;
      srand(time(0)); /*Establece que el origen de los numeros rand() seran el numero de segundos sucedidos entre el anyo Nuevo de 1990 hasta hoy: time(0)*/
  tabla[0][0] = (rand()%(9))+1; /*Para obtener un entero entre 0 y 8, sacamos el resto (con el operador %) de un aleatorio entre 9, dando un numero entre 0 y 8. Le sumamos 1 para que sea entre 1 y 9 en numero resultante*/
  do aux = (rand()%(9)) + 1;
      while(aux == tabla[0][0]); /*Se busca un numero aleatorio que NO sea igual al anterior*/
  tabla[0][1] = aux;
  do aux = (rand()%(9))+1;
      while(aux == tabla[0][0] || aux == tabla[0][1]);/*Se busca un numero aleatorio que NO sea igual que los anteriores*/
  tabla[0][2] = aux;
  do aux = (rand()%(9))+1;
      while(aux == tabla[0][0] || aux == tabla[0][1] || aux == tabla[0][2]);
  tabla[1][0] = aux;
  do aux = (rand()%(9))+1;
      while(aux == tabla[0][0] || aux == tabla[0][1] || aux == tabla[0][2] || aux == tabla[1][0]);
  tabla[1][1] = aux;
  do aux = (rand()%(9))+1;
      while(aux == tabla[0][0] || aux == tabla[0][1] || aux == tabla[0][2] || aux == tabla[1][0] || aux == tabla[1][1]);
  tabla[1][2] = aux;
  do aux = (rand()%(9))+1;
      while(aux == tabla[0][0] || aux == tabla[0][1] || aux == tabla[0][2] || aux == tabla[1][0] || aux == tabla[1][1] || aux == tabla[1][2]);
  tabla[2][0] = aux;
  do aux = (rand()%(9))+1;
      while(aux == tabla[0][0] || aux == tabla[0][1] || aux == tabla[0][2] || aux == tabla[1][0] || aux == tabla[1][1] || aux == tabla[1][2] || aux == tabla[2][0]);
  tabla[2][1] = aux;
  do aux = (rand()%(9))+1;
      while(aux == tabla[0][0] || aux == tabla[0][1] || aux == tabla[0][2] || aux == tabla[1][0] || aux == tabla[1][1] || aux == tabla[1][2] || aux == tabla[2][0] || aux == tabla[2][1]);
  tabla[2][2] = aux;
  /*Se rellenan los dos cuadros que quedan de arriba*/
  tabla[1][3]=tabla[0][0];
  tabla[1][4]=tabla[0][1];
  tabla[1][5]=tabla[0][2];

  tabla[2][6]=tabla[0][0];
  tabla[2][7]=tabla[0][1];
  tabla[2][8]=tabla[0][2];

  tabla[2][3]=tabla[1][0];
  tabla[2][4]=tabla[1][1];
  tabla[2][5]=tabla[1][2];

  tabla[0][6]=tabla[1][0];
  tabla[0][7]=tabla[1][1];
  tabla[0][8]=tabla[1][2];

  tabla[0][3]=tabla[2][0];
  tabla[0][4]=tabla[2][1];
  tabla[0][5]=tabla[2][2];

  tabla[1][6]=tabla[2][0];
  tabla[1][7]=tabla[2][1];
  tabla[1][8]=tabla[2][2];

  /*Se rellenan los cuadros de la izquierda*/
  tabla[3][1]=tabla[0][0];
  tabla[4][1]=tabla[1][0];
  tabla[5][1]=tabla[2][0];

  tabla[6][2]=tabla[0][0];
  tabla[7][2]=tabla[1][0];
  tabla[8][2]=tabla[2][0];

  tabla[3][2]=tabla[0][1];
  tabla[4][2]=tabla[1][1];
  tabla[5][2]=tabla[2][1];

  tabla[6][0]=tabla[0][1];
  tabla[7][0]=tabla[1][1];
  tabla[8][0]=tabla[2][1];

  tabla[3][0]=tabla[0][2];
  tabla[4][0]=tabla[1][2];
  tabla[5][0]=tabla[2][2];

  tabla[6][1]=tabla[0][2];
  tabla[7][1]=tabla[1][2];
  tabla[8][1]=tabla[2][2];

  /* Se rellena el cuadro central y derecho-centro*/
  tabla[3][3]=tabla[5][0];
  tabla[3][4]=tabla[5][1];
  tabla[3][5]=tabla[5][2];

  tabla[4][6]=tabla[5][0];
  tabla[4][7]=tabla[5][1];
  tabla[4][8]=tabla[5][2];

  tabla[5][3]=tabla[4][0];
  tabla[5][4]=tabla[4][1];
  tabla[5][5]=tabla[4][2];

  tabla[3][6]=tabla[4][0];
  tabla[3][7]=tabla[4][1];
  tabla[3][8]=tabla[4][2];

  tabla[5][6]=tabla[3][0];
  tabla[5][7]=tabla[3][1];
  tabla[5][8]=tabla[3][2];

  tabla[4][3]=tabla[3][0];
  tabla[4][4]=tabla[3][1];
  tabla[4][5]=tabla[3][2];

  /* Se rellena el cuadro central y derecho-centro*/
  tabla[6][3]=tabla[8][0];
  tabla[6][4]=tabla[8][1];
  tabla[6][5]=tabla[8][2];

  tabla[7][6]=tabla[8][0];
  tabla[7][7]=tabla[8][1];
  tabla[7][8]=tabla[8][2];

  tabla[8][3]=tabla[7][0];
  tabla[8][4]=tabla[7][1];
  tabla[8][5]=tabla[7][2];

  tabla[6][6]=tabla[7][0];
  tabla[6][7]=tabla[7][1];
  tabla[6][8]=tabla[7][2];

  tabla[8][6]=tabla[6][0];
  tabla[8][7]=tabla[6][1];
  tabla[8][8]=tabla[6][2];

  tabla[7][3]=tabla[6][0];
  tabla[7][4]=tabla[6][1];
  tabla[7][5]=tabla[6][2];

       for (i=0;i<9;i++)
       {
            for (j=0;j<=8;j++)
                {
                    if ( (rand()% 81) > LEVEL)
                        cout<<tabla[i][j]<<" ";
                     else
                         cout<< "0"<<" ";
                    if (j==2 || j==5 || j==8) cout<<"";
                }

            if (i==2 || i==5 || i==8) cout<<"\n";
               else cout<<"\n";
         }
}


void Sudoku::ReadIn()
{
 un++;

                        for(int i=0;i<9;i++)
                        {
                                for(int j=0;j<9;j++)
                                {
                                        cin>> tabla[i][j]; //un++;
                                     //   if(!tabla[i][j])
                                             //  un++;
                                }
                        }

}


void Sudoku::Solve()
{
    un++;

    int a=0;
    bool b= Sudoku::check(tabla,0);



            if(!b)
        {
            cout <<b;

        }


    //else if (!c) cout <<"2";
    else if(un==3)
        {
                //cout << un << endl;
                cout <<"1"<< endl;
                for(int i=0;i<9;i++)
                {
                        for(int j=0;j<9;j++)
                        {
                                cout << tabla[i][j] << " ";
                        }
                        cout << endl;
                }


        }
   else  cout<<"2";
        cout << endl;

 }


bool Sudoku::absentSurLigne (int k, int tabla[9][9], int i)
{
    int j;
    for (j=0; j < 9; j++)
        if (tabla[i][j] == k)
            return false;
    return true;
}

bool Sudoku::absentSurColonne (int k, int tabla[9][9], int j)
{
    int i;
    for (i=0; i < 9; i++)
        if (tabla[i][j] == k)
            return false;
    return true;
}

bool Sudoku::absentSurBloc (int k, int tabla[9][9], int i, int j)
{
    int _i = i-(i%3), _j = j-(j%3);  // ou encore : _i = 3*(i/3), _j = 3*(j/3);
    for (i=_i; i < _i+3; i++)
        for (j=_j; j < _j+3; j++)
            if (tabla[i][j] == k)
                return false;
    return true;
}

bool Sudoku::check (int tabla[9][9], int position)
{
   // if(position == )

    if (position == 9*9)
      return true;

    int i = position/9, j = position%9;

    if (tabla[i][j] != 0)
        return check(tabla, position+1);

   int k;
    for (k=1; k <= 9; k++)
    {
        if (absentSurLigne(k,tabla,i) && absentSurColonne(k,tabla,j) && absentSurBloc(k,tabla,i,j))
        {
            tabla[i][j] = k;

            if ( check (tabla, position+1) )
                return true;
        }
    }
    tabla[i][j] = 0;

    return false;
}
