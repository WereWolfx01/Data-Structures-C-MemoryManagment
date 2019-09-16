#include "ds_memory.h"

int main() {

  printf("sizeof( struct ds_counts_struct ) = %ld\n", sizeof( struct ds_counts_struct ));
  printf("sizeof( struct ds_blocks_struct ) = %ld\n", sizeof( struct ds_blocks_struct ));
  printf("sizeof( struct ds_file_struct ) = %ld\n", sizeof( struct ds_file_struct ));

  if ( ds_init( "test.bin" ) == 0 ) {
    printf("success\n");
    ds_test_init();
  }
  else {
    printf("failure\n");
  }

  return 0;
}
