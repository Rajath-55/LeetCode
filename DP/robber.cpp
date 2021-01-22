class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return (int)max(nums[0], nums[1]);
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = nums[1];
        for (int i = 2; i < n; ++i)
        {
            if (i == 2)
            {
                dp[i] = dp[i - 2] + nums[i];
            }
            else
            {
                dp[i] = nums[i] + max(dp[i - 2], dp[i - 3]);
            }
        }
        return (int)max(dp[n - 1], dp[n - 2]);
    }
};

/*
2 4 1 9 3 12

2 4 3 13 
*/
