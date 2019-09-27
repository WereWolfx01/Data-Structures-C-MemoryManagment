#include "ds_list.h"
#include <stdlib.h>

int main ( int argc, char **argv )
{
  ds_init_list();
  ds_read_elements("elements.txt");
  ds_finish_list();
  return 0;
}
