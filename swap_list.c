#include "ds_list.h"
#include <stdlib.h>

int main ( int argc, char **argv )
{
  long index1, index2;

  if (argc !=3)
  {
    fprintf(stderr, "Usage: %s index1 index2 \n", argv[0]);
    return -1;
  }
  index1 = atol(argv[1]);
  index2 = atol(argv[2]);

  ds_init_list();
  ds_swap(index1 , index2);
  ds_finish_list();

  return 0;
}
