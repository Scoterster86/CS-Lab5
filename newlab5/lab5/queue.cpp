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
		cout<<"Adding Shopper to end of list"<<endl;
	this->listtail_->nextshopper_= shopper;
	this->listtail_ = shopper;
	}
	else{
		cout<<"Setting shopper to head of list"<<endl;
		this->listhead_=shopper;
		this->listtail_=shopper;
	}
}
