#include "../common.h"

using std::begin;
using std::end;

// 0ms
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> vec1 = toVector(version1);
        vector<int> vec2 = toVector(version2);


        int maxSize = std::max(vec1.size(), vec2.size());
        vec1.resize(maxSize, 0);
        vec2.resize(maxSize, 0);

        if (vec1 == vec2)
            return 0;
        else if (vec1 > vec2)
            return 1;
        else
            return -1;
    }

private:
    vector<int> toVector(const string &s)
    {
        vector<int> res;
        auto lastDot = begin(s);
        auto it = begin(s);
        for (; it != end(s); it++)
        {
            if (*it == '.')
            {
                string tmp(lastDot, it);
                res.push_back(std::stoi(tmp));
                lastDot = it+1;
            }
        }
        string tmp(lastDot, it);
        res.push_back(std::stoi(tmp));

        return res;
    }
};




int main()
{
    Solution s;

    string s1{"0"};
    string s2{"1"};

    cout << s.compareVersion(s1, s2) << endl;

    return 0;
}

