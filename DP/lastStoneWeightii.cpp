class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum1=0;
        for(int i:stones){
            sum1+=i;
        }
        int sum=sum1/2;
        int n = stones.size();
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        for(int i=0;i<=n;i++){
            dp[i][0]=1;
        }
       
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(stones[i-1]<=j){
                    dp[i][j]=dp[i-1][j-stones[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        for(int i=sum;i>=0;i--){
            if(dp[n][i]==1){
                return sum1-i*2; 
            }
        }
        return sum;
    }
};
