#include "functions.h"

void malloc_error(void *pointer)
{
    if (pointer == NULL)
        errx(1, "Error: malloc failed");
}

void pointer_is_null(void *pointer)
{
    if (pointer == NULL)
        errx(1, "Error: pointer is null");
}