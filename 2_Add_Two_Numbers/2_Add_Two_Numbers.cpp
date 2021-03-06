// 2_Add_Two_Numbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* CopyListNode(ListNode* l)
{
    if (!l)
    {
        return NULL;
    }

    ListNode* ret = new ListNode(l->val);
    l = l->next;

    ListNode* lEnd = ret;

    while (l)
    {
        ListNode* newNode = new ListNode(l->val);
        lEnd->next = newNode;
        lEnd = lEnd->next;

        l = l->next;
    }

    return ret;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if (!(l1 && l2))
        {
            if (l1)
                return CopyListNode(l1);
            else if (l2)
                return CopyListNode(l2);
            else
                return NULL;
        }

        int sum = l1->val + l2->val;
        
        int digit = sum % 10;
        int carry = sum / 10;

        ListNode* ret = new ListNode(digit);
        ListNode* lEnd = ret;

        l1 = l1->next;
        l2 = l2->next;

        while (l1 && l2)
        {
            int sum = l1->val + l2->val + carry;

            digit = sum % 10;
            carry = sum / 10;

            ListNode* newNode = new ListNode(digit);

            lEnd->next = newNode;
            lEnd = lEnd->next;

            l1 = l1->next;
            l2 = l2->next;
        }

        // copy remains
        if (l1)
        {
            lEnd->next = CopyListNode(l1);
        }
        else if (l2)
        {
            lEnd->next = CopyListNode(l2);
        }

        while (carry)
        {
            if (!lEnd->next)
            {
                lEnd->next = new ListNode(carry);
                carry = 0;
            }
            else
            {
                ListNode* digit = lEnd->next;
                ListNode* digitPrev = lEnd;
                while (carry && digit)
                {
                    int sum = digit->val + carry;
                    digit->val = sum % 10;
                    carry = sum / 10;

                    digit = digit->next;
                    digitPrev = digitPrev->next;
                }

                if (carry && !digit)
                {
                    digitPrev->next = new ListNode(carry);
                    carry = 0;
                }
            }
        }

        return ret;
    }
};

int main()
{
    ListNode* l1 = new ListNode(9);
    l1->next = new ListNode(8);
    //l1->next->next = new ListNode(9);
    //l1->next->next->next = new ListNode(9);

    ListNode* l2 = new ListNode(1);

    //ListNode* l1 = new ListNode(5);

    //ListNode* l2 = new ListNode(5);

    Solution s;
    ListNode* sum = s.addTwoNumbers(l1, l2);
    return 0;
}

