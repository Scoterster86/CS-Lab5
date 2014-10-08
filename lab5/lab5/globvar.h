#define LENGTH 17
#define WIDTH 17
#define HEIGHT 2
int TIME;
int floor[LENGTH][WIDTH][HEIGHT];
int bottimes[9][3];
enum direction {North, NorthWest, West, SouthWest,South, SouthEast, East, NorthEast, Up, Down,StNorth, StSouth, StEast,StWest, StNorthWest, StNorthEast,StSouthEast, StSouthWest, NorthWest2,NorthEast2, SouthWest2, SouthEast2, End};
int BOTNUM, xpos, ypos, zpos;
