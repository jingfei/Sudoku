#include"Sudoku.h"


void Sudoku::ReadIn()
{
    /*ofstream output;
    output.open("infile");
	cout << "Enter a Sudoku puzzle:" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++){
			cin >> num[i][j];
			output << num[i][j] << " ";
		}
		output << "\n";
	}
	output.close();*/

	int i=0, j=0;
	int temp;
	ifstream infile;
	infile.open("output.txt");
	if (!infile) {
		cerr<<"Failed opening"<<endl;
		exit(1);
	}

	while (infile >> temp) {
		num[i][j] = temp;
		i++;
		if(i==9) {
			j++; i=0;
		}
	}

}

void Sudoku::GiveQuestion()
{
    int number[9] = {};
    int x;

    srandom(time(0));
    for(int i = 0; i<9; i++){
       x = rand() % 9 + 1;
       number[i] = x;
       for(int j = 0; j<i; ++j){
          if(x == number[j]){number[i] = 0; i= i-1;}
       }
    }
    int puzzle[9][9] = {{number[7], 0,number[6],number[1], number[2],number[0],0, 0,0}, //erease some number to have a unique solvble puzzle
                        {number[1], 0,0,0, 0,number[3],number[7], number[8],0},
                        {0, number[5],0,0, number[8],number[6],0,0,0},
                        {number[6], 0,0,0, number[1],0,number[3], number[4],number[5]},
                        {number[0], 0,0,0,0,0,0,0,number[8]},
                        {number[3], number[4],number[5],0, number[7],0,0,0,number[2]},
                        {0,0,0,number[2], number[0],0,0, number[3],0},
                        {0, number[0],number[1],number[5],0,0,0,0,number[7]},
                        {0,0,0,number[8], number[6],number[7],number[2],0,number[1]},
                       };
    cout<<"Here you have a Sudoku puzzle, have fun \n";
    ofstream outfile;
    outfile.open("output.txt");
    if(!outfile){
       cerr<<"Failed opening"<<endl;
       exit(1);
    }
    for(int i = 0; i<9; ++i){
       for(int j = 0; j<9; ++j){
          outfile<<puzzle[i][j]<<" ";
          cout<<puzzle[i][j]<<" ";
       }
       outfile<<endl;
       cout<<endl;
    }
    outfile.close();
}

void Sudoku::Solve()
{
	ofstream outfile;
	outfile.open("output.txt");
	if (!isCorrect(num))
		outfile<<"Invalid input"<< endl;
	else if (Compare(num)) {
	    outfile<<"1 \n";
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++){
				outfile<< num[j][i] << " ";
                cout<<num[j][i]<<" ";
            }
			outfile<< endl;
			cout<<endl;
		}
	} else
		outfile << "doesn't have solution" << endl;

}

int Sudoku::NumberofZeros(int grid[][9], int freeCellList[][2])
{

	int numberOfFreeCells = 0;

	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (grid[i][j] == 0) {
				freeCellList[numberOfFreeCells][0] = i;
				freeCellList[numberOfFreeCells][1] = j;
				numberOfFreeCells++;
			}

			return numberOfFreeCells;
}


bool Sudoku::Compare(int num[][9])
{
	int k = 0;
	bool found = false;
	int freeCell[81][2];
	int numberOfFreeCells = NumberofZeros(num, freeCell);

	while (!found) {
		int i = freeCell[k][0];
		int j = freeCell[k][1];
		if (num[i][j] == 0)  num[i][j] = 1;

		if (isCorrect(i, j, num)) {
			if (k + 1 == numberOfFreeCells) {
				found = true;
			} else {
				k++;
			}
		} else if (num[i][j] < 9) {
			num[i][j] = num[i][j] + 1;
		} else {
			while (num[i][j] == 9) {
				num[i][j] = 0;
				if (k == 0)	return false;
				k--;
				i = freeCell[k][0];
				j = freeCell[k][1];
			}
			num[i][j] = num[i][j] + 1;
		}
	}

	return true;
}


bool Sudoku::isCorrect(int i, int j, int num[][9]){

   for (int column = 0; column < 9; column++){
      if (column != j && num[i][column] == num[i][j]) return false;

   }

	for (int row = 0; row < 9; row++){
		if (row != i && num[row][j] == num[i][j]) return false;
	}

	for (int row = (i / 3) * 3; row < (i / 3) * 3 + 3; row++){
       for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; col++){
		  if (row != i && col != j && num[row][col] == num[i][j]) return false;

       }
	}

	return true;
}


bool Sudoku::isCorrect(int num[][9]){

	for (int i = 0; i < 9; i++){
       for (int j = 0; j < 9; j++){
          if (num[i][j] != 0){
             if (!isCorrect(i, j, num)) return false;
          }
       }
	}
	for (int i = 0; i < 9; i++){
       for (int j = 0; j < 9; j++){
          if ((num[i][j] < 0) || (num[i][j] > 9)) return false;
       }
	}

	return true;
}
