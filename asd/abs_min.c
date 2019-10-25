#include <stdlib.h>
int abs_min(int array[], int count)
{
int min = array[0];
int i = 0;
for (int i; i < count; i++)
{
if (abs(array[i]) < abs(min))
{
min = array[i];
}
}
return min;
}
