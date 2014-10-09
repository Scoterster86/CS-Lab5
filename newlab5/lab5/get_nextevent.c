//Scott Iwanicki
//finle includes rr_nextevent and fi_nextevent
#include <stdio.h>
#include <stdlib.h>
#include "globvar.h"
//processes the process for time_slice then returns the process to the event list to be
//re-inserted in the rr queue if it still needs cpu service, else
//the process is finished with the cpu add the process to the IO queue

int rr_nextevent(Link *rrheadPtr,Link *rrtailPtr,Link *fcfsheadPtr,Link *fcfstailPtr,Link *eventPtr){
  Link tempPtr;
  Link somePtr;
  Link headPtr;
  Link tailPtr;
  //sets pointers to the structs the input pointers are pointing to
  //except for the round robin tail pointer
  tempPtr = *rrheadPtr;
  somePtr= *eventPtr;
  headPtr= *fcfsheadPtr;
  tailPtr= *fcfstailPtr;

  //sets *rrheadPtr to the pointer the struct is pointing to
  *rrheadPtr= (*rrheadPtr)->link;

  //running total of the time spent in the cpu queue
  (tempPtr->cpu_wait) = (tempPtr->cpu_wait) + TIME-(tempPtr->arrival_time);

  //print out when the process enters the cpu
  printf("Process %d enters the CPU at time %.2f seconds\n", (tempPtr->process_id), TIME*.1);

  //if the process will need more service at the cpu:
  if( (tempPtr->cpu_time) > TIME_SLICE){
    
    //subtracts the processed time (time slice) from the needed processing time
    (tempPtr->cpu_time) = (tempPtr->cpu_time) - TIME_SLICE;
    (tempPtr->arrival_time) = TIME + TIME_SLICE;

    //re-adds the process to the event list to be placed back in the queue for the cpu 
    add_event(tempPtr->process_id, tempPtr->arrival_time, tempPtr->cpu_time, tempPtr->io_time, &somePtr, tempPtr->cpu_wait, tempPtr->io_wait, tempPtr->total_time);
    *eventPtr = somePtr;
  }

  //if the process will be done with service from the cpu:
  else{
    
    //sets the cpu time needed to 0, the arrival time to the IO queue,
    // and inserts the process in the io queue
    (tempPtr->cpu_time) = 0;
    (tempPtr->arrival_time)=TIME+TIME_SLICE;
    io_enqueue(&headPtr, &tailPtr, &tempPtr);
    *fcfsheadPtr=headPtr;
    *fcfstailPtr=tailPtr;
  }
  
  //sets the time when the cpu is free
  RR_TIME= TIME+TIME_SLICE;
  return 0;
}



//fi_nextevent
//processes the next process until it is done needing service, then removes the process
//from the simulation
int fi_nextevent(Link *fcfsheadPtr){
  Link tempPtr;

  //sets tempPtr to the srucht *fcfsheadPtr is pointing to
  tempPtr = *fcfsheadPtr;

  //sets *fcfsheadPtr to the pointer the struct is pointing to
  *fcfsheadPtr = ((*fcfsheadPtr)->link);
  //Prints out when the process arrives at the IO
  printf("Process %d arrives at IO at time %.2f seconds\n", (tempPtr->process_id), TIME*.1);

  //sets the time when the io is free
  if(FI_TIME==0){
    FI_TIME=(tempPtr->arrival_time)+ (tempPtr->io_time);
  }
  else{
    FI_TIME= TIME + (tempPtr->io_time);
  }

  //the time spent waiting in the queue for the io
  if(TIME==0){
    tempPtr->io_wait = 0;
  }
  else{
    tempPtr->io_wait =(TIME -(tempPtr->arrival_time)+TIME_SLICE);
  }

  //inputs the processes data into an array for output
  output[PROC_NUM][0] = (tempPtr->process_id);
  output[PROC_NUM][1] = (tempPtr->cpu_wait)*.1;
  output[PROC_NUM][2] = (tempPtr->io_wait)*.1;
  output[PROC_NUM][3] = (FI_TIME-(tempPtr->total_time))*.1;

  //prints out the process's leaving statement
  printf("Process %d leaves the I/O at %.2f seconds\n", tempPtr->process_id, FI_TIME*.1);
  

  //adds the processing time to the total time the io spent processing
  TOTAL_IO= TOTAL_IO +(tempPtr->io_time);

  //frees the memory of the removed process
  free(tempPtr);

  //removes a process fomr the total processes in/waiting for service
  PROCESS_LEFT--;
  PROC_NUM++;
  return 0;
}  
