#include <iostream>
#include <vector>
using namespace std;

class Map {

	public:
		Map();
		int getElement(int index);
		void setElement(int index, int value);
		vector<int> check_only(int zero);
		int getFirstZeroIndex();
		bool isCorrect();
		static const int sudokuSize = 81;

	private:
		bool checkUnity(int arr[]);
		int map[sudokuSize];
};

class Sudoku {

	public:
		Sudoku();
		int getAnswer(Map question, Map & answer);
		void Solve();
		void ReadIn();	
		void GiveQuestion();
		Map question;
		Map answer;
	private:
		int count;

};
