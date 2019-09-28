#include "ds_list.h"
#include <stdlib.h>

int main ( int argc, char **argv )
{

  int i, randomIndex, numLines;
  long index1, index2;

  if (argc !=2)
  {
    fprintf(stderr, "Usage: %s int\n", argv[0]);
    return -1;
  }
  numLines = atoi(argv[1]);

  ds_init_list();
  ds_read_elements("elements.txt");
  ds_finish_list();

  ds_init_list();
  for( i=30; i>0; i--)
  {
    randomIndex = rand() % (((numLines-1) + 1 - 0) + 0);
    index1 = randomIndex;
    randomIndex = rand() % (((numLines-1) + 1 - 0) + 0);
    index2 = randomIndex;
    printf("swapping %ld and %ld\n", index1, index2);
    ds_insert( 0, index1);
  }
  ds_finish_list();

  return 0;
}