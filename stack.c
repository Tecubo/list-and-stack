#include "stack.h"
#include "functions.h"

int main(int argc, char **argv)
{
  Stack *stack = stack_init();
  stack_push(stack, 3);
  stack_push(stack, 7);
  stack_push(stack, 8);
  stack_print(stack);
  printf("[2] : %d\n", stack_get(stack, 2));
  printf("pop value : %d\n", stack_pop(stack));
  stack_print(stack);
  stack_free(stack);
  return 0;
}

Stack* stack_init()
{
  Stack *stack = malloc(sizeof(*stack));
  malloc_error(stack);
  stack->first = NULL;
  return stack;
}

void stack_push(Stack *stack, int value)
{
  Element *new = malloc(sizeof(*new));
  malloc_error(new);
  new->value = value;
  new->next = stack->first;
  stack->first = new;
}

int stack_pop(Stack *stack)
{
  Element *toPop = stack->first;
  int value = toPop->value;
  stack->first = toPop->next;
  free(toPop);
  return value;
}

void stack_free(Stack *stack)
{
  while (stack->first != NULL)
    stack_pop(stack);
  free(stack);
}

void stack_print(Stack *stack)
{
  Element *el = stack->first;
  printf("[\n");
  while (el != NULL)
  {
    printf(" %d,\n", el->value);
    el = el->next;
  }
  printf("]\n");
}

int stack_get(Stack *stack, int index)
{
  Element *el = stack->first;
  int i = 0;
  while (i < index && el != NULL)
  {
    el = el->next;
    i++;
  }

  if (i != index)
    errx(1, "Index out of range");
  else
    return el->value;
}