#Created by Don Spickler  1/21/2022

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Die.o yahtzee.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Die.o : Die.h Die.cpp
	$(CC) $(CPPFLAGS) -c Die.cpp

yahtzee.o : yahtzee.h yahtzee.cpp
	$(CC) $(CPPFLAGS) -c yahtzee.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
