#include "../common.h"



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 12ms
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head || !head->next)
            return false;

        ListNode *n1 = head;
        ListNode *n2 = head;
        
        while (n2 != NULL)
        {
            n1 = n1->next;
            n2 = n2->next;
            if (n2 == NULL)
                return false;
            n2 = n2->next;
            if (n2 == NULL)
                return false;
            if (n1 == n2)
                return true;
        }
    }
};


int main()
{
    return 0;
}

