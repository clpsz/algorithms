#include "../common.h"




class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> aux(nums1);
        nums1.resize(m+n);
        int i = 0, j = 0, k = 0;
        while (i < m && j < n)
        {
            if (aux[i] > nums2[j])
                nums1[k++] = nums2[j++];
            else
                nums1[k++] = aux[i++];
        }
        while (i < m)
            nums1[k++] = aux[i++];
        while (j < n)
            nums1[k++] = nums2[j++];
    }
};





int main()
{
    vector<int> v1{1,3,5,7,9};
    v1.reserve(20);
    vector<int> v2{2,4,6,8,10};

    for(auto i : v1)
    {
        cout << i << endl;
    }
    Solution s;
    s.merge(v1, 0, v2, 0);
    for(auto i : v1)
    {
        cout << i << endl;
    }

    
    return 0;
}

