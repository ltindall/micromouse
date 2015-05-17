// Constants

#ifndef Maze_h
#define Maze_h


#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

#define SIZE 16			// Size of one dimention of Map


// Directions
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3



// Solver Constants - will be used on mouse
#define START_X 15
#define START_Y 0
#define LARGEVAL 301



typedef struct Node { 

  /* data fields */
  short floodval;
  short row;
  short column;
  short visited;

  /* pointers to neighbors */
  struct Node * left;
  struct Node * right;
  struct Node * up;
  struct Node * down;

}
Node;

typedef struct Maze {

  Node * map [SIZE][SIZE];	

} 
Maze;



#endif


