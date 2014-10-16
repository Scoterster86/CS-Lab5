#include "lab5.h"


//Yo Karita
//constructor for a shopper
Shopper::Shopper()
{
        this->RobotNum_ = 0;
        this->smove_ = new Move();
        this->slices = 0;
        this->enteredstore_=0;
        this->nextshopper_ = nullptr;
        this->nextInQueue_=nullptr;
}

//Yo Karita
//constructor for a shopper with the bot number as an input
Shopper::Shopper(int k)
{ 
        this->RobotNum_ = k;
        this->smove_ = new Move();
        this->slices = 0;
        this->enteredstore_=0;
        this->nextshopper_ = nullptr;
        this->nextInQueue_=nullptr;
}


//Scott Iwanicki
//runs when a shopper reaches a store
int Shopper::storecomplete(){
        int xpos = this->smove_->storelist_->xstore_;
        int ypos = this->smove_->storelist_->ystore_;
        int zpos = this->smove_->storelist_->zstore_;
        printf("Shopper %d arrives at store S(%d,%d) on the %d Floor at time %d\n", this->RobotNum_, xpos, ypos, (zpos + 1), TIME);
        //shopper enters round robin queue
        RRqueue* ptr = new RRqueue(this);
        //the shopper is processed at the round robin queue
        while(this->smove_->storelist_->TimeSlice_ != 0)
        {
                TIME+= (TimeSlice/10);
                ptr->RunQueue();
                timecheck();
        }
        //removes the store from the shopper's list of stores
        this->smove_->RemoveStore();
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
                this->smove_->xpos_ = shopper->smove_->xpos_;
                this->smove_->ypos_ = shopper->smove_->ypos_;
                this->smove_->zpos_ = shopper->smove_->zpos_;
                this->smove_->storelist_ = new Store();
                this->nextshopper_ = nullptr;
        }
        //else set the shopper to the next shopper
        else{
        	Shopper* headptr = this->nextshopper;
        	Shopper* tailptr = NULL;
        	while(headptr !=NULL){
        		tailptr= headptr;
        		headptr=headptr->nextshopper;
        		
        	}
        	if(tailptr !=NULL){
        		tailptr->nextshopper_ = shopper;
        	}
        	else{
        		this->nextshopper_=shopper;
        	}
}

//Yo Karita
//removes the shopper from a list of shoppers
void Shopper::RemoveShopper(Shopper* shopper)
{
        shopper= shopper->nextshopper_;
}

void Shopper::AddItem(string productcode, int amount)
{
	Item* newitem = new Item(productcode, amount);
	ItemList* temp = this->itemlist_;
	while (temp)
	{
		temp = this->itemlist_->nextitem_;
	}
	temp->item_ = newitem;
	temp->nextitem_ = nullptr;
}


