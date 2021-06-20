class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> Q;
        vector<int> ans;
        
        // Processing First K Elements Seperately
        for(int i=0; i<k; i++){
            // If new element is greater than  element present at back index of dequeue 
            // then no need to store that index.
            while(!Q.empty() && nums[i]>nums[Q.back()]){
                Q.pop_back();
            }
			// Pushing the current index 
            Q.push_back(i);
        }
        
        int j = k;
        
        while(j < nums.size()){
            
            // Pushing maximum of current window to answer
            ans.push_back(nums[Q.front()]);
            
            // Removing all the indexes which are out of the current window
            while(!Q.empty() && Q.front()<=j-k){
                Q.pop_front();
            }
            
            // If new element is greater than back index of element of dequeue 
            // then no need to store that index.
            while(!Q.empty() && nums[Q.back()]<=nums[j]){
                Q.pop_back();
            }
            
            // Inserting the index pf current element
            Q.push_back(j);
            
            j++;
        }
        
        // For the last window
        ans.push_back(nums[Q.front()]);
        
        return ans;
    }
};
