#include "../common.h"
#include <algorithm>
#include <stdio.h>

using std::sort;
using std::begin;
using std::end;

class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            sort(begin(nums), end(nums));
            int size = nums.size();
            int i;
            for (i = 0; i < size - 1; ++i)
            {
                if (nums[i] != nums[i+1])
                    return nums[i];

                ++i;
            }

            return nums[i];
        }
};


int main()
{
    Solution s;
    vector<int> test{1,2,3,4,5,6,7,8,9,1,2,3,4,5,6,8,9};
    cout << s.singleNumber(test) << endl;


    return 0;
}

