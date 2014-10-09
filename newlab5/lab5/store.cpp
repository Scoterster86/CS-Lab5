#include "lab5.h"

Store::Store(Store* store)
{
	this->xstore_ = store->xstore_;
	this->ystore_ = store->ystore_;
	this->zstore_ = store->zstore_;
	this->TimeSlice_ = store->TimeSlice_;
	this->pNext = nullptr;
}


Store::Store()
{
	this->xstore_ = 0;
	this->ystore_ = 0;
	this->zstore_ = 0;
	this->TimeSlice_ = 0;
	this->pNext = nullptr;
}

///add a store to the storelist 
void Store::AddStore(Store* store)
{
	Store* ptr = this;
	
	//look for the end of the storelist
	while (ptr->pNext)
	{
		ptr = ptr->pNext;
	}
	ptr->pNext = store;	//the end of store has a points to the next store
}

int Store::GetSize()
{

	int n = 0;
	Store* ptr = this;
	while (ptr)	//loop until it reaches to the end of the list
	{
		n++;
		ptr = ptr->pNext;
	}
	return n;
}
