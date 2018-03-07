#include "MaxPQ.h"
#include "common.h"

MaxPQ::MaxPQ(int maxSize)
{
    pq = new int[maxSize + 1];
    size = 0;
}

MaxPQ::~MaxPQ()
{
    delete []pq;
}

int MaxPQ::max()
{
    return pq[1];
}

void MaxPQ::show()
{
    for (int i = 1; i <= size; i++)
    {
        cout << pq[i] << " ";
    }
    cout << endl;
}

int MaxPQ::getSize()
{
    return size;
}

bool MaxPQ::isEmpty()
{
    return size == 0;
}

bool MaxPQ::less(int i, int j)
{
    return pq[i] < pq[j];
}

void MaxPQ::exch(int i, int j)
{
    int tmp = pq[i];
    pq[i] = pq[j];
    pq[j] = tmp;
}

void MaxPQ::swim(int k)
{
    while (k > 1 && less(k/2, k))
    {
        exch(k/2, k);
        k = k / 2;
    }
}

void MaxPQ::sink(int k)
{
    while (2*k <= size)
    {
        int j = 2*k;
        if (j < size && less(j, j+1))
        {
            j = j+1;
        }
        // if pq[k] is already bigger than its successor, nothing to do
        if (less(j, k))
        {
            break;
        }
        exch(j, k);
        k = j;
    }
}

void MaxPQ::insert(int value)
{
    size += 1;
    pq[size] = value;
    swim(size);
}

int MaxPQ::deleteMax()
{
    int value = pq[1];

    exch(1, size--);
    sink(1);

    return value;
}

