#include "../common.h"



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 0ms
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root)
        {
            TreeNode *left = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(left);
        }
        return root;
    }
};

void printTree(TreeNode *root)
{
    if (!root)
        return;
    cout << root->val << endl;
    printTree(root->left);
    printTree(root->right);
}

int main()
{
    TreeNode *root = new TreeNode(4);
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(3);
    TreeNode *t7 = new TreeNode(7);
    TreeNode *t6 = new TreeNode(6);
    TreeNode *t9 = new TreeNode(9);
    t2->left = t1;
    t2->right = t3;
    root->left = t2;

    t7->left = t6;
    t7->right = t9;
    root->right = t7;

    printTree(root);
    cout << endl;

    Solution s;
    s.invertTree(root);

    printTree(root);

    return 0;
}

