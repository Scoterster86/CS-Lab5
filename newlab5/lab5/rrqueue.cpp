#include "lab5.h"

RRqueue::RRqueue()
{

	this->listhead_ = NULL;
	this->listtail_ = NULL;
}

RRqueue::RRqueue(Shopper* shopper)
{

	this->listhead_ = shopper;
	this->listtail_ = shopper;
}


void RRqueue::AddShopper(Shopper* shopper)
{
	if(this->listhead_ ==NULL){
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
	if(ptr->storelist_->TimeSlice_ > TimeSlice)
	{
		ptr->storelist_->TimeSlice_ -= TimeSlice;
		
		ptr->slices++;
		RemoveShopper();
		this->AddShopper(ptr);
	}
	else
	{
		ptr->storelist_->TimeSlice_=0;
		ptr->slices++;
		RemoveShopper();
		cout<<"Shopper 1 leaves store (" <<ptr->xpos_ <<", " << ptr->ypos_ <<") after " << ptr->slices << "Time slices at Time" <<TIME << endl;;
		ptr->slices = 0;
		
	}
}
