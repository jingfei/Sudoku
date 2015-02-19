#include "Sudoku.h"
#include <vector>

using namespace std;

Sudoku::Sudoku()
{
    for(int i=0;i<sudokuSize;i++)
	map[i]=0;
    temp=0;
}

Sudoku::Sudoku(const int init_map[])
{
    for(int i=0;i<sudokuSize;i++)
	map[i]=init_map[i];
    temp=0;
}


void Sudoku::setMap(const int set_map[])
{
    for(int i=0;i<sudokuSize;i++)
	map[i]=set_map[i];
}

int Sudoku::getElement(int index)
{
    return map[index];
}

bool Sudoku::checkUnity(int arr[])
{
    int arr_unity[9];
    
    for(int i=0;i<9;i++)
	arr_unity[i]=0;
    for(int i=0;i<9;i++)
	arr_unity[arr[i]-1]++;
    for(int i=0;i<9;i++)
	if(arr_unity[i]!=1)
	 return false;
	return true;
    }

bool Sudoku::checkUnity2(int arr[])
{
    int arr_unity[9];

    for(int i=0;i<9;i++)
	arr_unity[i]=0;
    for(int i=0;i<9;i++)
	arr_unity[arr[i]-1]++;
    for(int i=0;i<9;i++)
	if(arr_unity[i]>1)
	    return false;
    return true;
}

void Sudoku::setElement(int index, int value)
{
    map[index] = value;
}

int Sudoku::getFirstZeroIndex()
{
    for(int i=0;i<sudokuSize;i++)
	if(map[i]==0)
	    return i;
    return -1;
}

bool Sudoku::isCorrect()
{
    bool check_result;
    int check_arr[9];
    int location;


    /*check row*/
    for(int i=0;i<81;i+=9)
    {
	for(int j=0;j<9;j++)
	    check_arr[j]=map[i+j];
	check_result = checkUnity(check_arr);
	if(check_result==false)
	    return false;
    }

    /*check column*/
    for(int i=0;i<9;i++)
    {
	for(int j=0;j<9;j++)
	  check_arr[j]=map[i+j*9];
	check_result=checkUnity(check_arr);
	if(check_result==false)
	    return false;
    }

    /*check cells*/
    for(int i=0;i<9;i++)
    {
	for(int j=0;j<9;j++)
	{
	    location=27*(i/3)+3*(i%3)+9*(j/3)+(j%3);
	    check_arr[j]=map[location];
	}
	check_result=checkUnity(check_arr);
	if(check_result==false)
	    return false;
    }

    return true;

}

bool Sudoku::isCorrect2()
{
    bool check_result;
    int check_arr[9];
    int location;

    /*check rows*/
    for(int i=0;i<73;i+=9)
    {
	for(int j=0;j<9;j++)
	    check_arr[j]=map[i+j];
	check_result=checkUnity2(check_arr);
	if(check_result==false)
	    return false;
    }

    /*check columns*/
    for(int i=0;i<9;i++)
    {
	for(int j=0;j<9;j++)
	    check_arr[j]=map[i+j*9];
	check_result = checkUnity2(check_arr);
	if(check_result == false)
	    return false;
    }

    /*check cells*/
    for(int i=0;i<9;i++)
    {
	for(int j=0;j<9;j++)
	{
	   location=27*(i/3)+3*(i%3)+9*(j/3)+(j%3);
	   check_arr[j]=map[location];
	}
    
	check_result = checkUnity2(check_arr);
	if(check_result==false)
	    return false;
    }
    return true;
}

    void Sudoku::push(int i)
{
    temp++;
    tempNumber[temp] = i;
}

int Sudoku::pop()
{
    if(temp<=0)
	return -1;
    else
	return tempNumber[temp];
}

void Sudoku::display()
{
    for(int i=0;i<81;i++)
    {
	cout<<getElement(i)<<" ";

	if(i%9==8)
	    cout<<endl;
    }

    cout<<endl<<endl;
}
void Sudoku::GiveQuestion()
{
    srand((unsigned)time(NULL));
    if(GiveQuestion1())
	{
        }
}


bool Sudoku::GiveQuestion1()
{
    bool x;

    x=GiveQuestion0();
  
    while(x!=true)
    {
      x=GiveQuestion0();
    }
  //  cout<<"hello"<<endl;
    return true;
  
  //  if(GiveQuestion0()==false)
  //  {
//	GiveQuestion();
  //  }
   // else if(GiveQuestion0()==true)
    //{
     // return 0;
   //` }
}
bool Sudoku::GiveQuestion0()
{
    Sudoku question;
 //   srand((unsigned)time(NULL));
    int z,x, arr1[9];
    int temp;
    int tempSu[81];
    int a,b,c,d,e,f,g,h,i;
    int arr[10]={1,2,3,4,5,6,7,8,9,0};

    int su[81]={8,9,7,2,3,1,5,6,4,
                2,3,1,5,6,4,8,9,7,
                5,6,4,8,9,7,2,3,1,
                7,8,9,1,2,3,4,5,6,
                1,2,3,4,5,6,7,8,9,
                4,5,6,7,8,9,1,2,3, 
	        9,7,8,3,1,2,6,4,5,
	        3,1,2,6,4,5,9,7,8,
	        6,4,5,9,7,8,3,1,2};
    
    for(z=0;z<9;z++)
    {
	x=rand()%9;
	temp=arr[z];
	arr[z]=arr[x];
	arr[x]=temp;
    }

    
    for(z=0;z<40;z++)
    {
	su[rand()%81]=10;
    }

    for(z=0;z<81;z++)
    {
	question.setElement(z,arr[su[z]-1]);
	tempSu[z]=arr[su[z]-1];
//	cout<<tempSu[z]<<" ";
//		if(z%9==8)
//		cout<<endl;
    }
//	cout<<endl;
    
    if(question.Solve0()==1)
    {
	for(z=0;z<81;z++)
	{
	    cout<<tempSu[z]<<" ";
	    if(z%9==8)
		cout<<endl;
	}
  //      cout<<"goodbye"<<endl;
	return true;
    }
  //  cout<<"E04SU3SU;6"<<endl;
    return false;
}

