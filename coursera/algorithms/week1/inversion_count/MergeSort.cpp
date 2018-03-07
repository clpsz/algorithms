#include "MergeSort.h"
#include "common.h"
#include <assert.h>

MergeSort::MergeSort(): Sort()
{
    aux = new int[dataLen];
}

MergeSort::~MergeSort()
{
    delete []aux;
}

LLONG MergeSort::sort()
{
    return sortTopDown();
    //sortBottomUp();
}




LLONG MergeSort::sort(int lo, int hi)
{
    int mid = (lo+hi) / 2;

    if (lo >= hi)
    {
        return 0;
    }

    LLONG left = sort(lo, mid);
    LLONG right = sort(mid + 1, hi);
    LLONG split = merge(lo, mid, hi);

    return left + right + split;
}

LLONG MergeSort::sortTopDown()
{
    return sort(0, dataLen - 1);
}

void MergeSort::sortBottomUp()
{
    int step = 1;
    int lo, mid, hi;


    while (step < dataLen)
    {
        lo = 0;
        mid = lo + step - 1;
        hi = lo + 2*step - 1;

        // if mid >= dataLen-1, then stop
        while (lo < dataLen - step)
        {
            merge(lo, mid, hi);

            lo += 2*step;
            mid = lo + step -1;
            hi = lo + 2*step -1;
        }

        step *= 2;
    }
}

// mid belongs to left
LLONG MergeSort::merge(int lo, int mid, int hi)
{
    int i = lo;
    int j = mid + 1;

    LLONG inversionCount = 0;
    int leftLen = mid - lo + 1;

    mid = std::min(mid, dataLen -1);
    hi = std::min(hi, dataLen -1);

    //cout << lo << " " << mid << " " << hi << endl;

    for (int k = lo; k <= hi; k++)
    {
        aux[k] = data[k];
    }

    for (int k = lo; k <= hi; k++)
    {
        if (i > mid)
        {
            data[k] = aux[j++];
            assert(leftLen == 0);
        }
        else if(j > hi)
        {
            data[k] = aux[i++];
        }
        else if (less(aux[i], aux[j]))
        {
            data[k] = aux[i++];
            --leftLen;
        }
        else
        {
            data[k] = aux[j++];
            inversionCount += leftLen;
        }
    }

    return inversionCount;
}

