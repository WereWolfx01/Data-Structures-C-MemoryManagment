#include "ds_memory.h"

int main() {

  printf("sizeof( struct ds_counts_struct ) = %ld\n", sizeof( struct ds_counts_struct ));
  printf("sizeof( struct ds_blocks_struct ) = %ld\n", sizeof( struct ds_blocks_struct ));
  printf("sizeof( struct ds_file_struct ) = %ld\n", sizeof( struct ds_file_struct ));

  if ( ds_create("test.bin", 1234) == 0 ) {
    printf("success\n");
  }
  else {
    printf("failure\n");
  }

  return 0;
}
