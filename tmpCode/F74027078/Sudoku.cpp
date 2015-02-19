#include <iostream>
#include <iomanip>
#include "Sudoku.h"
#include <stdlib.h>
#include <time.h>
 
using namespace std;

Sudoku::Sudoku(){
	for(int i=0; i<size;i++){
		for(int j=0;j<size;j++)
			map[i][j] =0;
	 
	}
}
Sudoku::Sudoku( const int init_map[9][9]){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++)
			map[i][j] = init_map[i][j];
	}
}

void Sudoku::setMap( const int init_map [9][9]){
	for(int i=0; i<9; i++){
                for(int j=0; j<9; j++)
                        map[i][j] = init_map[i][j];
	}
}
void Sudoku::setAnswer(const int init_map[9][9])
{		for(int i=0; i<9; i++)
			{
                	for(int j=0; j<9; j++)
                        givenAnswer[i][j] = init_map[i][j];
        		}
}
void Sudoku::setArrayToCompare( const int init_map[9][9]){
		for(int i=0; i<9;i++){
			for(int j=0; j<9; j++){
				arrayToCompare[i][j] = init_map[9][9];
				}
			
			}
}

void Sudoku::GiveQuestion(){
	
	resolution_gQuestion();
	/*generateZeros();*/
	PrintAnswer();
}
void Sudoku::ReadIn(){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cin>>map[i][j];	
		}	
	}
}		
void Sudoku::Solve(){
	int res;	
	res=resolution();
	cout<<res<<endl;	
	if(res == 1) PrintAnswer(); 
}

void Sudoku::PrintAnswer(){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++)
			cout<<setw(2)<<givenAnswer[i][j];
		cout<<endl;
	}	
}
void Sudoku::PrintCompared(){
	for(int i=0; i<size; i++){
                for(int j=0; j<size; j++)
                        cout<<setw(2)<<givenAnswer[i][j];
                cout<<endl;
        }
}

// Use to randomly create a valid 9*9 solved sudoku
void Sudoku::GenerateRandom(){ 
	bool numberPresent[9] = {0};
	int randNumber;
	srand(time(NULL));
	for(int i=(size/3); i<size-3; i++){
		for(int j=(size/3); j<size-3; j++){
			do{
			  randNumber = rand()%10;}while(numberPresent[randNumber-1]!=0|| randNumber==0);
			map[i][j] = randNumber;
			numberPresent[randNumber-1]++;
			}
		}

}
void Sudoku::PrintMap(){
	for(int i=0; i<size; i++){
		for(int j=0; j<size; j++){
			cout<<setw(2)<<map[i][j];
			}
		cout<<endl;
		}
}

/*---------------ISVALID_FUNCTION_MEMBER-------------------------------------*/
int Sudoku::isValid ( LIST* position)
        {
	static int counter =0;
	srand(time(NULL));
	int arrStoreValues[9]= {0};
	int rK[9];
	int r=0;
for(int m=0; m<9; m++){
do{ r=rand()%9;}while(arrStoreValues[r]);
        arrStoreValues[r]++;
	rK[m] = r;
}
#ifdef DEBUG
#endif
	if(position== NULL){


		return true;
		}
	int i = position->i, j=position->j; 
	for (int k=0; k < 9; k++)
    	{
        // Verify in arrays if the value exists
       	 if ( !existOnLign[i][rK[k]] && !existOnColumn[j][rK[k]]
		 && !existOnBloc[3*(i/3)+(j/3)][rK[k]] )
       	 {
           	 // Add k to stored values
           		 existOnLign[i][rK[k]] = existOnColumn[j][rK[k]]
				 = existOnBloc[3*(i/3)+(j/3)][rK[k]] = true;

           		 if (isValid(position->next) )
         		   {
               		 // write the good choice in map
               		 givenAnswer[i][j] = rK[k]+1;
 /*       #ifdef DEBUG
cout<<"\n";
PrintAnswer();
cout<<"\n";
#endif
     
*/	  		 return true;
			}
            // delete stored k values
            existOnLign[i][rK[k]] = existOnColumn[j][rK[k]] 
			= existOnBloc[3*(i/3)+(j/3)][rK[k]] = false;
        }
    }

    return false;
}

