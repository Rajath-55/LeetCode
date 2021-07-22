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
    ListNode* reverseList(ListNode* head) {
        if(not head or not head->next) return head;
        ListNode *currHead = head->next;
        head->next = nullptr;
        while(currHead){
            ListNode *currNext = currHead->next;
            currHead->next = head;
            head = currHead;
            currHead = currNext;
        }
        // head->next = nullptr;
        return head;
    }
};
