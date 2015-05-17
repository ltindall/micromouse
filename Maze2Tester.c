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

	//test get_smallest_neighbor
	printf("\n\n%s", "testing get get_smallest_neighbor" );
	Node * northcell = new_Node(2,0);
	Node * southcell = new_Node(2,2);
	Node * eastcell = new_Node(3,1);
	Node * westcell = new_Node(1,1);

	newNode->up = northcell;
	newNode->left = westcell;
	set_wall(newNode,EAST);
	newNode->down = southcell;

	if(get_smallest_neighbor(newNode) == 7)
		printf("%s\n", "get_smallest_neighbor: PASSED");
	else
		printf("%s\n", "get_smallest_neighbor: FAILED");
}