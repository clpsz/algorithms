#include "../common.h"
#include <algorithm>
#include <stdio.h>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = 0, right = 0;
        left = 1 + maxDepth(root->left);
        right = 1 + maxDepth(root->right);

        return std::max(left, right);
    }
};


int main()
{
    return 0;
}