void Sudoku::ReadIn()
{
    int z,i=0;

    while(cin>>z)
    {
	setElement(i,z);
	i++;
    }
}

void Sudoku::Solve()
{
    switch(Solve0()){
	case 1:
	    {
		cout<<"1"<<endl;

		for(int i=0;i<81;i++)
		{
		    cout<<getElement(i)<<" ";
		    if(i%9==8)
			cout<<endl;
		}
		break;
	    }
	case 2:
	    {
	    cout<<"2"<<endl;
	    break;
	    }
	case 3:
	    {
	    cout<<"0"<<endl;
	    break;
	    }
}
}

int Sudoku::Solve0()
{
    Sudoku question,question1,question2,question3;
    Sudoku answer,answer1,answer2,answer3;
    vector<int> v1(81), v2(81),v3(81),v4(81);

    for(int i=0;i<81;i++)
    {
	question.setElement(i,getElement(i));
	question1.setElement(80-i,getElement(i));
	question2.setElement(80-i,getElement(i));
	question3.setElement(i,getElement(i));
    }

    
    if(question.isCorrect2())
    {
    solve1(question,answer);
    solve1(question1,answer1);
    solve2(question2,answer2);
    solve2(question3,answer3);

    for(int i=0;i<81;i++)
    {
	v1.at(i)=answer.getElement(i);
	v4.at(80-i)=answer1.getElement(i);
	v2.at(80-i)=answer2.getElement(i);
	v3.at(i)=answer.getElement(i);
    }
/*
	for(int i=0;i<81;i++)
	{
	 cout<<v2.at(i)<<" ";
	 if(i%9==8)
		cout<<endl;
        }
	
	cout<<endl;

	for(int i=0;i<81;i++)
	{
 	 cout<<v4.at(i)<<" ";
	  if(i%9==8)
		cout<<endl;
	}

	cout<<endl;
*/
    if(solve1(question,answer)==false)
    {
	return 3;
    }
    else if(v1==v2&&v2==v3&&v3==v1&&v1==v4&&v2==v4&&v3==v4)
    {
	for(int i=0;i<81;i++)
	    setElement(i,answer.getElement(i));
	return 1;
    }
    else 
    {
//	cout<<solve3(question2,answer2)<<" is here"<<endl;
	//cout<<"2"<<endl;
	return 2;
    }
    }
    return 3;
}

bool Sudoku::solve1(Sudoku question, Sudoku & answer)
{
    int firstZero, num=0;
    firstZero = question.getFirstZeroIndex();
    
    if(firstZero==-1)
    {
	if(question.isCorrect())
	{
	    answer=question;
	    return true;
	}
	else 
	    return false;
    }

    do{
	num=question.getElement(firstZero);
	num++;
	question.setElement(firstZero,num);
	if(question.getElement(firstZero)>9)
	{
	    if(question.gettemp()==1)
	    {
		return false;
	    }
	    num=0;
	    question.setElement(firstZero,num);
	    firstZero=question.pop();
	}
	else
	{
	    if(question.isCorrect2())
	    {
		question.push(firstZero);
		if(solve1(question,answer))
		{
		    return true;
		}
	    }
	}
    }while(firstZero<81&&question.getElement(firstZero)>0);

    return false;
}

bool Sudoku::solve2(Sudoku question, Sudoku & answer)
{
    int firstZero, num=9;
    firstZero = question.getFirstZeroIndex();
    
    if(firstZero==-1)
    {
        if(question.isCorrect())
        {
            answer =question;
            return true;
        }
        else
            return false;
    }
    
    do{
        question.setElement(firstZero,num);
        //	cout<<question.gettemp()<<endl;
        //	question.display();
        if(question.getElement(firstZero)<1)
        {
            // cout<<"hello"<<endl;
            //	    if(question.gettemp()==1)
            //	    {
            //		return false;
            //	    }
            firstZero = question.pop();
        }
        else
        {
            if(question.isCorrect2())
            {
                question.push(firstZero);
                if(solve2(question,answer))
                {
                    return true;
                }
            }
            num--;
        }
    }while(firstZero<81&&question.getElement(firstZero)>0);
    
    return false;
}


int Sudoku::gettemp()
{
    return temp;
}

