#include "ds_array.h"
#include <stdlib.h>

int main ( int argc, char **argv )
{
  int value;
  long index;

  if (argc !=3)
  {
    fprintf(stderr, "Usage: %s value index \n", argv[0]);
    return -1;
  }
  value= atoi(argv[1]);
  index = atoi(argv[2]);

  ds_init_array();
  ds_replace(value , index);
  ds_finish_array();

  return 0;
}
