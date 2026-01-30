#Created by Don Spickler  2/18/2023

PROG = prog
CC = g++
CPPFLAGS = -g -Wall -std=c++11
OBJS = main.o IntegerList.o Die.o

OBJDIR = ./obj

OBJECT_FILES=$(addprefix $(OBJDIR)/, $(OBJS))

MKDIR_P = mkdir -p

.PHONY: directories

all: directories $(PROG)

directories: ${OBJDIR}

${OBJDIR}:
	${MKDIR_P} ${OBJDIR}

$(PROG) : $(OBJECT_FILES)
	$(CC) -o $(PROG) ${OBJECT_FILES}

$(OBJDIR)/main.o : main.cpp
	$(CC) $(CPPFLAGS) -o ${OBJDIR}/main.o -c main.cpp

$(OBJDIR)/IntegerList.o : IntegerList.h IntegerList.cpp
	$(CC) $(CPPFLAGS) -o ${OBJDIR}/IntegerList.o -c IntegerList.cpp

$(OBJDIR)/Die.o : Die.h Die.cpp
	$(CC) $(CPPFLAGS) -o ${OBJDIR}/Die.o -c Die.cpp

clean:
	rm -f core $(PROG) ${OBJDIR}/*.o

rebuild:
	make clean
	make
