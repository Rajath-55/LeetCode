class Solution {
public:
    int rob(vector<int>& nums) {
        //includeFirstHouse;
        int n = nums.size();
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0], nums[1]);
        }
        
        vector<int>dp(n,0);
        //when 0 but not n-1
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i=2; i< n - 1; ++i){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int maxi1 = *max_element(dp.begin(), dp.end());
        fill(dp.begin(), dp.end(), 0);
        dp[1] = nums[1];
        dp[2] = max(nums[1], nums[2]);
        
        for(int i = 3; i < n ; ++i){
            dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        int maxi2 = *max_element(dp.begin(), dp.end());
        return max(maxi1, maxi2);
        
    }
        
};

/*
Let us see what the state is:
state  = amount gained after visiting a house, and deciding whether to rob that or not.

# either include the first house and exclude last, or exclude first and include last;


1 2 3 4 5

1 2 4 6 5+4-1






*/
