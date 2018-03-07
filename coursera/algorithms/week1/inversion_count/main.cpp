#include "common.h"
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
    //for (auto d : datas)
    //{
    //    //cout << d << endl;
    //}
}

int merge(int left, int center, int right)
{
    vector<int> aux(datas);


    return 0;
}

int do_get_res(int left, int right)
{
    assert(left <= right);
    if (left == right)
        return 0;

    int center = (left + right) / 2;

    printf("left: %d, right: %d, center: %d\n", left, right, center);

    int leftRes = do_get_res(left, center);
    int rightRes = do_get_res(center + 1, right);
    int splitRes = merge(left, center, right);

    return leftRes + rightRes + splitRes;
}

int get_res()
{
    int left = 0;
    int right = datas.size() - 1;

    return do_get_res(left, right);
}

#include "MergeSort.h"



int main()
{
    Sort *s = new MergeSort();


    LLONG res = s->sort();

    cout << res << endl;
    //s->show();

    return 0;
}

