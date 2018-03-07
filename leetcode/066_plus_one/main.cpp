#include "../common.h"
#include <stack>

using std::stack;



class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        stack<int> s;
        vector<int> res;
        int carry = 1;

        for (auto it = digits.rbegin(); it != digits.rend(); it++)
        {
            int thisAdd = *it + carry;
            carry = thisAdd/10;
            thisAdd %= 10;
            s.push(thisAdd);
        }
        if (carry)
            s.push(carry);

        while (!s.empty())
        {
            int d = s.top();
            s.pop();

            res.push_back(d);
        }


        for (auto d : res)
            cout << d << endl;

        return res;
    }
};


int main()
{
    Solution s;
    vector<int> v{10};
    s.plusOne(v);

    return 0;
}

