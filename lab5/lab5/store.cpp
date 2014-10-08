#include "lab5.h"

Store::Store(Store* store)
{
	this->xstore_ = store->xstore_;
	this->ystore_ = store->ystore_;
	this->zstore_ = store->zstore_;
	this->TimeSlice_ = store->TimeSlice_;
}

void AddStore(Store* store)
{
	storelist.push_back(*store);
}

void RemoveStore()
{
	storelist.pop_back();
}