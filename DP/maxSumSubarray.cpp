#include<bits/stdc++.h>

/*
 * This is dp with state : atindex i max sum until now.
 * Kadanes version :same thing tbh
 *
 */


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // dp approach
        vector<int>dp(nums.size(), -1e6);
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            dp[i] = max(nums[i], dp[i-1] + nums[i]);
        }
        
        
        
        return *max_element(dp.begin(), dp.end());
       
    }
};
