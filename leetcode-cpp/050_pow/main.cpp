#include "../common.h"


class Solution {
public:
    // 4ms
    double myPow(double x, int n) {
        bool minus = false;
        double tmp = 0;

        if (n < 0)
        {
            n = -1 * n;
            minus = true;
        }
        if (n == 0) tmp = 1;
        else if (n == 1) tmp = x;
        else if (n%2 == 0)
        {
            tmp = myPow(x*x, n/2);
        }
        else
        {
            tmp = x*myPow(x*x, n/2);
        }

        if (minus)  return 1/tmp;
        else return tmp;
    }
};


int main()
{
    Solution s;

    cout << s.myPow(3, 3) << endl;
    cout << s.myPow(34.00515, -3) << endl;
    cout << s.myPow(5, -2) << endl;

    return 0;
}
