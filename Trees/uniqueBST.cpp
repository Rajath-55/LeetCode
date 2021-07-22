class Solution {
public:
    int numTrees(int n) {
        vector<int>dp(n+1,0);
        dp[0] = 1;
        dp[1] = 1;
       
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i; ++j){
                dp[i]+=(dp[i-j]*dp[j-1]);
            }
        }
        return dp[n];
    }
};
/*
dp solution
basically, for each i, if i were the root, how many posible ways:
there we can see that left side has i-1 and right has n-i values
and this can be precomputed and thus bottom up dp can be done
with base case dp[0] = 1 and dp[1] = 1;

another direct way is to get the catalan number = 2n!/(n+1)!(n!)
*/
