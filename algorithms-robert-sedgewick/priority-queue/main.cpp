#include "common.h"
#include "MaxPQ.h"


int main(int argc, char *argv[])
{
    // hold 1000 values max
    MaxPQ pq(1000);

    int value;
    while (cin >> value)
    {
        pq.insert(value);
    }

    while (!pq.isEmpty())
    {
        cout <<  pq.deleteMax() << " ";
    }
    cout << endl;
    return 0;
}
