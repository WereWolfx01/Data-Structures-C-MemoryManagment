#include "ds_list.h"
#include <stdlib.h>

int main ( int argc, char **argv )
{
  long index;

  if (argc !=2)
  {
    fprintf(stderr, "Usage: %s value index \n", argv[0]);
    return -1;
  }
  index = atol(argv[1]);

  ds_init_list();
  ds_delete(index);
  ds_finish_list();

  return 0;
}
