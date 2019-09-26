#include "ds_array.h"
#include <stdlib.h>

int main ( int argc, char **argv )
{
  ds_init_array();
  ds_read_elements("elements.txt");
  ds_finish_array();
  return 0;
}
