#include "lab5.h"


void Store::AddStore(Store* store)
{
	///	If the store list is not empty	///
	if (this)
	{

	}

	//// If the store list is empty	///
	else
	{
		this->xstore_ = store->xstore_;
		this->ystore_ = store->ystore_;
		this->zstore_ = store->zstore_;

		this->NextStore_ = nullptr;	//set the next store as empty
	}
}