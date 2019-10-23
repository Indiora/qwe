#include <stdio.h>
#include <stdlib.h>
#include "abs_min.h"
#include "abs_max.h"
#include "diff.h"
#include "sum.h"

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
