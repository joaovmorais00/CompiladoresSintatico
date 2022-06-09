all: main

main: main.c lexico.o 
	gcc -O3 lexico.o main.c -o main  -w

lexico.o: lexico.c lexico.h
	gcc -O3 -c  lexico.c  -w

clear:
	rm *.o