#include "lab5.h"


Shopper::Shopper()
{
	this->RobotNum_ = 0;
	this->xpos_ = 0;
	this->ypos_ = 0;
	this->zpos_ = 0;
	this->storelist_ = new Store();
	this->slices = 0;
	this->nextshopper_ = nullptr;
}

Shopper::Shopper(int k)	//constructor with robotnumber value
{
	this->RobotNum_ = k;
	this->xpos_ = 0;
	this->ypos_ = 0;
	this->zpos_ = 0;
	this->storelist_ = new Store();
	this->slices = 0;
	this->nextshopper_ = nullptr;
}

void Shopper::AddStore(Store* store)
{
	if (this->storelist_->xstore_ == 0 && this->storelist_->ystore_ == 0 && this->storelist_->zstore_ == 0)this->storelist_ = store;	//if the storelist is empty
	else this->storelist_->AddStore(store);	//if the list is not empty, call Store::Addstore(Store)
}

void Shopper::RemoveStore()
{
	this->storelist_ = this->storelist_->pNext;	//change the pointer
}


//Scott Iwanicki
//runs when a shopper reaches a store
int Shopper::storecomplete(){
        int xpos = this->smove_->storelist_->xstore_;
        int ypos = this->smove_->storelist_->ystore_;
        int zpos = this->smove_->storelist_->zstore_;
        printf("Shopper %d arrives at store S(%d,%d) on the %d Floor at time %d\n", this->RobotNum_, xpos, ypos, (zpos + 1), TIME);
        //shopper enters round robin queue
        RRqueue* ptr = new RRqueue(this);
        //the shopper is processed at the round robin queue
        while(this->smove_->storelist_->TimeSlice_ != 0)
        {
                TIME+= (TimeSlice/10);
                ptr->RunQueue();
                timecheck();
        }
        //removes the store from the shopper's list of stores
        this->smove_->RemoveStore();
        return 0;
}



/// Add a shopper to the list
void Shopper::AddShopper(Shopper* shopper)
{
	if (this->RobotNum_ == 0)
	{
		///sets values if the list is empty
		this->RobotNum_ = shopper->RobotNum_;
		this->xpos_ = shopper->xpos_;
		this->ypos_ = shopper->ypos_;
		this->zpos_ = shopper->zpos_;
		this->storelist_ = new Store();
		this->nextshopper_ = nullptr;
	}
	else//find the end of the list and connect the new shopper
	{
		Shopper* ptr = this;
		while (ptr->nextshopper_ != nullptr)
		{
			ptr = ptr->nextshopper_;
		}
		ptr->nextshopper_ = shopper;
	}
	
}

void Shopper::RemoveShopper(Shopper* shopper)
{
	shopper= shopper->nextshopper_;
}

Store Shopper::FindStore(BinaryTree tree)
{
	BinaryTree* currentp = new BinaryTree();
	currentp = &tree;
	if (tree.node_.HasPriority(*(this->itemlist_)) == 0)
	{

		return *(tree.node_.pStore);
	}
	else if (tree.node_.HasPriority(*(this->itemlist_)) == 1)
	{ 
		this->FindStore(*(currentp->left_));
	}
	else
	{
		this->FindStore(*(currentp->right_));
	}
}

void Shopper::AddItem(string itemcode)
{
	Item* item = new Item(itemcode);

	ItemList* temp = this->itemlist_;
	while (temp)
	{
		temp = this->itemlist_->nextItem;
	}
	this->itemlist_->item = *item;
}
