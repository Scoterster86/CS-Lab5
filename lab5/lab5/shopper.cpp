#include "lab5.h"

void Shopper::BotMove()
{
	//prototypes
	int movement(int);
	int timecheck();
	int stores = this->storelist.size();	//number of stores

	int i,xstore,ystore,zstore,storecomplete;
	//moves robot to every store and returns the robot to the starting position
	for(i=0;i<=stores;i++){
		/*
		//if the bot hasn't completed all store runs, scan for next store
		if(i<stores){
			printf("Input store coordinates x y z:\n");
			getchar();
			scanf("%d %d %d", &xstore, &ystore, &zstore);
		}
		else{//set store to starting position
			xstore=8;
			ystore=16;
			zstore=0;
		}
		*/

		if (stores == i)
		{
			xstore=8;
			ystore=16;
			zstore=0;
		}

		int xpos = this->xpos_;
		int ypos = this->ypos_;
		int zpos = this->zpos_;
		int xstore = this->storelist.front().xstore_;
		int ystore = this->storelist.front().ystore_;
		int zstore = this->storelist.front().zstore_;


		storecomplete=0;
		if(i==0){//begin if
		  Floor[8][16][0]=this->RobotNum_;
		  xpos=8;
		  ypos=16;
		  zpos=0;
		  TIME++;
		  timecheck();
		  movement(NorthWest);
		}//end i==0 if

	while(storecomplete==0){
      //printf("\n%d %d %d\n", xpos, ypos, zpos);

      //if bot position (3,13,X)
      if(xpos==3 && ypos==13){
	//printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
	  //if the target store is (3,12,0) move there and back to (3,13,0)
	  if(xstore==4 && ystore==12 && zstore==0){
	    movement(StSouthWest);
	    storecomplete=1;
	  }
	  else{
	    //moves robot from (3,15,0) to (0,8,0)
	    movement(NorthWest2);
	    // printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	  }//end else
	}
	else{//zpos ==1
	  //if the target store is (4,12,1) move there and back to (3,13,1)
	  if(xstore==4 &&ystore==12 && zstore==1){
	    //  printf("L57");
            movement(StSouthWest);
            storecomplete=1;
          }
	  else{//move SouthEast
	    // printf("L62");
	    movement(SouthEast2);
	  }
	}//end else
      }//end if
    

      //if bot position (0,8,X)
      else if(xpos==0 && ypos==8){
	// printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
	  //if the store is on the second floor or the fastest route to the store is down
	  if(zstore==1 || (zstore==0 && ystore>=6)){//begin zs1 || zs0 && ys>=6 if
	    movement(South);
	    // printf("South");
	  }//end zs1 || zs0 && ys>=6 if
	  else{//else continue moving around the outside
	    movement(SouthWest);
	  }//end else
	}
	else{//else if zpos==1
	  movement(SouthEast);
	}
      }//end if
      
      
      //if bot position (4,8,X)
      else if(xpos==4 && ypos==8){
	//	printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
          //if the target store is (4,6,0) move there and back to (4,8,0)
	  if(xstore==4 && ystore==6 && zstore==0){
	    movement(StWest);
	    storecomplete=1;
	  }//end x4,y6,z0 store if
          //if the target store is (4,10,0) move there and back to (4,8,0)
	  else if(xstore==4 && ystore==10 && zstore==0){//begin x4,y8,z0 pos if
	    movement(StEast);
	    storecomplete=1;
	  }//end x4,y10,z0 if
	  else{
	    movement(South);
	  }
	}
	else{//if zpos=1
          //if the target store is (4,6,1) move there and back to (4,8,1)
	  if(xstore==4 && ystore==6 && zstore==1){
            movement(StWest);
            storecomplete=1;
          }
          //if the target store is (4,10,1) move there and back to (4,8,1)
          else if(xstore==4 && ystore==10 && zstore==1){
            movement(StEast);
            storecomplete=1;
          }
          else{
	    movement(North);
	  }
	}//end else
      }//end if
    

      //if bot position (3,3,x)
      else if(xpos==3 && ypos==3){
	//printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
          //if the target store is (4,4,0) move there and back to (3,3,0)
	  if(xstore==4 && ystore==4 && zstore==0){
	    movement(StSouthEast);
	    storecomplete=1;
	  }
	  else{
	    movement(SouthWest2);
	  }//end else
	}
	else{//if zpos=1
          //if the target store is (4,4,1) move there and back to (3,3,1)
	  if(xstore==4 && ystore==4 && zstore==1){
            movement(StSouthEast);
            storecomplete=1;
          }
          else{
	    //  printf("\nL143\n");
            movement(NorthEast2);
          }
        }//end else
      }//end if


      //if bot position (8,0,X)
      else if(xpos==8 && ypos==0){
        //printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
	  //if the target store is (13,3,0) or (13,13,0) move SouthEast
	  if((xstore==12 && ystore==4 && zstore==0)||(xstore==12 && ystore==12 && zstore==0)){
	    movement(SouthEast);
	  }//end store pos if
	  else{//begin else
	    movement(East);
	  }
	}//end else
	else{//if zpos=1
	  movement(NorthEast);
	}
      }//end xpos8 ypos0 zpos0 if


      //if bot position (8,4,X)
      else if(xpos==8 && ypos==4){
        //printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
          //if the target store is (6,4,0) move there and back to (8,4,0)
	  if(xstore==6 && ystore==4 && zstore==0){
	    movement(StNorth);
	    storecomplete=1;
	  }
          //if the target store is (10,4,0) move there and back to (8,4,0)
	  else if(xstore==10 && ystore==4 && zstore==0){
	    movement(StSouth);
	    storecomplete=1;
	  }
	  else{
	    movement(East);
	  }  
	}
	else{//if zpos=1
	  //if the target store is (6,4,1) move there and back to (8,4,1)
          if(xstore==6 && ystore==4 && zstore==1){
            movement(StNorth);
            storecomplete=1;
          }
          //if the target store is (10,4,0) move there and back to (8,4,1)
          else if(xstore==10 && ystore==4 && zstore==1){
            movement(StSouth);
            storecomplete=1;
          }
          else{
            movement(West);
          }
	}//end else
      }//end if


      //if bot position (13,3,X)
      else if(xpos==13 && ypos==3){
        //printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
	  //if the target store is (12,4,0) move there and back to (3,13,0)
	  if(xstore==12 && ystore==4 && zstore==0){
	    movement(StNorthEast);
	    storecomplete=1;
	  }
	  else{
	    movement(SouthEast2);
	  }
	}
	else{//if zpos=1
	  //if the target store is (12,4,1) move there and back to (13,3,1)
	  if(xstore==12 && ystore==4 && zstore==1){
            movement(StNorthEast);
            storecomplete=1;
          }
          else{
	    //	    printf("\nL221\n");
            movement(NorthWest2);
          }
        }//end else
      }//end if


      //if bot position (8,8,X)
      else if(xpos==8 && ypos==8){
        //printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
	  //if the target store is on the second floor use the elevator
	  if(zstore==1){
	    movement(Up);
	  }
	  //if the target store is located at a position of (12,6<=,0) move South
	  else if(xstore==12 && ystore>=6 && zstore==0){
	    movement(South);
	  }
	  else{
	    movement(East);
	  }
	}
	else{//if zpos==1
	  //if the target store is on the first floor use the elevator
          if(zstore==0){
            movement(Down);
          }
          //if the target store is located at a position of (4,10>=,0) move West
          else if(xstore<=10 && ystore==4 && zstore==1){
            movement(West);
          }
          else{
            movement(North);
          }
        }//end else
      }//end if


      //if bot position (16,8,0)
      else if(xpos==16 && ypos==8){
        //printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
	  movement(NorthEast);
	}
	else{//if zpos=1
	  //if the target store is (12,4,1) or (4,4,1) move NorthWest
	  if((xstore==12 && ystore==4 && zstore==1)||(xstore==4 && ystore==4 && zstore==1)){
	    movement(NorthWest);
	  }
	  else{
	    movement(North);
	  }
	}//end else
      }//end if


      //if bot position (12,8,X)
      else if(xpos==12 && ypos==8){
        //printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
	  //if the target store is located at a position of (12,6,0)
	  //move to the store and back to (12,8,0) and set storecomplete=1
	  if(xstore==12 && ystore==6 && zstore==0){
	    movement(StWest);
	    storecomplete=1;
	  }
	  //if the target store is (12,10,0) move there and back to (12,8,0)
	  //and set storecomplete=1
	  else if(xstore==12 && ystore==10 && zstore==0){
	    movement(StEast);
	    storecomplete=1;
	  }
	  else{
	    movement(South);
	  }
	}
	else{//if zpos==1
	  //if the target store is (12,6,1) move there and back to (12,8,1)
	  //and set storecomplete=1
	  if(xstore==12 && ystore==6 && zstore==1){
	    movement(StWest);
	    storecomplete=1;
	  }
	  //if the target store is (12,6,1) move there and back to (12,8,1)
	  //and set storecomplete=1
	  else if(xstore==14 && ystore==6 && zstore==1){
	    movement(StEast);
	    storecomplete=1;
	  }
	  else{
	    movement(North);
	  }
	}//end else
      }//end if


      //if bot position (8,12,X)
      else if(xpos==8 && ypos==12){
        //printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
	  //if the target store is (6,12,0) move there and back to (8,12,0)
	  //and set storecomplete=1
	  if(xstore==6 && ystore==12 && zstore==0){
	    movement(StNorth);
	    storecomplete=1;
	  }
	  //if the target store is (10,12,0) move there and back to (8,12,0)
	  //and set storecomplete=1
	  else if(xstore==10 && ystore==12 && zstore==0){
	    movement(StSouth);
	    storecomplete=1;
	  }
	  else{
	    movement(East);
	  }
	}
	else{//if zpos==1
	  //if the target store is (6,12,2) move there and back to (8,12,1)
          //and set storecomplete=1
	  if(xstore==6 && ystore==12 && zstore==1){
            movement(StNorth);
            storecomplete=1;
          }
	  //if the target store is (10,12,0) move there and back to (8,12,1)
          //and set storecomplete=1
          else if(xstore==10 && ystore==12 && zstore==1){
            movement(StSouth);
            storecomplete=1;
          }
          else{
            movement(West);
          }
        }//end else
      }//end if


      //if bot position (13,13,X)
      else if(xpos==13 && ypos==13){
        //printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
	  //if the target store is (12,12,0) move there and back to (13,13,0)
          //and set storecomplete=1
	  if(xstore==12 && ystore==12 && zstore==0){
	    movement(StNorthWest);
	    storecomplete=1;
	  }
	  else{
	    //	    printf("\nL345\n");
	    movement(NorthEast2);
	  }
	}
	else{//if zpos==1
	  //if the target store is (12,12,1) move there and back to (13,13,1)
          //and set storecomplete=1
	  if(xstore==12 && ystore==12 && zstore==1){
	    movement(StNorthWest);
	    storecomplete=1;
	  }
	  else{
	    //  printf("\nL385\n");
	    movement(SouthWest2);
	  }
	}
      }//end if


      //if bot position (8,16,X)
      else if(xpos==8 && ypos==16){
        //printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
	  //if the target store is (8,16,0) move there and back to (8,16,0)
          //and set storecomplete=1
	  if(xstore==8 && ystore==16 && zstore==0){
	    storecomplete=1;
	    TIME++;
	    movement(End);
	  }
	  else{
	    movement(NorthWest);
	  }
	}
	else{//if zpos==1
	  //if the target store is (12,X,1) move SouthWest
	  if(xstore==12 && zstore==1){
	    movement(SouthWest);
	  }
	  else{
	    movement(West);
	  }
	}
      }//end if


    } //end while    
  }//end i for loop
}

void Shopper::AddStore(Store* store)
{
	this->storelist.push_back(*store);
}

void Shopper::RemoveStore()
{
	this->storelist.pop_front();
}

void RRqueue()
