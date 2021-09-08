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

    int isValid(ListNode *head, int k){
        ListNode *temp = head;
        int count = 0;
        while(temp){
            temp = temp->next;
            count++;
        }
        return count >= k;
    }
        
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(not isValid(head, k)) return head;
        int count = k;
        ListNode *temp = head, *prev = nullptr;
        while(count-- and temp){
            ListNode *newNext = temp->next;
            temp->next = prev;
            prev = temp;
            temp = newNext;
        }
        if(temp){
            head->next = reverseKGroup(temp, k);
        }
        return prev;
        
    }
};
