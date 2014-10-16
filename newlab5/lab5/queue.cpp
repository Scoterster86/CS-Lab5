#include "lab5.h"

Queue::Queue()
{
	this->listhead_ = nullptr;
	this->listtail_ = nullptr;
}

///change the pointer to the next shopper in the queue
void Queue::RemoveShopper()
{
	this->listhead_ = this->listhead_->nextshopper_;
}

///Get a shopper pointer and put it at the end of the list
void Queue::AddShopper(Shopper* shopper)
{
	if(this->listhead_ != NULL){
	//cout<<"Adding Shopper to end of list"<<endl;
	this->listtail_->nextshopper_= shopper;
	this->listtail_ = shopper;
	}
	else{
	//cout<<"Setting shopper to head of list"<<endl;
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
        if(ptr->smove_->storelist_->zstore_ == 0){
        	if(ptr->smove_->storelist_->items_->itemsleft_==0){
        			ptr->smove_->storelist_->RemoveItem();
        			if(ptr->smove_->storelist_->items_ == NULL){
        				this->listhead_ = this->listhead_->nextshopper_;
        			}
        	}
        }
        else{
        	if(ptr->smove_->storelist_->items_->amount_ - ptr->smove_->storelist_->items_->itemsleft_ % TimeSlice = 0 ||
        			(ptr->smove_->storelist_->items_->itemsleft_ == 0)){
        		if(ptr->smove_->storelist_->items_->itemsleft_ != 0){
        			this->listtail_->nextshopper_ = this->listhead_;
        			this->listtail_ = this->listhead_;
        			this->listhead_ = this->listhead_->nextshopper_;
        		}
        		else{
        			ptr->smove_->storelist_->RemoveItem();
        			if(ptr->smove_->storelist_->items_ == NULL){
        				this->listhead_ = this->listhead_->nextshopper_;
        			}
        			else{
					this->listtail_->nextshopper_ = this->listhead_;
        				this->listtail_ = this->listhead_;
        				this->listhead_ = this->listhead_->nextshopper_;
        			}
        		}
        	}
        }
}
