#include "BubbleSort.h"
#include "common.h"

void BubbleSort::sort()
{
    for (int i = dataLen; i > 0; i--)
    {
        for (int j = 1; j < i; j++)
        {
            if (less(data[j], data[j-1]))
            {
                exch(j, j-1);
            }
        }
    }
}

