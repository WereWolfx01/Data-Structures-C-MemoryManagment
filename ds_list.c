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

int ds_replace( int value, long index )
{
  int i;
  long previous_loc;
  struct ds_list_item_struct previous, current;

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
  ds_read( &current, previous.next, sizeof(struct ds_list_item_struct) );
  current.item = value;
  ds_write( previous.next, &current, sizeof(struct ds_list_item_struct) );

  return 0;
}

int ds_delete( long index )
{
  int i;
  long previous_loc, current_loc;
  struct ds_list_item_struct previous, current;

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
  if ( index == 0 ) /* if deleting element at index 0 */
  {
    if( previous.next == -1 )
    {
      return -1;
    }
    ds_read( &current, previous.next, sizeof(struct ds_list_item_struct) );
    ds_write( 0, &current.next, sizeof(long) );
    ds_free( previous.next );
    return 0;
  }
  ds_read( &current, previous.next, sizeof(struct ds_list_item_struct) );
  current_loc = previous.next;
  previous.next = current.next;
  ds_free( current_loc );
  ds_write( previous_loc, &previous, sizeof(struct ds_list_item_struct) );


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
    ds_read( &li, loc, sizeof(struct ds_list_item_struct) );
    printf("%ld item=%d next=%ld\n", loc, li.item, li.next);
    loc = li.next;
  }
  ds_finish_list();
}

int ds_read_elements( char *filename )
{
  FILE *fp;
  int value;
  long index = 0 ;
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
    ds_insert( value, index );
    printf("inserting %d at %ld\n", value, index);
    index++;
  }
  /*return non 0 if unssucessful, file errors, exceeding MAX elements*/

  return 0;
}
