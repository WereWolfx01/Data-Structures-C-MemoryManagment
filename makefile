all: myprog

myprog: ds_memory.h ds_memory.c main.c
	gcc -ansi -pedantic -Wall ds_memory.c -o ds_memory.o -c
	gcc -ansi -pedantic -Wall main.c -o main.o -c
	gcc -ansi -pedantic -Wall	-o myprog main.o ds_memory.o

clean:
	rm *.o
	rm myprog
