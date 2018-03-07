#include "../common.h"


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 16ms
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        if (head == NULL)
            return head;

        while (cur && cur->next)
        {
            if (cur->val == cur->next->val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }

        return head;
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
    ListNode *r2 = new ListNode(2);
    root->next = r1;
    r1->next = r2;
    print(root);
    s.deleteDuplicates(root);
    print(root);



    ListNode *soot = new ListNode(1);
    ListNode *s1 = new ListNode(1);
    ListNode *s2 = new ListNode(2);
    ListNode *s3 = new ListNode(3);
    ListNode *s4 = new ListNode(3);
    soot->next = s1;
    s1->next = s2;
    s2->next = s3;
    s3->next = s4;
    print(soot);
    s.deleteDuplicates(soot);
    print(soot);

    return 0;
}

