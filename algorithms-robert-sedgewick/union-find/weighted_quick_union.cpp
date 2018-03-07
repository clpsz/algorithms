#include "weighted_quick_union.h"

weightedQuickUnion::weightedQuickUnion(int N): UF(N)
{
    sz = new int[N];
    for (int i = 0; i < N; i++)
    {
        sz[i] = 1;
    }
}


int weightedQuickUnion::find(int p)
{
    int root = p;

    while (root != id[root])
    {
        root = id[root];
    }

    return root;
}

void weightedQuickUnion::_union(int p, int q)
{
    int pId = find(p);
    int qId = find(q);

    if (pId == qId)
    {
        return;
    }

    if (sz[p] < sz[q])
    {
        id[pId] = qId;
        sz[pId] += sz[qId];
    }
    else
    {
        id[qId] = pId;
        sz[qId] += sz[pId];
    }

    count--;
}

