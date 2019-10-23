#include "sum.h"
int sum(int array[], int size)
{
    int i=0;
    int sum = 0;
    int flag = 0;
    for (int i; i < size; i++)
    {
        if ((flag == 1) || (array[i] == abs_max(array,size)))
        {
            sum = sum + array[i];
            flag = 1;
        }
    }
    return sum;
}
