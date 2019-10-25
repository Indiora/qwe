#include "abs_max.h"
#include "abs_min.h"
int diff(int array[], int count)
{
return abs_max(array, count) - abs_min(array, count);
}
