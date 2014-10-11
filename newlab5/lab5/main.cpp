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
	int n, items;
	int tempNumOfShoppers =0;
	cin >> tempNumOfShoppers; // in lab5
	cin >> n;
	NumOfShoppers = tempNumOfShoppers;
	Shopper* shopper = new Shopper();
	int xpos=0, ypos=0, zpos=0, ts = 0;
	for (int i = 0; i < NumOfShoppers; i++)
	{
		Shopper* newshopper = new Shopper(++i);
			for (int i = 0; i < n; i++)
			{
		
				cout<<"in Store For Loop" <<endl;
				cin >> xpos >> ypos >> zpos >> ts;
				Store* store = new Store();		//create a store
				store->xstore_ = xpos;	// sets the location
				store->ystore_ = ypos;
				store->zstore_ = zpos;	
				store->TimeSlice_ = ts;	//sets the timeslice

				newshopper->smove_AddStore(store);	//Add the store to the shopper's storelist
			}
		shopper->AddShopper(newshopper);	//add a shopper
	}
	
	//shopper moves to each store and enters the RRqueue to be serviced
	while(NumOfShoppers !=0){
		cout <<shopper->smove_->xpos_ <<" " <<shopper->smove_->ypos_ <<" "<< shopper->smove_->zpos_ << endl;
		if(shopper->smove_->xpos_ != shopper->smove->storelist_->xstore_ || shopper->smove_->ypos_ != shopper->smove_->storelist_->ystore_
			|| shopper->smove_->zpos_ != shopper->smove->storelist_->zstore_){
				cout<<"Enter BotMove"<<endl;
				shopper->smove_->BotMove();
		}
		else{
			if(shopper->storelist_->xstore_ == 8 && shopper->storelist_->ystore_ == 16 && shopper->storelist_->zstore_ == 0){
				shopper->smove_->movement(End);
				NumOfShoppers--;
			}
			else{
				shopper->RemoveStore();
				cout<<"Removed Store-----------------------------"<<endl;
				if(shopper->storelist_==NULL){
					cout<<"Storelist NULL"<<endl;
					Store* endStore = new Store();
					endStore->xstore_ = 8;
					endStore->ystore_ =16;
					endStore->zstore_ = 0;
					endStore->TimeSlice_ = 0;
					shopper->smove->storelist_ = endStore;
					cout<<"Added Store"<<endl;
				}
			}
		}
		TIME++;
	}
	
	return 0;
}
