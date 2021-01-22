/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


/*
O(n) time and O(1) space;
returns a pointer to the resulting ListNode
Same like merge two sorted arrays with pointer shix

*/
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *res;
        //Base Cases:
        ListNode *temp;
        res = NULL;
        temp = NULL;
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        while (l1 && l2)
        {
            if (!temp)
            {
                if (l1->val > l2->val)
                {
                    temp = l2;
                    l2 = l2->next;
                }
                else
                {
                    temp = l1;
                    l1 = l1->next;
                }
                res = temp;
            }
            else
            {
                if (l1->val > l2->val)
                {
                    temp->next = l2;
                    temp = temp->next;
                    l2 = l2->next;
                }
                else
                {
                    temp->next = l1;
                    temp = temp->next;
                    l1 = l1->next;
                }
            }
        }
        if (l1)
        {
            while (l1)
            {
                temp->next = l1;
                temp = temp->next;
                l1 = l1->next;
            }
        }
        else if (l2)
        {
            while (l2)
            {
                temp->next = l2;
                temp = temp->next;
                l2 = l2->next;
            }
        }
        return res;
    }
};