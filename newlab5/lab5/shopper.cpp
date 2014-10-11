#include "lab5.h"
int DEBUG =1;
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
  //if the robot is in the bottom row
  if(this->xpos_ == 16){
  	if(DEBUG)cout<<"Line 50" <<endl;
  	if(this->ypos_ == 8){
  		if(this->zpos_ == 0){
  			this->movement(East);
  		}
  		else{//begin else
  			if((this->storelist_->xstore_==12 && this->storelist_->ystore_==4 && this->storelist_->zstore_==1)||
  			   (this->storelist_->xstore_==4 && this->storelist_->ystore_==4 && this->storelist_->zstore_==1)) {
  				this->movement(West);
  			}
  			else{
  				this->movement(North);
  			}
  		}//end else
  	}
  	else if(this->zpos_ == 0){
  		if(this->ypos_ == 10){
  			this->movement(NorthEast);
  		}
  		else{
  			this->movement(East);
  		}
  	}
  	else{
  		if(this->ypos_ == 6){
  			this->movement(NorthWest);
  		}
  		else{
  			this->movement(West);	
  		}
  		
  	}
  }//end if xpos ==16


  //if the robot is in the top row
  else if(this->xpos_ == 0){
  	if(DEBUG)cout<<"Line 87"<<cout;
  	if(this->ypos_ == 8){
  		if(this->zpos_ == 1){
  			this->movement(East);
  		}
  		else{//begin else
  			if(this->storelist_->ystore_==4) {
  				this->movement(West);
  			}
  			else{
  				this->movement(South);
  			}
  		}//end else
  	}//end if ypos==8
  	else if(this->zpos_ == 0){
  		if(this->ypos_ == 10){
  			this->movement(SouthEast);
  		}
  		else{
  			this->movement(East);
  		}
  	}
  	else{
  		if(this->ypos_ == 6){
  			this->movement(NorthWest);
  		}
  		else{
  			this->movement(West);	
  		}
  		
  	}
  }
  
  
  else if(this->ypos_ ==0){
  	if(DEBUG)cout<<"Line 122"<<cout;
  	if(this->zpos_ ==0){
  		if(this->xpos_ == 8){
  			if((this->storelist_->xstore_==12 && this->storelist_->ystore_==4 && this->storelist_->zstore_==0)||
  			   (this->storelist_->xstore_==12 && this->storelist_->ystore_==12 && this->storelist_->zstore_==0)){
  			   	this->movement(South);
  			   }
  			   else{
  			   	this->movement(East);
  			   }
  		}
  		if(this->xpos_ == 10){
  			this->movement(SouthEast);
  		}
  		else{
  			this->movement(South);
  		}
  	}
  	else{//if zpos == 1
  		if(this->xpos_ == 6){
  			this->movement(NorthEast);
  		}
  		else{
  			this->movement(North);
  		}
  	
  	}
  }
  
  //if the robot is in column 16
  else if(this->ypos_ ==16){
	if(DEBUG)cout<<"Line 153"<<cout;
  	if(this->zpos_ ==1){//if on the second floor
  		if(this->xpos_ == 8){
  			if(this->storelist_->xstore_==12 && this->storelist_->zstore_==1){
  			   	this->movement(South);
  			   }
  			   else{
  			   	this->movement(West);
  			   }
  		}
  		if(this->xpos_ == 10){
  			this->movement(SouthWest);
  		}
  		else{
  			this->movement(South);
  		}
  	}
  	else{//if zpos == 0
  		if(DEBUG)cout<<"Z==0" <<endl;
  		if(this->xpos_ == 6){
  			cout<<"enter NW" << endl;
  			this->movement(NorthWest);
  		}
  		else if(this->xpos_==8){
  			if(this->storelist_->xstore_==8 && this->storelist_->ystore_ == 16 && this->storelist_->zstore_==0){
  				this->movement(End);
  			}
  		
  			else{
  				if(DEBUG)cout<<"enter N" <<endl;
  				this->movement(North);
  			}
  		}
  		else{
  			if(DEBUG)cout<<"enter N" <<endl;
  			this->movement(North);
  		}
  	
  	}
  }
  
  
  else if(this->xpos_*10+this->ypos_ ==51 || this->xpos_*10+this->ypos_ ==42 || 
  	    this->xpos_*10+this->ypos_ ==24 || this->xpos_*10+this->ypos_ ==15){
  	    	if(DEBUG)cout<<"Line 198"<<cout;
	if(this->zpos_ ==0){
		this->movement(SouthWest);
	}
  	else{
  		this->movement(NorthEast);
  	}
  }
  
  else if(this->xpos_*10+this->ypos_ ==21 || this->xpos_*10+this->ypos_ ==32 || 
  	    this->xpos_*10+this->ypos_ ==54 || this->xpos_*10+this->ypos_ ==65){
  	    	if(DEBUG)cout<<"line 205" <<endl;
	if(this->zpos_==0){
		this->movement(NorthWest);
	}
	else{
		this->movement(SouthEast);
	}
  }


  else if(this->xpos_*10+this->ypos_ ==125 || this->xpos_*10+this->ypos_ ==134 || 
  	    this->xpos_*10+this->ypos_ ==152 || this->xpos_*10+this->ypos_ ==161){
  	    	if(DEBUG)cout<<"Line 220"<<cout;
	if(this->zpos_==0){
		cout<<"enter NE" <<endl;
		this->movement(NorthEast);
	}
	else{
		this->movement(SouthWest);
	}
  }

  else if(this->xpos_*10+this->ypos_ ==111 || this->xpos_*10+this->ypos_ ==122 || 
  	    this->xpos_*10+this->ypos_ ==144 || this->xpos_*10+this->ypos_ ==155){
  	    	if(DEBUG)cout<<"Line 232"<<cout;
	if(this->zpos_==0){
		this->movement(SouthEast);
	}
	else{
		this->movement(NorthWest);
	}
  }
  
  //if the bot is at 3 3 Z
  else if(this->xpos_ == 3 && this->ypos_ == 3){
  	if(DEBUG)cout<<"Line 243"<<cout;
  	//if the bot is on the first floor
  	if(this->zpos_ == 0){
  		//if the next store is at (4,4,0)
  		if((this->storelist_->xstore_==4 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 0)){
  			this->movement(SouthEast);
  		}
  		else{
  			this->movement(SouthWest);
  		}
  	}
  	else{
  		//if the next store is at (4,4,1)
  		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 1){
  			this->movement(SouthEast);
  		}
  		else{
  			this->movement(NorthEast);
  		}
  	}
  }

  else if(this->xpos_ == 3 && this->ypos_ == 13){
  	if(DEBUG)cout<<"Line 266"<<cout;
  	//if the bot is on the first floor
  	if(this->zpos_ == 0){
  		//if the next store is at (4,12,0)
  		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 0){
  			this->movement(SouthWest);
  		}
  		else{
  			this->movement(NorthWest);
  		}
  	}
  	else{
  		//if the next store is at (4,12,1)
  		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 1){
  			this->movement(SouthWest);
  		}
  		else{
  			this->movement(SouthEast);
  		}
  	}
  }


  else if(this->xpos_ == 4 && this->ypos_ == 12){
  	if(DEBUG)cout<<"Line 290"<<cout;
 	movement(NorthEast);
  }

  else if(this->xpos_ == 4 && this->ypos_ == 4){
  	if(DEBUG)cout<<"Line 295"<<cout;
	this->movement(NorthWest);
  }


  else if(this->xpos_*10+this->ypos_ ==81 || this->xpos_*10+this->ypos_ ==82 || 
  	    this->xpos_*10+this->ypos_ ==83 || this->xpos_*10+this->ypos_ ==85 ||
	    this->xpos_*10+this->ypos_ ==86 || this->xpos_*10+this->ypos_ ==87 ||
	    this->xpos_*10+this->ypos_ ==89 || this->xpos_*10+this->ypos_ ==90 ||
	    this->xpos_*10+this->ypos_ ==91 || this->xpos_*10+this->ypos_ ==93 ||
	    this->xpos_*10+this->ypos_ ==94 || this->xpos_*10+this->ypos_ ==95){
	    	if(DEBUG)cout<<"Line 306"<<cout;
	if(this->zpos_==0){
		this->movement(East);
	}
	else{
		this->movement(West);
	}
  }


  else if(this->xpos_*10+this->ypos_ ==18 || this->xpos_*10+this->ypos_ ==28 || 
  	    this->xpos_*10+this->ypos_ ==38 || this->xpos_*10+this->ypos_ ==58 ||
	    this->xpos_*10+this->ypos_ ==68 || this->xpos_*10+this->ypos_ ==78 ||
	    this->xpos_*10+this->ypos_ ==98 || this->xpos_*10+this->ypos_ ==108 ||
	    this->xpos_*10+this->ypos_ ==118 || this->xpos_*10+this->ypos_ ==138 ||
	    this->xpos_*10+this->ypos_ ==148 || this->xpos_*10+this->ypos_ ==158){
	    	if(DEBUG)cout<<"Line 322"<<cout;
	if(this->zpos_==0){
		this->movement(East);
	}
	else{
		this->movement(West);
  	}
 }

  else if(this->xpos_ == 8 && this->ypos_ ==4){
  	if(DEBUG)cout<<"Line 332"<<cout;
	if(this->zpos_ == 0){
		if(this->storelist_->xstore_==6 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 0){
  			this->movement(North);
  		}
		else if(this->storelist_->xstore_==10 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 0){
  			this->movement(South);
  		}
		else{
			this->movement(East);
		}
	}
	else{
		if(this->storelist_->xstore_==6 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 1){
  			this->movement(North);
  		}
		else if(this->storelist_->xstore_==10 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 1){
  			this->movement(South);
  		}
		else{
			this->movement(West);
		}
	}
  }

  else if(this->xpos_ == 7 && this->ypos_ == 4){
  	if(DEBUG)cout<<"Line 358"<<cout;
	if(this->zpos_ == 0){
		if(this->storelist_->xstore_==6 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 0){
			this->movement(North);
		}
		else{
			this->movement(South);
		}
	}
	else{
		if(this->storelist_->xstore_==6 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 1){
			this->movement(North);
		}
		else{
			this->movement(South);
		}
	}
  }
		

  else if(this->xpos_ == 9 && this->ypos_ == 4){
  	if(DEBUG)cout<<"Line 379"<<cout;
	if(this->zpos_ == 0){
		if(this->storelist_->xstore_==10 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 0){
			this->movement(South);
		}
		else{
			this->movement(North);
		}
	}
	else{
		if(this->storelist_->xstore_==10 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 1){
			this->movement(South);
		}
		else{
			this->movement(North);
		}
	}
  }

  else if(this->xpos_ == 10 && this->ypos_==4){
  	if(DEBUG)cout<<"Line 399"<<cout;
	this->movement(North);
  }

  else if(this->xpos_ == 6 && this->ypos_==4){
  	if(DEBUG)cout<<"Line 404"<<cout;
	this->movement(South);
  }

  else if(this->xpos_ == 8 && this->ypos_ == 12){
  	if(DEBUG)cout<<"Line 409"<<cout;
	if(this->zpos_ ==0){
		if(this->storelist_->xstore_==6 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 0){
			this->movement(North);
		}
		else if(this->storelist_->xstore_==10 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 0){
			this->movement(South);
		}
		else{
			this->movement(East);
		}
	}
	else{
		if(this->storelist_->xstore_==10 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 1){
			this->movement(South);
		}
		else if(this->storelist_->xstore_==6 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 1){
			this->movement(North);
		}
		else{
			this->movement(West);
		}
	}
  }
  else if(this->xpos_ == 7 && this->ypos_ == 12){
  	if(DEBUG)cout<<"Line 434"<<cout;
	if(this->zpos_ == 0){
		if(this->storelist_->xstore_== 6 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 0){
			this->movement(North);
		}
		else{
			this->movement(South);
		}
	}
	else{
		if(this->storelist_->xstore_==10 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 1){
			this->movement(South);
		}
		else{
			this->movement(North);
		}
	}
  }

  else if(this->xpos_ == 10 && this->ypos_ == 12){
  	if(DEBUG)cout<<"Line 454"<<cout;
	this->movement(North);
  }


  else if(this->xpos_ == 6 && this->ypos_ == 12){
  	if(DEBUG)cout<<"Line 459"<<cout;
	this->movement(South);
  }


  else if(this->xpos_ == 12 && this->ypos_ == 8){
  	if(DEBUG)cout<<"Line 466"<<cout;
	if(this->zpos_ ==0){
		if(this->storelist_->xstore_==12 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 0){
			this->movement(West);
		}
		else if(this->storelist_->xstore_==12 && this->storelist_->ystore_==10 && this->storelist_->zstore_ == 0){
			this->movement(East);
		}
		else{
			this->movement(South);
		}
	}
	else{
		if(this->storelist_->xstore_==12 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 1){
			this->movement(West);
		}
		else if(this->storelist_->xstore_==12 && this->storelist_->ystore_==10 && this->storelist_->zstore_ == 1){
			this->movement(East);
		}
		else{
			this->movement(North);
		}
	}
  }

  else if(this->xpos_ == 12 && this->ypos_ == 7){
  	if(DEBUG)cout<<"Line 492"<<cout;
	if(this->zpos_ == 0){
		if(this->storelist_->xstore_==12 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 0){
			this->movement(West);
		}
		else{
			this->movement(East);
		}
	}
	else{
		if(this->storelist_->xstore_==12 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 1){
			this->movement(East);
		}
		else{
			this->movement(West);
		}
	}
  }


  else if(this->xpos_ == 12 && this->ypos_ ==9){
  	if(DEBUG)cout<<"Line 513"<<cout;
	if(this->zpos_ == 0){
		if(this->storelist_->xstore_==12 && this->storelist_->ystore_==10 && this->storelist_->zstore_ == 0){
			this->movement(East);
		}
		else{
			this->movement(West);
		}
	}
	else{
		if(this->storelist_->xstore_==12 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 1){
			this->movement(West);
		}
		else{
			this->movement(East);
		}
	}
  }

  else if(this->xpos_ == 12 && this->ypos_==6){
  	if(DEBUG)cout<<"Line 533"<<cout;
	this->movement(West);
  }

  else if(this->xpos_ == 12 && this->ypos_==10){
  	if(DEBUG)cout<<"Line 538"<<cout;
	this->movement(East);
  }

  else if(this->xpos_ == 4 && this->ypos_ == 8){
  	if(DEBUG)cout<<"Line 543"<<cout;
	if(this->zpos_ ==0){
		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 0){
			this->movement(West);
		}
		else if(this->storelist_->xstore_==4 && this->storelist_->ystore_==10 && this->storelist_->zstore_ == 0){
			this->movement(East);
		}
		else{
			this->movement(South);
		}
	}
	else{
		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 1){
			this->movement(West);
		}
		else if(this->storelist_->xstore_==4 && this->storelist_->ystore_==10 && this->storelist_->zstore_ == 1){
			this->movement(East);
		}
		else{
			this->movement(North);
		}
	}
  }

  else if(this->xpos_ == 4 && this->ypos_ == 7){
  	if(DEBUG)cout<<"Line 569"<<cout;
	if(this->zpos_ == 0){
		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 0){
			this->movement(West);
		}
		else{
			this->movement(East);
		}
	}
	else{
		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 1){
			this->movement(East);
		}
		else{
			this->movement(West);
		}
	}
  }


  else if(this->xpos_ == 4 && this->ypos_ ==9){
  	if(DEBUG)cout<<"Line 590"<<cout;
	if(this->zpos_ == 0){
		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==10 && this->storelist_->zstore_ == 0){
			this->movement(East);
		}
		else{
			this->movement(West);
		}
	}
	else{
		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 1){
			this->movement(West);
		}
		else{
			this->movement(East);
		}
	}
  }

  else if(this->xpos_ == 4 && this->ypos_==6){
  	if(DEBUG)cout<<"Line 610"<<cout;
	this->movement(West);
  }

  else if(this->xpos_ == 4 && this->ypos_==10){
  	if(DEBUG)cout<<"Line 615"<<cout;
	this->movement(East);
  }

  else if(this->xpos_ == 8 && this->ypos_ == 8){
  	if(DEBUG)cout<<"Line 620"<<cout;
	if(this->zpos_ == 0){
		if(this->storelist_->zstore_ == 1){
			this->movement(Up);
		}
		else if((this->storelist_->xstore_==12 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 0) ||
			  (this->storelist_->xstore_==12 && this->storelist_->ystore_==10 && this->storelist_->zstore_ == 0) ||
			  (this->storelist_->xstore_==12 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 0)){
			this->movement(South);
		}
		else{
			this->movement(East);
		}
	}
	else{
		if(this->storelist_->zstore_ == 0){
			this->movement(Down);
		}
		else if((this->storelist_->xstore_== 10 && this->storelist_->ystore_== 4 && this->storelist_->zstore_ == 1) ||
			  (this->storelist_->xstore_== 6 && this->storelist_->ystore_== 4 && this->storelist_->zstore_ == 1) ||
			  (this->storelist_->xstore_== 4 && this->storelist_->ystore_== 4 && this->storelist_->zstore_ == 1)){
			this->movement(South);
		}
		else{
			this->movement(North);
		}
	}
  }

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
		
		break;
	case SouthWest:
		//printf("SW");
		//case 3 Moves down a row and left a column
		this->xpos_++;
		this->ypos_--;
		Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
		
		break;
	case South:
		//printf("S");
		//case 4 Moves down a row
		this->xpos_++;
		Floor[this->xpos_][this->ypos_][this->zpos_] = this->RobotNum_;
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
		//case 10 Removes bot from simulation and prints out a notification
		printf("Shopper %d left the simulation at time %d\n", this->RobotNum_, TIME);
		RemoveShopper(this);
		break;
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
