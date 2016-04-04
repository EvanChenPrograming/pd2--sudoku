all: Sudoku.o giveQuestion.cpp solve.cpp transform.cpp
	g++ -o giveQuestion.o giveQuestion.cpp Sudoku.o
	g++ -o solve.o solve.cpp Sudoku.o
	g++ -o transform.o transform.cpp Sudoku.o

Sudoku.o: Sudoku.cpp Sudoku.h
	g++ -c Sudoku.cpp -o Sudoku.o

clean:
	rm solve tramsform giveQuestion *.o
