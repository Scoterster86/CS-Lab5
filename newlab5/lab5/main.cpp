#include "lab5.h"

int Floor[LENGTH][WIDTH][HEIGHT];
int TIME = 0;
int TimeSlice = 1;
//Scott Iwanicki
int main(int argc, char* argv[])
{
	//sets input values
	int n = atoi(argv[1]);
	int tmpTimeSlice = atoi(argv[2]);
	TimeSlice = tmpTimeSlice;
	


	int NumOfShoppers = 1; // in lab5
	Shopper* shopper = new Shopper();
	int xpos=0, ypos=0, zpos=1, ts = 0;
	for (int i = 0; i < NumOfShoppers; i++)
	{
		Shopper* newshopper = new Shopper(++i);
		shopper->AddShopper(newshopper);	//add a shopper
	}
	
	for (int i = 0; i < n; i++)
	{

		cin >> xpos >> ypos >> ts;
		zpos=1;//sets 1 for lab5
		Store* store = new Store();		//create a store
		store->xstore_ = xpos;	// sets the location
		store->ystore_ = ypos;
		store->zstore_ = zpos;	
		store->TimeSlice_ = ts;	//sets the timeslice

		shopper->AddStore(store);	//Add the store to the shopper's storelist
	}
	//shopper moves to each store and enters the RRqueue to be serviced
	while(NumOfShoppers !=0){
		if(shopper->xpos_ != shopper->storelist_->xstore_ && shopper->ypos_ != shopper->storelist_->ystore_
			&& shopper->zpos_ != shopper->storelist_->zstore_){
				shopper->BotMove();
		}
		else{
			shopper->RemoveStore();
			if(shopper->nextshopper_==NULL){
				shopper->nextshopper_->
			}
		}	
	}
	
	return 0;
}
