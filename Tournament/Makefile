all: ./tmpCode/hw2_check.o ./tmpCode/Sudoku.o
	g++ -o ./tmpCode/hw2_check ./tmpCode/hw2_check.o ./tmpCode/Sudoku.o

./tmpCode/hw2_check.o: ./Code/hw2_check.cpp ./tmpCode/Sudoku.h
	g++ -c ./Code/hw2_check.cpp -o ./tmpCode/hw2_check.o

./tmpCode/Sudoku.o: ./tmpCode/Sudoku.h ./tmpCode/Sudoku.cpp
	g++ -c ./tmpCode/Sudoku.cpp -o ./tmpCode/Sudoku.o

clean:
	rm ./tmpCode/*

