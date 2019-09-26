#include "ds_array.h"
#include <stdlib.h>

int main ( int argc, char **argv )
{
  long index1;
  long index2;

  if (argc !=3)
  {
    fprintf(stderr, "Usage: %s index1 index2\n", argv[0]);
    return -1;
  }
  index1 = atol(argv[1]);
  index2 = atol(argv[2]);

  ds_init_array();
  ds_swap(index1, index2);
  ds_finish_array();

  return 0;
}
