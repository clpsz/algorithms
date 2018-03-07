#include "common.h"
#include "QuickSort.h"
#include <assert.h>
#include <stdio.h>

vector<int> datas;

void read_data()
{
    int num;
    while (cin >> num)
    {
        datas.push_back(num);
    }
}

void print_data()
{
    cout << "length: " << datas.size() << endl;
    for (auto d : datas)
    {
        cout << d << endl;
    }
}


int main()
{
    Sort *s = new QuickSort();
    LLONG res = s->sort();
    s->show();

    cout << res;

    return 0;
}

