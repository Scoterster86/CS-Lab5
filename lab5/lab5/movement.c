//Scott Iwanicki
//Moves the robot in the specified direction
#include <stdio.h>

//prototypes
int timecheck();
int storecomplete();

int movement(int direction){
  int j;
  switch (direction){
  case North:
    //case 0  Moves up 4 rows and increments TIME by 1 for each movement
    for(j=0; j<4; j++){

      xpos--;
      TIME= TIME+1;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;
  case NorthWest:
    //printf("NW, %d %d %d", xpos, ypos, zpos);
    //case 1  Moves up 2 rows and up and to the right 3 times and 
    //increments TIME by 1 for each movement
    for(j=0; j<5; j++){
      if(j<2 && zpos==0){
	this.xpos=this.xpos--;
      }
      else if(j<2 && this.zpos==1){
	this.ypos--;
      }
      else{
	this.xpos= this.xpos--;
	this.ypos= this.ypos--;
      }
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
      break;
  case West:
    //printf("W");
    //case 2  Moves left 4 columns and increments TIME by 1 for each movement
    for(j=0; j<4; j++){
      this.ypos=this.ypos--;
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;
  case SouthWest:
    //printf("SW");
    //case 3  Moves down 2 rows, down and the to 
    //the left 3 times and increments TIME by 1
    for(j=0; j<5; j++){
      if(j<2 && this.zpos==0){
	this.ypos= this.ypos--;
      }
      else if(j<2 && this.zpos==1){
	this.xpos=this.xpos++;
      }
      else{
	this.xpos=this.xpos++;
	this.ypos=this.ypos--;
     }
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;
  case South:
    //printf("S");
    //case 4  Moves down 4 rows and increments TIME by 1 for each movement
    for(j=0; j<4; j++){
      this.xpos=xpos++;
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;
  case SouthEast:
    //printf("SE");
    //case 5  Moves down 2 rows, down and the right 3 times
    // and increments TIME by 1
    for(j=0;j<5;j++){
      if(j<2 && this.zpos==0){
	this.xpos=xpos++;
      }
      else if(j<2 && zpos==1){
	this.ypos=ypos++;
      }
      else{
	this.xpos=xpos++;
	this.ypos=ypos++;
      }
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;
  case East:
    //printf("E");
    //case 6 Moves right 4 columns and increments TIME by 1 for each movement
    for(j=0; j<4; j++){
      this.ypos=ypos++;
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;
  case NorthEast:
    //printf("NE");
    //case 7 Moves up a row and right a column and increments TIME by 1
    for(j=0;j<5;j++){
      if(j<2 && this.zpos==0){
	this.ypos++;
      }
      else if(j<2 && this.zpos==1){
	this.xpos--;
      }
      else{
	this.xpos--;
	this.ypos++;
      }
    TIME++;
    floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
    timecheck();
    }
    break;
  case Up:
    //printf("Up");
    //case 8 Moves up a floor, increments TIME by 3, and prints when the bot
    //got on and off the elevator
    this.zpos++;
    printf("robot %d got on elevator at time %d\n", BOTNUM, TIME);
    floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
    for(j=0;j<3;j++){
      TIME++;
      timecheck();
    }
    printf("robot %d got off elevator at time %d\n", BOTNUM, TIME);
    break;
  case Down:
    //printf("Down");
    //case 9 Moves down a floor and increments TIME by 3, and prints when the bot
    //got on and off the elevator
    this.zpos=this.zpos--;
    printf("robot %d got on elevator at time %d\n", BOTNUM, TIME);
    floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
    for(j=0;j<3;j++){
      TIME++;
      timecheck();
    }
    printf("robot %d got off elevator at time %d\n", BOTNUM, TIME);
    break;
  case StNorth:
    //printf("StN");
    //case 10 moves up two rows, enters the store, then moves down two rows
    //increments time by 1 for each movement
    for(j=0; j<5; j++){
      if(j<2){
        this.xpos= this.xpos--;
      }
      else if(j==2){
        storecomplete();
      }
      else{
        this.xpos=xpos++;
      }
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;
  case StSouth:
    //    printf("StS");
    //case 11 moves down two rows, enters the store, then moves up two rows
    //increments time by 1 for each movement
    for(j=0; j<5; j++){
      if(j<2){
        this.xpos=this.xpos++;
      }
      else if(j==2){
        storecomplete();
      }
      else{
        this.xpos=this.xpos--;
      }
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;
  case StEast:
    //    printf("StE");
    //case 12 moves right two columns, enters the store, then moves left two columns
    //increments time by 1 for each movement
    for(j=0; j<5; j++){
      if(j<2){
	this.ypos=this.ypos++;
      }
      else if(j==2){
	storecomplete();
      }
      else{
	this.ypos=this.ypos--;
      }
      TIME++;
      floor[xpos][ypos][zpos] = BOTNUM;
      timecheck();
    }
    break;
  case StWest:
    //   printf("StW");
    //case 13 moves left two columns, enters the store, then moves right two columns
    //increments time by 1 for each movement
    for(j=0; j<5; j++){
      if(j<2){
        this.ypos=ypos--;
      }
      else if(j==2){
        storecomplete();
      }
      else{
        this.ypos=ypos++;
      }
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;
  case StNorthWest:
    //    printf("StNW");
    //case 14 moves up a row and left a column, enters the store,
    // then moves down a row and right a column increments time by 1 for each movement
    for(j=0;j<3;j++){
      if(j==0){
	this.xpos=this.xpos--;
	ypos--;
      }
      else if(j==1){
	storecomplete();
      }
      else{
	this.xpos=xpos++;
	this.ypos=ypos++;
      }
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;
  case StNorthEast:
    //    printf("StNE");
    //case 15 moves up a row and right a column, enters the store,
    // then moves down a row and left a column increments time by 1 for each movement
    for(j=0;j<3;j++){
      if(j==0){
        this.xpos=this.xpos--;
        this.ypos=ypos++;
      }
      else if(j==1){
        storecomplete();
      }
      else{
        this.xpos=xpos++;
        this.ypos=ypos--;
      }
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;
  case StSouthEast:
    //case 16 moves down a row and right a column, enters the store,
    // then moves up a row and left a column increments time by 1 for each movement
    // printf("StSE");
    for(j=0;j<3;j++){
      if(j==0){
        this.xpos=xpos++;
        this.ypos=ypos++;
      }
      else if(j==1){
        storecomplete();
      }
      else{
        this.xpos=xpos--;
        this.ypos=ypos--;
      }
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;
  case StSouthWest:
    //case 15 moves down a row and left a column, enters the store,
    // then moves up a row and right a column, increments time by 1 for each movement 
    //printf("StSW");
    for(j=0;j<3;j++){
      if(j==0){
        this.xpos=xpos++;
        this.ypos=ypos--;
      }
      else if(j==1){
        storecomplete();
      }
      else{
        this.xpos=xpos--;
        this.ypos=ypos++;
      }
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;
  case NorthWest2:
    //    printf("%d %d %d",xpos, ypos,zpos);
    //case 16 Moves up a row and left a column and increments TIME by 1
    for(j=0;j<5;j++){
      if(j>2 && this.zpos==0){
        this.ypos=ypos--;
      }
      else if(j>2 && this.zpos==1){
        this.xpos--;
      }
      else{
        this.xpos=xpos--;
        this.ypos=ypos--;
      }
      //printf("NW2\n");
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;
  case NorthEast2:
    //printf("NE2");
    //case 17 Moves up a row and right a column and increments TIME by 1
    for(j=0;j<5;j++){
      if(j>2 && this.zpos==0){
        this.xpos=xpos--;
      }
      else if(j>2 && this.zpos==1){
        this.ypos=this.ypos++;
      }
      else{
        this.xpos=xpos--;
        this.ypos=ypos++;
      }
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;

  case SouthWest2:
    // printf("SW2");
    //case 18 Moves down a row and left a column and increments TIME by 1
    for(j=0;j<5;j++){
      if(j>2 && this.zpos==0){
        this.xpos=this.xpos++;
      }
      else if(j>2 && this.zpos==1){
        this.ypos=this.ypos--;
      }
      else{
        this.xpos=this.xpos++;
        this.ypos=this.ypos--;
      }
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;

  case SouthEast2:
    //printf("SE2");
    //case 19 Moves down a row and right a column and increments TIME by 1
    for(j=0;j<5;j++){
      if(j>2 && this.zpos==0){
        this.ypos++;
      }
      else if(j>2 && this.zpos==1){
        this.xpos=this.xpos++;
      }
      else{
        this.xpos=this.xpos++;
        this.ypos=ypos++;
      }
      TIME++;
      floor[this.xpos][this.ypos][this.zpos] = BOTNUM;
      timecheck();
    }
    break;
  case End:
    //case 20 Removes bot from simulation and prints out a notification
    printf("robot %d left the simulation at time %d\n", BOTNUM, TIME);
    bottimes[BOTNUM-1][2]=TIME;
    
    TIME++;

  default:
    break;
  }
  return 0;
}
