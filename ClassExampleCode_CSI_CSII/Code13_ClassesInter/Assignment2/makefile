#Created by Don Spickler  1/21/2022

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Thing.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Thing.o : Thing.h Thing.cpp
	$(CC) $(CPPFLAGS) -c Thing.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
