all: chained-queue

chained-queue: main.o chained-queue.o developer.o
	gcc -o chained-queue main.o chained-queue.o developer.o -ansi -Wall -pedantic -g
	
main.o: main.c chained-queue.h developer.h
	gcc -o main.o -c main.c -ansi -Wall -pedantic -g
	
chained-queue.o: chained-queue.c
	gcc -o chained-queue.o -c chained-queue.c -ansi -Wall -pedantic -g

developer.o: developer.c
	gcc -o developer.o -c developer.c -ansi -Wall -pedantic -g	
	
clean:
	rm -rf *.o *~ chained-queue