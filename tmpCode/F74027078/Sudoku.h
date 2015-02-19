#ifndef SUDOKU_H
#include <iostream>
#include <time.h>
typedef struct _list
{
    int i, j;
    int nbPossibleValues;
    struct _list *next;
} LIST;

// return new initialized element
static LIST* new_elem (int i, int j, int n);

// delete entirely linked list
void liste_delete (LIST** list);
// add at the head
void liste_cons (LIST** list, int i, int j, int n);

// insertion in sorted list
void insertion (LIST** list, LIST* elem);
// sort insertion in linked list
LIST* list_sort (LIST* list);

class Sudoku {
	public:
	Sudoku();
	Sudoku( const int init_map[9][9]);
	void setMap(const int init_map[9][9]);
	void setAnswer(const int init_map[9][9]);
	void setArrayToCompare(const int init_map[9][9]);
	void GiveQuestion();
	void ReadIn();
	void Solve();
	void PrintAnswer();
	void PrintMap();
	void PrintCompared();
	const static int size=9;
	static int retr;
	int getArrayToCompare(int i, int j);
	private:
	int map[size][size];
	LIST* position;  // Will store number of possible values for each '0' case.
					// To optimize the solver; 
	int givenAnswer[size][size];
	int arrayToCompare[size][size];
	bool existOnLign[9][9]; // for memorisation
	bool existOnColumn[9][9];
	bool existOnBloc[9][9];
	int resolution_gQuestion();	
	int resolution();
	int possible_nbs ( int i, int j);	
	void GenerateRandom();
/*	void GenerateLeftBlock();*/
	int isValid ( LIST* position= 0);
/*	bool absentOnLign (int k, int i);
	bool absentOnColumn (int k, int j);
	bool absentOnBloc (int k , int i, int j);*/
	void generateBlock();
	bool isSameArrays(const int arr1[9][9], const int arr2[9][9]);
	void generateZeros();
/*bool AbsentOnLign(const int &k, const int &i, const int &untilWhere);
	bool absentOnBlock();*/
		
};


inline 
void ssleep(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
	

#endif