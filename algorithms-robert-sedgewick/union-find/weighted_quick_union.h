#include "UF.h"

class weightedQuickUnion: public UF
{
public:
    weightedQuickUnion(int N);

    int find(int p);
    void _union(int p, int q);

private:
    int *sz;
};

