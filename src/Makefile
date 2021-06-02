run : Matrix.o BNN.o main.o
	clang++ Matrix.o BNN.o main.o -o run

test : Matrix.o BNN.o tests.o
	clang++ Matrix.o BNN.o tests.o -o test

main.o : main.cpp
	clang++ -c main.cpp

BNN.o : BNN.cpp BNN.h
	clang++ -c BNN.cpp

Matrix.o : Matrix.cpp Matrix.h
	clang++ -c Matrix.cpp

tests.o : tests.cpp
	clang++ -c tests.cpp

clean : 
	rm run *.o test *.o











