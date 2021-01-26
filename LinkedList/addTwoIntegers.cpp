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
Basic broot phorce soluchan, very bad
*/
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *res = new ListNode(-1);
        ListNode *tail = res;
        int carry = 0;
        while (l1 || l2)
        {
            int temp = carry;
            if (l1)
            {
                temp += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                temp += l2->val;
                l2 = l2->next;
            }
            tail->next = new ListNode(temp % 10);
            tail = tail->next;
            carry = temp / 10;
        }
        if (carry)
            tail->next = new ListNode(carry);
        return res->next;
    }
};