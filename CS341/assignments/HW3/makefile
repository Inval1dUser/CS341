OBJS	= driver.o bitarray.o set.o dictionary.o
SOURCE	= driver.cpp bitarray.cpp set.cpp dictionary.cpp
HEADER	= bitarray.h set.h dictionary.h
OUT	= out.exe
FLAGS	= -g -c -Wall
LFLAGS	= 
CC	= g++

all:	out.exe

out.exe: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

driver.o: driver.cpp
	$(CC) $(FLAGS) driver.cpp 

bitarray.o: bitarray.cpp
	$(CC) $(FLAGS) bitarray.cpp 

set.o: set.cpp
	$(CC) $(FLAGS) set.cpp

dictionary.o: dictionary.cpp
	$(CC) $(FLAGS) dictionary.cpp

clean:
	rm -f $(OBJS) $(OUT)
