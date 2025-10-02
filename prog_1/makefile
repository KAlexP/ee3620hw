CC = gcc
CFLAGS = -Werror

objects = main.c vec_funcs.o prob1.o prob2.o prob3.o

all: $(objects)
	$(CC) $^ -o main

$(objects): %.o: %.c
	$(CC) -c $^ -o $@

main.c:
	echo "Error Main doesn't exist"

clean:
	rm -rf *.o
