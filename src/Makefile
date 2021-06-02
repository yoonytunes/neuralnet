run : Matrix.o BNN.o main.o
	clang++ Matrix.o BNN.o main.o -o run

main.o : main.cpp
	clang++ -c main.cpp

BNN.o : BNN.cpp BNN.h
	clang++ -c BNN.cpp

Matrix.o : Matrix.cpp Matrix.h
	clang++ -c Matrix.cpp








