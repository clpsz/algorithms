#ifndef __SORT_H
#define __SORT_H

#include "common.h"

class Sort
{
public:
    Sort()
    {
        dataLen = 0;

        int d;
        while (cin >> d)
        {
            data.push_back(d);
            dataLen++;
        }
    }

    virtual LLONG sort() = 0;
    bool less(int a, int b)
    {
        return a < b;
    }

    void exch(int i, int j)
    {
        int tmp = data[i];
        data[i] = data[j];
        data[j] = tmp;
    }

    bool isSorted()
    {
        for (int i = 1; i < dataLen; i++)
        {
            if (less(data[i], data[i-1]))
            {
                return false;
            }
        }
    }

    void show()
    {
        for (int i = 0; i < dataLen; i++)
        {
            cout << data[i] << endl;
        }
        cout << endl;
    }

protected:
    int dataLen;
    vector<int> data;
};

#endif

