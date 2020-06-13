all: stack

stack: main.o stack.o developer.o
	gcc -o stack main.o stack.o developer.o -ansi -Wall -pedantic -g
	
main.o: main.c stack.h developer.h
	gcc -o main.o -c main.c -ansi -Wall -pedantic -g
	
stack.o: stack.c
	gcc -o stack.o -c stack.c -ansi -Wall -pedantic -g

developer.o: developer.c
	gcc -o developer.o -c developer.c -ansi -Wall -pedantic -g	
	
clean:
	rm -rf *.o *~ stack