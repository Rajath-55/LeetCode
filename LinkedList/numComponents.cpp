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
    int connected = 0;
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        set<int>numsc;
        int count = nums.size();

        for(auto x : nums) numsc.insert(x);
        
        ListNode* temp = head;
        while(temp){
            bool marked= false;
           
            while(temp && numsc.find(temp->val) !=numsc.end()){
                marked = true;
                temp = temp->next;
            }
            if(marked){
                connected++;
            }
            if(temp) temp = temp->next;
        }          
       
        return connected;
        
    }
};
