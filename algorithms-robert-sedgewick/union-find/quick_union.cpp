#include "quick_union.h"

int quickUnion::find(int p)
{
    int root = p;

    while (root != id[root])
    {
        root = id[root];
    }

    return root;
}

void quickUnion::_union(int p, int q)
{
    int pId = find(p);
    int qId = find(q);

    if (pId == qId)
    {
        return;
    }

    id[pId] = qId;
    count--;
}

