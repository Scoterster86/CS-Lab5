#include <iostream>
#include <list>
using namespace std;

#define nullptr NULL

list<Store> storelist;

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
	int xpos_, ypos_, zpos_;

	Shopper();
	void botmove(Store*);
	void AddShopper(Shopper*);
	void RemoveStore();
};