#include "ds_memory.h"
#include <stdio.h>

int main() {

  unsigned char c1,c2;
  unsigned short s1,s2;
  unsigned int i1,i2;
  unsigned long l1,l2;
  float f1,f2;
  double d1,d2;

  long memory[12];
  int i;

  c1=1;
  c2=3;
  s1=3;
  s2=4;
  i1=5;
  i2=6;
  l1=7;
  l2=8;
  f1=9.0;
  f2=10.0;
  d1=11.0;
  d2=12.0;

  ds_create( "test.bin", 1234 );
  ds_init( "test.bin" );
  memory[0] = ds_malloc( sizeof(c1) );
  ds_write( memory[0], &c1, sizeof(c1) );
  printf("memory 0 = %ld \n", memory[0]);
  memory[1] = ds_malloc( sizeof(c2) );
  ds_write( memory[1], &c2, sizeof(c2) );
  printf("memory 1 = %ld \n", memory[1]);
  ds_free( memory[1] );

  memory[2] = ds_malloc( sizeof(s1) );
  ds_write( memory[2], &s1, sizeof(s1) );
  printf("memory 2 = %ld \n", memory[2]);
  memory[3] = ds_malloc( sizeof(s2) );
  ds_write( memory[3], &s2, sizeof(s2) );
  printf("memory 3 = %ld \n", memory[3]);
  ds_free( memory[3] );

  memory[4] = ds_malloc( sizeof(i1) );
  ds_write( memory[4], &i1, sizeof(i1) );
  printf("memory 4 = %ld \n", memory[4]);
  memory[5] = ds_malloc( sizeof(i2) );
  ds_write( memory[5], &i2, sizeof(i2) );
  printf("memory 5 = %ld \n", memory[5]);
  ds_free( memory[5] );

  memory[6] = ds_malloc( sizeof(l1) );
  ds_write( memory[6], &l1, sizeof(l1) );
  printf("memory 6 = %ld \n", memory[6]);
  memory[7] = ds_malloc( sizeof(l2) );
  ds_write( memory[7], &l2, sizeof(l2) );
  printf("memory 7 = %ld \n", memory[7]);
  ds_free( memory[7] );

  memory[8] = ds_malloc( sizeof(f1) );
  ds_write( memory[8], &f1, sizeof(f1) );
  printf("memory 8 = %ld \n", memory[8]);
  memory[9] = ds_malloc( sizeof(f2) );
  ds_write( memory[9], &f2, sizeof(f2) );
  printf("memory 9 = %ld \n", memory[9]);
  ds_free( memory[9] );

  memory[10] = ds_malloc( sizeof(d1) );
  ds_write( memory[10], &d1, sizeof(d1) );
  printf("memory 10 = %ld \n", memory[10]);
  memory[11] = ds_malloc( sizeof(d2) );
  ds_write( memory[11], &d2, sizeof(d2) );
  printf("memory 11 = %ld \n", memory[11]);
  ds_free( memory[11] );

  printf("Remaining memory allocations:\n");
  for(i=0;i<12;i+=2) {
    printf("%ld\n", memory[i]);
  }

  ds_test_init();
  ds_finish();


  return 0;
}
