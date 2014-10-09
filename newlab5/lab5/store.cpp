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

void Store::AddStore(Store* store)
{
	Store* ptr = this;
	
	while (ptr->pNext)
	{
		ptr = ptr->pNext;
	}
	ptr->pNext = store;
}

int Store::GetSize()
{

	int n = 0;
	Store* ptr = this;
	while (ptr)
	{
		n++;
		ptr = ptr->pNext;
	}
	return n;
}
