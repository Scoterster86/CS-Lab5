#include "lab5.h"

//Yo Karita
//constructor for a shopper
Shopper::Shopper()
{
	this->RobotNum_ = 0;
	this->xpos_ = 8;
	this->ypos_ = 16;
	this->zpos_ = 0;
	this->storelist_ = new Store();
	this->slices = 0;
	this->nextshopper_ = nullptr;
}

//Yo Karita
//constructor for a shopper with the bot number as an input
Shopper::Shopper(int k)
{
	this->RobotNum_ = k;
	this->xpos_ = 8;
	this->ypos_ = 16;
	this->zpos_ = 0;
	this->storelist_ = new Store();
	this->slices = 0;
	this->nextshopper_ = nullptr;
}

//Yo Karita
//adds a store to the list of stores
void Shopper::AddStore(Store* store)
{
	if (this->storelist_->xstore_ == 0 && this->storelist_->ystore_ == 0 && this->storelist_->zstore_ == 0)this->storelist_ = store;
	else this->storelist_->AddStore(store);
}

//Yo Karita
//removes a store from the list of stores
void Shopper::RemoveStore()
{
	this->storelist_ = this->storelist_->pNext;
}

//Yo Karita
//controls the movement of the shopper
void Shopper::BotMove()
{
  int stores = this->storelist_->GetSize();	//number of stores
  
  int i,xstore,ystore,zstore,storecomplete;
  //moves robot to every store and returns the robot to the starting position


      int xpos = this->xpos_;
      int ypos = this->ypos_;
      int zpos = this->zpos_;
      if (stores == i)
      {
	xstore=8;
	ystore=16;
	zstore=0;
      }
      else{
        xstore = this->storelist_->xstore_;
        ystore = this->storelist_->ystore_;
        zstore = this->storelist_->zstore_;
      }
      //if bot position (3,13,X)
      if(xpos==3 && ypos==13){
	//printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
	  //if the target store is (3,12,0) move there and back to (3,13,0)
	  if(xstore==4 && ystore==12 && zstore==0){
	    this->movement(StSouthWest);
	    storecomplete=1;
	  }
	  else{
	    //moves robot from (3,15,0) to (0,8,0)
	    this->movement(NorthWest2);
	    // printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	  }//end else
	}
	else{//zpos ==1
	  //if the target store is (4,12,1) move there and back to (3,13,1)
	  if(xstore==4 &&ystore==12 && zstore==1){
	    //  printf("L57");
            this->movement(StSouthWest);
            storecomplete=1;
          }
	  else{//move SouthEast
	    // printf("L62");
	    this->movement(SouthEast2);
	  }
	}//end else
      }//end if
    

      //if bot position (0,8,X)
      else if(xpos==0 && ypos==8){
	// printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
	  //if the store is on the second Floor or the fastest route to the store is down
	  if(zstore==1 || (zstore==0 && ystore>=6)){//begin zs1 || zs0 && ys>=6 if
	    this->movement(South);
	    // printf("South");
	  }//end zs1 || zs0 && ys>=6 if
	  else{//else continue moving around the outside
	    this->movement(SouthWest);
	  }//end else
	}
	else{//else if zpos==1
	  this->movement(SouthEast);
	}
      }//end if
      
      
      //if bot position (4,8,X)
      else if(xpos==4 && ypos==8){
	//	printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
          //if the target store is (4,6,0) move there and back to (4,8,0)
	  if(xstore==4 && ystore==6 && zstore==0){
	    this->movement(StWest);
	    storecomplete=1;
	  }//end x4,y6,z0 store if
          //if the target store is (4,10,0) move there and back to (4,8,0)
	  else if(xstore==4 && ystore==10 && zstore==0){//begin x4,y8,z0 pos if
	    this->movement(StEast);
	    storecomplete=1;
	  }//end x4,y10,z0 if
	  else{
	    this->movement(South);
	  }
	}
	else{//if zpos=1
          //if the target store is (4,6,1) move there and back to (4,8,1)
	  if(xstore==4 && ystore==6 && zstore==1){
            this->movement(StWest);
            storecomplete=1;
          }
          //if the target store is (4,10,1) move there and back to (4,8,1)
          else if(xstore==4 && ystore==10 && zstore==1){
            this->movement(StEast);
            storecomplete=1;
          }
          else{
	    this->movement(North);
	  }
	}//end else
      }//end if
    

      //if bot position (3,3,x)
      else if(xpos==3 && ypos==3){
	//printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
          //if the target store is (4,4,0) move there and back to (3,3,0)
	  if(xstore==4 && ystore==4 && zstore==0){
	    this->movement(StSouthEast);
	    storecomplete=1;
	  }
	  else{
	    this->movement(SouthWest2);
	  }//end else
	}
	else{//if zpos=1
          //if the target store is (4,4,1) move there and back to (3,3,1)
	  if(xstore==4 && ystore==4 && zstore==1){
            this->movement(StSouthEast);
            storecomplete=1;
          }
          else{
	    //  printf("\nL143\n");
            this->movement(NorthEast2);
          }
        }//end else
      }//end if


      //if bot position (8,0,X)
      else if(xpos==8 && ypos==0){
        //printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
	  //if the target store is (13,3,0) or (13,13,0) move SouthEast
	  if((xstore==12 && ystore==4 && zstore==0)||(xstore==12 && ystore==12 && zstore==0)){
	    this->movement(SouthEast);
	  }//end store pos if
	  else{//begin else
	    this->movement(East);
	  }
	}//end else
	else{//if zpos=1
	  this->movement(NorthEast);
	}
      }//end xpos8 ypos0 zpos0 if


      //if bot position (8,4,X)
      else if(xpos==8 && ypos==4){
        //printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
          //if the target store is (6,4,0) move there and back to (8,4,0)
	  if(xstore==6 && ystore==4 && zstore==0){
	    this->movement(StNorth);
	    storecomplete=1;
	  }
          //if the target store is (10,4,0) move there and back to (8,4,0)
	  else if(xstore==10 && ystore==4 && zstore==0){
	    this->movement(StSouth);
	    storecomplete=1;
	  }
	  else{
	    this->movement(East);
	  }  
	}
	else{//if zpos=1
	  //if the target store is (6,4,1) move there and back to (8,4,1)
          if(xstore==6 && ystore==4 && zstore==1){
            this->movement(StNorth);
            storecomplete=1;
          }
          //if the target store is (10,4,0) move there and back to (8,4,1)
          else if(xstore==10 && ystore==4 && zstore==1){
            this->movement(StSouth);
            storecomplete=1;
          }
          else{
            this->movement(West);
          }
	}//end else
      }//end if


      //if bot position (13,3,X)
      else if(xpos==13 && ypos==3){
        //printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
	  //if the target store is (12,4,0) move there and back to (3,13,0)
	  if(xstore==12 && ystore==4 && zstore==0){
	    this->movement(StNorthEast);
	    storecomplete=1;
	  }
	  else{
	    this->movement(SouthEast2);
	  }
	}
	else{//if zpos=1
	  //if the target store is (12,4,1) move there and back to (13,3,1)
	  if(xstore==12 && ystore==4 && zstore==1){
            this->movement(StNorthEast);
            storecomplete=1;
          }
          else{
	    //	    printf("\nL221\n");
            this->movement(NorthWest2);
          }
        }//end else
      }//end if


      //if bot position (8,8,X)
      else if(xpos==8 && ypos==8){
        //printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
	  //if the target store is on the second Floor use the elevator
	  if(zstore==1){
	    this->movement(Up);
	  }
	  //if the target store is located at a position of (12,6<=,0) move South
	  else if(xstore==12 && ystore>=6 && zstore==0){
	    this->movement(South);
	  }
	  else{
	    this->movement(East);
	  }
	}
	else{//if zpos==1
	  //if the target store is on the first Floor use the elevator
          if(zstore==0){
            this->movement(Down);
          }
          //if the target store is located at a position of (4,10>=,0) move West
          else if(xstore<=10 && ystore==4 && zstore==1){
            this->movement(West);
          }
          else{
            this->movement(North);
          }
        }//end else
      }//end if


      //if bot position (16,8,0)
      else if(xpos==16 && ypos==8){
        //printf("\n Position %d %d %d\n", xpos, ypos, zpos);
	if(zpos==0){
	  this->movement(NorthEast);
	}
	else{//if zpos=1
	  //if the target store is (12,4,1) or (4,4,1) move NorthWest
	  if((xstore==12 && ystore==4 && zstore==1)||(xstore==4 && ystore==4 && zstore==1)){
	    this->movement(NorthWest);
	  }
	  else{
	    this->movement(North);
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
	    this->movement(StWest);
	    storecomplete=1;
	  }
	  //if the target store is (12,10,0) move there and back to (12,8,0)
	  //and set storecomplete=1
	  else if(xstore==12 && ystore==10 && zstore==0){
	    this->movement(StEast);
	    storecomplete=1;
	  }
	  else{
	    this->movement(South);
	  }
	}
	else{//if zpos==1
	  //if the target store is (12,6,1) move there and back to (12,8,1)
	  //and set storecomplete=1
	  if(xstore==12 && ystore==6 && zstore==1){
	    this->movement(StWest);
	    storecomplete=1;
	  }
	  //if the target store is (12,10,1) move there and back to (12,8,1)
	  //and set storecomplete=1
	  else if(xstore==12 && ystore==10 && zstore==1){
	    this->movement(StEast);
	    storecomplete=1;
	  }
	  else{
	    this->movement(North);
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
	    this->movement(StNorth);
	    storecomplete=1;
	  }
	  //if the target store is (10,12,0) move there and back to (8,12,0)
	  //and set storecomplete=1
	  else if(xstore==10 && ystore==12 && zstore==0){
	    this->movement(StSouth);
	    storecomplete=1;
	  }
	  else{
	    this->movement(East);
	  }
	}
	else{//if zpos==1
	  //if the target store is (6,12,2) move there and back to (8,12,1)
          //and set storecomplete=1
	  if(xstore==6 && ystore==12 && zstore==1){
            this->movement(StNorth);
            storecomplete=1;
          }
	  //if the target store is (10,12,0) move there and back to (8,12,1)
          //and set storecomplete=1
          else if(xstore==10 && ystore==12 && zstore==1){
            this->movement(StSouth);
            storecomplete=1;
          }
          else{
            this->movement(West);
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
	    this->movement(StNorthWest);
	    storecomplete=1;
	  }
	  else{
	    //	    printf("\nL345\n");
	    this->movement(NorthEast2);
	  }
	}
	else{//if zpos==1
	  //if the target store is (12,12,1) move there and back to (13,13,1)
          //and set storecomplete=1
	  if(xstore==12 && ystore==12 && zstore==1){
	    this->movement(StNorthWest);
	    storecomplete=1;
	  }
	  else{
	    //  printf("\nL385\n");
	    this->movement(SouthWest2);
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
	    this->movement(End);
	  }
	  else{
	    this->movement(NorthWest);
	  }
	}
	else{//if zpos==1
	  //if the target store is (12,X,1) move SouthWest
	  if(xstore==12 && zstore==1){
	    this->movement(SouthWest);
	  }
	  else{
	    this->movement(West);
	  }
	}
      }//end if


    } //end while    
  }//end i for loop
}

