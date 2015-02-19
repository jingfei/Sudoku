#include "Sudoku.h"

int Sudoku::cal(int question[],int index,int&zero,int&b){
int a=0,x=0,y,in = index - index%3 - index/9%3*9;
for(int i=1;i<10;i++)
{

for(int j=0;j<9;j++)
if(question[(index/9)*9 +j] == i)
a++;
if(!a)
{
for(int j=0;j<9;j++)
if(question[index%9 +9*j] == i)
a++;
	if(!a)
	{
	for(int j=0;j<9;j++)
	if(question[(in+j%3) + j/3 *9] ==i)
	a++;
		if(!a)
		{y=i;x++;}
	}

}

a=0;
}
if(x==1)
{question[index] = y;zero--;b=0;}

}


void Sudoku::GiveQuestion(){

srandom(time(NULL));
int x;
x= random()%3;

switch(x)
{
	case 0:{
	int qarr[81] = 
	{3,6,0,2,0,0,0,4,5,
	0,0,0,5,3,0,6,9,0,
	0,8,7,0,0,0,1,0,0,
	0,0,0,1,2,0,9,6,0,
	0,0,3,6,0,5,8,0,0,
	0,2,8,0,9,4,0,0,0,
	0,0,1,0,0,0,4,8,0,
	0,7,5,0,6,3,0,0,0,
	2,4,0,0,0,9,0,5,7};
	for(int i=0;i<9;i++)
	{
	for(int j=0;j<9;j++)
	cout<<setw(4)<<qarr[i*9+j];
	cout<<endl;
	}
	/*for(int i=0;i<81;i++)
	question[i] = qarr[i];*/
	break;}

	case 1:{
	int qarr[81] =
	{0,0,0,0,0,0,0,0,0,
	0,0,0,4,0,1,0,0,0,
	1,3,0,0,0,0,0,6,4,
	0,0,0,0,7,0,0,0,0,
	5,0,0,0,0,0,0,0,2,
	0,2,8,0,4,0,7,1,0,
	0,9,2,8,0,6,5,7,0,
	0,0,7,0,0,0,8,0,0,
	0,0,0,5,0,7,0,0,0,
	};
	for(int i=0;i<9;i++)
	{
	for(int j=0;j<9;j++)
	cout<<setw(4)<<qarr[i*9+j];
	cout<<endl;
	}
	/*for(int i=0;i<81;i++)
	question[i] = qarr[i];*/
	break;}

	case 2:{
	int qarr[81] =
	{0,3,1,7,0,4,0,0,0,
	0,0,4,0,1,0,8,0,7,
	0,6,0,5,0,0,0,1,9,
	2,0,0,0,6,0,3,0,5,
	0,9,0,1,0,2,0,6,0,
	3,0,6,0,5,0,0,0,4,
	5,4,0,0,0,1,0,8,0,
	6,0,3,0,2,0,9,0,0,
	0,0,0,3,0,9,5,7,0,
	};
	for(int i=0;i<9;i++)
	{
	for(int j=0;j<9;j++)
	cout<<setw(4)<<qarr[i*9+j];
	cout<<endl;
	}
	/*for(int i=0;i<81;i++)
	question[i] = qarr[i];*/
	break;}
};

/*for(;;)
{
x = random();
int q[9] = {0};
for(int i=1;i<10;i++)
{
for(;;)
{
if(!q[x%9])
{
q[x%9] = i;
x = random();
break;
}
}
}
if( check(q) )
break;
}


for(int i=0;i<9;i++)
qarr[30+(i%3) + (i/3 *9)] = q[i];

x = random();

int y = x%3;
if(!y)
y++;
int z;
if(y==1)
z = 2;
if(y==2)
z=1;
for(int i=0;i<9;i++)
{
int k = (i%3) + (i/3 *9);
if( k+y*9 >= 27)
qarr[30+(y-1)*9 -3] = qarr[30+k];
else
qarr[30+k+ y*9 -3] = qarr[30+k];
if( k+z*9 >= 27)
qarr[30+(z-1)*9 +3] = qarr[30+k];
else
qarr[30+k+ z*9 +3] = qarr[30+k];

if( (k%3+y) >= 3)
qarr[30+(y-1) + 27] = qarr[30+k];
else
qarr[30+k+ y + 27] = qarr[30+k];

if( (k%3+z) >=3)
qarr[30 + (z-1) -27 ] = qarr[30+k];
else
qarr[30+k+z-27] = qarr[30+k];

qarr[ = qarr[30+k];
*/

}

void Sudoku::ReadIn(){

int i=0;

while(cin>>question[i])
{i++; if(i==81)break;}

/*for(int i=0;i<9;i++)
{for(int j=0;j<9;j++)
cout<<setw(4)<<question[i*9+j];
cout<<endl;
}*/

}

void Sudoku::Solve(){

int zero=0;

for(int i=0;i<81;i++)
if(question[i]<0 || question[i]>9)
{cout<<0<<endl;exit(1);}


for(int i=0;i<81;i++)
if(!question[i])
zero++;



for(;;)
{
if(!zero)
break;
else
{
int b=1;
for(int j=0;j<81;j++)
{
if(!question[j])
{cal(question,j,zero,b);}
}
if(b)
break;
}
}

if( correct() )
{
cout<<1<<endl;
for(int i=0;i<9;i++)
{
for(int j=0;j<9;j++)
cout<<setw(4)<<question[i*9+j];
cout<<endl;
}
}
else
if( no_so() )
cout<<0<<endl;
else
cout<<2<<endl;


}


int Sudoku::check(int check_arr[]){

int arr[9] ={0};

for(int i=0;i<9;i++)
++arr[check_arr[i]-1];

for(int i=0;i<9;i++)
if(arr[i] != 1)
return 0;
return 1;
}

int Sudoku::correct(){

int check_arr[9];

for(int i=0;i<9;i++)
{
for(int j=0;j<9;j++)
check_arr[j] = question[i*9+j];
if( !check(check_arr) )
return 0;
}

for(int i=0;i<9;i++)
{
for(int j=0;j<9;j++)
check_arr[j] = question[i+j*9];
if( !check(check_arr) )
return 0;
}

for(int i=0;i<9;i++)
{
for(int j=0;j<9;j++)
{
int in;
in = 27*(i/3) + 3*(i%3) + 9*(j/3) + (j%3);
check_arr[j] = question[in];
}
if( !check(check_arr) )
return 0;
}
return 1;
}

int Sudoku::no_so(){

int check_arr[9];

for(int i=0;i<9;i++)
{
for(int j=0;j<9;j++)
check_arr[j] = question[i*9+j];
if( check_no(check_arr) )
return 1;
}

for(int i=0;i<9;i++)
{
for(int j=0;j<9;j++)
check_arr[j] = question[i+j*9];
if( check_no(check_arr) )
return 1;
}

for(int i=0;i<9;i++)
{
for(int j=0;j<9;j++)
{
int in;
in = 27*(i/3) + 3*(i%3) + 9*(j/3) + (j%3);
check_arr[j] = question[in];
}
if( check_no(check_arr) )
return 1;
}
}


int Sudoku::check_no(int check_arr[]){

int arr[9] ={0};

for(int i=0;i<9;i++)
++arr[check_arr[i]-1];

for(int i=0;i<9;i++)
if(arr[i] != 1&&arr[i] != 0)
return 1;
return 0;

}


