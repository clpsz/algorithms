#include "../common.h"


// 4ms
class Solution {
public:
    int lengthOfLastWord(string s) {
        bool startCount = false;
        int count = 0;

        for (auto it = s.rbegin(); it != s.rend(); it++)
        {
            auto c = *it;
            if (c != ' ' && startCount == false)
            {
                startCount = true;
                ++count;
            }
            else if (c != ' ' && startCount == true)
            {
                ++count;
            }
            else if (c == ' ' && startCount == true)
            {
                return count;
            }
        }

        return count;
    }
};



int main()
{
    Solution s;
    cout << s.lengthOfLastWord(string("Helloworld")) << endl;
    cout << s.lengthOfLastWord(string("Hello world")) << endl;
    cout << s.lengthOfLastWord(string("0")) << endl;
    cout << s.lengthOfLastWord(string("a ")) << endl;
    cout << s.lengthOfLastWord(string("")) << endl;


    return 0;
}