//Scott Iwanicki
//moves the shopper in the given direction
int Shopper::movement(int direction){
	int j;
	;
	switch (direction){
	case North:
		//printf("N");
		//Moves up a row
			this->xpos_--;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
		}
		break;
	case NorthWest:
		//Moves up a row and left a colmun
		this->xpos_--;
		this->ypos_--;
		Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
		break;
	case West:
		//case 2 Moves left 4 columns and increments TIME by 1 for each movement
			this->ypos_--;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
		}
		break;
	case SouthWest:
		//printf("SW");
		//case 3 Moves down a row and left a column
		this->xpos_++;
		this->ypos_--;
		Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
		}
		break;
	case South:
		//printf("S");
		//case 4 Moves down a row
			this->xpos_++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
		}
		break;
	case SouthEast:
		//printf("SE");
		//case 5 Moves down and to the right
		this->xpos_++;
		this->ypos_++;
		Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
		break;
	case East:
		//printf("E");
		//case 6 Moves right a column
			this->ypos_++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
		break;
	case NorthEast:
		//printf("NE");
		//case 7 Moves up a row and right a column
		this->xpos_--;
		this->ypos_++;

		Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
		break;
	case Up:
		//printf("Up");
		//case 8 Moves up a Floor and prints when the bot
		//got on and off the elevator
		this->zpos_++;
		printf("Shopper %d got on elevator at time %d\n", this->RobotNum_, TIME);
		Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
		printf("Shopper %d got off elevator at time %d\n", this->RobotNum_, TIME+3);
		break;
	case Down:
		//printf("Down");
		//case 9 Moves down a Floor and prints when the bot
		//got on and off the elevator
		this->zpos_--;
		printf("Shopper %d got on elevator at time %d\n", this->RobotNum_, TIME);
		Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
		printf("Shopper %d got off elevator at time %d\n", this->RobotNum_, TIME+3);
		break;

	case End:
		//case 20 Removes bot from simulation and prints out a notification
		printf("Shopper %d left the simulation at time %d\n", this->RobotNum_, TIME);
		//[this->RobotNum_ - 1][2] = TIME;
		TIME++;
	default:
		break;
	}
	return 0;
}

