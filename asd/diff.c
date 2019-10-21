#include "diff.h"
int diff(int array[], int size)
{
    return abs_max(array, size) - abs_min(array, size);
}

