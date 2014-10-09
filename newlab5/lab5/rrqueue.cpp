#include "lab5.h"

//constructor for the round robin queue
RRqueue::RRqueue()
{

	this->listhead_ = NULL;
	this->listtail_ = NULL;
}

//constructor of round robin queue with a shopper as an input
RRqueue::RRqueue(Shopper* shopper)
{
	//sets the shopper to the head and tail pointers
	this->listhead_ = shopper;
	this->listtail_ = shopper;
}

//adds a shopper to the queue
void RRqueue::AddShopper(Shopper* shopper)
{
	//if the list is empty, insert the shopper at the front of the list
	if(this->listhead_ ==NULL){
	this->listhead_=shopper;
	this->listtail_=shopper;
	}
	//else, insert the shopper at the end of the list
	else{
	this->listtail_->nextshopper_=shopper;
	this->listtail_ = shopper;
	}
  
}

//removes a shopper from the head of the list
void RRqueue::RemoveShopper(){
	this->listhead_ = this->listhead_->nextshopper_;
}

//processes the head of the list and removes it from the queue if its service is complete,
//or inserts the shopper at the end of the queue
void RRqueue::RunQueue()
{
	Shopper* ptr;
	ptr = this->listhead_;
	//if the shopper needs more service
	if(ptr->storelist_->TimeSlice_ > TimeSlice)
	{
		//remove a timeslice from the needed service
		ptr->storelist_->TimeSlice_ -= TimeSlice;
		//increment slices
		ptr->slices++;
		//remove the shopper from the head of the queue
		RemoveShopper();
		//add the shopper to the end of the queue
		this->AddShopper(ptr);
	}
	//if the shopper needs no more service
	else
	{
		//set timeslice to 0
		ptr->storelist_->TimeSlice_=0;
		//increment slices
		ptr->slices++;
		//remove the shopper from the head of the list
		RemoveShopper();
		cout<<"Shopper 1 leaves store (" <<ptr->xpos_ <<", " << ptr->ypos_ <<") after " << ptr->slices << " Time slices at Time " <<TIME << endl;;
		//reset the number of slices
		ptr->slices = 0;
		
	}
}
