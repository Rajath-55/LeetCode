class Solution {
public:
    int dp[21][21];
    
    int solve(vector<int>&v, int l, int r){
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        
        int maxi = max(v[l] - solve(v, l + 1, r), v[r] - solve(v, l, r - 1));
        return dp[l][r] = maxi;
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp, -1,sizeof(dp));
        int n = nums.size();
        return solve(nums,0, n-1) >=0;
    }
    
};

/*
you either take from the left or from the right
when you take from the left you increase the left pointer
else you decrease the right pointer
maximum of those you can keep as dp[l][r].
then return dp[0][n-1];
full array.

l to r gives a subarray right
so full aray you need


*/
