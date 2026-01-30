#Created by Don Spickler  1/21/2022

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Triangle.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Triangle.o : Triangle.h Triangle.cpp
	$(CC) $(CPPFLAGS) -c Triangle.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
