#include "../common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



// 12ms
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode *newHead = NULL;
        ListNode *curPos = newHead;

        while (l1 && l2)
        {
            ListNode *next = NULL;
            if (l1->val > l2->val)
            {
                next = l2;
                l2 = l2->next;
            }
            else
            {
                next = l1;
                l1 = l1->next;
            }
            if (newHead == NULL)
            {
                newHead = next;
                curPos = newHead;
            }
            else
            {
                curPos->next = next;
                curPos = curPos->next;
            }
        }

        while (l1)
        {
            curPos->next = l1;
            curPos = curPos->next;
            l1 = l1->next;
        }
        while (l2)
        {
            curPos->next = l2;
            curPos = curPos->next;
            l2 = l2->next;
        }

        return newHead;
    }
};

void print(ListNode *head)
{
    while (head)
    {
        cout << head->val << endl;
        head = head->next;
    }

    cout << endl;
}




int main()
{
    ListNode *root1 = new ListNode(1);
    ListNode *l2 = new ListNode(3);
    ListNode *l3 = new ListNode(5);
    ListNode *l4 = new ListNode(7);
    ListNode *l5 = new ListNode(9);
    root1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;

    ListNode *soot1 = new ListNode(2);
    ListNode *s2 = new ListNode(4);
    ListNode *s3 = new ListNode(6);
    ListNode *s4 = new ListNode(8);
    ListNode *s5 = new ListNode(10);
    soot1->next = s2;
    s2->next = s3;
    s3->next = s4;
    s4->next = s5;


    Solution s;
    ListNode *newHead = s.mergeTwoLists(root1, soot1);
    print(newHead);

    return 0;
}

