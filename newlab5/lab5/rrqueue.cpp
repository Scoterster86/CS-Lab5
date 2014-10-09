#include "lab5.h"

void RRqueue::RRqueue()
{

	this->listhead_ = NULL;
	this->listtail_ = NULL;
}

void RRqueue::AddShopper(Shopper* shopper)
{
	if(this->listhead ==NULL){
	this->listhead=shopper;
	this->listtail=shopper;
	}
	else{
	this->listtail->nextshopper_=shopper;
	this->listtail = shopper;
	}
  
}

void RemoveShopper(){
	this->headptr_ = this->headptr_->nextshopper_;
}
void RunQueue()
{
	Shopper* = ptr;
	ptr = this->headptr_;
	RemoveShopper();
	if(ptr->storelist_->TimeSlice_ > TimeSlice)
	{
		ptr->storelist_->TimeSlice_ -= TimeSlice;
		ptr->slices++;
		this->AddShopper(ptr);
	}
	else
	{
		ptr->slices++;
		cout<<"Shopper 1 leaves store (" <<ptr->xpos <<", " << ptr->ypos <<") after " << ptr->slices << "Time slices at Time" <<TIME endl;
		
	}
}
