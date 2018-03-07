#include "../common.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



// 8ms
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *newHead = NULL;
        ListNode *tmp = NULL;

        while (head)
        {
            tmp = head->next;
            head->next = newHead;
            newHead = head;
            head = tmp;
        }

        return newHead;
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
    ListNode *r1 = new ListNode(2);
    ListNode *r2 = new ListNode(3);
    root->next = r1;
    r1->next = r2;

    print(root);
    ListNode *newList = s.reverseList(root);
    print(newList);

    return 0;
}

