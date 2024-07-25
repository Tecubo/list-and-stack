#include "queue.h"
#include "functions.h"

int main(int argc, char **argv)
{
  
  return 0;
}

Queue* queue_init()
{
  Queue *queue = malloc(sizeof(*queue));
  malloc_error(queue);
  queue->first = NULL;
  return queue;
}

void enqueue(Queue *queue, int value)
{
  
}