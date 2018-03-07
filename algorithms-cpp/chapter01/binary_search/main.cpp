#include "../common.h"
#include <assert.h>

int binarySearchRecursive(const vector<int> &datas, int left, int right, int target)
{
    assert(left <= right);
    if (left == right)
    {
        if (datas[left] == target)
            return left;
        return -1;
    }

    int center = (left + right) / 2;
    if (target < datas[center])
        return binarySearchRecursive(datas, left, center, target);
    else if (target > datas[center])
        return binarySearchRecursive(datas, center + 1, right, target);
    else if (target == datas[center])
        return center;

    return -1;
}


int searchRecursive(const vector<int> &datas, int target)
{
    int left = 0, right = datas.size() - 1;

    return binarySearchRecursive(datas, left, right, target);
}


int searchIterative(const vector<int> &datas, int target)
{
    int left = 0, right = datas.size() - 1;    

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (datas[mid] == target)
        {
            return mid;
        }
        else if (datas[mid] > target)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    return -1;
}


void print(const vector<int> &datas)
{
    int i = 0;
    for (auto d : datas)
    {
        cout << i << ": " << d << endl;
        i++;
    }
}


int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "usage:" 
             << "       ./_main <number>"
             << endl;
        exit(-1);
    }


    vector<int> datas;
    int num;

    while (cin >> num)
    {
        datas.push_back(num);
    }

    print(datas);
    cout << endl;

    int target = std::stoi(string(argv[1]));

    int pos = -1;
    if ((pos = searchRecursive(datas, target)) >= 0)
    {
        cout << "pos is: " << pos << endl;
    }

    if ((pos = searchIterative(datas, target)) >= 0)
    {
        cout << "pos is: " << pos << endl;
    }

    return 0;
}

