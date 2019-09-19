#include "ds_memory.h"
#include <stdio.h>

int main () {

  long memory;
  ds_init( "test.bin" );

  printf("calling ds_malloc(10)\n");
  memory = ds_malloc( 18 );
  printf("return value is %ld\n", memory);

  printf("calling ds_malloc(100000)\n");
  printf("return value is %ld\n", ds_malloc(100000));


  printf("calling ds_malloc(50)\n");
  printf("return value is %ld\n", ds_malloc(50));

  ds_free( memory );
  ds_finish();


  return 0;
}
