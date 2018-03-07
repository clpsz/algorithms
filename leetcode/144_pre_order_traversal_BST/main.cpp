#include "../common.h"
#include <stack>

using std::stack;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 0ms
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;

        stack<TreeNode *> s;
        s.push(root);
        while (!s.empty())
        {
            TreeNode *cur = s.top();
            res.push_back(cur->val);
            s.pop();
            if (cur->right)
            {
                s.push(cur->right);
            }
            if (cur->left)
            {
                s.push(cur->left);
            }
        }
        

        return res;
    }
};




int main()
{
    Solution s;

    TreeNode *t2 = new TreeNode(2);
    TreeNode *t1 = new TreeNode(1);
    TreeNode *t3 = new TreeNode(3);

    t2->left = t1;
    t2->right = t3;

    auto res = s.preorderTraversal(t2);
    for (auto n : res)
    {
        cout << n << endl;
    }

    return 0;
}

