class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n + 1, 1), p(n + 1, -1);
        sort(nums.begin(), nums.end());
        int pos = 0, maxi = 1;
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i]%nums[j] == 0){
                    if(dp[i] < dp[j] + 1){
                        dp[i] = dp[j] + 1;
                        p[i] = j;
                    }
                    if(dp[i] > maxi){
                        maxi = dp[i];
                        pos = i;
                    }
                }
                
            }
        }
        vector<int>ans;
        while(pos!=-1){
            ans.push_back(nums[pos]);
            pos = p[pos];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

/*
Variant of LIS
dp[i] = longest increasing subsequence 
backtrack to get the answer later oof

*/
