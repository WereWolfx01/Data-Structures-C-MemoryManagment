# Aeman Abdulmuhssen
# 1003984
# aabdulmu@uoguelph.ca
CFLAGS = -ansi -pedantic -Wall
CC = gcc
HEADER = ds_memory.h
HEADER2 = ds_array.h
HEADER3 = ds_list.h


all: ds_memory ds_array ds_list

ds_memory: $(HEADER) ds_memory.c
	$(CC) $(CFLAGS) ds_memory.c -o ds_memory.o -c

ds_array: $(HEADER2) $(HEADER) ds_array.c
	$(CC) $(CFLAGS) ds_array.c -o ds_array.o -c

ds_list: $(HEADER3) $(HEADER) ds_list.c
	$(CC) $(CFLAGS) ds_list.c -o ds_list.o -c

clean:
	rm *.o
	rm *.bin
