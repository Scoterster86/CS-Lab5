//Scott Iwanicki
#include <stdio.h>
#include <stdlib.h>
#include "globvar.h"
int add_event(int pid, int arrival, int  cpu, int io, Link *sPtr, int cpu_time, int io_time, int total){
  Link  newPtr;      // new node
  Link  previousPtr; // previous node
  Link  currentPtr;  // current node

  // dynamically allocate memory
  newPtr = malloc( sizeof(Node) );

  // if newPtr does not equal NULL
  if ( newPtr ) {
    newPtr->process_id = pid;
    newPtr->arrival_time = arrival;
    newPtr->cpu_time = cpu;
    newPtr->io_time = io;
    newPtr->link = NULL;
    newPtr->cpu_wait = cpu_time;
    newPtr->io_wait = cpu_time;
    newPtr->total_time = total;
    previousPtr = NULL;

    // set currentPtr to start of list
    currentPtr = (*sPtr);

    // loop to find correct location in list
    while ( currentPtr!=NULL && arrival > (currentPtr->arrival_time)) {
      previousPtr = currentPtr;
      currentPtr = currentPtr->link;
    } // end while

    // insert at beginning of list
    if (previousPtr == NULL) {
      newPtr->link = *sPtr;
      *sPtr = newPtr;
    } //end if
    else if(currentPtr != NULL){
      if((currentPtr->arrival_time) == arrival){

	//if the arrival times are the same add the processes with the lower id first
	if(pid <(currentPtr->process_id)){
	  newPtr->link = (currentPtr->link);
	  currentPtr->link = newPtr;
	}
	else{ 
	  // insert node between previousPtr and currentPtr
	  previousPtr->link = newPtr;
	  newPtr->link = currentPtr;
	} // end else
      }
      else {
	// insert node between previousPtr and currentPtr
	previousPtr->link = newPtr;
	newPtr->link = currentPtr;
      } // end else
    }//end else if != Null

    else{
      // insert node between previousPtr and currentPtr
      previousPtr->link = newPtr;
      newPtr->link = currentPtr;
    } // end else
    
  } // end if
  else {
    printf( "No memory available.\n");
  } // end else
  return 0;
}
