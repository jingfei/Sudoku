#include <cstdlib>
 #include <iostream>
 #include <fstream>
 //#include "Sudoku.h"
 using namespace std;
 int main()
 {
     int num=0;
 int sudoku_in[81]={8,6,5,3,2,9,4,1,7,2,4,3,1,7,5,8,6,9,1,9,7,6,8,4,5,2,3,3,1,9,2,5,8,6,7,4,4,2,6,7,9,1,
 3,5,8,5,7,8,4,3,6,1,9,2,7,5,4,9,1,3,2,8,6,6,8,2,5,4,7,9,3,1,9,3,1,8,6,2,7,4,5};
 ofstream ofile("infile2.txt",ios::out);
 if(ofile.is_open())
 {
 for(int i=0;i<81;i++)
 {
         num=sudoku_in[i];
         ofile<<num;
         if((i+1)%9==0){ofile<<endl;}
}
}
else{cout<<"error";}
 
ofile.close();
system("pause");
return 0;
}
