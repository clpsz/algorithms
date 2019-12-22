#include "../common.h"
#include <stdio.h>

using std::begin;
using std::end;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 44ms
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root->val > p->val && root->val > q->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (root->val < p->val && root->val < q->val)
            return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
};

// 52ms
class Solution1 {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pNodes = find(root, p);
        vector<TreeNode*> qNodes = find(root, q);
        
        return findLowest(pNodes, qNodes);
    }

private:
    vector<TreeNode*> find(TreeNode *root, TreeNode *target)
    {
        vector<TreeNode*> res;
        if (root == NULL)
            return res;

        if (root->val == target->val)
        {
            res.push_back(root);
            return res;
        }
        else if (target->val < root->val)
        {
            res.push_back(root);
            vector<TreeNode*> subRes = find(root->left, target);
            res.insert(end(res), begin(subRes), end(subRes));
            return res;
        }
        else
        {
            res.push_back(root);
            vector<TreeNode*> subRes = find(root->right, target);
            res.insert(end(res), begin(subRes), end(subRes));
            return res;
        }
    }

    TreeNode *findLowest(const vector<TreeNode*> &pNodes, const vector<TreeNode*> &qNodes)
    {
        int size = std::min(pNodes.size(), qNodes.size());
        TreeNode *lowest = NULL;

        for (int i = 0; i < size; i++)
        {
            if (pNodes[i] == qNodes[i])
                lowest = pNodes[i];
        }

        return lowest;
    }

    void printChain(const vector<TreeNode*> &nodes)
    {
        for (auto node : nodes)
        {
            cout << node->val << endl;
        }

        cout << endl;
    }
};

int main()
{
    TreeNode *t2 = new TreeNode(2);
    TreeNode *t1 = new TreeNode(1);

    t2->left = t1;

    Solution s;
    TreeNode *t = s.lowestCommonAncestor(t2, t2, t1);
    cout << t->val;

    return 0;
}

