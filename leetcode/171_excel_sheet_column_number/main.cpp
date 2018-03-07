#include "../common.h"


class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        for (auto c : s)
        {
            int d = c - 'A' + 1;
            res *= 26;
            res += d;
        }


        return res;
    }
};


int main()
{
    Solution s;
    cout << s.titleToNumber(string("Z")) << endl;

    return 0;
}

