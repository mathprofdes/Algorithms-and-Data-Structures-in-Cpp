#Created by Don Spickler  1/21/2022

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Vector.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Vector.o : Vector.h Vector.cpp
	$(CC) $(CPPFLAGS) -c Vector.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
