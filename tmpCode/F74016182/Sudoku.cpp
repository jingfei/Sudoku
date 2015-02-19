#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
#include "Sudoku.h"
using namespace std;

Sudoku::Sudoku(){
	for(int i=0 ; i<sudokuSize ; ++i){
		map[i] = 0;
		count=0;
	}
    int a1[sudokuSize]={
            9,0,0,0,0,6,0,0,3,
            3,6,7,0,2,0,9,0,4,
            1,4,0,3,0,9,0,0,6,
            7,2,0,0,0,4,8,6,9,
            6,9,1,0,0,0,3,4,0,
            8,0,4,6,9,0,0,2,1,
            5,0,0,8,0,1,0,9,2,
            4,0,0,0,6,0,1,3,0,
            2,1,0,0,0,0,0,0,0};
    for (int i=0 ; i<sudokuSize ; ++i)
        arr1[i]=a1[i];
    int a2[sudokuSize]={
        8,0,0,0,0,0,0,0,0,
        0,0,3,6,0,0,0,0,0,
        0,7,0,0,9,0,2,0,0,
        0,5,0,0,0,7,0,0,0,
        0,0,0,0,4,5,7,0,0,
        0,0,0,1,0,0,0,3,0,
        0,0,1,0,0,0,0,6,8,
        0,0,8,5,0,0,0,1,0,
        0,9,0,0,0,0,4,0,0};
    for (int i=0 ; i<sudokuSize ; ++i)
        arr2[i]=a2[i];
    int a3[sudokuSize]={
        0,5,0,0,0,0,7,0,0,
        0,0,4,0,0,0,0,0,8,
        8,0,3,0,5,1,0,0,0,
        0,3,0,0,0,7,0,0,5,
        0,0,0,5,9,2,0,0,0,
        6,0,0,4,0,0,0,2,0,
        0,0,0,1,7,0,4,0,2,
        4,0,0,0,0,0,6,0,0,
        0,0,6,0,0,0,0,9,0};
    for (int i=0 ; i<sudokuSize ; ++i)
        arr3[i]=a3[i];


}

void Sudoku::setMap(const int set_map[])
{
	for(int i=0 ; i<sudokuSize ; ++i)
		map[i] = set_map[i];
}

int Sudoku::getElement(int index)
{
	return map[index];
}
void Sudoku::ReadIn(){
    int num;
    /*ifstream infile("output.txt",ios::in);
	for(int i=0;i<81;++i) // read in question
	{
		infile >> num;
		setElement(i, num);
	}
    infile.close();*/
    for(int i=0;i<81;++i) // read in question
	{
		cin >> num;
		setElement(i, num);
	}

}
void Sudoku::GiveQuestion(){
    int a;
        srand(time(NULL));
        a=rand()%3;
        switch(a){

    case 0:
        for(int i=0; i<81; i++)
		{
			cout << arr1[i] << " ";
			if(i%9==8)
				cout << endl;
		}

    break;
    case 1:
        for(int i=0; i<81; i++)
		{
			cout << arr2[i] << " ";
			if(i%9==8)
				cout << endl;
		}

    break;
    case 2:
        for(int i=0; i<81; i++)
		{
			cout << arr3[i] << " ";
			if(i%9==8)
				cout << endl;
		}

    break;


}
}
void Sudoku::Solve(){
    count = 0;
    int a;
    a=solvee();


    if (a==2)
        {cout<<"2"<<endl;}

    else
    {
		for(int i=0 ; i<sudokuSize ; ++i){
		map[i] = 0;
		count=0;
		}
        ReadIn();

		for(int i=0 ; i<sudokuSize ; ++i){
		answer[i] = 0;
		count=0;
		}

		if(search()==1){
		cout << "1\n";
		for(int i=0; i<81; i++)
		{
			cout << answer[i] << " ";
			if(i%9==8)
				cout << endl;
		}
		}

        else
            cout<< "0" <<endl;
		/*for(int i=0; i<81; i++)
		{
			cout << getElement(i) << " ";
			if(i%9==8)
				cout << endl;
		}*/
	}
}
void Sudoku::FindFirst(int a, vector<int> &vec){
    vec.clear();
    int array_row[9];
    int array_co[9];
    int array_cell[9];
    //vector<int> vec;
    int j=0,k=0,f=0,r=0;
    int location=0;
    for(int i=(a-(a%9));i<=(a+(9-a%9)-1);++i){
        array_row[j]=map[i];
        j++;
}
    for(int i=(a%9);i<=(a%9+72);i+=9){
        array_co[k]=map[i];
        k++;
}

    f=(a%9/3)+3*(a/27);

    for(int i=0; i<9; ++i)
    {
        location = 27*(f/3) + 3*(f%3) + 9*(i/3) + (i%3);
        array_cell[r] = map[location];
        r++;
}
    int arr_unity1[9];
    int arr_unity2[9];
    int arr_unity3[9]; // counters

    for(int i=0; i<9; i++)
		arr_unity1[i] = 0; // initialize
    for(int i=0; i<9; i++)
        if (array_row[i]!=0)
            arr_unity1[array_row[i]-1] = 1;



    for(int k=0; k<9; ++k)
		arr_unity2[k] = 0; // initialize
    for(int k=0; k<9; ++k)
        if (array_co[k]!=0)
            ++arr_unity2[array_co[k]-1];


    for(int j=0; j<9; ++j)
		arr_unity3[j] = 0; // initialize

    for(int j=0; j<9; ++j)
        if (array_cell[j]!=0)
            ++arr_unity3[array_cell[j]-1];

    for (int i=0;i<9;i++)
    {
        if(arr_unity1[i]==0&&arr_unity2[i]==0&&arr_unity3[i]==0)
            vec.push_back(i+1);
    }
        //if(vec.size()==0)
            //vec.push_back(1);
        /*for (int i=0;i<vec.size();i++){
            cout << vec.at(i) <<" ";
        }
        cout <<endl;*/

}





