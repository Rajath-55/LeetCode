class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long long>dp(target + 1, 0);
        int n = nums.size();
        
        dp[0] = 1;
         for(int i = 0; i <= target; ++i){
             for(int j = 0; j < n; ++j){
                 if(i - nums[j] >=0 ){
                     dp[i] += dp[i-nums[j]];
                 }
             }
         }
        return dp[target];
        
    }
};
/*

Knapsack problem only
No of ways to get i - nums[j] you can add for all such j before i;

*/
