#include "lab5.h"

int Floor[LENGTH][WIDTH][HEIGHT];
int TIME = 0;
int TimeSlice =0;
int NumOfRobots =0;
Shopper* Shopperlist[9];
//Scott Iwanicki
int main(int argc, char* argv[])
{
  //sets input values
  BinaryTree* RoboMall = new BinaryTree();
  TimeSlice = atoi(argv[1]);
  int i,j,k, stores[12], items, count, location;
  char item[2];
  int tempNumOfRobots =0;
  cin >> tempNumOfRobots; // in lab5
  NumOfRobots = tempNumOfRobots;
  int xpos=0, ypos=0, zpos=0, ts = 0;
  for (i = 0; i < NumOfRobots; i++)
    {
      cin >> stores[i];
      //cout<< "Number of Stores" << stores[i] <<endl;
    }
  for(i = 0; i<NumOfRobots; i++){
    Shopper* newshopper = new Shopper(i+1);
    for (j = 0; j < stores[j]; j++)
      {
	cin >> xpos >> ypos >> zpos >> items;
	//cout <<xpos << " " <<ypos <<" " <<zpos <<endl;
	Store* store = new Store();//create a store
	store->xstore_ = xpos;	// sets the location
	store->ystore_ = ypos;
	store->zstore_ = zpos;
	store->TimeSlice_ = 0;	//sets the timeslice
	newshopper->smove_->AddStore(store);//Add the store to the shopper's storelist
	for(k =0; k < items; k++){
	  
	  cin >>item  >>count;
	  Item* newitem = new Item();
	  newitem->ProductCode_ = item;
	  newitem->amount_ = count;
	  store->items_->AddItem(newitem);
	  //cout <<"Item " <<item <<"Count " <<count <<endl;
	  
	}
	
	//cout <<"Store Coords:" << newshopper->smove_->storelist_->xstore_ <<endl;
      }
    cout<<i<<endl;
    newshopper->smove_->wait_ = i*25;
    Shopperlist[i] = newshopper;	//add a shopper
  }
  //shopper moves to each store and enters the RRqueue to be serviced
  while(NumOfRobots !=0){
    for(i=0; i<9; i++){
      if(Shopperlist[i]!=NULL){
	if(Shopperlist[i]->smove_->wait_ <=TIME){
		if(Shopperlist[i]->smove_->wait_ % 25 ==0 && TIME % 25 ==0){
		  cout<<"Robot "<<Shopperlist[i]->RobotNum_ 
		      <<" enters the simulation at time " <<TIME <<endl;
		      Shopperlist[i]->smove_->wait_=1;
		}
	  /*cout <<"Robot: "<< Shopperlist[i]->RobotNum_<< endl
	       << "Pos: "<<Shopperlist[i]->smove_->xpos_ <<" " 
	       <<Shopperlist[i]->smove_->ypos_ <<" "<< Shopperlist[i]->smove_->zpos_ << endl;
	  cout <<"Store:" <<Shopperlist[i]->smove_->storelist_->xstore_ 
	       << " " <<Shopperlist[i]->smove_->storelist_->ystore_ << " " 
	       <<Shopperlist[i]->smove_->storelist_->zstore_ << endl;
	  */
	  //if the robot isn't at a store
	  if(Shopperlist[i]->smove_->xpos_ != Shopperlist[i]->smove_->storelist_->xstore_ || 
	     Shopperlist[i]->smove_->ypos_ != Shopperlist[i]->smove_->storelist_->ystore_ ||
	     Shopperlist[i]->smove_->zpos_ != Shopperlist[i]->smove_->storelist_->zstore_)
	  {
	    Shopperlist[i]->smove_->BotMove(Shopperlist[i]->RobotNum_);
	  }
	  //if the robot is at a "store"
	  else{
	  	//if the store is A1, remove the robot from the simulation
	    if(Shopperlist[i]->smove_->storelist_->xstore_ == 8 && 
	       Shopperlist[i]->smove_->storelist_->ystore_ == 16 && 
	       Shopperlist[i]->smove_->storelist_->zstore_ == 0)
	    {
	      Shopperlist[i]->smove_->movement(End, Shopperlist[i]->RobotNum_);
	      Shopperlist[i] = NULL;
	      //decriments the number of robots in the simulation
	      NumOfRobots--;
	    }
	    //if the robot is at a store
	    else{
	      cout<<"Robot " <<Shopperlist[i]->RobotNum_<<" arrives at store("
	          << Shopperlist[i]->smove_->storelist_->xstore_ << ", "
	          <<Shopperlist[i]->smove_->storelist_->ystore_ << ", " 
	          <<Shopperlist[i]->smove_->storelist_->zstore_ <<") at time "<< TIME <<endl;
	      //if the robot is out of items to add to the store, remove the store from the list of stores
	      if(Shopperlist[i]->smove_->storelist_->items_ == NULL){    
	         Shopperlist[i]->smove_->RemoveStore();
	      }
	      
	      else{
		RoboMall->AddItem(Shopperlist[i]->smove_->storelist_->items_ , Shopperlist[i]->smove_->_storelist_);
	      }
	      //if there are no more stores in the robots list
	      if(Shopperlist[i]->smove_->storelist_==NULL){
		//	cout<<"Storelist NULL"<<endl;
		Store* endStore = new Store();
		endStore->xstore_ = 8;
		endStore->ystore_ =16;
		endStore->zstore_ = 0;
		endStore->TimeSlice_ = 0;
		Shopperlist[i]->smove_->storelist_ = endStore;
		//	cout<<"Added Store"<<endl;
	      }
	    }
	  }
	}
      }
    }
    /*
    for(i=0; i<9; i++){
      if(Shopperlist[i]!=NULL){
	cout<<"Shopper" <<Shopperlist[i]->RobotNum_ << "  " <<Shopperlist[i]->smove_->xpos_ 
	    <<" " <<Shopperlist[i]->smove_->ypos_ <<" "<< Shopperlist[i]->smove_->zpos_ << endl;
      }
    }
    */
    timecheck();
    TIME++;
  }
  
  return 0;
}
