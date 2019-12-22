#include "../common.h"

// 4ms
class Solution {
public:
    int findMin(vector<int>& nums) {
        int size = nums.size();

        return doFind(nums, 0, size - 1);

    }

    int doFind(const vector<int> &nums, int left, int right)
    {
        if (left == right)
            return nums[left];

        if (nums[left] < nums[right])
            return nums[left];

        int center = (left + right) / 2;
        int minLeft, minRight;

        minRight = doFind(nums, center + 1, right);
        minLeft = doFind(nums, left, center);

        return std::min(minRight, minLeft);
    }
};

// 4ms
class Solution1 {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        for (auto n : nums)
        {
            if (n < min)
                min = n;
        }
        
        return min;
    }
};


int main()
{
    Solution s;
    vector<int> v{4,5,6,7,0,1,2};
    cout << s.findMin(v) << endl;
    return 0;
}

