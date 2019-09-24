#include "ds_array.h"
#include "ds_memory.h"

int ds_create_array()
{
  long temp;
  int array[MAX_ELEMENTS];
  temp = 0;
  ds_init("array.bin");
  ds_malloc(sizeof(long));
  ds_write(0, &temp, 8);
  ds_malloc(sizeof(array));
  ds_finish();
  /* if non successful return value other than 0*/
  return 0;
}

int ds_init_array()
{
  long temp = 1;
  ds_init("array.bin");
  ds_read( &temp, 0, sizeof(long) );
  elements = temp;
  printf("temp = %ld\n", temp);
  /*if unsuccessful returnvalue other than 0*/
  return 0;
}

void show_array()
{
  int i, temp;
  ds_test_init();
  printf("elements = %ld\n", elements);
  for (i=0; i<elements; i++)
  {
    ds_read( &temp, sizeof(long)+(sizeof(int)*i), 4 );
    printf("element %d = %d\n", i, temp);
  }
}

int ds_replace( int value, long index )
{
  return 0;
}

int ds_insert( int value, long index )
{
  return 0;
}

int ds_delete( long index )
{
  return 0;
}

int ds_swap( long index1, long index2 )
{
  return 0;
}

long ds_find( int target )
{
  return 0;
}

int ds_read_elements( char *filename )
{
  return 0;
}

int ds_finish_array()
{
  ds_write(0, &elements, sizeof(elements));
  ds_finish();
  /*return non 0 if non successful*/
  return 0;
}
