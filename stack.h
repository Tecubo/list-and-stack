#ifndef _STACK_H
#define _STACK_H 1

#include <stdio.h>
#include <stdlib.h>
#include <err.h>

typedef struct Stack Stack;
typedef struct Element Element;

struct Stack {
  Element *first;
};

struct Element {
  int value;
  Element *next;
};

Stack* stack_init();
void stack_push(Stack *stack, int value);
int stack_pop(Stack *stack);
void stack_free(Stack *stack);
void stack_print(Stack *stack);
int stack_get(Stack *stack, int index);

#endif