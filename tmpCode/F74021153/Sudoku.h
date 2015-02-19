#include <iostream>
#include <cstdlib>
using namespace std;


class Sudoku{
    public:
    	Sudoku();
    	Sudoku(const int init_map[]);
    	void setMap(const int set_map[]);
    	int getElement(int index);
    	bool checkUnity(int arr[]);
    	bool isCorrect();
    	int ReadIn();
    	int Solve();
    	int GiveQuestion();
    	static const int sudokuSize = 81;

    private:
    	int map[sudokuSize];
        int zero_Place[sudokuSize];
        int Possible_Ans[sudokuSize][10];
        int result[sudokuSize];

};