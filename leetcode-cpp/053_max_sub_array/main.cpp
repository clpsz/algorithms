#include "../common.h"


// 12ms
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = 0;
        int thisSum = 0;
        int maxD = nums[0];

        for (auto d : nums)
        {
            if (d > maxD)
                maxD = d;
        }

        maxSum = maxD;


        int thisCount = 0;
        for (auto d : nums)
        {
            thisSum += d;
            ++thisCount;
            if (thisSum < 0)
            {
                thisSum = 0;
                thisCount = 0;
            }

            if (thisSum > maxSum && thisCount > 0)
                maxSum = thisSum;
        }


        return maxSum;
    }
};




int main()
{
    Solution s;
    vector<int> v{-1, 0, -2};

    cout << s.maxSubArray(v);

    return 0;
}

