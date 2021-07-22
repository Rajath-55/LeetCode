class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1, 1e5);
        dp[0] = 0;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j*j <=i; ++j){
                dp[i] = min(dp[i-j*j] + 1, dp[i]);
            }
        }
        
        return dp[n];
    }
};
/*
numSquares
dp
for every number 
for every square number less than that, we can come to it 
so check with dp




*/
