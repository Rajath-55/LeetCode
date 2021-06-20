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
    int getSize(ListNode *head){
        int size = 0;
        while(head){
            head = head->next;
            size++;
        }
        return size;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        int size = getSize(head);
        if(size <=1 ) return head;
        k%=size;
        
        int lastIdx = size - k -1,j=0;
        ListNode *temp = head;
        while(j != lastIdx and temp->next){
            j++;
            temp = temp->next;
        }
        cout<<temp->val<<"\n";
        ListNode *lastVal = (temp->next) ? temp->next : nullptr;
        ListNode *newHead = lastVal;
        temp->next = nullptr;
        if(lastVal != nullptr){
        while(lastVal->next){
            lastVal = lastVal->next;
        }
        
        lastVal->next = head;
        head = newHead;
        }
        
        return head;
        
    }
};


/*
1-2-3-4-5
5-1-2-3-4
4-5-1-2-3
3-4-5-1-2
2-3-4-5-1
*/
