#include "QuickSort.h"

void QuickSort::sort()
{
    sort(0, dataLen - 1);
}

void QuickSort::sort(int lo, int hi)
{
    if (lo >= hi)
    {
        return;
    }

    int p = partition(lo, hi);
    sort(lo, p - 1);
    sort(p + 1, hi);
}

int QuickSort::partition(int lo, int hi)
{
    int v = data[lo];
    int i = lo + 1;
    int j = hi;

    while (true)
    {
        while (less(data[i], v))
        {
            if (i == hi)
                break;
            i++;
        }

        while (less(v, data[j]))
        {
            if (j == lo)
                break;
            j--;
        }

        if (i >= j)
            break;

        exch(i, j);
    }

    exch(lo, j);

    return j; // data[lo..j-1] <= data[j] <= data[j+1..hi]
}