// Calculate the number of possible values
int Sudoku::possible_nbs ( int i, int j)
{
    int ret = 0;
    for (int k=0; k < 9; k++)
        if ( !existOnLign[i][k] && !existOnColumn[j][k] && !existOnBloc[3*(i/3)+(j/3)][k] )
            ret++;
    return ret;
}

/*----------------------------RESOLUTION_FUNCTION_MEMBER----------*/
int Sudoku::resolution()
{
static int counter =0;
static int counterCompare = 0;
static int arr2[9][9]= {0};
	setAnswer(map ); 
    //initialize arrays
 do{   for (int i=0; i < 9; i++)
        for (int j=0; j < 9; j++)
            existOnLign[i][j] = existOnColumn[i][j] = existOnBloc[i][j] = false;
    // Store in arrays all the existing values
    int k;
    for (int i=0; i < 9; i++)
        for (int j=0; j < 9; j++)
            if ( (k = map[i][j]) != 0)
                existOnLign[i][k-1] = existOnColumn[j][k-1] = existOnBloc[3*(i/3)+(j/3)][k-1] = true;
    // create and fill a list for empty cases to visit
    LIST* positions = NULL;
    for (int i=0; i < 9; i++)
       for (int j=0; j < 9; j++)
            if (map[i][j] == 0 )
                liste_cons ( &positions, i, j, possible_nbs( i, j) );
    // Sort the list (- to +)
    positions = list_sort (positions);
    // Call of backtracking recursive isValid()

 if(counter == 0){
	counter= isValid( positions);

	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			arr2[i][j] = givenAnswer[i][j];}}
	setArrayToCompare( givenAnswer);
	 }
	 else if(counter >0 && counter<2)
		{
		isValid( positions);	
		if(!isSameArrays(givenAnswer, arr2)){
		
		
		 counter++;}
		
		else counterCompare++;
		}
#ifdef DEBUG
	cout<<"COUNTER : "<<counter<<endl; 
#endif
liste_delete (&positions);
	if(counterCompare>200) return counter;;
	}while( counter<2 && counter>0  );		

         
	/*if(retr>=2 || retr ==0) return retr;
	else resolution();	*/
	 

    // Delete the list
  
    // return resul
    return counter;
}
/*
void Sudoku::generateBlock(){
	int randNumber;
	bool numberPresent[9]= {0};
	srand(time(NULL));
 for(int i=0; i<3; i++){
                for(int j=0; j<3; j++){
                        do{
                          randNumber = rand()%10;}while(numberPresent[randNumber-1]!=0|| randNumber==0);
                        map[i][j] = randNumber;
                        numberPresent[randNumber-1]++;
                        }
                }
}*/
void Sudoku::generateZeros(){
	int r, temp;
	int i,j;
	int randCounter[9][9]={0};
	srand(time(NULL));
	int numberOfZeros = (55+rand()%16);	

	for(int k=0;k<numberOfZeros;k++){
 	ssleep(1000);
	do{
	i=rand()%9;
	j=rand()%9;}while( randCounter[i][j]);
	temp = givenAnswer[i][j];
	randCounter[i][j]++;
	givenAnswer[i][j] = 0;
	}
			
	
}
	
	
bool Sudoku::isSameArrays(const int arr1[9][9], const int arr2[9][9]){
	
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			if(arr1[i][j]!= arr2[i][j])return false;
			
			}
		}
	return true;
}	
/*------------------------- Linked List-------------------*/
// return new initialized element
static LIST* new_elem (int i, int j, int n)
{
    LIST* ret = (LIST*) malloc(sizeof* ret);
    if (ret != NULL)
        ret->i = i, ret->j = j, ret->nbPossibleValues = n, ret->next = NULL;
    return ret;
}

