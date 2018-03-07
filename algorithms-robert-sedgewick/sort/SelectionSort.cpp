#include "SelectionSort.h"

SelectionSort::SelectionSort(): Sort()
{
}

void SelectionSort::sort()
{
    int minIndex;
    for (int i = 0; i < dataLen; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < dataLen; j++)
        {
            if (less(data[j], data[minIndex]))
            {
                minIndex = j;
            }
        }
        exch(minIndex, i);
    }
}

