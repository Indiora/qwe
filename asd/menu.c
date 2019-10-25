#include <stdio.h>
#include "abs_max.h"
#include "abs_min.h"
#include "diff.h"
#include "sum.h"
int main()
{
int arr[100]; 
int i = 0; 
char b; 
int val;
int count = 0;
scanf("%d", &val);
while (b != '\n')
{
scanf("%d%c", &arr[i], &b);
i++;
count++;
}

switch(val)
{
case 0: printf("%d\n", abs_max(arr, count));
break;
case 1: printf("%d\n", abs_min(arr, count));
break;
case 2: printf("%d\n", diff(arr, count));
break;
case 3: printf("%d\n", sum(arr, count));
break;
default: printf("%s\n", "Данные некорректны");

}
return 0;
}
