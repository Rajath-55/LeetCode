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
    ListNode* swapNodes(ListNode* head, int k) {
        int currIdx = k;
        int size = 0;
        ListNode* temp = head;
        ListNode* tail = head;
        while(temp){
            temp = temp->next;
            size++;
        }
        cout<<size<<endl;
        
        temp = head;
        k--;
        int nextone = size - currIdx ;
        while(nextone--){
            tail = tail->next;
        }
        
        
        while(k--){
            temp = temp->next;
        }
        swap(temp->val, tail->val);
        return head;
    }
};

/* 
A little more optimised
*/
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *ptr1 = head, *ptr2 = head, *kth = NULL;
        while (--k)
            ptr1 = ptr1->next;
        
        kth = ptr1;
        ptr1 = ptr1->next;
        
        while (ptr1) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        swap(ptr2->val, kth->val);
        return head;
    }
};