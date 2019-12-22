#include "../common.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//12 ms
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (!root)
            return 0;

        if (!root->left && !root->right)
            return 1;
        else if (root->left && root->right)
        {
            int minLeft = 1 + minDepth(root->left);
            int minRigth = 1 + minDepth(root->right);
            return std::min(minLeft, minRigth);
        }
        else if (root->left)
            return 1 + minDepth(root->left);
        else
            return 1 + minDepth(root->right);
    }
};




int main()
{
    Solution s;

    TreeNode *root = new TreeNode(3);
//    TreeNode *r1 = new TreeNode(2);
//
//    root->left = r1;

    cout << s.minDepth(root) << endl; 


    return 0;
}

