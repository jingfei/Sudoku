#ifndef __ZIPCODE_H_
#define __ZIPCODE_H_

#include<iostream>
#include<fstream>
using namespace std;

class Sudoku
{
private:
	int num[9][9];
	bool search(int num[][9]);
	int List(int num[][9], int freeCell[][2]);
	bool isValid(int i, int j, int num[][9]);
	bool isValid(int num[][9]);

public:
	void setinput();
	void getoutput();
	Sudoku(char *inname);
};

#endif 