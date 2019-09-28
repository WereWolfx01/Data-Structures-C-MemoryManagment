#include "ds_array.h"
#include <stdlib.h>

int main ( int argc, char **argv )
{
  int i, randomIndex, numLines;
  long index;

  if (argc !=2)
  {
    fprintf(stderr, "Usage: %s int\n", argv[0]);
    return -1;
  }
  numLines = atoi(argv[1]);


  ds_init_array();
  ds_read_elements("elements.txt");
  ds_finish_array();


  ds_init_array();
  for( i=30; i>0; i--)
  {
    randomIndex = rand() % (((numLines-1) + 1 - 0) + 0);
    index = randomIndex;
    printf("replacing %d at %ld\n", 0, index);
    ds_replace(0 , index);
  }
  ds_finish_array();
  return 0;
}
