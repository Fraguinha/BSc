#A Simple Example Makefile for soshell
#
# Alvo: Dependencias
# tab Action 1
# tab Action 2
#
#Variaveis: Compiler, compiler flags, libraries to link, name of of object files
#
CC=cc
FLAGS=-c -Wall
LIBS=-lm
OBS=main.o execute.o parse.o socp.o redirects.o containsPipe.o aviso.o calc.o

#Alvo por defeito é o primeiro
all :  soshell

main.o : shell.h main.c
	$(CC) $(FLAGS) main.c
execute.o : shell.h execute.c
	$(CC) $(FLAGS) execute.c
parse.o : shell.h parse.c
	$(CC) $(FLAGS) parse.c
socp.o : shell.h socp.c
	$(CC) $(FLAGS) socp.c
redirects.o : shell.h redirects.c
	$(CC) $(FLAGS) redirects.c
containsPipe.o : shell.h containsPipe.c
	$(CC) $(FLAGS) containsPipe.c
calc.o : shell.h calc.c
	$(CC) $(FLAGS) calc.c
aviso.o : shell.h aviso.c
	$(CC) $(FLAGS) aviso.c
soshell : $(OBS)
	$(CC)  -o soshell  $(OBS) $(LIBS)
clean :
	rm -f soshell *.o
	echo "Limpeza dos ficheiros exectuaveis, objectos e gedit tralha"
