run : ./src/Matrix.o ./src/BNN.o ./src/main.o
	clang++ ./src/Matrix.o ./src/BNN.o ./src/main.o -o run

test : ./src/Matrix.o ./src/BNN.o ./src/tests.o
	clang++ ./src/Matrix.o ./src/BNN.o ./src/tests.o -o test

main.o : ./src/main.cpp
	clang++ -c ./src/main.cpp

BNN.o : ./src/BNN.cpp ./include/BNN.h
	clang++ -c ./src/BNN.cpp

Matrix.o : ./src/Matrix.cpp ./include/Matrix.h
	clang++ -c ./src/Matrix.cpp

tests.o : ./src/tests.cpp
	clang++ -c ./src/tests.cpp

clean : 
	rm run test *.o ./src/*.o











