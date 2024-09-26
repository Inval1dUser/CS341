OBJS	= card.o driver.o standardDeck.o
SOURCE	= card.cpp driver.cpp standardDeck.cpp
HEADER	= card.h standardDeck.h
OUT	= Cards.exe
FLAGS	= -g3 -c -Wall
LFLAGS	= 
CC	= g++

all:	Cards.exe

Cards.exe: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

card.o: card.cpp
	$(CC) $(FLAGS) card.cpp 

driver.o: driver.cpp
	$(CC) $(FLAGS) driver.cpp 

standardDeck.o: standardDeck.cpp
	$(CC) $(FLAGS) standardDeck.cpp

clean:
	rm -f $(OBJS) $(OUT)

valgrind: Cards.exe
	valgrind Cards.exe

valgrind_leakcheck: Cards.exe
	valgrind --leak-check=full Cards.exe

valgrind_extreme: Cards.exe
	valgrind --leak-check=full --show-leak-kinds=all --leak-resolution=high --track-origins=yes --vgdb=yes Card