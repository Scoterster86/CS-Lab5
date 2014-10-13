#include "lab5.h"
BinaryTree::BinaryTree()
{
	this->node_ = Item();
	this->left_ = nullptr;
	this->right_ = nullptr;
}
BinaryTree::BinaryTree(Item item)
{
	this->node_ = item;
	this->left_ = nullptr;
	this->right_ = nullptr;
}
int Item::HasPriority(Item item)
{
	if (this->ProductCode_.compare(item.ProductCode_) == 0) return 0;
	else if (this->ProductCode_.compare(item.ProductCode_) > 0) return 1;
	else  return -1;
}

void BinaryTree::AddItem(Item* item, Store* store)
{

	/// if there is no items
	if (this->node_.ProductCode_ == "")
	{
		this->node_ = *item;
		this->node_.pStore = store;
		//this->node_.pStore->AddStore(store);
		return;
	}

	/// if node has same productcode
	if (this->node_.HasPriority(*item) == 0)
	{

		this->node_.pStore->AddStore(store);
		this->node_.pStore = headstoreptr;
	}
	/// if the node has higher priority, 
	else if (this->node_.HasPriority(*item) == 1)
	{
		if (this->left_) this->left_->AddItem(item, store);
		else
		{
			BinaryTree* newTree = new BinaryTree(*item);
			this->left_ = newTree;
			this->left_->node_.pStore = store;
			//this->left_->node_.pStore->AddStore(store);
		}

	}

	/// if the node has lower priority, 
	else if (this->node_.HasPriority(*item) == -1)
	{
		if (this->right_)this->right_->AddItem(item, store);
		else
		{
			BinaryTree* newTree = new BinaryTree(*item);
			this->right_ = newTree;
			this->right_->node_.pStore = store;
			//this->right_->node_.pStore->AddStore(store);
		}
	}
}

void Store::AddStore(Store* store)
{
	if (this->xstore_ == 0 && this->ystore_ == 0 && this->zstore_ == 0)
	{
		this->xstore_ = store->xstore_;
		this->ystore_ = store->ystore_;
		this->zstore_ = store->zstore_;

		this->ProductAmount_ += store->ProductAmount_;

		headstoreptr = store;
		return;
	}
	headstoreptr = this;

	Store* pCurrent = this;
	Store* pPrev = nullptr;
	while (pCurrent && (this->ProductAmount_ > store->ProductAmount_))
	{
		pPrev = pCurrent;
		pCurrent = pCurrent->pNext;
	}

	if (pPrev)
	{
		pPrev->pNext = store;
		store->pNext = pCurrent;
	}
	else
	{
		store->pNext = this;
		headstoreptr = store;
	}

	store->ProductAmount_ += store->ProductAmount_;
}

