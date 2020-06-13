all: queue

queue: main.o queue.o developer.o
	gcc -o queue main.o queue.o developer.o -ansi -Wall -pedantic -g
	
main.o: main.c queue.h developer.h
	gcc -o main.o -c main.c -ansi -Wall -pedantic -g
	
queue.o: queue.c
	gcc -o queue.o -c queue.c -ansi -Wall -pedantic -g

developer.o: developer.c
	gcc -o developer.o -c developer.c -ansi -Wall -pedantic -g	
	
clean:
	rm -rf *.o *~ queue