all: chained-stack

chained-stack: main.o chained-stack.o developer.o
	gcc -o chained-stack main.o chained-stack.o developer.o -ansi -Wall -pedantic -g
	
main.o: main.c chained-stack.h developer.h
	gcc -o main.o -c main.c -ansi -Wall -pedantic -g
	
chained-stack.o: chained-stack.c
	gcc -o chained-stack.o -c chained-stack.c -ansi -Wall -pedantic -g

developer.o: developer.c
	gcc -o developer.o -c developer.c -ansi -Wall -pedantic -g	
	
clean:
	rm -rf *.o *~ chained-stack