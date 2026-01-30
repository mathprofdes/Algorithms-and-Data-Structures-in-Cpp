#Created by Don Spickler  1/21/2022

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o Budget.o Auxil.o

$(PROG) : $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o : main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

Budget.o : Budget.h Budget.cpp
	$(CC) $(CPPFLAGS) -c Budget.cpp

Auxil.o : Auxil.h Auxil.cpp
	$(CC) $(CPPFLAGS) -c Auxil.cpp

clean:
	rm -f core $(PROG) $(OBJS)

rebuild:
	make clean
	make
