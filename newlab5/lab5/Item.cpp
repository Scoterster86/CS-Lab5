#include "lab5.h"

//Scott Iwanicki
//default constructor for an item
Item::Item()
{
  this->ProductCode_ == "";
  this->amount_=0;
  this->nextItem_ = nullptr;
  this->pStore = new Store();
}
Item::Item(string string)
{
	this->ProductCode_ == string;
	this->pStore = new Store();
	pStore = nullptr;
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

//Scott Iwanicki
void Item::AddItem(Item* item)
{
        Item* ptr = this;
        if(ptr->ProductCode_ == ""){
                ptr->ProductCode_ = item->ProductCode_;
                ptr->amount_ = item->amount_;
                ptr->nextItem_ = new Item();
        }
        else{
        while (ptr->nextItem_)
        {
                ptr = ptr->nextItem_;
        }

        ptr->nextItem_ = item;
        }
}