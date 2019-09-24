CFLAGS = -ansi -pedantic -Wall
CC = gcc
HEADER = ds_memory.h
HEADER2 = ds_array.h


all: ds_memory main a1_create a1_malloc a1_view a1_write a1_read ds_array create_array show_array

ds_memory: $(HEADER) ds_memory.c
	$(CC) $(CFLAGS) ds_memory.c -o ds_memory.o -c

main: $(HEADER) main.c ds_memory
	$(CC) $(CFLAGS) main.c ds_memory.o -o main

a1_create: $(HEADER) a1_create.c ds_memory
	$(CC) $(CFLAGS) a1_create.c ds_memory.o -o a1_create

a1_malloc: $(HEADER) a1_malloc.c ds_memory
	$(CC) $(CFLAGS) a1_malloc.c ds_memory.o -o a1_malloc

a1_view: $(HEADER) a1_view.c ds_memory
	$(CC) $(CFLAGS) a1_view.c ds_memory.o -o a1_view

a1_write: $(HEADER) a1_write.c  ds_memory
	$(CC) $(CFLAGS) a1_write.c ds_memory.o -o a1_write

a1_read: $(HEADER) a1_read.c  ds_memory
	$(CC) $(CFLAGS) a1_read.c ds_memory.o -o a1_read

ds_array: $(HEADER2) $(HEADER) ds_array.c
	$(CC) $(CFLAGS) ds_array.c -o ds_array.o -c

create_array: $(HEADER2) $(HEADER) create_array.c ds_array ds_memory
	$(CC) $(CFLAGS) create_array.c ds_array.o ds_memory.o -o create_array

show_array: $(HEADER2) $(HEADER) show_array.c ds_array ds_memory
	$(CC) $(CFLAGS) show_array.c ds_array.o ds_memory.o -o show_array

clean:
	rm *.o
	rm main
	rm a1_malloc
	rm a1_create
	rm a1_view
	rm a1_write
	rm a1_read
	rm create_array
	rm show_array
	rm *.bin
