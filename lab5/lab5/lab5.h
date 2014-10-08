#include <iostream>
#include <list>
using namespace std;

#define nullptr NULL

int TimeSlice;
int TIME=0;

int Floor[16][16][2];

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

	void BotMove();
	void AddShopper(Shopper*);
	void RemoveShopper();
};
