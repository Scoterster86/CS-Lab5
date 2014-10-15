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
	Shopper* temp = this->listhead_;
	if(temp != NULL){
	this->listtail_->nextshopper_=shopper
	this->listtail_ = shopper;
	}
	else{
		this->listhead_=shopper;
		this->listtail_=shopper;
	}
}
