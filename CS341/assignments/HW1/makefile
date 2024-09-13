OBJS	= Student.o driver.o
SOURCE	= Student.cpp driver.cpp
HEADER	= Student.h
OUT	= GPA.exe
FLAGS	= -g -c -Wall
LFLAGS	= 
CC	= g++

all:	GPA.exe

GPA.exe: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

Student.o: Student.cpp
	$(CC) $(FLAGS) Student.cpp 

driver.o: driver.cpp
	$(CC) $(FLAGS) driver.cpp 

clean:
	rm -f $(OBJS) $(OUT)
