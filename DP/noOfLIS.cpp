class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1), mp(n,1);
       
        dp[0] = 1;
        for(int i = 1; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[j] < nums[i]){
                    if(dp[i] < 1 + dp[j]){
                        dp[i] = 1 + dp[j];
                        mp[i] = mp[j];
                    }else if(dp[i] == dp[j] + 1){
                        mp[i] += mp[j];
                    }
                }
            }
        }
        int maxi = *max_element(dp.begin(), dp.end());
        int ans = 0;
        for(int i = 0; i < n; ++i){
            if(dp[i] == maxi) ans+=mp[i];
        }
        
        
        return ans;
        
    }
};
