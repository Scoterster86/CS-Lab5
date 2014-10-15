#include "lab5.h"

//Yo Karita
//constructor for Store with a store as an input
Store::Store(Store* store)
{
        this->xstore_ = store->xstore_;
        this->ystore_ = store->ystore_;
        this->zstore_ = store->zstore_;
        this->productamount_ = store->productamount_;
        this->TimeSlice_ = store->TimeSlice_;
        this->items_= NULL;
        this->pNext = nullptr;
}
//Yo Karita
//constructor for a store
Store::Store()
{
        this->xstore_ = 0;
        this->ystore_ = 0;
        this->zstore_ = 0;
        this->TimeSlice_ = 0;
        this->productamount_ = 0;
        this->items_= NULL;
        this->pNext = nullptr;
}

Store::Store(int x, int y, int z)
{
        this->xstore_ = x;
        this->ystore_ = y;
        this->zstore_ = z;
        this->TimeSlice_ = 0;
        this->items_= new Item();
        this->pNext = nullptr;
}

//Yo Karita
//Adds a store to the list of stores
void Store::AddStorelist(Store* store)
{
        Store* ptr = this;

        while (ptr->pNext)
        {
                ptr = ptr->pNext;
        }
        ptr->pNext = store;
}

//Yo Karita
//adds a store to the list of stores
void Store::AddStore(Store* store, Store* head)
{
  //if the store location is (0,0,0) set the first store in the list
  if (this->xstore_ == 0 && this->xstore_ == 0 && this->zstore_ == 0)
    {
      this->xstore_ = store->xstore_;
      this->ystore_ = store->ystore_;
      this->zstore_ = store->zstore_;

      this->productamount_ += store->productamount_;

      head = store;
      return;
    }
 //sets the head pointer of the list to the first store in the list
  head = this;

  //sets the currento pointer to the first store in the list
  Store* pCurrent = this;

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
      pCurrent = pCurrent->pNext;
    }
  //if the store already exsists in the list
  if(pCurrent != NULL){
     if((pCurrent->xstore_ == store->xstore_) &&
        (pCurrent->ystore_ == store->ystore_)&&
        (pCurrent->zstore_ == store->zstore_))
       {
         //add the new product amount to the total product amount
         pCurrent->productamount_ += store->productamount_;
        return;
    }
  }
  //if the previous pointer isn't null instert the store between the previous and current store
  if (pPrev != NULL)
    {
      //set the previous store's next pointer to the store
      pPrev->pNext = store;
      //set the store's next pointer to the current store
      store->pNext = pCurrent;
    }
  //if the previous pointer is null
  else
    {
            cout<<"pPrev is null"<<endl;
      //set the store's next pointer as the previous head of the list
      store->pNext = this;
      //set the head pointer of the list to the store
      head = store;
    }
}

//Yo Karita
//Counts the number of stores in the list
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


//Yo Karita
//prints out the stores
void Store::PrintStores()
{
  //sets the current pointer to this
  Store* pCurrent = this;

  //while the current pointer isn't null
  while (pCurrent)
    {
      //print out the store location and the product amount
      cout << "(" << pCurrent->xstore_ << ", " << pCurrent->ystore_ << ", " <<\
 pCurrent->zstore_ << ")Total items: " << pCurrent->productamount_ << "   ";
      pCurrent = pCurrent->pNext;
    }
}


void Store::RemoveItem()
{
        this->items_= this->items_->nextItem_;
}

///Find the store which has most of an item
Store* Store::FindStore(BinaryTree tree)
{
	cout<<"in FindStore"<<endl;
	BinaryTree* currentp = &tree;
	if(tree.node_ != NULL){
	if (tree.node_->HasPriority(*(this->items_)) == 0)
	{
		cout<<"found item"<<endl;
		return tree.node_->pStore;
	}
	else if (tree.node_->HasPriority(*(this->items_)) == 1)
	{
		cout<<"left branch"<<endl;
		if(currentp->left_ != NULL)this->FindStore(*(currentp->left_));
		
	}
	else if(tree.node_->HasPriority(*(this->items_)) == -1)
	{
		cout<<"right branch"<<endl;
		if(currentp->right_ != NULL)this->FindStore(*(currentp->right_));
		
	}
	}
	else{
		cout<<"didn't find store"<<endl;
		return new Store();
	}
}
/*
void Store::addItem(Item* item){
	if(this->items_ ==NULL){
		this->items_=item;
	}
	else{
		Item* pCurrent = this->items_;
		Item* pNext = NULL;
		while(pCurrent &&)
		
	}
}
