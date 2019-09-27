#include "ds_list.h"
#include "ds_array.h"
#include "ds_memory.h"


void ds_create_list()
{
  long value = -1;
  ds_init( "list.bin" );
  ds_malloc( sizeof(long) );
  ds_write( 0, &value, sizeof(long) );
  ds_finish();
}

int ds_init_list()
{
  if ( ds_init( "list.bin" ) != 0 )
  {
    return -1;
  }
  return 0;
}

int ds_insert( int value, long index )
{
  struct ds_list_item_struct new, previous;
  long address;
  long int previous_loc = 0;
  int i;

  ds_read( &previous.next, 0, sizeof(long) );

  for ( i=index; i>0; i--)
  {
    if( previous.next == -1 )
    {
      return -1;
    }
    previous_loc = previous.next;
    ds_read( &previous, previous_loc, 16 );
  }
  new.item = value;
  new.next = previous.next;
  address = ds_malloc( sizeof(struct ds_list_item_struct) );
  previous.next = address;
  ds_write( address, &new, sizeof(struct ds_list_item_struct) );

  if (previous_loc == 0) {
    ds_write( 0, &address, sizeof(long) );
    return 0;
  }
  else {
    ds_write( previous_loc, &previous, sizeof(struct ds_list_item_struct));
  }
  return 0;
}

int ds_finish_list()
{
  if (ds_finish() != 0)
  {
    return -1;
  }
  return 0;
}

void show_list()
{
  long loc;
  struct ds_list_item_struct li;

  ds_test_init();
  ds_read( &loc, 0, sizeof(long) );
  while ( loc != (-1) )
  {
    printf("test\n");
    ds_read( &li, loc, sizeof(struct ds_list_item_struct) );
    printf("%ld item=%d next=%ld\n", loc, li.item, li.next);
    loc = li.next;
  }
  ds_finish_list();
}
