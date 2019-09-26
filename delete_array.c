#include "ds_array.h"
#include <stdlib.h>

int main ( int argc, char **argv )
{
  long index;

  if (argc !=2)
  {
    fprintf(stderr, "Usage: %s index\n", argv[0]);
    return -1;
  }
  index = atoi(argv[1]);

  ds_init_array();
  ds_delete(index);
  ds_finish_array();

  return 0;
}
