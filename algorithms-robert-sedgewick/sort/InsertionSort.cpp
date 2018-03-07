#include "InsertionSort.h"

void InsertionSort::sort()
{
    for (int i = 1; i < dataLen; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (less(data[j], data[j-1]))
            {
                exch(j, j-1);
            }
            else
            {
                break;
            }
        }
    }
}

