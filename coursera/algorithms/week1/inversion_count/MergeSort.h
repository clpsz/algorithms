#ifndef __MERGE_SORT_H
#define __MERGE_SORT_H

#include "Sort.h"
#include "common.h"

class MergeSort: public Sort
{
public:
    MergeSort();
    ~MergeSort();
    LLONG sort();

private:
    LLONG merge(int lo, int mid, int hi);
    LLONG sort(int lo, int hi);
    LLONG sortTopDown();
    void sortBottomUp();

    int *aux;
};

#endif

