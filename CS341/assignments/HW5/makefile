OBJS	= driver.o TreeNode.o BinarySearchTree.o RedBlackTree.o
SOURCE	= driver.cpp TreeNode.cpp BinarySearchTree.cpp RedBlackTree.cpp
HEADER	= TreeNode.h BinarySearchTree.h RedBlackTree.h
OUT	= out.exe
FLAGS	= -g -c -Wall
LFLAGS	= 
CC	= g++

all:	out.exe

out.exe: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

driver.o: driver.cpp
	$(CC) $(FLAGS) driver.cpp 

TreeNode.o: TreeNode.cpp
	$(CC) $(FLAGS) TreeNode.cpp

BinarySearchTree.o: BinarySearchTree.cpp
	$(CC) $(FLAGS) BinarySearchTree.cpp

RedBlackTree.o: RedBlackTree.cpp
	$(CC) $(FLAGS) RedBlackTree.cpp

clean:
	rm -f $(OBJS) $(OUT)
