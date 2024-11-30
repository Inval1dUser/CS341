OBJS	= driver.o bitarray.o
SOURCE	= driver.cpp bitarray.cpp
HEADER	= bitarray.h
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

clean:
	rm -f $(OBJS) $(OUT)