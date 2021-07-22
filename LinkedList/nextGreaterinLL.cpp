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
    vector<int>nodeElements;
    
    void addElements(ListNode *head){
        ListNode *temp = head;
        while(temp){
            nodeElements.push_back(temp->val);
            temp = temp->next;
        }
    }
    
    void getNextLarger(vector<int>&ans){
        stack<int>st;
        int n = nodeElements.size();
        st.push(nodeElements[n-1]);
        for(int i = n-2; i >=0; --i){
            // cout<<st.top()<<"\n";
            while(not st.empty() and st.top() <= nodeElements[i]) st.pop();
            if(not st.empty()) ans[i] = st.top();
            st.push(nodeElements[i]);
        }
    }
    
    vector<int> nextLargerNodes(ListNode* head) {
        addElements(head);
        vector<int>ans(nodeElements.size(), 0);
        getNextLarger(ans);
        return ans;
    }
};

/*
Idea seems to be to use a stack after getting all values in an array (Brute force ig)
Let's see
Yep
so the idea is to push the last element onto the stack, and that one's answrer is 0, because circular travel is not allowed.
Now, for every element from n-2 to 0, pop off the elements <=that from the stack ,and then if not empty the top is the ans[i]
else its 0 anyways;
*/

