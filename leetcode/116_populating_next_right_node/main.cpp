#include "../common.h"
#include <map>
#include <stack>
#include <queue>


using std::map;
using std::stack;
using std::queue;




struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};


class Solution {
public:
    void connect(TreeLinkNode* root) {
        if (!root)
            return;

        doConnect(root->left, root, true);
        doConnect(root->right, root, false);
    }

    void doConnect(TreeLinkNode *root, TreeLinkNode *parent, bool left)
    {
        if (!root)
            return;

        if (left)
            root->next = parent->right;
        else
        {
            if (parent->next)
            {
                root->next = parent->next->left;
            }
        }

        doConnect(root->left, root, true);
        doConnect(root->right, root, false);
    }






    void print(TreeLinkNode *root) {
        if (root == NULL)
            return;

        queue<TreeLinkNode *> s;
        s.push(root);
        vector<vector<TreeLinkNode *>> nodes;


        while (!s.empty())
        {
            queue<TreeLinkNode *> aux;
            vector<TreeLinkNode *> thisNodes;
            while (!s.empty())
            {
                TreeLinkNode *t = s.front();
                s.pop();
                thisNodes.push_back(t);

                if (t->left)
                {
                    aux.push(t->left);
                }
                if (t->right)
                    aux.push(t->right);
            }
            s = aux;
            nodes.push_back(thisNodes);
        }

        for (auto ns : nodes)
        {
            for (auto n : ns)
            {
                cout << n->val << " ";
                if (n->next)
                    cout << "->" << n->next->val << ":";
            }
            cout << endl;
        }

        return;
    }
};



//               3
//           9      20
//        15   7 8     13



int main()
{
    Solution s;
    TreeLinkNode *root = new TreeLinkNode(3);
    TreeLinkNode *r1 = new TreeLinkNode(9);
    TreeLinkNode *r2 = new TreeLinkNode(20);

    TreeLinkNode *r3 = new TreeLinkNode(15);
    TreeLinkNode *r4 = new TreeLinkNode(7);
    TreeLinkNode *r5 = new TreeLinkNode(8);
    TreeLinkNode *r6 = new TreeLinkNode(13);

    root->left = r1;
    root->right = r2;
    r1->left = r3;
    r1->right = r4;
    r2->left = r5;
    r2->right = r6;


    s.connect(root);
    s.print(root);

    return 0;
}

