#include "../common.h"


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};




class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;

        return isSymmetric2(root->left, root->right);
    }

private:
    bool isSymmetric2(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL)
            return root2 == NULL;
        if (root2 == NULL)
            return root1 == NULL;

        if (root1->val != root2->val)
            return false;



        bool leftSymetric = isSymmetric2(root1->left, root2->right);
        bool rightSymetric = isSymmetric2(root1->right, root2->left);

        return leftSymetric && rightSymetric;
    }

    bool isLeaf(TreeNode *node)
    {
        return node->left == NULL && node->right == NULL;
    }
};

int main()
{
    TreeNode *root = new TreeNode(1);
    TreeNode *l2 = new TreeNode(2);
    TreeNode *r2 = new TreeNode(2);
    TreeNode *l3 = new TreeNode(3);
    TreeNode *r3 = new TreeNode(3);
    TreeNode *l4 = new TreeNode(4);
    TreeNode *r4 = new TreeNode(4);
    root->left = l2;
    root->right = r2;

    l2->left = l3;
    l2->right = l4;

    r2->left = r4;
    r2->right = r3;


    Solution s;
    cout << s.isSymmetric(root) << endl;

    return 0;
}

