#include "../common.h"



// 8ms
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty())
            return 0;

        int size = nums.size();

        int i;
        for (i = 0; i < size; i++)
        {
            if (target == nums[i])
                return i;

            if (target < nums[i])
                return i;
        }

        if (i == size)
            return size;

        return 0;
    }
};


int main()
{
    Solution s;
    vector<int> v1{1,3,5,6};
    cout << s.searchInsert(v1, 5) << endl;
    cout << s.searchInsert(v1, 2) << endl;
    cout << s.searchInsert(v1, 7) << endl;
    cout << s.searchInsert(v1, 0) << endl;


    return 0;
}

