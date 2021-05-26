# Hannah Hunt
# makefile for project

CC = gcc
CFLAGS = -Wall -g

SRC = ./src/
INC = ./include/
OBJ = ./obj/

all : Semantics.o CodeGen.o IOMngr.o SymTab.o main.o
	yacc -d ExprEval.y
	lex lex1.l
	$(CC) $(CFLAGS) $(OBJ)*.o -I $(INC) ./lex.yy.c ./y.tab.c 

main.o : Semantics.o  CodeGen.o IOMngr.o SymTab.o 
	$(CC) $(CFLAGS) -c $(SRC)main.c -I $(INC) -o $(OBJ)main.o

# GENERATION AND ROUTINE STUFF ---------------------------------------------------------
Semantics.o : SymTab.o IOMngr.o CodeGen.o $(INC)Semantics.h $(SRC)Semantics.c
	$(CC) $(CFLAGS) -c $(SRC)Semantics.c -I $(INC) -o $(OBJ)Semantics.o

CodeGen.o : $(INC)CodeGen.h 
	$(CC) $(CFLAGS) -c $(SRC)CodeGen.c -I $(INC) -o $(OBJ)CodeGen.o

# IOMNGR STUFF -----------------------------------------------------------
IOMngr.o : $(INC)IOMngr.h 
	$(CC) $(CFLAGS) -c $(SRC)IOMngr.c -I $(INC) -o $(OBJ)IOMngr.o

# SYMTAB STUFF -----------------------------------------------------------
SymTab.o : $(INC)SymTab.h
	$(CC) $(CFLAGS) -c $(SRC)SymTab.c -I $(INC) -o $(OBJ)SymTab.o