
#include <stdlib.h>
#include <stdio.h>
#include "Maze2.h"
//#include <stack>



/* Node Constructor */
Node * new_Node (short i, short j) {

  Node * this_node;
  short halfsize;

  this_node = (Node *) malloc(sizeof(Node));
  halfsize = SIZE / 2;

  this_node->column = i;
  this_node->row = j;
  this_node->visited = FALSE;

  /* Initializing the flood value at this coord
   	   NOTE : Right now this only works when SIZE is even -- which is ok */
  if (i < halfsize && j < halfsize)
    this_node->floodval = (halfsize - 1 - i) + (halfsize - 1 - j) ;

  else if (i < halfsize && j >= halfsize)
    this_node->floodval = (halfsize - 1 - i) + (j - halfsize) ;

  else if (i >= halfsize && j < halfsize)
    this_node->floodval = (i - halfsize) + (halfsize - 1 - j) ;

  else
    this_node->floodval = (i - halfsize) + (j - halfsize) ;

  return this_node;
}
/* Maze Constructor */
Maze * new_Maze () {

  Maze * this_maze;
  short x, y;

  this_maze = (Maze *) malloc(sizeof(Maze));

  /* Allocate a new Node for each coord of maze */
  for (x = 0; x < SIZE; ++x) 
    for (y = 0; y < SIZE; ++y) 
      this_maze->map[x][y] = new_Node (x, y);

  /* setting the neighbors ptrs... must be done after all cells allocated */
  for (x = 0; x < SIZE; x++)
    for (y = 0; y < SIZE; y++) {
      (this_maze->map[x][y])->left = (x == 0) ? NULL : (this_maze->map[x-1][y]);
      (this_maze->map[x][y])->right = (x == SIZE-1) ? NULL : (this_maze->map[x+1][y]);
      (this_maze->map[x][y])->up = (y == 0) ? NULL : (this_maze->map[x][y-1]);
      (this_maze->map[x][y])->down = (y == SIZE-1) ? NULL : (this_maze->map[x][y+1]);
    }

  return this_maze;
}

/* Function: print_map
   Description: prints the flood values of each cell in the maze */
void print_map (const Maze * this_maze) {

  short x, y;

  printf("\n%s\n\n", "CURRENT MAP VALUES: ");
  for (x = 0; x < SIZE; ++x) {
    for (y = 0; y < SIZE; ++y) {
      printf("%s%3hd", "  ", (this_maze->map[x][y])->floodval);
    } 
    printf("\n\n");
  }
  printf("\n");
}

/* Function: set walls of cell
   Description: given a cell, and given a direction of a wall in that cell
   				"set a wall" of that cell by removing pointers between the
   				two cells. 
*/
void set_wall(Node * cell, short walldirection)
{
	Node * neighbor;

	if(walldirection == NORTH && cell->up != NULL)
	{
		neighbor = cell->up;
		cell->up = NULL;
		neighbor->down = NULL;
	}
	else if(walldirection == SOUTH && cell->down != NULL)
	{
		neighbor = cell->down;
		cell->down = NULL;
		neighbor->up = NULL;
	}
	else if(walldirection == EAST && cell->right != NULL)
	{
		neighbor = cell->right;
		cell->right = NULL;
		neighbor->left = NULL;
	}
	else if(walldirection == WEST && cell->left != NULL)
	{
		neighbor = cell->left;
		cell->left = NULL;
		neighbor->right = NULL;
	}
}

short get_smallest_neighbor( Node * cell )
{

	short smallest = 999; 

	if( cell->left != NULL && cell->left->floodval < smallest)
		smallest = cell->left->floodval; 
	if( cell->right != NULL && cell->right->floodval < smallest)
		smallest = cell->right->floodval;
	if( cell->up != NULL && cell->up->floodval < smallest)
		smallest = cell->up->floodval; 
	if( cell->down != NULL && cell->down->floodval < smallest)
		smallest = cell->down->floodval;

	return smallest; 
}