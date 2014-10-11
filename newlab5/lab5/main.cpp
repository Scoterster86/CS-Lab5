#include "lab5.h"

int Floor[LENGTH][WIDTH][HEIGHT];
int TIME = 0;
int TimeSlice =0;
int NumOfShoppers =0;
//Scott Iwanicki
int main(int argc, char* argv[])
{
	//sets input values
	TimeSlice = atoi(argv[1]);
	int n;
	int tempNumOfShoppers =0;
	cin >> tempNumOfShoppers; // in lab5
	cin >> n;
	NumOfShoppers = tempNumOfShoppers;
	Shopper* shopper = new Shopper();
	int xpos=0, ypos=0, zpos=1, ts = 0;
	for (int i = 0; i < NumOfShoppers; i++)
	{
		Shopper* newshopper = new Shopper(++i);
		shopper->AddShopper(newshopper);	//add a shopper
	}
	
	for (int i = 0; i < n; i++)
	{
		
		cout<<"in Store For Loop" <<endl;
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
		cout <<shopper->xpos_ <<" " <<shopper->ypos_ <<" "<< shopper->zpos_ << endl;
		if(shopper->xpos_ != shopper->storelist_->xstore_ || shopper->ypos_ != shopper->storelist_->ystore_
			|| shopper->zpos_ != shopper->storelist_->zstore_){
				cout<<"Enter BotMove"<<endl;
				shopper->BotMove();
		}
		else{
			cout<<"Remove Store"<<endl;
			shopper->RemoveStore();
			cout<<"Removed Store"<<endl;
			if(shopper->storelist_==NULL){
				cout<<"Storelist NULL"<<endl;
				Store* endStore = new Store();
				endstore->xstore_ = 8;
				endstore->ystore_ =16;
				endstore->zstore_ = 0;
				endstore->TimeSlice = 0;
				shopper->AddStore(endStore);
			}
		}
		TIME++;
	}
	
	return 0;
}
