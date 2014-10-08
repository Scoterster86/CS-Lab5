#include <iostream>
#include <list>
using namespace std;

#define nullptr NULL

int TimeSlice;
int TIME=0;

int Floor[16][16][2];
enum direction { North, NorthWest, West, SouthWest, South, SouthEast, East, NorthEast, Up, Down, 
	StNorth, StSouth, StEast, StWest, StNorthWest, StNorthEast, StSouthEast, 
	StSouthWest, NorthWest2, NorthEast2, SouthWest2, SouthEast2, End };

class Store
{
public:
	int xstore_, ystore_, zstore_;
	
	int TimeSlice_;

	Store();
	Store(Store*);
};

class Shopper
{
public:

	int RobotNum_;
	int xpos_, ypos_, zpos_;
	list<Store> storelist;

	Shopper();

	void AddStore(Store* store);
	void RemoveStore();
	void storecomplete();
	void BotMove();
	int movement(int);
	void AddShopper(Shopper*);
	void RemoveShopper();
};
