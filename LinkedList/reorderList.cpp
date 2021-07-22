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
    ListNode* reverse(ListNode* head){
        
        ListNode * currHead = head->next;
        head->next=NULL;
        
        
        while(currHead){
              ListNode* temp= currHead->next;
              currHead->next=head;
              head=currHead;
              currHead=temp;
        }
        
        return head;
      
    }
    
    void reorderList(ListNode* head) {
         if(!head->next) return;
        
         ListNode* slow=head;
         ListNode* fast=head;
         ListNode*prev=NULL;
        
        // finding the midway of linked list
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=NULL;                    // disconnecting the first half from another.
       ListNode* ptr = reverse(slow);       // reverse the second half
       ListNode * tempHead = head;          // for traversal of first half 
        
        // inserting the second (reversed) half elements to first half alternatively.
        while(ptr){
            ListNode * temp=ptr;
            ptr=ptr->next;          
            temp->next=NULL;                // just to isolate the node completley
            ListNode* remainingNodes = tempHead->next;
            tempHead->next=temp;
            temp->next=remainingNodes;
            if(tempHead->next->next)
                tempHead=tempHead->next->next;
            else                                                   // if the elements of first half < second half.
                tempHead=tempHead->next;
        }
    }
};

/*
 * Stack version O(n) space tho
 *
 */
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
    void reorderList(ListNode* head) {
        if(not head or not head->next or not head->next->next) return;
        stack<ListNode*>st;
        ListNode *temp = head;
        int size = 0;
        while(temp){
            st.push(temp);
            temp = temp->next;
            size++;
        }
      
        temp = head;
        for(int i = 0; i < size/2; ++i){
            if(i == size/2 - 1 and size%2 == 0){
                temp = temp->next;
                break;
            }
            ListNode *toInsert = st.top();
           
            st.pop();
            ListNode *toInsertNext = temp->next;
            temp->next = toInsert;
            toInsert->next = toInsertNext;
            temp = toInsertNext;
        }
        temp->next = nullptr;
    }
};
