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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* currp = head;
        
        if (!currp) return head;
        
        while(currp->next) {
            if (currp->next->val == val) {
                ListNode* delp = currp->next;
                currp->next = delp->next;
                delete delp;
            } else {
                currp = currp->next;
            }
        }
        if (head->val == val) {
            ListNode* delp = head;
            head = head->next;
            delete delp;
        }
        return head;
    }
};
