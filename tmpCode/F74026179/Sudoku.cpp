#include "Sudoku.h"
using namespace std;
Sudoku::Sudoku(){
copy[0]=0;
}
void Sudoku::GiveQuestion(){
int random[9]={1,2,3,4,5,6,7,8,9};
int original,rand_number,i,j,q[81];
srandom(time(NULL));
for(i=0;i<9;i++){
 rand_number=rand()%9;
 original=random[rand_number];
 random[rand_number]=random[i];
 random[i]=original;}
for(i=0;i<3;i++){
 for(j=0;j<3;j++){
  map[(3+i)*9+(3+j)]=random[i*3+j];}}
for(i=0;i<3;i++){
 map[5+i*9]=map[30+i*9];
 map[58+i*9]=map[30+i*9];
 map[4+i*9]=map[32+i*9];
 map[57+i*9]=map[32+i*9];
 map[3+i*9]=map[31+i*9];
 map[59+i*9]=map[31+i*9];
 map[36+i]=map[30+i];
 map[51+i]=map[30+i];
 map[45+i]=map[39+i];
 map[33+i]=map[39+i];
 map[27+i]=map[48+i];
 map[42+i]=map[48+i];}
for(i=0;i<3;i++){
 map[9+i]=map[3+i];
 map[24+i]=map[3+i];
 map[18+i]=map[12+i];
 map[6+i]=map[12+i];
 map[i]=map[21+i];
 map[15+i]=map[21+i];
 map[63+i]=map[57+i];
 map[78+i]=map[57+i];
 map[72+i]=map[66+i];
 map[60+i]=map[66+i];
 map[54+i]=map[75+i];
 map[69+i]=map[75+i];}
for(i=0;i<81;i++)
{q[i]=map[i];}
i=0;
while(i<40)
{rand_number=rand()%81;
 original=q[rand_number];
 q[rand_number]=0;
 for(j=0;j<81;j++)
 {map[j]=q[j];}
 OAO();
 if(answer!=1)
 {q[rand_number]=original;i--;}
 else
 {i++;}}
for(i=0;i<81;i++){
 cout<<q[i]<<" ";
 if(i%9==8)
  {cout<<endl;}}
}
void Sudoku::ReadIn(){
int i,j,count;
string g;
for(i=0;i<9;i++)
{getline(cin,g);
 count=0;
 for(j=0;j<17;j++)
 {if(g[j]<='9'&&g[j]>='0')
  {map[i*9+count]=g[j]-'0';count++;}}}
}
void Sudoku::Solve(){
int i,j,check,ch;
for(i=0;i<81;i++)
{if(map[i]!=0)
 {check=1;
  ch=map[i];
  map[i]=0;
  check=checkout(i,ch);
  map[i]=ch;
  if(check==0)
  {cout<<"0";exit(0);}}
 }
OAO();
cout<<answer<<endl;
if(answer==1)
{for(i=0;i<81;i++)
{cout<<copy[i]<<" ";
 if(i%9==8)
 {cout<<endl;}}}
}
void Sudoku::OAO(){
int i,j,k,check,count;
answer=0;
for(i=0;i<81;i++){
 ans[i][0]=0;
 count=1;
 if(map[i]==0)
 {for(j=1;j<10;j++)
  {check=1;
   check=checkout(i,j);
  if(check==1)
  {ans[i][0]++;ans[i][count]=j;count++;}}}
 else
 {ans[i][0]++;ans[i][1]=map[i];}}
for(i=0;i<81;i++){
 if(ans[i][0]==1)
 {map[i]=ans[i][1];}}
QAQ(0);
}
int Sudoku::QAQ(int i){
int j,k,c,s,check=1;
if(i==81)
{for(j=0;j<81;j++){
  if(map[j]==0)
  {check=0;i=0;}}
 if(check==1)
  {answer++;
   for(j=0;j<81;j++)
   {copy[j]=map[j];}
   if(answer!=1)
   answer=2;
   return 0;}
}
else
{if(map[i]==0)
 {for(j=1;j<ans[i][0]+1;j++)
  {check=1;
   s=ans[i][j];
   check=checkout(i,s);
   if(check==1)
   {map[i]=s;k=i+1;
    QAQ(k);}}map[i]=0;}
else
 {k=i+1;QAQ(k);}
}
}
int Sudoku::checkout(int i,int s){
int k;
for(k=0;k<9;k++)
{if(map[i%9+k*9]==s)
 {return 0;}
 if(map[(i/9)*9+k]==s)
 {return 0;}
 if(map[((i/9)/3)*27+((i%9)/3)*3+(k/3)*9+k%3]==s)
 {return 0;}}
return 1;
}
