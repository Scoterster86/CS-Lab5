#ifndef LAB5_H
#define LAB5_H
#include <iostream>
#include <string>


using namespace std;
//define global variables
#define nullptr NULL
#define LENGTH 17
#define WIDTH 17
#define HEIGHT 2
extern int TimeSlice;
extern int TIME;
extern int Floor[LENGTH][WIDTH][HEIGHT];
extern int NumOfRobots;
class BinaryTree;
class Queue;
class RRqueue;
class Shopper;
extern  BinaryTree* RoboMall;

enum direction { North, NorthWest, West, SouthWest, South, SouthEast, East, NorthEast, Up, Down, End };

class Store;
extern Store* headstoreptr;
//Yo Karita
//class for the items
class Item
{
 public:
  //the item's product code
  string ProductCode_;
  int amount_;
  int itemsleft_;
  Item* nextItem_;
  RRqueue* rrqueue;
  Queue* queue;
  //pointer to the list of stores with the item inside
  Store* pStore;

  //determines the location of the item in a binary tree
  int HasPriority(Item);
  void AddItem(Item*);
  void AddStore(Store*);
  void PrintItems();
  void RemoveStore();
  
  Item();
  Item(string, int);
};

class ItemList
{
public:
	Item* item_;
	ItemList* nextitem_;
};
//Yo Karita
//Store class
class Store
{
public:
        int xstore_, ystore_, zstore_;
        Item* items_;
        int productamount_;
        Store* pNext;
        int TimeSlice_;
        Queue* queue_;
	Queue* endQueue_;
	RRqueue* rrqueue;
        Queue* storequeue;

        void AddStorelist(Store*);
        void AddStore(Store*, Store*);
        Store* FindStore(BinaryTree, int &, int &, int &);
        Store* FindStore(Store*);
	int ShopperinQueue(Shopper*);
        int GetSize();
        void PrintStores();
        void RemoveItem();
        Store();
        Store(Store*);
        Store(int, int ,int);

};

class Move
{
public:
        int xpos_, ypos_, zpos_, wait_, delay_;
        Store* storelist_;

        Move();
        void AddStore(Store*);
        void AddStoreShopper(Store*);
        void RemoveStore();
        void BotMove(int);
        int movement(int, int);

};


//Scott Iwanicki
//binary tree class
class BinaryTree
{
public:
  //an item as the node of the tree
  Item* node_;
  //pointer to the left branch of the tree
  BinaryTree* left_;
  //pointer to the right branch of the tree
  BinaryTree* right_;


  //adds an item to the binary tree
  void AddItem(Item*, Store*, Store*);
  //prints the binary tree
  void PrintBinaryTree();
  //default constructor for the binary tree
  BinaryTree();
  //deafault constructor for the binary tree with an item to be inserted
  BinaryTree(Item*);
};
//Scott Iwanicki
//Shopper class
class Shopper
{
public:

	int RobotNum_;
	int slices;
	Shopper* nextshopper_;
	Shopper* nextInQueue_;
	Move* smove_;
	ItemList* itemlist_;
	int enteredstore_;

	Shopper();
	Shopper(int);

	int storecomplete();
	void AddShopper(Shopper*);
	void RemoveShopper(Shopper*);
	
	//void AddStore(BinaryTree*);
	void AddItem(string, int);
};
//Scott Iwanicki
//UNSUED class
class RRqueue
{
public:
	Shopper* listhead_;
	Shopper* listtail_;

	RRqueue();
	RRqueue(Shopper*);
	void RunQueue();
	void AddShopper(Shopper*);
	void RemoveShopper();
};


class Queue
{
public:
	Shopper* listhead_;
	Shopper* listtail_;

	Queue();
	void RunQueue();
	void RemoveShopper();
	Shopper* RemoveShopper(Shopper*);
	void AddShopper(Shopper*, int);
	void AddShopper(Shopper*);
};


//checks to see if the time is divisible by 25
int timecheck();

#endif

