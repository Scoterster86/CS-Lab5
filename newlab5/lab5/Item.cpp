#include "lab5.h"

//Scott Iwanicki
//default constructor for an item
Item::Item()
{
  this->ProductCode_ = "";
  this->amount_=0;
  this->nextItem_ = nullptr;
  this->pStore = new Store();
}

Item::Item(string productcode, int amount)
{
	this->ProductCode_ = productcode;
	this->amount_ = amount;
	this->nextItem_ = nullptr;
	this->pStore = new Store();
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
                ptr->nextItem_ = NULL;
        }
        else{
        while (ptr->nextItem_)
        {
                ptr = ptr->nextItem_;
        }

        ptr->nextItem_ = item;
        }
}

//prints items
void Item::PrintItems()
{
  //sets the current pointer to this
  Item* pCurrent = this;

  //while the current pointer isn't null
  while (pCurrent)
    {
      //print out the store location and the product amount
      cout << "(" << pCurrent->ProductCode_ << ", " << pCurrent->amount_ << ") ";
      pCurrent = pCurrent->nextItem_;
    }
}

void Item::AddStore(Store* store)
{
  //if the store location is (0,0,0) set the first store in the list
  if (this->pStore->xstore_ == 0 && this->pStore->xstore_ == 0 && this->pStore->zstore_ == 0)
    {
      this->pStore->xstore_ = store->xstore_;
      this->pStore->ystore_ = store->ystore_;
      this->pStore->zstore_ = store->zstore_;
	cout<<"Added to empty list"<<endl;
      this->pStore->productamount_ += store->productamount_;
      return;
    }
  //sets the currento pointer to the first store in the list
  Store* pCurrent = this->pStore;

  //sets the previous pointer to null
  Store* pPrev = nullptr;

  //loops until pCurrent is null or then the current product amount
  //is greater than the store's prodcut amount or if the stores are the same
  while (pCurrent && (pCurrent->productamount_ > store->productamount_) && (
        (pCurrent->xstore_ =! store->xstore_) ||
        (pCurrent->ystore_ =! store->ystore_)||
        (pCurrent->zstore_=! store->zstore_)) )
    {
      //sets the previous pointer to the current pointer
      pPrev = pCurrent;

      //sets the current pointer to the next store in the list
      pCurrent = pCurrent->pNext ;
    }
  //if the store already exsists in the list
  if(pCurrent != NULL){
     if((pCurrent->xstore_ == store->xstore_) &&
        (pCurrent->ystore_ == store->ystore_)&&
        (pCurrent->zstore_ == store->zstore_))
       {
       	cout<<"Add items to same store"<<endl;
         //add the new product amount to the total product amount
         pCurrent->productamount_ += store->productamount_;
        return;
    }
  }
  //if the previous pointer isn't null instert the store between the previous and current store
  if (pPrev != NULL)
    {
      //set the previous store's next pointer to the store
      pPrev->pNext  = store;
      //set the store's next pointer to the current store
      store->pNext  = pCurrent;
      cout<<"pPrev isn't null"<<endl;
    }
  else{
  	cout<<store->pNext->xstore_ <<endl;
  	store->pNext = this->pStore;
  	this->pStore=store;
  	cout<<"pPrev is null"<<endl;
  }  
}

