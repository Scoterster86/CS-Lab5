#ifndef LAB5_H
#define LAB5_H
#include <iostream>

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
enum direction { North, NorthWest, West, SouthWest, South, SouthEast, East, NorthEast, Up, Down, End };

class Store;
//Yo Karita
//class for the items
class Item
{
 public:
  //the item's product code
  string ProductCode_;
  int amount_;
  Item* nextItem_;
  //pointer to the list of stores with the item inside
  Store* pStore;

  //determines the location of the item in a binary tree
  int HasPriority(Item);
  void AddItem(Item*);
  Item();
};

//Yo Karita
//Store class
class Store
{
public:
	int xstore_, ystore_, zstore_;
	Item* items_;
	Store* pNext;
	int TimeSlice_;

	void AddStore(Store*);
	int GetSize();
	Store();
	Store(Store*);
	Store(int, int ,int);
};

class Move
{
public:
	int xpos_, ypos_, zpos_, wait_;
	Store* storelist_;
	
	Move();
	void AddStore(Store* store);
	void RemoveStore();
	void BotMove(int);
	int movement(int, int);
	
};
//Scott Iwanicki
//Shopper class
class Shopper
{
public:

	int RobotNum_;
	int slices;
	Shopper* nextshopper_;
	Move* smove_;
	
	Shopper();
	Shopper(int);


	int storecomplete();
	void AddShopper(Shopper*);
	void RemoveShopper(Shopper*);

};

//Scott Iwanicki
//RRqueue class
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

//Scott Iwanicki
//binary tree class
class BinaryTree
{
  //an item as the node of the tree
  Item node_;
  //pointer to the left branch of the tree
  BinaryTree* left_;
  //pointer to the right branch of the tree
  BinaryTree* right_;

 public:
  //adds an item to the binary tree
  void AddItem(Item*, Store*);
  //prints the binary tree
  void PrintBinaryTree();
  //adds an item to the left branch of the binary tree
  void AddLeft(Item);
  //adds an item to the right branch of the binary tree
  void AddRight(Item);
  //default constructor for the binary tree
  BinaryTree();
  //deafault constructor for the binary tree with an item to be inserted
  BinaryTree(Item);
};



//checks to see if the time is divisible by 25
int timecheck();
#endif
