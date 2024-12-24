all: run

profunc.o: profunc.c profunc.h
	gcc -c profunc.c

prog: main.c profunc.o
	gcc main.c profunc.o -o prog

run: prog
	./prog

clean:
	rm *.o prog
