#include "../common.h"
#include <stack>
#include <queue>

using std::stack;
using std::queue;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
// 8ms
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL)
            return res;

        queue<TreeNode *> s;
        s.push(root);

        while(!s.empty())
        {
            queue<TreeNode *> aux;
            vector<int> thisLevel;
            while (!s.empty())
            {
                TreeNode *t = s.front();
                s.pop();
                thisLevel.push_back(t->val);
                if (t->left)
                    aux.push(t->left);
                if (t->right)
                    aux.push(t->right);
            }
            res.push_back(thisLevel);
            s = aux;
        }

        return res;
    }
};



int main()
{
    Solution s;
    TreeNode *root = new TreeNode(3);
    TreeNode *r1 = new TreeNode(9);
    TreeNode *r2 = new TreeNode(20);
    TreeNode *r3 = new TreeNode(15);
    TreeNode *r4 = new TreeNode(7);

    root->left = r1;
    root->right = r2;
    r2->left = r3;
    r2->right = r4;


    auto res = s.levelOrder(root);

    for (auto v : res)
    {
        for (auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }


    return 0;
}

