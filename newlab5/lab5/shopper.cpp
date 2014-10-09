#include "lab5.h"


Shopper::Shopper()
{
	this->RobotNum_ = 0;
	this->xpos_ = 0;
	this->ypos_ = 0;
	this->zpos_ = 0;
	this->storelist_ = new Store();
	this->slices = 0;
	this->nextshopper_ = nullptr;
}

Shopper::Shopper(int k)
{
	this->RobotNum_ = k;
	this->xpos_ = 0;
	this->ypos_ = 0;
	this->zpos_ = 0;
	this->storelist_ = new Store();
	this->slices = 0;
	this->nextshopper_ = nullptr;
}

void Shopper::AddStore(Store* store)
{
	if (this->storelist_->xstore_ == 0 && this->storelist_->ystore_ == 0 && this->storelist_->zstore_ == 0)this->storelist_ = store;
	else this->storelist_->AddStore(store);
}

void Shopper::RemoveStore()
{
	this->storelist_ = this->storelist_->pNext;
}

void Shopper::BotMove()
{
  int stores = this->storelist_->GetSize();	//number of stores
  
  int i,xstore,ystore,zstore,storecomplete;
  //moves robot to every store and returns the robot to the starting position
  for(i=0;i<=stores;i++){    

    /*
    xstore = this->storelist_->xstore_;
    ystore = this->storelist_->ystore_;
    zstore = this->storelist_->zstore_;
    */
    
    storecomplete=0;
    if(i==0){//begin if
      Floor[8][16][0]=this->RobotNum_;
      this->xpos_=8;
      this->ypos_=16;
      this->zpos_=0;
      TIME++;
      timecheck();
      this->movement(NorthWest);
    }//end i==0 if
    
    while(storecomplete==0){
      //printf("\n%d %d %d\n", xpos, ypos, zpos);
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
	  //if the target store is (12,6,1) move there and back to (12,8,1)
	  //and set storecomplete=1
	  else if(xstore==14 && ystore==6 && zstore==1){
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



int Shopper::movement(int direction){
	int j;
	;
	switch (direction){
	case North:
		//printf("N");
		//case 0 Moves up 4 rows and increments TIME by 1 for each movement
		for (j = 0; j<4; j++){
			this->xpos_--;
			TIME = TIME + 1;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case NorthWest:
		//printf("NW, %d %d %d", this->xpos_, this->ypos_, this->zpos_);
		//case 1 Moves up 2 rows and up and to the right 3 times and
		//increments TIME by 1 for each movement
		for (j = 0; j<5; j++){
			if (j<2 && this->zpos_ == 0){
				this->xpos_--;
			}
			else if (j<2 && this->zpos_ == 1){
				this->ypos_--;
			}
			else{
				this->xpos_--;
				this->ypos_--;
			}
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case West:
		//printf("W");
		//case 2 Moves left 4 columns and increments TIME by 1 for each movement
		for (j = 0; j<4; j++){
			this->ypos_--;
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case SouthWest:
		//printf("SW");
		//case 3 Moves down 2 rows, down and the to
		//the left 3 times and increments TIME by 1
		for (j = 0; j<5; j++){
			if (j<2 && this->zpos_ == 0){
				this->ypos_--;
			}
			else if (j<2 && this->zpos_ == 1){
				this->xpos_++;
			}
			else{
				this->xpos_++;
				this->ypos_--;
			}
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case South:
		//printf("S");
		//case 4 Moves down 4 rows and increments TIME by 1 for each movement
		for (j = 0; j<4; j++){
			this->xpos_++;
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case SouthEast:
		//printf("SE");
		//case 5 Moves down 2 rows, down and the right 3 times
		// and increments TIME by 1
		for (j = 0; j<5; j++){
			if (j<2 && this->zpos_ == 0){
				this->xpos_++;
			}
			else if (j<2 && this->zpos_ == 1){
				this->ypos_++;
			}
			else{
				this->xpos_++;
				this->ypos_++;
			}
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case East:
		//printf("E");
		//case 6 Moves right 4 columns and increments TIME by 1 for each movement
		for (j = 0; j<4; j++){
			this->ypos_++;
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case NorthEast:
		//printf("NE");
		//case 7 Moves up a row and right a column and increments TIME by 1
		for (j = 0; j<5; j++){
			if (j<2 && this->zpos_ == 0){
				this->ypos_++;
			}
			else if (j<2 && this->zpos_ == 1){
				this->xpos_--;
			}
			else{
				this->xpos_--;
				this->ypos_++;
			}
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case Up:
		//printf("Up");
		//case 8 Moves up a Floor, increments TIME by 3, and prints when the bot
		//got on and off the elevator
		this->zpos_++;
		printf("robot %d got on elevator at time %d\n", this->RobotNum_, TIME);
		Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
		for (j = 0; j<3; j++){
			TIME++;
			timecheck();
		}
		printf("robot %d got off elevator at time %d\n", this->RobotNum_, TIME);
		break;
	case Down:
		//printf("Down");
		//case 9 Moves down a Floor and increments TIME by 3, and prints when the bot
		//got on and off the elevator
		this->zpos_--;
		printf("robot %d got on elevator at time %d\n", this->RobotNum_, TIME);
		Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
		for (j = 0; j<3; j++){
			TIME++;
			timecheck();
		}
		printf("robot %d got off elevator at time %d\n", this->RobotNum_, TIME);
		break;
	case StNorth:
		//printf("StN");
		//case 10 moves up two rows, enters the store, then moves down two rows
		//increments time by 1 for each movement
		for (j = 0; j<5; j++){
			if (j<2){
				this->xpos_--;
			}
			else if (j == 2){
				this->storecomplete();
			}
			else{
				this->xpos_++;
			}
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case StSouth:
		// printf("StS");
		//case 11 moves down two rows, enters the store, then moves up two rows
		//increments time by 1 for each movement
		for (j = 0; j<5; j++){
			if (j<2){
				this->xpos_++;
			}
			else if (j == 2){
				this->storecomplete();
			}
			else{
				this->xpos_--;
			}
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case StEast:
		// printf("StE");
		//case 12 moves right two columns, enters the store, then moves left two columns
		//increments time by 1 for each movement
		for (j = 0; j<5; j++){
			if (j<2){
				this->ypos_++;
			}
			else if (j == 2){
				this->storecomplete();
			}
			else{
				this->ypos_--;
			}
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case StWest:
		// printf("StW");
		//case 13 moves left two columns, enters the store, then moves right two columns
		//increments time by 1 for each movement
		for (j = 0; j<5; j++){
			if (j<2){
				this->ypos_--;
			}
			else if (j == 2){
				this->storecomplete();
			}
			else{
				this->ypos_++;
			}
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case StNorthWest:
		// printf("StNW");
		//case 14 moves up a row and left a column, enters the store,
		// then moves down a row and right a column increments time by 1 for each movement
		for (j = 0; j<3; j++){
			if (j == 0){
				this->xpos_--;
				this->ypos_--;
			}
			else if (j == 1){
				this->storecomplete();
			}
			else{
				this->xpos_++;
				this->ypos_++;
			}
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case StNorthEast:
		// printf("StNE");
		//case 15 moves up a row and right a column, enters the store,
		// then moves down a row and left a column increments time by 1 for each movement
		for (j = 0; j<3; j++){
			if (j == 0){
				this->xpos_--;
				this->ypos_++;
			}
			else if (j == 1){
				this->storecomplete();
			}
			else{
				this->xpos_++;
				this->ypos_--;
			}
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case StSouthEast:
		//case 16 moves down a row and right a column, enters the store,
		// then moves up a row and left a column increments time by 1 for each movement
		// printf("StSE");
		for (j = 0; j<3; j++){
			if (j == 0){
				this->xpos_++;
				this->ypos_++;
			}
			else if (j == 1){
				this->storecomplete();
			}
			else{
				this->xpos_--;
				this->ypos_--;
			}
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case StSouthWest:
		//case 15 moves down a row and left a column, enters the store,
		// then moves up a row and right a column, increments time by 1 for each movement
		//printf("StSW");
		for (j = 0; j<3; j++){
			if (j == 0){
				this->xpos_++;
				this->ypos_--;
			}
			else if (j == 1){
				this->storecomplete();
			}
			else{
				this->xpos_--;
				this->ypos_++;
			}
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case NorthWest2:
		// printf("%d %d %d",this->xpos_, this->ypos_,this->zpos_);
		//case 16 Moves up a row and left a column and increments TIME by 1
		for (j = 0; j<5; j++){
			if (j>2 && this->zpos_ == 0){
				this->ypos_--;
			}
			else if (j>2 && this->zpos_ == 1){
				this->xpos_--;
			}
			else{
				this->xpos_--;
				this->ypos_--;
			}
			//printf("NW2\n");
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case NorthEast2:
		//printf("NE2");
		//case 17 Moves up a row and right a column and increments TIME by 1
		for (j = 0; j<5; j++){
			if (j>2 && this->zpos_ == 0){
				this->xpos_--;
			}
			else if (j>2 && this->zpos_ == 1){
				this->ypos_++;
			}
			else{
				this->xpos_--;
				this->ypos_++;
			}
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case SouthWest2:
		// printf("SW2");
		//case 18 Moves down a row and left a column and increments TIME by 1
		for (j = 0; j<5; j++){
			if (j>2 && this->zpos_ == 0){
				this->xpos_++;
			}
			else if (j>2 && this->zpos_ == 1){
				this->ypos_--;
			}
			else{
				this->xpos_++;
				this->ypos_--;
			}
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case SouthEast2:
		//printf("SE2");
		//case 19 Moves down a row and right a column and increments TIME by 1
		for (j = 0; j<5; j++){
			if (j>2 && this->zpos_ == 0){
				this->ypos_++;
			}
			else if (j>2 && this->zpos_ == 1){
				this->xpos_++;
			}
			else{
				this->xpos_++;
				this->ypos_++;
			}
			TIME++;
			Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
			timecheck();
		}
		break;
	case End:
		//case 20 Removes bot from simulation and prints out a notification
		printf("robot %d left the simulation at time %d\n", this->RobotNum_, TIME);
		//[this->RobotNum_ - 1][2] = TIME;
		TIME++;
	default:
		break;
	}
	return 0;
}



int Shopper::storecomplete(){
	int xpos = this->storelist_->xstore_;
	int ypos = this->storelist_->ystore_;
	int zpos = this->storelist_->zstore_;
	printf("robot %d arrives at store S(%d,%d) on the %d Floor at time %d\n", this->RobotNum_, xpos, ypos, (zpos + 1), TIME);
	RRqueue* ptr = new RRqueue(this);
	while(this->storelist_->TimeSlice_ != 0)
	{
		TIME++;
		ptr->RunQueue();
		timecheck();
	}
	RemoveStore();
	return 0;
}
void Shopper::AddShopper(Shopper* shopper)
{
	if (this->RobotNum_ == 0)
	{
		this->RobotNum_ = shopper->RobotNum_;
		this->xpos_ = shopper->xpos_;
		this->ypos_ = shopper->ypos_;
		this->zpos_ = shopper->zpos_;
		this->storelist_ = new Store();
		this->nextshopper_ = nullptr;
	}
	else this->nextshopper_ = shopper;
}

void Shopper::RemoveShopper(Shopper* shopper)
{
	shopper= shopper->nextshopper_;
}

