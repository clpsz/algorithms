#include "../common.h"
#include <map>


using std::map;


// 0ms
class Solution {
public:
    int numTrees(int n) {
        auto it = cache.find(n);
        if (it != cache.end())
            return it->second;

        if (n <= 1)
            return 1;
        int res = 0;

        for (int i = 0; i < n; i++)
        {
            int left = numTrees(i);
            int right = numTrees((n-1) - i);
            res += left * right;
        }

        cache[n] = res;
        return res;
    }

private:
    map<int, int> cache;
};




int main()
{
    Solution s;
    cout << s.numTrees(11) << endl;


    return 0;
}

