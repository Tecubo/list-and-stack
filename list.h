#ifndef _LIST_H
#define _LIST_H 1

#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

typedef struct List List;
struct List
{
    int value;
    List *next;
};

List *list_empty();
int list_is_empty(List *list);
void list_append(List *list, int element);
int list_pop(List *list);
int list_lenght(List *list);
void list_print(List *list);
int list_get_element(List *list, int index);
void list_destroy(List *list);

#endif