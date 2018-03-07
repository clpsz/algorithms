#include "common.h"
#include "QuickSort.h"

LLONG QuickSort::sort()
{
    return sort(0, dataLen - 1);
}

int QuickSort::sort(int lo, int hi)
{
    static int count = 0;
    if (lo >= hi)
    {
        return 0;
    }

    int compCount = 0;
    int p = partition(lo, hi, compCount);
    if (count++ == 0)
        cout << "First count:" << compCount << endl;
    int leftCount = sort(lo, p - 1);
    int rightCount = sort(p + 1, hi);

    return compCount + leftCount + rightCount;
}

int QuickSort::getMedian(int lo, int hi)
{
    int mi = (lo+hi)/2;
    vector<int> v{data[lo], data[mi], data[hi]};
    std::sort(v.begin(), v.end());

    if (data[lo] == v[1])
        return lo;
    else if (data[hi] == v[1])
        return hi;
    else
        return mi;
}

int QuickSort::partition(int lo, int hi, int &compCount)
{
//    Question 3
//    int mi = getMedian(lo, hi);
//    exch(mi, lo);

//    Question 2
//    exch(lo, hi);

//    Question 1
//    Nothing more

    int v = data[lo];
    int i = lo + 1;
    int j = lo + 1;

    while (j <= hi)
    {
        if (data[j] < v)
        {
            exch(j, i);
            ++i;
        }

        j++;
    }

    exch(lo, i - 1);
    compCount = hi - lo;

    return i - 1; // data[lo..j-1] <= data[j] <= data[j+1..hi]
}

