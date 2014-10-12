#ifndef LAB5_H
#define LAB5_H
#include <iostream>

using namespace std;
//define global variables
#define nullptr NULL
#define LENGTH 17
#define WIDTH 17
#define HEIGHT 2
extern int TimeSlice;
extern int TIME;
extern int Floor[LENGTH][WIDTH][HEIGHT];
extern int NumOfRobots;
enum direction { North, NorthWest, West, SouthWest, South, SouthEast, East, NorthEast, Up, Down, End };


//Yo Karita
//Store class
class Store
{
public:
	int xstore_, ystore_, zstore_;
	Store* pNext;
	int TimeSlice_;

	void AddStore(Store*);
	int GetSize();
	Store();
	Store(Store*);
};

class Move
{
public:
	int xpos_, ypos_, zpos_, wait_;
	Store* storelist_;
	
	Move();
	void AddStore(Store* store);
	void RemoveStore();
	void BotMove(int);
	int movement(int, int);
	
};
//Scott Iwanicki
//Shopper class
class Shopper
{
public:

	int RobotNum_;
	int slices;
	Shopper* nextshopper_;
	Move* smove_;
	
	Shopper();
	Shopper(int);


	int storecomplete();
	void AddShopper(Shopper*);
	void RemoveShopper(Shopper*);

};

//Scott Iwanicki
//RRqueue class
class RRqueue
{
public:
	Shopper* listhead_;
	Shopper* listtail_;
	
	RRqueue();
	RRqueue(Shopper*);
	void RunQueue();
	void AddShopper(Shopper*);
	void RemoveShopper();
};


//checks to see if the time is divisible by 25
int timecheck();
#endif
