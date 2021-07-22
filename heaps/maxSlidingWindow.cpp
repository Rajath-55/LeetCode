class Solution {
public:
    vector<int>bruteForce(vector<int>&nums, int k){
        vector<int>ans;
        ans.push_back(*max_element(nums.begin(), nums.begin() + k));
        int lastIdx = 0;
        for(int i = k; i < nums.size(); ++i){
            lastIdx++;
            ans.push_back(*max_element(nums.begin() + lastIdx, nums.begin() + i + 1));
        }
        
        return ans;
    }
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        priority_queue<pair<int,int>>pq;
        for(int i = 0; i < k; ++i){
            pq.push({nums[i], i});
        }
        ans.push_back(pq.top().first);
        
        for(int i = k; i < nums.size(); ++i){
            pq.push({nums[i],i});
            while(!(pq.top().second > i-k)){
                pq.pop();
            }
            ans.push_back(pq.top().first);
        }
        return ans;
        
        
    }
};
/*
Brute force, traverse all elements and max element in array
gives tle
A better algorithm is to use a maxHeap.

*/
