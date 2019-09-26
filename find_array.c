#include "ds_array.h"
#include <stdlib.h>

int main ( int argc, char **argv )
{
  int value, result;

  if (argc !=2)
  {
    fprintf(stderr, "Usage: %s index\n", argv[0]);
    return -1;
  }
  value = atoi(argv[1]);

  ds_init_array();
  result = ds_find(value);
  ds_finish_array();
  printf("result = %d\n", result);
  return 0;
}
