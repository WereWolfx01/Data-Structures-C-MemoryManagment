all: add

myprog: ds_memory.h ds_memory.c main.c
	gcc -ansi -pedantic -Wall -c ds_memory.h ds_memory.c -o ds_memory.o
	gcc -ansi -pedantic -Wall -c mian.c -o main.o
	gcc -ansi -pedantic -Wall	-o myprog main.o ds_memory.o
