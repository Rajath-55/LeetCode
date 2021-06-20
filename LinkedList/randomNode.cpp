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
    private: ListNode*head;
    int length;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        length = 0;
        ListNode *temp = head;
        while(temp){
            length++;
            temp = temp->next;
        }
        
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int pos = rand()%length;
       ListNode *temp = head;
        while(pos--){
            temp = temp->next;
            
        }
        return temp->val;
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
