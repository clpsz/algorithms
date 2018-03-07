#include "../common.h"
#include <assert.h>


int main(int argc, char *argv[])
{
    vector<int> datas;
    int num;

    while (cin >> num)
    {
        datas.push_back(num);
    }

    int maxSum = 0;
    int thisSum = 0;

    int from = 0, end = 0;
    for (int i = 0; i < datas.size(); i++)
    {
        thisSum += datas[i];   
        if (thisSum < 0)
        {
            thisSum = 0;
            from = i + 1;
        }
        if (thisSum > maxSum)
        {
            maxSum = thisSum;
            end = i;
        }
    }


    cout << "Max sum is: " << maxSum << endl;
    cout << "from: " << from << ", end: " << end << endl;
    return 0;
}

