OBJS	= driver.o Node.o LinkedNode.o LinkedList.o DoublyLinkedList.o
SOURCE	= driver.cpp Node.cpp LinkedNode.cpp LinkedList.cpp DoublyLinkedList.cpp
HEADER	= Node.h LinkedNode.h LinkedList.h DoublyLinkedList.h
OUT	= out.exe
FLAGS	= -g -c -Wall
LFLAGS	= 
CC	= g++

all:	out.exe

out.exe: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

driver.o: driver.cpp
	$(CC) $(FLAGS) driver.cpp 

Node.o: Node.cpp
	$(CC) $(FLAGS) Node.cpp 

LinkedNode.o: LinkedNode.cpp
	$(CC) $(FLAGS) LinkedNode.cpp

LinkedList.o: LinkedList.cpp
	$(CC) $(FLAGS) LinkedList.cpp

DoublyLinkedList.o: DoublyLinkedList.cpp
	$(CC) $(FLAGS) DoublyLinkedList.cpp

clean:
	rm -f $(OBJS) $(OUT)
