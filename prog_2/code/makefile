main: main.c convolve.o matrix.o
	gcc -o main main.c convolve.o matrix.o

convolve.o: convolve.c convolve.h
	gcc -c convolve.c

matrix.o: matrix.c matrix.h
	gcc -c matrix.c
