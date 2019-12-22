#include "../common.h"


// 8ms
class Solution {
public:
    string countAndSay(int n) {
        string test("1");

        while (--n)
        {
            string s;
            int last = 0;
            int count = 0;

            for (auto d : test)
            {
                if (count == 0)
                {
                    ++count;
                    last = d;
                }
                else
                {
                    if (d == last)
                        ++count;
                    else
                    {
                        s += std::to_string(count) + string(1, last);
                        last = d;
                        count = 1;
                    }
                }
            }
            s += std::to_string(count) + string(1, last);
            test = s;
        }

        return test;
    }
};



int main()
{
    Solution s;
    cout << s.countAndSay(1) << endl;
    cout << s.countAndSay(2) << endl;
    cout << s.countAndSay(3) << endl;
    cout << s.countAndSay(4) << endl;
    cout << s.countAndSay(5) << endl;

    return 0;
}

