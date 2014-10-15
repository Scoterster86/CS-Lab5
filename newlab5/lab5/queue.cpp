#include "lab5.h"

Queue::Queue()
{
	this->shopperPtr_ = nullptr;
	this->nextShopper = nullptr;
}

Queue::Queue(Shopper* shopperPtr)
{
	this->shopperPtr_ = shopperPtr;
	this->nextShopper = nullptr;
}
