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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root)
            return res;
        stack<TreeNode *> s;

        TreeNode *current = root;
        while (current || !s.empty())
        {
            if (current == NULL)
            {
                TreeNode *top = s.top();
                s.pop();
                res.push_back(top->val);
                current = top->right;
            }
            else
            {
                s.push(current);
                current = current->left;
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

    auto res = s.inorderTraversal(t2);
    for (auto n : res)
    {
        cout << n << endl;
    }

    return 0;
}

