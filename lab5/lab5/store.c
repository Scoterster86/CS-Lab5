//Scott Iwanicki
//Runs when bot reaches a store
//outputs notification when bot reaches store
#include <stdio.h>
#include "globvar.h"
//prototypes
int timecheck();
int storecomplete(){
  printf("robot %d arrives at store S(%d,%d) on the %d Floor at time %d\n", BOTNUM, xpos, ypos, (zpos+1), TIME);
  if(zpos==0){
    TIME++;
    timecheck();
  }
  else{
    TIME++;
    timecheck();
    TIME++;
    timecheck();
  }
  return 0;
}
