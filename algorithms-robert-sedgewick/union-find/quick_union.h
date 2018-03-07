#include "UF.h"

class quickUnion: public UF
{
public:
    quickUnion(int N): UF(N)
    {
    }

    int find(int p);
    void _union(int p, int q);
};

