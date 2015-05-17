#include <stdlib.h>
#include <stdio.h>
#include "Maze2.c"
#include "Stack.c"
#include "Queue.c"

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
	northcell->floodval = 9;
	Node * southcell = new_Node(2,2);
	southcell->floodval = 7;
	Node * eastcell = new_Node(3,1);
	eastcell->floodval = 5;
	Node * westcell = new_Node(1,1);
	westcell->floodval = 10;

	newNode->up = northcell;
	newNode->left = westcell;
	set_wall(newNode,EAST);
	newNode->down = southcell;

	short smallval = get_smallest_neighbor(newNode);

	if(smallval == 7)
		printf("%s\n", "get_smallest_neighbor: PASSED");
	else{
		printf("%s,%d\n", "get_smallest_neighbor: FAILED",smallval);
	}

	//test maze constructor
	printf("%s\n","testing maze construction" );
	Maze * themaze = new_Maze();
	print_map(themaze);

	Node * threefour = themaze->map[3][4];
	printf("%s\n", "neighbors of cell:" );
	printf("%d,%d\n", threefour->column, threefour->row);

	printf("north: %d,%d\n", threefour->up->column, threefour->up->row );
	printf("south: %d,%d\n", threefour->down->column, threefour->down->row );
	printf("east: %d,%d\n", threefour->right->column, threefour->right->row );
	printf("west: %d,%d\n", threefour->left->column, threefour->left->row );

	Node * zerofifteen = themaze->map[0][15];
	printf("%s\n", "neighbors of cell 0,15:" );
	if(zerofifteen->up != NULL)
		printf("north: %d,%d\n", zerofifteen->up->column, zerofifteen->up->row );
	if(zerofifteen->down != NULL)
		printf("south: %d,%d\n", zerofifteen->down->column, zerofifteen->down->row );
	if(zerofifteen->right != NULL)
		printf("east: %d,%d\n", zerofifteen->right->column, zerofifteen->right->row );
	if(zerofifteen->left != NULL)
		printf("west: %d,%d\n", zerofifteen->left->column, zerofifteen->left->row );

	//testing arvind's stack.
	Stack * thestack = new_Stack();
	if(is_empty_Stack(thestack)){
		printf("\n\n%s\n", "stack is empty.");
	}
	push(thestack,threefour);
	push(thestack,zerofifteen);
	if(!is_empty_Stack(thestack)){
		printf("%s\n", "stack is not empty.");
	}
	printf("%s", "top of stack is...");
	Node * temp;
	pop(thestack, &temp);
	printf("%d,%d\n", temp->column, temp->row);

	printf("%s", "top of stack is...");
	pop(thestack, &temp);
	printf("%d,%d\n", temp->column, temp->row);
	if(is_empty_Stack(thestack))
		printf("%s\n", "stack is empty.");

	//testing that floodfill is working.
	printf("%s\n", "testing flodfill with deadend at 3,14" );
	Node * zerofourteen = themaze->map[0][14];
	Node * onefourteen = themaze->map[1][14];
	Node * twofourteen = themaze->map[2][14];
	Node * threefourteen = themaze->map[3][14];
	set_wall(zerofourteen,NORTH);
	set_wall(onefourteen,NORTH);

	set_wall(twofourteen,NORTH);
	set_wall(twofourteen,SOUTH);

	set_wall(threefourteen,NORTH);
	set_wall(threefourteen,EAST);
	set_wall(threefourteen,SOUTH);

	push(thestack,threefourteen);

	printf("%s\n", "current walls:" );
	printf("\n%s\n", "neighbors of cell:" );
	printf("%d,%d\n", zerofourteen->column, zerofourteen->row);
	if(zerofourteen->up != NULL)
		printf("\n%s\n", "north neighbor" );
	if(zerofourteen->down != NULL)
		printf("\n%s\n", "south neighbor" );
	if(zerofourteen->right != NULL)
		printf("\n%s\n", "east neighbor" );
	if(zerofourteen->left != NULL)
		printf("\n%s\n", "west neighbor" );

	printf("\n%s\n", "neighbors of cell:" );
	printf("%d,%d\n", onefourteen->column, onefourteen->row);
	if(onefourteen->up != NULL)
		printf("\n%s\n", "north neighbor" );
	if(onefourteen->down != NULL)
		printf("\n%s\n", "south neighbor" );
	if(onefourteen->right != NULL)
		printf("\n%s\n", "east neighbor" );
	if(onefourteen->left != NULL)
		printf("\n%s\n", "west neighbor" );

	printf("\n%s\n", "neighbors of cell:" );
	printf("%d,%d\n", twofourteen->column, twofourteen->row);
	if(twofourteen->up != NULL)
		printf("\n%s\n", "north neighbor" );
	if(twofourteen->down != NULL)
		printf("\n%s\n", "south neighbor" );
	if(twofourteen->right != NULL)
		printf("\n%s\n", "east neighbor" );
	if(twofourteen->left != NULL)
		printf("\n%s\n", "west neighbor" );

	printf("\n%s\n", "neighbors of cell:" );
	printf("%d,%d\n", threefourteen->column, threefourteen->row);
	if(threefourteen->up != NULL)
		printf("\n%s\n", "north neighbor" );
	if(threefourteen->down != NULL)
		printf("\n%s\n", "south neighbor" );
	if(threefourteen->right != NULL)
		printf("\n%s\n", "east neighbor" );
	if(threefourteen->left != NULL)
		printf("\n%s\n", "west neighbor" );




	floodfill(thestack);
	print_map(themaze);

	Node * tenthree = themaze->map[10][3];
	short foo = get_smallest_neighbor_dir(tenthree, WEST); 
	printf("Preferred direction with no walls %d", foo); 
	set_wall(tenthree, WEST); 
	short fu = get_smallest_neighbor_dir(tenthree, WEST); 
	printf("new pref dir %d", fu); 

	//test queue
	printf("%s\n", "testing queue");
	Queue * speedqueue = new_Queue();
	if(is_empty_Queue(speedqueue))
		printf("%s\n", "queue is empty");
	Qpush(speedqueue, (short)NORTH);
	Qpush(speedqueue, (short)SOUTH);
	if(!is_empty_Queue(speedqueue))
		printf("%s\n", "queue is not empty");
	printf("%s", "top of queue is..." );
	printf("%hu\n", Qpop(speedqueue));
	printf("%s", "top of queue is..." );
	printf("%hu\n", Qpop(speedqueue));

	if(is_empty_Queue(speedqueue))
		printf("%s\n", "queue is empty");
	Qpush(speedqueue, EAST);
	if(!is_empty_Queue(speedqueue))
		printf("%s\n", "queue is not empty");
	printf("%s", "top of queue is..." );
	printf("%hu\n", Qpop(speedqueue));


	


}