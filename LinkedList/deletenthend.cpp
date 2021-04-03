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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
    struct ListNode* del,* pnode = head;
    while(pnode != NULL)
    {
        count++;
        pnode = pnode->next;
    }
    count = count - n - 1;
    if(count < 0)
    {
        del = head;
        head = del->next;
    }
    else
    {
        pnode = head;
        for( int i = 0; i < count; i++)
        {
            pnode = pnode->next;
        }
        del = pnode->next;
        pnode->next = del->next;
    }
    
    return head;
    }
};