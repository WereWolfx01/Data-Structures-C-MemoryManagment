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

int ds_swap( long index1, long index2 )
{
  int i1, i2, temp1, temp2;
  long previous_loc, loc1 ,loc2;
  struct ds_list_item_struct previous, swap1, swap2;


  if (index1 == index2)
  {
    return 0;
  }
  else if( index1 > index2 )
  {
    i1 = index2;
    i2 = index1;
  }
  else
  {
    i1 = index1;
    i2 = index2;
  }

  ds_read( &previous.next, 0, sizeof(long) );
  for ( ; i1>0; i1--)
  {
    if( previous.next == -1 )
    {
      return -1;
    }
    previous_loc = previous.next;
    ds_read( &previous, previous_loc, 16 );
  }
  loc1 = previous.next;
  ds_read( &swap1, loc1, sizeof(struct ds_list_item_struct) );
  temp1 = swap1.item;

  ds_read( &previous.next, 0, sizeof(long) );
  for ( ; i2>0; i2--)
  {
    if( previous.next == -1 )
    {
      return -1;
    }
    previous_loc = previous.next;
    ds_read( &previous, previous_loc, 16 );
  }
  loc2 = previous.next;
  ds_read( &swap2, loc2, sizeof(struct ds_list_item_struct) );
  temp2 = swap2.item;

  swap1.item = temp2;
  swap2.item = temp1;

  ds_write( loc1, &swap1, sizeof(struct ds_list_item_struct) );
  ds_write( loc2, &swap2, sizeof(struct ds_list_item_struct) );

  return 0;
}

long ds_find( int target )
{
  int i = 0;
  struct ds_list_item_struct current;
  long location;
  ds_read( &current.next, 0, sizeof(long) );
  location = current.next;
  while ( location != -1)
  {
    ds_read( &current, location, sizeof(struct ds_list_item_struct) );
    if( current.item == target )
    {
      return i;
    }
    location = current.next;
    i++;
  }

  return -1;
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
