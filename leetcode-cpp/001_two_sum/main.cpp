#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using std::vector;

using std::pair;
using std::make_pair;

using std::map;
using std::multimap;

using std::cout;
using std::cin;
using std::endl;


class Solution {
public:
    // 32ms
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> res;
        multimap<int, int> posMap;

        for (int i = 0; i < size; i++)
        {
            posMap.insert(std::make_pair(nums[i], i+1));
        }

        for (std::multimap<int, int>::iterator it = posMap.begin(); it != posMap.end();  ++it)
        {
            auto its = posMap.equal_range(target - it->first);
            for (auto first = its.first; first != its.second; first++)
            {
                if (first != it &&
                    it->second < first->second)
                {
                    res.push_back(it->second);
                    res.push_back(first->second);
                    return res;
                }
            }
        }

        return res;
    }
};


int main()
{
    Solution s;
    vector<int> vi{0, 4, 3, 0};
    vector<int> res = s.twoSum(vi, 0);

    for (auto i : res)
    {
        cout << i << endl;
    }
}

