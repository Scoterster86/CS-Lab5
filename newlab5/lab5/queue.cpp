#include "lab5.h"
//Scott Iwanicki
//constructor for queue
Queue::Queue()
{
	this->listhead_ = nullptr;
	this->listtail_ = nullptr;
}

//removes the shopper at the head of the list
void Queue::RemoveShopper()
{
	this->listhead_ = this->listhead_->nextInQueue_;
}

//Scott Iwanicki
//removes a shopper from the list
Shopper* Queue::RemoveShopper(Shopper* shopper){
	Shopper* currentPtr =this->listhead_;
	Shopper* prevPtr = NULL;
	//cout<<"Remove Shopper"<<endl;
	while(currentPtr && currentPtr->RobotNum_ != shopper->RobotNum_){
		prevPtr = currentPtr;
		currentPtr = currentPtr->nextshopper_ ;
		//cout<<"removing shopper"<<endl;
	}
	if(currentPtr == NULL){
		//cout<<"Current Ptr null"<<endl;
		return NULL;
	}
	else{
		//if the shopper isn't at the front of the list
		if(prevPtr != NULL){
		//	cout<<"Prev Ptr not null"<<endl;
		//set the previous shopper's next pointer to the  current shoppers's next shopper
		prevPtr->nextshopper_ = currentPtr->nextshopper_ ;
		return currentPtr->nextshopper_;
		}
		else{
		//cout<<"Remove first shopper in list"<<endl;
		//sets the list head to the next shopper in the list
			this->listhead_ = this->listhead_->nextshopper_ ;
			return this->listhead_;
		}
	}
}

//Scott Iwanicki
//adds a shopper to a queue
void Queue::AddShopper(Shopper* shopper, int i){
	//if the list is emput
	if(this->listhead_ != NULL){
	//cout<<"Adding Shopper to end of list"<<endl;
	this->listtail_->nextshopper_= shopper;
	this->listtail_ = shopper;
	}
	//if the list isn't empyt
	else{
	//cout<<"Setting shopper to head of list"<<endl;
	//adds the shopper to the end of the list
		this->listhead_=shopper;
		this->listtail_=shopper;
	}	
}

//Scott Iwanicki
///Get a shopper pointer and put it at the end of the list
void Queue::AddShopper(Shopper* shopper)
{
	//if the list isn't empty
	if(this->listhead_ != NULL){
	//cout<<"Adding Shopper to end of list"<<endl;
	//add the shopper to the end of the list
	this->listtail_->nextInQueue_= shopper;
	this->listtail_ = shopper;
	}
	else{
	//cout<<"Setting shopper to head of list"<<endl;
	//set the shopper to the head and tail of the list
		this->listhead_=shopper;
		this->listtail_=shopper;
	}
}
//Scott Iwanicki
//if the shopper is in a store on the first floor then use the fcfs queue else
//processes the head of the list and removes it from the queue if its service is complete,
//or inserts the shopper at the end of the queue
void Queue::RunQueue()
{
        Shopper* ptr;
        ptr = this->listhead_;
        //if the shopper needs more service
        ptr->smove_->storelist_->items_->itemsleft_ --;
        //if the store is on the first floor
        if(ptr->smove_->storelist_->zstore_ == 0){
        	//cout<< ptr->smove_->storelist_->items_->itemsleft_<< endl;
        //	cout<<"Store is z=0"<<endl;
        	//if the shopper is done with that item 
        	if(ptr->smove_->storelist_->items_->itemsleft_==0){
        		ptr->smove_->storelist_->RemoveItem();
        		//if there are no more items in the shopper's list
        		if(ptr->smove_->storelist_->items_ == NULL){
        			this->listhead_ = this->listhead_->nextInQueue_;
        		//	cout<<"Remove Store for queue"<<endl;
        			ptr->smove_->RemoveStore();
        			ptr->enteredstore_ = 0;
        		}
        		else if(ptr->smove_->storelist_->items_->ProductCode_  == ""){
        			this->listhead_ = this->listhead_->nextInQueue_;
        			//cout<<"Remove Store for queue"<<endl;
        			ptr->smove_->RemoveStore();
        			ptr->enteredstore_ = 0;
        		}
        	}
        }
        //if the store is on the second floor
        else{
        	//cout<< ptr->smove_->storelist_->items_->itemsleft_<< endl;
        	//if the timeslice is up or if the shopper is out of the item
        	if((ptr->smove_->storelist_->items_->amount_ - ptr->smove_->storelist_->items_->itemsleft_ % TimeSlice == 0 )
        		|| (ptr->smove_->storelist_->items_->itemsleft_ == 0)){
        			//cout<<"TimeSlice Up/Out of Items"<<endl;
        		//if there is no more of that item
        		if(ptr->smove_->storelist_->items_->itemsleft_ == 0){
        			//remove the item from the shopper
        			ptr->smove_->storelist_->RemoveItem();
        			//if there are no items in the list
        			if(ptr->smove_->storelist_->items_ == NULL){
        				//remove the store
        				ptr->smove_->RemoveStore();
        				//set entered store =0
        				ptr->enteredstore_ = 0;
        			}
        			//if there are items in the list
        			else{
        				//remove the shopper from the head of the queue
        				//and add the shopper to the end of the list 
        				this->listtail_->nextInQueue_ = this->listhead_;
        				this->listtail_ = this->listhead_;
        				this->listhead_ = this->listhead_->nextInQueue_;
        			}
        			
        		}
        		//if there are still items left
        		else{
        			if(ptr->smove_->storelist_->items_ == NULL){
        				this->listhead_ = this->listhead_->nextInQueue_;
        				ptr->smove_->RemoveStore();
        				ptr->enteredstore_ = 0;
        			}
        			//remove the shopper from the head of the queue
        			//and add the shopper to the end of the list 
        			else{
					this->listtail_->nextInQueue_ = this->listhead_;
        				this->listtail_ = this->listhead_;
        				this->listhead_ = this->listhead_->nextInQueue_;
        			}
        		}
        	}
        }
}
