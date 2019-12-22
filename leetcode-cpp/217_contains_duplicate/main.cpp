#include "../common.h"
#include <set>
#include <algorithm>

using std::sort;
using std::begin;
using std::end;

using std::set;


// 52ms
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty())
            return false;

        set<int> s(begin(nums), end(nums));
        if (s.size() < nums.size())
            return true;
        
        return false;
    }
};

// 40ms
class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty())
            return false;
        sort(begin(nums), end(nums));
        for (auto it = begin(nums); it != end(nums) - 1; it++)
        {
            if (*it == *(it+1))
                return true;
        }
        
        return false;
    }
};


int main()
{
    vector<int> t{1,2,3,4,5,6,7,8};
    Solution s;
    cout << s.containsDuplicate(t) << endl;
    return 0;
}

