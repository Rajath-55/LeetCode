class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum + target)%2 == 1 or abs(target) > sum) return 0;
        int tar = (sum + target)/2;
        vector<int>dp(tar + 1);
        dp[0] = 1;
        for(auto x : nums){
            for(int j = tar; j >= x; --j){
                dp[j] += dp[j - x];
            }
        }
        
        return dp[tar];
    }
};

/*
Either to the left or to the right
i.e + or -

0-1 knapsack type but add a[i] or subtract a[i];
subset sum problem type only

divide all positive values into one subset and the negative values into another
then s1 - s2 == target 


*/
