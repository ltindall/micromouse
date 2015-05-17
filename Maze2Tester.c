#include <stdlib.h>
#include <stdio.h>
#include "Maze2.c"

int main( int argc, char * argv[])
{
	printf("testing node constructor\n");
	Node * newNode = new_Node(2,1);
	printf("new node created: \n");
	printf("new node row : ");
	printf("%d", newNode->row);
	printf(",%d\n", newNode->column);
	printf("%d\n", newNode->floodval);


	//test set_wall.
	Node * neighbor = new_Node(2,2);
	neighbor->up = newNode;
	newNode->down = neighbor;
	printf("created new south neighbor\n");
	if(newNode->down != NULL)
		printf("newNode has south neighbor\n");
	if(neighbor->up != NULL)
		printf("neighbor has north neighbor\n");
	set_wall(newNode, SOUTH);
	printf("south wall set for newNode\n");
	if(newNode->down == NULL)
		printf("newNOde has no south neighbor\n");
	if(neighbor->up == NULL)
		printf("neighbor has no north neighbor\n");

	
}