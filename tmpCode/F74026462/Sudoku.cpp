#include"Sudoku.h"
#include<cstdlib>
#include<ctime>
#include<cstring>
using namespace std;

Sudoku::Sudoku()
{
  for(int i=0;i<sudokuSize;i++)
  {
    map[i]=0;
    Solution[i]=0;
  }
  indexOftmp=0;
  solveResult=0;
  data[0]="2 0 0 0 0 0 0 0 9 3 1 0 4 0 0 0 0 0 0 0 0 0 0 0 5 6 0 0 0 1 0 0 0 0 0 0 8 3 0 0 0 0 0 0 7 4 9 0 0 8 0 0 5 3 0 6 0 0 9 0 1 0 0 0 0 0 8 6 0 3 0 0 7 0 0 0 4 1 0 0 0";
  data[1]="0 8 6 0 0 0 0 9 0 0 2 0 0 0 0 1 8 0 4 0 0 7 0 0 0 0 0 0 3 0 0 0 0 2 0 0 1 0 9 2 0 0 0 0 8 5 0 0 3 0 0 0 0 7 0 0 0 0 7 4 9 0 0 0 0 0 1 0 0 0 0 0 0 0 0 8 5 3 0 7 0";
  data[2]="4 3 7 0 0 0 0 2 0 0 0 0 0 0 9 0 0 6 6 0 0 0 0 3 0 7 0 0 1 0 0 0 0 8 0 0 5 6 0 0 8 1 9 0 0 0 0 0 0 0 7 1 0 0 0 0 5 0 9 4 0 0 0 0 9 0 0 6 0 0 0 0 1 0 0 0 5 0 0 0 0";
  data[3]="0 8 6 0 5 0 0 4 2 0 0 0 0 0 6 0 0 0 4 0 0 8 0 0 0 1 6 0 0 0 0 1 0 7 0 0 0 0 0 0 2 3 5 0 9 0 2 0 7 0 9 0 3 0 0 0 0 0 0 0 0 0 4 0 0 0 0 9 0 2 0 0 7 9 0 0 0 8 0 0 0";
  data[4]="0 0 0 0 0 0 3 0 0 0 8 0 1 0 2 7 0 9 0 9 0 0 0 0 0 2 4 3 0 0 2 0 4 6 0 0 0 0 0 0 5 6 0 0 0 0 0 4 8 0 0 0 0 0 4 0 0 0 1 5 0 6 2 0 2 0 6 0 0 0 0 0 1 7 0 0 0 0 0 0 0";
  data[5]="4 0 2 7 0 0 8 0 0 0 1 0 0 8 0 0 0 0 6 0 0 0 0 0 1 0 9 0 0 6 1 0 0 0 9 0 3 8 0 0 0 0 0 7 0 0 0 1 0 0 0 0 3 0 5 0 4 3 0 0 6 0 0 0 0 0 5 2 0 0 0 0 0 0 7 0 1 0 0 0 0";
  data[6]="8 4 2 0 0 0 0 0 0 5 0 0 0 1 3 4 0 0 0 0 0 0 0 0 5 0 0 0 0 0 0 0 0 0 0 0 0 9 0 0 7 5 3 0 0 0 0 0 0 2 0 0 7 1 4 0 0 9 0 1 0 0 0 0 1 0 8 0 0 0 0 5 0 3 0 0 0 6 0 4 0";
  data[7]="0 7 0 2 0 3 0 4 0 0 0 6 0 0 0 0 0 0 8 0 0 0 9 0 2 0 0 0 4 2 1 0 0 0 0 0 0 0 0 0 0 2 5 0 3 5 6 0 0 0 0 0 0 0 0 0 3 0 1 0 6 0 0 1 0 7 0 0 8 0 0 2 0 0 0 0 0 9 0 8 0";
  data[8]="0 0 5 0 0 0 8 0 7 8 0 0 0 3 0 0 0 2 7 0 0 5 0 0 9 3 0 4 0 3 0 0 0 7 0 0 0 0 0 0 6 0 0 0 0 5 0 8 1 0 2 6 0 0 0 0 0 0 9 0 0 0 0 6 0 0 0 4 0 0 0 0 0 0 4 0 0 6 3 0 9";
  data[9]="0 0 3 0 0 0 0 0 0 4 0 0 6 9 0 0 0 8 0 2 0 0 0 0 0 0 5 8 0 1 0 0 4 0 0 0 0 0 0 0 7 1 0 6 3 0 6 0 9 0 0 0 8 4 3 0 0 0 0 7 0 1 0 0 0 0 0 0 0 5 0 2 0 7 0 0 4 0 0 0 0";
}

void Sudoku::GiveQuestion()
{
 
  srand(time(NULL));
  dataIndex=rand()%10;
  cout << data[dataIndex] << endl;
}

void Sudoku::ReadIn()
{
  for(int i=0;i<sudokuSize;i++)
    cin >> map[i];
}

void Sudoku::Solve()
{
  backtracking();
  if(solveResult>1) 
  {
    cout << "2" << endl;
    return;
  }
  if(solveResult==0) 
  {
    cout << "0" << endl;
    return;
  }
  if(solveResult==1)
  { 
    cout << solveResult << endl;
    printSolution();
  }
}

void Sudoku::backtracking()
{
  if(indexOfZero(map)==100 && isCorrect(map)==true)
  {
    getSolution();
    solveResult++;
    return;
  }
  for(int i=1;i<=9;i++)
  {
    if(isCorrect(map))
    {
      tmp[indexOftmp]=indexOfZero(map);
      map[tmp[indexOftmp]]=i;
      indexOftmp++;
      backtracking();

      map[tmp[--indexOftmp]]=0;
    }
  }
}

bool Sudoku::checkUnity(int arr[])
{
  int arr_unity[9];

  for(int i=0;i<9;++i)
    arr_unity[i]=0; //initialize
  for(int i=0;i<9;++i)
    ++arr_unity[arr[i]-1];
  for(int i=0;i<9;++i)
    if(arr_unity[i]!=0 && arr_unity[i]!=1) return false;
  return true;
}

bool Sudoku::isCorrect(int map[sudokuSize])
{
  int checkColumn[9];
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
      checkColumn[j] = map[i+j*9];
    if(checkUnity(checkColumn)==false) return false;
  }

  int checkRow[9];
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
      checkRow[j] = map[i*9+j];
    if(checkUnity(checkRow)==false) return false;
  }

  int checkCell[9];
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
      checkCell[j] = map[27*(i/3)+3*(i%3)+9*(j/3)+(j%3)];
    if(checkUnity(checkCell)==false) return false;
  }

  return true;
}

int Sudoku::indexOfZero(int map[sudokuSize])
{
  for(int i=0;i<sudokuSize;i++)
    if(map[i]==0) return i;
  return 100;
}

void Sudoku::printSolution()
{
  for(int i=0;i<sudokuSize;i++)
  {
    cout << Solution[i] << " " ;
    if(i%9==8) cout << endl;
  }
  cout << endl;
}

void Sudoku::getSolution()
{
  for(int i=0;i<sudokuSize;i++)
    Solution[i]=map[i];
}

