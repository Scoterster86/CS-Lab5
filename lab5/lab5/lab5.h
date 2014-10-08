#include <iostream>
#define nullptr NULL

class Store
{
public:
	int xstore_, ystore_, zstore_;
	Store* NextStore_;
	int TimeSlice_;

	Store();
	void AddStore(Store*);
	void RemoveStore();
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