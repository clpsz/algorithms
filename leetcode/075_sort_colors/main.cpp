#include "../common.h"



class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> counts(4, 0);
        vector<int> res(nums.size(), 0);

        for (auto d : nums)
            ++counts[d+1];

        counts[2] += counts[1];

        for (auto d : nums)
        {
            res[counts[d]] = d;
            ++counts[d];
        }
        std::swap(res, nums);
    }
};


int main()
{
    Solution s;

    vector<int> nums{1,1,1,2,2,2,2,0,0,0,0};

    s.sortColors(nums);

    for (auto d : nums)
        cout << d << endl;

    return 0;
}

