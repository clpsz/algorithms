#include "../common.h"
#include <stdio.h>


class Solution {
public:
    // 8ms
    bool isPowerOfTwo(int n) {
        int count = 0;

        if (n & 0x80000000) return false;

        for (int i = 0; i < 32; i++)
        {
            bool res = ((n<<i) & 0x80000000) != 0;
            count += res;
        }

        return count == 1;
    }
};


int main()
{
    Solution s;
    cout << s.isPowerOfTwo(4) << endl;
    cout << s.isPowerOfTwo(5) << endl;
    cout << s.isPowerOfTwo(0x90000000) << endl;

    return 0;
}

