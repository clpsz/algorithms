#ifndef __UF_H
#define __UF_H


class UF
{
public:
    UF(int N)
    {
        id = new int[N];
        idLen = N;
        count = N;

        for (int i = 0; i < N; i++)
        {
            id[i] = i;
        }
    }

    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }

    int getCount()
    {
        return count;
    }

    virtual int find(int p) = 0;
    virtual void _union(int p, int q) = 0;

protected:
    int *id;
    // connections count
    int count;
    // length of id array
    int idLen;
};

#endif

