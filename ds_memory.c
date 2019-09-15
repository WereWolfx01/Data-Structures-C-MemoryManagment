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
  if ( fp == NULL ) {
    return 1;
  }
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
