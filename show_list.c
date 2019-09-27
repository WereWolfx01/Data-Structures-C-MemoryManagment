#include "ds_list.h"
#include "ds_memory.h"

int main ()
{

  ds_init_list();
  ds_insert( 0, 0 );
  ds_insert( 1, 1 );
  ds_insert( 1, 2 );
  ds_insert( -1, 0 );
  ds_insert( -2, 0 );
  ds_insert( -3, 0 );
  ds_insert( -5, 2 );

  show_list();
  return 0;
}
