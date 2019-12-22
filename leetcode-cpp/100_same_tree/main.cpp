#include "../common.h"
#include <stdio.h>


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};



class Solution {
public:
    // 0ms
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        else if (p && q && p->val == q->val)
        {
            bool sameLeft = isSameTree(p->left, q->left);
            bool sameRight = isSameTree(p->right, q->right);
            return sameLeft && sameRight;
        }
        else
            return false;
    }
};


int main()
{
    return 0;
}

