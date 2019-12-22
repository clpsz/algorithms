#include <string>
#include <iostream>
#include <map>

using std::string;

using std::map;

using std::cout;
using std::cin;
using std::endl;


class Solution {
public:
    int romanToInt(string s) {
        int ret = 0;
        map<char, int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;

        for (int idx = 0; idx < s.size(); ++idx) {
            if ((idx < s.size()-1) && (m[s[idx]] < m[s[idx+1]])) {
                ret -= m[s[idx]];
            }
            else {
                ret += m[s[idx]];
            }
        }
        return ret;
    }
};

int main()
{
    Solution s;
    cout << s.romanToInt("III") << endl;

    return 0;
}

