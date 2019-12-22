#include "../common.h"


// 4ms
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((n >> i) & 0x01)
            {
                count++;
            }
        }

        return count;
    }
};




int main()
{
    Solution s;

    cout << s.hammingWeight(15) << endl;


    return 0;
}

