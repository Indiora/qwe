#include "abs_max.h"
int abs_max(int array[], int size)
{
    int i=0;
    int max = array[0];
    for (int i = 0; i < size; i++)
    {
        if (abs(array[i]) > abs(max))
        {
            max = array[i];
        }
    }
    return max;
}
