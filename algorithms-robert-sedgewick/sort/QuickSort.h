#ifndef __QUICK_SORT_H
#define __QUICK_SORT_H

#include "Sort.h"

class QuickSort: public Sort
{
public:
    void sort();

private:
    void sort(int lo, int hi);
    int partition(int lo, int hi);
};

#endif

