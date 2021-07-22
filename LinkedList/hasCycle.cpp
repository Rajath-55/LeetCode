/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow_pointer = head, *fast_pointer = head;
        while(slow_pointer and fast_pointer and fast_pointer->next){
            slow_pointer = slow_pointer->next;
            fast_pointer = fast_pointer->next->next;
            if(fast_pointer == slow_pointer) return true;
        }
        return false;
    }
};