//Scott Iwanicki
//runs when a shopper reaches a store
int Shopper::storecomplete(){
	int xpos = this->storelist_->xstore_;
	int ypos = this->storelist_->ystore_;
	int zpos = this->storelist_->zstore_;
	printf("Shopper %d arrives at store S(%d,%d) on the %d Floor at time %d\n", this->RobotNum_, xpos, ypos, (zpos + 1), TIME);
	//shopper enters round robin queue
	RRqueue* ptr = new RRqueue(this);
	//the shopper is processed at the round robin queue
	while(this->storelist_->TimeSlice_ != 0)
	{
		TIME+= (TimeSlice/10);
		ptr->RunQueue();
		timecheck();
	}
	//removes the store from the shopper's list of stores
	RemoveStore();
	return 0;
}

//Yo Karita
//adds a shopper to a list of shoppers
void Shopper::AddShopper(Shopper* shopper)
{
	//if the first shopper is empty, set the shopper as the head shopper
	if (this->RobotNum_ == 0)
	{
		this->RobotNum_ = shopper->RobotNum_;
		this->xpos_ = shopper->xpos_;
		this->ypos_ = shopper->ypos_;
		this->zpos_ = shopper->zpos_;
		this->storelist_ = new Store();
		this->nextshopper_ = nullptr;
	}
	//else set the shopper to the next shopper
	else this->nextshopper_ = shopper;
}

//Yo Karita
//removes the shopper from a list of shoppers
void Shopper::RemoveShopper(Shopper* shopper)
{
	shopper= shopper->nextshopper_;
}
