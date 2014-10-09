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
