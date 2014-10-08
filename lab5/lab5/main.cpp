#include "lab5.h"



int main(int argc, char* argv[])
{
	int n = atoi(argv[1]);
	TimeSlice = atoi(argv[2]);

	Shopper* shopper = new Shopper();	//create a shopper

	int xpos=0, ypos=0, zpos=1, t = 0;

	for(int i = 0; i < n ; i++)
	{
		cin >> xpos, ypos, t;
		Store* store = new Store();		//create a store
		store->xstore_ = xpos;	// sets the location
		store->ystore_ = ypos;
		store->zstore_ = 1;	//sets 1 for lab5
		store->TimeSlice_ = t;	//sets the timeslice

		shopper->AddStore(store);	//Add the store to the shopper's storelist
	}

	shopper->BotMove();
	return 0;
}
