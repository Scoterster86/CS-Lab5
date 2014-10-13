#include "lab5.h"
//Scott Iwanicki
//default constructor for a binary tree
BinaryTree::BinaryTree()
{
  this->node_ = Item();
  this->left_ = nullptr;
  this->right_ = nullptr;
}

//Scott Iwanicki
//default constructor for a binary tree with an item
BinaryTree::BinaryTree(Item item)
{
  this->node_ = item;
  this->left_ = nullptr;
  this->right_ = nullptr;
}


//Scott Iwanicki
//adds an item to the binary tree
void BinaryTree::AddItem(Item* item, Store* store, Store* head)
{

  /// if there is no items
  if (this->node_.ProductCode_ == "")
    {
      this->node_ = *item;
      this->node_.pStore = store;
      //this->node_.pStore->AddStore(store);
      return;
    }
  cout<<"BT line 34" <<endl;
  /// if node has same productcode
  if (this->node_.HasPriority(*item) == 0)
    {
    cout<<"BT line 38" <<endl;
      this->node_.pStore->AddStore(store, head);
      this->node_.pStore = head;
    }
    
  /// if the node has higher priority,
  else if (this->node_.HasPriority(*item) == 1)
    {
      if(this->left_) this->left_->AddItem(item, store, head);
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
      cout<<"BT line 60" <<endl;
      if (this->right_){
         this->right_->AddItem(item, store, head);   
      }
      else{
          BinaryTree* newTree = new BinaryTree(*item);
          this->right_ = newTree;
          this->right_->node_.pStore = store;
          //this->right_->node_.pStore->AddStore(store);
       }
    }
}

//Scott Iwanicki
//prints out the binary tree
void BinaryTree::PrintBinaryTree()
{
  //exits the function when this is NULL
  if (this == nullptr) return;

  //prints out the left branch of the binary tree
  this->left_->PrintBinaryTree();

  //prints out the current node
  cout << this->node_.ProductCode_ << ": ";

  //prints out the current node's list of stores
  this->node_.pStore->PrintStores();

  //prints out the right branch of the binary tree
  this->right_->PrintBinaryTree();
}

