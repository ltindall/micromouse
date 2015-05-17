
#include <stdlib.h>
#include <stdio.h>
#include "Maze2.h"
#include <stack>

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