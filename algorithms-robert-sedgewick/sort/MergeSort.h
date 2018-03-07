#ifndef __MERGE_SORT_H
#define __MERGE_SORT_H

#include "Sort.h"
#include "common.h"

class MergeSort: public Sort
{
public:
    MergeSort();
    ~MergeSort();
    void sort();

private:
    void merge(int lo, int mid, int hi);
    void sort(int lo, int hi);
    void sortTopDown();
    void sortBottomUp();

    int *aux;
};

#endif

