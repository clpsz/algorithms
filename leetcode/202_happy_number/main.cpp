#include <iostream>
#include <set>

using std::set;

using std::cout;
using std::cin;
using std::endl;


class Solution {
public:
    bool isHappy(int n) {
        set<int> record;
        if (n == 1)
            return true;

        int tmp = n;
        record.insert(n);

        while (true) {
            tmp = getSqureSumOfDigits(tmp);
            if (tmp == 1)
                return true;
            if (record.find(tmp) != record.end()) {
                return false;
            }

            record.insert(tmp);
        }

        return true;
    }

private:
    int getSqureSumOfDigits(int n) {
        int ret = 0;

        while (n > 0) {
            int thisDigit = n % 10;
            n /= 10;
            ret += thisDigit * thisDigit;
        }

        return ret;
    }
};


int main()
{
    Solution s;

    cout << s.isHappy(20) << endl;
    
    return 0;
}

