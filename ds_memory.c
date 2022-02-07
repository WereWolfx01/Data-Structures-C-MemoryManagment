

#include "ds_memory.h"

struct ds_file_struct ds_file;
struct ds_counts_struct ds_counts;

int ds_create( char *filename, long size ) {
  int i;
  FILE *fp;

  ds_file.block[0].start = 0;
  ds_file.block[0].length = size;
  ds_file.block[0].alloced = '0';

  for (i=1; i<MAX_BLOCKS; i++) {
    ds_file.block[i].start = 0;
    ds_file.block[i].length = 0;
    ds_file.block[i].alloced = '0';
  }
  fp = fopen( filename, "wb" );
  if ( fwrite( ds_file.block, sizeof(struct ds_blocks_struct), MAX_BLOCKS, fp ) != MAX_BLOCKS) {
    return 1;
  }

  for (i=0; i<size; i++) {
    if ( fputc(0, fp) == EOF ) {
      return 1;
    }
  }


  if ( fclose( fp ) != 0 ) {
    return 1;
  }


  return 0;
}


int ds_init( char *filename ) {
  ds_file.fp = fopen( filename, "rb+" );
  if ( ds_file.fp == NULL ) {
    return -1;
  }
  if ( fread( ds_file.block, sizeof(struct ds_blocks_struct), MAX_BLOCKS, ds_file.fp ) != MAX_BLOCKS ) {
    return -1;
  }
  ds_counts.reads = 0;
  ds_counts.writes = 0;


  return 0;
}

void ds_test_init() {
  int i;

  printf("Block #      start      length      alloced\n");
  for (i=0; i<MAX_BLOCKS; i++) {
  printf("     %d        %ld         %ld           %c\n", i, ds_file.block[i].start, ds_file.block[i].length, ds_file.block[i].alloced);
  }
  printf("reads: %d\n", ds_counts.reads);
  printf("writes: %d\n", ds_counts.writes);
}

long ds_malloc( long amount ) {
  long i, j;
  /*printf("searching for block with amount %ld\n", amount);*/
  for( i=0; i<MAX_BLOCKS; i++ ) {
    if( ds_file.block[i].length >= amount && ds_file.block[i].alloced == '0' ) {
      for( j=0; j<MAX_BLOCKS; j++ ) {
        if( ds_file.block[j].length == 0 ) {
          ds_file.block[j].start = ds_file.block[i].start + amount;
          ds_file.block[j].length = ds_file.block[i].length - amount;
          ds_file.block[j].alloced = '0';
          break;
        }
      }
      /*printf("block %ld with length = %ld is not yet alloced\n", i, ds_file.block[i].length);*/
      ds_file.block[i].length = amount;
      ds_file.block[i].alloced = '1';
      return ds_file.block[i].start;
    }
  }
  return -1;
}

void ds_free( long start ) {
  int i;
  for( i=0; i<MAX_BLOCKS; i++) {
    if( ds_file.block[i].start == start ) {
      ds_file.block[i].alloced = '0';
      break;
    }
  }
}

int ds_finish() {

  /*return 0 if unsuccessful */

  fseek(ds_file.fp, 0, SEEK_SET); /*Seek to start of file*/
  fwrite( ds_file.block, sizeof(struct ds_blocks_struct), MAX_BLOCKS, ds_file.fp );
  if ( fclose(ds_file.fp) != 0 )
  {
    return 0;
  }
  printf("reads: %d\n", ds_counts.reads);
  printf("writes: %d\n", ds_counts.writes);


  return 1;

}

void *ds_read( void *ptr, long start, long bytes ) {

  fseek( ds_file.fp, sizeof(ds_file.block)+start, SEEK_SET );
  fread( ptr, 1, bytes, ds_file.fp );\
  ds_counts.reads++;
  return ptr;
}

long ds_write( long start, void *ptr, long bytes ) {
  fseek( ds_file.fp, sizeof(ds_file.block)+start, SEEK_SET );
  fwrite( ptr, bytes, 1, ds_file.fp );
  ds_counts.writes++;
  return start;
}
