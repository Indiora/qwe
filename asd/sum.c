#include "abs_max.h"
int sum(int array[], int count)
{

int sum = 0;
int c = 0;
for (int i = 0; i < count; i++)
{
if ((c == 1) || (array[i] == abs_max(array,count)))
{
sum = sum + array[i];
c = 1;
}
}



return sum;
}