bool Sudoku::search()
{
    vector<int> vec;
	int firstZero;
	firstZero = getFirstZeroIndex();
    FindFirst(firstZero,vec);

	if(firstZero == -1)
	{ // end condition
		if(isCorrect())
		{

            for (int i=0;i<81;++i){
                answer[i]=map[i];
            }

			return true;
		}
		else
			return false;
	}


	else
	{
	    	//FindFirst(firstZero);

		for(int num=0; num<vec.size(); ++num)
		{

			setElement(firstZero, vec.at(num));
					/*for(int i=0; i<81; i++)
		{
			cout << getElement(i) << " ";
			if(i%9==8)
				cout << endl;
		}

			system("pause");*/

			if(solvee())
				return true;
		}
        setElement(firstZero, 0);
		return false;
	}
}
bool Sudoku::isCorrect()
{
	bool check_result;
	int check_arr[9];
	int location;
	for(int i=0; i<81; i+=9) // check rows
	{
		for(int j=0; j<9; ++j)

			check_arr[j] = map[i+j];

		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	}
	for(int i=0; i<9; ++i) // check columns
	{
		for(int j=0; j<9; ++j)

			check_arr[j] = map[i+9*j];

		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	}

	for(int i=0; i<9; ++i) // check cells
	{
		for(int j=0; j<9; ++j)
		{
            location = 27*(i/3) + 3*(i%3) + 9*(j/3) + (j%3);
            check_arr[j] = map[location];
		}

		check_result = checkUnity(check_arr);
		if(check_result == false)
			return false;
	}
	return true;
}
int Sudoku::solvee()
{
    vector<int> vec;
	int firstZero;
	firstZero = getFirstZeroIndex();
    FindFirst(firstZero,vec);

	if(firstZero == -1)
	{ // end condition
		if(isCorrect())
		{

            for (int i=0;i<81;++i){
                answer[i]=map[i];
            }
            count++;
			//return true;
			if(count==2)
                return 2;
            //else if(count==1)
             //   return 1;

		}

	}


	else
	{
	    	if(count==2)
                return 2;
	    	//FindFirst(firstZero);
		for(int num=0; num<vec.size(); ++num)
		{

			setElement(firstZero, vec.at(num));
					/*for(int i=0; i<81; i++)
		{
			cout << getElement(i) << " ";
			if(i%9==8)
				cout << endl;
		}

			system("pause");*/
            //int a=0;
            solvee();





		}
        setElement(firstZero, 0);
        if(count==2)
                return 2;
		//return 0;
	}
}
bool Sudoku::checkUnity(int arr[])
{
	int arr_unity[9]; // counters

	for(int i=0; i<9; ++i)
		arr_unity[i] = 0; // initialize
	for(int i=0; i<9; ++i)

		++arr_unity[arr[i]-1];
	//

	for(int i=0; i<9; ++i)

		if(arr_unity[i] != 1)
			//


			return false;
	//

	return true;
}
void Sudoku::setElement(int index, int value)
{
	map[index] = value;
}
int Sudoku::getFirstZeroIndex()
{
	for(int i=0;i<sudokuSize;++i)
		if(map[i] == 0)
			return i;
	return -1;
}
