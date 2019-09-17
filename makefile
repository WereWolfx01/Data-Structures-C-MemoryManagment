CFLAGS = -ansi -pedantic -Wall
CC = gcc


all: myprog a1_create a1_malloc a1_view

myprog: main
	$(CC) $(CFLAGS)	main.o ds_memory.o -o myprog

ds_memory: ds_memory.c
	$(CC) $(CFLAGS) ds_memory.c -o ds_memory.o -c

main: ds_memory
	$(CC) $(CFLAGS) main.c -o main.o -c

a1_create: a1_create.c
	$(CC) $(CFLAGS) a1_create.c ds_memory.o -o a1_create

a1_malloc: a1_malloc.c
	$(CC) $(CFLAGS) a1_malloc.c ds_memory.o -o a1_malloc

a1_view: a1_view.c
	$(CC) $(CFLAGS) a1_view.c ds_memory.o -o a1_view

clean:
	rm *.o
	rm myprog
	rm *.bin
