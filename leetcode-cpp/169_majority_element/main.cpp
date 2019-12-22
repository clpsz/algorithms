#include "../common.h"
#include <algorithm>

using std::sort;

// 44ms
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int size = nums.size();
        if (size == 1)
            return nums[0];

        int count = 1;
        for (auto it = begin(nums); it != end(nums) - 1; it++)
        {
            if (*it == *(it + 1))
            {
                count++;
            }
            else
            {
                count = 1;
            }

            if (count > size/2)
                return *it;
        }

        return 0;
    }
};

int main()
{
    Solution s;
    vector<int> t{1,1,1,1,1,6,6,6,6,6,6,6,6};
    cout << s.majorityElement(t) << endl;
    vector<int> t1{1};
    cout << s.majorityElement(t1) << endl;

    return 0;
}

