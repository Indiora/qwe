#include <stdlib.h>

int abs_max(int array[], int count)
{
int max = array[0];
int i = 0;
for (i; i < count; i++)
{
if (abs(array[i]) > abs(max))
{
max = array[i];
}
}
return max;
}
