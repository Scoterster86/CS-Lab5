#include "lab5.h"

int Floor[LENGTH][WIDTH][HEIGHT];
int TIME = 0;
int TimeSlice =0;
int NumOfRobots =0;
int Debug = 1;
Shopper* Shopperlist[9];
Store* headstoreptr = NULL;
//Scott Iwanicki
int main(int argc, char* argv[])
{
  //sets input values
  int shop_time =0;
  TimeSlice = atoi(argv[1]);
  BinaryTree* RoboMall = new BinaryTree();
  //RoboMall->node_ = new Item();
  int i,j,k, stores[12], items, count,NumOfShoppers,numOfItems, arrival;
  string item;
  //cout<<endl;
  int tempNumOfRobots =0;
  cin >> tempNumOfRobots; // in lab5
  NumOfRobots = tempNumOfRobots;
  int xpos=0, ypos=0, zpos=0;
  for (i = 0; i < NumOfRobots; i++)
    {
      cin >> stores[i];
      //cout<< "Number of Stores" << stores[i] <<endl;
    }
  for(i = 0; i<NumOfRobots; i++){
    Shopper* newshopper = new Shopper(i+1);
    for (j = 0; j < stores[i]; j++)
      {
        cin >> xpos >> ypos >> zpos >> items;
        //cout <<xpos << " " <<ypos <<" " <<zpos <<endl;
        Store* store = new Store();//create a store
        store->xstore_ = xpos;  // sets the location
        store->ystore_ = ypos;
        store->zstore_ = zpos;
        store->items_ = new Item();
        store->TimeSlice_ = 0;  //sets the timeslice
        newshopper->smove_->AddStore(store);//Add the store to the shopper's storelist
        //cout<<"Added Store" <<endl;
        for(k =0; k < items; k++){

          cin >>item  >>count;
          Item* newitem = new Item();
          newitem->ProductCode_ = item;
          newitem->amount_ = count;
          newitem->nextItem_ = NULL;
          //cout<<"Add item" <<endl;
          store->items_->AddItem(newitem);
          //store->items_->PrintItems();
          //cout<<endl;
          //cout <<"Item " <<store->items_->ProductCode_ <<"Count " <<store->items_->amount_ <<endl;

        }

        //cout <<"Store Coords:" << newshopper->smove_->storelist_->xstore_ <<endl;
      }
    cout<<i<<endl;
    newshopper->smove_->wait_ = i*25;
    Shopperlist[i] = newshopper;        //add a shopper
  }
  //shopper moves to each store and enters the RRqueue to be serviced
  while(NumOfRobots !=0){
    for(i=0; i<9; i++){
      if(Shopperlist[i]!=NULL){
        if(Shopperlist[i]->smove_->wait_ <=TIME){
                if(Shopperlist[i]->smove_->wait_ % 25 ==0 && TIME % 25 ==0){
                  cout<<"Robot "<<Shopperlist[i]->RobotNum_
                      <<" enters the simulation at time " <<TIME <<endl;
                      Shopperlist[i]->smove_->wait_=-1;
                }
                /*
          cout <<"Robot: "<< Shopperlist[i]->RobotNum_<< endl
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
            //cout<<"Move"<<endl;
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
              if(Shopperlist[i]->enteredstore_ == 0){
                 cout<<"Robot " <<Shopperlist[i]->RobotNum_<<" arrives at store("
                    << Shopperlist[i]->smove_->storelist_->xstore_ << ", "
                    <<Shopperlist[i]->smove_->storelist_->ystore_ << ", "
                    <<Shopperlist[i]->smove_->storelist_->zstore_ <<") at time "<< TIME <<endl;
                    Shopperlist[i]->enteredstore_ = 1;
              }
              //if the robot is out of items to add to the store, remove the store from the list of stores
              if(Shopperlist[i]->smove_->storelist_->items_ == NULL){
                
                Shopperlist[i]->smove_->RemoveStore();
                Shopperlist[i]->enteredstore_ = 0;
              }

            else{
              //Shopperlist[i]->smove_->storelist_->items_->PrintItems();
              //cout<<endl;
             // Shopperlist[i]->smove_->storelist_->PrintStores();
              //cout<<endl;
              Store* treestore = new Store(Shopperlist[i]->smove_->storelist_);
              
                RoboMall->AddItem(Shopperlist[i]->smove_->storelist_->items_ ,treestore , headstoreptr);
                //RoboMall->PrintBinaryTree();
                Shopperlist[i]->smove_->storelist_->RemoveItem();
                //cout<<"end Print"<<endl;

              }
              //if there are no more stores in the robots list
              if(Shopperlist[i]->smove_->storelist_==NULL){
                //cout<<"Storelist NULL"<<endl;
                Store* endStore = new Store();
                endStore->xstore_ = 8;
                endStore->ystore_ =16;
                endStore->zstore_ = 0;
                endStore->TimeSlice_ = 0;
                Shopperlist[i]->smove_->storelist_ = endStore;
                //cout<<"Added Store"<<endl;
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
    //timecheck();
    TIME++;
  }
  //END ROBOT simulations
  //Begin Shopper simulation
	cout << "Begin Shoppers" << endl;
	Queue* Shoppers = new Queue;
	cin >> NumOfShoppers;
	for (i = 1; i <= NumOfShoppers; i++){
		Shopper* nextShopper = new Shopper(i);
		cin >> arrival >> numOfItems;
		//cout<<"adding arrival time"<<endl;
		nextShopper->smove_->delay_ = arrival;
		//cout<<"added arrival time"<<endl;
		//for every store
		for (j = 0; j<numOfItems; j++){
			//get the item id and the amount of that item
			cin >> item >> count;
			//make a new item
			Item* newitem = new Item();
			//set the item's values to the inserted values
			newitem->ProductCode_ = item;
			newitem->amount_ = count;
			newitem->itemsleft_= count;
			//cout<<"set item and count"<<endl;
			newitem->nextItem_ = NULL;
			//create a new store
			Store* newStore = new Store();
			//add the item to the new store
			newStore->items_ = newitem;
			//cout << "OKD" << endl;
			int *xs= new int;
			int *ys = new int;
			int *zs = new int;
			//finds the store with the most of the item added
			newStore->FindStore(*RoboMall, *xs, *ys, *zs);
			//cout<<"found store1" <<endl;
			//if a store containing the item was found
			if (*xs != -1){
				//cout<<"found a store"<<endl;
				//sets the new store's location to the store with the most items
				newStore->xstore_ = *xs;
				newStore->ystore_ = *ys;
				newStore->zstore_ = *zs;
				//cout << "Adding store" << endl;
				nextShopper->smove_->AddStore(newStore);//Add the store to the shopper's storelist
				/*
				Store* str = nextShopper->smove_->storelist_;
				 while(str){
				   str->items_->PrintItems();
				   str= str->pNext;
				 }*/
			}
		}
		Shoppers->AddShopper(nextShopper, 1);
		Shopper* ptr = Shoppers->listhead_;
		cout<<"while loop"<<endl;
		while(ptr){
		   cout<<ptr->RobotNum_ << endl;
		   cout<<"in while loop"<<endl;
		   
		   Store* std = ptr->smove_->storelist_;
		   while(std){
		      std->items_->PrintItems();
		      std= std->pNext;
		   }
		   ptr= ptr->nextshopper_;
		}

	}
	
	Store* StoreList = new Store();//create a store
        StoreList->xstore_ = 4;  // sets the location
        StoreList->ystore_ = 4;
        StoreList->zstore_ = 0;
        
	Store* store1 = new Store();//create a store
        store1->xstore_ = 6;  // sets the location
        store1->ystore_ = 4;
        store1->zstore_ = 0;
        StoreList->AddStorelist(store1);
        
	Store* store2 = new Store();//create a store
        store2->xstore_ = 10;  // sets the location
        store2->ystore_ = 4;
        store2->zstore_ = 0;
        StoreList->AddStorelist(store2);
        
        Store* store3 = new Store();//create a store
        store3->xstore_ = 12;  // sets the location
        store3->ystore_ = 4;
        store3->zstore_ = 0;
        StoreList->AddStorelist(store3);
        
        Store* store4 = new Store();//create a store
        store4->xstore_ = 4;  // sets the location
        store4->ystore_ = 6;
        store4->zstore_ = 0;
        StoreList->AddStorelist(store4);
        
        Store* store5 = new Store();//create a store
        store5->xstore_ = 12;  // sets the location
        store5->ystore_ = 6;
        store5->zstore_ = 0;
        StoreList->AddStorelist(store5);
        
        Store* store6 = new Store();//create a store
        store6->xstore_ = 4;  // sets the location
        store6->ystore_ = 10;
        store6->zstore_ = 0;
        StoreList->AddStorelist(store6);
        
        Store* store7 = new Store();//create a store
        store7->xstore_ = 12;  // sets the location
        store7->ystore_ = 10;
        store7->zstore_ = 0;
        StoreList->AddStorelist(store7);
        
        Store* store8 = new Store();//create a store
        store8->xstore_ = 4;  // sets the location
        store8->ystore_ = 12;
        store8->zstore_ = 0;
        StoreList->AddStorelist(store8);
        
        Store* store9 = new Store();//create a store
        store9->xstore_ = 6;  // sets the location
        store9->ystore_ = 12;
        store9->zstore_ = 0;
        StoreList->AddStorelist(store9);
        
        Store* store10 = new Store();//create a store
        store10->xstore_ = 10;  // sets the location
        store10->ystore_ = 12;
        store10->zstore_ = 0;
        StoreList->AddStorelist(store10);
        
        Store* store11 = new Store();//create a store
        store11->xstore_ = 12;  // sets the location
        store11->ystore_ = 12;
        store11->zstore_ = 0;
        StoreList->AddStorelist(store11);

	Store* store12 = new Store();//create a store
        store12->xstore_ = 4;  // sets the location
        store12->ystore_ = 4;
        store12->zstore_ = 1;
        StoreList->AddStorelist(store12);
        
	Store* store13 = new Store();//create a store
        store13->xstore_ = 6;  // sets the location
        store13->ystore_ = 4;
        store13->zstore_ = 1;
        StoreList->AddStorelist(store13);
        
	Store* store14 = new Store();//create a store
        store14->xstore_ = 10;  // sets the location
        store14->ystore_ = 4;
        store14->zstore_ = 1;
        StoreList->AddStorelist(store14);
        
        Store* store15 = new Store();//create a store
        store15->xstore_ = 12;  // sets the location
        store15->ystore_ = 4;
        store15->zstore_ = 1;
        StoreList->AddStorelist(store15);
        
        Store* store16 = new Store();//create a store
        store16->xstore_ = 4;  // sets the location
        store16->ystore_ = 6;
        store16->zstore_ = 1;
        StoreList->AddStorelist(store16);
        
        Store* store17 = new Store();//create a store
        store17->xstore_ = 12;  // sets the location
        store17->ystore_ = 6;
        store17->zstore_ = 1;
        StoreList->AddStorelist(store17);
        
        Store* store18 = new Store();//create a store
        store18->xstore_ = 4;  // sets the location
        store18->ystore_ = 10;
        store18->zstore_ = 1;
        StoreList->AddStorelist(store18);
        
        Store* store19 = new Store();//create a store
        store19->xstore_ = 12;  // sets the location
        store19->ystore_ = 10;
        store19->zstore_ = 1;
        StoreList->AddStorelist(store19);
        
        Store* store20 = new Store();//create a store
        store20->xstore_ = 4;  // sets the location
        store20->ystore_ = 12;
        store20->zstore_ = 1;
        StoreList->AddStorelist(store20);
        
        Store* store21 = new Store();//create a store
        store21->xstore_ = 6;  // sets the location
        store21->ystore_ = 12;
        store21->zstore_ = 1;
        StoreList->AddStorelist(store21);
        
        Store* store22 = new Store();//create a store
        store22->xstore_ = 10;  // sets the location
        store22->ystore_ = 12;
        store22->zstore_ = 1;
        StoreList->AddStorelist(store22);
        
        Store* store23 = new Store();//create a store
        store23->xstore_ = 12;  // sets the location
        store23->ystore_ = 12;
        store23->zstore_ = 1;
        StoreList->AddStorelist(store23);

	shop_time = 0;
	while (Shoppers){
		Shopper* currentShopperptr = Shoppers->listhead_;
		while (currentShopperptr){
			if (currentShopperptr->smove_->delay_ <= shop_time){
				if (currentShopperptr->smove_->delay_ == shop_time){
					cout << "Shopper " << currentShopperptr->RobotNum_
						<< " enters the simulation at time " << TIME << endl;
					currentShopperptr->smove_->delay_ = -1;
				}
				if(TIME>1200){
				cout <<"Shopper: "<< currentShopperptr->RobotNum_<< endl
               << "Pos: "<<currentShopperptr->smove_->xpos_ <<" "
               <<currentShopperptr->smove_->ypos_ <<" "<< currentShopperptr->smove_->zpos_ << endl;
          cout <<"Store:" <<currentShopperptr->smove_->storelist_->xstore_
               << " " <<currentShopperptr->smove_->storelist_->ystore_ << " "
               <<currentShopperptr->smove_->storelist_->zstore_ << endl;
				}
				if (currentShopperptr->smove_->xpos_ != currentShopperptr->smove_->storelist_->xstore_ ||
					currentShopperptr->smove_->ypos_ != currentShopperptr->smove_->storelist_->ystore_ ||
					currentShopperptr->smove_->zpos_ != currentShopperptr->smove_->storelist_->zstore_)
				{
					//cout<<"Move"<<endl;
					currentShopperptr->smove_->BotMove(currentShopperptr->RobotNum_);
				}
				//if the shopper is at a "store"
				else{
					cout<<"At a store"<<endl;
					//if the store is A1, remove the shopper from the simulation
					if (currentShopperptr->smove_->storelist_->xstore_ == 8 &&
						currentShopperptr->smove_->storelist_->ystore_ == 16 &&
						currentShopperptr->smove_->storelist_->zstore_ == 0)
					{
						currentShopperptr->smove_->movement(End, currentShopperptr->RobotNum_);
						currentShopperptr = Shoppers->RemoveShopper(currentShopperptr);
					}
					//if the robot is at a store
					else{
						cout<<"At a store2"<<endl;
						if (currentShopperptr->enteredstore_ == 0){
							cout << "Shopper " << currentShopperptr->RobotNum_ << " arrives at store("
								<< currentShopperptr->smove_->storelist_->xstore_ << ", "
								<< currentShopperptr->smove_->storelist_->ystore_ << ", "
								<< currentShopperptr->smove_->storelist_->zstore_ << ") at time " << TIME << endl;
							currentShopperptr->enteredstore_ = 1;
						}
						//if the shopper is out of items to remove from the store, remove the store from the list of stores
						if (currentShopperptr->smove_->storelist_->items_ == NULL){
							currentShopperptr->smove_->RemoveStore();
							currentShopperptr->enteredstore_ = 0;
						}
						else{
							//find the store that the shopper is at
							//if(Debug)cout<<"find store"<<endl;
							Store* currentStore = currentShopperptr->smove_->storelist_->FindStore(StoreList);
							//if the shopper is already in the queue
							if(currentShopperptr->smove_->storelist_->FindStore(StoreList)->ShopperinQueue(currentShopperptr)){
								//if the shopper is at the head of the store
								if(Debug)cout<<"shopper in queue"<<endl <<currentStore->storequeue->listhead_->RobotNum_<<endl;
								if(currentShopperptr->RobotNum_  == currentStore->storequeue->listhead_->RobotNum_ ){
									currentStore->storequeue->RunQueue();
								}
								if(currentStore->storequeue->listhead_ != NULL){
								if(currentStore->storequeue->listhead_->smove_->xpos_ != currentStore->xstore_ ||
								  currentStore->storequeue->listhead_->smove_->ypos_ != currentStore->ystore_ ||
								  currentStore->storequeue->listhead_->smove_->zpos_ != currentStore->zstore_ ){
								  	cout<<"REMOVE HEAD SHOPPER NEW HEAD "<<currentStore->storequeue->listhead_->nextInQueue_->RobotNum_<<endl;
								  	currentStore->storequeue->listhead_ = NULL;
								  }
								}
							}
							else{
								//if(Debug)cout<<"shopper not in queue"<<endl;
								//add the shopper to the queue
								currentStore->storequeue->AddShopper(currentShopperptr);
								if(Debug){cout<<"added shopper"<< " Head of list: "<<currentStore->storequeue->listhead_->RobotNum_
											<<" "<<currentStore->storequeue->listhead_->smove_->xpos_
											<<" "<<currentStore->storequeue->listhead_->smove_->ypos_
											<<" "<<currentStore->storequeue->listhead_->smove_->zpos_<<endl;
								}
								
								if(currentStore->storequeue->listhead_->smove_->xpos_ != currentStore->xstore_ ||
								  currentStore->storequeue->listhead_->smove_->ypos_ != currentStore->ystore_ ||
								  currentStore->storequeue->listhead_->smove_->zpos_ != currentStore->zstore_ ){
								  	cout<<"REMOVE HEAD SHOPPER NEW HEAD "<<currentStore->storequeue->listhead_->nextInQueue_->RobotNum_<<endl;
								  	currentStore->storequeue->listhead_ = NULL;
								  }
								//if the shopper is at the head of the store
								else if(currentShopperptr->RobotNum_  == currentStore->storequeue->listhead_->RobotNum_ ){
									if(currentShopperptr->smove_->storelist_->zstore_ == 1){
										currentStore->storequeue->RunQueue();
									}
								}
							}
						}
						//if there are no more stores in the robots list
						if (currentShopperptr->smove_->storelist_ == NULL || currentShopperptr->smove_->storelist_->xstore_ == 0){
							//cout<<"Storelist NULL"<<endl;
							Store* endStore = new Store();
							endStore->xstore_ = 8;
							endStore->ystore_ = 16;
							endStore->zstore_ = 0;
							endStore->TimeSlice_ = 0;
							currentShopperptr->smove_->storelist_ = endStore;
							//cout<<"Added Store"<<endl;
						}
					}
				}
			}
	   	   if(currentShopperptr !=NULL){
		      currentShopperptr = currentShopperptr->nextshopper_;
		   }
		}
		shop_time++;
		TIME++;
	}
	return 0;
}
