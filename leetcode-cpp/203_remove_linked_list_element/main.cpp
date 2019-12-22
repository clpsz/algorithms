#include "../common.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 32ms
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
            return NULL;

        ListNode *newList = NULL;
        ListNode *curPos = NULL;

        while (head)
        {
            if (head->val != val)
            {
                if (newList == NULL)
                {
                    newList = head;
                    curPos = newList;
                }
                else
                {
                    curPos->next = head;
                    curPos = curPos->next;
                }
            }
            head = head->next;
        }
        if (curPos)
            curPos->next = NULL;

        return newList;
    }
};


void print(ListNode *root)
{
    while (root)
    {
        cout << root->val << endl;
        root = root->next;
    }
    cout << endl;
}


int main()
{
    Solution s;
    
    ListNode *root = new ListNode(1);
    ListNode *r1 = new ListNode(1);
    root->next = r1;
    print(root);
    
    ListNode *newList = s.removeElements(root, 2);
    print(newList);

    return 0;
}

