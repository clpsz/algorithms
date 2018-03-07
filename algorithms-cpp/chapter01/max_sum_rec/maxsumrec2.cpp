#include "../common.h"


int main(int argc, char *argv[])
{
    vector<int> datas;
    int num;

    while (cin >> num)
    {
        datas.push_back(num);
    }

    int maxSum = 0;
    int from, end;
    for (unsigned int i = 0; i < datas.size(); i++)
    {
        int thisSum = 0;
        for (unsigned int j = i; j < datas.size(); j++)
        {
            thisSum += datas[j];

            if (thisSum > maxSum)
            {
                maxSum = thisSum;
                from = i;
                end = j;
            }
        }
    }

    cout << "Max sum is: " << maxSum << endl;
    cout << "from: " << from << ", end: " << end << endl;

    return 0;
}

