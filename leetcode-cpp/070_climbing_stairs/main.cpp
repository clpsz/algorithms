#include "../common.h"
#include <map>

using std::map;


class Solution {
public:
    int climbStairs(int n) {
        auto it = cache.find(n);
        if (it != std::end(cache))
            return it->second;
        
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        int count1 = climbStairs(n-1);
        int count2 = climbStairs(n-2);
        int res = count1 + count2;
        cache[n] = res;

        return count1 + count2;
    }

private:
    map<int, int> cache;
};




int main()
{
    Solution s;

    cout << s.climbStairs(44) << endl;

    return 0;
}

