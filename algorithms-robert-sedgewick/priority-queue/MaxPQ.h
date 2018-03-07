#ifndef __MAX_PQ_H
#define __MAX_PQ_H

class MaxPQ
{
public:
    MaxPQ(int maxSize);
    ~MaxPQ();

    int max();
    int deleteMax();
    void insert(int value);
    bool less(int i, int j);
    void exch(int i, int j);
    void swim(int k);
    void sink(int k);
    int getSize();
    bool isEmpty();
    void show();

private:
    int size;
    int *pq;
};

#endif

