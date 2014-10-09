#include "lab5.h"

void RRqueue::RRqueue()
{

	this->listhead_ = NULL;
	this->listtail_ = NULL;
}

void RRqueue::AddShopper(Shopper* shopper)
{
	if(this->listhead ==NULL){
	this->listhead_=shopper;
	this->listtail_=shopper;
	}
	else{
	this->listtail_->nextshopper_=shopper;
	this->listtail_ = shopper;
	}
  
}

void RRqueue::RemoveShopper(){
	this->listhead_ = this->listhead_->nextshopper_;
}

void RRqueue::RunQueue()
{
	Shopper* ptr;
	ptr = this->listhead_;
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
