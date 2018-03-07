#include "quick_find.h"

int quickFind::find(int p)
{
    return id[p];
}

void quickFind::_union(int p, int q)
{
    int pId = find(p);
    int qId = find(q);

    if (pId == qId)
    {
        return;
    }

    for (int i = 0; i < idLen; i++)
    {
        if (id[i] == pId)
        {
            id[i] = qId;
        }
    }

    count--;
}

