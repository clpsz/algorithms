#ifndef __QUICK_SORT_H
#define __QUICK_SORT_H

#include "Sort.h"
#include "common.h"

class QuickSort: public Sort
{
public:
    LLONG sort();

private:
    int sort(int lo, int hi);
    int partition(int lo, int hi, int &compCount);
    int getMedian(int lo, int hi);
};

#endif

