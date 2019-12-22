#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using std::vector;

using std::cout;
using std::cin;
using std::endl;


class Solution {
public:
    int addDigits1(int num) {
        if (num < 10)
            return num;

        int res = 0;

        while (num > 0)
        {
            int thisDight = num % 10;
            num /= 10;
            res += thisDight;
        }

        return addDigits(res);
    }

    int addDigits(int num) {
        int res = num - 9*((num - 1) / 9);

        return res;
    }
};

int main()
{
    Solution s;
    cout << s.addDigits(38) << endl;

    return 0;
}

