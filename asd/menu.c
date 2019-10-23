#include <stdio.h>
#include <stdlib.h>
#include "abs_min.h"
#include "abs_max.h"
#include "diff.h"
#include "sum.h"

int abs_max(int array[], int size, int i)
{
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


int abs_min(int array[], int size, int i)
{
    int min = array[0];
    for (int i = 0; i < size; i++)
    {
        if (abs(array[i]) < abs(min))
        {
            min = array[i];
        }
    }
    return min;
}


int diff(int array[], int size)
{
    return abs_max(array, size) - abs_min(array, size);
}


int sum(int array[], int size, int i)
{
    int sum = 0;
    int flag = 0;
    for (int i = 0; i < size; i++)
    {
        if ((flag == 1) || (array[i] == abs_max(array,size)))
        {
            sum = sum + array[i];
            flag = 1;
        }
    }
    return sum;
}


int main()
{
    int array[100];
    int i = 0;
    int menu;
    int size = 0;
    char flag;
    scanf("%d", &menu);
    while (flag != '\n')
    {
        scanf("%d%c", &array[i], &flag);
        i++;
    }
    size = i;

    switch(menu)
    {
    case 0: printf("%d", abs_max(array, size));
    break;
    case 1: printf("%d", abs_min(array, size));
    break;
    case 2: printf("%d", diff(array, size));
    break;
    case 3: printf("%d", sum(array, size));
    break;
    default: printf("Äàííûå íåêîððåêòíû");
    }
return 0;
}
