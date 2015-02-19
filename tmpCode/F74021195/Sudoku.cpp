#include "Sudoku.h"

Sudoku::Sudoku() {
}
void Sudoku::GiveQuestion() {
	vector<int> q(81, 0), v;

	for (int i = 1; i <= 9; i++) v.push_back(i);
	srandom(time(NULL));
	random_shuffle(v.begin(), v.end());

	q.at(53) = q.at(74) = v.at(0);
	q.at(50) = q.at(62) = v.at(1);
	q.at(5) = q.at(35) = q.at(72) = v.at(2);
	q.at(0) = q.at(77) = v.at(3);
	q.at(37) = q.at(70) = v.at(4);
	q.at(10) = q.at(40) = q.at(69) = v.at(5);
	
	q.at(39) = q.at(47) = v.at(7);
	q.at(16) = v.at(8);

	for (int i = 0; i < 81; i++) {
		printf("%d ", q.at(i));
		if (i % 9 == 8) putchar('\n');
	}
}
void Sudoku::ReadIn() {
	int t;
	
	question.clear();
	for (int i = 0; i < 81; i++) {
		if (scanf("%d", &t) == 1 && t >= 0 && t <= 9) question.push_back(t);
		else break;
	}
}
void Sudoku::Solve() {
	int n = 0;
	vector<int> answer;

	if ((question.size() == 81) && isValid(question)) backtrack(question, answer, n);
	printf("%d\n", n);
	if (n == 1) {
		for (int i = 0; i < 81; i++) {
			printf("%d ", answer.at(i));
			if (i % 9 == 8) putchar('\n');
		}
	}
}
int Sudoku::getFirstZeroIndex(vector<int>& v) {
	for (int i = 0; i < 81; i++) {
		if (v.at(i) == 0) return i;
	}
	return -1;
}
bool Sudoku::isValid(vector<int>& v) {
	for (int i = 0; i < 9; i++) {	//row
		for (int j = 0; j < 9; j++) {
			for (int k = j + 1; k < 9; k++) {
				if ((v.at(i*9+j) != 0) && (v.at(i*9+j) == v.at(i*9+k))) return false;
			}
		}
	}
	for (int i = 0; i < 9; i++) {	//column
		for (int j = 0; j < 9; j++) {
			for (int k = j + 1; k < 9; k++) {
				if ((v.at(i+j*9) != 0) && (v.at(i+j*9) == v.at(i+k*9))) return false;
			}
		}
	}
	for (int i = 0; i < 9; i++) {	//cell
		for (int j = 0; j < 9; j++) {
			for (int k = j + 1; k < 9; k++) {
				int l = (i/3)*27+(i%3)*3;
				if ((v.at(l + (j/3)*9+(j%3)) != 0) && (v.at(l + (j/3)*9+j%3) == v.at((l + (k/3)*9+k%3)))) return false;
			}
		}
	}
	return true;
}
bool Sudoku::isCorrect(vector<int>& v) {
	vector<int> counter;

	for (int i = 0; i < 9; i++) {	//row
		counter.assign(9, 0);
		for (int j = 0; j < 9; j++) {
			if (++counter.at(v.at(i*9+j)-1) != 1) return false;
		}
	}
	for (int i = 0; i < 9; i++) {	//column
		counter.assign(9, 0);
		for (int j = 0; j < 9; j++) {
			if (++counter.at(v.at(i+j*9)-1) != 1) return false;
		}
	}
	for (int i = 0; i < 9; i++) {	//cells
		counter.assign(9, 0);
		for (int j = 0; j < 9; j++) {
			if (++counter.at(v.at(27*(i/3)+3*(i%3) + 9*(j/3)+j%3)-1) != 1) return false;
		}
	}
	return true;
}
void Sudoku::backtrack(vector<int>& q, vector<int>& a, int& n) {
	int firstZero;

	firstZero = getFirstZeroIndex(q);
	if ((firstZero == -1) && isCorrect(q)) {
		if (++n == 2) {
			puts("2");
			exit(0);
		}
		a = q;
		return;
	}
	for (int i = 1; i <= 9; i++) {
		int t;
		bool b = true;
		
		t = firstZero / 9;	//row
		for (int j = 0; (j < 9) && b; j++) {
			if (q.at(t * 9 + j) == i) {
				b = false;
				break;
			}
		}
		if (!b) continue;

		t = firstZero % 9;	//column
		for (int j = 0; (j < 9) && b; j++) {
		if (q.at(j * 9 + t) == i) {
				b = false;
				break;
			}
		}
		if (!b) continue;

		if (firstZero / 9 <= 2) {	//cell
			if (firstZero % 9 <= 2) t = 0;
			else if ((firstZero % 9 >= 3) && (firstZero % 9 <= 5)) t = 3;
			else t = 6;
		} else if ((firstZero / 9 >= 3) && (firstZero / 9 <= 5)) {
			if (firstZero % 9 <= 2) t = 27;
			else if ((firstZero % 9 >= 3) && (firstZero % 9 <= 5)) t = 30;
			else t = 33;
		} else {
			if (firstZero % 9 <= 2) t = 54;
			else if ((firstZero % 9 >= 3) && (firstZero % 9 <= 5)) t = 57;
			else t = 60;
			}
		for (int j = 0; (j < 9) && b; j++) {
			if (q.at(t) == i) {
				b = false;
				break;
			}
			t += (t % 3 == 2) ? 7 : 1;
		}
		if (!b) continue;
		
		q.at(firstZero) = i;
		backtrack(q, a, n);
		q.at(firstZero) = 0;
	}
}
