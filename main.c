#include "ds_memory.h"

int main() {
  long val;
  printf("sizeof( struct ds_counts_struct ) = %ld\n", sizeof( struct ds_counts_struct ));
  printf("sizeof( struct ds_blocks_struct ) = %ld\n", sizeof( struct ds_blocks_struct ));
  printf("sizeof( struct ds_file_struct ) = %ld\n", sizeof( struct ds_file_struct ));

  if ( ds_create( "test.bin", 1234 ) == 0 ) {
    printf("success\n");
  }
  else {
    printf("failure\n");
  }
  val = ds_malloc(10);
  printf("return value of 10 is %ld\n", val);
  printf("return value of 123456 is %ld\n", ds_malloc(123456));
  ds_free(val);
  ds_test_init();
  return 0;
}
