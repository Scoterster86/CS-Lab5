#include "lab5.h"

int Floor[LENGTH][WIDTH][HEIGHT];
int TIME = 0;
int TimeSlice =0;
int NumOfRobots =0;
//Scott Iwanicki
int main(int argc, char* argv[])
{
	//sets input values
	TimeSlice = atoi(argv[1]);
	int i,j,n, stores[12], items, item, count;
	int tempNumOfRobots =0;
	cin >> tempNumOfRobots; // in lab5
	NumOfRobots = tempNumOfRobots;
	Shopper* shopper = new Shopper();
	int xpos=0, ypos=0, zpos=0, ts = 0;
	for (i = 0; i < NumOfRobots; i++)
	{
		cin >> stores[i];
	}
	for(i = 0; i<NumOfRobots; i++){
		Shopper* newshopper = new Shopper(++i);
		for (j = 0; j < n; j++)
		{
			cin >> xpos >> ypos >> zpos >> items;
			Store* store = new Store();//create a store
			Move* move = new Move();
			store->xstore_ = xpos;	// sets the location
			store->ystore_ = ypos;
			store->zstore_ = zpos;
			store->TimeSlice_ = 0;	//sets the timeslice
			for(k =0; k < items; k++){
				
				cin >>item >>count;

			}
			newshopper->smove_->AddStore(store);//Add the store to the shopper's storelist
		}
		shopper->AddShopper(newshopper);	//add a shopper
	}
	
	//shopper moves to each store and enters the RRqueue to be serviced
	while(NumOfRobots !=0){
		cout <<shopper->smove_->xpos_ <<" " <<shopper->smove_->ypos_ <<" "<< shopper->smove_->zpos_ << endl;
		if(shopper->smove_->xpos_ != shopper->smove_->storelist_->xstore_ || shopper->smove_->ypos_ != shopper->smove_->storelist_->ystore_
			|| shopper->smove_->zpos_ != shopper->smove_->storelist_->zstore_){
				cout<<"Enter BotMove"<<endl;
				shopper->smove_->BotMove(shopper->RobotNum_);
		}
		else{
			if(shopper->smove_->storelist_->xstore_ == 8 && shopper->smove_->storelist_->ystore_ == 16 && shopper->smove_->storelist_->zstore_ == 0){
				shopper->smove_->movement(End, shopper->RobotNum_);
				shopper->RemoveShopper(shopper);
				NumOfRobots--;
			}
			else{
				shopper->smove_->RemoveStore();
				cout<<"Removed Store-----------------------------"<<endl;
				if(shopper->smove_->storelist_==NULL){
					cout<<"Storelist NULL"<<endl;
					Store* endStore = new Store();
					endStore->xstore_ = 8;
					endStore->ystore_ =16;
					endStore->zstore_ = 0;
					endStore->TimeSlice_ = 0;
					shopper->smove_->storelist_ = endStore;
					cout<<"Added Store"<<endl;
				}
			}
		}
		TIME++;
	}
	
	return 0;
}
