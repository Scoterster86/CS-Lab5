#include "lab5.h"
int DEBUG = 0;

//Scott Iwanicki

Move::Move()
{

	this->xpos_ = 8;
	this->ypos_ = 16;
	this->zpos_ = 0;
	this->wait_=0;
	this->storelist_ = new Store();
}

//Yo Karita
//adds a store to the list of stores
void Move::AddStore(Store* store)
{

	if (this==NULL || (this->storelist_->xstore_ == 0 
	   && this->storelist_->ystore_ == 0 
	   && this->storelist_->zstore_ == 0)){
		this->storelist_ = store;
	}
	else this->storelist_->AddStorelist(store);
}

//Yo Karita
//removes a store from the list of stores
void Move::RemoveStore()
{
	this->storelist_ = this->storelist_->pNext;
	//cout<<"RM Store" <<endl;
}


//Scott Iwanicki
//controls the movement of the shopper
void Move::BotMove(int RobotNum)
{
	if(DEBUG)cout<<"BotMove"<<endl;
  //if the robot is in the bottom row
  if(this->xpos_ == 16){
  	if(DEBUG)cout<<"Line 50" <<endl;
  	if(this->ypos_ == 8){
  		if(this->zpos_ == 0){
  			this->movement(East, RobotNum);
  		}
  		else{//begin else
  			if((this->storelist_->xstore_==12 && this->storelist_->ystore_==4 && this->storelist_->zstore_==1)||
  			   (this->storelist_->xstore_==4 && this->storelist_->ystore_==4 && this->storelist_->zstore_==1)) {
  				this->movement(West, RobotNum);
  			}
  			else{
  				this->movement(North, RobotNum);
  			}
  		}//end else
  	}
  	else if(this->zpos_ == 0){
  		if(this->ypos_ == 10){
  			this->movement(NorthEast, RobotNum);
  		}
  		else{
  			this->movement(East, RobotNum);
  		}
  	}
  	else{
  		if(this->ypos_ == 6){
  			this->movement(NorthWest, RobotNum);
  		}
  		else{
  			this->movement(West, RobotNum);	
  		}
  		
  	}
  }//end if xpos ==16


  //if the robot is in the top row
  else if(this->xpos_ == 0){
  	if(DEBUG)cout<<"Line 87"<<endl;

  	if(this->zpos_ == 0){ if(DEBUG)cout<<"Z=0"<<endl;
  		if(this->ypos_ == 6){
  			this->movement(SouthWest, RobotNum);
  		}
  		else if(this->ypos_ == 8){
  			if(this->storelist_->ystore_==4) {
  				this->movement(West, RobotNum);
  			}
  			else{
  				this->movement(South, RobotNum);
  			}
	  	}//end if ypos==8

  		else{
  			this->movement(West, RobotNum);
  		}
  	}
  	else{//zpos =1
  		if(this->ypos_ == 10){
  			this->movement(SouthEast, RobotNum);
  		}
  		else{
  			this->movement(East, RobotNum);	
  		}
  		
  	}
  }
  
  
  else if(this->ypos_ ==0){
  	if(DEBUG)cout<<"Line 122"<<endl;
  	if(this->zpos_ ==0){
  		if(this->xpos_ == 8){
  			if((this->storelist_->xstore_==12 && this->storelist_->ystore_==4 && this->storelist_->zstore_==0)||
  			   (this->storelist_->xstore_==12 && this->storelist_->ystore_==12 && this->storelist_->zstore_==0)){
  			   	this->movement(South, RobotNum);
  			   }
  			   else{
  			   	this->movement(East, RobotNum);
  			   }
  		}
  		else if(this->xpos_ == 10){
  			this->movement(SouthEast, RobotNum);
  		}
  		else{
  			this->movement(South, RobotNum);
  		}
  	}
  	else{//if zpos == 1
  		if(this->xpos_ == 6){
  			this->movement(NorthEast, RobotNum);
  		}
  		else{
  			this->movement(North, RobotNum);
  		}
  	
  	}
  }
  
  //if the robot is in column 16
  else if(this->ypos_ ==16){
	if(DEBUG)cout<<"Line 153"<<endl;
  	if(this->zpos_ ==1){//if on the second floor
  		if(this->xpos_ == 8){
  			if(this->storelist_->xstore_==12 && this->storelist_->zstore_==1){
  			   	this->movement(South, RobotNum);
  			   }
  			   else{
  			   	this->movement(West, RobotNum);
  			   }
  		}
  		else if(this->xpos_ == 10){
  			this->movement(SouthWest, RobotNum);
  		}
  		else{
  			this->movement(South, RobotNum);
  		}
  	}
  	else{//if zpos == 0
  		if(DEBUG)cout<<"Z==0" <<endl;
  		if(this->xpos_ == 6){
  			if(DEBUG)cout<<"enter NW" << endl;
  			this->movement(NorthWest, RobotNum);
  		}
  		else if(this->xpos_==8){
  			if(this->storelist_->xstore_==8 && this->storelist_->ystore_ == 16 && this->storelist_->zstore_==0){
  				this->movement(End, RobotNum);
  			}
  		
  			else{
  				if(DEBUG)cout<<"enter N" <<endl;
  				this->movement(North, RobotNum);
  			}
  		}
  		else{
  			if(DEBUG)cout<<"enter N" <<endl;
  			this->movement(North, RobotNum);
  		}
  	
  	}
  }
  
  
  else if(this->xpos_*10+this->ypos_ ==51 || this->xpos_*10+this->ypos_ ==42 || 
  	    this->xpos_*10+this->ypos_ ==24 || this->xpos_*10+this->ypos_ ==15){
  	if(DEBUG)cout<<"Line 198"<<endl;
	if(this->zpos_ ==0){
		this->movement(SouthWest, RobotNum);
	}
  	else{
  		this->movement(NorthEast, RobotNum);
  	}
  }
  
  else if(this->xpos_*10+this->ypos_ ==21 || this->xpos_*10+this->ypos_ ==32 || 
  	    (this->xpos_== 4 && this->ypos_ ==14) || this->xpos_*10+this->ypos_ ==65){
  	    	if(DEBUG)cout<<"line 205" <<endl;
	if(this->zpos_==0){ 
		this->movement(NorthWest, RobotNum);
	}
	else{
		this->movement(SouthEast, RobotNum);
	}
  }


  else if((this->xpos_ == 11 && this->ypos_ ==15) || (this->xpos_ == 12 && this->ypos_ ==14) || 
  	    (this->xpos_ == 14 && this->ypos_ ==12) || (this->xpos_ == 15 && this->ypos_ ==11)){
  	    	if(DEBUG)cout<<"Line 220"<<endl;
	if(this->zpos_==0){
		if(DEBUG)cout<<"enter NE" <<endl;
		this->movement(NorthEast, RobotNum);
	}
	else{
		this->movement(SouthWest, RobotNum);
	}
  }

  else if((this->xpos_ == 11 &&this->ypos_ ==1) || (this->xpos_ == 12 && this->ypos_ ==2) || 
  	    (this->xpos_ == 14 && this->ypos_ ==4) || (this->xpos_ == 15 && this->ypos_ == 5)){
  	    	if(DEBUG)cout<<"Line 232"<<endl;
	if(this->zpos_==0){
		this->movement(SouthEast, RobotNum);
	}
	else{
		this->movement(NorthWest, RobotNum);
	}
  }
  
  //if the bot is at 3 3 Z
  else if(this->xpos_ == 3 && this->ypos_ == 3){
  	if(DEBUG)cout<<"Line 243"<<endl;
  	//if the bot is on the first floor
  	if(this->zpos_ == 0){
  		//if the next store is at (4,4,0)
  		if((this->storelist_->xstore_==4 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 0)){
  			this->movement(SouthEast, RobotNum);
  		}
  		else{
  			this->movement(SouthWest, RobotNum);
  		}
  	}
  	else{
  		//if the next store is at (4,4,1)
  		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 1){
  			this->movement(SouthEast, RobotNum);
  		}
  		else{
  			this->movement(NorthEast, RobotNum);
  		}
  	}
  }

  else if(this->xpos_ == 3 && this->ypos_ == 13){
  	if(DEBUG)cout<<"Line 266"<<endl;
  	//if the bot is on the first floor
  	if(this->zpos_ == 0){
  		//if the next store is at (4,12,0)
  		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 0){
  			this->movement(SouthWest, RobotNum);
  		}
  		else{
  			this->movement(NorthWest, RobotNum);
  		}
  	}
  	else{
  		//if the next store is at (4,12,1)
  		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 1){
  			this->movement(SouthWest, RobotNum);
  		}
  		else{
  			this->movement(SouthEast, RobotNum);
  		}
  	}
  }
  
    else if(this->xpos_ == 13 && this->ypos_ ==13){
  	if(DEBUG)cout<<"Line 290"<<endl;
  	//if the bot is on the first floor
  	if(this->zpos_ == 0){
  		//if the next store is at (4,4,0)
  		if((this->storelist_->xstore_==12 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 0)){
  			this->movement(NorthWest, RobotNum);
  		}
  		else{
  			this->movement(NorthEast, RobotNum);
  		}
  	}
  	else{
  		//if the next store is at (4,4,1)
  		if(this->storelist_->xstore_==12 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 1){
  			this->movement(NorthWest, RobotNum);
  		}
  		else{
  			this->movement(SouthWest, RobotNum);
  		}
  	}
  }
  
      else if(this->xpos_ == 13 && this->ypos_ ==3){
  	if(DEBUG)cout<<"Line 313"<<endl;
  	//if the bot is on the first floor
  	if(this->zpos_ == 0){
  		//if the next store is at (12,4,0)
  		if((this->storelist_->xstore_==12 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 0)){
  			this->movement(NorthEast, RobotNum);
  		}
  		else{
  			this->movement(SouthEast, RobotNum);
  		}
  	}
  	else{
  		//if the next store is at (4,4,1)
  		if(this->storelist_->xstore_==12 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 1){
  			this->movement(NorthEast, RobotNum);
  		}
  		else{
  			this->movement(NorthWest, RobotNum);
  		}
  	}
  }


  else if(this->xpos_ == 4 && this->ypos_ == 12){
  	if(DEBUG)cout<<"Line 314"<<endl;
 	movement(NorthEast, RobotNum);
  }

  else if(this->xpos_ == 4 && this->ypos_ == 4){
  	if(DEBUG)cout<<"Line 318"<<endl;
	this->movement(NorthWest, RobotNum);
  }
  
    else if(this->xpos_ == 12 && this->ypos_ == 4){
  	if(DEBUG)cout<<"Line 347"<<endl;
 	movement(SouthWest, RobotNum);
  }
  
      else if(this->xpos_ == 12 && this->ypos_ == 12){
  	if(DEBUG)cout<<"Line 348"<<endl;
 	movement(SouthEast, RobotNum);
  }


  else if(this->xpos_ == 8 && this->ypos_ ==1 || this->xpos_ == 8 && this->ypos_ ==2 || 
  	    this->xpos_ == 8 && this->ypos_ ==3 || this->xpos_ == 8 && this->ypos_ ==5 ||
	    this->xpos_ == 8 && this->ypos_ ==6 || this->xpos_ == 8 && this->ypos_ ==7 ||
	    this->xpos_ == 8 && this->ypos_ ==9 || this->xpos_ == 8 && this->ypos_ ==10 ||
	    this->xpos_ == 8 && this->ypos_ ==11 || this->xpos_ == 8 && this->ypos_ ==13 ||
	    this->xpos_ == 8 && this->ypos_ ==14 || this->xpos_ == 8 && this->ypos_ ==15){
	    	if(DEBUG)cout<<"Line 330"<<endl;
	if(this->zpos_==0){
		this->movement(East, RobotNum);
	}
	else{
		this->movement(West, RobotNum);
	}
  }


  else if((this->xpos_ == 1  && this->ypos_ == 8) || (this->xpos_ == 2 && this->ypos_ == 8) || 
  	    (this->xpos_ == 3 && this->ypos_ == 8)|| (this->xpos_ == 5 && this->ypos_ == 8) ||
	    (this->xpos_ == 6 && this->ypos_ == 8)|| (this->xpos_ == 7 && this->ypos_ == 8) ||
	    (this->xpos_ == 9 && this->ypos_ == 8)|| (this->xpos_ == 10 && this->ypos_ ==8) ||
	    (this->xpos_ == 11 && this->ypos_ ==8)|| (this->xpos_ == 13 && this->ypos_ ==8) ||
	    (this->xpos_ == 14 && this->ypos_ ==8)|| (this->xpos_ ==15 && this->ypos_ == 8)){
	    	if(DEBUG)cout<<"Line 346"<<endl;
	if(this->zpos_==0){
		this->movement(South, RobotNum);
	}
	else{
		this->movement(North, RobotNum);
  	}
 }

  else if(this->xpos_ == 8 && this->ypos_ ==4){
  	if(DEBUG)cout<<"Line 356"<<endl;
	if(this->zpos_ == 0){
		if(this->storelist_->xstore_==6 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 0){
  			this->movement(North, RobotNum);
  		}
		else if(this->storelist_->xstore_==10 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 0){
  			this->movement(South, RobotNum);
  		}
		else{
			this->movement(East, RobotNum);
		}
	}
	else{
		if(this->storelist_->xstore_==6 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 1){
  			this->movement(North, RobotNum);
  		}
		else if(this->storelist_->xstore_==10 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 1){
  			this->movement(South, RobotNum);
  		}
		else{
			this->movement(West, RobotNum);
		}
	}
  }

  else if(this->xpos_ == 7 && this->ypos_ == 4){
  	if(DEBUG)cout<<"Line 382"<<endl;
	if(this->zpos_ == 0){
		if(this->storelist_->xstore_==6 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 0){
			this->movement(North, RobotNum);
		}
		else{
			this->movement(South, RobotNum);
		}
	}
	else{
		if(this->storelist_->xstore_==6 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 1){
			this->movement(North, RobotNum);
		}
		else{
			this->movement(South, RobotNum);
		}
	}
  }
		

  else if(this->xpos_ == 9 && this->ypos_ == 4){
  	if(DEBUG)cout<<"Line 403"<<endl;
	if(this->zpos_ == 0){
		if(this->storelist_->xstore_==10 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 0){
			this->movement(South, RobotNum);
		}
		else{
			this->movement(North, RobotNum);
		}
	}
	else{
		if(this->storelist_->xstore_==10 && this->storelist_->ystore_==4 && this->storelist_->zstore_ == 1){
			this->movement(South, RobotNum);
		}
		else{
			this->movement(North, RobotNum);
		}
	}
  }

  else if(this->xpos_ == 10 && this->ypos_==4){
  	if(DEBUG)cout<<"Line 423"<<endl;
	this->movement(North, RobotNum);
  }

  else if(this->xpos_ == 6 && this->ypos_==4){
  	if(DEBUG)cout<<"Line 428"<<endl;
	this->movement(South, RobotNum);
  }

  else if(this->xpos_ == 8 && this->ypos_ == 12){
  	if(DEBUG)cout<<"Line 433"<<endl;
	if(this->zpos_ ==0){
		if(this->storelist_->xstore_==6 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 0){
			this->movement(North, RobotNum);
		}
		else if(this->storelist_->xstore_==10 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 0){
			this->movement(South, RobotNum);
		}
		else{
			this->movement(East, RobotNum);
		}
	}
	else{
		if(this->storelist_->xstore_==10 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 1){
			this->movement(South, RobotNum);
		}
		else if(this->storelist_->xstore_==6 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 1){
			this->movement(North, RobotNum);
		}
		else{
			this->movement(West, RobotNum);
		}
	}
  }
  else if(this->xpos_ == 7 && this->ypos_ == 12){
  	if(DEBUG)cout<<"Line 458"<<endl;
	if(this->zpos_ == 0){
		if(this->storelist_->xstore_== 6 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 0){
			this->movement(North, RobotNum);
		}
		else{
			this->movement(South, RobotNum);
		}
	}
	else{
		if(this->storelist_->xstore_==6 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 1){
			this->movement(North, RobotNum);
		}
		else{
			this->movement(South, RobotNum);
		}
	}
  }

  else if(this->xpos_ == 10 && this->ypos_ == 12){
  	if(DEBUG)cout<<"Line 478"<<endl;
	this->movement(North, RobotNum);
  }
    else if(this->xpos_ == 9 && this->ypos_ == 12){
  	if(DEBUG)cout<<"Line 480"<<endl;
  	if(this->zpos_ == 0){
			if(this->storelist_->xstore_== 10 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 0){
			this->movement(South, RobotNum);
		}
		else{
			this->movement(North, RobotNum);
		}
	}
	else{
		if(this->storelist_->xstore_==10 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 1){
			this->movement(South, RobotNum);
		}
		else{
			this->movement(North, RobotNum);
		}
	}
  }


  else if(this->xpos_ == 6 && this->ypos_ == 12){
  	if(DEBUG)cout<<"Line 484"<<endl;
	this->movement(South, RobotNum);
  }


  else if(this->xpos_ == 12 && this->ypos_ == 8){
  	if(DEBUG)cout<<"Line 490"<<endl;
	if(this->zpos_ ==0){
		if(this->storelist_->xstore_==12 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 0){
			this->movement(West, RobotNum);
		}
		else if(this->storelist_->xstore_==12 && this->storelist_->ystore_==10 && this->storelist_->zstore_ == 0){
			this->movement(East, RobotNum);
		}
		else{
			this->movement(South, RobotNum);
		}
	}
	else{
		if(this->storelist_->xstore_==12 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 1){
			this->movement(West, RobotNum);
		}
		else if(this->storelist_->xstore_==12 && this->storelist_->ystore_==10 && this->storelist_->zstore_ == 1){
			this->movement(East, RobotNum);
		}
		else{
			this->movement(North, RobotNum);
		}
	}
  }

  else if(this->xpos_ == 12 && this->ypos_ == 7){
  	if(DEBUG)cout<<"Line 516"<<endl;
	if(this->zpos_ == 0){
		if(this->storelist_->xstore_==12 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 0){
			this->movement(West, RobotNum);
		}
		else{
			this->movement(East, RobotNum);
		}
	}
	else{
		if(this->storelist_->xstore_==12 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 1){
			this->movement(West, RobotNum);
		}
		else{
			this->movement(East, RobotNum);
		}
	}
  }


  else if(this->xpos_ == 12 && this->ypos_ ==9){
  	if(DEBUG)cout<<"Line 537"<<endl;
	if(this->zpos_ == 0){
		if(this->storelist_->xstore_==12 && this->storelist_->ystore_==10 && this->storelist_->zstore_ == 0){
			this->movement(East, RobotNum);
		}
		else{
			this->movement(West, RobotNum);
		}
	}
	else{
		if(this->storelist_->xstore_==12 && this->storelist_->ystore_==10 && this->storelist_->zstore_ == 1){
			this->movement(East, RobotNum);
		}
		else{
			this->movement(West, RobotNum);
		}
	}
  }

  else if(this->xpos_ == 12 && this->ypos_==6){
  	if(DEBUG)cout<<"Line 557"<<endl;
	this->movement(East, RobotNum);
  }

  else if(this->xpos_ == 12 && this->ypos_==10){
  	if(DEBUG)cout<<"Line 562"<<endl;
	this->movement(West, RobotNum);
  }

  else if(this->xpos_ == 4 && this->ypos_ == 8){
  	if(DEBUG)cout<<"Line 567"<<endl;
	if(this->zpos_ ==0){
		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 0){
			this->movement(West, RobotNum);
		}
		else if(this->storelist_->xstore_==4 && this->storelist_->ystore_==10 && this->storelist_->zstore_ == 0){
			this->movement(East, RobotNum);
		}
		else{
			this->movement(South, RobotNum);
		}
	}
	else{
		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 1){
			this->movement(West, RobotNum);
		}
		else if(this->storelist_->xstore_==4 && this->storelist_->ystore_==10 && this->storelist_->zstore_ == 1){
			this->movement(East,RobotNum);
		}
		else{
			this->movement(North, RobotNum);
		}
	}
  }

  else if(this->xpos_ == 4 && this->ypos_ == 7){
  	if(DEBUG)cout<<"Line 593"<<endl;
	if(this->zpos_ == 0){
		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 0){
			this->movement(West, RobotNum);
		}
		else{
			this->movement(East, RobotNum);
		}
	}
	else{
		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 1){
			this->movement(West, RobotNum);
		}
		else{
			this->movement(East, RobotNum);
		}
	}
  }


  else if(this->xpos_ == 4 && this->ypos_ ==9){
  	if(DEBUG)cout<<"Line 614"<<endl;
	if(this->zpos_ == 0){
		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==10 && this->storelist_->zstore_ == 0){
			this->movement(East, RobotNum);
		}
		else{
			this->movement(West, RobotNum);
		}
	}
	else{
		if(this->storelist_->xstore_==4 && this->storelist_->ystore_==10 && this->storelist_->zstore_ == 1){
			this->movement(East, RobotNum);
		}
		else{
			this->movement(West, RobotNum);
		}
	}
  }

  else if(this->xpos_ == 4 && this->ypos_==6){
  	if(DEBUG)cout<<"Line 634"<<endl;
	this->movement(East, RobotNum);
  }

  else if(this->xpos_ == 4 && this->ypos_==10){
  	if(DEBUG)cout<<"Line 639"<<endl;
	this->movement(West, RobotNum);
  }

  else if(this->xpos_ == 8 && this->ypos_ == 8){
  	if(DEBUG)cout<<"Line 644"<<endl;
	if(this->zpos_ == 0){
		if(this->storelist_->zstore_ == 1){
			this->movement(Up, RobotNum);
			this->wait_ = TIME+3;
		}
		else if((this->storelist_->xstore_==12 && this->storelist_->ystore_==6 && this->storelist_->zstore_ == 0) ||
			  (this->storelist_->xstore_==12 && this->storelist_->ystore_==10 && this->storelist_->zstore_ == 0) ||
			  (this->storelist_->xstore_==12 && this->storelist_->ystore_==12 && this->storelist_->zstore_ == 0)){
			this->movement(South, RobotNum);
		}
		else{
			this->movement(East, RobotNum);
		}
	}
	else{
		if(this->storelist_->zstore_ == 0){
			this->movement(Down, RobotNum);
			this->wait_ = TIME+3;
		}
		else if((this->storelist_->xstore_== 10 && this->storelist_->ystore_== 4 && this->storelist_->zstore_ == 1) ||
			  (this->storelist_->xstore_== 6 && this->storelist_->ystore_== 4 && this->storelist_->zstore_ == 1) ||
			  (this->storelist_->xstore_== 4 && this->storelist_->ystore_== 4 && this->storelist_->zstore_ == 1)){
			this->movement(West, RobotNum);
		}
		else{
			this->movement(North, RobotNum);
		}
	}
  }
  else{
  	cout<<endl <<endl << endl << endl <<RobotNum << endl << endl << endl;
  	
  }

}

