#include "../common.h"
#include <stack>
#include <queue>
#include <stdio.h>

using std::stack;
using std::queue;


class Solution {
public:
    int reverse(int x) {
        if (x == 0)
            return 0;

        bool minus = false;
        if (x < 0)
        {
            minus = true;
            x = -1 * x;
        }

        long long reverse = 0;
        while (x > 0)
        {
            long long tmp = reverse;
            
            // multiply 10, 4ms fater
            reverse <<= 3;
            reverse += tmp;
            reverse += tmp;

            reverse += x%10;

            // hack divide by 10, no effect on time
            //long long invDivisor = 0x1999999A;
            // x = (invDivisor * x) >> 32;
            //

            // hack again, still no effect on time
            int n = x;
            int q, r;

            q = (n >> 1) + (n >> 2); 
            q = q + (q >> 4); 
            q = q + (q >> 8); 
            q = q + (q >> 16);
            q = q >> 3;
            r = n - (((q << 2) + q) << 1); 
            x = q + (r > 9);
        }

        // if MSB is 1, then add overflow
        if (reverse > (0x80000000ll))
            return 0;

        if (minus)
            reverse = 0 - reverse;

        return reverse;
    }
};




int main()
{
    Solution s;

    cout << s.reverse(1534236469) << endl;
    cout << s.reverse(1534) << endl;
    cout << s.reverse(-1534) << endl;

    return 0;
}

