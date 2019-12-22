/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "../common.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // 68ms
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = nullptr;
        ListNode *cur = nullptr;
        int carry = 0;

        while (l1 != nullptr && l2 != nullptr)
        {
            int v1 = l1->val;
            int v2 = l2->val;

            int thisAdd = v1 + v2 + carry;
            carry = thisAdd / 10;
            thisAdd %= 10;
            ListNode *newNode = new ListNode(thisAdd);
            if (res == nullptr)
            {
                res = newNode;
            }
            else
            {
                cur->next = newNode;
            }
            cur = newNode;

            l1 = l1->next;
            l2 = l2->next;
        }

        while (l1 != nullptr)
        {
            int v = l1->val;
            int thisAdd = v + carry;
            carry = thisAdd / 10;
            thisAdd %= 10;
            ListNode *newNode = new ListNode(thisAdd);
            cur->next = newNode;
            cur = newNode;
            l1 = l1->next;
        }
        while (l2 != nullptr)
        {
            int v = l2->val;
            int thisAdd = v + carry;
            carry = thisAdd / 10;
            thisAdd %= 10;
            ListNode *newNode = new ListNode(thisAdd);
            cur->next = newNode;
            cur = newNode;
            l2 = l2->next;
        }

        if (carry)
        {
            cur->next = new ListNode(carry);
        }
        
        return res;
    }
};

ListNode *toListNode(int num)
{
    ListNode *res = nullptr;
    ListNode *cur = nullptr;

    if (num == 0)
    {
        return new ListNode(0);
    }

    while (num > 0)
    {
        int d = num % 10;     
        num /= 10;

        ListNode *newNode = new ListNode(d);
        if (res == nullptr)
        {
            res = newNode;
        }
        else
        {
            cur->next = newNode;
        }
        cur = newNode;
    }

    return res;
}

void printListNode(ListNode *list)
{
    int i = 0;
    vector<int> nums;

    while (list != nullptr)
    {
        nums.push_back(list->val);
        list = list->next;
        i++;
    }

    while (--i >= 0)
    {
        cout << nums[i];
    }

    cout << endl;
}

int main()
{
    ListNode *l1 = toListNode(0);
    ListNode *l2 = toListNode(37);
    Solution s;

    ListNode *res = s.addTwoNumbers(l1, l2);

    printListNode(res);

    return 0;
}

