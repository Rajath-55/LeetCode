class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<long>dp(amount + 1, INT_MAX);
        dp[0] = 1;
    
        for(int i = 0; i <= amount; ++i){
            for(int j = 0; j < coins.size(); ++j){
                if(i - coins[j] >= 0){
                    dp[i] = min(dp[i - coins[j]] + 1, dp[i]); 
                }
            }
        }
        return dp[amount] == INT_MAX ? -1 : --dp[amount];
        
    }
};

/*
Dp for amount as state
dp[i] = min coins required to get amount i
for(int i = 0; i <= amount; ++i){
    for(int j = 0; j < coins.size(); ++j){
    
    }
}

*/

