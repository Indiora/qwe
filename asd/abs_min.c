#include "abs_min.h"
int abs_min(int array[], int size)
{
    int min = array[0];
    for (int i=0; i < size; i++)
    {
        if (abs(array[i]) < abs(min))
        {
            min = array[i];
        }
    }
    return min;
}
