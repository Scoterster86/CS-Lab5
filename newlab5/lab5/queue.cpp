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
