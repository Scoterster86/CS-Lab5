#include "lab5.h"

//Scott Iwanicki
//default constructor for an item
Item::Item()
{
  this->ProductCode_ == "";
  this->amount_=0;
  this->nextItem_ = nullptr;
  this->pStore = nullptr;
}

//Yo Karita
//default constructor for a store
Store::Store()
{
  this->xstore_ = 0;
  this->ystore_ = 0;
  this->zstore_ = 0;
  this->items_ = nullptr;
  this->pNext = nullptr;

}

//Scott Iwanicki
//determines the priority of the item
int Item::HasPriority(Item item)
{
  //if the product codes are the same return 0
  if (this->ProductCode_.compare(item.ProductCode_) == 0) return 0;

  //else if the item's product code is a lower priority return 1
  else if (this->ProductCode_.compare(item.ProductCode_) > 0) return 1;

  //else if the item's product code is a higher priority return -1
  else  return -1;
}
