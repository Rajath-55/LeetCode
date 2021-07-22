class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;
        vector<int>ans;
        
        int n = nums.size();
       
        for(int i = 0; i < n; ++i){
            while(not dq.empty() and dq.front().second <= i - k){
                dq.pop_front();
            }
            int now = nums[i];
            while(not dq.empty() and dq.back().first <= now){
                dq.pop_back();
            }
            dq.push_back({now,i});
            if(i >= k - 1) ans.push_back(dq.front().first);
            
        }
        return ans;
    }
};

/*
Insert eleements in deque:
1. Pop front of deque if its index is outside the window
2. Maintain the deque in descending order
3. Push curr node
4. include max of curr window -> It will be the top element 
Time Complexity = O(N);
Heap sol = NlogN

*/