//Scott Iwanicki
//moves the Object in the given direction
int Move::movement(int direction, int RobotNum){
	switch (direction){
	case North:
		//printf("N");
		//Moves up a row
		this->xpos_--;
		Floor[this->xpos_][this->ypos_][this->zpos_] = Floor[this->xpos_][this->ypos_][this->zpos_]*10+ RobotNum;
		
		break;
	case NorthWest:
		//Moves up a row and left a colmun
		this->xpos_--;
		this->ypos_--;
		Floor[this->xpos_][this->ypos_][this->zpos_] = Floor[this->xpos_][this->ypos_][this->zpos_]*10+ RobotNum;
		break;
	case West:
		//case 2 Moves left 4 columns and increments TIME by 1 for each movement
		this->ypos_--;
		Floor[this->xpos_][this->ypos_][this->zpos_] = Floor[this->xpos_][this->ypos_][this->zpos_]*10+ RobotNum;
		
		break;
	case SouthWest:
		//printf("SW");
		//case 3 Moves down a row and left a column
		this->xpos_++;
		this->ypos_--;
		Floor[this->xpos_][this->ypos_][this->zpos_] = Floor[this->xpos_][this->ypos_][this->zpos_]*10+ RobotNum;
		
		break;
	case South:
		//printf("S");
		//case 4 Moves down a row
		this->xpos_++;
		Floor[this->xpos_][this->ypos_][this->zpos_] = Floor[this->xpos_][this->ypos_][this->zpos_]*10+ RobotNum;
		break;
	case SouthEast:
		//printf("SE");
		//case 5 Moves down and to the right
		this->xpos_++;
		this->ypos_++;
		Floor[this->xpos_][this->ypos_][this->zpos_] = Floor[this->xpos_][this->ypos_][this->zpos_]*10+ RobotNum;
		break;
	case East:
		//printf("E");
		//case 6 Moves right a column
		this->ypos_++;
		Floor[this->xpos_][this->ypos_][this->zpos_] = Floor[this->xpos_][this->ypos_][this->zpos_]*10+ RobotNum;
		break;
	case NorthEast:
		//printf("NE");
		//case 7 Moves up a row and right a column
		this->xpos_--;
		this->ypos_++;
		Floor[this->xpos_][this->ypos_][this->zpos_] = Floor[this->xpos_][this->ypos_][this->zpos_]*10+ RobotNum;
		break;
	case Up:
		//printf("Up");
		//case 8 Moves up a Floor and prints when the bot
		//got on and off the elevator
		this->zpos_++;
		printf("Shopper %d got on elevator at time %d\n", RobotNum, TIME);
		Floor[this->xpos_][this->ypos_][this->zpos_] =Floor[this->xpos_][this->ypos_][this->zpos_]*10+ RobotNum;
		printf("Shopper %d got off elevator at time %d\n", RobotNum, TIME+3);
		break;
	case Down:
		//printf("Down");
		//case 9 Moves down a Floor and prints when the bot
		//got on and off the elevator
		this->zpos_--;
		printf("Shopper %d got on elevator at time %d\n", RobotNum, TIME);
		Floor[this->xpos_][this->ypos_][this->zpos_] = Floor[this->xpos_][this->ypos_][this->zpos_]*10+ RobotNum;
		printf("Shopper %d got off elevator at time %d\n", RobotNum, TIME+3);
		break;

	case End:
		//case 10 Removes bot from simulation and prints out a notification
		printf("Shopper %d left the simulation at time %d\n", RobotNum, TIME);
		break;
	default:
		break;
	}
	return 0;
}
