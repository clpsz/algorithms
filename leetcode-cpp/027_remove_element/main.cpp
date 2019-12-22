#include "../common.h"



// 4ms
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> res;
        int newSize = 0;

        for (auto d : nums)
        {
            if (d != val)
            {
                ++newSize;
                res.push_back(d);
            }
        }

        nums = res;

        return newSize;
    }
};


void print(const vector<int> &nums)
{
    for (auto d : nums)
        cout << d << endl;

    cout << endl;
}

int main()
{
    Solution s;
    vector<int> v1{1,1,1,1};
    print(v1);
    cout << s.removeElement(v1, 1) << endl;
    print(v1);


    return 0;
}

