CC = gcc
CFLAGS = -Werror

obj_files = vec_funcs.o prob1.o prob2.o prob3.o
src_files = main.c vec_funcs.c prob1.c prob2.c prob3.c

.PHONY: all, clean

main: main.c $(obj_files)
	$(CC) main.c $(obj_files) $(CFLAGS) -o main

$(objects): %.o: %.c
	$(CC) -c $^ -o $@ $(CFLAGS)

clean:
	rm -rf *.o
