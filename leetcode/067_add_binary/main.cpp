#include "../common.h"
#include "stdio.h"


// 8ms
class Solution {
public:
    string addBinary(string a, string b) {
        vector<int> va, vb;
        for (auto c : a)
            va.push_back(c == '1');

        for (auto c : b)
            vb.push_back(c == '1');

        std::reverse(va.begin(), va.end());
        std::reverse(vb.begin(), vb.end());

        int maxSize = std::max(va.size(), vb.size());
        va.resize(maxSize, 0);
        vb.resize(maxSize, 0);

        

        int carry = 0;
        int res = 0;
        vector<int> vres;
        for (int i = 0; i < maxSize; i++)
        {
            res = addTwo(va[i], vb[i], carry);
            vres.push_back(res);
        }

        if (carry)
            vres.push_back(carry);

        std::reverse(vres.begin(), vres.end());
        string s;
        for (auto d : vres)
            s += (d == 0 ? string("0") : string("1"));


        return s;
    }

public:
    void printV(const vector<int> &v)
    {
        for (auto c : v)
            cout << c << endl;
        cout << endl;
    }

public:
    int addTwo(int a, int b, int &c)
    {
        int res = a+b+c;
        c = ((res & 0x02) == 0x02);
        res %= 2;

        return res;
    }
};

int main()
{
    Solution s;
    string s1("1");
    string s2("1");
    cout << s.addBinary(s1, s2) << endl;



    return 0;
}

