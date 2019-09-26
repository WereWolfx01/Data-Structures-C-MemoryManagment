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
  long size;
  if ( (index >= elements) || (index < 0) )
  {
    /*printf("Invalid index\n");*/
    return 1;
  }
  size = index * sizeof(int) + sizeof(elements);
  ds_write( size, &value, 4 );
  /*return other than 0 if unssuccessful invalid index for example*/
  return 0;
}

int ds_insert( int value, long index )
{
  int old, new, i;
  long location;
  new = value;
  for (i=index; i<=elements; i++)
  {
    location = (i * sizeof(int)) + sizeof(elements);
    ds_read( &old, location, 4 );
    ds_write( location, &new, 4);
    new = old;
    /*return other than 0 if unsuccessful*/

  }
  elements++;


  return 0;
}

int ds_delete( long index )
{
  int i, temp;
  long current, next;
  if ( (index >= elements) || (index < 0) || (elements == 0) ) {
    printf("Invalid index\n");
    return 1;
  }
  for ( i=index; i<(elements-1); i++ )
  {
    current = ( ( i * sizeof(int) ) + sizeof(long) );
    next = ( ( (i+1) * sizeof(int) ) + sizeof(long) );
    ds_read( &temp, next, 4 );
    ds_write( current, &temp, 4 );
  }
  elements--;
  /*return other than 0 if unssuccessful*/
  return 0;
}

int ds_swap( long index1, long index2 )
{
  int temp1, temp2;
  long address1, address2;
  if ( (index1 >= elements) || (index2 >= elements) || (index1 < 0) || (index2 < 0) )
  {
    printf("Invalid index\n");
    return 1;
  }
  address1 = (index1 * sizeof(int)) + sizeof(long);
  address2 = (index2 * sizeof(int)) + sizeof(long);
  ds_read( &temp1, address1, 4 );
  ds_read( &temp2, address2, 4 );
  ds_write( address2, &temp1, 4 );
  ds_write( address1, &temp2, 4 );

  return 0;
}

long ds_find( int target )
{
  int i, temp;
  long address;
  for ( i=0; i<elements; i++ )
  {
    address = (i * sizeof(int)) + sizeof(long);
    ds_read( &temp, address, 4 );
    if ( temp == target )
    {
      return i;
    }
  }
  return -1;

  return 0;
}

int ds_read_elements( char *filename )
{
  FILE *fp;
  int value;
  long index;
  fp = fopen(filename, "r");
  if ( !(fp) )
  {
    /*printf("Error cannot open file\n");*/
    return 1;
  }

  while (!feof(fp))
  {
    if ( fscanf( fp, "%d", &value) != 1 )
    {
      break;
    }
    if ( index > MAX_ELEMENTS ) {
      return 1;
    }
    ds_insert( value, index );

    index++;
  }
  /*return non 0 if unssucessful, file errors, exceeding MAX elements*/

  return 0;
}

int ds_finish_array()
{
  ds_write(0, &elements, sizeof(elements));
  ds_finish();
  /*return non 0 if non successful*/
  return 0;
}
