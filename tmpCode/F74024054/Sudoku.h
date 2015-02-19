using namespace std;


class Sudoku {
public:
Sudoku();
Sudoku(const int init_map[]);
void setMap(const int set_map[]);
int getElement(int index);
bool isCorrect();

int Solve(int index = 0);
int getFirstZeroIndex();

int getAns();
static int Ans;
int GiveQuestion();
int ReadIn();
void setElement(int index,int value);
static const int sudokuSize = 81;
private:
bool checkUnity(int arr[]);
int map[sudokuSize];
int PlacesOfZero[sudokuSize];//0?????
void setAns(int a);
int PossAns[sudokuSize][10];
int result[sudokuSize];

};


