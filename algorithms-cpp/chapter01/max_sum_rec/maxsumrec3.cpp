#include "../common.h"
#include <assert.h>


int calcMaxSum(const vector<int> &datas, int left, int right)
{
    assert(left <= right);

    if (left == right)
    {
        if (datas[left] > 0)
            return datas[left];
        else
            return 0;
    }

    // center belongs to left
    int center = (left + right) / 2;
    int maxLeft = calcMaxSum(datas, left, center);
    int maxRight = calcMaxSum(datas, center + 1, right);

    int maxLeftBoarder = 0, maxRightBoarder = 0;
    int thisSum = 0;
    for (int i = center; i >= left; i--)
    {
        thisSum += datas[i];
        if (thisSum > maxLeftBoarder)
            maxLeftBoarder = thisSum;
    }
    thisSum = 0;
    for (int i = center + 1; i <= right; i++)
    {
        thisSum += datas[i];
        if (thisSum > maxRightBoarder)
            maxRightBoarder = thisSum;
    }
    int maxCenter = maxLeftBoarder + maxRightBoarder;

    int max1 = std::max(maxLeft, maxRight);
    int max2 = std::max(max1, maxCenter);

    return max2;
}

int maxSum(const vector<int> &datas)
{
    int left = 0;
    int right = datas.size() - 1;
    
    return calcMaxSum(datas, left, right);
}


int main(int argc, char *argv[])
{
    vector<int> datas;
    int num;

    while (cin >> num)
    {
        datas.push_back(num);
    }

    int max = maxSum(datas);
    cout << max << endl;

    return 0;
}

