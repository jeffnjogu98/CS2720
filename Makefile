CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors -c $(DEBUG)
LFLAGS = -Wall -pedantic-errors $(DEBUG)

compile: main.o DoublyLinkedList.o
	$(CC) $(LFLAGS) -o main main.o DoublyLinkedList.o

main.o: main.cpp DoublyLinkedList.h 
	$(CC) $(CFLAGS) main.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp DoublyLinkedList.h
	$(CC) $(CFLAGS) DoublyLinkedList.cpp

run: compile
	./main

clean:
	rm -f main
	rm -f *.o

