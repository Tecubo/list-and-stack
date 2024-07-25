#ifndef _QUEUE_H
#define _QUEUE_H 1

#include <stdio.h>
#include <stdlib.h>
#include <err.h>

typedef struct Queue Queue;
typedef struct Element Element;

struct Queue {
  Element *first;
};

struct Element {
  int value;
  Element *next;
};

#endif