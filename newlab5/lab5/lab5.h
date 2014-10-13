#include <iostream>

using namespace std;

#define nullptr NULL
#define LENGTH 17
#define WIDTH 17
#define HEIGHT 2

extern int TimeSlice;
extern int TIME;
extern int Floor[LENGTH][WIDTH][HEIGHT];
enum direction { North, NorthWest, West, SouthWest, South, SouthEast, East, NorthEast, Up, Down, 
	StNorth, StSouth, StEast, StWest, StNorthWest, StNorthEast, StSouthEast, 
	StSouthWest, NorthWest2, NorthEast2, SouthWest2, SouthEast2, End };
extern BinaryTree RoboMall;
Store* headstoreptr;
class Store
{
public:
	int xstore_, ystore_, zstore_;
	Store* pNext;
	int TimeSlice_;
	int ProductAmount_;

	void AddStore(Store*);
	int GetSize();
	Store();
	Store(Store*);
};


class Shopper
{
public:

	int RobotNum_;
	int xpos_, ypos_, zpos_;
	Store* storelist_;
	int slices;
	Shopper* nextshopper_;

	ItemList* itemlist_;

	Shopper();
	Shopper(int);

	void AddStore(Store*);
	void RemoveStore();
	void AddItem(string);

	int storecomplete();
	void BotMove();
	int movement(int);
	void AddShopper(Shopper*);
	void RemoveShopper(Shopper*);
	Store FindStore(BinaryTree);

};

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
int timecheck();

class Item
{
public:
	string ProductCode_;
	Store* pStore;
	int HasPriority(Item);
	Item();
	Item(string);
};

class ItemList
{
public:
	Item item;
	ItemList* nextItem;
};

class BinaryTree
{
public:
	Item node_;
	BinaryTree* left_;
	BinaryTree* right_;
	void AddItem(Item*, Store*);
	void PrintBinaryTree();
	void AddLeft(Item);
	void AddRight(Item);
	BinaryTree();
	BinaryTree(Item);
};
