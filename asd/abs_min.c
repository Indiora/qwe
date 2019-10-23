#include "abs_min.h"
int abs_min(int array[], int size)
{
    int i=0;
    int min = array[0];
    for (int i; i < size; i++)
    {
        if (abs(array[i]) < abs(min))
        {
            min = array[i];
        }
    }
    return min;
}
