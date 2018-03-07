#ifndef __QUICK_FIND_H
#define __QUICK_FIND_H


#include "UF.h"

class quickFind: public UF
{
public:
    quickFind(int N): UF(N)
    {
    }

    int find(int p);
    void _union(int p, int q);
};

#endif

