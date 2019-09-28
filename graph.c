#include <stdlib.h>
#include <stdio.h>
#include "ds_memory.h"
#include "ds_list.h"


int main ( int argc, char **argv )
{
  int numLines, i, randomInt, randomIndex;
  long index;
  FILE *fp;

  if (argc !=2)
  {
    fprintf(stderr, "Usage: %s int\n", argv[0]);
    return -1;
  }
  numLines = atoi(argv[1]);

  fp = fopen( "elements.txt", "w+" );
  for ( i=numLines; i>0; i-- )
  {
    randomInt = rand() % ((100 + 1 - 0) + 0);
    fprintf(fp, "%d\n", randomInt);
  }

  /*ds_init_list();
  ds_read_elements("elements.txt");
  ds_finish_list();*/

  /*
  ds_init_list();
  for( i=30; i>0; i--)
  {
    randomIndex = rand() % (((numLines-1) + 1 - 0) + 0);
    index = randomIndex;
    ds_replace(0 , index);
  }
  ds_finish_list();
*/

  return 0;
}
