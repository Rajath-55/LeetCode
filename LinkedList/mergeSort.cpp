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
    ListNode *getMid(ListNode *node){
        ListNode *slow = node, *fast = node, *prev = nullptr;
        
        while(fast and fast->next){
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
            
        }
        prev->next = nullptr;
        return slow; 
    }
    
    ListNode *merge(ListNode *left, ListNode *right){
        ListNode dummy(0);
        ListNode *temp = &dummy;
        
        while(left and right){
            if(left->val < right->val){
                temp->next = left;
                left = left->next;
            }else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        
        while(left){
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }
        while(right){
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }
        return dummy.next;
        
    }
    
    ListNode* sortList(ListNode* head) {
        if(not head or not head->next) return head;
        ListNode *mid = getMid(head);
        auto left = sortList(head);
        auto right = sortList(mid);
        auto sorted = merge(left, right);
        return sorted;
    }
};

/*
Merge sort;
 
*/
