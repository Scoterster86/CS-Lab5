#include "lab5.h"

int Floor[LENGTH][WIDTH][HEIGHT];
int TIME = 0;
int TimeSlice = 1;
int main(int argc, char* argv[])
{
	
	int n = atoi(argv[1]);
	int tmpTimeSlice = atoi(argv[2]);
	TimeSlice = tmpTimeSlice;
	


	int NumOfShoppers = 1; // number of robots is 1 in lab5
	Shopper* shopper = new Shopper();
	int xpos=0, ypos=0, zpos=1, ts = 0;// inputs of store posistion and time (z is always 1 in lab5)
	for (int i = 0; i < NumOfShoppers; i++)
	{
		Shopper* newshopper = new Shopper(++i);	//create a new shopper
		shopper->AddShopper(newshopper);	//add a shopper to the list
	}
	
	for (int i = 0; i < n; i++)
	{

		cin >> xpos >> ypos >> ts;	//get the store values
		zpos=1;//sets 1 for lab5
		Store* store = new Store();		//create a store
		store->xstore_ = xpos;	// sets the location
		store->ystore_ = ypos;
		store->zstore_ = zpos;	
		store->TimeSlice_ = ts;	//sets the timeslice

		shopper->AddStore(store);	//Add the store to the shopper's storelist
	}

	shopper->BotMove();	//moving the robot
	
	return 0;
}