// delete entirely linked list
void liste_delete (LIST** list)
{
    LIST* tmp;
    while ( (tmp = *list) != NULL)
        *list = (*list)->next, free(tmp);
}

// add at the head
void liste_cons (LIST** list, int i, int j, int n)
{
    LIST* elem = new_elem (i, j, n);
    if (elem != NULL)
        elem->next = *list, *list = elem;
}
// insertion in sorted list
void insertion (LIST** list, LIST* elem)
{
    if (*list == NULL)
        *list = elem, elem->next = NULL;
    else if ((*list)->nbPossibleValues < elem->nbPossibleValues)
        insertion (&(*list)->next, elem);
    else
        elem->next = *list, *list = elem;
}

// sort insertion in linked list
LIST* list_sort (LIST* list)
{
    LIST *curr, *list2 = NULL, *tmp;
    for (curr = list; curr != NULL; curr = tmp)
    {
        tmp = curr->next;
        insertion (&list2, curr);
    }
    return list2;}

int Sudoku::getArrayToCompare(int i, int j){

	return arrayToCompare[i][j];
	}
/****IsValid 2**********/
/*
int Sudoku::isValid ( LIST* position)
        {
        srand(time(NULL));
        int arrStoreValues[9]= {0};
        int rK[9];
        int r=0;
for(int m=0; m<9; m++){
do{ r=rand()%9;}while(arrStoreValues[r]);
        arrStoreValues[r]++;
        rK[m] = r;
}
#ifdef DEBUG
static int o=0;
cout<<"r : "<<setw(2)<<r;
if(o>=20){ o=0;
cout<<" "<<endl;
}
o++;
#endif

        if(position== NULL){
              return true ;
                }
        int i = position->i, j=position->j;
        for (int k=0; k < 9; k++)
        {
        // Verify in arrays if the value exists
         if ( !existOnLign[i][rK[k]] && !existOnColumn[j][rK[k]]
                 && !existOnBloc[3*(i/3)+(j/3)][rK[k]] )
         {
                 // Add k to stored values
                         existOnLign[i][rK[k]] = existOnColumn[j][rK[k]]
                                 = existOnBloc[3*(i/3)+(j/3)][rK[k]] = true;

                         if (isValid(position->next) )
                           {
                         // write the good choice in map
                         map[i][j] = rK[k]+1;
                         return true;
                        }
            // delete stored k values
            existOnLign[i][rK[k]] = existOnColumn[j][rK[k]]
                        = existOnBloc[3*(i/3)+(j/3)][rK[k]] = false;
        }
    }

    return false;
}*/

/*-----------------GIVE_QUESTION :   RESOLUTION_2---------------------------*/



int Sudoku::resolution_gQuestion()
{

	setAnswer(map ); 
    //initialize arrays
 for (int i=0; i < 9; i++)
        for (int j=0; j < 9; j++)
            existOnLign[i][j] = existOnColumn[i][j] = existOnBloc[i][j] = false;
    // Store in arrays all the existing values
    int k;
    for (int i=0; i < 9; i++)
        for (int j=0; j < 9; j++)
            if ( (k = map[i][j]) != 0)
                existOnLign[i][k-1] = existOnColumn[j][k-1] = existOnBloc[3*(i/3)+(j/3)][k-1] = true;
    // create and fill a list for empty cases to visit
    LIST* positions = NULL;
    for (int i=0; i < 9; i++)
       for (int j=0; j < 9; j++)
            if (map[i][j] == 0 )
                liste_cons ( &positions, i, j, possible_nbs( i, j) );
    // Sort the list (- to +)
    positions = list_sort (positions);

	/*for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			arr2[i][j] = givenAnswer[i][j];}}*/
#ifdef DEBUG
#endif
//Call of backtracking recursive isValid()
bool ret =isValid( positions);
    // Delete the list
  liste_delete (&positions);
    // return resul
    return ret;
}