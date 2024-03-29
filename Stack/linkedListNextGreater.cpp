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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>nums;
        while(head)
        {
            nums.push_back(head->val);
            head=head->next;
        }
        stack<int>s;
        vector<int>res;
        for(int i=nums.size()-1;i>=0;i--)
        {
            while(s.size()!=0&&s.top()<=nums[i])
            {
                s.pop();
            }
            if(s.size()==0)
                res.push_back(0);
            else
                res.push_back(s.top());
            s.push(nums[i]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
