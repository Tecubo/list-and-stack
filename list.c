#include "list.h"

int main()
{
    List *list = list_empty();
    list_append(list, 1);
    list_append(list, 2);
    list_append(list, 3);
    list_print(list);
    int r = list_pop(list);
    printf("%d\n", r);
    list_print(list);
    r = list_get_element(list, 1);
    printf("%d\n", r);
    list_destroy(list);
    return 0;
}

List *list_empty()
{
    List *list = malloc(sizeof(List));
    malloc_error(list);
    list->value = 0;
    list->next = NULL;
    return list;
}

int list_is_empty(List *list)
{
    pointer_is_null(list);
    if (list->value)
        return 0;
    else
        return 1;
}

void list_append(List *list, int element)
{
    pointer_is_null(list);
    List *new_element = malloc(sizeof(List));
    malloc_error(new_element);
    new_element->value = element;
    new_element->next = NULL;
    List *l = list;
    while (l->next != NULL)
        l = l->next;
    l->next = new_element;
    list->value++;
}

int list_pop(List *list)
{
    pointer_is_null(list);
    int value = 0;
    if (list_is_empty(list))
        return -1;
    List *previous_element = list;
    List *last_element = list->next;
    while (last_element->next != NULL)
    {
        previous_element = last_element;
        last_element = last_element->next;
    }
    value = last_element->value;
    previous_element->next = NULL;
    free(last_element);
    list->value--;
    return value;
}

int list_lenght(List *list)
{
    pointer_is_null(list);
    return list->value;
}

void list_print(List *list)
{
    pointer_is_null(list);
    List *l = list->next;
    int lenght = list_lenght(list);
    printf("[");
    for (int i = 0; i < lenght; i++)
    {
        if (i == lenght - 1)
            printf("%d", l->value);
        else
            printf("%d, ", l->value);
        l = l->next;
    }
    printf("]\n");
}

int list_get_element(List *list, int index)
{
    pointer_is_null(list);
    int lenght = list_lenght(list);
    if (index >= lenght)
        errx(1, "Error: index out of range");
    List *l = list->next;
    for (int i = 0; i < index; i++)
    {
        l = l->next;
    }
    return l->value;
}

void list_destroy(List *list)
{
    pointer_is_null(list);
    List *previous_element = list;
    List *last_element = list->next;
    while (last_element != NULL)
    {
        free(previous_element);
        previous_element = last_element;
        last_element = last_element->next;
    }
}