#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;

class Sudoku{
	public:

		Sudoku();


		Sudoku(int init_map[]);


		void set_element(int index, int value);


		int get_element(int index);


		void set_map(int arr[]);


		int find_zero();


		bool check_correct(int arr[]);

		void output_map();


		void GiveQuestion();

		void ReadIn();

		void Solve();

		void my_solve();

		static const int sudokuSize = 81;

	private:

		int map[sudokuSize];
		int answer[sudokuSize];
		int counter;

		bool check_unity(int arr[9]);	

};
