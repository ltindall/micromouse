#include <stdlib.h>
#include <stdio.h>
//#include "Maze2.h"



// Queue Constructor
Queue* new_Queue() {

  Queue * this_queue = (Queue *) malloc(sizeof(Queue));
  this_queue->size = 0;
  this_queue->position = 0;

  return this_queue;
}



// Checks if this_stack is empty
int is_empty_Queue (Queue * this_queue) {


  if (this_queue->size == 0)
    return 1;
  else return 0;
}

// Pops the top element of this_stack
short Qpop (Queue * this_queue) {

  short direction = this_queue->directions[this_queue->position];
  (this_queue->position)++;
  (this_queue->size)--;

  return direction;
}

// Pushes an element to the top of this_stack
void Qpush (Queue * this_queue, short newDirection) {

  this_queue->directions[ (this_queue->position) + (this_queue->size) ] = newDirection;
  (this_queue->size)++;
}



