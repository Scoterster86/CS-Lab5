#include "lab5.h"

void RRqueue::RRqueue()
{

	this->listhead_ = NULL;
	this->listtail_ = NULL;
}

void RRqueue::AddShopper(Shopper*)
{
	Store* ptr = this;
	
	while (ptr->pNext)
	{
		ptr = ptr->pNext;
	}
	ptr->pNext = store;
}
	this->listhead=Shopper*;
	this->listtail=Shopper*;
  
}
