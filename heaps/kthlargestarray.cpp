class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int> > pq;
        for(auto ele : nums) pq.push(ele);
        k--;
        while(k--){
            pq.pop();
        }
       return pq.top();
        
    }
};
